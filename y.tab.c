/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "jac.y" /* yacc.c:339  */

  #include <stdio.h>
  #include <string.h>
  #include "ast.h"
  #include "symbol_table.h"
  void yyerror();
  int yylex();

  node* ast;

  extern char* yytext;
  extern int line, col, yyleng;

#line 80 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 15 "jac.y" /* yacc.c:355  */

  struct token_struct* token;
  struct node *node;

#line 223 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 238 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

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
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  176

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   304

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
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

#if YYDEBUG || YYERROR_VERBOSE || 0
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
  "ParseArgs", "ExprAux", "Expr", "Type", "IDAux", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304
};
# endif

#define YYPACT_NINF -54

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-54)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
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

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
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

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -54,   -54,   -54,   -54,   -54,   -54,   126,   -54,   -54,   128,
     -54,   -54,   -54,    72,   -54,   -54,   -54,   -54,   -54,    32,
     -31,   -54,   -28,   -27,   -54,   -54,   -26,    76,   -53,    43,
      -1
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     7,    12,    13,    27,    28,    14,    21,    53,
      22,    54,    55,    56,    57,    25,    30,    45,    86,    87,
      46,    82,    75,    76,   159,   101,    77,    78,    79,    58,
     106
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
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

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
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


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

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
#line 43 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = ast = create_and_insert_node("Program", 1, 2, (yyvsp[-3].node), (yyvsp[-1].node));}
#line 1472 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 45 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = create_and_insert_node("Program", 0, 2, (yyvsp[-1].node), (yyvsp[0].node));}
#line 1478 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 46 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = create_terminal_node("Empty", 0, NULL);}
#line 1484 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 48 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = create_and_insert_node("FieldDeclAux", 0, 1, (yyvsp[0].node));}
#line 1490 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 49 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = create_and_insert_node("MethodDeclAux", 0, 1, (yyvsp[0].node));}
#line 1496 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 50 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = create_terminal_node("Semi", 0, NULL);}
#line 1502 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 52 "jac.y" /* yacc.c:1646  */
    {if ((yyvsp[-1].node) != NULL) { ast_decl((yyvsp[-2].node), (yyvsp[-1].node)); (yyval.node) = (yyvsp[-1].node); } else { (yyval.node) = (yyvsp[-1].node); }}
#line 1508 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 53 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = NULL; }
#line 1514 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 55 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = create_and_insert_node("FieldDecl", 0, 2, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1520 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 56 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 58 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = create_and_insert_node("FieldDecl", 1, 1, (yyvsp[0].node));}
#line 1532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 60 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = create_and_insert_node("MethodDecl", 1, 2, (yyvsp[-1].node), (yyvsp[0].node));}
#line 1538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 62 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = create_and_insert_node("MethodHeader", 1, 3, (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-1].node));}
#line 1544 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 63 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = create_and_insert_node("MethodHeader", 1, 3, (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-1].node));}
#line 1550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 65 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1556 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 66 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = create_and_insert_node("MethodParams", 1, 1, (yyvsp[0].node));}
#line 1562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 67 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = create_and_insert_node("MethodParams", 1, 0);}
#line 1568 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 69 "jac.y" /* yacc.c:1646  */
    {(yyval.node)=create_terminal_node("Void", 1, (yyvsp[0].token));}
#line 1574 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 71 "jac.y" /* yacc.c:1646  */
    {(yyvsp[-2].node)->to_be_used = 0; (yyval.node) = create_and_insert_node("MethodParams", 1, 2, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 72 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = create_and_insert_node("MethodParams", 1, 1, (yyvsp[0].node));}
#line 1586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 74 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = create_and_insert_node("ParamDecl", 1, 2, (yyvsp[-3].node), (yyvsp[0].node));}
#line 1592 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 76 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = create_and_insert_node("ParamDecl", 1, 2, (yyvsp[-1].node), (yyvsp[0].node));}
#line 1598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 78 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = create_and_insert_node("StringArray", 1, 0);}
#line 1604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 80 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = create_and_insert_node("MethodBody", 1, 1, (yyvsp[-1].node));}
#line 1610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 82 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = create_and_insert_node("MethodBody", 0, 2, (yyvsp[-1].node), (yyvsp[0].node));}
#line 1616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 83 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = create_and_insert_node("MethodBody", 0, 2, (yyvsp[-1].node), (yyvsp[0].node));}
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 84 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = create_terminal_node("Empty", 0, NULL);}
#line 1628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 88 "jac.y" /* yacc.c:1646  */
    {if ((yyvsp[-1].node) != NULL) { ast_decl((yyvsp[-2].node), (yyvsp[-1].node)); (yyval.node) = (yyvsp[-1].node); } else { (yyval.node) = (yyvsp[-1].node); } }
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 90 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = create_and_insert_node("VarDecl", 0, 2, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 91 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 93 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = create_and_insert_node("VarDecl", 1, 1, (yyvsp[0].node));}
#line 1652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 95 "jac.y" /* yacc.c:1646  */
    {if((yyvsp[-1].node) != NULL && (yyvsp[-1].node)->n_children <= 1) {(yyval.node) = create_and_insert_node("Block", 0, 1, (yyvsp[-1].node)); } else { (yyval.node) = create_and_insert_node("Block", 1, 1, (yyvsp[-1].node));}}
#line 1658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 96 "jac.y" /* yacc.c:1646  */
    {if(check_if_expr((yyvsp[-2].node))){ (yyvsp[-2].node) = create_terminal_node("Block", 1, NULL);} if(check_if_statement((yyvsp[0].node))){ (yyvsp[0].node) = create_terminal_node("Block", 1, NULL);} (yyval.node) = create_and_insert_node("If", 1, 3, (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));}
#line 1664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 97 "jac.y" /* yacc.c:1646  */
    {if(check_if_expr((yyvsp[0].node))){ (yyvsp[0].node) = create_terminal_node("Block", 1, NULL);} (yyval.node) = create_and_insert_node("If", 1, 3, (yyvsp[-2].node), (yyvsp[0].node), create_terminal_node("Block", 1, NULL));}
#line 1670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 98 "jac.y" /* yacc.c:1646  */
    {if(check_while_statement((yyvsp[0].node))){ (yyvsp[0].node) = create_terminal_node("Block", 1, NULL);} (yyval.node) = create_and_insert_node("While", 1, 2, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 99 "jac.y" /* yacc.c:1646  */
    {if(check_while_statement((yyvsp[-5].node))){ (yyvsp[-5].node) = create_terminal_node("Block", 1, NULL);} (yyval.node) = create_and_insert_node("DoWhile", 1, 2, (yyvsp[-5].node), (yyvsp[-2].node));}
#line 1682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 100 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = create_and_insert_node("Print", 1, 1, (yyvsp[-2].node));}
#line 1688 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 101 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = create_and_insert_node("Print", 1, 1, (yyvsp[-2].node));}
#line 1694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 102 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = create_and_insert_node("Assign", 1, 1, (yyvsp[-1].node));}
#line 1700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 103 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = create_and_insert_node("Call", 1, 1, (yyvsp[-1].node));}
#line 1706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 104 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = create_and_insert_node("ParseArgs", 1, 1, (yyvsp[-1].node));}
#line 1712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 105 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = create_terminal_node("Semi", 0, NULL);}
#line 1718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 106 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = create_and_insert_node("Return", 1, 1, (yyvsp[-1].node));}
#line 1724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 107 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = create_and_insert_node("Return", 1, 0);}
#line 1730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 108 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = create_terminal_node("Error", 0, NULL);}
#line 1736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 110 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = create_and_insert_node("Statement", 0, 2, (yyvsp[-1].node), (yyvsp[0].node));}
#line 1742 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 111 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = create_terminal_node("Empty", 0, NULL);}
#line 1748 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 113 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = create_and_insert_node("Assign", 0, 2, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 115 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = create_and_insert_node("Call", 0, 3, (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[-1].node));}
#line 1760 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 116 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = create_and_insert_node("Call", 0, 1, (yyvsp[-2].node));}
#line 1766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 117 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = create_terminal_node("Error", 0, NULL);}
#line 1772 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 119 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = create_and_insert_node("Call", 0, 2, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 120 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = create_terminal_node("Empty", 0, NULL);}
#line 1784 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 122 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = create_terminal_node("StrLit", 1, (yyvsp[0].token));}
#line 1790 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 124 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = create_and_insert_node("ParseArgs", 0, 2, (yyvsp[-4].node), (yyvsp[-2].node));}
#line 1796 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 125 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = create_terminal_node("Error", 0, NULL);}
#line 1802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 127 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = create_and_insert_node("Call", 1, 1, (yyvsp[0].node));}
#line 1808 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 128 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = create_and_insert_node("ParseArgs", 1, 1, (yyvsp[0].node));}
#line 1814 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 129 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = create_and_insert_node("And", 1, 2, (yyvsp[-2].node), (yyvsp[0].node));(yyval.node)->token->line = (yyvsp[-1].token)->line;(yyval.node)->token->col = (yyvsp[-1].token)->col;}
#line 1820 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 130 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = create_and_insert_node("Or", 1, 2, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1826 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 131 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = create_and_insert_node("Eq", 1, 2, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1832 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 132 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = create_and_insert_node("Geq", 1, 2, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1838 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 133 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = create_and_insert_node("Gt", 1, 2, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1844 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 134 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = create_and_insert_node("Leq", 1, 2, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1850 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 135 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = create_and_insert_node("Lt", 1, 2, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1856 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 136 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = create_and_insert_node("Neq", 1, 2, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1862 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 137 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = create_and_insert_node("Add", 1, 2, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1868 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 138 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = create_and_insert_node("Sub", 1, 2, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1874 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 139 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = create_and_insert_node("Mul", 1, 2, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 140 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = create_and_insert_node("Div", 1, 2, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1886 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 141 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = create_and_insert_node("Mod", 1, 2, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1892 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 142 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = create_and_insert_node("Plus", 1, 1, (yyvsp[0].node));}
#line 1898 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 143 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = create_and_insert_node("Minus", 1, 1, (yyvsp[0].node));}
#line 1904 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 144 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = create_and_insert_node("Not", 1, 1, (yyvsp[0].node));}
#line 1910 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 145 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1916 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 146 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = create_and_insert_node("Length", 1, 1, (yyvsp[-1].node));}
#line 1922 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 147 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 1928 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 148 "jac.y" /* yacc.c:1646  */
    {(yyval.node)=create_terminal_node("BoolLit", 1, (yyvsp[0].token));}
#line 1934 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 149 "jac.y" /* yacc.c:1646  */
    {(yyval.node)=create_terminal_node("DecLit", 1, (yyvsp[0].token));}
#line 1940 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 150 "jac.y" /* yacc.c:1646  */
    {(yyval.node)=create_terminal_node("RealLit", 1, (yyvsp[0].token));}
#line 1946 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 151 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = create_terminal_node("Error", 0, NULL);}
#line 1952 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 154 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = create_and_insert_node("Assign", 1, 1, (yyvsp[0].node));}
#line 1958 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 155 "jac.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1964 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 157 "jac.y" /* yacc.c:1646  */
    {(yyval.node)=create_terminal_node("Bool", 1, (yyvsp[0].token));}
#line 1970 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 158 "jac.y" /* yacc.c:1646  */
    {(yyval.node)=create_terminal_node("Int", 1, (yyvsp[0].token));}
#line 1976 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 159 "jac.y" /* yacc.c:1646  */
    {(yyval.node)=create_terminal_node("Double", 1, (yyvsp[0].token));}
#line 1982 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 161 "jac.y" /* yacc.c:1646  */
    {(yyval.node)=create_terminal_node("Id", 1, (yyvsp[0].token));}
#line 1988 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1992 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 163 "jac.y" /* yacc.c:1906  */


void yyerror(const char *s) {
  error_flag = 1;
	printf("Line %d, col %d: %s: %s\n", line, col - yyleng, s, yytext);
}
