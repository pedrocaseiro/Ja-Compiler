%{
  #include<stdio.h>
  #include<ctype.h>
  static int col = 1;
%}

id                  [a-zA-Z_$][a-zA-Z_$0-9]*
declit              0|[1-9]+("_"*[0-9]+)*
reallit             [1-9]+("_"*[0-9]+)*"."[0-9]+("_"[0-9]+)*([eE][+-]?)*0+[0_]*|[1-9]+("_"*[0-9]+)*"."[0-9]*([eE][+-]?)*[1-9]+("_"[0-9]+)*|"."[0-9]+("_"[0-9]+)*([eE][+-]?)*0+[0_]*|"."[0-9]+("_"[0-9]+)*([eE][+-]?)*0+[0_]*|[1-9]+("_"*[0-9]+)*([eE][+-]?)*[1-9]+("_"[0-9]+)*|[1-9]+("_"*[0-9]+)*([eE][+-]?)*0+[0_]*
escape              \\(f|n|r|t|\\|\")
strlit              \"({escape}|[^\n\r\"])*\"

whitespace          [ \n\t\f\r]*
reserved            "++"|"--"|"null"|"Integer"|"System"|"abstract"|"assert"|"break"|"byte"|"case"|"catch"|"char"|"const"|"continue"|"default"|"enum"|"extends"|"final"|"finally"|"for"|"goto"|"implements"|"import"|"instanceof"|"interface"|"long"|"native"|"new"|"package"|"private"|"protected"|"short"|"strictfp"|"super"|"switch"|"synchronized"|"this"|"throw"|"throws"|"transient"|"try"|"volatile"

%%
"boolean"            {printf("BOOL\n"); col+=yyleng;}
"true"|"false"       {printf("BOOLLIT(%s)\n", yytext); col+=yyleng;}
"class"              {printf("CLASS\n"); col+=yyleng;}
"do"                 {printf("DO\n"); col+=yyleng;} 
".length"            {printf("DOTLENGTH\n"); col+=yyleng;}
"double"             {printf("DOUBLE\n"); col+=yyleng;}
"else"               {printf("ELSE\n"); col+=yyleng;}
"if"                 {printf("IF\n"); col+=yyleng;}
"int"                {printf("INT\n"); col+=yyleng;}
"Integer.parseInt"   {printf("PARSEINT\n"); col+=yyleng;}
"System.out.println" {printf("PRINT\n"); col+=yyleng;}
"public"             {printf("PUBLIC\n"); col+=yyleng;}
"return"             {printf("RETURN\n"); col+=yyleng;}
"static"             {printf("STATIC\n"); col+=yyleng;}
"String"             {printf("STRING\n"); col+=yyleng;}
"void"               {printf("VOID\n"); col+=yyleng;}
"while"              {printf("WHILE\n"); col+=yyleng;}
"("                  {printf("OCURV\n"); col+=yyleng;}
")"                  {printf("CCURV\n"); col+=yyleng;}
"{"                  {printf("OBRACE\n"); col+=yyleng;}
"}"                  {printf("CBRACE\n"); col+=yyleng;}
"["                  {printf("OSQUARE\n"); col+=yyleng;}
"]"                  {printf("CSQUARE\n"); col+=yyleng;}
"&&"                 {printf("AND\n"); col+=yyleng;}
"||"                 {printf("OR\n"); col+=yyleng;}
"<"                  {printf("LT\n"); col+=yyleng;}
">"                  {printf("GT\n"); col+=yyleng;}
"=="                 {printf("EQ\n"); col+=yyleng;}
"!="                 {printf("NEQ\n"); col+=yyleng;}
"<="                 {printf("LEQ\n"); col+=yyleng;}
">="                 {printf("GEQ\n"); col+=yyleng;}
"+"                  {printf("PLUS\n"); col+=yyleng;}
"-"                  {printf("MINUS\n"); col+=yyleng;}
"*"                  {printf("STAR\n"); col+=yyleng;}
"/"                  {printf("DIV\n"); col+=yyleng;}
"%"                  {printf("MOD\n"); col+=yyleng;}
"!"                  {printf("NOT\n"); col+=yyleng;}
"="                  {printf("ASSIGN\n"); col+=yyleng;}
";"                  {printf("SEMI\n"); col+=yyleng;}
","                  {printf("COMMA\n"); col+=yyleng;}

{whitespace}         {;}
{reserved}           {printf("RESERVED(%s)\n", yytext);}
{reallit}            {printf("REALLIT(%s)\n", yytext);}
{declit}             {printf("DECLIT(%s)\n", yytext);}
{strlit}             {printf("STRLIT(%s)\n", yytext);}
{id}                 {printf("ID(%s)\n", yytext);}
.                    {;}
%%
int main(int argc, char **argv) {
  yylex();
  return 0;
}

int yywrap() {
  return 1;
}
