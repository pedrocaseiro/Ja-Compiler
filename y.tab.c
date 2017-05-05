/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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




/* Copy the first part of user declarations.  */
#line 1 "jac.y"

  #include <stdio.h>
  #include <string.h>
  #include "ast.h"
  #include "symbol_table.h"
  void yyerror();
  int yylex();

  node* ast;

  extern char* yytext;
  extern int line, col, yyleng;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 15 "jac.y"
{
  struct token_struct* token;
  struct node *node;
}
/* Line 193 of yacc.c.  */
#line 213 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 226 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   346

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  88
/* YYNRULES -- Number of states.  */
#define YYNSTATES  176

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   304

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     9,    12,    13,    15,    17,    19,    25,
      28,    32,    34,    36,    41,    47,    53,    55,    57,    58,
      60,    64,    66,    71,    74,    76,    80,    83,    86,    87,
      91,    95,    97,    99,   103,   111,   117,   123,   131,   137,
     143,   146,   149,   152,   154,   158,   161,   164,   167,   168,
     172,   178,   182,   187,   191,   192,   194,   202,   207,   209,
     211,   215,   219,   223,   227,   231,   235,   239,   243,   247,
     251,   255,   259,   263,   266,   269,   272,   274,   277,   281,
     283,   285,   287,   291,   293,   295,   297,   299,   301
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      51,     0,    -1,     5,    80,    20,    52,    21,    -1,    52,
      53,    -1,    -1,    54,    -1,    57,    -1,    41,    -1,    14,
      16,    79,    55,    41,    -1,     1,    41,    -1,    55,    42,
      56,    -1,    56,    -1,    80,    -1,    14,    16,    58,    65,
      -1,    79,    80,    18,    59,    19,    -1,    60,    80,    18,
      59,    19,    -1,    61,    -1,    62,    -1,    -1,    23,    -1,
      61,    42,    63,    -1,    63,    -1,    64,    24,    25,    80,
      -1,    79,    80,    -1,    22,    -1,    20,    66,    21,    -1,
      66,    67,    -1,    66,    70,    -1,    -1,    79,    68,    41,
      -1,    68,    42,    69,    -1,    69,    -1,    80,    -1,    20,
      71,    21,    -1,    10,    18,    78,    19,    70,     9,    70,
      -1,    10,    18,    78,    19,    70,    -1,    17,    18,    78,
      19,    70,    -1,     6,    70,    17,    18,    78,    19,    41,
      -1,    13,    18,    78,    19,    41,    -1,    13,    18,    75,
      19,    41,    -1,    72,    41,    -1,    73,    41,    -1,    76,
      41,    -1,    41,    -1,    15,    78,    41,    -1,    15,    41,
      -1,     1,    41,    -1,    71,    70,    -1,    -1,    80,    40,
      78,    -1,    80,    18,    78,    74,    19,    -1,    80,    18,
      19,    -1,    80,    18,     1,    19,    -1,    74,    42,    78,
      -1,    -1,    46,    -1,    12,    18,    80,    24,    78,    25,
      19,    -1,    12,    18,     1,    19,    -1,    73,    -1,    76,
      -1,    77,    26,    77,    -1,    77,    27,    77,    -1,    77,
      30,    77,    -1,    77,    33,    77,    -1,    77,    29,    77,
      -1,    77,    32,    77,    -1,    77,    28,    77,    -1,    77,
      31,    77,    -1,    77,    34,    77,    -1,    77,    35,    77,
      -1,    77,    36,    77,    -1,    77,    37,    77,    -1,    77,
      38,    77,    -1,    34,    77,    -1,    35,    77,    -1,    39,
      77,    -1,    80,    -1,    80,     7,    -1,    18,    78,    19,
      -1,     4,    -1,    44,    -1,    45,    -1,    18,     1,    19,
      -1,    72,    -1,    77,    -1,     3,    -1,    11,    -1,     8,
      -1,    47,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    43,    43,    45,    46,    48,    49,    50,    52,    53,
      55,    56,    58,    60,    62,    63,    65,    66,    67,    69,
      71,    72,    74,    76,    78,    80,    82,    83,    84,    88,
      90,    91,    93,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   110,   111,   113,
     115,   116,   117,   119,   120,   122,   124,   125,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   154,   155,   157,   158,   159,   161
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BOOL", "BOOLLIT", "CLASS", "DO",
  "DOTLENGTH", "DOUBLE", "ELSE", "IF", "INT", "PARSEINT", "PRINT",
  "PUBLIC", "RETURN", "STATIC", "WHILE", "OCURV", "CCURV", "OBRACE",
  "CBRACE", "STRING", "VOID", "OSQUARE", "CSQUARE", "AND", "OR", "LT",
  "GT", "EQ", "NEQ", "LEQ", "GEQ", "PLUS", "MINUS", "STAR", "DIV", "MOD",
  "NOT", "ASSIGN", "SEMI", "COMMA", "RESERVED", "DECLIT", "REALLIT",
  "STRLIT", "ID", "IF_NO_ELSE", "UNARY", "$accept", "Program",
  "DeclarationAux", "DeclarationL", "FieldDecl", "FieldDeclL", "FieldsIds",
  "MethodDecl", "MethodHeader", "MethodParamsL", "VOIDAux", "MethodParams",
  "FormalParamsStringArray", "FormalParams", "StringArray", "MethodBody",
  "VarDeclStatement", "VarDecl", "VarDeclL", "VarsIds", "Statement",
  "StatementL", "Assignment", "MethodInvocation", "CommaExpr", "StrLitAux",
  "ParseArgs", "ExprAux", "Expr", "Type", "IDAux", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    51,    52,    52,    53,    53,    53,    54,    54,
      55,    55,    56,    57,    58,    58,    59,    59,    59,    60,
      61,    61,    62,    63,    64,    65,    66,    66,    66,    67,
      68,    68,    69,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    71,    71,    72,
      73,    73,    73,    74,    74,    75,    76,    76,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    78,    78,    79,    79,    79,    80
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     2,     0,     1,     1,     1,     5,     2,
       3,     1,     1,     4,     5,     5,     1,     1,     0,     1,
       3,     1,     4,     2,     1,     3,     2,     2,     0,     3,
       3,     1,     1,     3,     7,     5,     5,     7,     5,     5,
       2,     2,     2,     1,     3,     2,     2,     2,     0,     3,
       5,     3,     4,     3,     0,     1,     7,     4,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     2,     1,     2,     3,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    88,     0,     1,     4,     0,     0,     0,
       2,     7,     3,     5,     6,     9,     0,    85,    87,    86,
      19,     0,     0,     0,    28,    13,     0,     0,    11,    12,
       0,    18,     8,     0,    18,     0,     0,     0,     0,     0,
       0,     0,    48,    25,    43,    26,    27,     0,     0,     0,
       0,     0,    24,     0,    16,    17,    21,     0,     0,    10,
      12,     0,    46,     0,     0,     0,     0,    79,     0,     0,
       0,     0,    45,    80,    81,    83,    58,    59,    84,     0,
      76,     0,     0,    40,    41,    42,     0,    31,    32,     0,
       0,    15,     0,     0,    23,    14,     0,     0,     0,     0,
      55,     0,     0,     0,     0,    73,    76,    74,    75,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    44,    77,     0,    33,    47,    29,     0,     0,
      51,    54,    49,    20,     0,     0,     0,    57,     0,     0,
       0,    82,    78,    60,    61,    66,    64,    62,    67,    65,
      63,    68,    69,    70,    71,    72,     0,    30,    52,     0,
      22,     0,    35,     0,    39,    38,    36,    50,     0,     0,
       0,     0,    53,    37,    34,    56
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     7,    12,    13,    27,    28,    14,    21,    53,
      22,    54,    55,    56,    57,    25,    30,    45,    86,    87,
      46,    82,    75,    76,   159,   101,    77,    78,    79,    58,
     106
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -54
static const yytype_int16 yypact[] =
{
      22,    -3,    50,   -54,    42,   -54,   -54,     5,    27,    54,
     -54,   -54,   -54,   -54,   -54,   -54,    37,   -54,   -54,   -54,
     -54,    52,    -3,    -3,   -54,   -54,    59,   -18,   -54,    60,
     160,    30,   -54,    -3,    30,    38,   211,    65,    66,    68,
     226,    69,   -54,   -54,   -54,   -54,   -54,    49,    53,    56,
      -3,    -6,   -54,    74,    58,   -54,   -54,    71,    -3,   -54,
     -54,    79,   -54,    82,   262,     0,   244,   -54,   202,   262,
     262,   262,   -54,   -54,   -54,   -54,   -54,   -54,   284,    62,
      13,   262,   198,   -54,   -54,   -54,     1,   -54,   -54,    57,
     262,   -54,    63,    81,   -54,   -54,    89,    92,    95,    99,
     -54,   105,   107,   112,   113,   -54,     7,   -54,   -54,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   -54,   -54,   117,   -54,   -54,   -54,    -3,   119,
     -54,   -54,   -54,   -54,    -3,   262,   211,   -54,   262,   100,
     115,   -54,   -54,   308,   297,   114,   114,    84,    84,   114,
     114,   -20,   -20,   -54,   -54,   -54,   211,   -54,   -54,   -12,
     -54,   121,   144,   129,   -54,   -54,   -54,   -54,   262,   116,
     211,   139,   -54,   -54,   -54,   -54
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -54,   -54,   -54,   -54,   -54,   -54,   126,   -54,   -54,   128,
     -54,   -54,   -54,    72,   -54,   -54,   -54,   -54,   -54,    32,
     -31,   -54,   -28,   -27,   -54,   -54,   -26,    76,   -53,    43,
      -1
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
       4,    98,    47,    48,    49,    63,     8,   167,    47,    48,
      49,    97,    89,   102,   123,   104,   119,   120,   121,     9,
     123,    26,    29,    32,    33,    89,    10,     1,   124,    51,
     168,    89,    60,    17,    90,    51,   131,   132,    18,    80,
      17,    19,   127,   128,     3,    18,    11,     3,    19,    88,
       5,   126,    52,    90,    47,    48,    49,    94,   129,    23,
      20,    67,     6,    80,    99,    80,    17,    80,    15,    38,
      16,    18,    24,    50,    19,    68,   130,    31,    34,    62,
      80,    51,   161,    64,    65,   163,    66,    81,    80,    80,
      83,    69,    70,    91,    84,    93,    71,    85,    95,    96,
      92,    73,    74,   122,     3,   162,   134,   135,    47,    48,
      49,   136,   111,   112,   137,   172,   115,   116,   117,   118,
     119,   120,   121,   138,   139,   166,   140,    88,    47,    48,
      49,   141,   142,   160,    80,    51,   156,    80,   158,   174,
     169,   164,    47,    48,    49,   105,   107,   108,   117,   118,
     119,   120,   121,   170,   171,    51,   165,   173,   175,    59,
     157,    35,    61,    17,   133,     0,    36,    80,    18,    51,
      37,    19,    38,    39,     0,    40,     0,    41,     0,     0,
      42,    43,     0,     0,     0,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,     0,    35,
       0,    44,     0,   103,    36,     0,    67,     3,    37,     0,
      38,    39,    35,    40,    38,    41,     0,    36,    42,   125,
      68,    37,     0,    38,    39,     0,    40,     0,    41,     0,
      67,    42,     0,     0,     0,     0,    69,    70,    38,    44,
       0,    71,     0,     0,    68,     3,    73,    74,    67,     3,
       0,     0,    44,     0,     0,     0,    38,     0,     3,     0,
      69,    70,    68,     0,     0,    71,    67,    72,     0,     0,
      73,    74,     0,     3,    38,     0,     0,     0,    69,    70,
      68,     0,     0,    71,     0,     0,     0,     0,    73,    74,
     100,     3,     0,     0,     0,     0,    69,    70,     0,     0,
       0,    71,     0,     0,     0,     0,    73,    74,     0,     3,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   109,     0,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121
};

static const yytype_int16 yycheck[] =
{
       1,     1,    30,    30,    30,    36,     1,    19,    36,    36,
      36,    64,    18,    66,     7,    68,    36,    37,    38,    14,
       7,    22,    23,    41,    42,    18,    21,     5,    81,    30,
      42,    18,    33,     3,    40,    36,    89,    90,     8,    40,
       3,    11,    41,    42,    47,     8,    41,    47,    11,    50,
       0,    82,    22,    40,    82,    82,    82,    58,     1,    16,
      23,     4,    20,    64,    65,    66,     3,    68,    41,    12,
      16,     8,    20,    30,    11,    18,    19,    18,    18,    41,
      81,    82,   135,    18,    18,   138,    18,    18,    89,    90,
      41,    34,    35,    19,    41,    24,    39,    41,    19,    17,
      42,    44,    45,    41,    47,   136,    25,    18,   136,   136,
     136,    19,    28,    29,    19,   168,    32,    33,    34,    35,
      36,    37,    38,    24,    19,   156,    19,   128,   156,   156,
     156,    19,    19,   134,   135,   136,    19,   138,    19,   170,
      19,    41,   170,   170,   170,    69,    70,    71,    34,    35,
      36,    37,    38,     9,    25,   156,    41,    41,    19,    33,
     128,     1,    34,     3,    92,    -1,     6,   168,     8,   170,
      10,    11,    12,    13,    -1,    15,    -1,    17,    -1,    -1,
      20,    21,    -1,    -1,    -1,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,    -1,     1,
      -1,    41,    -1,     1,     6,    -1,     4,    47,    10,    -1,
      12,    13,     1,    15,    12,    17,    -1,     6,    20,    21,
      18,    10,    -1,    12,    13,    -1,    15,    -1,    17,    -1,
       4,    20,    -1,    -1,    -1,    -1,    34,    35,    12,    41,
      -1,    39,    -1,    -1,    18,    47,    44,    45,     4,    47,
      -1,    -1,    41,    -1,    -1,    -1,    12,    -1,    47,    -1,
      34,    35,    18,    -1,    -1,    39,     4,    41,    -1,    -1,
      44,    45,    -1,    47,    12,    -1,    -1,    -1,    34,    35,
      18,    -1,    -1,    39,    -1,    -1,    -1,    -1,    44,    45,
      46,    47,    -1,    -1,    -1,    -1,    34,    35,    -1,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    44,    45,    -1,    47,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    26,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,    51,    47,    80,     0,    20,    52,     1,    14,
      21,    41,    53,    54,    57,    41,    16,     3,     8,    11,
      23,    58,    60,    79,    20,    65,    80,    55,    56,    80,
      66,    18,    41,    42,    18,     1,     6,    10,    12,    13,
      15,    17,    20,    21,    41,    67,    70,    72,    73,    76,
      79,    80,    22,    59,    61,    62,    63,    64,    79,    56,
      80,    59,    41,    70,    18,    18,    18,     4,    18,    34,
      35,    39,    41,    44,    45,    72,    73,    76,    77,    78,
      80,    18,    71,    41,    41,    41,    68,    69,    80,    18,
      40,    19,    42,    24,    80,    19,    17,    78,     1,    80,
      46,    75,    78,     1,    78,    77,    80,    77,    77,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    41,     7,    78,    21,    70,    41,    42,     1,
      19,    78,    78,    63,    25,    18,    19,    19,    24,    19,
      19,    19,    19,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    19,    69,    19,    74,
      80,    78,    70,    78,    41,    41,    70,    19,    42,    19,
       9,    25,    78,    41,    70,    19
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 43 "jac.y"
    {(yyval.node) = ast = create_and_insert_node("Program", 1, 2, (yyvsp[(2) - (5)].node), (yyvsp[(4) - (5)].node));}
    break;

  case 3:
#line 45 "jac.y"
    {(yyval.node) = create_and_insert_node("Program", 0, 2, (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));}
    break;

  case 4:
#line 46 "jac.y"
    {(yyval.node) = create_terminal_node("Empty", 0, NULL);}
    break;

  case 5:
#line 48 "jac.y"
    {(yyval.node) = create_and_insert_node("FieldDeclAux", 0, 1, (yyvsp[(1) - (1)].node));}
    break;

  case 6:
#line 49 "jac.y"
    {(yyval.node) = create_and_insert_node("MethodDeclAux", 0, 1, (yyvsp[(1) - (1)].node));}
    break;

  case 7:
#line 50 "jac.y"
    {(yyval.node) = create_terminal_node("Semi", 0, NULL);}
    break;

  case 8:
#line 52 "jac.y"
    {if ((yyvsp[(4) - (5)].node) != NULL) { ast_decl((yyvsp[(3) - (5)].node), (yyvsp[(4) - (5)].node)); (yyval.node) = (yyvsp[(4) - (5)].node); } else { (yyval.node) = (yyvsp[(4) - (5)].node); }}
    break;

  case 9:
#line 53 "jac.y"
    {(yyval.node) = NULL; }
    break;

  case 10:
#line 55 "jac.y"
    {(yyval.node) = create_and_insert_node("FieldDecl", 0, 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 11:
#line 56 "jac.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 12:
#line 58 "jac.y"
    {(yyval.node) = create_and_insert_node("FieldDecl", 1, 1, (yyvsp[(1) - (1)].node));}
    break;

  case 13:
#line 60 "jac.y"
    {(yyval.node) = create_and_insert_node("MethodDecl", 1, 2, (yyvsp[(3) - (4)].node), (yyvsp[(4) - (4)].node));}
    break;

  case 14:
#line 62 "jac.y"
    {(yyval.node) = create_and_insert_node("MethodHeader", 1, 3, (yyvsp[(1) - (5)].node), (yyvsp[(2) - (5)].node), (yyvsp[(4) - (5)].node));}
    break;

  case 15:
#line 63 "jac.y"
    {(yyval.node) = create_and_insert_node("MethodHeader", 1, 3, (yyvsp[(1) - (5)].node), (yyvsp[(2) - (5)].node), (yyvsp[(4) - (5)].node));}
    break;

  case 16:
#line 65 "jac.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 17:
#line 66 "jac.y"
    {(yyval.node) = create_and_insert_node("MethodParams", 1, 1, (yyvsp[(1) - (1)].node));}
    break;

  case 18:
#line 67 "jac.y"
    {(yyval.node) = create_and_insert_node("MethodParams", 1, 0);}
    break;

  case 19:
#line 69 "jac.y"
    {(yyval.node)=create_terminal_node("Void", 1, (yyvsp[(1) - (1)].token));}
    break;

  case 20:
#line 71 "jac.y"
    {(yyvsp[(1) - (3)].node)->to_be_used = 0; (yyval.node) = create_and_insert_node("MethodParams", 1, 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 21:
#line 72 "jac.y"
    {(yyval.node) = create_and_insert_node("MethodParams", 1, 1, (yyvsp[(1) - (1)].node));}
    break;

  case 22:
#line 74 "jac.y"
    {(yyval.node) = create_and_insert_node("ParamDecl", 1, 2, (yyvsp[(1) - (4)].node), (yyvsp[(4) - (4)].node));}
    break;

  case 23:
#line 76 "jac.y"
    {(yyval.node) = create_and_insert_node("ParamDecl", 1, 2, (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));}
    break;

  case 24:
#line 78 "jac.y"
    {(yyval.node) = create_and_insert_node("StringArray", 1, 0);}
    break;

  case 25:
#line 80 "jac.y"
    {(yyval.node) = create_and_insert_node("MethodBody", 1, 1, (yyvsp[(2) - (3)].node));}
    break;

  case 26:
#line 82 "jac.y"
    {(yyval.node) = create_and_insert_node("MethodBody", 0, 2, (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));}
    break;

  case 27:
#line 83 "jac.y"
    {(yyval.node) = create_and_insert_node("MethodBody", 0, 2, (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));}
    break;

  case 28:
#line 84 "jac.y"
    {(yyval.node) = create_terminal_node("Empty", 0, NULL);}
    break;

  case 29:
#line 88 "jac.y"
    {if ((yyvsp[(2) - (3)].node) != NULL) { ast_decl((yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node)); (yyval.node) = (yyvsp[(2) - (3)].node); } else { (yyval.node) = (yyvsp[(2) - (3)].node); } }
    break;

  case 30:
#line 90 "jac.y"
    {(yyval.node) = create_and_insert_node("VarDecl", 0, 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 31:
#line 91 "jac.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 32:
#line 93 "jac.y"
    {(yyval.node) = create_and_insert_node("VarDecl", 1, 1, (yyvsp[(1) - (1)].node));}
    break;

  case 33:
#line 95 "jac.y"
    {if((yyvsp[(2) - (3)].node) != NULL && (yyvsp[(2) - (3)].node)->n_children <= 1) {(yyval.node) = create_and_insert_node("Block", 0, 1, (yyvsp[(2) - (3)].node)); } else { (yyval.node) = create_and_insert_node("Block", 1, 1, (yyvsp[(2) - (3)].node));}}
    break;

  case 34:
#line 96 "jac.y"
    {if(check_if_expr((yyvsp[(5) - (7)].node))){ (yyvsp[(5) - (7)].node) = create_terminal_node("Block", 1, NULL);} if(check_if_statement((yyvsp[(7) - (7)].node))){ (yyvsp[(7) - (7)].node) = create_terminal_node("Block", 1, NULL);} (yyval.node) = create_and_insert_node("If", 1, 3, (yyvsp[(3) - (7)].node), (yyvsp[(5) - (7)].node), (yyvsp[(7) - (7)].node));}
    break;

  case 35:
#line 97 "jac.y"
    {if(check_if_expr((yyvsp[(5) - (5)].node))){ (yyvsp[(5) - (5)].node) = create_terminal_node("Block", 1, NULL);} (yyval.node) = create_and_insert_node("If", 1, 3, (yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node), create_terminal_node("Block", 1, NULL));}
    break;

  case 36:
#line 98 "jac.y"
    {if(check_while_statement((yyvsp[(5) - (5)].node))){ (yyvsp[(5) - (5)].node) = create_terminal_node("Block", 1, NULL);} (yyval.node) = create_and_insert_node("While", 1, 2, (yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node));}
    break;

  case 37:
#line 99 "jac.y"
    {if(check_while_statement((yyvsp[(2) - (7)].node))){ (yyvsp[(2) - (7)].node) = create_terminal_node("Block", 1, NULL);} (yyval.node) = create_and_insert_node("DoWhile", 1, 2, (yyvsp[(2) - (7)].node), (yyvsp[(5) - (7)].node));}
    break;

  case 38:
#line 100 "jac.y"
    {(yyval.node) = create_and_insert_node("Print", 1, 1, (yyvsp[(3) - (5)].node));}
    break;

  case 39:
#line 101 "jac.y"
    {(yyval.node) = create_and_insert_node("Print", 1, 1, (yyvsp[(3) - (5)].node));}
    break;

  case 40:
#line 102 "jac.y"
    {(yyval.node) = create_and_insert_node("Assign", 0, 1, (yyvsp[(1) - (2)].node));}
    break;

  case 41:
#line 103 "jac.y"
    {(yyval.node) = create_and_insert_node("Call", 1, 1, (yyvsp[(1) - (2)].node));}
    break;

  case 42:
#line 104 "jac.y"
    {(yyval.node) = create_and_insert_node("ParseArgs", 1, 1, (yyvsp[(1) - (2)].node));}
    break;

  case 43:
#line 105 "jac.y"
    {(yyval.node) = create_terminal_node("Semi", 0, NULL);}
    break;

  case 44:
#line 106 "jac.y"
    {(yyval.node) = create_and_insert_node("Return", 1, 1, (yyvsp[(2) - (3)].node));(yyval.node)->token->line = (yyvsp[(1) - (3)].token)->line;(yyval.node)->token->col = (yyvsp[(1) - (3)].token)->col;}
    break;

  case 45:
#line 107 "jac.y"
    {(yyval.node) = create_and_insert_node("Return", 1, 0);(yyval.node)->token->line = (yyvsp[(1) - (2)].token)->line;(yyval.node)->token->col = (yyvsp[(1) - (2)].token)->col;}
    break;

  case 46:
#line 108 "jac.y"
    {(yyval.node) = create_terminal_node("Error", 0, NULL);}
    break;

  case 47:
#line 110 "jac.y"
    {(yyval.node) = create_and_insert_node("Statement", 0, 2, (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));}
    break;

  case 48:
#line 111 "jac.y"
    {(yyval.node) = create_terminal_node("Empty", 0, NULL);}
    break;

  case 49:
#line 113 "jac.y"
    {(yyval.node) = create_and_insert_node("Assign", 1, 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); (yyval.node)->token->line = (yyvsp[(2) - (3)].token)->line;(yyval.node)->token->col = (yyvsp[(2) - (3)].token)->col;}
    break;

  case 50:
#line 115 "jac.y"
    {(yyval.node) = create_and_insert_node("Call", 0, 3, (yyvsp[(1) - (5)].node), (yyvsp[(3) - (5)].node), (yyvsp[(4) - (5)].node));}
    break;

  case 51:
#line 116 "jac.y"
    {(yyval.node) = create_and_insert_node("Call", 0, 1, (yyvsp[(1) - (3)].node));}
    break;

  case 52:
#line 117 "jac.y"
    {(yyval.node) = create_terminal_node("Error", 0, NULL);}
    break;

  case 53:
#line 119 "jac.y"
    {(yyval.node) = create_and_insert_node("Call", 0, 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 54:
#line 120 "jac.y"
    {(yyval.node) = create_terminal_node("Empty", 0, NULL);}
    break;

  case 55:
#line 122 "jac.y"
    {(yyval.node) = create_terminal_node("StrLit", 1, (yyvsp[(1) - (1)].token));}
    break;

  case 56:
#line 124 "jac.y"
    {(yyval.node) = create_and_insert_node("ParseArgs", 0, 2, (yyvsp[(3) - (7)].node), (yyvsp[(5) - (7)].node));}
    break;

  case 57:
#line 125 "jac.y"
    {(yyval.node) = create_terminal_node("Error", 0, NULL);}
    break;

  case 58:
#line 127 "jac.y"
    {(yyval.node) = create_and_insert_node("Call", 1, 1, (yyvsp[(1) - (1)].node)); (yyval.node)->token->line = (yyval.node)->childs[0]->token->line; (yyval.node)->token->col=(yyval.node)->childs[0]->token->col;}
    break;

  case 59:
#line 128 "jac.y"
    {(yyval.node) = create_and_insert_node("ParseArgs", 1, 1, (yyvsp[(1) - (1)].node)); }
    break;

  case 60:
#line 129 "jac.y"
    {(yyval.node) = create_and_insert_node("And", 1, 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); (yyval.node)->token->line = (yyvsp[(2) - (3)].token)->line;(yyval.node)->token->col = (yyvsp[(2) - (3)].token)->col;}
    break;

  case 61:
#line 130 "jac.y"
    {(yyval.node) = create_and_insert_node("Or", 1, 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); (yyval.node)->token->line = (yyvsp[(2) - (3)].token)->line;(yyval.node)->token->col = (yyvsp[(2) - (3)].token)->col;}
    break;

  case 62:
#line 131 "jac.y"
    {(yyval.node) = create_and_insert_node("Eq", 1, 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); (yyval.node)->token->line = (yyvsp[(2) - (3)].token)->line;(yyval.node)->token->col = (yyvsp[(2) - (3)].token)->col;}
    break;

  case 63:
#line 132 "jac.y"
    {(yyval.node) = create_and_insert_node("Geq", 1, 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); (yyval.node)->token->line = (yyvsp[(2) - (3)].token)->line;(yyval.node)->token->col = (yyvsp[(2) - (3)].token)->col;}
    break;

  case 64:
#line 133 "jac.y"
    {(yyval.node) = create_and_insert_node("Gt", 1, 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); (yyval.node)->token->line = (yyvsp[(2) - (3)].token)->line;(yyval.node)->token->col = (yyvsp[(2) - (3)].token)->col;}
    break;

  case 65:
#line 134 "jac.y"
    {(yyval.node) = create_and_insert_node("Leq", 1, 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); (yyval.node)->token->line = (yyvsp[(2) - (3)].token)->line;(yyval.node)->token->col = (yyvsp[(2) - (3)].token)->col;}
    break;

  case 66:
#line 135 "jac.y"
    {(yyval.node) = create_and_insert_node("Lt", 1, 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); (yyval.node)->token->line = (yyvsp[(2) - (3)].token)->line;(yyval.node)->token->col = (yyvsp[(2) - (3)].token)->col;}
    break;

  case 67:
#line 136 "jac.y"
    {(yyval.node) = create_and_insert_node("Neq", 1, 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); (yyval.node)->token->line = (yyvsp[(2) - (3)].token)->line;(yyval.node)->token->col = (yyvsp[(2) - (3)].token)->col;}
    break;

  case 68:
#line 137 "jac.y"
    {(yyval.node) = create_and_insert_node("Add", 1, 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); (yyval.node)->token->line = (yyvsp[(2) - (3)].token)->line;(yyval.node)->token->col = (yyvsp[(2) - (3)].token)->col;}
    break;

  case 69:
#line 138 "jac.y"
    {(yyval.node) = create_and_insert_node("Sub", 1, 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); (yyval.node)->token->line = (yyvsp[(2) - (3)].token)->line;(yyval.node)->token->col = (yyvsp[(2) - (3)].token)->col;}
    break;

  case 70:
#line 139 "jac.y"
    {(yyval.node) = create_and_insert_node("Mul", 1, 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); (yyval.node)->token->line = (yyvsp[(2) - (3)].token)->line;(yyval.node)->token->col = (yyvsp[(2) - (3)].token)->col;}
    break;

  case 71:
#line 140 "jac.y"
    {(yyval.node) = create_and_insert_node("Div", 1, 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); (yyval.node)->token->line = (yyvsp[(2) - (3)].token)->line;(yyval.node)->token->col = (yyvsp[(2) - (3)].token)->col;}
    break;

  case 72:
#line 141 "jac.y"
    {(yyval.node) = create_and_insert_node("Mod", 1, 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); (yyval.node)->token->line = (yyvsp[(2) - (3)].token)->line;(yyval.node)->token->col = (yyvsp[(2) - (3)].token)->col;}
    break;

  case 73:
#line 142 "jac.y"
    {(yyval.node) = create_and_insert_node("Plus", 1, 1, (yyvsp[(2) - (2)].node));(yyval.node)->token->line = (yyvsp[(1) - (2)].token)->line;(yyval.node)->token->col = (yyvsp[(1) - (2)].token)->col;}
    break;

  case 74:
#line 143 "jac.y"
    {(yyval.node) = create_and_insert_node("Minus", 1, 1, (yyvsp[(2) - (2)].node));(yyval.node)->token->line = (yyvsp[(1) - (2)].token)->line;(yyval.node)->token->col = (yyvsp[(1) - (2)].token)->col;}
    break;

  case 75:
#line 144 "jac.y"
    {(yyval.node) = create_and_insert_node("Not", 1, 1, (yyvsp[(2) - (2)].node));(yyval.node)->token->line = (yyvsp[(1) - (2)].token)->line;(yyval.node)->token->col = (yyvsp[(1) - (2)].token)->col;}
    break;

  case 76:
#line 145 "jac.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 77:
#line 146 "jac.y"
    {(yyval.node) = create_and_insert_node("Length", 1, 1, (yyvsp[(1) - (2)].node));(yyval.node)->token->line = (yyvsp[(2) - (2)].token)->line;(yyval.node)->token->col = (yyvsp[(2) - (2)].token)->col;}
    break;

  case 78:
#line 147 "jac.y"
    {(yyval.node) = (yyvsp[(2) - (3)].node);}
    break;

  case 79:
#line 148 "jac.y"
    {(yyval.node)=create_terminal_node("BoolLit", 1, (yyvsp[(1) - (1)].token));(yyval.node)->token->line = (yyvsp[(1) - (1)].token)->line;(yyval.node)->token->col = (yyvsp[(1) - (1)].token)->col;}
    break;

  case 80:
#line 149 "jac.y"
    {(yyval.node)=create_terminal_node("DecLit", 1, (yyvsp[(1) - (1)].token));(yyval.node)->token->line = (yyvsp[(1) - (1)].token)->line;(yyval.node)->token->col = (yyvsp[(1) - (1)].token)->col;}
    break;

  case 81:
#line 150 "jac.y"
    {(yyval.node)=create_terminal_node("RealLit", 1, (yyvsp[(1) - (1)].token));(yyval.node)->token->line = (yyvsp[(1) - (1)].token)->line;(yyval.node)->token->col = (yyvsp[(1) - (1)].token)->col;}
    break;

  case 82:
#line 151 "jac.y"
    {(yyval.node) = create_terminal_node("Error", 0, NULL);}
    break;

  case 83:
#line 154 "jac.y"
    {(yyval.node) = create_and_insert_node("Assign", 0, 1, (yyvsp[(1) - (1)].node));}
    break;

  case 84:
#line 155 "jac.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 85:
#line 157 "jac.y"
    {(yyval.node)=create_terminal_node("Bool", 1, (yyvsp[(1) - (1)].token));}
    break;

  case 86:
#line 158 "jac.y"
    {(yyval.node)=create_terminal_node("Int", 1, (yyvsp[(1) - (1)].token));}
    break;

  case 87:
#line 159 "jac.y"
    {(yyval.node)=create_terminal_node("Double", 1, (yyvsp[(1) - (1)].token));}
    break;

  case 88:
#line 161 "jac.y"
    {(yyval.node)=create_terminal_node("Id", 1, (yyvsp[(1) - (1)].token));(yyval.node)->token->line = (yyvsp[(1) - (1)].token)->line;(yyval.node)->token->col = (yyvsp[(1) - (1)].token)->col;}
    break;


/* Line 1267 of yacc.c.  */
#line 2047 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 163 "jac.y"


void yyerror(const char *s) {
  error_flag = 1;
	printf("Line %d, col %d: %s: %s\n", line, col - yyleng, s, yytext);
}

