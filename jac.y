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
  char *id;
  struct node *node;
}

%token BOOL BOOLLIT CLASS DO DOTLENGTH DOUBLE ELSE IF INT PARSEINT PRINT PUBLIC
%token RETURN STATIC STRING VOID WHILE OCURV CCURV OBRACE CBRACE
%token OSQUARE CSQUARE AND OR LT GT EQ NEQ LEQ GEQ PLUS MINUS STAR DIV MOD NOT
%token ASSIGN SEMI COMMA RESERVED DECLIT REALLIT STRLIT
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

%type <node> Program Declaration FieldDecl MethodDecl MethodHeader MethodBody VarDeclStatement FormalParams CommaTypeId VarDecl CommaId Statement StatementL Assignment MethodInvocation ParseArgs Expr Type ExprCommaExpr CommaExpr IDAux

%%

Program: CLASS IDAux OBRACE Declaration CBRACE                       {$$ = ast = create_and_insert_node("Program", 1, 2, $2, $4);}

Declaration: Declaration FieldDecl                                   {$$ = create_and_insert_node("FieldDecl", 1, 2, $1, $2);}
           | Declaration MethodDecl                                  {$$ = create_and_insert_node("MethodDecl", 1, 2, $1, $2);}
           | Declaration SEMI
           |                                                         {$$ = create_terminal_node("Empty", 0, NULL);}

FieldDecl: PUBLIC STATIC Type IDAux CommaId SEMI                     {$$ = create_and_insert_node("FieldDecl", 0, 2, $3, $4);}
         | error SEMI

MethodDecl: PUBLIC STATIC MethodHeader MethodBody                    {$$ = create_and_insert_node("MethodDecl", 0, 2, $3, $4);}

MethodHeader: Type IDAux OCURV MethodParams CCURV                    {$$ = create_and_insert_node("MethodHeader", 1, 3, $1, $2, $4);}
            | VOID IDAux OCURV MethodParams CCURV                    {$$ = create_and_insert_node("MethodHeader", 1, 3, $1, $2, $4);}

MethodParams: FormalParams                                           {$$ = create_and_insert_node("MethodParams"), 1, 1, $1);}
            |                                                        {$$ = create_terminal_node("Empty", 0, NULL);}

MethodBody: OBRACE VarDeclStatement CBRACE                           {$$ = create_and_insert_node("MethodBody", 1, 1, $2);}

VarDeclStatement: VarDeclStatement VarDecl                           {$$ = create_and_insert_node("MethodBody", 0, 2, $1, $2);}
                | VarDeclStatement Statement                         {$$ = create_and_insert_node("MethodBody", 0, 2, $1, $2);}
                |                                                    {$$ = create_terminal_node("Empty", 0, NULL);}

FormalParams: Type IDAux CommaTypeId                                 {$$ = create_and_insert_node("ParamDecl", 1, 2, $1, $2);}
            | STRING OSQUARE CSQUARE IDAux                           {$$ = create_and_insert_node("ParamDecl", 1, 2, $1, $4);}
            |                                                        {$$ = create_terminal_node("Empty", 0, NULL);}

CommaTypeId: CommaTypeId COMMA Type IDAux                            {}
           |                                                         {$$ = create_terminal_node("Empty", 0, NULL);}

VarDecl: Type IDAux CommaId SEMI                                     {$$ = create_and_insert_node("VarDecl", 1, 2, $1, $2);}

CommaId: CommaId COMMA IDAux
       |

Statement: OBRACE StatementL CBRACE                                  {$$ = create_and_insert_node("Block", 1, 1, $2);}
         | IF OCURV Expr CCURV Statement ELSE Statement
         | IF OCURV Expr CCURV Statement %prec IF_NO_ELSE
         | WHILE OCURV Expr CCURV Statement
         | DO Statement WHILE OCURV Expr CCURV SEMI
         | PRINT OCURV Expr CCURV SEMI
         | PRINT OCURV STRLIT CCURV SEMI
         | Assignment SEMI
         | MethodInvocation SEMI
         | ParseArgs SEMI
         | SEMI
         | RETURN Expr SEMI
         | RETURN SEMI
         | error SEMI

StatementL: StatementL Statement
          |

Assignment: IDAux ASSIGN Expr

MethodInvocation: IDAux OCURV ExprCommaExpr CCURV
                | IDAux OCURV error CCURV

ParseArgs: PARSEINT OCURV IDAux OSQUARE Expr CSQUARE CCURV
         | PARSEINT OCURV error CCURV

Expr: Assignment
    | MethodInvocation
    | ParseArgs
    | Expr AND Expr
    | Expr OR Expr
    | Expr EQ Expr
    | Expr GEQ Expr
    | Expr GT Expr
    | Expr LEQ Expr
    | Expr LT Expr
    | Expr NEQ Expr
    | Expr PLUS Expr
    | Expr MINUS Expr %prec UNARY
    | Expr STAR Expr
    | Expr DIV Expr
    | Expr MOD Expr
    | PLUS Expr
    | MINUS Expr
    | NOT Expr
    | IDAux
    | IDAux DOTLENGTH
    | OCURV Expr CCURV
    | BOOLLIT
    | DECLIT
    | REALLIT
    | OCURV error CCURV

Type: BOOL                                                {$$=create_terminal_node("Bool", 1, NULL);}
    | INT                                                 {$$=create_terminal_node("Int", 1, NULL);}
    | DOUBLE                                              {$$=create_terminal_node("Double", 1, NULL);}


ExprCommaExpr: Expr CommaExpr
             |

CommaExpr: CommaExpr COMMA Expr
         |

IDAux: ID                                                {$$=create_terminal_node("Id", 1, $1);}

%%

void yyerror(const char *s) {
	printf("Line %d, col %d: %s: %s\n", line, col - yyleng, s, yytext);
}
