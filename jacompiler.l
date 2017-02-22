%{
  #include<stdio.h>
  #include<ctype.h>
  static int col = 1;

%}

%option yylineno
%X COMMENT
%X ERRORS

int                 [0-9]+
float               [0-9]+.[0-9]+ 





%%
%%
int main() {
  yylex();
  return 0;
}

int yywrap() {
  return 1;
}
