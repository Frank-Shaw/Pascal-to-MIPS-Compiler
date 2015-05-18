
/*  A Bison parser, made from parser.y
    by GNU Bison version 1.28  */

#define YYBISON 1  /* Identify Bison output.  */

#define	PROGRAM	257
#define	_BEGIN	258
#define	_END	259
#define	VAR	260
#define	INTEGER	261
#define	REAL	262
#define	CHAR	263
#define	STRING	264
#define	CONST	265
#define	SYS_CON	266
#define	SYS_TYPE	267
#define	TYPE	268
#define	ARRAY	269
#define	OF	270
#define	RECORD	271
#define	FUNCTION	272
#define	PROCEDURE	273
#define	READ	274
#define	WRITELN	275
#define	SYS_PROC	276
#define	IF	277
#define	THEN	278
#define	ELSE	279
#define	REPEAT	280
#define	UNTIL	281
#define	WHILE	282
#define	DO	283
#define	FOR	284
#define	TO	285
#define	DOWNTO	286
#define	GOTO	287
#define	CASE	288
#define	_AND	289
#define	_OR	290
#define	_NOT	291
#define	LP	292
#define	RP	293
#define	LB	294
#define	RB	295
#define	DOT	296
#define	COMMA	297
#define	COLON	298
#define	SEMI	299
#define	ASSIGN	300
#define	UNEQUAL	301
#define	EQUAL	302
#define	_MUL	303
#define	_DIV	304
#define	_MOD	305
#define	_PLUS	306
#define	_MINUS	307
#define	_GE	308
#define	_GT	309
#define	_LE	310
#define	_LT	311
#define	_ID	312
#define	ERROR	313
#define	SYS_FUNCT	314

#line 1 "parser.y"

#define YYPARSER
#include "global.h"
#include "util.h"
#include "scan.h"
#define YYSTYPE TreeNode *
static int savedVal;
static TreeNode * savedTree;
extern int TraceParser;
int yyerror(char * message);
int err=0;
#ifndef YYSTYPE
#define YYSTYPE int
#endif
#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		312
#define	YYFLAG		-32768
#define	YYNTBASE	61

#define YYTRANSLATE(x) ((unsigned)(x) <= 314 ? yytranslate[x] : 117)

static const char yytranslate[] = {     0,
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
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     3,     4,     5,     6,
     7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
    17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
    27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
    37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
    47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
    57,    58,    59,    60
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     4,     8,    11,    14,    20,    21,    24,    25,    31,
    36,    38,    40,    42,    44,    47,    48,    51,    53,    58,
    60,    62,    64,    71,    78,    85,    89,    92,    94,    99,
   103,   105,   107,   109,   113,   117,   121,   126,   132,   139,
   144,   147,   148,   151,   153,   158,   161,   164,   166,   168,
   169,   174,   180,   185,   189,   193,   197,   201,   202,   206,
   208,   212,   215,   217,   219,   223,   226,   227,   228,   233,
   235,   237,   239,   241,   243,   245,   247,   249,   251,   253,
   255,   259,   266,   273,   280,   286,   288,   293,   298,   303,
   305,   310,   315,   320,   325,   330,   335,   340,   344,   350,
   353,   354,   359,   364,   373,   375,   377,   383,   386,   388,
   393,   398,   401,   405,   407,   411,   415,   419,   423,   427,
   431,   433,   437,   441,   445,   447,   451,   455,   459,   463,
   465,   467,   472,   477,   482,   484,   489,   491,   495,   498,
   501,   506,   511,   516,   520,   524,   526,   528
};

static const short yyrhs[] = {    62,
    63,    42,     0,     3,   116,    45,     0,    65,    92,     0,
    65,    92,     0,    66,    67,    70,    80,    83,     0,     0,
    11,    68,     0,     0,    68,   116,    48,    69,    45,     0,
   116,    48,    69,    45,     0,     7,     0,     8,     0,     9,
     0,    10,     0,    14,    71,     0,     0,    71,    72,     0,
    72,     0,   116,    48,    73,    45,     0,    79,     0,    74,
     0,    75,     0,    15,    40,    79,    41,    16,    73,     0,
    15,    40,    79,     1,    16,    73,     0,    15,     1,    79,
    41,    16,    73,     0,    17,    76,     5,     0,    76,    77,
     0,    77,     0,    78,    44,    73,    45,     0,    78,    43,
   116,     0,   116,     0,    13,     0,   116,     0,    38,    78,
    39,     0,    38,    78,     1,     0,     1,    78,    39,     0,
    69,    42,    42,    69,     0,    53,    69,    42,    42,    69,
     0,    53,    69,    42,    42,    53,    69,     0,   116,    42,
    42,   116,     0,     6,    81,     0,     0,    81,    82,     0,
    82,     0,    78,    44,    73,    45,     0,    83,    84,     0,
    83,    86,     0,    84,     0,    86,     0,     0,    85,    45,
    64,    45,     0,    18,   116,    88,    44,    79,     0,    87,
    45,    64,    45,     0,    19,   116,    88,     0,    38,    89,
    39,     0,    38,    89,     1,     0,     1,    89,    39,     0,
     0,    89,    45,    90,     0,    90,     0,    91,    44,    79,
     0,     6,    78,     0,    78,     0,    99,     0,    93,    94,
    45,     0,    94,    45,     0,     0,     0,     7,    95,    44,
    96,     0,    96,     0,    97,     0,    98,     0,    99,     0,
   100,     0,   102,     0,   103,     0,   104,     0,   106,     0,
   109,     0,     1,     0,   116,    46,   111,     0,   116,    40,
   111,    41,    46,   111,     0,   116,    40,   111,     1,    46,
   111,     0,   116,     1,   111,    41,    46,   111,     0,   116,
    42,   116,    46,   111,     0,   116,     0,   116,    38,   115,
    39,     0,   116,    38,   115,     1,     0,   116,     1,   115,
    39,     0,    22,     0,    22,    38,   110,    39,     0,    21,
    38,   114,    39,     0,    21,    38,   114,     1,     0,    21,
     1,   114,    39,     0,    20,    38,   114,    39,     0,    20,
    38,   114,     1,     0,    20,     1,   114,    39,     0,     4,
    93,     5,     0,    23,   111,    24,    94,   101,     0,    25,
    94,     0,     0,    26,    93,    27,   111,     0,    28,   111,
    29,    94,     0,    30,   116,    46,   111,   105,   111,    29,
    94,     0,    31,     0,    32,     0,    34,   111,    16,   107,
     5,     0,   107,   108,     0,   108,     0,    69,    44,    94,
    45,     0,   116,    44,    94,    45,     0,    33,     7,     0,
   110,    43,   111,     0,   111,     0,   111,    54,   112,     0,
   111,    55,   112,     0,   111,    56,   112,     0,   111,    57,
   112,     0,   111,    48,   112,     0,   111,    47,   112,     0,
   112,     0,   112,    52,   113,     0,   112,    53,   113,     0,
   112,    36,   113,     0,   113,     0,   113,    49,   114,     0,
   113,    50,   114,     0,   113,    51,   114,     0,   113,    35,
   114,     0,   114,     0,   116,     0,   116,    38,   115,    39,
     0,   116,    38,   115,     1,     0,   116,     1,   115,    39,
     0,    60,     0,    60,    38,   115,    39,     0,    69,     0,
    38,   111,    39,     0,    37,   114,     0,    53,   114,     0,
   116,    40,   111,    41,     0,   116,    40,   111,     1,     0,
   116,     1,   111,    41,     0,   116,    42,   116,     0,   115,
    43,   111,     0,   111,     0,    58,     0,    59,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    24,    32,    35,    44,    53,    64,    66,    72,    74,    84,
    93,   100,   107,   114,   122,   128,   135,   142,   149,   158,
   164,   170,   177,   186,   196,   207,   216,   223,   230,   240,
   247,   254,   261,   269,   277,   286,   295,   304,   313,   322,
   332,   338,   344,   351,   358,   368,   375,   382,   387,   392,
   398,   408,   418,   428,   437,   443,   450,   457,   463,   470,
   477,   486,   491,   498,   504,   511,   516,   518,   518,   525,
   531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
   543,   551,   560,   570,   580,   590,   597,   605,   614,   623,
   630,   638,   646,   655,   664,   672,   681,   691,   694,   704,
   710,   713,   722,   731,   744,   751,   759,   793,   800,   803,
   811,   820,   828,   835,   838,   847,   856,   865,   874,   883,
   892,   898,   907,   916,   925,   931,   940,   949,   958,   967,
   970,   976,   984,   993,  1002,  1003,  1004,  1009,  1011,  1019,
  1027,  1035,  1044,  1053,  1062,  1069,  1075,  1081
};
#endif


#if YYDEBUG != 0 || defined (YYERROR_VERBOSE)

static const char * const yytname[] = {   "$","error","$undefined.","PROGRAM",
"_BEGIN","_END","VAR","INTEGER","REAL","CHAR","STRING","CONST","SYS_CON","SYS_TYPE",
"TYPE","ARRAY","OF","RECORD","FUNCTION","PROCEDURE","READ","WRITELN","SYS_PROC",
"IF","THEN","ELSE","REPEAT","UNTIL","WHILE","DO","FOR","TO","DOWNTO","GOTO",
"CASE","_AND","_OR","_NOT","LP","RP","LB","RB","DOT","COMMA","COLON","SEMI",
"ASSIGN","UNEQUAL","EQUAL","_MUL","_DIV","_MOD","_PLUS","_MINUS","_GE","_GT",
"_LE","_LT","_ID","ERROR","SYS_FUNCT","program","program_head","routine","sub_routine",
"routine_head","label_part","const_part","const_expr_list","const_value","type_part",
"type_decl_list","type_definition","type_decl","array_type_decl","record_type_decl",
"field_decl_list","field_decl","name_list","simple_type_decl","var_part","var_decl_list",
"var_decl","routine_part","function_decl","function_head","procedure_decl","procedure_head",
"parameters","para_decl_list","para_type_list","var_para_list","routine_body",
"stmt_list","stmt","@1","non_label_stmt","assign_stmt","proc_stmt","compound_stmt",
"if_stmt","else_clause","repeat_stmt","while_stmt","for_stmt","direction","case_stmt",
"case_expr_list","case_expr","goto_stmt","expression_list","expression","expr",
"term","factor","args_list","ID", NULL
};
#endif

static const short yyr1[] = {     0,
    61,    62,    63,    64,    65,    66,    67,    67,    68,    68,
    69,    69,    69,    69,    70,    70,    71,    71,    72,    73,
    73,    73,    74,    74,    74,    75,    76,    76,    77,    78,
    78,    79,    79,    79,    79,    79,    79,    79,    79,    79,
    80,    80,    81,    81,    82,    83,    83,    83,    83,    83,
    84,    85,    86,    87,    88,    88,    88,    88,    89,    89,
    90,    91,    91,    92,    93,    93,    93,    95,    94,    94,
    96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
    97,    97,    97,    97,    97,    98,    98,    98,    98,    98,
    98,    98,    98,    98,    98,    98,    98,    99,   100,   101,
   101,   102,   103,   104,   105,   105,   106,   107,   107,   108,
   108,   109,   110,   110,   111,   111,   111,   111,   111,   111,
   111,   112,   112,   112,   112,   113,   113,   113,   113,   113,
   114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
   114,   114,   114,   114,   115,   115,   116,   116
};

static const short yyr2[] = {     0,
     3,     3,     2,     2,     5,     0,     2,     0,     5,     4,
     1,     1,     1,     1,     2,     0,     2,     1,     4,     1,
     1,     1,     6,     6,     6,     3,     2,     1,     4,     3,
     1,     1,     1,     3,     3,     3,     4,     5,     6,     4,
     2,     0,     2,     1,     4,     2,     2,     1,     1,     0,
     4,     5,     4,     3,     3,     3,     3,     0,     3,     1,
     3,     2,     1,     1,     3,     2,     0,     0,     4,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     3,     6,     6,     6,     5,     1,     4,     4,     4,     1,
     4,     4,     4,     4,     4,     4,     4,     3,     5,     2,
     0,     4,     4,     8,     1,     1,     5,     2,     1,     4,
     4,     2,     3,     1,     3,     3,     3,     3,     3,     3,
     1,     3,     3,     3,     1,     3,     3,     3,     3,     1,
     1,     4,     4,     4,     1,     4,     1,     3,     2,     2,
     4,     4,     4,     3,     3,     1,     1,     1
};

static const short yydefact[] = {     0,
     0,     6,   147,   148,     0,     0,     0,     8,     2,     1,
     0,     3,    64,     0,    16,    80,    68,     0,     0,    90,
     0,     0,     0,     0,     0,     0,     0,     0,    70,    71,
    72,    73,    74,    75,    76,    77,    78,    79,     0,     7,
     0,     0,    42,     0,     0,     0,     0,     0,     0,    11,
    12,    13,    14,     0,     0,     0,   135,   137,     0,   121,
   125,   130,     0,     0,     0,     0,   112,     0,    98,     0,
    66,     0,     0,     0,     0,     0,     0,     0,    15,    18,
     0,     0,    50,     0,     0,     0,     0,     0,     0,   114,
   139,     0,   140,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,    65,   146,     0,   146,
     0,     0,     0,    81,     0,     0,    17,     0,     0,    41,
    44,    31,     0,     0,     5,    48,     0,    49,     0,    69,
    97,    96,    95,    94,    93,    92,    91,     0,   138,     0,
   101,   120,   119,   115,   116,   117,   118,   124,   122,   123,
   129,   126,   127,   128,   146,     0,     0,     0,   144,   102,
   103,     0,     0,     0,   109,     0,     0,    89,     0,    88,
    87,     0,     0,     0,     0,    10,     0,    32,     0,     0,
     0,     0,     0,     0,    21,    22,    20,    33,     0,     0,
    43,     0,     0,    46,    47,     6,     6,   113,   136,     0,
    99,   143,   134,   133,   132,   142,   141,   105,   106,     0,
     0,   107,   108,     0,     0,   145,     0,     0,    85,     9,
     0,     0,     0,     0,    28,     0,     0,     0,     0,    19,
     0,    30,     0,     0,     0,     0,    54,     0,     0,     0,
   100,     0,     0,     0,    84,    83,    82,    36,     0,     0,
    26,    27,     0,    35,    34,     0,     0,     0,    45,     0,
    63,     0,    60,     0,     0,     0,    51,     4,    53,     0,
   110,   111,     0,     0,     0,     0,     0,    37,    40,    62,
    57,     0,     0,    56,    55,    52,   104,     0,     0,     0,
    29,     0,    38,    59,    61,    25,    24,    23,    39,     0,
     0,     0
};

static const short yydefgoto[] = {   310,
     2,     6,   248,   249,     8,    15,    40,    58,    43,    79,
    80,   194,   195,   196,   234,   235,   271,   197,    83,   130,
   131,   135,   136,   137,   138,   139,   246,   272,   273,   274,
    12,    27,    28,    44,    29,    30,    31,    32,    33,   211,
    34,    35,    36,   220,    37,   174,   175,    38,    89,   120,
    60,    61,    62,   119,    63
};

static const short yypact[] = {     8,
    78,-32768,-32768,-32768,   -31,   -26,    31,    14,-32768,-32768,
   119,-32768,-32768,    78,    26,-32768,-32768,    47,    59,     9,
   335,   299,   335,    78,    54,   335,   348,    13,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,   129,    78,
    43,    78,   113,    57,   335,   335,   335,   335,   335,-32768,
-32768,-32768,-32768,   335,   335,   335,    87,-32768,   182,   130,
   223,-32768,   494,   382,   444,    82,-32768,   344,-32768,   123,
-32768,   335,   335,   335,    78,   335,   122,   286,    78,-32768,
   153,    78,   138,   431,   148,    11,   161,    45,   105,   506,
-32768,   374,-32768,   335,   416,   335,   335,   335,   335,   335,
   335,   335,   335,   335,   335,   335,   335,   335,   335,   335,
   335,    78,   335,   416,   335,    63,-32768,   283,   107,   506,
    36,    51,   157,   506,   286,   159,-32768,   469,   149,    78,
-32768,-32768,    78,    78,   138,-32768,   162,-32768,   163,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,   335,-32768,   112,
   185,   130,   130,   130,   130,   130,   130,   223,   223,   223,
-32768,-32768,-32768,-32768,   511,   120,    92,   171,-32768,   506,
-32768,   209,   170,    10,-32768,   177,   176,-32768,   335,-32768,
-32768,   178,   188,   335,   190,-32768,    78,-32768,    42,    78,
    78,   286,   200,   201,-32768,-32768,-32768,   207,    78,   469,
-32768,    21,     6,-32768,-32768,-32768,-32768,   506,-32768,   416,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,   335,
   416,-32768,-32768,   416,   335,   506,   335,   335,   506,-32768,
   142,   303,   303,    -3,-32768,   152,    95,   211,   213,-32768,
   217,-32768,   225,    -5,    -5,   224,-32768,   231,    31,   233,
-32768,   458,   235,   236,   506,   506,   506,-32768,   244,    23,
-32768,-32768,   469,-32768,-32768,   259,   286,    78,-32768,    78,
   262,    71,-32768,   258,    41,   303,-32768,-32768,-32768,   416,
-32768,-32768,   291,   292,   293,   269,    24,-32768,-32768,   262,
-32768,    -5,   303,-32768,-32768,-32768,-32768,   469,   469,   469,
-32768,   286,-32768,-32768,-32768,-32768,-32768,-32768,-32768,   315,
   317,-32768
};

static const short yypgoto[] = {-32768,
-32768,-32768,   121,   332,-32768,-32768,-32768,   -16,-32768,-32768,
   256,  -196,-32768,-32768,-32768,   102,   -73,  -227,-32768,-32768,
   216,-32768,   212,-32768,   215,-32768,   145,   106,    62,-32768,
   114,   343,   -19,-32768,   295,-32768,-32768,    -4,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,   203,-32768,-32768,   139,
   473,   186,   -18,    70,    -1
};


#define	YYLAST		574


static const short yytable[] = {     5,
   270,   261,    13,   243,   259,   260,   244,    70,   129,    39,
     1,   142,    41,     9,   222,    10,    50,    51,    52,    53,
    39,   244,    66,   284,    14,    39,    85,    86,    87,    88,
    50,    51,    52,    53,    11,    91,   180,    93,    77,    42,
    81,   294,   232,   245,    70,   145,    49,    45,   296,   143,
   -58,   182,     3,     4,     3,     4,   129,    71,   245,    47,
    67,   126,    39,   285,   -58,   305,   286,     3,     4,    50,
    51,    52,    53,   123,   181,   151,   302,    81,   179,   295,
   132,   233,    39,   146,    46,   292,   161,   162,   163,   164,
    78,   183,   214,    39,   171,   264,    48,    96,    97,   173,
    84,   306,   307,   308,    98,    99,   100,   101,   185,   291,
   169,   193,    39,   231,   176,   292,   236,   237,    82,    16,
     3,     4,    11,   -67,    94,    17,   198,   115,   132,    72,
   215,   202,   203,   265,   179,     3,     4,   199,    18,    19,
    20,    21,   121,   147,    22,   178,    23,   148,    24,   179,
   209,    25,    26,   -86,   179,   133,   134,   173,   213,    59,
   236,    65,   179,   150,    68,   102,    73,   117,    74,   125,
    75,   216,   176,   -86,    76,   238,     3,     4,   166,   167,
   258,   103,   104,   193,   199,   132,   141,    90,   132,   132,
   251,   199,   200,    92,   199,   263,   290,   242,   198,   144,
   128,   253,   184,   186,   254,    95,   206,   207,    39,   210,
   118,   217,   122,   221,   124,   193,   193,    96,    97,    39,
   224,   225,    39,   227,    98,    99,   100,   101,    96,    97,
   198,   198,   132,   228,   230,    98,    99,   100,   101,   218,
   219,   239,   132,   132,    13,   240,   193,   165,   241,   168,
   288,   170,   266,   172,   267,    96,    97,   105,   268,   193,
   297,   198,    98,    99,   100,   101,   289,   276,   132,   269,
   303,   106,   107,   108,   198,   277,   193,   279,    39,   281,
   282,   193,   193,   193,   283,   309,   208,   158,   159,   160,
   132,   198,    50,    51,    52,    53,   198,   198,   198,    16,
   287,   293,    11,   187,   199,    17,   298,   299,   300,    50,
    51,    52,    53,   301,   311,   188,   312,   226,    18,    19,
    20,    21,   229,   177,    22,   -67,    23,   250,    24,    96,
    97,    25,    26,     7,   127,   262,    98,    99,   100,   101,
   191,    50,    51,    52,    53,   201,   204,   247,    16,   205,
   275,    11,    69,   304,    17,   192,     3,     4,   252,   116,
     3,     4,   278,   255,    64,   256,   257,    18,    19,    20,
    21,    54,    55,    22,     0,    23,   223,    24,   140,     0,
    25,    26,    16,     0,     0,    11,     0,    56,    17,     0,
    96,    97,     3,     4,    57,     0,     0,    98,    99,   100,
   101,    18,    19,    20,    21,     3,     4,    22,   113,    23,
     0,    24,   149,     0,    25,    26,    16,     0,     0,    11,
    96,    97,    17,     0,     0,     0,     0,    98,    99,   100,
   101,    16,     0,     0,    11,    18,    19,    20,    21,     3,
     4,    22,     0,    23,     0,    24,     0,     0,    25,    26,
    18,    19,    20,    21,     0,     0,    22,     0,    23,     0,
    24,     0,     0,    25,    26,     0,     0,     0,     0,   187,
     0,     0,   114,     3,     4,    50,    51,    52,    53,     0,
     0,   188,     0,   189,     0,   190,   280,     0,     3,     4,
    96,    97,     0,     0,   109,     0,     0,    98,    99,   100,
   101,     0,     0,     0,    96,    97,   191,     0,     0,  -131,
     0,    98,    99,   100,   101,     0,     0,  -131,  -131,     0,
     0,   192,  -131,     0,  -131,  -131,     3,     4,  -131,  -131,
     0,   110,  -131,   111,  -131,   112,  -131,     0,  -131,     0,
  -131,  -131,  -131,  -131,  -131,  -131,  -131,  -131,  -131,  -131,
  -131,   212,    96,    97,     0,     0,     0,    96,    97,    98,
    99,   100,   101,     0,    98,    99,   100,   101,   152,   153,
   154,   155,   156,   157
};

static const short yycheck[] = {     1,
     6,     5,     7,   200,   232,   233,     1,    27,    82,    11,
     3,     1,    14,    45,     5,    42,     7,     8,     9,    10,
    22,     1,    24,     1,    11,    27,    45,    46,    47,    48,
     7,     8,     9,    10,     4,    54,     1,    56,    40,    14,
    42,     1,     1,    38,    64,     1,    38,     1,   276,    39,
    45,     1,    58,    59,    58,    59,   130,    45,    38,     1,
     7,    78,    64,    41,    44,   293,   263,    58,    59,     7,
     8,     9,    10,    75,    39,    95,    53,    79,    43,    39,
    82,    40,    84,    39,    38,    45,   105,   106,   107,   108,
    48,    41,     1,    95,   114,     1,    38,    47,    48,   116,
    44,   298,   299,   300,    54,    55,    56,    57,   125,    39,
   112,   128,   114,   187,   116,    45,   190,   191,     6,     1,
    58,    59,     4,     5,    38,     7,   128,    46,   130,     1,
    39,   133,   134,    39,    43,    58,    59,    43,    20,    21,
    22,    23,    73,    39,    26,    39,    28,    43,    30,    43,
    39,    33,    34,    25,    43,    18,    19,   174,    39,    21,
   234,    23,    43,    94,    26,    36,    38,    45,    40,    48,
    42,     1,   174,    45,    46,   192,    58,    59,   109,   110,
    39,    52,    53,   200,    43,   187,    39,    49,   190,   191,
   210,    43,    44,    55,    43,    44,   270,   199,   200,    39,
    48,   221,    46,    45,   224,    24,    45,    45,   210,    25,
    72,    41,    74,    44,    76,   232,   233,    47,    48,   221,
    44,    46,   224,    46,    54,    55,    56,    57,    47,    48,
   232,   233,   234,    46,    45,    54,    55,    56,    57,    31,
    32,    42,   244,   245,   249,    45,   263,   109,    42,   111,
   267,   113,    42,   115,    42,    47,    48,    35,    42,   276,
   280,   263,    54,    55,    56,    57,   268,    44,   270,    45,
   287,    49,    50,    51,   276,    45,   293,    45,   280,    45,
    45,   298,   299,   300,    41,   302,   148,   102,   103,   104,
   292,   293,     7,     8,     9,    10,   298,   299,   300,     1,
    42,    44,     4,     1,    43,     7,    16,    16,    16,     7,
     8,     9,    10,    45,     0,    13,     0,   179,    20,    21,
    22,    23,   184,    41,    26,    27,    28,   207,    30,    47,
    48,    33,    34,     2,    79,   234,    54,    55,    56,    57,
    38,     7,     8,     9,    10,   130,   135,   203,     1,   135,
   245,     4,     5,   292,     7,    53,    58,    59,   220,    16,
    58,    59,   249,   225,    22,   227,   228,    20,    21,    22,
    23,    37,    38,    26,    -1,    28,   174,    30,    84,    -1,
    33,    34,     1,    -1,    -1,     4,    -1,    53,     7,    -1,
    47,    48,    58,    59,    60,    -1,    -1,    54,    55,    56,
    57,    20,    21,    22,    23,    58,    59,    26,    27,    28,
    -1,    30,    39,    -1,    33,    34,     1,    -1,    -1,     4,
    47,    48,     7,    -1,    -1,    -1,    -1,    54,    55,    56,
    57,     1,    -1,    -1,     4,    20,    21,    22,    23,    58,
    59,    26,    -1,    28,    -1,    30,    -1,    -1,    33,    34,
    20,    21,    22,    23,    -1,    -1,    26,    -1,    28,    -1,
    30,    -1,    -1,    33,    34,    -1,    -1,    -1,    -1,     1,
    -1,    -1,    29,    58,    59,     7,     8,     9,    10,    -1,
    -1,    13,    -1,    15,    -1,    17,    29,    -1,    58,    59,
    47,    48,    -1,    -1,     1,    -1,    -1,    54,    55,    56,
    57,    -1,    -1,    -1,    47,    48,    38,    -1,    -1,    16,
    -1,    54,    55,    56,    57,    -1,    -1,    24,    25,    -1,
    -1,    53,    29,    -1,    31,    32,    58,    59,    35,    36,
    -1,    38,    39,    40,    41,    42,    43,    -1,    45,    -1,
    47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
    57,    41,    47,    48,    -1,    -1,    -1,    47,    48,    54,
    55,    56,    57,    -1,    54,    55,    56,    57,    96,    97,
    98,    99,   100,   101
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "bison.simple"

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Bob Corbett and Richard Stallman

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 1, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */


#ifndef malloc
#ifdef __GNUC__
#define malloc __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc)
#include <malloc.h>
#else /* not sparc */
#if (defined (MSDOS) || defined(WIN32)) && !defined (__TURBOC__)
#include <malloc.h>
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
#include <malloc.h>
 #pragma malloc
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc.  */
#endif /* not GNU C.  */
#endif /* malloc not defined.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	return(0)
#define YYABORT 	return(1)
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#define YYLEX		yylex(&yylval, &yylloc)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_bcopy(FROM,TO,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_bcopy (from, to, count)
     char *from;
     char *to;
     int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_bcopy (char *from, char *to, int count)
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif


#line 169 "bison.simple"
int
yyparse()
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
#ifdef YYLSP_NEEDED
		 &yyls1, size * sizeof (*yylsp),
#endif
		 &yystacksize);

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
      yyss = (short *) malloc (yystacksize * sizeof (*yyssp));
      __yy_bcopy ((char *)yyss1, (char *)yyss, size * sizeof (*yyssp));
      yyvs = (YYSTYPE *) malloc (yystacksize * sizeof (*yyvsp));
      __yy_bcopy ((char *)yyvs1, (char *)yyvs, size * sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) malloc (yystacksize * sizeof (*yylsp));
      __yy_bcopy ((char *)yyls1, (char *)yyls, size * sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 1:
#line 25 "parser.y"
{
	 	if(TraceParser)
			printf("%d:  program\n",lineno);
		yyval=yyvsp[-1];
		savedTree=yyval;
	;
    break;}
case 2:
#line 33 "parser.y"
{;
    break;}
case 3:
#line 36 "parser.y"
{
		if(TraceParser)
			printf("%d:  routine\n",lineno);
		yyval=newStmtNode(RoutineK);
		yyval->child[0]=yyvsp[-1];
		yyval->child[1]=yyvsp[0];
	;
    break;}
case 4:
#line 45 "parser.y"
{
		if(TraceParser)
			printf("%d: sub routine\n",lineno);		
		yyval=newStmtNode(RoutineK);
		yyval->child[0]=yyvsp[-1];
		yyval->child[1]=yyvsp[0];
	;
    break;}
case 5:
#line 54 "parser.y"
{
		if(TraceParser)
			printf("%d: routine head\n",lineno);
		yyval=newStmtNode(RHeadK);
		yyval->child[0]=yyvsp[-3];
		yyval->child[1]=yyvsp[-2];
		yyval->child[2]=yyvsp[-1];
		yyval->child[3]=yyvsp[0];
	;
    break;}
case 6:
#line 64 "parser.y"
{;
    break;}
case 7:
#line 67 "parser.y"
{
		if(TraceParser)
			printf("%d: const part\n",lineno);
		yyval=yyvsp[0];
	;
    break;}
case 8:
#line 72 "parser.y"
{yyval=NULL;;
    break;}
case 9:
#line 75 "parser.y"
{
		if(TraceParser)
			printf("%d: const list 1\n",lineno);
		yyval=newExpNode(ConstExpK);
		yyval->child[0] = yyvsp[-3];
		yyval->child[1] = yyvsp[-1];
		nodeInsert(yyvsp[-4],yyval);
		yyval=yyvsp[-4];
	;
    break;}
case 10:
#line 85 "parser.y"
{
		if(TraceParser)
			printf("%d: const list 2\n",lineno);
		yyval=newExpNode(ConstExpK);
		yyval->child[0] = yyvsp[-3];
		yyval->child[1] = yyvsp[-1];
	;
    break;}
case 11:
#line 94 "parser.y"
{ 
		if(TraceParser)
			printf("%d: const int\n",lineno);
		yyval=newExpNode(ConstIK); 
		yyval->attr.ival=atoi(tokenString);
	;
    break;}
case 12:
#line 101 "parser.y"
{ 
		if(TraceParser)
			printf("%d: const real\n",lineno);
		yyval=newExpNode(ConstRK); 
		yyval->attr.fval=atof(tokenString);
	;
    break;}
case 13:
#line 108 "parser.y"
{ 
		if(TraceParser)
			printf("%d: const char\n",lineno);
		yyval=newExpNode(ConstCK); 
		yyval->attr.cval=tokenString[0];
	;
    break;}
case 14:
#line 115 "parser.y"
{
		if(TraceParser)
			printf("%d: const string\n",lineno);
		yyval=newExpNode(ConstSK); 
		yyval->attr.sval=copyString(tokenString);
	;
    break;}
case 15:
#line 123 "parser.y"
{
		if(TraceParser)
			printf("%d: type_part 1\n",lineno);
		yyval=yyvsp[0];
	;
    break;}
case 16:
#line 129 "parser.y"
{
		if(TraceParser)
			printf("%d: type_part 2\n",lineno);
		yyval=NULL;
	;
    break;}
case 17:
#line 136 "parser.y"
{
		if(TraceParser)
			printf("%d: type list1\n",lineno);
		yyval=yyvsp[-1]; 
		nodeInsert(yyvsp[-1],yyvsp[0]);
	;
    break;}
case 18:
#line 143 "parser.y"
{
		if(TraceParser)
			printf("%d: type list 2\n",lineno);
		yyval = yyvsp[0];
	;
    break;}
case 19:
#line 150 "parser.y"
{
		if(TraceParser)
			printf("%d: type def\n",lineno);
		yyval=newStmtNode(TypeDefK); 
		yyval->child[0]=yyvsp[-3];
		yyval->child[1]=yyvsp[-1];
	;
    break;}
case 20:
#line 159 "parser.y"
{
		if(TraceParser)
			printf("%d: type decl simple \n",lineno);
		yyval = yyvsp[0];
	;
    break;}
case 21:
#line 165 "parser.y"
{
		if(TraceParser)
			printf("%d: type decl array\n",lineno);
		yyval = yyvsp[0];
	;
    break;}
case 22:
#line 171 "parser.y"
{
		if(TraceParser)
			printf("%d: type decl record \n",lineno);
		yyval = yyvsp[0];
	;
    break;}
case 23:
#line 178 "parser.y"
{
		if(TraceParser)
			printf("%d: type array\n",lineno);
		yyval = newStmtNode(TypeK);
		yyval->attr.name = "ArrayType";	
		yyval->child[0]=yyvsp[-3];
		yyval->child[1]=yyvsp[0];
	;
    break;}
case 24:
#line 187 "parser.y"
{
		if(TraceParser)
			printf("%d: type array\n",lineno);
		yyerror("missing ']' ");
		yyval = newStmtNode(TypeK);
		yyval->attr.name = "ArrayType";	
		yyval->child[0]=yyvsp[-3];
		yyval->child[1]=yyvsp[0];
	;
    break;}
case 25:
#line 197 "parser.y"
{
		if(TraceParser)
			printf("%d: type array\n",lineno);
		yyerror("missing '[' ");
		yyval = newStmtNode(TypeK);
		yyval->attr.name = "ArrayType";	
		yyval->child[0]=yyvsp[-3];
		yyval->child[1]=yyvsp[0];
	;
    break;}
case 26:
#line 208 "parser.y"
{
		if(TraceParser)
			printf("%d: type record\n",lineno);
		yyval = newStmtNode(TypeK);
		yyval->attr.name = "RecordType";	
		yyval->child[0]=yyvsp[-1];
	;
    break;}
case 27:
#line 217 "parser.y"
{	
		if(TraceParser)
			printf("%d: field list1\n",lineno);
		yyval=yyvsp[-1]; 
		nodeInsert(yyvsp[-1],yyvsp[0]);
	;
    break;}
case 28:
#line 224 "parser.y"
{
		if(TraceParser)
			printf("%d: field list2\n",lineno);
		yyval=yyvsp[0];
	;
    break;}
case 29:
#line 231 "parser.y"
{
		if(TraceParser)
			printf("%d: field decl\n",lineno);
		yyval=newStmtNode(DeclK);
		yyval->attr.name="FieldDecl";
		yyval->child[0] = yyvsp[-3];
		yyval->child[1] = yyvsp[-1];
	;
    break;}
case 30:
#line 241 "parser.y"
{
		if(TraceParser)
			printf("%d: name list 1\n",lineno);
		yyval=yyvsp[-2]; 
		nodeInsert(yyvsp[-2],yyvsp[0]);
	;
    break;}
case 31:
#line 248 "parser.y"
{
		if(TraceParser)
			printf("%d: name list 2\n",lineno);
		yyval = yyvsp[0];
	;
    break;}
case 32:
#line 255 "parser.y"
{
		if(TraceParser)
			printf("%d: simple type decl sys\n",lineno);
		yyval = newStmtNode(TypeK);
		yyval->attr.name = copyString(tokenString);	
	;
    break;}
case 33:
#line 262 "parser.y"
{
		if(TraceParser)
			printf("%d: simple type decl ID\n",lineno);
		yyval = newStmtNode(TypeK);
		yyval->attr.name = "IDType";
		yyval->child[0] = yyvsp[0];	
	;
    break;}
case 34:
#line 270 "parser.y"
{
		if(TraceParser)
			printf("%d: simple type decl ENUM\n",lineno);
		yyval = newStmtNode(TypeK);
		yyval->attr.name = "EnumType";	
		yyval->child[0]=yyvsp[-1];
	;
    break;}
case 35:
#line 278 "parser.y"
{
		if(TraceParser)
			printf("%d: simple type decl ENUM\n",lineno);
		yyerror("missing ')' ");
		yyval = newStmtNode(TypeK);
		yyval->attr.name = "EnumType";	
		yyval->child[0]=yyvsp[-1];
	;
    break;}
case 36:
#line 287 "parser.y"
{
		if(TraceParser)
			printf("%d: simple type decl ENUM\n",lineno);
		yyerror("missing '(' ");
		yyval = newStmtNode(TypeK);
		yyval->attr.name = "EnumType";	
		yyval->child[0]=yyvsp[-1];
	;
    break;}
case 37:
#line 296 "parser.y"
{
		if(TraceParser)
			printf("%d: simple type decl range 1\n",lineno);
		yyval = newStmtNode(TypeK);
		yyval->attr.name = "RangeType";	
		yyval->child[0]=yyvsp[-3];
		yyval->child[1]=yyvsp[0];
	;
    break;}
case 38:
#line 305 "parser.y"
{
		if(TraceParser)
			printf("%d: simple type decl range 2\n",lineno);
		yyval = newStmtNode(TypeK);
		yyval->attr.name = "RangeType2";	
		yyval->child[0]=yyvsp[-3];
		yyval->child[1]=yyvsp[0];
	;
    break;}
case 39:
#line 314 "parser.y"
{
		if(TraceParser)
			printf("%d: simple type decl range 3\n",lineno);
		yyval = newStmtNode(TypeK);
		yyval->attr.name = "RangeType3";	
		yyval->child[0]=yyvsp[-4];
		yyval->child[1]=yyvsp[-1];
	;
    break;}
case 40:
#line 323 "parser.y"
{
		if(TraceParser)
			printf("%d: simple type decl range 4\n",lineno);
		yyval = newStmtNode(TypeK);
		yyval->attr.name = "RangeType4";	
		yyval->child[0]=yyvsp[-3];
		yyval->child[1]=yyvsp[0];
	;
    break;}
case 41:
#line 333 "parser.y"
{
		if(TraceParser)
			printf("%d: var part1\n",lineno);
		yyval=yyvsp[0];
	;
    break;}
case 42:
#line 338 "parser.y"
{
		if(TraceParser)
			printf("%d: var part 2\n",lineno);
		yyval=NULL;
	;
    break;}
case 43:
#line 345 "parser.y"
{
		if(TraceParser)
			printf("%d: var decl list1\n",lineno);
		yyval=yyvsp[-1]; 
		nodeInsert(yyvsp[-1],yyvsp[0]);
	;
    break;}
case 44:
#line 352 "parser.y"
{
		if(TraceParser)
			printf("%d: var decl list2\n",lineno);
		yyval=yyvsp[0];
	;
    break;}
case 45:
#line 359 "parser.y"
{
		if(TraceParser)
			printf("%d: var decl \n",lineno);
		yyval=newStmtNode(DeclK);
		yyval->attr.name="ValDecl";
		yyval->child[0] = yyvsp[-3];
		yyval->child[1] = yyvsp[-1];
	;
    break;}
case 46:
#line 369 "parser.y"
{
		if(TraceParser)
			printf("%d: routine part 1\n",lineno);
		yyval=yyvsp[-1]; 
		nodeInsert(yyvsp[-1],yyvsp[0]);
	;
    break;}
case 47:
#line 376 "parser.y"
{
		if(TraceParser)
			printf("%d: routine part 2\n",lineno);
		yyval=yyvsp[-1]; 
		nodeInsert(yyvsp[-1],yyvsp[0]);
	;
    break;}
case 48:
#line 382 "parser.y"
{ 
		if(TraceParser)
			printf("%d: routine part 3\n",lineno);
		yyval=yyvsp[0]; 
	;
    break;}
case 49:
#line 387 "parser.y"
{ 
		if(TraceParser)
			printf("%d: routine part 4\n",lineno);
		yyval=yyvsp[0];
	 ;
    break;}
case 50:
#line 392 "parser.y"
{
		if(TraceParser)
			printf("%d: routine part 5 \n",lineno);
		yyval=NULL;
	;
    break;}
case 51:
#line 399 "parser.y"
{
		if(TraceParser)
			printf("%d: func decl \n",lineno);
		yyval=newStmtNode(DeclK);
		yyval->attr.name="FuncDecl";
		yyval->child[0] = yyvsp[-3];
		yyval->child[1] = yyvsp[-1];
	;
    break;}
case 52:
#line 409 "parser.y"
{
		if(TraceParser)
			printf("%d: func head \n",lineno);
		yyval=newStmtNode(FHeadK);
		yyval->child[0] = yyvsp[-3];
		yyval->child[1] = yyvsp[-2];
		yyval->child[2] = yyvsp[0];
	;
    break;}
case 53:
#line 419 "parser.y"
{
		if(TraceParser)
			printf("%d: proc decl \n",lineno);
		yyval=newStmtNode(DeclK);
		yyval->attr.name="ProcDecl";
		yyval->child[0] = yyvsp[-3];
		yyval->child[1] = yyvsp[-1];
	;
    break;}
case 54:
#line 429 "parser.y"
{
		if(TraceParser)
			printf("%d: proc head \n",lineno);
		yyval=newStmtNode(PHeadK);
		yyval->child[0] = yyvsp[-1];
		yyval->child[1] = yyvsp[0];
	;
    break;}
case 55:
#line 438 "parser.y"
{ 
		if(TraceParser)
			printf("%d: para 1 \n",lineno);
		yyval=yyvsp[-1];
	;
    break;}
case 56:
#line 444 "parser.y"
{ 
		if(TraceParser)
			printf("%d: para 1 \n",lineno);
		yyerror("missing ')' ");
		yyval=yyvsp[-1];
	;
    break;}
case 57:
#line 451 "parser.y"
{ 
		if(TraceParser)
			printf("%d: para 1 \n",lineno);
		yyerror("missing '(' ");
		yyval=yyvsp[-1];
	;
    break;}
case 58:
#line 457 "parser.y"
{ 
		if(TraceParser)
			printf("%d: para 2 \n",lineno);
		yyval=NULL;
	;
    break;}
case 59:
#line 464 "parser.y"
{ 
		if(TraceParser)
			printf("%d: para decl list 1 \n",lineno);
		yyval=yyvsp[-2]; 
		nodeInsert(yyvsp[-2],yyvsp[0]);
	;
    break;}
case 60:
#line 471 "parser.y"
{ 
		if(TraceParser)
			printf("%d: para decl list 2 \n",lineno);
		yyval=yyvsp[0]; 
	;
    break;}
case 61:
#line 478 "parser.y"
{
		if(TraceParser)
			printf("%d: para type list \n",lineno);
		yyval = newStmtNode(ParaK);
		yyval->child[0]=yyvsp[-2];
		yyval->child[1]=yyvsp[0];
	;
    break;}
case 62:
#line 486 "parser.y"
{
		if(TraceParser)
			printf("%d: var para  list 1\n",lineno);
		yyval = yyvsp[0];
	;
    break;}
case 63:
#line 492 "parser.y"
{
		if(TraceParser)
			printf("%d: var para  list 2 \n",lineno);
		yyval = yyvsp[0];
	;
    break;}
case 64:
#line 498 "parser.y"
{
		if(TraceParser)
			printf("%d: routine body \n",lineno);
		yyval = yyvsp[0];
	;
    break;}
case 65:
#line 505 "parser.y"
{
		if(TraceParser)
			printf("%d: stmt list 1 \n",lineno);
		yyval=yyvsp[-2]; 
		nodeInsert(yyvsp[-2],yyvsp[-1]);
	;
    break;}
case 66:
#line 511 "parser.y"
{
		if(TraceParser)
			printf("%d: stmt list 2 \n",lineno);
		yyval=yyvsp[-1];
	;
    break;}
case 67:
#line 516 "parser.y"
{yyval = NULL;;
    break;}
case 68:
#line 518 "parser.y"
{savedVal=atoi(tokenString);;
    break;}
case 69:
#line 519 "parser.y"
{
		if(TraceParser)
			printf("%d: stmt label \n",lineno);
		yyval=yyvsp[0]; 
		yyval->attr.ival=savedVal;
	;
    break;}
case 70:
#line 525 "parser.y"
{
		if(TraceParser)
			printf("%d: stmt non label \n",lineno);
		yyval=yyvsp[0];
	;
    break;}
case 71:
#line 531 "parser.y"
{yyval=yyvsp[0];;
    break;}
case 72:
#line 532 "parser.y"
{yyval=yyvsp[0];;
    break;}
case 73:
#line 533 "parser.y"
{yyval=yyvsp[0];;
    break;}
case 74:
#line 534 "parser.y"
{yyval=yyvsp[0];;
    break;}
case 75:
#line 535 "parser.y"
{yyval=yyvsp[0];;
    break;}
case 76:
#line 536 "parser.y"
{yyval=yyvsp[0];;
    break;}
case 77:
#line 537 "parser.y"
{yyval=yyvsp[0];;
    break;}
case 78:
#line 538 "parser.y"
{yyval=yyvsp[0];;
    break;}
case 79:
#line 539 "parser.y"
{yyval=yyvsp[0];;
    break;}
case 80:
#line 540 "parser.y"
{yyerror("incorrect statement");  yyval=NULL;;
    break;}
case 81:
#line 544 "parser.y"
{
		if(TraceParser)
			printf("%d: assign id \n",lineno);
		yyval = newStmtNode(AssignK);
		yyval->child[0] = yyvsp[-2];
		yyval->child[1] = yyvsp[0];
	;
    break;}
case 82:
#line 552 "parser.y"
{	
		if(TraceParser)
			printf("%d: assign array \n",lineno);
		yyval = newStmtNode(ArrayAssignK);
		yyval->child[0] = yyvsp[-5];
	 	yyval->child[1] = yyvsp[-3];
	 	yyval->child[2] = yyvsp[0];
	;
    break;}
case 83:
#line 561 "parser.y"
{	
		if(TraceParser)
			printf("%d: assign array \n",lineno);
		yyerror("missing ']' ");
		yyval = newStmtNode(ArrayAssignK);
		yyval->child[0] = yyvsp[-5];
	 	yyval->child[1] = yyvsp[-3];
	 	yyval->child[2] = yyvsp[0];
	;
    break;}
case 84:
#line 571 "parser.y"
{	
		if(TraceParser)
			printf("%d: assign array \n",lineno);
		yyerror("missing '[' ");
		yyval = newStmtNode(ArrayAssignK);
		yyval->child[0] = yyvsp[-5];
	 	yyval->child[1] = yyvsp[-3];
	 	yyval->child[2] = yyvsp[0];
	;
    break;}
case 85:
#line 581 "parser.y"
{
		if(TraceParser)
			printf("%d: assign elem \n",lineno);
		yyval = newStmtNode(ElemAssignK);
		yyval->child[0] = yyvsp[-4];
	 	yyval->child[1] = yyvsp[-2];
	 	yyval->child[2] = yyvsp[0];
	 ;
    break;}
case 86:
#line 591 "parser.y"
{
		if(TraceParser)
			printf("%d: ProcK no args \n",lineno);
		yyval = newStmtNode(ProcK);
		yyval->child[0]=yyvsp[0];
	;
    break;}
case 87:
#line 598 "parser.y"
{
		if(TraceParser)
			printf("%d: ProcK with args \n",lineno);
		yyval = newStmtNode(ProcK);
		yyval->child[0] = yyvsp[-3];
		yyval->child[1] = yyvsp[-1];
	;
    break;}
case 88:
#line 606 "parser.y"
{
		if(TraceParser)
			printf("%d: ProcK with args \n",lineno);
		yyerror("missing ')' ");
		yyval = newStmtNode(ProcK);
		yyval->child[0] = yyvsp[-3];
		yyval->child[1] = yyvsp[-1];
	;
    break;}
case 89:
#line 615 "parser.y"
{
		if(TraceParser)
			printf("%d: ProcK with args \n",lineno);
		yyerror("missing '(' ");
		yyval = newStmtNode(ProcK);
		yyval->child[0] = yyvsp[-3];
		yyval->child[1] = yyvsp[-1];
	;
    break;}
case 90:
#line 624 "parser.y"
{
		if(TraceParser)
			printf("%d: ProcK sys \n",lineno);
		yyval = newStmtNode(ProcK);
		yyval->attr.name="sProc";
	;
    break;}
case 91:
#line 631 "parser.y"
{
		if(TraceParser)
			printf("%d: ProcK sys args \n",lineno);
		yyval = newStmtNode(ProcK);
		yyval->attr.name="Proc";
		yyval->child[0] = yyvsp[-1];
	;
    break;}
case 92:
#line 639 "parser.y"
{
		if(TraceParser)
			printf("%d: WriteK \n",lineno);
		yyval = newStmtNode(WriteK);
		yyval->attr.name="writeln";
		yyval->child[0] = yyvsp[-1];
	;
    break;}
case 93:
#line 647 "parser.y"
{
		if(TraceParser)
			printf("%d: WriteK \n",lineno);
		yyerror("missing ')' ");
		yyval = newStmtNode(WriteK);
		yyval->attr.name="writeln";
		yyval->child[0] = yyvsp[-1];
	;
    break;}
case 94:
#line 656 "parser.y"
{
		if(TraceParser)
			printf("%d: WriteK \n",lineno);
		yyerror("missing '(' ");
		yyval = newStmtNode(WriteK);
		yyval->attr.name="writeln";
		yyval->child[0] = yyvsp[-1];
	;
    break;}
case 95:
#line 665 "parser.y"
{
		if(TraceParser)
			printf("%d: ReadK \n",lineno);
		yyval = newStmtNode(ReadK);
		yyval->attr.name="read";
		yyval->child[0] = yyvsp[-1];
	;
    break;}
case 96:
#line 673 "parser.y"
{
		if(TraceParser)
			printf("%d: ReadK \n",lineno);
		yyerror("missing ')' ");
		yyval = newStmtNode(ReadK);
		yyval->attr.name="read";
		yyval->child[0] = yyvsp[-1];
	;
    break;}
case 97:
#line 682 "parser.y"
{
		if(TraceParser)
			printf("%d: ReadK \n",lineno);
		yyerror("missing '(' ");
		yyval = newStmtNode(ReadK);
		yyval->attr.name="read";
		yyval->child[0] = yyvsp[-1];
	;
    break;}
case 98:
#line 692 "parser.y"
{yyval=yyvsp[-1];;
    break;}
case 99:
#line 695 "parser.y"
{
		if(TraceParser)
			printf("%d: if stmt \n",lineno);
		yyval=newStmtNode(IfK);
		yyval->child[0] = yyvsp[-3];
		yyval->child[1] = yyvsp[-1];
		yyval->child[2] = yyvsp[0];
	;
    break;}
case 100:
#line 705 "parser.y"
{
		if(TraceParser)
			printf("%d: else stmt \n",lineno);
		yyval=yyvsp[0];
	;
    break;}
case 101:
#line 710 "parser.y"
{ if(TraceParser)
			printf("%d: no else \n",lineno);yyval=NULL;;
    break;}
case 102:
#line 714 "parser.y"
{
		if(TraceParser)
			printf("%d: repeat stmt \n",lineno);
		yyval=newStmtNode(RepeatK);
		yyval->child[0] = yyvsp[-2];
		yyval->child[1] = yyvsp[0];
	;
    break;}
case 103:
#line 723 "parser.y"
{
		if(TraceParser)
			printf("%d: while stmt \n",lineno);
		yyval=newStmtNode(WhileK);
		yyval->child[0] = yyvsp[-2];
		yyval->child[1] = yyvsp[0];
	;
    break;}
case 104:
#line 732 "parser.y"
{
		if(TraceParser)
			printf("%d: for stmt \n",lineno);
		yyval=newStmtNode(ForK);
		yyval->child[0] =newStmtNode(AssignK);
		yyval->child[0] ->child[0]=yyvsp[-6];
		yyval->child[0] ->child[1]=yyvsp[-4];
		yyval->child[1] = yyvsp[-3];
		yyval->child[2] = yyvsp[-2];
		yyval->child[3] = yyvsp[0];
	;
    break;}
case 105:
#line 745 "parser.y"
{
		if(TraceParser)
			printf("%d: direct to \n",lineno);
		yyval=newStmtNode(ForK);
		yyval->attr.ival=1;
	;
    break;}
case 106:
#line 752 "parser.y"
{	
		if(TraceParser)
			printf("%d: direct downto \n",lineno);
		yyval=newStmtNode(ForK);
		yyval->attr.ival=0;
	;
    break;}
case 107:
#line 760 "parser.y"
{
		/*
		$$=newStmtNode(CaseK);
		$$->child[0] = $2;
		$$->child[1] = $4;
		*/
		TreeNode * tmp;
		TreeNode * tmp2;
		TreeNode * iter;
		if(TraceParser)
			printf("%d: case stmt \n",lineno);
		iter=yyvsp[-1];
		yyval=newStmtNode(IfK);
		tmp=newExpNode(OpK);
		tmp->attr.op = EQ;
		tmp->child[0]=yyvsp[-3];
		tmp->child[1]=iter->child[0];
		yyval->child[0]=tmp;
		yyval->child[1]=iter->child[1];
		tmp2=yyval;
		while((iter=iter->sibling)!=NULL)
		{
			tmp2->child[2]=newStmtNode(IfK);
			tmp2=tmp2->child[2];
			tmp=newExpNode(OpK);
			tmp->attr.op = EQ;
			tmp->child[0]=yyvsp[-3];
			tmp->child[1]=iter->child[0];
			tmp2->child[0]=tmp;
			tmp2->child[1]=iter->child[1];
		}
	;
    break;}
case 108:
#line 794 "parser.y"
{
		if(TraceParser)
			printf("%d: case exp list 1 \n",lineno);
		yyval=yyvsp[-1]; 
		nodeInsert(yyvsp[-1],yyvsp[0]);
	;
    break;}
case 109:
#line 800 "parser.y"
{ if(TraceParser)
			printf("%d: case exp list 2 \n",lineno);yyval=yyvsp[0];;
    break;}
case 110:
#line 804 "parser.y"
{
		if(TraceParser)
			printf("%d: case expr const \n",lineno);
		yyval=newExpNode(CaseExpK);
		yyval->child[0]=yyvsp[-3];
		yyval->child[1]=yyvsp[-1];
	;
    break;}
case 111:
#line 812 "parser.y"
{
		if(TraceParser)
			printf("%d: case expr id \n",lineno);
		yyval=newExpNode(CaseExpK);
		yyval->child[0]=yyvsp[-3];
		yyval->child[1]=yyvsp[-1];
	;
    break;}
case 112:
#line 821 "parser.y"
{
		if(TraceParser)
			printf("%d: goto stmt \n",lineno);
		yyval=newStmtNode(GotoK);
		yyval->attr.ival=atoi(tokenString);
	;
    break;}
case 113:
#line 829 "parser.y"
{
		if(TraceParser)
			printf("%d: exp list 1 \n",lineno);
		yyval=yyvsp[-2]; 
		nodeInsert(yyvsp[-2],yyvsp[0]);
	;
    break;}
case 114:
#line 835 "parser.y"
{if(TraceParser)
			printf("%d: exp list 2 \n",lineno);yyval=yyvsp[0];;
    break;}
case 115:
#line 839 "parser.y"
{
		if(TraceParser)
			printf("%d: exp ge \n",lineno);
		yyval = newExpNode(OpK);
		yyval->child[0] = yyvsp[-2];
		yyval->child[1] = yyvsp[0];
		yyval->attr.op = GE;
	;
    break;}
case 116:
#line 848 "parser.y"
{
		if(TraceParser)
			printf("%d: exp gt \n",lineno);
		yyval = newExpNode(OpK);
	 	yyval->child[0] = yyvsp[-2];
	 	yyval->child[1] = yyvsp[0];
		yyval->attr.op = GT;
	;
    break;}
case 117:
#line 857 "parser.y"
{
		if(TraceParser)
			printf("%d: exp le \n",lineno);
		yyval = newExpNode(OpK);
		yyval->child[0] = yyvsp[-2];
		yyval->child[1] = yyvsp[0];
		yyval->attr.op = LE;
	;
    break;}
case 118:
#line 866 "parser.y"
{
		if(TraceParser)
			printf("%d: exp lt\n",lineno);
		yyval = newExpNode(OpK);
		yyval->child[0] = yyvsp[-2];
		yyval->child[1] = yyvsp[0];
		yyval->attr.op = LT;
	;
    break;}
case 119:
#line 875 "parser.y"
{
		if(TraceParser)
			printf("%d: exp eq \n",lineno);
		yyval = newExpNode(OpK);
		yyval->child[0] = yyvsp[-2];
		yyval->child[1] = yyvsp[0];
		yyval->attr.op = EQ;
	;
    break;}
case 120:
#line 884 "parser.y"
{
		if(TraceParser)
			printf("%d: exp ne \n",lineno);
		yyval = newExpNode(OpK);
		yyval->child[0] = yyvsp[-2];
		yyval->child[1] = yyvsp[0];
		yyval->attr.op = NE;
	;
    break;}
case 121:
#line 892 "parser.y"
{
		if(TraceParser)
			printf("%d: one expr \n",lineno);
		yyval=yyvsp[0];
	;
    break;}
case 122:
#line 899 "parser.y"
{ 
		if(TraceParser)
			printf("%d: expr plus \n",lineno);
		yyval=newExpNode(OpK);
		yyval->child[0] = yyvsp[-2];
		yyval->child[1] = yyvsp[0];
		yyval->attr.op = PLUS;
	;
    break;}
case 123:
#line 908 "parser.y"
{ 
		if(TraceParser)
			printf("%d: expr minus \n",lineno);
		yyval=newExpNode(OpK);
		yyval->child[0] = yyvsp[-2];
		yyval->child[1] = yyvsp[0];
		yyval->attr.op = MINUS;
	;
    break;}
case 124:
#line 917 "parser.y"
{ 
		if(TraceParser)
			printf("%d: expr or \n",lineno);
		yyval=newExpNode(OpK);
		yyval->child[0] = yyvsp[-2];
		yyval->child[1] = yyvsp[0];
		yyval->attr.op = OR;
	;
    break;}
case 125:
#line 925 "parser.y"
{
		if(TraceParser)
			printf("%d: expr term \n",lineno);
		yyval=yyvsp[0];
	;
    break;}
case 126:
#line 932 "parser.y"
{ 
		if(TraceParser)
			printf("%d: term mul \n",lineno);
		yyval=newExpNode(OpK);
		yyval->child[0] = yyvsp[-2];
		yyval->child[1] = yyvsp[0];
		yyval->attr.op = MUL;
	;
    break;}
case 127:
#line 941 "parser.y"
{ 
		if(TraceParser)
			printf("%d: term div \n",lineno);
		yyval=newExpNode(OpK);
		yyval->child[0] = yyvsp[-2];
		yyval->child[1] = yyvsp[0];
		yyval->attr.op = DIV;
	;
    break;}
case 128:
#line 950 "parser.y"
{ 
		if(TraceParser)
			printf("%d: term mod \n",lineno);
		yyval=newExpNode(OpK);
		yyval->child[0] = yyvsp[-2];
		yyval->child[1] = yyvsp[0];
		yyval->attr.op = MOD;
	;
    break;}
case 129:
#line 959 "parser.y"
{ 
 		if(TraceParser)
			printf("%d: term and \n",lineno);
		yyval=newExpNode(OpK);
		yyval->child[0] = yyvsp[-2];
		yyval->child[1] = yyvsp[0];
		yyval->attr.op = AND;
	;
    break;}
case 130:
#line 967 "parser.y"
{if(TraceParser)
			printf("%d: term factor \n",lineno);yyval=yyvsp[0];;
    break;}
case 131:
#line 971 "parser.y"
{
		if(TraceParser)
			printf("%d: factor id \n",lineno);
		yyval = yyvsp[0];
	;
    break;}
case 132:
#line 977 "parser.y"
{
		if(TraceParser)
			printf("%d: factor call \n",lineno);
		yyval = newExpNode(CallK);
		yyval->child[0] = yyvsp[-3];
		yyval->child[1] = yyvsp[-1];
	;
    break;}
case 133:
#line 985 "parser.y"
{
		if(TraceParser)
			printf("%d: factor call \n",lineno);
		yyerror("missing ')' ");
		yyval = newExpNode(CallK);
		yyval->child[0] = yyvsp[-3];
		yyval->child[1] = yyvsp[-1];
	;
    break;}
case 134:
#line 994 "parser.y"
{
		if(TraceParser)
			printf("%d: factor call \n",lineno);
		yyerror("missing '(' ");
		yyval = newExpNode(CallK);
		yyval->child[0] = yyvsp[-3];
		yyval->child[1] = yyvsp[-1];
	;
    break;}
case 135:
#line 1002 "parser.y"
{;
    break;}
case 136:
#line 1003 "parser.y"
{;
    break;}
case 137:
#line 1004 "parser.y"
{ 
		if(TraceParser)
			printf("%d: factor const  \n",lineno);
		yyval=yyvsp[0];
	;
    break;}
case 138:
#line 1009 "parser.y"
{ if(TraceParser)
			printf("%d: factor exp \n",lineno);yyval = yyvsp[-1];;
    break;}
case 139:
#line 1012 "parser.y"
{
		if(TraceParser)
			printf("%d: factor not \n",lineno);
		yyval=newExpNode(UnaryK);
		yyval->attr.ival=0;  // ~
		yyval->child[0]=yyvsp[0];
	;
    break;}
case 140:
#line 1020 "parser.y"
{
		if(TraceParser)
			printf("%d: factor minus \n",lineno);
		yyval=newExpNode(UnaryK);
		yyval->attr.ival=1;  // -
		yyval->child[0]=yyvsp[0];
	;
    break;}
case 141:
#line 1028 "parser.y"
{
		if(TraceParser)
			printf("%d: factor array \n",lineno);
		yyval=newExpNode(ArrayK);
		yyval->child[0]=yyvsp[-3];
		yyval->child[1]=yyvsp[-1];
	;
    break;}
case 142:
#line 1036 "parser.y"
{
		if(TraceParser)
			printf("%d: factor array \n",lineno);
		yyerror("missing ']' ");
		yyval=newExpNode(ArrayK);
		yyval->child[0]=yyvsp[-3];
		yyval->child[1]=yyvsp[-1];
	;
    break;}
case 143:
#line 1045 "parser.y"
{
		if(TraceParser)
			printf("%d: factor array \n",lineno);
		yyerror("missing '[' ");
		yyval=newExpNode(ArrayK);
		yyval->child[0]=yyvsp[-3];
		yyval->child[1]=yyvsp[-1];
	;
    break;}
case 144:
#line 1054 "parser.y"
{
		if(TraceParser)
			printf("%d: factor element \n",lineno);
		yyval=newExpNode(ElemK);
		yyval->child[0]=yyvsp[-2];
		yyval->child[1]=yyvsp[0];
	;
    break;}
case 145:
#line 1063 "parser.y"
{
		if(TraceParser)
			printf("%d: args list 1 \n",lineno);
		yyval=yyvsp[-2]; 
		nodeInsert(yyvsp[-2],yyvsp[0]);
	;
    break;}
case 146:
#line 1070 "parser.y"
{
		if(TraceParser)
			printf("%d: args list 2 \n",lineno);
		yyval=yyvsp[0];
	;
    break;}
case 147:
#line 1076 "parser.y"
{
		yyval = newExpNode(IdK);
		yyval->attr.name = copyString(tokenString);	
		yyval->lineno=lineno;	
	;
    break;}
case 148:
#line 1082 "parser.y"
{
		if(TraceParser)
			printf("%d: ERROR TOKEN \n",lineno);
		yyval=NULL;
		yyerror("illegal token");
	;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 442 "bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  for (x = 0; x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = 0; x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;
}
#line 1090 "parser.y"


int yyerror(char * message)
{
	printf("error %d",lineno);
	fprintf(listing,"Syntax error at line %d: %s\n",lineno,message);
	fprintf(listing,"Current token: ");
	printToken(yychar,tokenString);
	err=1;
	return 0;
}

/* yylex calls getToken to make Yacc/Bison output*/

static int yylex(void)
{
	return getToken(); 
}

TreeNode * parse(void)
{	
	yyparse();
	if(!err)
		return savedTree;
	else
		return NULL;
}

/*
void main()
{
	TreeNode* root;
	root= parse();
	printTree(root);
	if(TraceParser)
			printf("OK");
}
*/