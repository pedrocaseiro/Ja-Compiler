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
           | Declaration MethodDecl
           | Declaration SEMI
           |                                                         {$$ = create_terminal_node("Empty", 0, NULL);}

FieldDecl: PUBLIC STATIC Type IDAux CommaId SEMI                     {$$ = create_and_insert_node("FieldDecl", 0, 2, $3, $4);}
         | error SEMI

MethodDecl: PUBLIC STATIC MethodHeader MethodBody

MethodHeader: Type IDAux OCURV FormalParams CCURV
            | VOID IDAux OCURV FormalParams CCURV

MethodBody: OBRACE VarDeclStatement CBRACE

VarDeclStatement: VarDeclStatement VarDecl
                | VarDeclStatement Statement
                |

FormalParams: Type IDAux CommaTypeId
            | STRING OSQUARE CSQUARE IDAux
            |

CommaTypeId: CommaTypeId COMMA Type IDAux
           |

VarDecl: Type IDAux CommaId SEMI

CommaId: CommaId COMMA IDAux
       |

Statement: OBRACE StatementL CBRACE
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
