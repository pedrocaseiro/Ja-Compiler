%{
  #include <stdio.h>
  #include <string.h>
  #include "ast.h"
  #include "symbol_table.h"
  void yyerror();
  int yylex();

  node* ast;

  extern char* yytext;
  extern int line, col, yyleng;
%}

%union{
  struct token_struct* token;
  struct node *node;
}

%token <token> BOOL BOOLLIT CLASS DO DOTLENGTH DOUBLE ELSE IF INT PARSEINT PRINT PUBLIC
%token <token> RETURN STATIC WHILE OCURV CCURV OBRACE CBRACE STRING
%token <token> VOID
%token <token> OSQUARE CSQUARE AND OR LT GT EQ NEQ LEQ GEQ PLUS MINUS STAR DIV MOD NOT
%token <token> ASSIGN SEMI COMMA RESERVED DECLIT REALLIT STRLIT
%token <token> ID

%nonassoc IF_NO_ELSE
%nonassoc ELSE

%right ASSIGN
%left OR
%left AND
%left EQ NEQ
%left GT LT GEQ LEQ
%left PLUS MINUS
%left STAR DIV MOD
%right NOT UNARY

%type <node> Program DeclarationL DeclarationAux FieldDecl FieldDeclL FormalParamsStringArray FieldsIds StringArray MethodDecl MethodHeader MethodBody MethodParams MethodParamsL VOIDAux VarDeclStatement FormalParams StrLitAux VarDecl VarDeclL VarsIds Statement StatementL Assignment MethodInvocation ParseArgs Expr ExprAux Type CommaExpr IDAux

%%

Program: CLASS IDAux OBRACE DeclarationAux CBRACE                    {$$ = ast = create_and_insert_node("Program", 1, 2, $2, $4);}

DeclarationAux: DeclarationAux DeclarationL                          {$$ = create_and_insert_node("Program", 0, 2, $1, $2);}
              |                                                      {$$ = create_terminal_node("Empty", 0, NULL);}

DeclarationL: FieldDecl                                              {$$ = create_and_insert_node("FieldDeclAux", 0, 1, $1);}
            | MethodDecl                                             {$$ = create_and_insert_node("MethodDeclAux", 0, 1, $1);}
            | SEMI                                                   {$$ = create_terminal_node("Semi", 0, NULL);}

FieldDecl: PUBLIC STATIC Type FieldDeclL SEMI                        {if ($4 != NULL) { ast_decl($3, $4); $$ = $4; } else { $$ = $4; }}
         | error SEMI                                                {$$ = NULL; }

FieldDeclL: FieldDeclL COMMA FieldsIds                               {$$ = create_and_insert_node("FieldDecl", 0, 2, $1, $3);}
          | FieldsIds                                                {$$ = $1;}

FieldsIds: IDAux                                                     {$$ = create_and_insert_node("FieldDecl", 1, 1, $1);}

MethodDecl: PUBLIC STATIC MethodHeader MethodBody                    {$$ = create_and_insert_node("MethodDecl", 1, 2, $3, $4);}

MethodHeader: Type IDAux OCURV MethodParamsL CCURV                   {$$ = create_and_insert_node("MethodHeader", 1, 3, $1, $2, $4);}
            | VOIDAux IDAux OCURV MethodParamsL CCURV                {$$ = create_and_insert_node("MethodHeader", 1, 3, $1, $2, $4);}

MethodParamsL: MethodParams                                          {$$ = $1;}
             | FormalParamsStringArray                               {$$ = create_and_insert_node("MethodParams", 1, 1, $1);}
             |                                                       {$$ = create_and_insert_node("MethodParams", 1, 0);}

VOIDAux: VOID                                                        {$$=create_terminal_node("Void", 1, $1);}

MethodParams: MethodParams COMMA FormalParams                        {$1->to_be_used = 0; $$ = create_and_insert_node("MethodParams", 1, 2, $1, $3);}
            | FormalParams                                           {$$ = create_and_insert_node("MethodParams", 1, 1, $1);}

FormalParamsStringArray: StringArray OSQUARE CSQUARE IDAux           {$$ = create_and_insert_node("ParamDecl", 1, 2, $1, $4);}

FormalParams: Type IDAux                                             {$$ = create_and_insert_node("ParamDecl", 1, 2, $1, $2);}

StringArray: STRING                                                  {$$ = create_and_insert_node("StringArray", 1, 0);}

MethodBody: OBRACE VarDeclStatement CBRACE                           {$$ = create_and_insert_node("MethodBody", 1, 1, $2);}

VarDeclStatement: VarDeclStatement VarDecl                           {$$ = create_and_insert_node("MethodBody", 0, 2, $1, $2);}
                | VarDeclStatement Statement                         {$$ = create_and_insert_node("MethodBody", 0, 2, $1, $2);}
                |                                                    {$$ = create_terminal_node("Empty", 0, NULL);}



VarDecl: Type VarDeclL SEMI                                          {if ($2 != NULL) { ast_decl($1, $2); $$ = $2; } else { $$ = $2; } }

VarDeclL: VarDeclL COMMA VarsIds                                     {$$ = create_and_insert_node("VarDecl", 0, 2, $1, $3);}
        | VarsIds                                                    {$$ = $1;}

VarsIds: IDAux                                                       {$$ = create_and_insert_node("VarDecl", 1, 1, $1);}

Statement: OBRACE StatementL CBRACE                                  {if($2 != NULL && $2->n_children <= 1) {$$ = create_and_insert_node("Block", 0, 1, $2); } else { $$ = create_and_insert_node("Block", 1, 1, $2);}}
         | IF OCURV Expr CCURV Statement ELSE Statement              {if(check_if_expr($5)){ $5 = create_terminal_node("Block", 1, NULL);} if(check_if_statement($7)){ $7 = create_terminal_node("Block", 1, NULL);} $$ = create_and_insert_node("If", 1, 3, $3, $5, $7);}
         | IF OCURV Expr CCURV Statement %prec IF_NO_ELSE            {if(check_if_expr($5)){ $5 = create_terminal_node("Block", 1, NULL);} $$ = create_and_insert_node("If", 1, 3, $3, $5, create_terminal_node("Block", 1, NULL));}
         | WHILE OCURV Expr CCURV Statement                          {if(check_while_statement($5)){ $5 = create_terminal_node("Block", 1, NULL);} $$ = create_and_insert_node("While", 1, 2, $3, $5);}
         | DO Statement WHILE OCURV Expr CCURV SEMI                  {if(check_while_statement($2)){ $2 = create_terminal_node("Block", 1, NULL);} $$ = create_and_insert_node("DoWhile", 1, 2, $2, $5);}
         | PRINT OCURV Expr CCURV SEMI                               {$$ = create_and_insert_node("Print", 1, 1, $3);}
         | PRINT OCURV StrLitAux CCURV SEMI                          {$$ = create_and_insert_node("Print", 1, 1, $3);}
         | Assignment SEMI                                           {$$ = create_and_insert_node("Assign", 0, 1, $1);}
         | MethodInvocation SEMI                                     {$$ = create_and_insert_node("Call", 1, 1, $1);}
         | ParseArgs SEMI                                            {$$ = create_and_insert_node("ParseArgs", 1, 1, $1); if($$->n_children){$$->token->line = $$->childs[0]->token->line; $$->token->col=$$->childs[0]->token->col;}}
         | SEMI                                                      {$$ = create_terminal_node("Semi", 0, NULL);}
         | RETURN Expr SEMI                                          {$$ = create_and_insert_node("Return", 1, 1, $2);$$->token->line = $1->line;$$->token->col = $1->col;}
         | RETURN SEMI                                               {$$ = create_and_insert_node("Return", 1, 0);$$->token->line = $1->line;$$->token->col = $1->col;}
         | error SEMI                                                {$$ = create_terminal_node("Error", 0, NULL);}

StatementL: StatementL Statement                                     {$$ = create_and_insert_node("Statement", 0, 2, $1, $2);}
          |                                                          {$$ = create_terminal_node("Empty", 0, NULL);}

Assignment: IDAux ASSIGN Expr                                        {$$ = create_and_insert_node("Assign", 1, 2, $1, $3); $$->token->line = $2->line;$$->token->col = $2->col;}

MethodInvocation: IDAux OCURV Expr CommaExpr CCURV                   {$$ = create_and_insert_node("Call", 0, 3, $1, $3, $4);}
                | IDAux OCURV CCURV                                  {$$ = create_and_insert_node("Call", 0, 1, $1);}
                | IDAux OCURV error CCURV                            {$$ = create_terminal_node("Error", 0, NULL);}

CommaExpr: CommaExpr COMMA Expr                                      {$$ = create_and_insert_node("Call", 0, 2, $1, $3);}
         |                                                           {$$ = create_terminal_node("Empty", 0, NULL);}

StrLitAux: STRLIT                                                    {$$ = create_terminal_node("StrLit", 1, $1);}

ParseArgs: PARSEINT OCURV IDAux OSQUARE Expr CSQUARE CCURV           {$$ = create_and_insert_node("ParseArgs", 0, 2, $3, $5);}
         | PARSEINT OCURV error CCURV                                {$$ = create_terminal_node("Error", 0, NULL);}

ExprAux: MethodInvocation                                            {$$ = create_and_insert_node("Call", 1, 1, $1); if($$->n_children){$$->token->line = $$->childs[0]->token->line; $$->token->col=$$->childs[0]->token->col;}}
       | ParseArgs                                                   {$$ = create_and_insert_node("ParseArgs", 1, 1, $1);$$->token->line = $$->childs[0]->token->line; $$->token->col=$$->childs[0]->token->col;}
       | ExprAux AND ExprAux                                         {$$ = create_and_insert_node("And", 1, 2, $1, $3); $$->token->line = $2->line;$$->token->col = $2->col;}
       | ExprAux OR ExprAux                                          {$$ = create_and_insert_node("Or", 1, 2, $1, $3); $$->token->line = $2->line;$$->token->col = $2->col;}
       | ExprAux EQ ExprAux                                          {$$ = create_and_insert_node("Eq", 1, 2, $1, $3); $$->token->line = $2->line;$$->token->col = $2->col;}
       | ExprAux GEQ ExprAux                                         {$$ = create_and_insert_node("Geq", 1, 2, $1, $3); $$->token->line = $2->line;$$->token->col = $2->col;}
       | ExprAux GT ExprAux                                          {$$ = create_and_insert_node("Gt", 1, 2, $1, $3); $$->token->line = $2->line;$$->token->col = $2->col;}
       | ExprAux LEQ ExprAux                                         {$$ = create_and_insert_node("Leq", 1, 2, $1, $3); $$->token->line = $2->line;$$->token->col = $2->col;}
       | ExprAux LT ExprAux                                          {$$ = create_and_insert_node("Lt", 1, 2, $1, $3); $$->token->line = $2->line;$$->token->col = $2->col;}
       | ExprAux NEQ ExprAux                                         {$$ = create_and_insert_node("Neq", 1, 2, $1, $3); $$->token->line = $2->line;$$->token->col = $2->col;}
       | ExprAux PLUS ExprAux                                        {$$ = create_and_insert_node("Add", 1, 2, $1, $3); $$->token->line = $2->line;$$->token->col = $2->col;}
       | ExprAux MINUS ExprAux                                       {$$ = create_and_insert_node("Sub", 1, 2, $1, $3); $$->token->line = $2->line;$$->token->col = $2->col;}
       | ExprAux STAR ExprAux                                        {$$ = create_and_insert_node("Mul", 1, 2, $1, $3); $$->token->line = $2->line;$$->token->col = $2->col;}
       | ExprAux DIV ExprAux                                         {$$ = create_and_insert_node("Div", 1, 2, $1, $3); $$->token->line = $2->line;$$->token->col = $2->col;}
       | ExprAux MOD ExprAux                                         {$$ = create_and_insert_node("Mod", 1, 2, $1, $3); $$->token->line = $2->line;$$->token->col = $2->col;}
       | PLUS ExprAux %prec UNARY                                    {$$ = create_and_insert_node("Plus", 1, 1, $2);$$->token->line = $1->line;$$->token->col = $1->col;}
       | MINUS ExprAux %prec UNARY                                   {$$ = create_and_insert_node("Minus", 1, 1, $2);$$->token->line = $1->line;$$->token->col = $1->col;}
       | NOT ExprAux                                                 {$$ = create_and_insert_node("Not", 1, 1, $2);$$->token->line = $1->line;$$->token->col = $1->col;}
       | IDAux                                                       {$$ = $1;}
       | IDAux DOTLENGTH                                             {$$ = create_and_insert_node("Length", 1, 1, $1);$$->token->line = $2->line;$$->token->col = $2->col;}
       | OCURV Expr CCURV                                            {$$ = $2;}
       | BOOLLIT                                                     {$$=create_terminal_node("BoolLit", 1, $1);$$->token->line = $1->line;$$->token->col = $1->col;}
       | DECLIT                                                      {$$=create_terminal_node("DecLit", 1, $1);$$->token->line = $1->line;$$->token->col = $1->col;}
       | REALLIT                                                     {$$=create_terminal_node("RealLit", 1, $1);$$->token->line = $1->line;$$->token->col = $1->col;}
       | OCURV error CCURV                                           {$$ = create_terminal_node("Error", 0, NULL);}


Expr: Assignment                                                     {$$ = create_and_insert_node("Assign", 0, 1, $1);}
    | ExprAux                                                        {$$ = $1;}

Type: BOOL                                                           {$$=create_terminal_node("Bool", 1, $1);}
    | INT                                                            {$$=create_terminal_node("Int", 1, $1);}
    | DOUBLE                                                         {$$=create_terminal_node("Double", 1, $1);}

IDAux: ID                                                            {$$=create_terminal_node("Id", 1, $1);$$->token->line = $1->line;$$->token->col = $1->col;}

%%

void yyerror(const char *s) {
  error_flag = 1;
	printf("Line %d, col %d: %s: %s\n", line, col - yyleng, s, yytext);
}
