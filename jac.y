%{
  #include <stdio.h>
  #include <string.h>
  void yyerror();
  int yylex();

  extern char* yytext;
  extern int line, col, yyleng;
%}


%union{
  char* token;
}

%token BOOL BOOLLIT CLASS DO DOTLENGTH DOUBLE ELSE IF INT PARSEINT PRINT PUBLIC
%token RETURN STATIC STRING VOID WHILE OCURV CCURV OBRACE CBRACE
%token OSQUARE CSQUARE AND OR LT GT EQ NEQ LEQ GEQ PLUS MINUS STAR DIV MOD NOT
%token ASSIGN SEMI COMMA RESERVED DECLIT REALLIT STRLIT ID

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

%%

Program: CLASS ID OBRACE Declaration CBRACE

Declaration: Declaration FieldDecl
           | Declaration MethodDecl
           | Declaration SEMI
           |

FieldDecl: PUBLIC STATIC Type ID CommaId SEMI
         | error SEMI

MethodDecl: PUBLIC STATIC MethodHeader MethodBody

MethodHeader: Type ID OCURV FormalParams CCURV
            | VOID ID OCURV FormalParams CCURV

MethodBody: OBRACE VarDeclStatement CBRACE

VarDeclStatement: VarDeclStatement VarDecl
                | VarDeclStatement Statement
                |

FormalParams: Type ID CommaTypeId
            | STRING OSQUARE CSQUARE ID
            |

CommaTypeId: CommaTypeId COMMA Type ID
           |

VarDecl: Type ID CommaId SEMI

CommaId: CommaId COMMA ID
       |

Statement: OBRACE StatementL CBRACE
         | IF OCURV Expr CCURV Statement ELSE Statement
         | IF OCURV Expr CCURV Statement %prec IF_NO_ELSE
         | WHILE OCURV Expr CCURV Statement
         | DO Statement WHILE OCURV Expr CCURV SEMI
         | PRINT OCURV Expr CCURV SEMI
         | PRINT OCURV STRLIT CCURV SEMI
         | AssignmentMethodInvocationParseArgs SEMI
         | RETURN Expr SEMI
         | RETURN SEMI
         | error SEMI

StatementL: StatementL Statement
          |

Assignment: ID ASSIGN Expr

MethodInvocation: ID OCURV ExprCommaExpr CCURV
                | ID OCURV error CCURV

ParseArgs: PARSEINT OCURV ID OSQUARE Expr CSQUARE CCURV
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
    | MINUS Expr %prec UNARY
    | NOT Expr
    | ID
    | ID DOTLENGTH
    | OCURV Expr CCURV
    | BOOLLIT
    | DECLIT
    | REALLIT
    | OCURV error CCURV

Type: BOOL
    | INT
    | DOUBLE


ExprCommaExpr: Expr CommaExpr
             |

CommaExpr: CommaExpr COMMA Expr
         |

AssignmentMethodInvocationParseArgs: Assignment
                                   | MethodInvocation
                                   | ParseArgs
                                   |
%%

void yyerror(const char *s) {
	printf("Line %d, col %d: %s: %s\n", line, col - yyleng, s, yytext);
}
