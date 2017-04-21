/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     BOOL = 258,
     BOOLLIT = 259,
     CLASS = 260,
     DO = 261,
     DOTLENGTH = 262,
     DOUBLE = 263,
     ELSE = 264,
     IF = 265,
     INT = 266,
     PARSEINT = 267,
     PRINT = 268,
     PUBLIC = 269,
     RETURN = 270,
     STATIC = 271,
     WHILE = 272,
     OCURV = 273,
     CCURV = 274,
     OBRACE = 275,
     CBRACE = 276,
     STRING = 277,
     VOID = 278,
     OSQUARE = 279,
     CSQUARE = 280,
     AND = 281,
     OR = 282,
     LT = 283,
     GT = 284,
     EQ = 285,
     NEQ = 286,
     LEQ = 287,
     GEQ = 288,
     PLUS = 289,
     MINUS = 290,
     STAR = 291,
     DIV = 292,
     MOD = 293,
     NOT = 294,
     ASSIGN = 295,
     SEMI = 296,
     COMMA = 297,
     RESERVED = 298,
     DECLIT = 299,
     REALLIT = 300,
     STRLIT = 301,
     ID = 302,
     IF_NO_ELSE = 303,
     UNARY = 304
   };
#endif
/* Tokens.  */
#define BOOL 258
#define BOOLLIT 259
#define CLASS 260
#define DO 261
#define DOTLENGTH 262
#define DOUBLE 263
#define ELSE 264
#define IF 265
#define INT 266
#define PARSEINT 267
#define PRINT 268
#define PUBLIC 269
#define RETURN 270
#define STATIC 271
#define WHILE 272
#define OCURV 273
#define CCURV 274
#define OBRACE 275
#define CBRACE 276
#define STRING 277
#define VOID 278
#define OSQUARE 279
#define CSQUARE 280
#define AND 281
#define OR 282
#define LT 283
#define GT 284
#define EQ 285
#define NEQ 286
#define LEQ 287
#define GEQ 288
#define PLUS 289
#define MINUS 290
#define STAR 291
#define DIV 292
#define MOD 293
#define NOT 294
#define ASSIGN 295
#define SEMI 296
#define COMMA 297
#define RESERVED 298
#define DECLIT 299
#define REALLIT 300
#define STRLIT 301
#define ID 302
#define IF_NO_ELSE 303
#define UNARY 304




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 15 "jac.y"
{
  char* token;
  struct node *node;
}
/* Line 1529 of yacc.c.  */
#line 152 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

