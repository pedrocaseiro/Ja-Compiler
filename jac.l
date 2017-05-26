%{
  #include <stdio.h>
  #include <ctype.h>
  #include <stdarg.h>
  #include "y.tab.h"
  #include "ast.h"
  #include "symbol_table.h"
  #include "code_gen.h"
  #define MAX_SIZE 1024

  int yyparse();
  int col = 1;
  int line = 1;
  static int comment_start_col = 0;
  static int comment_start_line = 0;
  static int string_start_col = 0;
  static int string_start_line = 0;
  static int input_flag = 0;
  static int return_flag = 0;

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
<MULTILINECOMMENT><<eof>>    {printf("Line %d, col %d: unterminated comment\n", comment_start_line, comment_start_col); col+=1; return 0;}
<MULTILINECOMMENT>"*/"       {col+=yyleng; BEGIN 0;}
<MULTILINECOMMENT>\n         {col=1; line+=1;}
<MULTILINECOMMENT>\r         {col=1; line+=1;}
<MULTILINECOMMENT>\r\n       {col=1; line+=1;}
<MULTILINECOMMENT>"\f"|"\t"  {col+=1;}
<MULTILINECOMMENT>.          {col+=yyleng;}

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

"boolean"            {col+=yyleng; if(input_flag) { printf("BOOL\n"); } if(return_flag) { yylval.token = allocate_structure(line, col - yyleng, yytext); return BOOL;}}
"true"|"false"       {col+=yyleng; if(input_flag) { printf("BOOLLIT(%s)\n", yytext); } if(return_flag) { yylval.token = allocate_structure(line, col - yyleng, yytext); return BOOLLIT;}}
"class"              {col+=yyleng; if(input_flag) { printf("CLASS\n"); } if(return_flag) { yylval.token = allocate_structure(line, col - yyleng, yytext); return CLASS;}}
"do"                 {col+=yyleng; if(input_flag) { printf("DO\n"); } if(return_flag) { yylval.token = allocate_structure(line, col - yyleng, yytext); return DO;}}
".length"            {col+=yyleng; if(input_flag) { printf("DOTLENGTH\n"); } if(return_flag) { yylval.token = allocate_structure(line, col - yyleng, yytext); return DOTLENGTH;}}
"double"             {col+=yyleng; if(input_flag) { printf("DOUBLE\n"); } if(return_flag) { yylval.token = allocate_structure(line, col - yyleng, yytext); return DOUBLE;}}
"else"               {col+=yyleng; if(input_flag) { printf("ELSE\n"); } if(return_flag) { yylval.token = allocate_structure(line, col - yyleng, yytext); return ELSE;}}
"if"                 {col+=yyleng; if(input_flag) { printf("IF\n"); } if(return_flag) { yylval.token = allocate_structure(line, col - yyleng, yytext); return IF;}}
"int"                {col+=yyleng; if(input_flag) { printf("INT\n"); } if(return_flag) { yylval.token = allocate_structure(line, col - yyleng, yytext); return INT;}}
"Integer.parseInt"   {col+=yyleng; if(input_flag) { printf("PARSEINT\n"); } if(return_flag) { yylval.token = allocate_structure(line, col - yyleng, yytext); return PARSEINT;}}
"System.out.println" {col+=yyleng; if(input_flag) { printf("PRINT\n"); } if(return_flag) { yylval.token = allocate_structure(line, col - yyleng, yytext); return PRINT;}}
"public"             {col+=yyleng; if(input_flag) { printf("PUBLIC\n"); } if(return_flag) { yylval.token = allocate_structure(line, col - yyleng, yytext); return PUBLIC;}}
"return"             {col+=yyleng; if(input_flag) { printf("RETURN\n"); } if(return_flag) { yylval.token = allocate_structure(line, col - yyleng, yytext); return RETURN;}}
"static"             {col+=yyleng; if(input_flag) { printf("STATIC\n"); } if(return_flag) { yylval.token = allocate_structure(line, col - yyleng, yytext); return STATIC;}}
"String"             {col+=yyleng; if(input_flag) { printf("STRING\n"); } if(return_flag) { yylval.token = allocate_structure(line, col - yyleng, yytext); return STRING;}}
"void"               {col+=yyleng; if(input_flag) { printf("VOID\n"); } if(return_flag) { yylval.token = allocate_structure(line, col - yyleng, yytext); return VOID;}}
"while"              {col+=yyleng; if(input_flag) { printf("WHILE\n"); } if(return_flag) { yylval.token = allocate_structure(line, col - yyleng, yytext); return WHILE;}}
"("                  {col+=yyleng; if(input_flag) { printf("OCURV\n"); } if(return_flag) { yylval.token = allocate_structure(line, col - yyleng, yytext); return OCURV;}}
")"                  {col+=yyleng; if(input_flag) { printf("CCURV\n"); } if(return_flag) { yylval.token = allocate_structure(line, col - yyleng, yytext); return CCURV;}}
"{"                  {col+=yyleng; if(input_flag) { printf("OBRACE\n"); } if(return_flag) { yylval.token = allocate_structure(line, col - yyleng, yytext); return OBRACE;}}
"}"                  {col+=yyleng; if(input_flag) { printf("CBRACE\n"); } if(return_flag) { yylval.token = allocate_structure(line, col - yyleng, yytext); return CBRACE;}}
"["                  {col+=yyleng; if(input_flag) { printf("OSQUARE\n"); } if(return_flag) { yylval.token = allocate_structure(line, col - yyleng, yytext); return OSQUARE;}}
"]"                  {col+=yyleng; if(input_flag) { printf("CSQUARE\n"); } if(return_flag) { yylval.token = allocate_structure(line, col - yyleng, yytext); return CSQUARE;}}
"&&"                 {col+=yyleng; if(input_flag) { printf("AND\n"); } if(return_flag) { yylval.token = allocate_structure(line, col - yyleng, yytext); return AND;}}
"||"                 {col+=yyleng; if(input_flag) { printf("OR\n"); } if(return_flag) { yylval.token = allocate_structure(line, col - yyleng, yytext); return OR;}}
"<"                  {col+=yyleng; if(input_flag) { printf("LT\n"); } if(return_flag) { yylval.token = allocate_structure(line, col - yyleng, yytext); return LT;}}
">"                  {col+=yyleng; if(input_flag) { printf("GT\n"); } if(return_flag) { yylval.token = allocate_structure(line, col - yyleng, yytext); return GT;}}
"=="                 {col+=yyleng; if(input_flag) { printf("EQ\n"); } if(return_flag) { yylval.token = allocate_structure(line, col - yyleng, yytext); return EQ;}}
"!="                 {col+=yyleng; if(input_flag) { printf("NEQ\n"); } if(return_flag) { yylval.token = allocate_structure(line, col - yyleng, yytext); return NEQ;}}
"<="                 {col+=yyleng; if(input_flag) { printf("LEQ\n"); } if(return_flag) { yylval.token = allocate_structure(line, col - yyleng, yytext); return LEQ;}}
">="                 {col+=yyleng; if(input_flag) { printf("GEQ\n"); } if(return_flag) { yylval.token = allocate_structure(line, col - yyleng, yytext); return GEQ;}}
"+"                  {col+=yyleng; if(input_flag) { printf("PLUS\n"); } if(return_flag) { yylval.token = allocate_structure(line, col - yyleng, yytext); return PLUS;}}
"-"                  {col+=yyleng; if(input_flag) { printf("MINUS\n"); } if(return_flag) { yylval.token = allocate_structure(line, col - yyleng, yytext); return MINUS;}}
"*"                  {col+=yyleng; if(input_flag) { printf("STAR\n"); } if(return_flag) { yylval.token = allocate_structure(line, col - yyleng, yytext); return STAR;}}
"/"                  {col+=yyleng; if(input_flag) { printf("DIV\n"); } if(return_flag) { yylval.token = allocate_structure(line, col - yyleng, yytext); return DIV;}}
"%"                  {col+=yyleng; if(input_flag) { printf("MOD\n"); } if(return_flag) { yylval.token = allocate_structure(line, col - yyleng, yytext); return MOD;}}
"!"                  {col+=yyleng; if(input_flag) { printf("NOT\n"); } if(return_flag) { yylval.token = allocate_structure(line, col - yyleng, yytext); return NOT;}}
"="                  {col+=yyleng; if(input_flag) { printf("ASSIGN\n"); } if(return_flag) { yylval.token = allocate_structure(line, col - yyleng, yytext); return ASSIGN;}}
";"                  {col+=yyleng; if(input_flag) { printf("SEMI\n"); } if(return_flag) { yylval.token = allocate_structure(line, col - yyleng, yytext); return SEMI;}}
","                  {col+=yyleng; if(input_flag) { printf("COMMA\n"); } if(return_flag) { yylval.token = allocate_structure(line, col - yyleng, yytext); return COMMA;}}
" "                  {col+=1;}
\t                   {col+=1;}
\r                   {col=1; line +=1;}
\n                   {col=1; line+=1;}
\f                   {col+=1;}
\r\n                 {col=1; line+=1;}
{reserved}           {col+=yyleng; if(input_flag) { printf("RESERVED(%s)\n", yytext); } if(return_flag) { yylval.token = allocate_structure(line, col - yyleng, yytext); return RESERVED;}}
{declit}             {col+=yyleng; if(input_flag) { printf("DECLIT(%s)\n", yytext); } if(return_flag) { yylval.token = allocate_structure(line, col - yyleng, yytext); return DECLIT;}}
{reallit}            {col+=yyleng; if(input_flag) { printf("REALLIT(%s)\n", yytext); } if(return_flag) { yylval.token = allocate_structure(line, col - yyleng, yytext); return REALLIT;}}
{strlit}             {col+=yyleng; if(input_flag) { printf("STRLIT(%s)\n", yytext); } if(return_flag) { yylval.token = allocate_structure(line, col - yyleng, yytext); return STRLIT;}}
{id}                 {col+=yyleng; if(input_flag) { printf("ID(%s)\n", yytext); } if(return_flag) { yylval.token = allocate_structure(line, col - yyleng, yytext); return ID;}}
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
      return_flag = 0;
      yylex();
    }else if(!strcmp(argv[1], "-2")){
      return_flag = 1;
      yyparse();
    } else if(!strcmp(argv[1], "-t")){
      return_flag = 1;
      yyparse();
      if(!error_flag){
        print_tree(ast, 0);
        //destroy_tree(ast);
      }
    } else if(!strcmp(argv[1], "-s")){
      return_flag = 1;
      yyparse();
      if(!error_flag){
        table_index = 0;
        table = new_table(MAX_SIZE);
        first_traverse(ast);
        create_an_tree(ast);
        print_table();
        printf("\n");
        print_tree(ast,0);
        //destroy_tree(ast);
      }
    } else if(!strcmp(argv[1], "-3")){
       return_flag = 1;
       yyparse();
       if(!error_flag){
        table_index = 0;
        table = new_table(MAX_SIZE);
        first_traverse(ast);
        create_an_tree(ast);
        //destroy_tree(ast);
      }
    }
  } else {
    return_flag = 1;
    yyparse();
    if(!error_flag){
      table_index = 0;
      table = new_table(MAX_SIZE);
      first_traverse(ast);
      create_an_tree(ast);
      code_generation(ast);
    }
  }
  //yylex_destroy();
  return 0;
}

int yywrap() {
  return 1;
}
