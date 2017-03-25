%{
  #include <stdio.h>
  #include <string.h>
  #include "ast.h"
  void yyerror();
  int yylex();

  node* ast;

  extern char* yytext;
  extern int line, col, yyleng;
%}

%union{
  char* token;
  char *id, *string;
  struct node *node;
}

%token <string> BOOL BOOLLIT CLASS DO DOTLENGTH DOUBLE ELSE IF INT PARSEINT PRINT PUBLIC
%token <string> RETURN STATIC WHILE OCURV CCURV OBRACE CBRACE STRING
%token <string> VOID
%token <string> OSQUARE CSQUARE AND OR LT GT EQ NEQ LEQ GEQ PLUS MINUS STAR DIV MOD NOT
%token <string> ASSIGN SEMI COMMA RESERVED DECLIT REALLIT STRLIT
%token <id> ID

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

%type <node> Program Declaration FieldDecl FieldDeclL MethodDecl MethodHeader MethodBody MethodParams VOIDAux VarDeclStatement FormalParams CommaTypeId VarDecl VarDeclL StringArray Statement StatementL StatementCanError Assignment MethodInvocation ParseArgs Expr Type CommaExpr IDAux

%%

Program: CLASS IDAux OBRACE Declaration CBRACE                       {$$ = ast = create_and_insert_node("Program", 1, 2, $2, $4);}

Declaration: Declaration FieldDecl                                   {$$ = $2;}
           | Declaration MethodDecl                                  {$$ = $2;}
           | Declaration SEMI                                        {;}
           |                                                         {$$ = NULL;}

FieldDecl: PUBLIC STATIC Type FieldDeclL SEMI                        {ast_fielddecl($3, $4); $$ = $4;}
         | error SEMI                                                {$$ = NULL;}

FieldDeclL: IDAux                                                    {$$ = create_and_insert_node("FieldDecl", 1, 1, $1);}
          | FieldDeclL COMMA IDAux                                   {$$ = create_and_insert_node("FieldDecl", 0, 2, $1, $3);}

MethodDecl: PUBLIC STATIC MethodHeader MethodBody                    {$$ = create_and_insert_node("MethodDecl", 1, 2, $3, $4);}

MethodHeader: Type IDAux OCURV MethodParams CCURV                    {$$ = create_and_insert_node("MethodHeader", 1, 3, $1, $2, $4);}
            | VOIDAux IDAux OCURV MethodParams CCURV                 {$$ = create_and_insert_node("MethodHeader", 1, 3, $1, $2, $4);}

VOIDAux: VOID                                                        {$$=create_terminal_node("Void", 1, $1);}

MethodParams: FormalParams                                           {$$ = create_and_insert_node("MethodParams", 1, 1, $1);}
            |                                                        {$$ = NULL;}

MethodBody: OBRACE VarDeclStatement CBRACE                           {$$ = create_and_insert_node("MethodBody", 1, 1, $2);}

VarDeclStatement: VarDeclStatement VarDecl                           {$$ = create_and_insert_node("MethodBody", 0, 2, $1, $2);}
                | VarDeclStatement Statement                         {$$ = create_and_insert_node("MethodBody", 0, 2, $1, $2);}
                |                                                    {$$ = NULL;}

FormalParams: Type IDAux CommaTypeId                                 {$$ = create_and_insert_node("ParamDecl", 1, 2, $1, $2);}
            | StringArray OSQUARE CSQUARE IDAux                      {$$ = create_and_insert_node("ParamDecl", 1, 2, $1, $4);}

StringArray: STRING                                                  {$$ = create_and_insert_node("StringArray", 1, 0);}

CommaTypeId: CommaTypeId COMMA Type IDAux                            {;}
           |                                                         {$$ = NULL;}

VarDecl: Type VarDeclL SEMI                                          {if ($2 != NULL) { ast_fielddecl($1, $2); $$ = $2; } else { $$ = $2; } }

VarDeclL: VarDeclL COMMA IDAux                                       {$$ = create_and_insert_node("VarDecl", 0, 2, $1, $3);}
        | IDAux                                                      {$$ = $1;}

Statement: OBRACE StatementL CBRACE                                  {if($2 != NULL && $2->n_children >= 2) { $$ = create_and_insert_node("Block", 1, 1, $2); } else { $$ = $2; }}
         | IF OCURV Expr CCURV Statement ELSE Statement              {$$ = create_and_insert_node("If", 1, 3, $3, $5, $7);}
         | IF OCURV Expr CCURV Statement %prec IF_NO_ELSE            {node *null_node = create_and_insert_node("Null", 1, 0); $$ = create_and_insert_node("If", 1, 3, $3, $5, null_node);}
         | WHILE OCURV Expr CCURV Statement                          {printf("#########");$$ = create_and_insert_node("While", 1, 2, $3, $5);}
         | DO Statement WHILE OCURV Expr CCURV SEMI                  {$$ = create_and_insert_node("DoWhile", 1, 2, $2, $5);}
         | PRINT OCURV Expr CCURV SEMI                               {$$ = create_and_insert_node("Print", 1, 1, $3);}
         | PRINT OCURV STRLIT CCURV SEMI                             {$$ = create_and_insert_node("Print", 1, 1, $3);}
         | IDAux ASSIGN Expr SEMI                                    {$$ = create_and_insert_node("Assign", 1, 2, $1, $3);}
         | MethodInvocation SEMI                                     {$$ = create_and_insert_node("Call", 1, 1, $1);}
         | ParseArgs SEMI                                            {$$ = create_and_insert_node("ParseArgs", 1, 1, $1);}
         | SEMI                                                      {;}
         | RETURN Expr SEMI                                          {$$ = create_and_insert_node("Return", 1, 1, $2);}
         | RETURN SEMI                                               {$$ = create_and_insert_node("Return", 1, 0);}

 StatementCanError: Statement { $$ = $1; }
                  | error SEMI { $$ = NULL; }
                  ;

StatementL: StatementL StatementCanError {if ($1 == NULL && $2 != NULL) { $$ = create_and_insert_node("Block", 0, 1, $2); } else if ($1 != NULL && $2 == NULL) { $$ = create_and_insert_node("Block", 0, 1, $1); } else if ($1 != NULL && $2 != NULL) $$ = create_and_insert_node("Block", 0, 2, $1, $2); else { $$ = NULL; } }
             | StatementCanError               {$$ = create_and_insert_node("Block", 0, 1, $1); }

/*
StatementL: StatementL Statement                                      {if ($2 != NULL && $2->n_children >= 2) { $$ = create_and_insert_node("Block", 1, 1, $2); } else { $$ = $2; }}
          |                                                           {$$ = NULL;}
*/

Assignment: IDAux ASSIGN Expr                                         {$$ = create_and_insert_node("Assign", 1, 2, $1, $3);}

MethodInvocation: IDAux OCURV Expr CommaExpr CCURV                    {$$ = create_and_insert_node("Call", 0, 3, $1, $3, $4);}
                | IDAux OCURV CCURV                                   {$$ = create_and_insert_node("Call", 0, 1, $1);}
                | IDAux OCURV error CCURV                             {$$ = NULL;}

CommaExpr: CommaExpr COMMA Expr                                       {$$ = create_and_insert_node("Call", 0, 2, $1, $3);}
         |                                                            {$$ = NULL;}

ParseArgs: PARSEINT OCURV IDAux OSQUARE Expr CSQUARE CCURV            {$$ = create_and_insert_node("ParseArgs", 0, 2, $3, $5);}
         | PARSEINT OCURV error CCURV                                 {$$ = NULL;}

Expr: Assignment                                                    {$$ = create_and_insert_node("Assign", 1, 1, $1);}
    | MethodInvocation                                              {$$ = create_and_insert_node("Call", 1, 1, $1);}
    | ParseArgs                                                     {$$ = create_and_insert_node("ParseArgs", 1, 1, $1);}
    | Expr AND Expr                                                 {$$ = create_and_insert_node("And", 1, 2, $1, $3);}
    | Expr OR Expr                                                  {$$ = create_and_insert_node("Or", 1, 2, $1, $3);}
    | Expr EQ Expr                                                  {$$ = create_and_insert_node("Eq", 1, 2, $1, $3);}
    | Expr GEQ Expr                                                 {$$ = create_and_insert_node("Geq", 1, 2, $1, $3);}
    | Expr GT Expr                                                  {$$ = create_and_insert_node("Gt", 1, 2, $1, $3);}
    | Expr LEQ Expr                                                 {$$ = create_and_insert_node("Leq", 1, 2, $1, $3);}
    | Expr LT Expr                                                  {$$ = create_and_insert_node("Lt", 1, 2, $1, $3);}
    | Expr NEQ Expr                                                 {$$ = create_and_insert_node("Neq", 1, 2, $1, $3);}
    | Expr PLUS Expr                                                {$$ = create_and_insert_node("Add", 1, 2, $1, $3);}
    | Expr MINUS Expr %prec UNARY                                   {$$ = create_and_insert_node("Sub", 1, 2, $1, $3);}
    | Expr STAR Expr                                                {$$ = create_and_insert_node("Mul", 1, 2, $1, $3);}
    | Expr DIV Expr                                                 {$$ = create_and_insert_node("Div", 1, 2, $1, $3);}
    | Expr MOD Expr                                                 {$$ = create_and_insert_node("Mod", 1, 2, $1, $3);}
    | PLUS Expr                                                     {$$ = create_and_insert_node("Plus", 1, 2, $2);}
    | MINUS Expr                                                    {$$ = create_and_insert_node("Minus", 1, 2, $2);}
    | NOT Expr                                                      {$$ = create_and_insert_node("Not", 1, 2, $2);}
    | IDAux                                                         {;}
    | IDAux DOTLENGTH                                               {;}
    | OCURV Expr CCURV                                              {$$ = $2;}
    | BOOLLIT                                                       {$$=create_terminal_node("BoolLit", 1, $1);}
    | DECLIT                                                        {$$=create_terminal_node("DecLit", 1, $1);}
    | REALLIT                                                       {$$=create_terminal_node("RealLit", 1, $1);}
    | OCURV error CCURV                                             {$$ = NULL;}

Type: BOOL                                                          {$$=create_terminal_node("Bool", 1, $1);}
    | INT                                                           {$$=create_terminal_node("Int", 1, $1);}
    | DOUBLE                                                        {$$=create_terminal_node("Double", 1, $1);}


IDAux: ID                                                            {$$=create_terminal_node("Id", 1, $1);}

%%

void yyerror(const char *s) {
	printf("Line %d, col %d: %s: %s\n", line, col - yyleng, s, yytext);
}
