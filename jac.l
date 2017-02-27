%{
  #include<stdio.h>
  #include<ctype.h>
  static int col = 1;
  static int line = 1;
  static int comment_start_col = 0;
  static int comment_start_line = 0;
  static int string_start_col = 0;
  static int string_start_line = 0;
  static int input_flag = 0;
%}

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
"/*" {BEGIN MULTILINECOMMENT; comment_start_col = col; comment_start_line = line; col+=yyleng;}
<MULTILINECOMMENT><<eof>> {printf("Line %d, col %d: unterminated comment\n", comment_start_line, comment_start_col); col=1; line=1; return 0;}
<MULTILINECOMMENT>"*/"  {col+=yyleng; BEGIN 0;}
<MULTILINECOMMENT>\n    {col=1; line+=1;}
<MULTILINECOMMENT>\r    {col=1; line+=1;}
<MULTILINECOMMENT>\r\n  {col=1; line+=1;}
<MULTILINECOMMENT>.     {col+=yyleng;}

"//" {BEGIN COMMENT;}
<COMMENT>"\n"|"\r" {col=1; line+=1; BEGIN 0;}
<COMMENT>.    {col+=yyleng;}

"\"" {BEGIN STRING; string_start_col = col; string_start_line = line; col+=yyleng;}
<STRING>\\[^nrft\\\"("\n")("\r")] {printf("Line %d, col %d: invalid escape sequence (%s)\n", line, col, yytext); col+=yyleng;}
<STRING>"\""          {col+=yyleng; BEGIN 0;}
<STRING>"\n"          {printf("Line %d, col %d: unterminated string literal\n", string_start_line,string_start_col); col=1; line+=1; BEGIN 0;}
<STRING>.             {col+=yyleng;}


"boolean"            {if(input_flag) printf("BOOL\n"); col+=yyleng;}
"true"|"false"       {if(input_flag) printf("BOOLLIT(%s)\n", yytext); col+=yyleng;}
"class"              {if(input_flag) printf("CLASS\n"); col+=yyleng;}
"do"                 {if(input_flag) printf("DO\n"); col+=yyleng;}
".length"            {if(input_flag) printf("DOTLENGTH\n"); col+=yyleng;}
"double"             {if(input_flag) printf("DOUBLE\n"); col+=yyleng;}
"else"               {if(input_flag) printf("ELSE\n"); col+=yyleng;}
"if"                 {if(input_flag) printf("IF\n"); col+=yyleng;}
"int"                {if(input_flag) printf("INT\n"); col+=yyleng;}
"Integer.parseInt"   {if(input_flag) printf("PARSEINT\n"); col+=yyleng;}
"System.out.println" {if(input_flag) printf("PRINT\n"); col+=yyleng;}
"public"             {if(input_flag) printf("PUBLIC\n"); col+=yyleng;}
"return"             {if(input_flag) printf("RETURN\n"); col+=yyleng;}
"static"             {if(input_flag) printf("STATIC\n"); col+=yyleng;}
"String"             {if(input_flag) printf("STRING\n"); col+=yyleng;}
"void"               {if(input_flag) printf("VOID\n"); col+=yyleng;}
"while"              {if(input_flag) printf("WHILE\n"); col+=yyleng;}
"("                  {if(input_flag) printf("OCURV\n"); col+=yyleng;}
")"                  {if(input_flag) printf("CCURV\n"); col+=yyleng;}
"{"                  {if(input_flag) printf("OBRACE\n"); col+=yyleng;}
"}"                  {if(input_flag) printf("CBRACE\n"); col+=yyleng;}
"["                  {if(input_flag) printf("OSQUARE\n"); col+=yyleng;}
"]"                  {if(input_flag) printf("CSQUARE\n"); col+=yyleng;}
"&&"                 {if(input_flag) printf("AND\n"); col+=yyleng;}
"||"                 {if(input_flag) printf("OR\n"); col+=yyleng;}
"<"                  {if(input_flag) printf("LT\n"); col+=yyleng;}
">"                  {if(input_flag) printf("GT\n"); col+=yyleng;}
"=="                 {if(input_flag) printf("EQ\n"); col+=yyleng;}
"!="                 {if(input_flag) printf("NEQ\n"); col+=yyleng;}
"<="                 {if(input_flag) printf("LEQ\n"); col+=yyleng;}
">="                 {if(input_flag) printf("GEQ\n"); col+=yyleng;}
"+"                  {if(input_flag) printf("PLUS\n"); col+=yyleng;}
"-"                  {if(input_flag) printf("MINUS\n"); col+=yyleng;}
"*"                  {if(input_flag) printf("STAR\n"); col+=yyleng;}
"/"                  {if(input_flag) printf("DIV\n"); col+=yyleng;}
"%"                  {if(input_flag) printf("MOD\n"); col+=yyleng;}
"!"                  {if(input_flag) printf("NOT\n"); col+=yyleng;}
"="                  {if(input_flag) printf("ASSIGN\n"); col+=yyleng;}
";"                  {if(input_flag) printf("SEMI\n"); col+=yyleng;}
","                  {if(input_flag) printf("COMMA\n"); col+=yyleng;}
" "                  {col+=1;}
\t                   {col+=1;}
\r                   {col=1; line +=1;}
\n                   {col=1; line+=1;}
\f                   {col+=1;}
\r\n                 {col=1; line+=1;}
{reserved}           {if(input_flag) printf("RESERVED(%s)\n", yytext); col+=yyleng;}
{declit}             {if(input_flag) printf("DECLIT(%s)\n", yytext); col +=yyleng;}
{reallit}            {if(input_flag) printf("REALLIT(%s)\n", yytext); col+=yyleng;}
{strlit}             {if(input_flag) printf("STRLIT(%s)\n", yytext); col+=yyleng;}
{id}                 {if(input_flag) printf("ID(%s)\n", yytext); col+=yyleng;}
<<eof>>              {col=1; return 0;}
.                    {printf("Line %d, col %d: illegal character (%c)\n", line, col, yytext[0]);col+=yyleng;}
%%
int main(int argc, char **argv) {
  if(argc > 1){
    if (strcmp(argv[1], "-l") || strcmp(argv[1], "-1")) {
      input_flag = 1;
    }
  }
  yylex();
  return 0;
}

int yywrap() {
  return 1;
}
