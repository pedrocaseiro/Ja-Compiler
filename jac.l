%{
  #include<stdio.h>
  #include<ctype.h>
  static int col = 1;
  static int comment_start_col = 0;
  static int comment_start_line = 0;
  static int string_start_col = 0;
  static int string_start_line = 0;
%}

%option yylineno

%X MULTILINECOMMENT
%X COMMENT
%X STRING

id                  [a-zA-Z_$][a-zA-Z_$0-9]*
declit              0|[1-9]+("_"*[0-9]+)*
reallit             [0-9]("_"*[0-9]+)*"."([0-9]("_"*[0-9]+)*)?([eE][+-]?[0-9]("_"*[0-9]+)*)?|"."([0-9]("_"*[0-9]+)*)([eE][+-]?[0-9]("_"*[0-9]+)*)?|[0-9]+("_"*[0-9]+)*[eE][+-]?[0-9]("_"*[0-9]+)*
escape              \\(f|n|r|t|\\|\")
strlit              \"({escape}|[^\n\r\"\\])*\"
reserved            "++"|"--"|"null"|"Integer"|"System"|"abstract"|"assert"|"break"|"byte"|"case"|"catch"|"char"|"const"|"continue"|"default"|"enum"|"extends"|"final"|"finally"|"float"|"for"|"goto"|"implements"|"import"|"instanceof"|"interface"|"long"|"native"|"new"|"package"|"private"|"protected"|"short"|"strictfp"|"super"|"switch"|"synchronized"|"this"|"throw"|"throws"|"transient"|"try"|"volatile"

%%
"/*" {BEGIN MULTILINECOMMENT; comment_start_col = col; comment_start_line = yylineno; col+=yyleng;}
<MULTILINECOMMENT><<eof>> {printf("Line %d, col %d: unterminated comment\n", comment_start_line, comment_start_col); col=1; return 0;}
<MULTILINECOMMENT>"*/"  {col+=yyleng; BEGIN 0;}
<MULTILINECOMMENT>\n    {col=1;}
<MULTILINECOMMENT>.     {col+=yyleng;}

"//" {BEGIN COMMENT;}
<COMMENT>"\n"|"\r" {col=1; BEGIN 0;}
<COMMENT>.    {col+=yyleng;}

"\"" {BEGIN STRING; string_start_col = col; string_start_line = yylineno; col+=yyleng;}
<STRING>\\[^nrft\\\"("\n")("\r")] {printf("Line %d, col %d: invalid escape sequence (%s)\n", yylineno, col, yytext); col+=yyleng;}
<STRING>"\""          {col+=yyleng; BEGIN 0;}
<STRING>"\n"          {printf("Line %d, col %d: unterminated string literal\n", string_start_line,string_start_col); col=1; BEGIN 0;}
<STRING>.             {col+=yyleng;}


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
" "                  {col+=1;}
\t                   {col+=1;}
\r                   {col=1;}
\n                   {col=1;}
\f                   {col+=1;}
\r\f                 {col=1;}
{reserved}           {printf("RESERVED(%s)\n", yytext); col+=yyleng;}
{declit}             {printf("DECLIT(%s)\n", yytext); col +=yyleng;}
{reallit}            {printf("REALLIT(%s)\n", yytext); col+=yyleng;}
{strlit}             {printf("STRLIT(%s)\n", yytext); col+=yyleng;}
{id}                 {printf("ID(%s)\n", yytext); col+=yyleng;}
<<eof>>              {col=1; return 0;}
.                    {printf("Line %d, col %d: illegal character (%c)\n", yylineno, col, yytext[0]);col+=yyleng;}
%%
int main(int argc, char **argv) {
  yylex();
  return 0;
}

int yywrap() {
  return 1;
}
