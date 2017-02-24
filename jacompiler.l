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
whitespace          [ \n\t\f\r]

%%
{whitespace}        {;}
%%
int main(int argc, char **argv) {
  yylex();
  return 0;
}

int yywrap() {
  return 1;
}
