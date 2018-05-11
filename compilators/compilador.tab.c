/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 6 "compilador.y"

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "compilador.h"
#include "tabela.h"

int num_vars,ind_element;



/* Line 268 of yacc.c  */
#line 84 "compilador.tab.c"

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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     PROGRAM = 258,
     ABRE_PARENTESES = 259,
     FECHA_PARENTESES = 260,
     VIRGULA = 261,
     PONTO_E_VIRGULA = 262,
     DOIS_PONTOS = 263,
     PONTO = 264,
     T_BEGIN = 265,
     T_END = 266,
     VAR = 267,
     IDENT = 268,
     ATRIBUICAO = 269,
     READ = 270,
     WRITE = 271,
     NUMERO = 272,
     MAIS = 273,
     MENOS = 274,
     OR = 275,
     VEZES = 276,
     DIVIDIDOS = 277,
     AND = 278,
     MAIOR = 279,
     MENOR = 280,
     MAIOR_IGUAL = 281,
     MENOR_IGUAL = 282,
     IGUAL = 283,
     DIFERENTE = 284,
     WHILE = 285,
     DO = 286,
     PROCEDURE = 287,
     FUNCTION = 288,
     LABEL = 289,
     GOTO = 290,
     IF = 291,
     THEN = 292,
     ELSE = 293,
     LOWER_THAN_ELSE = 294
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 165 "compilador.tab.c"

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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
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
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   160

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  82
/* YYNRULES -- Number of rules.  */
#define YYNRULES  127
/* YYNRULES -- Number of states.  */
#define YYNSTATES  201

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   294

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
      35,    36,    37,    38,    39
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,    14,    19,    21,    22,    26,    30,
      32,    34,    36,    37,    40,    42,    44,    46,    50,    52,
      54,    55,    59,    60,    63,    65,    66,    67,    74,    78,
      80,    82,    86,    89,    92,    93,    96,    98,   100,   102,
     104,   106,   108,   109,   113,   116,   118,   119,   120,   121,
     131,   132,   135,   136,   137,   138,   139,   152,   153,   158,
     162,   163,   167,   169,   170,   171,   177,   179,   180,   184,
     185,   187,   188,   189,   190,   195,   198,   199,   202,   205,
     208,   211,   214,   217,   220,   221,   223,   225,   229,   233,
     237,   240,   243,   245,   247,   251,   255,   259,   262,   264,
     268,   270,   272,   273,   275,   276,   277,   284,   287,   288,
     294,   295,   299,   300,   303,   305,   307,   312,   316,   318,
     320,   325,   329,   331,   333,   335,   337,   340
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      41,     0,    -1,    -1,    42,     3,    13,     4,   117,     5,
       7,    43,     9,    -1,    44,    53,    48,    61,    -1,    45,
      -1,    -1,    34,    46,     7,    -1,    46,     6,    47,    -1,
      47,    -1,    17,    -1,    49,    -1,    -1,    49,    50,    -1,
      50,    -1,    69,    -1,    75,    -1,    51,     6,    52,    -1,
      52,    -1,    13,    -1,    -1,    12,    54,    55,    -1,    -1,
      55,    56,    -1,    56,    -1,    -1,    -1,    57,    59,     8,
     118,    58,     7,    -1,    59,     6,    60,    -1,    60,    -1,
      13,    -1,    10,    62,    11,    -1,    64,    63,    -1,     7,
      62,    -1,    -1,   121,    65,    -1,    66,    -1,   103,    -1,
      61,    -1,   106,    -1,   112,    -1,   111,    -1,    -1,   119,
      67,    68,    -1,    14,   102,    -1,    73,    -1,    -1,    -1,
      -1,    32,    13,    70,    82,    71,     7,    43,    72,     7,
      -1,    -1,    74,    87,    -1,    -1,    -1,    -1,    -1,    33,
      13,    76,    82,    77,     8,   118,    78,     7,    43,    79,
       7,    -1,    -1,     4,    81,    88,     5,    -1,     4,    83,
       5,    -1,    -1,    83,     7,    84,    -1,    84,    -1,    -1,
      -1,    86,    85,    51,     8,   118,    -1,    12,    -1,    -1,
       4,    88,     5,    -1,    -1,    89,    -1,    -1,    -1,    -1,
      90,    93,    91,    92,    -1,     6,    89,    -1,    -1,    95,
      94,    -1,    28,    95,    -1,    29,    95,    -1,    24,    95,
      -1,    25,    95,    -1,    26,    95,    -1,    27,    95,    -1,
      -1,    96,    -1,    97,    -1,    95,    18,    97,    -1,    95,
      19,    97,    -1,    95,    20,    97,    -1,    18,    97,    -1,
      19,    97,    -1,    98,    -1,    99,    -1,    97,    21,    99,
      -1,    97,    22,    99,    -1,    97,    23,    99,    -1,   119,
     100,    -1,    17,    -1,     4,    93,     5,    -1,    80,    -1,
     101,    -1,    -1,    93,    -1,    -1,    -1,    30,   104,    93,
     105,    31,    65,    -1,   107,   109,    -1,    -1,    36,    93,
     108,    37,    65,    -1,    -1,    38,   110,    65,    -1,    -1,
      35,   120,    -1,   113,    -1,   116,    -1,    16,     4,   114,
       5,    -1,   114,     6,   115,    -1,   115,    -1,    93,    -1,
      15,     4,   119,     5,    -1,   117,     6,    13,    -1,    13,
      -1,    13,    -1,    13,    -1,    17,    -1,   120,     8,    -1,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    31,    31,    31,    43,    56,    56,    59,    62,    62,
      65,    75,    75,    78,    79,    82,    82,    86,    87,    89,
      99,    99,   100,   103,   104,   107,   110,   107,   124,   125,
     127,   140,   142,   144,   144,   147,   150,   151,   152,   153,
     154,   155,   159,   159,   162,   163,   173,   197,   202,   171,
     215,   215,   240,   264,   269,   278,   238,   288,   287,   312,
     313,   317,   318,   318,   322,   321,   333,   334,   341,   341,
     345,   346,   349,   352,   349,   359,   359,   367,   370,   371,
     372,   373,   374,   375,   376,   379,   383,   385,   386,   387,
     388,   389,   393,   397,   399,   400,   401,   404,   405,   412,
     415,   416,   417,   446,   481,   484,   481,   505,   513,   512,
     529,   529,   531,   539,   553,   553,   556,   558,   558,   561,
     568,   579,   580,   582,   585,   593,   604,   608
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PROGRAM", "ABRE_PARENTESES",
  "FECHA_PARENTESES", "VIRGULA", "PONTO_E_VIRGULA", "DOIS_PONTOS", "PONTO",
  "T_BEGIN", "T_END", "VAR", "IDENT", "ATRIBUICAO", "READ", "WRITE",
  "NUMERO", "MAIS", "MENOS", "OR", "VEZES", "DIVIDIDOS", "AND", "MAIOR",
  "MENOR", "MAIOR_IGUAL", "MENOR_IGUAL", "IGUAL", "DIFERENTE", "WHILE",
  "DO", "PROCEDURE", "FUNCTION", "LABEL", "GOTO", "IF", "THEN", "ELSE",
  "LOWER_THAN_ELSE", "$accept", "programa", "$@1", "bloco",
  "parte_declara_labels", "declara_labels", "lista_de_labels",
  "declara_label", "parte_declara_procedimentos", "declara_procedimentos",
  "declara_proc_ou_func", "lista_id_par", "insere_par",
  "parte_declara_vars", "$@2", "declara_vars", "declara_var", "$@3", "$@4",
  "lista_id_var", "insere_var", "comando_composto", "comandos",
  "comandos_aux", "comando", "comando_sem_rotulo", "atrib_ou_proc", "$@5",
  "atrib_ou_prox_aux", "declara_procedimento", "$@6", "$@7", "$@8",
  "chama_proc", "$@9", "declara_funcao", "$@10", "$@11", "$@12", "$@13",
  "chama_func", "$@14", "parametros_formais_aux", "parametros_formais",
  "declaracao_parametros", "$@15", "passagem_referencia",
  "passagem_parametros", "lista_passagem_parametros_aux",
  "lista_passagem_parametros", "$@16", "$@17", "passar_parametro_aux",
  "expressao", "expressao_aux", "expressao_simples_geral",
  "expressao_simples", "pre_termo", "termo", "fator",
  "seleciona_variavel_dir", "variavel_dir", "atribuicao",
  "comando_repetitivo", "$@18", "$@19", "comando_condicional", "if_then",
  "$@20", "cond_else", "$@21", "goto", "preset", "write",
  "lista_variaveis_write", "imprime_variavel", "read", "lista_idents",
  "tipo", "variavel", "rotulo", "usa_rotulo", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    42,    41,    43,    44,    44,    45,    46,    46,
      47,    48,    48,    49,    49,    50,    50,    51,    51,    52,
      54,    53,    53,    55,    55,    57,    58,    56,    59,    59,
      60,    61,    62,    63,    63,    64,    65,    65,    65,    65,
      65,    65,    67,    66,    68,    68,    70,    71,    72,    69,
      74,    73,    76,    77,    78,    79,    75,    81,    80,    82,
      82,    83,    83,    83,    85,    84,    86,    86,    87,    87,
      88,    88,    90,    91,    89,    92,    92,    93,    94,    94,
      94,    94,    94,    94,    94,    95,    95,    96,    96,    96,
      96,    96,    97,    97,    98,    98,    98,    99,    99,    99,
     100,   100,   101,   102,   104,   105,   103,   106,   108,   107,
     110,   109,   109,   111,   112,   112,   113,   114,   114,   115,
     116,   117,   117,   118,   119,   120,   121,   121
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     9,     4,     1,     0,     3,     3,     1,
       1,     1,     0,     2,     1,     1,     1,     3,     1,     1,
       0,     3,     0,     2,     1,     0,     0,     6,     3,     1,
       1,     3,     2,     2,     0,     2,     1,     1,     1,     1,
       1,     1,     0,     3,     2,     1,     0,     0,     0,     9,
       0,     2,     0,     0,     0,     0,    12,     0,     4,     3,
       0,     3,     1,     0,     0,     5,     1,     0,     3,     0,
       1,     0,     0,     0,     4,     2,     0,     2,     2,     2,
       2,     2,     2,     2,     0,     1,     1,     3,     3,     3,
       2,     2,     1,     1,     3,     3,     3,     2,     1,     3,
       1,     1,     0,     1,     0,     0,     6,     2,     0,     5,
       0,     3,     0,     2,     1,     1,     4,     3,     1,     1,
       4,     3,     1,     1,     1,     1,     2,     0
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     0,     0,     0,   122,     0,     0,
       0,     6,   121,     0,     0,    22,     5,    10,     0,     9,
       3,    20,    12,     0,     7,    25,     0,     0,     0,    11,
      14,    15,    16,     8,    21,    24,     0,    46,    52,   127,
       4,    13,    23,    30,     0,    29,    60,    60,   125,     0,
      34,     0,     0,     0,     0,    63,    47,    53,    31,   127,
      32,   126,   124,     0,     0,   104,     0,     0,    38,    35,
      36,    37,    39,   112,    41,    40,   114,   115,    42,    28,
     123,    26,    66,     0,    62,    64,     0,     0,    33,     0,
       0,     0,   113,     0,    98,     0,     0,   108,    84,    85,
      86,    92,    93,   102,   110,   107,    50,     0,    59,    67,
       0,     6,     0,     0,   119,     0,   118,   105,     0,    90,
      91,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    77,     0,     0,     0,    57,   100,    97,   101,     0,
       0,    43,    45,    69,    27,    61,    19,     0,    18,    48,
      54,   120,   116,     0,     0,    99,     0,    87,    88,    89,
      80,    81,    82,    83,    78,    79,    94,    95,    96,    72,
     111,   103,    44,    72,    51,     0,     0,     0,     0,   117,
       0,   109,     0,    70,     0,     0,    17,    65,    49,     6,
     106,    58,    73,    68,    55,    76,     0,    72,    74,    56,
      75
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    14,    15,    16,    18,    19,    28,    29,
      30,   147,   148,    22,    25,    34,    35,    36,   107,    44,
      45,    68,    49,    60,    50,    69,    70,   106,   141,    31,
      46,    86,   177,   142,   143,    32,    47,    87,   178,   196,
     136,   169,    56,    83,    84,   110,    85,   174,   182,   183,
     184,   195,   198,   114,   131,    98,    99,   100,   101,   102,
     137,   138,   172,    71,    91,   154,    72,    73,   121,   105,
     139,    74,    75,    76,   115,   116,    77,     8,    81,   103,
      51,    52
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -137
static const yytype_int16 yypact[] =
{
    -137,    11,    28,  -137,    15,    39,    64,  -137,    13,    66,
      65,    45,  -137,    67,    72,    71,  -137,  -137,    60,  -137,
    -137,  -137,    37,    67,  -137,  -137,    69,    73,    75,    37,
    -137,  -137,  -137,  -137,    76,  -137,    77,  -137,  -137,    74,
    -137,  -137,  -137,  -137,     1,  -137,    84,    84,  -137,    81,
      86,    87,     0,    77,    83,    59,  -137,  -137,  -137,    74,
    -137,  -137,  -137,    90,    93,  -137,    74,     4,  -137,  -137,
    -137,  -137,  -137,    61,  -137,  -137,  -137,  -137,  -137,  -137,
    -137,  -137,  -137,     7,  -137,  -137,    91,    92,  -137,    88,
       4,     4,  -137,     4,  -137,    25,    25,  -137,    21,  -137,
      36,  -137,  -137,    98,  -137,  -137,    89,    99,  -137,    95,
      96,    45,    83,   100,  -137,    70,  -137,  -137,   103,    36,
      36,    78,    25,    25,    25,     4,     4,     4,     4,     4,
       4,  -137,    25,    25,    25,  -137,  -137,  -137,  -137,     0,
       4,  -137,  -137,   106,  -137,  -137,  -137,    18,  -137,  -137,
    -137,  -137,  -137,     4,    80,  -137,     0,    36,    36,    36,
      42,    42,    42,    42,    42,    42,  -137,  -137,  -137,   107,
    -137,  -137,  -137,   107,  -137,    96,    83,   109,   110,  -137,
       0,  -137,   108,  -137,     4,   114,  -137,  -137,  -137,    45,
    -137,  -137,  -137,  -137,  -137,   115,   113,  -137,  -137,  -137,
    -137
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -137,  -137,  -137,  -109,  -137,  -137,  -137,   101,  -137,  -137,
      85,  -137,   -53,  -137,  -137,  -137,    97,  -137,  -137,  -137,
      79,   102,    68,  -137,  -137,  -136,  -137,  -137,  -137,  -137,
    -137,  -137,  -137,  -137,  -137,  -137,  -137,  -137,  -137,  -137,
    -137,  -137,    82,  -137,    14,  -137,  -137,  -137,   -48,   -71,
    -137,  -137,  -137,   -66,  -137,   -74,  -137,   -90,  -137,   -69,
    -137,  -137,  -137,  -137,  -137,  -137,  -137,  -137,  -137,  -137,
    -137,  -137,  -137,  -137,  -137,   -20,  -137,  -137,  -108,   -52,
      94,  -137
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -72
static const yytype_int16 yytable[] =
{
      78,    97,   149,   170,   150,   119,   120,    53,    93,    54,
      39,     3,   108,    62,   109,    63,    64,    62,     9,    10,
     181,    94,    95,    96,   175,   117,   176,   118,     5,    93,
      65,     4,   157,   158,   159,    66,    67,   113,    62,   122,
     123,   124,    94,     6,   190,   125,   126,   127,   128,   129,
     130,   160,   161,   162,   163,   164,   165,   132,   133,   134,
     122,   123,   124,   166,   167,   168,    23,    24,   187,    26,
      27,    82,   -67,    11,   171,   152,   153,     7,    12,    13,
     194,    20,    37,    21,    17,    39,    38,    78,    55,   -25,
      43,    48,    58,    59,    89,    61,    80,    90,   111,   104,
     112,    62,   135,   140,    78,   151,   144,    82,   155,   146,
     173,   180,   -71,   191,    41,   156,   188,   189,   192,   193,
     199,   197,   186,   145,    33,   185,   200,    88,    78,    57,
      40,    42,    79,   179,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      92
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-137))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      52,    67,   111,   139,   112,    95,    96,     6,     4,     8,
      10,     0,     5,    13,     7,    15,    16,    13,     5,     6,
     156,    17,    18,    19,     6,    91,     8,    93,    13,     4,
      30,     3,   122,   123,   124,    35,    36,    89,    13,    18,
      19,    20,    17,     4,   180,    24,    25,    26,    27,    28,
      29,   125,   126,   127,   128,   129,   130,    21,    22,    23,
      18,    19,    20,   132,   133,   134,     6,     7,   176,    32,
      33,    12,    13,     7,   140,     5,     6,    13,    13,    34,
     189,     9,    13,    12,    17,    10,    13,   139,     4,    13,
      13,    17,    11,     7,     4,     8,    13,     4,     7,    38,
       8,    13,     4,    14,   156,     5,     7,    12,     5,    13,
       4,    31,     5,     5,    29,    37,     7,     7,   184,     5,
       7,     6,   175,   109,    23,   173,   197,    59,   180,    47,
      28,    34,    53,   153,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      66
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    41,    42,     0,     3,    13,     4,    13,   117,     5,
       6,     7,    13,    34,    43,    44,    45,    17,    46,    47,
       9,    12,    53,     6,     7,    54,    32,    33,    48,    49,
      50,    69,    75,    47,    55,    56,    57,    13,    13,    10,
      61,    50,    56,    13,    59,    60,    70,    76,    17,    62,
      64,   120,   121,     6,     8,     4,    82,    82,    11,     7,
      63,     8,    13,    15,    16,    30,    35,    36,    61,    65,
      66,   103,   106,   107,   111,   112,   113,   116,   119,    60,
      13,   118,    12,    83,    84,    86,    71,    77,    62,     4,
       4,   104,   120,     4,    17,    18,    19,    93,    95,    96,
      97,    98,    99,   119,    38,   109,    67,    58,     5,     7,
      85,     7,     8,   119,    93,   114,   115,    93,    93,    97,
      97,   108,    18,    19,    20,    24,    25,    26,    27,    28,
      29,    94,    21,    22,    23,     4,    80,   100,   101,   110,
      14,    68,    73,    74,     7,    84,    13,    51,    52,    43,
     118,     5,     5,     6,   105,     5,    37,    97,    97,    97,
      95,    95,    95,    95,    95,    95,    99,    99,    99,    81,
      65,    93,   102,     4,    87,     6,     8,    72,    78,   115,
      31,    65,    88,    89,    90,    88,    52,   118,     7,     7,
      65,     5,    93,     5,    43,    91,    79,     6,    92,     7,
      89
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
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


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
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

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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

/* Line 1806 of yacc.c  */
#line 31 "compilador.y"
    { 
             geraCodigo (NULL, "INPP");
             nivel_lexico=0;
             }
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 37 "compilador.y"
    {
             geraCodigo (NULL, "PARA"); 
             }
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 47 "compilador.y"
    {
                  val = limpaTS();
                  if(val>0){
                     sprintf(s,"DMEM %d",val);
                     geraCodigo(NULL,s);
                  }
               }
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 65 "compilador.y"
    {
                  checaRepTS(token);
                  Attribute *attribute = malloc(sizeof(Attribute));
                  attribute -> Label.nl = nivel_lexico;
                  criaRotuloSingle();
                  sprintf(attribute -> Label.rot,"%s",last_single_rot -> abre);
                  insereTS(token,CAT_LABEL, attribute);
	}
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 89 "compilador.y"
    {   //arrumar <---
                  checaRepTS(token);
                  Attribute *attribute = malloc(sizeof(Attribute));
                  attribute -> PF.nl = nivel_lexico;
                  attribute -> PF.vr = var_ref;//transfere pf para proc na ts
                  tabela.celulas[ultimoProcTS()] -> attribute -> Proc.np++;
                  insereTS(token,CAT_PF, attribute);
                  num_vars++;
          }
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 99 "compilador.y"
    {desloc=0;}
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 107 "compilador.y"
    {num_vars = 0;}
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 110 "compilador.y"
    { 
                  if(!strcmp(token,"integer")){
                  insereTipoTS(num_vars,TIPO_INT);
                  }else{
                     imprimeErro("Tipo incorreto");
                  }
                  sprintf(s,"AMEM %d",num_vars);
                  geraCodigo(NULL,s);
              }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 127 "compilador.y"
    {   
                  checaRepTS(token);
                  num_vars++;
                  Attribute *attribute = malloc(sizeof(Attribute));
                  attribute -> VS.nl = nivel_lexico;
                  attribute -> VS.desl = desloc++;
                  insereTS(token,CAT_VS, attribute);
          }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 159 "compilador.y"
    {l_element = ind_element;}
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 173 "compilador.y"
    {
         
            criaRotuloSingle();
            empilhaRotuloSingle();
            sprintf(s,"DSVS %s",last_single_rot -> abre);
            geraCodigo(NULL,s);
            nivel_lexico++;
            checaRepTS(token);

            /*Inserindo variavel na tabela */
            Attribute *attribute = malloc(sizeof(Attribute));
            attribute -> Proc.nl = nivel_lexico;
            attribute -> Proc.np = 0;

            criaRotuloSingle();
            sprintf(attribute -> Proc.rot,"%s",last_single_rot -> abre);
            insereTS(token,CAT_PROC, attribute); //fix.

            sprintf(s,"ENPR %d",nivel_lexico);
            geraCodigo(last_single_rot -> abre,s);
            
         
         }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 197 "compilador.y"
    {
            atualizaProcTS();
	 }
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 202 "compilador.y"
    {
            sprintf(s,"RTPR %d, %d", nivel_lexico, tabela.celulas[ultimoProcTS()] -> attribute -> Proc.np);
            geraCodigo(NULL,s);
            geraCodigo(rotulos.last -> abre,"NADA");
            destroiRotulo();
            nivel_lexico--;
         }
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 215 "compilador.y"
    {
               l_element=ind_element;
               if(tabela.celulas[l_element] -> categoria != CAT_PROC){
                  sprintf(s,"A variável %s não é um procedimento",token);
                  imprimeErro(s);
               }
               empilhaValor(l_element);
               num_par=0;
            }
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 225 "compilador.y"
    {
               if(num_par != tabela.celulas[topo_val -> val] -> attribute -> Proc.np)
                  imprimeErro("Numero incorreto de parametros");
               desempilhaValor();
//               sprintf(s,"CHPR %s, %d",tabela.celulas[l_element] -> attribute -> Proc.rot,tabela.celulas[l_element] -> attribute -> Proc.np);
               sprintf(s,"CHPR %s, %d",tabela.celulas[l_element] -> attribute -> Proc.rot,nivel_lexico);
               geraCodigo(NULL,s);
            }
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 240 "compilador.y"
    {
            criaRotuloSingle();
            empilhaRotuloSingle();
            sprintf(s,"DSVS %s",last_single_rot -> abre);
            geraCodigo(NULL,s);
            nivel_lexico++;

            checaRepTS(token);

            /*Inserindo variavel na tabela */ // <-----------
            Attribute *attribute = malloc(sizeof(Attribute));
            attribute -> Func.p.nl = nivel_lexico;
            attribute -> Func.p.np = 0;
	         attribute -> Func.p.tipo_param = malloc(sizeof(int));
	         attribute -> Func.p.pas_param = malloc(sizeof(int));
	         criaRotuloSingle();
            sprintf(attribute -> Func.p.rot,"%s",last_single_rot -> abre);
            insereTS(token,CAT_FUNC, attribute); //fix.

            sprintf(s,"ENPR %d",nivel_lexico);
            geraCodigo(last_single_rot -> abre,s);
         
         }
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 264 "compilador.y"
    {
            atualizaProcTS();
	 }
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 269 "compilador.y"
    {
            if(!strcmp(token,"integer")){
                  atualizaFuncTS(TIPO_INT);
            }else{
                  imprimeErro("Tipo incorreto");
            }
         }
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 278 "compilador.y"
    {
            sprintf(s,"RTPR %d, %d", nivel_lexico, tabela.celulas[ultimoProcTS()] -> attribute -> Proc.np);
            geraCodigo(NULL,s);
            geraCodigo(rotulos.last -> abre,"NADA");
            destroiRotulo();
            nivel_lexico--;
         }
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 288 "compilador.y"
    {
               empilhaValor(ind_element);
               if(tabela.celulas[topo_val -> val] -> categoria != CAT_FUNC){
                  sprintf(s,"A variável %s não eh uma funcao",token);
                  imprimeErro(s);
               }
               num_par=0;
               geraCodigo(NULL,"AMEM 1");
               empilhaTipo(tabela.celulas[topo_val -> val] -> attribute -> Func.vs.tipo);
            }
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 299 "compilador.y"
    {
               if(num_par != tabela.celulas[topo_val -> val] -> attribute -> Proc.np)
                  imprimeErro("Numero incorreto de parametros");
               sprintf(s,"CHPR %s, %d",tabela.celulas[topo_val -> val] -> attribute -> Proc.rot,nivel_lexico);
               desempilhaValor();
               geraCodigo(NULL,s);
            }
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 322 "compilador.y"
    {num_vars=0;}
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 324 "compilador.y"
    {
                               if(!strcmp(token,"integer")){
                               insereTipoTS(num_vars,TIPO_INT);
                               }else{
                                  imprimeErro("Tipo incorreto");
                               }
                             }
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 333 "compilador.y"
    {var_ref=PF_REF;}
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 334 "compilador.y"
    {var_ref=PF_VAL;}
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 349 "compilador.y"
    {
                             pas_param = tabela.celulas[topo_val -> val] -> attribute -> Proc.pas_param[num_par];
                             
                             }
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 352 "compilador.y"
    {
                             if(desempilhaTipo() != tabela.celulas[topo_val -> val] -> attribute -> Proc.tipo_param[num_par])
                                imprimeErro("Erro no tipo da passagem de parametros");
                             num_par++;
                             }
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 370 "compilador.y"
    {geraCodigo(NULL,"CMIG");checaTipo(TIPO_INT,TIPO_BOOL);}
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 371 "compilador.y"
    {geraCodigo(NULL,"CMDG");checaTipo(TIPO_INT,TIPO_BOOL);}
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 372 "compilador.y"
    {geraCodigo(NULL,"CMMA");checaTipo(TIPO_INT,TIPO_BOOL);}
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 373 "compilador.y"
    {geraCodigo(NULL,"CMME");checaTipo(TIPO_INT,TIPO_BOOL);}
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 374 "compilador.y"
    {geraCodigo(NULL,"CMAG");checaTipo(TIPO_INT,TIPO_BOOL);}
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 375 "compilador.y"
    {geraCodigo(NULL,"CMEG");checaTipo(TIPO_INT,TIPO_BOOL);}
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 380 "compilador.y"
    {
          if(topo_val && pas_param==PF_REF)
            imprimeErro("Erro na passagem de parametros");
       }
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 385 "compilador.y"
    {geraCodigo(NULL,"SOMA");checaTipo(TIPO_INT,TIPO_INT);}
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 386 "compilador.y"
    {geraCodigo(NULL,"SUBT");checaTipo(TIPO_INT,TIPO_INT);}
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 387 "compilador.y"
    {geraCodigo(NULL,"DISJ");checaTipo(TIPO_BOOL,TIPO_BOOL);}
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 390 "compilador.y"
    {geraCodigo(NULL,"INVR");}
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 394 "compilador.y"
    {
          if(topo_val && pas_param==PF_REF)
            imprimeErro("Erro na passagem de parametros");
       }
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 399 "compilador.y"
    {geraCodigo(NULL,"MULT");checaTipo(TIPO_INT,TIPO_INT);}
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 400 "compilador.y"
    {geraCodigo(NULL,"DIVI");checaTipo(TIPO_INT,TIPO_INT);}
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 401 "compilador.y"
    {geraCodigo(NULL,"CONJ");checaTipo(TIPO_BOOL,TIPO_BOOL);}
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 405 "compilador.y"
    {
      if(topo_val && pas_param==PF_REF)
         imprimeErro("Erro na passagem de parametros");
      sprintf(s, "CRCT %s",token);
      geraCodigo(NULL,s);
      empilhaTipo(TIPO_INT);
   }
    break;

  case 102:

/* Line 1806 of yacc.c  */
#line 417 "compilador.y"
    {


      if(topo_val){//dentro da passagem de parametros

         if(pas_param == PF_VAL){
             handleNormalExpression(ind_element);
         }else{ //passagem por referencia, só pode ter uma variavel
            if(tabela.celulas[ind_element] -> categoria == CAT_PF &&
               tabela.celulas[ind_element] -> attribute -> PF.vr == PF_REF){
                  sprintf(s,"CRVL %d, %d",tabela.celulas[ind_element] -> attribute -> VS.nl,tabela.celulas[ind_element] -> attribute -> VS.desl);
            }else{
                  sprintf(s,"CREN %d, %d",tabela.celulas[ind_element] -> attribute -> VS.nl,tabela.celulas[ind_element] -> attribute -> VS.desl);
            }
            geraCodigo(NULL,s);
            empilhaTipo(tabela.celulas[ind_element] -> attribute -> VS.tipo);
         }
      } else {//fora da passagem de parametros
           handleNormalExpression(ind_element);
        }

   }
    break;

  case 103:

/* Line 1806 of yacc.c  */
#line 447 "compilador.y"
    {
          VarSimples *vs;
          switch(tabela.celulas[l_element] -> categoria){
          case CAT_VS:
             vs = &(tabela.celulas[l_element] -> attribute -> VS);
             sprintf(s, "ARMZ %d, %d",vs -> nl, vs -> desl);
             break;
          case CAT_FUNC:
             if(ultimoProcTS()!=l_element)
                imprimeErro("Variavel incorreta no lado esquerdo da atribuicao");
             vs = &(tabela.celulas[l_element] -> attribute -> Func.vs);
             sprintf(s, "ARMZ %d, %d",vs -> nl, vs -> desl);
             break;
          case CAT_PF:
             if(tabela.celulas[l_element] -> attribute -> PF.vr == PF_VAL){
                sprintf(s,"A variavel %s nao pode ser atribuida, pois foi passada como valor",tabela.celulas[l_element] -> ident);
                imprimeErro(s);
             }
             sprintf(s, "ARMI %d, %d",tabela.celulas[l_element] -> attribute -> PF.nl,tabela.celulas[l_element] -> attribute -> PF.desl);
             break;
          default:
             sprintf(s,"Categoria incorreta para atribuicao na variavel %s",tabela.celulas[l_element] -> ident);
             imprimeErro(s);
          }
          if(desempilhaTipo() != vs -> tipo)
                 imprimeErro("Atribuição de tipos diferentes");
          geraCodigo(NULL,s);
       }
    break;

  case 104:

/* Line 1806 of yacc.c  */
#line 481 "compilador.y"
    {
            criaRotulo();
            geraCodigo(rotulos.last->abre,"NADA");
           }
    break;

  case 105:

/* Line 1806 of yacc.c  */
#line 484 "compilador.y"
    {//checa se é expressão booleana?
            if(desempilhaTipo() != 1){
               imprimeErro("Expressão não booleana");
            }
            sprintf(s,"DSVF %s", rotulos.last -> fecha);
            geraCodigo(NULL,s);


           }
    break;

  case 106:

/* Line 1806 of yacc.c  */
#line 492 "compilador.y"
    {
            sprintf(s,"DSVS %s", rotulos.last -> abre);
            geraCodigo(NULL,s);
            geraCodigo(rotulos.last -> fecha,"NADA");
            destroiRotulo();
         }
    break;

  case 107:

/* Line 1806 of yacc.c  */
#line 505 "compilador.y"
    {
            geraCodigo(rotulos.last->fecha,"NADA");
            destroiRotulo();
         }
    break;

  case 108:

/* Line 1806 of yacc.c  */
#line 513 "compilador.y"
    {
            if(desempilhaTipo() != 1){
               imprimeErro("Expressão não booleana");
            }
            criaRotulo();
            sprintf(s,"DSVF %s", rotulos.last -> abre);
            geraCodigo(NULL,s);
            
         }
    break;

  case 109:

/* Line 1806 of yacc.c  */
#line 523 "compilador.y"
    {
            sprintf(s,"DSVS %s", rotulos.last -> fecha);
            geraCodigo(NULL,s);
            geraCodigo(rotulos.last->abre,"NADA");
         }
    break;

  case 110:

/* Line 1806 of yacc.c  */
#line 529 "compilador.y"
    {
         }
    break;

  case 113:

/* Line 1806 of yacc.c  */
#line 539 "compilador.y"
    {
        sprintf(s,"DSVR %s, %d, %d",tabela.celulas[ind_element] -> attribute -> Label.rot,
                                    tabela.celulas[ind_element] -> attribute -> Label.nl,
                                    nivel_lexico);
        geraCodigo(NULL,s);
     }
    break;

  case 119:

/* Line 1806 of yacc.c  */
#line 561 "compilador.y"
    {
         geraCodigo(NULL,"IMPR");
         desempilhaTipo();
      }
    break;

  case 120:

/* Line 1806 of yacc.c  */
#line 568 "compilador.y"
    {
         geraCodigo(NULL,"LEIT");
         sprintf(s,"ARMZ %d, %d",tabela.celulas[ind_element] -> attribute -> VS.nl,tabela.celulas[ind_element] -> attribute -> VS.desl);
         geraCodigo(NULL,s);      

      }
    break;

  case 124:

/* Line 1806 of yacc.c  */
#line 585 "compilador.y"
    {
      if((ind_element = buscaTS(token)) < 0){
            sprintf(s,"A variável %s não foi declarada",token);
            imprimeErro(s);      
      }
   }
    break;

  case 125:

/* Line 1806 of yacc.c  */
#line 593 "compilador.y"
    {
        if((ind_element = buscaTS(token)) < 0){
              sprintf(s,"O rotulo %s nao foi declarado",token);
              imprimeErro(s);      
        }
        if(tabela.celulas[ind_element] -> categoria != CAT_LABEL)
           imprimeErro("Rotulo invalido");
       }
    break;

  case 126:

/* Line 1806 of yacc.c  */
#line 604 "compilador.y"
    {
               sprintf(s,"ENRT %d, %d",nivel_lexico,numeroVSTS());
               geraCodigo(tabela.celulas[ind_element] -> attribute -> Label.rot,s);

            }
    break;



/* Line 1806 of yacc.c  */
#line 2272 "compilador.tab.c"
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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



/* Line 2067 of yacc.c  */
#line 613 "compilador.y"

void yyerror (char *s) {
    fprintf (stderr, "%s\n", s);
}
main (int argc, char** argv) {
   FILE* fp;
   extern FILE* yyin;

   if (argc<2 || argc>2) {
         printf("usage compilador <arq>a %d\n", argc);
         return(-1);
      }

   fp=fopen (argv[1], "r");
   if (fp == NULL) {
      printf("usage compilador <arq>b\n");
      return(-1);
   }


/* -------------------------------------------------------------------
 *  Inicia a Tabela de Símbolos
 * ------------------------------------------------------------------- */
   iniciaTS();
   iniciaPilhas();
   yyin=fp;
   yyparse();
   return 0;
}


