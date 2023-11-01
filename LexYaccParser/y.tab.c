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
     VOID = 258,
     AUTO = 259,
     BREAK = 260,
     CASE = 261,
     CHAR = 262,
     CONST = 263,
     CONTINUE = 264,
     DEFAULT = 265,
     DO = 266,
     DOUBLE = 267,
     ELSE = 268,
     ENUM = 269,
     EXTERN = 270,
     FLOAT = 271,
     FOR = 272,
     GOTO = 273,
     IF = 274,
     INLINE = 275,
     INT = 276,
     LONG = 277,
     REGISTER = 278,
     RESTRICT = 279,
     RETURN = 280,
     SHORT = 281,
     SIGNED = 282,
     SIZEOF = 283,
     STATIC = 284,
     STRUCT = 285,
     SWITCH = 286,
     TYPEDEF = 287,
     UNION = 288,
     UNSIGNED = 289,
     VOLATILE = 290,
     WHILE = 291,
     _ALIGNAS = 292,
     _ALIGNOF = 293,
     _ATOMIC = 294,
     _BOOL = 295,
     _COMPLEX = 296,
     _GENERIC = 297,
     _IMAGINARY = 298,
     _NORETURN = 299,
     _STATIC_ASSERT = 300,
     _THREAD_LOCAL = 301,
     IDENTIFIER = 302,
     NUMBER = 303,
     INCLUDE = 304,
     LP = 305,
     RP = 306,
     COMMA = 307,
     LETTICE = 308,
     DLETTICE = 309,
     LC = 310,
     RC = 311,
     LB = 312,
     RB = 313,
     DOT = 314,
     AND = 315,
     STAR = 316,
     PLUS = 317,
     MINUS = 318,
     TILDA = 319,
     NOT = 320,
     DIV = 321,
     MOD = 322,
     LT = 323,
     MT = 324,
     XOR = 325,
     OR = 326,
     QUESTION = 327,
     COLON = 328,
     SEMICOLON = 329,
     ASSIGN = 330,
     DCOLON = 331,
     ARROW = 332,
     ICREMENT = 333,
     DECREMENT = 334,
     DLT = 335,
     DMT = 336,
     LE = 337,
     GE = 338,
     EQ = 339,
     NE = 340,
     DAND = 341,
     DOR = 342,
     MULTASSIGN = 343,
     DIVASSIGN = 344,
     MODASSIGN = 345,
     PLUSASSIGN = 346,
     MINUSASSIGN = 347,
     DLTASSIGN = 348,
     DMTASSIGN = 349,
     ANDASSIGN = 350,
     XORASSIGN = 351,
     ORASSIGN = 352,
     COMMENT = 353,
     STR = 354,
     CHARACTER = 355
   };
#endif
/* Tokens.  */
#define VOID 258
#define AUTO 259
#define BREAK 260
#define CASE 261
#define CHAR 262
#define CONST 263
#define CONTINUE 264
#define DEFAULT 265
#define DO 266
#define DOUBLE 267
#define ELSE 268
#define ENUM 269
#define EXTERN 270
#define FLOAT 271
#define FOR 272
#define GOTO 273
#define IF 274
#define INLINE 275
#define INT 276
#define LONG 277
#define REGISTER 278
#define RESTRICT 279
#define RETURN 280
#define SHORT 281
#define SIGNED 282
#define SIZEOF 283
#define STATIC 284
#define STRUCT 285
#define SWITCH 286
#define TYPEDEF 287
#define UNION 288
#define UNSIGNED 289
#define VOLATILE 290
#define WHILE 291
#define _ALIGNAS 292
#define _ALIGNOF 293
#define _ATOMIC 294
#define _BOOL 295
#define _COMPLEX 296
#define _GENERIC 297
#define _IMAGINARY 298
#define _NORETURN 299
#define _STATIC_ASSERT 300
#define _THREAD_LOCAL 301
#define IDENTIFIER 302
#define NUMBER 303
#define INCLUDE 304
#define LP 305
#define RP 306
#define COMMA 307
#define LETTICE 308
#define DLETTICE 309
#define LC 310
#define RC 311
#define LB 312
#define RB 313
#define DOT 314
#define AND 315
#define STAR 316
#define PLUS 317
#define MINUS 318
#define TILDA 319
#define NOT 320
#define DIV 321
#define MOD 322
#define LT 323
#define MT 324
#define XOR 325
#define OR 326
#define QUESTION 327
#define COLON 328
#define SEMICOLON 329
#define ASSIGN 330
#define DCOLON 331
#define ARROW 332
#define ICREMENT 333
#define DECREMENT 334
#define DLT 335
#define DMT 336
#define LE 337
#define GE 338
#define EQ 339
#define NE 340
#define DAND 341
#define DOR 342
#define MULTASSIGN 343
#define DIVASSIGN 344
#define MODASSIGN 345
#define PLUSASSIGN 346
#define MINUSASSIGN 347
#define DLTASSIGN 348
#define DMTASSIGN 349
#define ANDASSIGN 350
#define XORASSIGN 351
#define ORASSIGN 352
#define COMMENT 353
#define STR 354
#define CHARACTER 355




/* Copy the first part of user declarations.  */
#line 1 "cparcer2.y"

#include <stdio.h>
#include <stdlib.h>
#include "lex.yy.c"

void yyerror(const char *s);
int yylex();
int yywrap();
int search(char *name);

int ic_idx=0;
int tc_idx=0;
int temp_var=0;
int temp_r=1;
int label=0;
int is_for=0;
char buff[100];
char rbuff[100];
char errors[10][100];
char reserved[10][10] = {"int", "float", "char", "void", "if", "else", "for", "main", "return", "include"};
char icg[100][100];
char tcg[100][100];
struct regVar {
    char name[120];
    int rNumber;
} regVars[120];
    
double arResults[1000];



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
#line 32 "cparcer2.y"
{ struct var_name {
            char name[120];
            int rNumber;
            struct node* nd;
        } nd_obj;

        struct var_name2 {
            char name[100];
            struct node* nd;
            char type[5];
        } nd_obj2;

        struct var_name3 {
            char name[100];
            struct node* nd;
            char if_body[5];
            char else_body[5];
        } nd_obj3;

    }
/* Line 193 of yacc.c.  */
#line 348 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 361 "y.tab.c"

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   660

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  101
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  98
/* YYNRULES -- Number of states.  */
#define YYNSTATES  176

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   355

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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     9,    11,    12,    20,    24,    25,
      28,    30,    32,    34,    36,    38,    40,    43,    46,    48,
      50,    54,    55,    56,    57,    58,    70,    73,    78,    79,
      83,    87,    90,    94,    96,    98,   100,   101,   114,   115,
     124,   134,   138,   142,   145,   148,   152,   154,   156,   161,
     169,   172,   173,   175,   177,   179,   181,   185,   189,   191,
     193,   197,   201,   205,   208,   211,   215,   221,   227,   229,
     231,   233,   235,   237,   239,   241,   243,   245,   247,   249,
     251,   253,   255,   257,   259,   261,   263,   265,   267,   269,
     271,   273,   275,   277,   279,   281,   283,   285,   287
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     102,     0,    -1,   103,   104,    -1,   103,   103,    -1,    49,
      -1,    -1,   106,    50,    51,    55,   108,   105,    56,    -1,
      25,   124,    74,    -1,    -1,   107,    47,    -1,    21,    -1,
      22,    -1,    16,    -1,    26,    -1,     3,    -1,     7,    -1,
     108,   108,    -1,   121,    74,    -1,   109,    -1,   115,    -1,
      55,   108,    56,    -1,    -1,    -1,    -1,    -1,    19,   110,
      50,   114,    51,   111,    55,   108,    56,   112,   113,    -1,
      13,   109,    -1,    13,    55,   108,    56,    -1,    -1,   124,
     127,   124,    -1,   114,   128,   114,    -1,   129,   114,    -1,
      50,   114,    51,    -1,   116,    -1,   118,    -1,   120,    -1,
      -1,    17,   117,    50,   121,    74,   114,    74,   124,    51,
      55,   108,    56,    -1,    -1,    36,   119,    50,   114,    51,
      55,   108,    56,    -1,    11,    55,   108,    56,    36,    50,
     114,    51,    74,    -1,   107,    47,   122,    -1,    47,   130,
     124,    -1,   126,   124,    -1,   124,   126,    -1,    50,   121,
      51,    -1,     9,    -1,     5,    -1,    47,    50,    99,    51,
      -1,    47,    50,    99,    52,    60,    47,    51,    -1,    75,
     124,    -1,    -1,    48,    -1,    99,    -1,   100,    -1,   125,
      -1,   124,    62,   124,    -1,   124,    63,   124,    -1,   123,
      -1,    47,    -1,   125,    61,   125,    -1,   125,    66,   125,
      -1,   125,    67,   125,    -1,   126,   125,    -1,   125,   126,
      -1,    50,   125,    51,    -1,    50,   125,    62,   125,    51,
      -1,    50,   125,    63,   125,    51,    -1,    78,    -1,    79,
      -1,    82,    -1,    83,    -1,    84,    -1,    85,    -1,    86,
      -1,    87,    -1,    68,    -1,    69,    -1,    60,    -1,    71,
      -1,    70,    -1,    86,    -1,    87,    -1,    65,    -1,    82,
      -1,    83,    -1,    84,    -1,    85,    -1,    88,    -1,    89,
      -1,    90,    -1,    91,    -1,    92,    -1,    93,    -1,    94,
      -1,    95,    -1,    96,    -1,    97,    -1,    75,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    76,    76,    79,    80,    81,    84,    87,   104,   107,
     110,   111,   112,   113,   114,   115,   118,   119,   120,   121,
     122,   123,   126,   126,   126,   126,   131,   132,   133,   136,
     200,   238,   239,   242,   243,   244,   247,   247,   257,   257,
     265,   268,   292,   309,   327,   345,   346,   347,   348,   349,
     352,   353,   356,   357,   358,   361,   362,   407,   459,   460,
     461,   506,   551,   556,   574,   592,   593,   638,   691,   692,
     695,   696,   697,   698,   699,   700,   701,   702,   705,   706,
     707,   708,   709,   712,   715,   716,   717,   718,   719,   720,
     721,   722,   723,   724,   725,   726,   727,   728,   729
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VOID", "AUTO", "BREAK", "CASE", "CHAR",
  "CONST", "CONTINUE", "DEFAULT", "DO", "DOUBLE", "ELSE", "ENUM", "EXTERN",
  "FLOAT", "FOR", "GOTO", "IF", "INLINE", "INT", "LONG", "REGISTER",
  "RESTRICT", "RETURN", "SHORT", "SIGNED", "SIZEOF", "STATIC", "STRUCT",
  "SWITCH", "TYPEDEF", "UNION", "UNSIGNED", "VOLATILE", "WHILE",
  "_ALIGNAS", "_ALIGNOF", "_ATOMIC", "_BOOL", "_COMPLEX", "_GENERIC",
  "_IMAGINARY", "_NORETURN", "_STATIC_ASSERT", "_THREAD_LOCAL",
  "IDENTIFIER", "NUMBER", "INCLUDE", "LP", "RP", "COMMA", "LETTICE",
  "DLETTICE", "LC", "RC", "LB", "RB", "DOT", "AND", "STAR", "PLUS",
  "MINUS", "TILDA", "NOT", "DIV", "MOD", "LT", "MT", "XOR", "OR",
  "QUESTION", "COLON", "SEMICOLON", "ASSIGN", "DCOLON", "ARROW",
  "ICREMENT", "DECREMENT", "DLT", "DMT", "LE", "GE", "EQ", "NE", "DAND",
  "DOR", "MULTASSIGN", "DIVASSIGN", "MODASSIGN", "PLUSASSIGN",
  "MINUSASSIGN", "DLTASSIGN", "DMTASSIGN", "ANDASSIGN", "XORASSIGN",
  "ORASSIGN", "COMMENT", "STR", "CHARACTER", "$accept", "program",
  "headers", "main_function", "return", "main", "datatype", "body",
  "op_if_else", "@1", "@2", "@3", "else", "condition", "op_loop",
  "for_loop", "@4", "while_loop", "@5", "do_while_loop", "op_statement",
  "init", "value", "statement", "p_stetament", "arithmetic_unar_sign",
  "compare_bin_sign", "logic_bin_sign", "logic_unar_sign", "assign_sign", 0
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   101,   102,   103,   103,   103,   104,   105,   105,   106,
     107,   107,   107,   107,   107,   107,   108,   108,   108,   108,
     108,   108,   110,   111,   112,   109,   113,   113,   113,   114,
     114,   114,   114,   115,   115,   115,   117,   116,   119,   118,
     120,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     122,   122,   123,   123,   123,   124,   124,   124,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   126,   126,
     127,   127,   127,   127,   127,   127,   127,   127,   128,   128,
     128,   128,   128,   129,   130,   130,   130,   130,   130,   130,
     130,   130,   130,   130,   130,   130,   130,   130,   130
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     1,     0,     7,     3,     0,     2,
       1,     1,     1,     1,     1,     1,     2,     2,     1,     1,
       3,     0,     0,     0,     0,    11,     2,     4,     0,     3,
       3,     2,     3,     1,     1,     1,     0,    12,     0,     8,
       9,     3,     3,     2,     2,     3,     1,     1,     4,     7,
       2,     0,     1,     1,     1,     1,     3,     3,     1,     1,
       3,     3,     3,     2,     2,     3,     5,     5,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     4,     0,     0,     1,    14,    15,    12,    10,    11,
      13,     3,     2,     0,     0,     0,     9,     0,    21,    47,
      46,     0,    36,    22,    38,    59,    52,     0,    21,    68,
      69,    53,    54,     0,     8,    18,    19,    33,    34,    35,
       0,    58,     0,    55,     0,    21,     0,     0,     0,     0,
      98,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,     0,     0,    55,     0,    51,
       0,     0,    16,    17,     0,     0,    44,     0,     0,     0,
      64,    59,     0,    43,    55,     0,     0,     0,     0,     0,
       0,    42,    45,    65,     0,     0,    20,     0,    41,     0,
       6,    56,    57,    60,    61,    62,     0,    63,     0,     0,
       0,    83,     0,     0,     0,     0,    48,     0,     0,     0,
      50,     7,     0,     0,     0,    23,    78,    80,    79,    81,
      82,     0,    76,    77,    70,    71,    72,    73,    74,    75,
       0,    31,     0,     0,    66,    67,     0,     0,    32,     0,
      30,    29,    21,     0,     0,     0,    21,     0,    49,     0,
       0,     0,    39,    40,     0,    24,    21,    28,     0,     0,
      25,    37,    21,    26,     0,    27
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    11,    12,    71,    13,    33,    72,    35,    47,
     149,   167,   170,   112,    36,    37,    46,    38,    48,    39,
      40,    98,    41,    42,    43,    85,   140,   131,   114,    65
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -89
static const yytype_int16 yypact[] =
{
     -43,   -89,    19,   103,   -89,   -89,   -89,   -89,   -89,   -89,
     -89,   -43,   -89,   -42,   -16,   -12,   -89,   -19,   525,   -89,
     -89,   -10,   -89,   -89,   -89,   538,   -89,   560,   525,   -89,
     -89,   -89,   -89,    -1,   155,   -89,   -89,   -89,   -89,   -89,
     -21,   -89,   107,   163,    68,   525,    -3,     7,    10,   -36,
     -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
     -89,   -89,   -89,   -89,   -89,    68,    16,    42,   190,     3,
      68,    18,   525,   -89,    68,    68,   -89,    68,    68,    68,
     -89,   -89,    68,   -58,   163,    68,   255,   560,   -27,   -27,
     -37,   -58,   -89,   -89,    68,    68,   -89,    68,   -89,   -34,
     -89,   -58,   -58,   163,   163,   163,    42,   163,    44,     9,
     -27,   -89,   157,   515,   -27,   222,   -89,    22,   153,   219,
     -58,   -89,    34,   -27,   236,   -89,   -89,   -89,   -89,   -89,
     -89,   -27,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
      68,   -53,    59,    50,   -89,   -89,   -27,     5,   -89,    62,
     -53,   -58,   525,    72,   276,    68,   525,   309,   -89,    52,
       8,   363,   -89,   -89,    73,   -89,   525,   117,   417,    -7,
     -89,   -89,   525,   -89,   471,   -89
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -89,   -89,   131,   -89,   -89,   -89,   129,   -15,   -29,   -89,
     -89,   -89,   -89,   -88,   -89,   -89,   -89,   -89,   -89,   -89,
     -25,   -89,   -89,   -33,    17,   -18,   -89,   -89,   -89,   -89
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      44,   115,    66,    34,    74,    75,     1,   126,    15,    44,
      44,    83,    23,    68,   116,   117,    44,   127,   128,     4,
      81,    26,   124,   110,    76,    80,   141,    44,    74,    75,
      86,    16,    91,   129,   130,   147,    18,    99,   111,    17,
     121,   101,   102,   150,    67,    45,    69,    87,   172,    80,
      44,    29,    30,    73,    44,   113,   113,    88,   154,   164,
      89,    84,   109,    90,   120,   126,    80,    92,    44,    44,
      74,    75,    31,    32,   100,   127,   128,   113,    97,   155,
     122,   113,   143,   123,   146,    80,    80,    80,    80,    80,
     113,   129,   130,    93,   103,   104,   105,   153,   113,   106,
      80,    80,   107,    77,    94,    95,     5,   151,    78,    79,
       6,   118,   119,   113,   152,    81,    26,   156,    82,     7,
      29,    30,   160,   158,     8,     9,   163,    67,   166,    10,
     169,     3,    14,     0,    44,     0,     0,   157,    44,    44,
     173,   161,     0,    44,     0,     0,    29,    30,    44,     0,
      44,   168,     1,     0,    44,     0,    44,   174,     5,     0,
      19,     0,     6,     0,    20,     0,    21,    31,    32,    74,
      75,     7,    22,     0,    23,     0,     8,     9,     0,     0,
      70,    10,     0,     0,     0,    29,    30,     0,     0,     0,
       0,    24,     0,     5,     0,    19,     0,     6,     0,    20,
       0,    21,    25,    26,   144,    27,     7,    22,   125,    23,
      28,     8,     9,     0,    77,     0,    10,   126,     0,    78,
      79,     0,     0,     0,    77,     0,    24,   127,   128,    78,
      79,    29,    30,    29,    30,     0,     0,    25,    26,     0,
      27,    29,    30,   129,   130,    28,    96,     0,     0,     0,
       0,     0,     0,     0,    31,    32,     0,     0,     5,     0,
      19,     0,     6,     0,    20,     0,    21,     0,    29,    30,
     145,     7,    22,   142,    23,     0,     8,     9,     0,     0,
      77,    10,   126,     0,     0,    78,    79,   148,     0,    31,
      32,    24,   127,   128,     0,     0,   126,    29,    30,     0,
       0,     0,    25,    26,     0,    27,   127,   128,   129,   130,
      28,   108,     5,     0,    19,     0,     6,     0,    20,     0,
      21,     0,   129,   130,     0,     7,    22,   159,    23,     0,
       8,     9,     0,    29,    30,    10,   126,     0,     0,     0,
       0,     0,     0,     0,     0,    24,   127,   128,     0,     0,
       0,     0,     0,     0,    31,    32,    25,    26,     0,    27,
       0,     0,   129,   130,    28,   162,     5,     0,    19,     0,
       6,     0,    20,     0,    21,     0,     0,     0,     0,     7,
      22,     0,    23,     0,     8,     9,     0,    29,    30,    10,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    24,
       0,     0,     0,     0,     0,     0,     0,     0,    31,    32,
      25,    26,     0,    27,     0,     0,     0,     0,    28,   165,
       5,     0,    19,     0,     6,     0,    20,     0,    21,     0,
       0,     0,     0,     7,    22,     0,    23,     0,     8,     9,
       0,    29,    30,    10,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    24,     0,     0,     0,     0,     0,     0,
       0,     0,    31,    32,    25,    26,     0,    27,     0,     0,
       0,     0,    28,   171,     5,     0,    19,     0,     6,     0,
      20,     0,    21,     0,     0,     0,     0,     7,    22,     0,
      23,     0,     8,     9,     0,    29,    30,    10,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    24,     0,     0,
       0,     0,     0,     0,     0,     0,    31,    32,    25,    26,
       0,    27,     0,     0,     0,     0,    28,   175,     5,     0,
      19,     0,     6,     0,    20,     0,    21,     0,     0,     0,
       0,     7,    22,     0,    23,     0,     8,     9,     0,    29,
      30,    10,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    24,     0,     5,     0,    19,     0,     6,     0,    20,
      31,    32,    25,    26,     0,    27,     7,    74,    75,     0,
      28,     8,     9,   132,   133,     0,    10,     0,    49,     0,
       0,     0,     0,     0,     0,     0,     0,   134,   135,   136,
     137,   138,   139,    29,    30,     0,     0,    25,    26,     0,
      27,     0,     0,    50,     0,     0,     0,     0,     0,     0,
      51,    52,    53,    54,    31,    32,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,     0,     0,    29,    30,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    31,
      32
};

static const yytype_int16 yycheck[] =
{
      18,    89,    27,    18,    62,    63,    49,    60,    50,    27,
      28,    44,    19,    28,    51,    52,    34,    70,    71,     0,
      47,    48,   110,    50,    42,    43,   114,    45,    62,    63,
      45,    47,    65,    86,    87,   123,    55,    70,    65,    51,
      74,    74,    75,   131,    27,    55,    47,    50,    55,    67,
      68,    78,    79,    74,    72,    88,    89,    50,   146,    51,
      50,    44,    87,    99,    97,    60,    84,    51,    86,    87,
      62,    63,    99,   100,    56,    70,    71,   110,    75,    74,
      36,   114,    60,    74,    50,   103,   104,   105,   106,   107,
     123,    86,    87,    51,    77,    78,    79,    47,   131,    82,
     118,   119,    85,    61,    62,    63,     3,   140,    66,    67,
       7,    94,    95,   146,    55,    47,    48,    55,    50,    16,
      78,    79,   155,    51,    21,    22,    74,   110,    55,    26,
      13,     0,     3,    -1,   152,    -1,    -1,   152,   156,   157,
     169,   156,    -1,   161,    -1,    -1,    78,    79,   166,    -1,
     168,   166,    49,    -1,   172,    -1,   174,   172,     3,    -1,
       5,    -1,     7,    -1,     9,    -1,    11,    99,   100,    62,
      63,    16,    17,    -1,    19,    -1,    21,    22,    -1,    -1,
      25,    26,    -1,    -1,    -1,    78,    79,    -1,    -1,    -1,
      -1,    36,    -1,     3,    -1,     5,    -1,     7,    -1,     9,
      -1,    11,    47,    48,    51,    50,    16,    17,    51,    19,
      55,    21,    22,    -1,    61,    -1,    26,    60,    -1,    66,
      67,    -1,    -1,    -1,    61,    -1,    36,    70,    71,    66,
      67,    78,    79,    78,    79,    -1,    -1,    47,    48,    -1,
      50,    78,    79,    86,    87,    55,    56,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    99,   100,    -1,    -1,     3,    -1,
       5,    -1,     7,    -1,     9,    -1,    11,    -1,    78,    79,
      51,    16,    17,    51,    19,    -1,    21,    22,    -1,    -1,
      61,    26,    60,    -1,    -1,    66,    67,    51,    -1,    99,
     100,    36,    70,    71,    -1,    -1,    60,    78,    79,    -1,
      -1,    -1,    47,    48,    -1,    50,    70,    71,    86,    87,
      55,    56,     3,    -1,     5,    -1,     7,    -1,     9,    -1,
      11,    -1,    86,    87,    -1,    16,    17,    51,    19,    -1,
      21,    22,    -1,    78,    79,    26,    60,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    36,    70,    71,    -1,    -1,
      -1,    -1,    -1,    -1,    99,   100,    47,    48,    -1,    50,
      -1,    -1,    86,    87,    55,    56,     3,    -1,     5,    -1,
       7,    -1,     9,    -1,    11,    -1,    -1,    -1,    -1,    16,
      17,    -1,    19,    -1,    21,    22,    -1,    78,    79,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,
      47,    48,    -1,    50,    -1,    -1,    -1,    -1,    55,    56,
       3,    -1,     5,    -1,     7,    -1,     9,    -1,    11,    -1,
      -1,    -1,    -1,    16,    17,    -1,    19,    -1,    21,    22,
      -1,    78,    79,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    99,   100,    47,    48,    -1,    50,    -1,    -1,
      -1,    -1,    55,    56,     3,    -1,     5,    -1,     7,    -1,
       9,    -1,    11,    -1,    -1,    -1,    -1,    16,    17,    -1,
      19,    -1,    21,    22,    -1,    78,    79,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    99,   100,    47,    48,
      -1,    50,    -1,    -1,    -1,    -1,    55,    56,     3,    -1,
       5,    -1,     7,    -1,     9,    -1,    11,    -1,    -1,    -1,
      -1,    16,    17,    -1,    19,    -1,    21,    22,    -1,    78,
      79,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    36,    -1,     3,    -1,     5,    -1,     7,    -1,     9,
      99,   100,    47,    48,    -1,    50,    16,    62,    63,    -1,
      55,    21,    22,    68,    69,    -1,    26,    -1,    50,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,    83,    84,
      85,    86,    87,    78,    79,    -1,    -1,    47,    48,    -1,
      50,    -1,    -1,    75,    -1,    -1,    -1,    -1,    -1,    -1,
      82,    83,    84,    85,    99,   100,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    -1,    -1,    78,    79,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,
     100
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    49,   102,   103,     0,     3,     7,    16,    21,    22,
      26,   103,   104,   106,   107,    50,    47,    51,    55,     5,
       9,    11,    17,    19,    36,    47,    48,    50,    55,    78,
      79,    99,   100,   107,   108,   109,   115,   116,   118,   120,
     121,   123,   124,   125,   126,    55,   117,   110,   119,    50,
      75,    82,    83,    84,    85,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,   130,   121,   125,   108,    47,
      25,   105,   108,    74,    62,    63,   126,    61,    66,    67,
     126,    47,    50,   124,   125,   126,   108,    50,    50,    50,
      99,   124,    51,    51,    62,    63,    56,    75,   122,   124,
      56,   124,   124,   125,   125,   125,   125,   125,    56,   121,
      50,    65,   114,   124,   129,   114,    51,    52,   125,   125,
     124,    74,    36,    74,   114,    51,    60,    70,    71,    86,
      87,   128,    68,    69,    82,    83,    84,    85,    86,    87,
     127,   114,    51,    60,    51,    51,    50,   114,    51,   111,
     114,   124,    55,    47,   114,    74,    55,   108,    51,    51,
     124,   108,    56,    74,    51,    56,    55,   112,   108,    13,
     113,    56,    55,   109,   108,    56
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
        case 7:
#line 87 "cparcer2.y"
    {
    int t = search((yyvsp[(2) - (3)].nd_obj2).name);
    if(t != -1){
        sprintf(tcg[tc_idx++], "MOV R%d R%d\n", temp_r++, t);
    }else{
        sprintf(tcg[tc_idx++], "MOV R%d %s\n", temp_r++, (yyvsp[(2) - (3)].nd_obj2).name);
    }
    sprintf(tcg[tc_idx++], "RET R%d\n", temp_r-1);
    
    if(t != -1){
        sprintf(tcg[tc_idx++], "\nResult: %lf\n", arResults[t-1]);
    }else{
        sprintf(tcg[tc_idx++], "\nResult: %s\n", (yyvsp[(2) - (3)].nd_obj2).name);
    }
    
    
}
    break;

  case 22:
#line 126 "cparcer2.y"
    { is_for = 0; }
    break;

  case 23:
#line 126 "cparcer2.y"
    { sprintf(icg[ic_idx++], "\nLABEL %s:\n", (yyvsp[(4) - (5)].nd_obj3).if_body); sprintf(tcg[tc_idx++], "\n%s:\n", (yyvsp[(4) - (5)].nd_obj3).if_body); }
    break;

  case 24:
#line 126 "cparcer2.y"
    { sprintf(icg[ic_idx++], "JUMP to L%d\n", label); sprintf(tcg[tc_idx++], "JMP L%d\n", label); sprintf(icg[ic_idx++], "\nLABEL %s:\n", (yyvsp[(4) - (9)].nd_obj3).else_body); sprintf(tcg[tc_idx++], "\n%s:\n", (yyvsp[(4) - (9)].nd_obj3).else_body); }
    break;

  case 25:
#line 126 "cparcer2.y"
    {
    sprintf(icg[ic_idx++], "\nLABEL L%d:\n", label++); sprintf(tcg[tc_idx++], "\nL%d:\n", label-1);
}
    break;

  case 29:
#line 136 "cparcer2.y"
    {
    if(is_for) {
        sprintf((yyval.nd_obj3).if_body, "L%d", label++);
        sprintf(tcg[tc_idx++], "\n%s:\n", (yyval.nd_obj3).if_body);
        sprintf(icg[ic_idx++], "\nLABEL %s:\n", (yyval.nd_obj3).if_body);
        sprintf(icg[ic_idx++], "\nif NOT (%s %s %s) GOTO L%d\n", (yyvsp[(1) - (3)].nd_obj2).name, (yyvsp[(2) - (3)].nd_obj).name, (yyvsp[(3) - (3)].nd_obj2).name, label);
        sprintf((yyval.nd_obj3).else_body, "L%d", label++);
        int t1 = search((yyvsp[(1) - (3)].nd_obj2).name);
        if(t1 != -1){
            int t2 = search((yyvsp[(3) - (3)].nd_obj2).name);
            if(t2 != -1){
                sprintf(tcg[tc_idx++], "CMP R%d R%d\n", t1, t2);
            }else{
                sprintf(tcg[tc_idx++], "CMP R%d %s\n", t1, (yyvsp[(3) - (3)].nd_obj2).name);
            }
        }else{
            int t2 = search((yyvsp[(3) - (3)].nd_obj2).name);
            if(t2 != -1){
                sprintf(tcg[tc_idx++], "CMP R%d R%d\n", temp_r++, t2);
            }else{
                sprintf(tcg[tc_idx++], "CMP R%d %s\n", temp_r++, (yyvsp[(3) - (3)].nd_obj2).name);
            }
        }
        if(!strcmp((yyvsp[(2) - (3)].nd_obj).name, "<")){
            sprintf(tcg[tc_idx++], "JGE L%d\n", label-1);
        }else if(!strcmp((yyvsp[(2) - (3)].nd_obj).name, "<=")){
            sprintf(tcg[tc_idx++], "JG L%d\n", label-1);
        }else if(!strcmp((yyvsp[(2) - (3)].nd_obj).name, ">")){
            sprintf(tcg[tc_idx++], "JLE L%d\n", label-1);
        }else if(!strcmp((yyvsp[(2) - (3)].nd_obj).name, ">=")){
            sprintf(tcg[tc_idx++], "JL L%d\n", label-1);
        }
    }
    else {
        sprintf(icg[ic_idx++], "\nif (%s %s %s) GOTO L%d else GOTO L%d\n", (yyvsp[(1) - (3)].nd_obj2).name, (yyvsp[(2) - (3)].nd_obj).name, (yyvsp[(3) - (3)].nd_obj2).name, label, label+1);
        sprintf((yyval.nd_obj3).if_body, "L%d", label++);
        sprintf((yyval.nd_obj3).else_body, "L%d", label++);
        int t1 = search((yyvsp[(1) - (3)].nd_obj2).name);
        if(t1 != -1){
            int t2 = search((yyvsp[(3) - (3)].nd_obj2).name);
            if(t2 != -1){
                sprintf(tcg[tc_idx++], "CMP R%d R%d\n", t1, t2);
            }else{
                sprintf(tcg[tc_idx++], "CMP R%d %s\n", t1, (yyvsp[(3) - (3)].nd_obj2).name);
            }
        }else{
            int t2 = search((yyvsp[(3) - (3)].nd_obj2).name);
            if(t2 != -1){
                sprintf(tcg[tc_idx++], "CMP R%d R%d\n", temp_r++, t2);
            }else{
                sprintf(tcg[tc_idx++], "CMP R%d %s\n", temp_r++, (yyvsp[(3) - (3)].nd_obj2).name);
            }
        }
        if(!strcmp((yyvsp[(2) - (3)].nd_obj).name, "<")){
            sprintf(tcg[tc_idx++], "JGE L%d\n", label-1);
        }else if(!strcmp((yyvsp[(2) - (3)].nd_obj).name, "<=")){
            sprintf(tcg[tc_idx++], "JG L%d\n", label-1);
        }else if(!strcmp((yyvsp[(2) - (3)].nd_obj).name, ">")){
            sprintf(tcg[tc_idx++], "JLE L%d\n", label-1);
        }else if(!strcmp((yyvsp[(2) - (3)].nd_obj).name, ">=")){
            sprintf(tcg[tc_idx++], "JL L%d\n", label-1);
        }
    }
}
    break;

  case 30:
#line 200 "cparcer2.y"
    {
    if(is_for) {
        sprintf((yyval.nd_obj3).if_body, "L%d", label++);
        sprintf(icg[ic_idx++], "\nLABEL %s:\n", (yyval.nd_obj3).if_body);
        sprintf(icg[ic_idx++], "\nif NOT (%s %s %s) GOTO L%d\n", (yyvsp[(1) - (3)].nd_obj3).name, (yyvsp[(2) - (3)].nd_obj).name, (yyvsp[(3) - (3)].nd_obj3).name, label);
        sprintf((yyval.nd_obj3).else_body, "L%d", label++);
    }
    else {
        sprintf(icg[ic_idx++], "\nif (%s %s %s) GOTO L%d else GOTO L%d\n", (yyvsp[(1) - (3)].nd_obj3).name, (yyvsp[(2) - (3)].nd_obj).name, (yyvsp[(3) - (3)].nd_obj3).name, label, label+1);
        sprintf((yyval.nd_obj3).if_body, "L%d", label++);
        sprintf((yyval.nd_obj3).else_body, "L%d", label++);
        int t1 = search((yyvsp[(1) - (3)].nd_obj3).name);
        if(t1 != -1){
            int t2 = search((yyvsp[(3) - (3)].nd_obj3).name);
            if(t2 != -1){
                sprintf(tcg[tc_idx++], "CMP R%d R%d\n", t1, t2);
            }else{
                sprintf(tcg[tc_idx++], "CMP R%d %s\n", t1, (yyvsp[(3) - (3)].nd_obj3).name);
            }
        }else{
            int t2 = search((yyvsp[(3) - (3)].nd_obj3).name);
            if(t2 != -1){
                sprintf(tcg[tc_idx++], "CMP R%d R%d\n", temp_r++, t2);
            }else{
                sprintf(tcg[tc_idx++], "CMP R%d %s\n", temp_r++, (yyvsp[(3) - (3)].nd_obj3).name);
            }
        }
        if(!strcmp((yyvsp[(2) - (3)].nd_obj).name, "<")){
            sprintf(tcg[tc_idx++], "JGE L%d\n", label-1);
        }else if(!strcmp((yyvsp[(2) - (3)].nd_obj).name, "<=")){
            sprintf(tcg[tc_idx++], "JG L%d\n", label-1);
        }else if(!strcmp((yyvsp[(2) - (3)].nd_obj).name, ">")){
            sprintf(tcg[tc_idx++], "JLE L%d\n", label-1);
        }else if(!strcmp((yyvsp[(2) - (3)].nd_obj).name, ">=")){
            sprintf(tcg[tc_idx++], "JL L%d\n", label-1);
        }
    }
}
    break;

  case 36:
#line 247 "cparcer2.y"
    { is_for = 1; }
    break;

  case 37:
#line 247 "cparcer2.y"
    {
    sprintf(icg[ic_idx++], buff);
    sprintf(icg[ic_idx++], "JUMP to %s\n", (yyvsp[(6) - (12)].nd_obj3).if_body);
    sprintf(icg[ic_idx++], "\nLABEL %s:\n", (yyvsp[(6) - (12)].nd_obj3).else_body);
    sprintf(tcg[tc_idx++], rbuff);
    sprintf(tcg[tc_idx++], "JMP %s\n", (yyvsp[(6) - (12)].nd_obj3).if_body);
    sprintf(tcg[tc_idx++], "\n%s:\n", (yyvsp[(6) - (12)].nd_obj3).else_body);
}
    break;

  case 38:
#line 257 "cparcer2.y"
    { is_for = 1; }
    break;

  case 39:
#line 257 "cparcer2.y"
    {
    sprintf(icg[ic_idx++], "JUMP to %s\n", (yyvsp[(4) - (8)].nd_obj3).if_body);
    sprintf(icg[ic_idx++], "\nLABEL %s:\n", (yyvsp[(4) - (8)].nd_obj3).else_body);
    sprintf(tcg[tc_idx++], "JMP %s\n", (yyvsp[(4) - (8)].nd_obj3).if_body);
    sprintf(tcg[tc_idx++], "\n%s:\n", (yyvsp[(4) - (8)].nd_obj3).else_body);
}
    break;

  case 41:
#line 268 "cparcer2.y"
    {
    sprintf(icg[ic_idx++], "%s = %s\n", (yyvsp[(2) - (3)].nd_obj).name, (yyvsp[(3) - (3)].nd_obj2).name);
    (yyvsp[(2) - (3)].nd_obj).rNumber = temp_r;
    strcpy(regVars[temp_r-1].name, (yyvsp[(2) - (3)].nd_obj).name);
    regVars[temp_r-1].rNumber = temp_r;
    int t0 = search((yyvsp[(3) - (3)].nd_obj2).name);
    if(t0 != -1){
        arResults[temp_r-1] = arResults[t0-1];
    }else{
        char *ptr;
        arResults[temp_r-1] = strtod((yyvsp[(3) - (3)].nd_obj2).name, &ptr);
    }
    //sprintf(tcg[tc_idx++], "%lf\n", arResults[temp_r-1]);
    if(strcmp((yyvsp[(3) - (3)].nd_obj2).name, "NULL")){
        int t = search((yyvsp[(3) - (3)].nd_obj2).name);
        if(t != -1){
            sprintf(tcg[tc_idx++], "MOV R%d R%d\n", temp_r++, t);
        }else{
            sprintf(tcg[tc_idx++], "MOV R%d %s\n", temp_r++, (yyvsp[(3) - (3)].nd_obj2).name);
        }
    }else{
        temp_r++;
    }
}
    break;

  case 42:
#line 292 "cparcer2.y"
    { 
    sprintf(icg[ic_idx++], "%s = %s\n", (yyvsp[(1) - (3)].nd_obj).name, (yyvsp[(3) - (3)].nd_obj2).name);
    int t = search((yyvsp[(1) - (3)].nd_obj).name);
    if(t != -1){
        int t2 = search((yyvsp[(3) - (3)].nd_obj2).name);
        if(t2 != -1){
            arResults[t-1] = arResults[t2-1];
            //sprintf(tcg[tc_idx++], "%lf\n", arResults[t-1]);
            sprintf(tcg[tc_idx++], "MOV R%d R%d\n", t, t2);
        }else{
            char *ptr;
            arResults[t-1] = strtod((yyvsp[(3) - (3)].nd_obj2).name, &ptr);
            //sprintf(tcg[tc_idx++], "%lf\n", arResults[t-1]);
            sprintf(tcg[tc_idx++], "MOV R%d %s\n", t, (yyvsp[(3) - (3)].nd_obj2).name);
        }
    }
}
    break;

  case 43:
#line 309 "cparcer2.y"
    {
    if(!strcmp((yyvsp[(1) - (2)].nd_obj).name, "++")) {
        sprintf(buff, "t%d = %s + 1\n%s = t%d\n", temp_var, (yyvsp[(2) - (2)].nd_obj2).name, (yyvsp[(2) - (2)].nd_obj2).name, temp_var++);
        int t0 = search((yyvsp[(2) - (2)].nd_obj2).name);
        if(t0 != -1){
            sprintf(rbuff, "ADD R%d 1\n", t0);
            arResults[t0-1]++;
        }
    }
    else {
        sprintf(buff, "t%d = %s - 1\n%s = t%d\n", temp_var, (yyvsp[(2) - (2)].nd_obj2).name, (yyvsp[(2) - (2)].nd_obj2).name, temp_var++);
        int t0 = search((yyvsp[(2) - (2)].nd_obj2).name);
        if(t0 != -1){
            sprintf(rbuff, "SUB R%d 1\n", t0);
            arResults[t0-1]--;
        }
    }
}
    break;

  case 44:
#line 327 "cparcer2.y"
    {
    if(!strcmp((yyvsp[(2) - (2)].nd_obj).name, "++")) {
        sprintf(buff, "t%d = %s + 1\n%s = t%d\n", temp_var, (yyvsp[(1) - (2)].nd_obj2).name, (yyvsp[(1) - (2)].nd_obj2).name, temp_var++);
        int t0 = search((yyvsp[(1) - (2)].nd_obj2).name);
        if(t0 != -1){
            sprintf(rbuff, "ADD R%d 1\n", t0);
            arResults[t0-1]++;
        }
    }
    else {
        sprintf(buff, "t%d = %s - 1\n%s = t%d\n", temp_var, (yyvsp[(1) - (2)].nd_obj2).name, (yyvsp[(1) - (2)].nd_obj2).name, temp_var++);
        int t0 = search((yyvsp[(1) - (2)].nd_obj2).name);
        if(t0 != -1){
            sprintf(rbuff, "SUB R%d 1\n", t0);
            arResults[t0-1]--;
        }
    }
}
    break;

  case 48:
#line 348 "cparcer2.y"
    { sprintf(tcg[tc_idx++], "CALL %s\n", (yyvsp[(1) - (4)].nd_obj).name); }
    break;

  case 49:
#line 349 "cparcer2.y"
    { sprintf(tcg[tc_idx++], "CALL %s\n", (yyvsp[(1) - (7)].nd_obj).name); }
    break;

  case 50:
#line 352 "cparcer2.y"
    { sprintf((yyval.nd_obj2).type, (yyvsp[(2) - (2)].nd_obj2).type); strcpy((yyval.nd_obj2).name, (yyvsp[(2) - (2)].nd_obj2).name); }
    break;

  case 51:
#line 353 "cparcer2.y"
    { sprintf((yyval.nd_obj2).type, "null"); strcpy((yyval.nd_obj2).name, "NULL"); }
    break;

  case 56:
#line 362 "cparcer2.y"
    {
    sprintf((yyval.nd_obj2).name, "t%d", temp_var);
    temp_var++;
    sprintf(icg[ic_idx++], "%s = %s %s %s\n",  (yyval.nd_obj2).name, (yyvsp[(1) - (3)].nd_obj2).name, (yyvsp[(2) - (3)].nd_obj).name, (yyvsp[(3) - (3)].nd_obj2).name);
    strcpy(regVars[temp_r-1].name, (yyval.nd_obj2).name);
    regVars[temp_r-1].rNumber = temp_r;
    int t0 = search((yyvsp[(1) - (3)].nd_obj2).name);
    if(t0 != -1){
        sprintf(tcg[tc_idx++], "MOV R%d R%d\n", temp_r++, t0);
        int t = search((yyval.nd_obj2).name);
        if(t != -1){
            arResults[t-1] = arResults[t0-1];
        }
        //sprintf(tcg[tc_idx++], "%lf\n", arResults[t-1]);
    }else{
        sprintf(tcg[tc_idx++], "MOV R%d %s\n", temp_r++, (yyvsp[(1) - (3)].nd_obj2).name);
        int t = search((yyval.nd_obj2).name);
        if(t != -1){
            char *ptr;
            arResults[t-1] = strtod((yyvsp[(1) - (3)].nd_obj2).name, &ptr);
        }
        //sprintf(tcg[tc_idx++], "%lf\n", arResults[t-1]);
    }
    int t = search((yyval.nd_obj2).name);
    if(t != -1){
        int t2 = search((yyvsp[(3) - (3)].nd_obj2).name);
        if(t2 != -1){
            arResults[t-1] = arResults[t-1] + arResults[t2-1];
            //sprintf(tcg[tc_idx++], "%lf\n", arResults[t-1]);
            sprintf(tcg[tc_idx++], "ADD R%d R%d\n", t, t2);
        }else{
            char *ptr;
            arResults[t-1] = arResults[t-1] + strtod((yyvsp[(3) - (3)].nd_obj2).name, &ptr);
            //sprintf(tcg[tc_idx++], "%lf\n", arResults[t-1]);
            sprintf(tcg[tc_idx++], "ADD R%d %s\n", t, (yyvsp[(3) - (3)].nd_obj2).name);
        }
    }else{
        int t2 = search((yyvsp[(3) - (3)].nd_obj2).name);
        if(t2 != -1){
            sprintf(tcg[tc_idx++], "ADD R%d R%d\n", temp_r++, t2);
        }else{
            sprintf(tcg[tc_idx++], "ADD R%d %s\n", temp_r++, (yyvsp[(3) - (3)].nd_obj2).name);
        }
    }
}
    break;

  case 57:
#line 407 "cparcer2.y"
    {
    sprintf((yyval.nd_obj2).name, "t%d", temp_var);
    temp_var++;
    sprintf(icg[ic_idx++], "%s = %s %s %s\n",  (yyval.nd_obj2).name, (yyvsp[(1) - (3)].nd_obj2).name, (yyvsp[(2) - (3)].nd_obj).name, (yyvsp[(3) - (3)].nd_obj2).name);
    strcpy(regVars[temp_r-1].name, (yyval.nd_obj2).name);
    regVars[temp_r-1].rNumber = temp_r;
    int t0 = search((yyvsp[(1) - (3)].nd_obj2).name);
    if(t0 != -1){
        sprintf(tcg[tc_idx++], "MOV R%d R%d\n", temp_r++, t0);
        int t = search((yyval.nd_obj2).name);
        if(t != -1){
            arResults[t-1] = arResults[t0-1];
        }
        //sprintf(tcg[tc_idx++], "%lf\n", arResults[t-1]);
    }else{
        sprintf(tcg[tc_idx++], "MOV R%d %s\n", temp_r++, (yyvsp[(1) - (3)].nd_obj2).name);
        int t = search((yyval.nd_obj2).name);
        if(t != -1){
            char *ptr;
            arResults[t-1] = strtod((yyvsp[(1) - (3)].nd_obj2).name, &ptr);
        }
        //sprintf(tcg[tc_idx++], "%lf\n", arResults[t-1]);
    }
    int t = search((yyval.nd_obj2).name);
    if(t != -1){
        int t2 = search((yyvsp[(3) - (3)].nd_obj2).name);
        if(t2 != -1){
            arResults[t-1] = arResults[t-1] - arResults[t2-1];
            //sprintf(tcg[tc_idx++], "%lf\n", arResults[t-1]);
            sprintf(tcg[tc_idx++], "SUB R%d R%d\n", t, t2);
        }else{
            char *ptr;
            arResults[t-1] = arResults[t-1] - strtod((yyvsp[(3) - (3)].nd_obj2).name, &ptr);
            //sprintf(tcg[tc_idx++], "%lf\n", arResults[t-1]);
            sprintf(tcg[tc_idx++], "SUB R%d %s\n", t, (yyvsp[(3) - (3)].nd_obj2).name);
        }
    }else{
        int t2 = search((yyvsp[(3) - (3)].nd_obj2).name);
        if(t2 != -1){
            arResults[t-1] = arResults[t-1] - arResults[t2-1];
            //sprintf(tcg[tc_idx++], "%lf\n", arResults[t-1]);
            sprintf(tcg[tc_idx++], "SUB R%d R%d\n", temp_r++, t2);
        }else{
            char *ptr;
            arResults[t-1] = arResults[t-1] - strtod((yyvsp[(3) - (3)].nd_obj2).name, &ptr);
            //sprintf(tcg[tc_idx++], "%lf\n", arResults[t-1]);
            sprintf(tcg[tc_idx++], "SUB R%d %s\n", temp_r++, (yyvsp[(3) - (3)].nd_obj2).name);
        }
    }
}
    break;

  case 58:
#line 459 "cparcer2.y"
    { strcpy((yyval.nd_obj2).name, (yyvsp[(1) - (1)].nd_obj2).name); sprintf((yyval.nd_obj2).type, (yyvsp[(1) - (1)].nd_obj2).type); }
    break;

  case 60:
#line 461 "cparcer2.y"
    {
    sprintf((yyval.nd_obj2).name, "t%d", temp_var);
    temp_var++;
    sprintf(icg[ic_idx++], "%s = %s %s %s\n",  (yyval.nd_obj2).name, (yyvsp[(1) - (3)].nd_obj2).name, (yyvsp[(2) - (3)].nd_obj).name, (yyvsp[(3) - (3)].nd_obj2).name);
    strcpy(regVars[temp_r-1].name, (yyval.nd_obj2).name);
    regVars[temp_r-1].rNumber = temp_r;
    int t0 = search((yyvsp[(1) - (3)].nd_obj2).name);
    if(t0 != -1){
        sprintf(tcg[tc_idx++], "MOV R%d R%d\n", temp_r++, t0);
        int t = search((yyval.nd_obj2).name);
        if(t != -1){
            arResults[t-1] = arResults[t0-1];
        }
        //sprintf(tcg[tc_idx++], "%lf\n", arResults[t-1]);
    }else{
        sprintf(tcg[tc_idx++], "MOV R%d %s\n", temp_r++, (yyvsp[(1) - (3)].nd_obj2).name);
        int t = search((yyval.nd_obj2).name);
        if(t != -1){
            char *ptr;
            arResults[t-1] = strtod((yyvsp[(1) - (3)].nd_obj2).name, &ptr);
        }
        //sprintf(tcg[tc_idx++], "%lf\n", arResults[t-1]);
    }
    int t = search((yyval.nd_obj2).name);
    if(t != -1){
        int t2 = search((yyvsp[(3) - (3)].nd_obj2).name);
        if(t2 != -1){
            arResults[t-1] = arResults[t-1] * arResults[t2-1];
            //sprintf(tcg[tc_idx++], "%lf\n", arResults[t-1]);
            sprintf(tcg[tc_idx++], "MULT R%d R%d\n", t, t2);
        }else{
            char *ptr;
            arResults[t-1] = arResults[t-1] * strtod((yyvsp[(3) - (3)].nd_obj2).name, &ptr);
            //sprintf(tcg[tc_idx++], "%lf\n", arResults[t-1]);
            sprintf(tcg[tc_idx++], "MULT R%d %s\n", t, (yyvsp[(3) - (3)].nd_obj2).name);
        }
    }else{
        int t2 = search((yyvsp[(3) - (3)].nd_obj2).name);
        if(t2 != -1){
            sprintf(tcg[tc_idx++], "MULT R%d R%d\n", temp_r++, t2);
        }else{
            sprintf(tcg[tc_idx++], "MULT R%d %s\n", temp_r++, (yyvsp[(3) - (3)].nd_obj2).name);
        }
    }
}
    break;

  case 61:
#line 506 "cparcer2.y"
    {
    sprintf((yyval.nd_obj2).name, "t%d", temp_var);
    temp_var++;
    sprintf(icg[ic_idx++], "%s = %s %s %s\n",  (yyval.nd_obj2).name, (yyvsp[(1) - (3)].nd_obj2).name, (yyvsp[(2) - (3)].nd_obj).name, (yyvsp[(3) - (3)].nd_obj2).name);
    strcpy(regVars[temp_r-1].name, (yyval.nd_obj2).name);
    regVars[temp_r-1].rNumber = temp_r;
    int t0 = search((yyvsp[(1) - (3)].nd_obj2).name);
    if(t0 != -1){
        sprintf(tcg[tc_idx++], "MOV R%d R%d\n", temp_r++, t0);
        int t = search((yyval.nd_obj2).name);
        if(t != -1){
            arResults[t-1] = arResults[t0-1];
        }
        //sprintf(tcg[tc_idx++], "%lf\n", arResults[t-1]);
    }else{
        sprintf(tcg[tc_idx++], "MOV R%d %s\n", temp_r++, (yyvsp[(1) - (3)].nd_obj2).name);
        int t = search((yyval.nd_obj2).name);
        if(t != -1){
            char *ptr;
            arResults[t-1] = strtod((yyvsp[(1) - (3)].nd_obj2).name, &ptr);
        }
        //sprintf(tcg[tc_idx++], "%lf\n", arResults[t-1]);
    }
    int t = search((yyval.nd_obj2).name);
    if(t != -1){
        int t2 = search((yyvsp[(3) - (3)].nd_obj2).name);
        if(t2 != -1){
            arResults[t-1] = arResults[t-1] / arResults[t2-1];
            //sprintf(tcg[tc_idx++], "%lf\n", arResults[t-1]);
            sprintf(tcg[tc_idx++], "DIV R%d R%d\n", t, t2);
        }else{
            char *ptr;
            arResults[t-1] = arResults[t-1] / strtod((yyvsp[(3) - (3)].nd_obj2).name, &ptr);
            //sprintf(tcg[tc_idx++], "%lf\n", arResults[t-1]);
            sprintf(tcg[tc_idx++], "DIV R%d %s\n", t, (yyvsp[(3) - (3)].nd_obj2).name);
        }
    }else{
        int t2 = search((yyvsp[(3) - (3)].nd_obj2).name);
        if(t2 != -1){
            sprintf(tcg[tc_idx++], "DIV R%d R%d\n", temp_r++, t2);
        }else{
            sprintf(tcg[tc_idx++], "DIV R%d %s\n", temp_r++, (yyvsp[(3) - (3)].nd_obj2).name);
        }
    }
}
    break;

  case 62:
#line 551 "cparcer2.y"
    {
    sprintf((yyval.nd_obj2).name, "t%d", temp_var);
    temp_var++;
    sprintf(icg[ic_idx++], "%s = %s %s %s\n",  (yyval.nd_obj2).name, (yyvsp[(1) - (3)].nd_obj2).name, (yyvsp[(2) - (3)].nd_obj).name, (yyvsp[(3) - (3)].nd_obj2).name);
}
    break;

  case 63:
#line 556 "cparcer2.y"
    {
    if(!strcmp((yyvsp[(2) - (2)].nd_obj2).name, "++")) {
        sprintf(buff, "t%d = %s + 1\n%s = t%d\n", temp_var, (yyvsp[(2) - (2)].nd_obj2).name, (yyvsp[(2) - (2)].nd_obj2).name, temp_var++);
        int t0 = search((yyvsp[(1) - (2)].nd_obj).name);
        if(t0 != -1){
            sprintf(rbuff, "ADD R%d 1\n", t0);
            arResults[t0-1]++;
        }
    }
    else {
        sprintf(buff, "t%d = %s - 1\n%s = t%d\n", temp_var, (yyvsp[(2) - (2)].nd_obj2).name, (yyvsp[(2) - (2)].nd_obj2).name, temp_var++);
        int t0 = search((yyvsp[(2) - (2)].nd_obj2).name);
        if(t0 != -1){
            sprintf(rbuff, "SUB R%d 1\n", t0);
            arResults[t0-1]--;
        }
    }
}
    break;

  case 64:
#line 574 "cparcer2.y"
    {
    if(!strcmp((yyvsp[(2) - (2)].nd_obj).name, "++")) {
        sprintf(buff, "t%d = %s + 1\n%s = t%d\n", temp_var, (yyvsp[(1) - (2)].nd_obj2).name, (yyvsp[(1) - (2)].nd_obj2).name, temp_var++);
        int t0 = search((yyvsp[(1) - (2)].nd_obj2).name);
        if(t0 != -1){
            sprintf(rbuff, "ADD R%d 1\n", t0);
            arResults[t0-1]++;
        }
    }
    else {
        sprintf(buff, "t%d = %s - 1\n%s = t%d\n", temp_var, (yyvsp[(1) - (2)].nd_obj2).name, (yyvsp[(1) - (2)].nd_obj2).name, temp_var++);
        int t0 = search((yyvsp[(1) - (2)].nd_obj2).name);
        if(t0 != -1){
            sprintf(rbuff, "SUB R%d 1\n", t0);
            arResults[t0-1]--;
        }
    }
}
    break;

  case 65:
#line 592 "cparcer2.y"
    { strcpy((yyval.nd_obj2).name, (yyvsp[(2) - (3)].nd_obj2).name); sprintf((yyval.nd_obj2).type, (yyvsp[(2) - (3)].nd_obj2).type); }
    break;

  case 66:
#line 593 "cparcer2.y"
    {
    sprintf((yyval.nd_obj2).name, "t%d", temp_var);
    temp_var++;
    sprintf(icg[ic_idx++], "%s = %s %s %s\n",  (yyval.nd_obj2).name, (yyvsp[(2) - (5)].nd_obj2).name, (yyvsp[(3) - (5)].nd_obj).name, (yyvsp[(4) - (5)].nd_obj2).name);
    strcpy(regVars[temp_r-1].name, (yyval.nd_obj2).name);
    regVars[temp_r-1].rNumber = temp_r;
    int t0 = search((yyvsp[(2) - (5)].nd_obj2).name);
    if(t0 != -1){
        sprintf(tcg[tc_idx++], "MOV R%d R%d\n", temp_r++, t0);
        int t = search((yyval.nd_obj2).name);
        if(t != -1){
            arResults[t-1] = arResults[t0-1];
        }
        //sprintf(tcg[tc_idx++], "%lf\n", arResults[t-1]);
    }else{
        sprintf(tcg[tc_idx++], "MOV R%d %s\n", temp_r++, (yyvsp[(2) - (5)].nd_obj2).name);
        int t = search((yyval.nd_obj2).name);
        if(t != -1){
            char *ptr;
            arResults[t-1] = strtod((yyvsp[(1) - (5)].nd_obj).name, &ptr);
        }
        //sprintf(tcg[tc_idx++], "%lf\n", arResults[t-1]);
    }
    int t = search((yyval.nd_obj2).name);
    if(t != -1){
        int t2 = search((yyvsp[(4) - (5)].nd_obj2).name);
        if(t2 != -1){
            arResults[t-1] = arResults[t-1] + arResults[t2-1];
            //sprintf(tcg[tc_idx++], "%lf\n", arResults[t-1]);
            sprintf(tcg[tc_idx++], "ADD R%d R%d\n", t, t2);
        }else{
            char *ptr;
            arResults[t-1] = arResults[t-1] + strtod((yyvsp[(4) - (5)].nd_obj2).name, &ptr);
            //sprintf(tcg[tc_idx++], "%lf\n", arResults[t-1]);
            sprintf(tcg[tc_idx++], "ADD R%d %s\n", t, (yyvsp[(4) - (5)].nd_obj2).name);
        }
    }else{
        int t2 = search((yyvsp[(4) - (5)].nd_obj2).name);
        if(t2 != -1){
            sprintf(tcg[tc_idx++], "ADD R%d R%d\n", temp_r++, t2);
        }else{
            sprintf(tcg[tc_idx++], "ADD R%d %s\n", temp_r++, (yyvsp[(4) - (5)].nd_obj2).name);
        }
    }
}
    break;

  case 67:
#line 638 "cparcer2.y"
    {
    sprintf((yyval.nd_obj2).name, "t%d", temp_var);
    temp_var++;
    sprintf(icg[ic_idx++], "%s = %s %s %s\n",  (yyval.nd_obj2).name, (yyvsp[(2) - (5)].nd_obj2).name, (yyvsp[(3) - (5)].nd_obj).name, (yyvsp[(4) - (5)].nd_obj2).name);
    strcpy(regVars[temp_r-1].name, (yyval.nd_obj2).name);
    regVars[temp_r-1].rNumber = temp_r;
    int t0 = search((yyvsp[(2) - (5)].nd_obj2).name);
    if(t0 != -1){
        sprintf(tcg[tc_idx++], "MOV R%d R%d\n", temp_r++, t0);
        int t = search((yyval.nd_obj2).name);
        if(t != -1){
            arResults[t-1] = arResults[t0-1];
        }
        //sprintf(tcg[tc_idx++], "%lf\n", arResults[t-1]);
    }else{
        sprintf(tcg[tc_idx++], "MOV R%d %s\n", temp_r++, (yyvsp[(2) - (5)].nd_obj2).name);
    }
    int t = search((yyval.nd_obj2).name);
    if(t != -1){
        int t2 = search((yyvsp[(4) - (5)].nd_obj2).name);
        if(t2 != -1){
            arResults[t-1] = arResults[t-1] - arResults[t2-1];
            //sprintf(tcg[tc_idx++], "%lf\n", arResults[t-1]);
            sprintf(tcg[tc_idx++], "SUB R%d R%d\n", t, t2);
        }else{
            char *ptr;
            arResults[t-1] = arResults[t-1] - strtod((yyvsp[(4) - (5)].nd_obj2).name, &ptr);
            //sprintf(tcg[tc_idx++], "%lf\n", arResults[t-1]);
            sprintf(tcg[tc_idx++], "SUB R%d %s\n", t, (yyvsp[(4) - (5)].nd_obj2).name);
        }
    }else{
        int t2 = search((yyvsp[(4) - (5)].nd_obj2).name);
        if(t2 != -1){
            arResults[t-1] = arResults[t-1] - arResults[t2-1];
            //sprintf(tcg[tc_idx++], "%lf\n", arResults[t-1]);
            sprintf(tcg[tc_idx++], "SUB R%d R%d\n", temp_r++, t2);
        }else{
            char *ptr;
            arResults[t-1] = arResults[t-1] - strtod((yyvsp[(3) - (5)].nd_obj).name, &ptr);
            //sprintf(tcg[tc_idx++], "%lf\n", arResults[t-1]);
            sprintf(tcg[tc_idx++], "SUB R%d %s\n", temp_r++, (yyvsp[(4) - (5)].nd_obj2).name);
        }
    }
}
    break;


/* Line 1267 of yacc.c.  */
#line 2488 "y.tab.c"
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


#line 732 "cparcer2.y"


int main() {
    yyparse();
    /*
     printf("\n\n");
     for(int i=0; i<ic_idx; i++){
        printf("%s", icg[i]);
    }
    */
    printf("\n\n");
    for(int i=0; i<tc_idx; i++){
        printf("%s", tcg[i]);
    }
    printf("\n\n");
}

void yyerror(const char* msg) {
    fprintf(stderr, "%s\n", msg);
}

int search(char *name) {
    int i;
    for(i=0; i<temp_r-1; i++) {
        if(strcmp(regVars[i].name, name)==0) {
            return i+1;
            break;
        }
    }
    return -1;
}

