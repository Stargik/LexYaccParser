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
/* Line 1529 of yacc.c.  */
#line 270 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

