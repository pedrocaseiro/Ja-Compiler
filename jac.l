%{
  #include <stdio.h>
  #include <ctype.h>
  #include <stdarg.h>
  #include "y.tab.h"
  #include "ast.h"
  int yyparse();
  int col = 1;
  int line = 1;
  static int comment_start_col = 0;
  static int comment_start_line = 0;
  static int string_start_col = 0;
  static int string_start_line = 0;
  static int input_flag = 0;

  extern node* ast;

%}

%X MULTILINECOMMENT
%X COMMENT
%X STRINGSTATE

id                  [a-zA-Z_$][a-zA-Z_$0-9]*
declit              0|[1-9]+("_"*[0-9]+)*
exponent            [eE][+-]?[0-9]("_"*[0-9]+)*
reallit             [0-9]("_"*[0-9]+)*"."([0-9]("_"*[0-9]+)*)?({exponent})?|"."([0-9]("_"*[0-9]+)*)({exponent})?|[0-9]+("_"*[0-9]+)*{exponent}
escape              \\(f|n|r|t|\\|\")
strlit              \"({escape}|[^\n\r\"\\])*\"
reserved            "++"|"--"|"null"|"Integer"|"System"|"abstract"|"assert"|"break"|"byte"|"case"|"catch"|"char"|"const"|"continue"|"default"|"enum"|"extends"|"final"|"finally"|"float"|"for"|"goto"|"implements"|"import"|"instanceof"|"interface"|"long"|"native"|"new"|"package"|"private"|"protected"|"short"|"strictfp"|"super"|"switch"|"synchronized"|"this"|"throw"|"throws"|"transient"|"try"|"volatile"

%%
"/*" {BEGIN MULTILINECOMMENT; comment_start_col = col; comment_start_line = line; col+=yyleng;}
<MULTILINECOMMENT><<eof>> {printf("Line %d, col %d: unterminated comment\n", comment_start_line, comment_start_col); col+=1; return 0;}
<MULTILINECOMMENT>"*/"  {col+=yyleng; BEGIN 0;}
<MULTILINECOMMENT>\n    {col=1; line+=1;}
<MULTILINECOMMENT>\r    {col=1; line+=1;}
<MULTILINECOMMENT>\r\n  {col=1; line+=1;}
<MULTILINECOMMENT>.     {col+=yyleng;}

"//" {BEGIN COMMENT;}
<COMMENT>"\n"|"\r" {col=1; line+=1; BEGIN 0;}
<COMMENT>\r\n      {col=1; line+=1; BEGIN 0;}
<COMMENT>.         {col+=yyleng;}

"\"" {BEGIN STRINGSTATE; string_start_col = col; string_start_line = line; col+=yyleng;}
<STRINGSTATE>({escape}|[^\"\\\n\r])*   {col+=yyleng;}
<STRINGSTATE>\\(.?)                    {printf("Line %d, col %d: invalid escape sequence (%s)\n", line, col, yytext); col+=yyleng;}
<STRINGSTATE>\n|\r|\r\n                {printf("Line %d, col %d: unterminated string literal\n", string_start_line , string_start_col); col = 1; line+=1; BEGIN 0;}
<STRINGSTATE>\"                        {col+=yyleng; BEGIN 0;}
<STRINGSTATE><<eof>>                   {printf("Line %d, col %d: unterminated string literal\n",string_start_line, string_start_col); col=1; return 0;}



"boolean"            {col+=yyleng; if(input_flag) { printf("BOOL\n"); } else { yylval.token =(char *) strdup(yytext); return BOOL;}}
"true"|"false"       {col+=yyleng; if(input_flag) { printf("BOOLLIT(%s)\n", yytext); } else { yylval.token =(char *) strdup(yytext); return BOOLLIT;}}
"class"              {col+=yyleng; if(input_flag) { printf("CLASS\n"); } else { yylval.token =(char *) strdup(yytext); return CLASS;}}
"do"                 {col+=yyleng; if(input_flag) { printf("DO\n"); } else { yylval.token =(char *) strdup(yytext); return DO;}}
".length"            {col+=yyleng; if(input_flag) { printf("DOTLENGTH\n"); } else { yylval.token =(char *) strdup(yytext); return DOTLENGTH;}}
"double"             {col+=yyleng; if(input_flag) { printf("DOUBLE\n"); } else { yylval.token =(char *) strdup(yytext); return DOUBLE;}}
"else"               {col+=yyleng; if(input_flag) { printf("ELSE\n"); } else { yylval.token =(char *) strdup(yytext); return ELSE;}}
"if"                 {col+=yyleng; if(input_flag) { printf("IF\n"); } else { yylval.token =(char *) strdup(yytext); return IF;}}
"int"                {col+=yyleng; if(input_flag) { printf("INT\n"); } else { yylval.token =(char *) strdup(yytext); return INT;}}
"Integer.parseInt"   {col+=yyleng; if(input_flag) { printf("PARSEINT\n"); } else { yylval.token =(char *) strdup(yytext); return PARSEINT;}}
"System.out.println" {col+=yyleng; if(input_flag) { printf("PRINT\n"); } else { yylval.token =(char *) strdup(yytext); return PRINT;}}
"public"             {col+=yyleng; if(input_flag) { printf("PUBLIC\n"); } else { yylval.token =(char *) strdup(yytext); return PUBLIC;}}
"return"             {col+=yyleng; if(input_flag) { printf("RETURN\n"); } else { yylval.token =(char *) strdup(yytext); return RETURN;}}
"static"             {col+=yyleng; if(input_flag) { printf("STATIC\n"); } else { yylval.token =(char *) strdup(yytext); return STATIC;}}
"String"             {col+=yyleng; if(input_flag) { printf("STRING\n"); } else { yylval.token =(char *) strdup(yytext); return STRING;}}
"void"               {col+=yyleng; if(input_flag) { printf("VOID\n"); } else { yylval.token =(char *) strdup(yytext); return VOID;}}
"while"              {col+=yyleng; if(input_flag) { printf("WHILE\n"); } else { yylval.token =(char *) strdup(yytext); return WHILE;}}
"("                  {col+=yyleng; if(input_flag) { printf("OCURV\n"); } else { yylval.token =(char *) strdup(yytext); return OCURV;}}
")"                  {col+=yyleng; if(input_flag) { printf("CCURV\n"); } else { yylval.token =(char *) strdup(yytext); return CCURV;}}
"{"                  {col+=yyleng; if(input_flag) { printf("OBRACE\n"); } else { yylval.token =(char *) strdup(yytext); return OBRACE;}}
"}"                  {col+=yyleng; if(input_flag) { printf("CBRACE\n"); } else { yylval.token =(char *) strdup(yytext); return CBRACE;}}
"["                  {col+=yyleng; if(input_flag) { printf("OSQUARE\n"); } else { yylval.token =(char *) strdup(yytext); return OSQUARE;}}
"]"                  {col+=yyleng; if(input_flag) { printf("CSQUARE\n"); } else { yylval.token =(char *) strdup(yytext); return CSQUARE;}}
"&&"                 {col+=yyleng; if(input_flag) { printf("AND\n"); } else { yylval.token =(char *) strdup(yytext); return AND;}}
"||"                 {col+=yyleng; if(input_flag) { printf("OR\n"); } else { yylval.token =(char *) strdup(yytext); return OR;}}
"<"                  {col+=yyleng; if(input_flag) { printf("LT\n"); } else { yylval.token =(char *) strdup(yytext); return LT;}}
">"                  {col+=yyleng; if(input_flag) { printf("GT\n"); } else { yylval.token =(char *) strdup(yytext); return GT;}}
"=="                 {col+=yyleng; if(input_flag) { printf("EQ\n"); } else { yylval.token =(char *) strdup(yytext); return EQ;}}
"!="                 {col+=yyleng; if(input_flag) { printf("NEQ\n"); } else { yylval.token =(char *) strdup(yytext); return NEQ;}}
"<="                 {col+=yyleng; if(input_flag) { printf("LEQ\n"); } else { yylval.token =(char *) strdup(yytext); return LEQ;}}
">="                 {col+=yyleng; if(input_flag) { printf("GEQ\n"); } else { yylval.token =(char *) strdup(yytext); return GEQ;}}
"+"                  {col+=yyleng; if(input_flag) { printf("PLUS\n"); } else { yylval.token =(char *) strdup(yytext); return PLUS;}}
"-"                  {col+=yyleng; if(input_flag) { printf("MINUS\n"); } else { yylval.token =(char *) strdup(yytext); return MINUS;}}
"*"                  {col+=yyleng; if(input_flag) { printf("STAR\n"); } else { yylval.token =(char *) strdup(yytext); return STAR;}}
"/"                  {col+=yyleng; if(input_flag) { printf("DIV\n"); } else { yylval.token =(char *) strdup(yytext); return DIV;}}
"%"                  {col+=yyleng; if(input_flag) { printf("MOD\n"); } else { yylval.token =(char *) strdup(yytext); return MOD;}}
"!"                  {col+=yyleng; if(input_flag) { printf("NOT\n"); } else { yylval.token =(char *) strdup(yytext); return NOT;}}
"="                  {col+=yyleng; if(input_flag) { printf("ASSIGN\n"); } else { yylval.token =(char *) strdup(yytext); return ASSIGN;}}
";"                  {col+=yyleng; if(input_flag) { printf("SEMI\n"); } else { yylval.token =(char *) strdup(yytext); return SEMI;}}
","                  {col+=yyleng; if(input_flag) { printf("COMMA\n"); } else { yylval.token =(char *) strdup(yytext); return COMMA;}}
" "                  {col+=1;}
\t                   {col+=1;}
\r                   {col=1; line +=1;}
\n                   {col=1; line+=1;}
\f                   {col+=1;}
\r\n                 {col=1; line+=1;}
{reserved}           {col+=yyleng; if(input_flag) { printf("RESERVED(%s)\n", yytext); } else { yylval.token =(char *) strdup(yytext); return RESERVED;}}
{declit}             {col+=yyleng; if(input_flag) { printf("DECLIT(%s)\n", yytext); col +=yyleng; } else { yylval.token =(char *) strdup(yytext); return DECLIT;}}
{reallit}            {col+=yyleng; if(input_flag) { printf("REALLIT(%s)\n", yytext); } else { yylval.token =(char *) strdup(yytext); return REALLIT;}}
{strlit}             {col+=yyleng; if(input_flag) { printf("STRLIT(%s)\n", yytext); } else { yylval.token =(char *) strdup(yytext); return STRLIT;}}
{id}                 {col+=yyleng; if(input_flag) { printf("ID(%s)\n", yytext); } else { yylval.token =(char *) strdup(yytext); return ID;}}
<<eof>>              {col+=1; return 0;}
.                    {printf("Line %d, col %d: illegal character (%c)\n", line, col, yytext[0]);col+=yyleng;}
%%

int main(int argc, char **argv) {
  if(argc > 1){
    if (!strcmp(argv[1], "-l")) {
      input_flag = 1;
      yylex();
    } else if(!strcmp(argv[1], "-1")){
      input_flag = 0;
      yylex();
    } else if(!strcmp(argv[1], "-t")){
      yyparse();
      if(!error_flag){
        print_tree(ast, 0);
        //destroy_tree(ast);
      }
    }
  } else {
    yyparse();
  }
  yylex_destroy();
  return 0;
}

int yywrap() {
  return 1;
}
