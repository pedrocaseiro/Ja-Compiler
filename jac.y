%{
  #include <stdio.h>
  #include <string.h>
%}

%token BOOL BOOLLIT CLASS DO DOTLENGTH DOUBLE ELSE IF INT PARSEINT PRINT PUBLIC
%token RETURN STATIC STRING VOID WHILE OCURV CCURV OBRACE CBRACE
%token OSQUARE CSQUARE AND OR LT GT EQ NEQ LEQ GEQ PLUS MINUS STAR DIV MOD NOT
%token ASSIGN SEMI COMMA RESERVED DECLIT REALLIT STRLIT ID

%%

Program: CLASS ID OBRACE Declaration CBRACE

Declaration: Declaration FieldDecl
           | Declaration MethodDecl
           | Declaration SEMI
           | %empty

FieldDecl: PUBLIC STATIC Type ID CommaId SEMI

MethodDecl: PUBLIC STATIC MethodHeader MethodBody

MethodHeader: Type ID OCURV FormalParams CCURV
            | Type Id OCURV CCURV
            | VOID ID OCURV FormalParams CCURV
            | VOID ID OCURV CCURV

MethodBody: OBRACE VarDeclStatement CBRACE

VarDeclStatement: VarDeclStatement VarDecl
              | VarDeclStatement Statement
              | %empty

FormalParams: Type ID CommaTypeId
            | STRING OSQUARE CSQUARE ID

CommaTypeId: CommaTypeId COMMA Type ID
           | %empty

VarDecl: Type ID CommaId SEMI

CommaId: CommaId COMMA ID
       | %empty

Type: BOOL
    | INT
    | DOUBLE

Statement: OBRACE StatementL CBRACE
         | IF OCURV Expr CCURV StatementL ElseStatement
         | WHILE OCURV Expr CCURV StatementL
         | DO StatementL WHILE OCURV Expr CCURV SEMI
         | PRINT OCURV ExprStrlit CCURV SEMI
         | AssignmentMethodInvocationParseArgs SEMI
         | RETURN ExprL SEMI

ElseStatement: ELSE StatementL

StatementL: OBRACE StatementL CBRACE
          | IF OCURV Expr CCURV StatementL ElseStatement
          | WHILE OCURV Expr CCURV StatementL
          | DO StatementL WHILE OCURV Expr CCURV SEMI
          | PRINT OCURV ExprStrlit CCURV SEMI
          | AssignmentMethodInvocationParseArgs SEMI
          | RETURN ExprL SEMI
          | %empty

Assignment: ID ASSIGN Expr

MethodInvocation: ID OCURV ExprCommaExpr CCURV

ParseArgs: PARSEINT OCURV ID OSQUARE Expr CSQUARE CCURV

Expr: AssignmentMethodInvocationParseArgsNotEmpty
    | ExprL AndOr Exprl
    | ExprL EqGeqGtLeqLtNeq ExprL
    | ExprL PlusMinusStarDivMod ExprL
    | PlusMinusNot ExprL
    | ID Dotlength
    | OCURV ExprL CCURV
    | BoollitDeclitReallit

ExprL: AssignmentMethodInvocationParseArgsNotEmpty
    | ExprL AndOr Exprl
    | ExprL EqGeqGtLeqLtNeq ExprL
    | ExprL PlusMinusStarDivMod ExprL
    | PlusMinusNot ExprL
    | ID Dotlength
    | OCURV ExprL CCURV
    | BoollitDeclitReallit
    | %empty

BoollitDeclitReallit: BOOLLIT
                    | DECLIT
                    | REALLIT

DotLength: DOTLENGTH
         | %empty

PlusMinusNot: PLUS
            | MINUS
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
             | %empty

CommaExpr: CommaExpr COMMA Expr
         | %empty

ExprStrlit: Expr
          | STRLIT
          | %empty

AssignmentMethodInvocationParseArgs: Assignment
                                   | MethodInvocation
                                   | ParseArgs
                                   | %empty
