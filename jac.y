%{
  #include <stdio.h>
  #include <string.h>
  int yyerror();
  int yylex();
%}


%union{
  char* token;
}

%token BOOL BOOLLIT CLASS DO DOTLENGTH DOUBLE ELSE IF INT PARSEINT PRINT PUBLIC
%token RETURN STATIC STRING VOID WHILE OCURV CCURV OBRACE CBRACE
%token OSQUARE CSQUARE AND OR LT GT EQ NEQ LEQ GEQ PLUS MINUS STAR DIV MOD NOT
%token ASSIGN SEMI COMMA RESERVED DECLIT REALLIT STRLIT ID

%right ASSIGN
%left OR
%left AND
%left EQ NEQ
%left GT LT GEQ LEQ
%left PLUS MINUS
%left STAR DIV MOD
%right UNARY
%right NOT
%left OBRACE CBRACE 

%nonassoc ELSE
%nonassoc IF_NO_ELSE

%%

Program: CLASS ID OBRACE Declaration CBRACE

Declaration: Declaration FieldDecl
           | Declaration MethodDecl
           | Declaration SEMI
           | 

FieldDecl: PUBLIC STATIC Type ID CommaId SEMI

MethodDecl: PUBLIC STATIC MethodHeader MethodBody

MethodHeader: Type ID OCURV FormalParams CCURV
            | Type ID OCURV CCURV
            | VOID ID OCURV FormalParams CCURV
            | VOID ID OCURV CCURV

MethodBody: OBRACE VarDeclStatement CBRACE

VarDeclStatement: VarDeclStatement VarDecl
                | VarDeclStatement Statement
                | 

FormalParams: Type ID CommaTypeId
            | STRING OSQUARE CSQUARE ID

CommaTypeId: CommaTypeId COMMA Type ID
           | 

VarDecl: Type ID CommaId SEMI

CommaId: CommaId COMMA ID
       | 

Type: BOOL
    | INT
    | DOUBLE

Statement: OBRACE StatementL CBRACE
         | IF OCURV Expr CCURV Statement ElseStatement
         | WHILE OCURV Expr CCURV Statement
         | DO Statement WHILE OCURV Expr CCURV SEMI
         | PRINT OCURV ExprStrlit CCURV SEMI
         | AssignmentMethodInvocationParseArgs SEMI
         | RETURN Expr SEMI
         | RETURN SEMI
         | error SEMI

StatementL: Statement StatementL
          |

ElseStatement: ELSE Statement %prec IF_NO_ELSE

Assignment: ID ASSIGN Expr

MethodInvocation: ID OCURV ExprCommaExpr CCURV

ParseArgs: PARSEINT OCURV ID OSQUARE Expr CSQUARE CCURV

DotLength: DOTLENGTH
         | 

Expr: AssignmentMethodInvocationParseArgsNotEmpty
    | Expr AndOr Expr
    | Expr EqGeqGtLeqLtNeq Expr
    | Expr PlusMinusStarDivMod Expr
    | PlusMinusNot Expr
    | ID DotLength
    | OCURV Expr CCURV
    | BoollitDeclitReallit

BoollitDeclitReallit: BOOLLIT
                    | DECLIT
                    | REALLIT

PlusMinusNot: PLUS
            | MINUS %prec UNARY
            | NOT

PlusMinusStarDivMod: PLUS
                   | MINUS
                   | STAR
                   | DIV
                   | MOD

EqGeqGtLeqLtNeq: EQ
               | GEQ
               | GT
               | LEQ
               | NEQ

AndOr: OR
     | AND

AssignmentMethodInvocationParseArgsNotEmpty: Assignment
                                           | MethodInvocation
                                           | ParseArgs

ExprCommaExpr: Expr CommaExpr
             | 

CommaExpr: CommaExpr COMMA Expr
         | 

ExprStrlit: Expr
          | STRLIT
          | 

AssignmentMethodInvocationParseArgs: Assignment
                                   | MethodInvocation
                                   | ParseArgs
                                   | 
