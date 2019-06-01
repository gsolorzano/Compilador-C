/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.3.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser-bison.y" /* yacc.c:337  */

# include <stdio.h>
# include <stdlib.h>
#include "stackC.h"
#include "symbolTable.h"
#include "symbolStack.h"
int errores = 0;
extern int yylineno;
extern FILE *fileOut;
extern int beamer;
extern char linea[700];
extern int conteo;
extern char *yytext;
extern char idActual[200];

int as = 0;


char temporal[200];
int tempAct = 0;

int numContxt = 1;

enum tok{ID, TIPO, ERROR, DATAO, TOKEN};
struct semantic_record* pila = NULL;

struct symbolT* symbolTable = NULL;

struct tableRegister* symbolStck = NULL;

#line 101 "parser-bison.tab.c" /* yacc.c:337  */
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser-bison.tab.h".  */
#ifndef YY_YY_PARSER_BISON_TAB_H_INCLUDED
# define YY_YY_PARSER_BISON_TAB_H_INCLUDED
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
    IDENTIFIER = 258,
    CONSTANT = 259,
    STRING_LITERAL = 260,
    SIZEOF = 261,
    PTR_OP = 262,
    INC_OP = 263,
    DEC_OP = 264,
    LEFT_OP = 265,
    RIGHT_OP = 266,
    LE_OP = 267,
    GE_OP = 268,
    EQ_OP = 269,
    NE_OP = 270,
    AND_OP = 271,
    OR_OP = 272,
    MUL_ASSIGN = 273,
    DIV_ASSIGN = 274,
    MOD_ASSIGN = 275,
    ADD_ASSIGN = 276,
    SUB_ASSIGN = 277,
    LEFT_ASSIGN = 278,
    RIGHT_ASSIGN = 279,
    AND_ASSIGN = 280,
    XOR_ASSIGN = 281,
    OR_ASSIGN = 282,
    TYPE_NAME = 283,
    TYPEDEF = 284,
    EXTERN = 285,
    STATIC = 286,
    AUTO = 287,
    REGISTER = 288,
    INLINE = 289,
    RESTRICT = 290,
    CHAR = 291,
    SHORT = 292,
    INT = 293,
    LONG = 294,
    SIGNED = 295,
    UNSIGNED = 296,
    FLOAT = 297,
    DOUBLE = 298,
    CONST = 299,
    VOLATILE = 300,
    VOID = 301,
    BOOL = 302,
    COMPLEX = 303,
    IMAGINARY = 304,
    STRUCT = 305,
    UNION = 306,
    ENUM = 307,
    ELLIPSIS = 308,
    CASE = 309,
    DEFAULT = 310,
    IF = 311,
    ELSE = 312,
    SWITCH = 313,
    WHILE = 314,
    DO = 315,
    FOR = 316,
    GOTO = 317,
    CONTINUE = 318,
    BREAK = 319,
    RETURN = 320
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_BISON_TAB_H_INCLUDED  */



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
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
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
#  define YYSIZE_T unsigned
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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


#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

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
# define YYCOPY_NEEDED 1
#endif


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
#define YYFINAL  56
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2218

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  90
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  89
/* YYNRULES -- Number of rules.  */
#define YYNRULES  267
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  433

#define YYUNDEFTOK  2
#define YYMAXUTOK   320

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    78,     2,     2,     2,    80,    73,     2,
      66,    89,    74,    75,    72,    76,    69,    79,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    86,    88,
      81,    87,    82,    85,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    67,     2,    68,    83,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    70,    84,    71,    77,     2,     2,     2,
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
      65
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    51,    51,    52,    53,    54,    55,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    72,    73,    77,
      78,    78,    79,    79,    80,    81,    82,    86,    87,    88,
      89,    90,    91,    92,    96,    97,   101,   102,   102,   103,
     103,   104,   104,   108,   109,   109,   110,   110,   114,   115,
     116,   120,   121,   122,   123,   124,   128,   129,   130,   134,
     135,   139,   140,   144,   145,   149,   150,   154,   155,   159,
     160,   160,   160,   160,   160,   164,   165,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   184,
     185,   189,   193,   194,   201,   202,   203,   204,   205,   206,
     207,   208,   212,   213,   217,   218,   218,   222,   223,   224,
     225,   226,   227,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   250,
     251,   252,   256,   257,   258,   262,   263,   267,   271,   272,
     273,   274,   278,   279,   283,   284,   285,   289,   290,   291,
     292,   293,   297,   298,   302,   303,   307,   308,   309,   310,
     314,   319,   320,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   341,   342,   343,   344,
     348,   349,   354,   355,   359,   360,   364,   365,   366,   370,
     371,   375,   376,   380,   381,   382,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   400,   401,   402,
     406,   407,   408,   409,   413,   417,   418,   422,   423,   427,
     428,   429,   430,   431,   432,   436,   437,   438,   442,   442,
     443,   443,   447,   448,   452,   453,   457,   458,   462,   462,
     462,   464,   468,   468,   468,   469,   473,   474,   478,   479,
     480,   481,   482,   483,   487,   488,   489,   490,   491,   492,
     496,   497,   501,   502,   506,   507,   511,   512
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "CONSTANT",
  "STRING_LITERAL", "SIZEOF", "PTR_OP", "INC_OP", "DEC_OP", "LEFT_OP",
  "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP", "OR_OP",
  "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN",
  "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN",
  "TYPE_NAME", "TYPEDEF", "EXTERN", "STATIC", "AUTO", "REGISTER", "INLINE",
  "RESTRICT", "CHAR", "SHORT", "INT", "LONG", "SIGNED", "UNSIGNED",
  "FLOAT", "DOUBLE", "CONST", "VOLATILE", "VOID", "BOOL", "COMPLEX",
  "IMAGINARY", "STRUCT", "UNION", "ENUM", "ELLIPSIS", "CASE", "DEFAULT",
  "IF", "ELSE", "SWITCH", "WHILE", "DO", "FOR", "GOTO", "CONTINUE",
  "BREAK", "RETURN", "'('", "'['", "']'", "'.'", "'{'", "'}'", "','",
  "'&'", "'*'", "'+'", "'-'", "'~'", "'!'", "'/'", "'%'", "'<'", "'>'",
  "'^'", "'|'", "'?'", "':'", "'='", "';'", "')'", "$accept",
  "primary_expression", "postfix_expression", "argument_expression_list",
  "unary_expression", "$@1", "$@2", "unary_operator", "cast_expression",
  "multiplicative_expression", "$@3", "$@4", "$@5", "additive_expression",
  "$@6", "$@7", "shift_expression", "relational_expression",
  "equality_expression", "and_expression", "exclusive_or_expression",
  "inclusive_or_expression", "logical_and_expression",
  "logical_or_expression", "conditional_expression", "$@8", "$@9", "$@10",
  "$@11", "assignment_expression", "assignment_operator", "expression",
  "constant_expression", "declaration", "declaration_specifiers",
  "init_declarator_list", "init_declarator", "$@12",
  "storage_class_specifier", "type_specifier", "struct_or_union_specifier",
  "struct_or_union", "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "type_qualifier", "function_specifier", "declarator",
  "direct_declarator", "pointer", "type_qualifier_list",
  "parameter_type_list", "parameter_list", "parameter_declaration",
  "identifier_list", "type_name", "abstract_declarator",
  "direct_abstract_declarator", "initializer", "initializer_list",
  "designation", "designator_list", "designator", "statement",
  "labeled_statement", "compound_statement", "$@13", "$@14",
  "block_item_list", "block_item", "expression_statement",
  "selection_statement", "$@15", "$@16", "optionsIF", "$@17", "$@18",
  "rparen", "iteration_statement", "jump_statement", "translation_unit",
  "external_declaration", "function_definition", "declaration_list", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,    40,    91,    93,    46,
     123,   125,    44,    38,    42,    43,    45,   126,    33,    47,
      37,    60,    62,    94,   124,    63,    58,    61,    59,    41
};
# endif

#define YYPACT_NINF -336

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-336)))

#define YYTABLE_NINF -260

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    2141,   -30,  -336,  -336,  -336,  -336,  -336,  -336,  -336,  -336,
    -336,  -336,  -336,  -336,  -336,  -336,  -336,  -336,  -336,  -336,
    -336,  -336,  -336,  -336,  -336,  -336,    46,  -336,    61,   401,
     463,  -336,    58,  -336,   525,   587,  2063,  -336,  -336,    -7,
      47,  -336,   133,    35,  -336,   -45,  -336,  1249,   -38,    68,
    -336,  -336,     6,  2166,  -336,  -336,  -336,  -336,    47,   -15,
      60,  -336,    14,  -336,  -336,  -336,   960,   133,  -336,    51,
    -336,  -336,    61,  -336,  2010,   773,   980,   -38,  2166,   -30,
     853,   346,  -336,    32,   908,   131,  1652,  -336,    21,  -336,
    -336,  -336,  -336,  -336,  -336,    57,    70,  1110,  1593,  -336,
    -336,   152,  -336,   101,    14,    97,  -336,    19,  -336,  1399,
    -336,  -336,  -336,  1697,  -336,  -336,   169,  1463,  -336,  -336,
     103,  -336,  -336,  -336,  -336,  -336,   306,   339,  1652,  -336,
     200,   171,   239,    77,   246,   108,   122,   136,   199,     2,
    -336,   149,  1515,  1709,  -336,  -336,  -336,  1652,   -42,  -336,
     141,  -336,  -336,    34,   157,  -336,  -336,  -336,  -336,  -336,
    -336,  -336,  1844,   144,  1652,   146,  -336,   177,   191,  1301,
     196,   234,   180,   190,  1266,  -336,  -336,    84,  -336,  -336,
    -336,  -336,  1032,  -336,  -336,  -336,  -336,  -336,  1478,  -336,
    -336,   649,  1606,  -336,    71,  -336,   205,  -336,  2088,   283,
    -336,  1463,  -336,  1730,  1730,  1560,  1958,    40,   178,    14,
    -336,   287,  -336,  -336,   925,  1652,   295,  -336,  -336,  -336,
    -336,  -336,  -336,  -336,  -336,  -336,  -336,  -336,  -336,  1652,
    -336,  -336,  -336,  -336,  -336,  -336,  1652,  1652,  1652,  1652,
    1652,  1652,  1652,  1652,  1652,  1652,  1652,  1652,  1652,   227,
    -336,  1652,  -336,   248,   261,  -336,  -336,    32,  -336,  1652,
    -336,  1301,   244,  1301,   266,  1652,  1652,  1781,   275,  1188,
     250,  -336,  -336,  -336,    94,  1652,  -336,  -336,  -336,  1652,
     333,  -336,   204,  1593,    86,  -336,    14,    14,  -336,  -336,
     273,   274,   205,   798,  1619,  -336,  -336,  -336,    14,  1463,
    -336,  -336,   277,  -336,   711,   218,  -336,  1638,  -336,  1377,
      54,  -336,  -336,    13,  -336,  -336,  1652,  1652,  1652,  1652,
    1652,   171,   171,   239,   239,   239,   239,    77,    77,   246,
     108,   122,   136,   199,  1652,   299,  -336,  -336,  -336,  -336,
    -336,  1301,  -336,  1652,    40,    40,   303,  1907,  1319,  1319,
    -336,  -336,  -336,   302,  -336,  -336,   659,  -336,  -336,  -336,
    -336,  -336,  -336,  -336,    14,  -336,  -336,   309,   310,   301,
      14,  -336,  1478,  -336,  1652,  -336,  -336,  -336,  -336,  -336,
     200,   200,   307,  -336,  -336,    40,  1301,  1301,  1652,   925,
     925,  -336,  -336,  -336,  1593,  -336,  -336,  -336,   301,   229,
    -336,   313,  -336,  -336,  -336,    40,    40,  1301,    40,  1301,
    -336,  -336,  1344,  -336,  1301,   312,  1301,  -336,  1301,  -336,
    -336,  1652,   344,  -336,  -336,  -336,  -336,  -336,   348,  -336,
    -336,  1301,  -336
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,   112,   127,   107,   108,   109,   110,   111,   160,   157,
     114,   115,   116,   117,   120,   121,   118,   119,   156,   158,
     113,   122,   123,   124,   132,   133,     0,   263,     0,     0,
       0,   125,     0,   126,     0,     0,     0,   260,   262,   151,
       0,   163,     0,     0,    92,     0,   102,     0,   162,     0,
      95,    97,   131,     0,    99,   101,     1,   261,     0,   154,
       0,   152,     0,   159,   180,   178,     0,     0,    93,   230,
     105,   266,     0,   265,     0,     0,     0,   161,     0,   128,
       0,     0,   135,     0,     0,     0,     0,   147,     0,   247,
     246,   164,   181,   179,   103,   104,     0,     0,     0,   267,
     264,   112,   189,   188,     0,   182,   184,     0,   175,     6,
       2,     3,     4,     0,    20,    22,     0,     0,   172,    27,
      28,    29,    30,    31,    32,     7,    19,     0,     0,    36,
      43,    48,    51,    56,    59,    61,    63,    65,    67,    69,
      75,     0,     0,     0,   138,   130,   136,     0,     0,   142,
     144,   140,   148,     0,     6,    28,    34,    91,   155,   149,
     153,   229,     6,     2,     0,     0,   238,     0,     0,     0,
       0,     0,     0,     0,     0,   236,    89,     0,   234,   235,
     219,   220,     0,   232,   221,   222,   223,   224,     0,   207,
     106,     0,     0,   186,   193,   187,   194,   173,     0,     0,
     174,     0,    25,     0,     0,     0,     6,     0,   191,     0,
     171,     0,    13,    14,     0,     0,     0,    88,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    77,     0,
      24,    37,    39,    41,    44,    46,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     167,     0,   166,    28,     0,   129,   145,     0,   137,     0,
     150,     0,     0,     0,     0,     0,     0,     6,     0,     0,
       0,   255,   256,   257,     0,     0,   237,   231,   233,     0,
       0,   210,     0,     0,     0,   215,     0,     0,   203,   197,
      28,     0,   195,     0,     0,   183,   185,   190,     0,     0,
      21,    23,     0,     5,     0,   193,   192,     0,    12,     6,
       0,    17,     9,     0,    11,    76,     0,     0,     0,     0,
       0,    49,    50,    54,    55,    52,    53,    57,    58,    60,
      62,    64,    66,    68,     0,     0,   170,   165,   143,   146,
     225,     0,   227,     0,     0,     0,     0,     6,     0,     0,
     254,   258,    90,     0,   218,   208,     0,   211,   214,   216,
     204,   196,   201,   198,     0,   205,   199,    28,     0,    26,
       0,   168,     0,    35,     0,    10,     8,    38,    40,    42,
      45,    47,    71,   169,   226,     0,     0,     0,     0,     0,
       0,   217,   209,   212,     0,   206,   202,   200,     0,     0,
      18,     0,   239,   241,   248,     0,     0,     0,     0,     0,
     213,    15,     0,    72,     0,     0,     0,   252,     0,   250,
      16,     0,   245,   240,   249,   253,   251,    73,     0,    74,
     243,     0,   244
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -336,  -336,  -336,  -336,   -53,  -336,  -336,  -336,  -106,   -14,
    -336,  -336,  -336,    73,  -336,  -336,    55,    78,   159,   161,
     162,   207,   168,  -336,   -82,  -336,  -336,  -336,  -336,   -75,
    -336,  -101,  -139,   -40,    18,  -336,   342,  -336,  -336,   -22,
    -336,  -336,   377,     3,   -78,  -336,   201,  -336,   398,   -20,
     175,  -336,    16,   -46,   -34,   -50,   -70,  -336,   259,  -336,
    -189,   -93,  -180,   -87,    87,  -335,  -336,   176,   -83,  -336,
       4,  -336,  -336,  -336,   279,  -252,  -336,  -336,  -336,  -336,
    -336,  -336,   -62,  -336,  -336,  -336,   426,  -336,  -336
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   125,   126,   310,   127,   203,   204,   128,   129,   130,
     316,   317,   318,   131,   319,   320,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   249,   401,   421,   429,   176,
     229,   177,   158,    27,    72,    45,    46,    98,    29,    30,
      31,    32,    81,    82,    83,   148,   149,    33,    60,    61,
      34,    35,    62,    48,    49,    66,   286,   105,   106,   107,
     209,   287,   196,   281,   282,   283,   284,   285,   179,   180,
     181,    96,    97,   182,   183,   184,   185,   264,   414,   423,
     428,   431,   288,   186,   187,    36,    37,    38,    74
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      91,   141,   144,    77,   157,   104,   151,    71,   256,    65,
     195,   190,   298,   108,   292,    89,   207,   349,    28,   248,
      89,   394,   230,   189,    59,   262,   142,    67,    75,    76,
     257,    80,    93,   156,    99,    41,    63,    59,  -176,   208,
    -134,    89,   197,    68,    47,   200,   258,    50,    51,    39,
      59,    73,    54,    55,    28,    89,    80,   178,    80,    80,
     202,    52,    80,    58,    41,   157,   205,   254,   160,   194,
       9,    41,    86,   274,    41,   156,    78,   394,   100,    18,
      19,   376,   157,    95,   146,   275,   268,   -70,    95,   238,
     239,   199,   159,   103,   156,    80,   389,   390,    42,   150,
     207,  -176,  -176,    90,    41,   260,    43,  -176,    90,    43,
     370,   156,   275,   189,   313,   306,    40,   291,   147,   193,
     339,    80,  -228,   208,  -176,   292,   374,    42,    53,    90,
     302,    87,    88,   160,    42,    43,    41,   191,   192,   311,
     353,   161,   178,    90,    70,   303,   146,   307,    77,    44,
     300,   301,   312,   279,   315,   280,   275,   194,   240,   241,
     -33,   -33,   -33,   -33,   344,   345,   275,   191,   192,   198,
      63,   210,   276,   358,   305,    43,   335,   157,   340,    80,
     342,   244,   351,   156,   156,   156,   156,   156,   156,   156,
     156,   156,   156,   156,   156,   156,   357,   157,   207,    42,
     352,   373,   152,   153,     9,   245,   156,    43,   189,   103,
     377,   378,   379,    18,    19,   247,   103,   250,    64,   368,
     246,   208,  -134,   364,   360,   361,   156,   259,    84,   348,
     261,   365,   263,   382,   -33,   -33,   369,   270,  -247,  -247,
    -247,    92,   385,   265,   304,   192,   234,   235,   375,   236,
     237,    64,    43,    84,   156,    84,    84,   266,   384,    84,
     242,   243,   269,   156,   156,   156,   156,   156,   271,   393,
     305,   293,   294,   150,   231,   355,   356,    80,   272,   232,
     233,   189,   386,   387,   304,   192,   297,   405,   406,   408,
     308,    64,    84,   323,   324,   325,   326,   189,   314,   400,
     411,   412,   395,   403,   404,   380,   381,   410,   398,   321,
     322,   103,   334,   211,   212,   213,   336,    92,    84,   189,
     327,   328,   103,   402,   417,   393,   419,   407,   409,   337,
     341,   422,   343,   425,   346,   426,   354,   189,   350,   427,
     217,   362,   363,   415,   416,   371,   418,    79,   432,   -34,
     -34,   -34,   -34,   -34,   -34,   -34,   -34,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   383,   156,   388,
     391,   372,   214,   215,     2,   216,    84,   396,   397,   275,
      92,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,   413,
     424,  -242,     1,   329,   -94,   430,   330,   -34,   331,    94,
     -34,   -34,   -34,   -34,   -34,   -34,   333,   145,   -34,   -34,
     -34,   -34,   -34,   -34,   -34,   -34,   228,   -34,   -34,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,   332,   143,    85,   296,   338,   399,
     359,   278,    57,     0,     1,     0,   -96,   -94,   -94,     0,
       0,     0,     0,   -94,    84,   -94,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -94,
     -94,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     1,     0,   -98,   -96,
     -96,     0,     0,     0,     0,   -96,     0,   -96,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -96,   -96,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     0,
    -100,   -98,   -98,     0,     0,     0,     0,   -98,     0,   -98,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -98,   -98,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     101,     0,    41,  -100,  -100,     0,     0,     0,     0,  -100,
     154,  -100,   110,   111,   112,   113,     0,   114,   115,     0,
       0,     0,     0,     0,     0,  -100,  -100,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   101,     0,     0,   191,   192,     0,     0,     0,
       0,     0,     0,    43,     0,   117,   279,     0,   280,   188,
     392,     0,   119,   155,   121,   122,   123,   124,    90,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   101,     0,   102,   304,   192,     0,
       0,     0,     0,     0,     0,    43,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   101,
      90,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,     0,     0,     0,    79,     0,  -139,     0,     0,     0,
       0,     0,    90,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     2,     0,     0,     0,     0,     0,    90,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,     0,     0,     0,    79,
       0,  -141,     0,     0,     0,     0,     0,     0,     0,  -139,
    -139,     0,     0,     0,     0,     0,   309,  -139,   110,   111,
     112,   113,     0,   114,   115,     0,     2,     0,     0,  -139,
       0,     0,  -139,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    63,     0,  -177,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -141,  -141,     0,     0,     0,     0,
       0,   109,  -141,   110,   111,   112,   113,     0,   114,   115,
       0,   117,     0,     0,  -141,     9,     0,  -141,   119,   155,
     121,   122,   123,   124,    18,    19,     0,     0,     0,     0,
       0,   116,     0,     0,    90,     9,     0,     0,     0,     0,
       0,     0,     0,     0,    18,    19,  -177,  -177,     0,     0,
       0,     0,  -177,   162,    43,   163,   111,   112,   113,     0,
     114,   115,     0,     0,     0,     0,   117,     0,   118,  -177,
       0,     0,     0,   119,   120,   121,   122,   123,   124,     0,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,     0,   164,   165,   166,     0,
     167,   168,   169,   170,   171,   172,   173,   174,   117,     0,
       0,     0,    69,   277,     0,   119,   155,   121,   122,   123,
     124,   162,     0,   163,   111,   112,   113,     0,   114,   115,
     175,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,     0,   164,   165,   166,     0,   167,   168,
     169,   170,   171,   172,   173,   174,   117,     0,     0,     0,
      69,     0,     0,   119,   155,   121,   122,   123,   124,   347,
       0,   110,   111,   112,   113,     0,   114,   115,   175,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     0,     0,     0,   117,     0,     0,     0,     0,     0,
       0,   119,   155,   121,   122,   123,   124,   154,     0,   110,
     111,   112,   113,     0,   114,   115,   175,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,   267,     0,   163,   111,   112,   113,     0,   114,
     115,     0,     0,     0,     0,     0,     0,     0,     0,    69,
     154,  -104,   110,   111,   112,   113,     0,   114,   115,     0,
       0,     0,   117,     0,     0,     0,    70,  -104,     0,   119,
     155,   121,   122,   123,   124,   154,     0,   110,   111,   112,
     113,     0,   114,   115,   273,   164,   165,   166,     0,   167,
     168,   169,   170,   171,   172,   173,   174,   117,     0,     0,
       0,    69,     0,     0,   119,   155,   121,   122,   123,   124,
     -33,   -33,   -33,   -33,     0,   117,     0,     0,     0,   175,
       0,     0,   119,   155,   121,   122,   123,   124,     0,     0,
       0,     0,   -33,   -33,   -33,   -33,     0,   175,     0,     0,
     117,   279,     0,   280,   188,   420,     0,   119,   155,   121,
     122,   123,   124,     0,     0,     0,     0,     0,     0,     0,
    -159,  -247,  -247,  -247,  -159,  -247,  -247,  -247,  -247,  -247,
    -247,  -247,  -247,  -159,  -159,  -247,     0,  -247,  -247,     0,
       0,     0,     0,     0,   -33,   -33,     0,     0,     0,     0,
       0,     0,     0,  -247,   206,  -247,   110,   111,   112,   113,
       0,   114,   115,     0,     0,     0,   -33,   -33,     0,   154,
       0,   110,   111,   112,   113,     0,   114,   115,     0,     0,
       0,     2,     0,     0,     0,     0,     0,     0,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,   109,     0,   110,   111,
     112,   113,     0,   114,   115,     0,     0,     0,     0,   117,
       0,     0,     0,     0,     0,     0,   119,   155,   121,   122,
     123,   124,     0,     0,   117,   279,   251,   280,   188,     0,
       9,   119,   155,   121,   122,   123,   124,     0,     0,    18,
      19,   109,     0,   110,   111,   112,   113,     0,   114,   115,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   117,     0,   252,     0,     0,     0,     0,   119,   253,
     121,   122,   123,   124,   154,     9,   110,   111,   112,   113,
       0,   114,   115,     0,    18,    19,     0,   154,     0,   110,
     111,   112,   113,     0,   114,   115,     0,     0,     0,     0,
     154,     0,   110,   111,   112,   113,   117,   114,   115,     0,
       0,     0,     0,   119,   155,   121,   122,   123,   124,   154,
       0,   110,   111,   112,   113,     0,   114,   115,     0,     0,
       0,     0,     0,   154,     0,   110,   111,   112,   113,   117,
     114,   115,     0,   188,     0,     0,   119,   155,   121,   122,
     123,   124,   117,     0,   289,     0,     0,     0,     0,   119,
     290,   121,   122,   123,   124,   117,     0,   366,     0,     0,
       0,     0,   119,   367,   121,   122,   123,   124,   154,     0,
     110,   111,   112,   113,   117,   114,   115,     0,   372,     0,
      79,   119,   155,   121,   122,   123,   124,     0,   117,     0,
       0,     0,     0,     0,     0,   119,   155,   121,   122,   123,
     124,   154,     0,   110,   111,   112,   113,     2,   114,   115,
       0,     0,     0,     0,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,     0,   201,     0,     0,     0,     0,     0,     0,
     119,   155,   121,   122,   123,   124,     0,     0,     0,     0,
     255,     0,     0,     0,   -33,   -33,   -33,   -33,     0,     0,
       0,     0,     0,     0,     0,     0,   299,     0,     0,     0,
       0,     0,     0,   119,   155,   121,   122,   123,   124,  -259,
    -259,  -259,  -259,  -259,  -259,  -259,  -259,  -259,  -259,  -259,
    -259,  -259,  -259,  -259,  -259,  -259,  -259,  -259,  -259,  -259,
    -259,  -259,  -259,  -259,     0,  -259,  -259,  -259,  -259,  -259,
    -259,  -259,  -259,  -259,  -259,  -259,  -259,   -33,   -33,   -33,
     -33,  -259,  -259,     0,     0,     0,     0,     0,   -33,   -33,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -112,  -112,  -112,  -112,  -112,  -112,  -112,  -112,
    -112,  -112,  -112,  -112,  -112,  -112,  -112,  -112,  -112,  -112,
    -112,  -112,  -112,  -112,  -112,  -112,  -112,     0,  -259,  -259,
    -259,     0,  -259,  -259,  -259,  -259,  -259,  -259,  -259,  -259,
     -33,   -33,   -33,   -33,  -134,  -259,     0,     0,     0,     0,
       0,   -33,   -33,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -112,  -112,  -112,  -112,  -112,
    -112,  -112,  -112,  -112,  -112,  -112,  -112,  -112,  -112,  -112,
    -112,  -112,  -112,  -112,  -112,  -112,  -112,  -112,  -112,  -112,
       0,   -33,   -33,   -33,   -33,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -134,     0,     0,
       0,     0,     0,     0,   -33,   -33,  -128,     0,     0,     0,
       0,     0,     0,  -128,  -128,  -128,  -128,  -128,  -128,  -128,
    -128,  -128,  -128,  -128,  -128,  -128,  -128,  -128,  -128,  -128,
    -128,     1,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -134,     0,
       0,     0,     0,     0,     0,   -33,   -33,     0,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    56,     1,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      69,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       0,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,   295,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    79,     0,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,     2,     0,     0,     0,     0,     0,
       0,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26
};

static const yytype_int16 yycheck[] =
{
      62,    76,    80,    49,    86,    75,    84,    47,   147,    43,
     103,    98,   201,    75,   194,     1,   117,   269,     0,    17,
       1,   356,   128,    98,     3,   164,    76,    72,    66,    67,
      72,    53,    66,    86,    74,     3,     1,     3,     3,   117,
      70,     1,   104,    88,    28,   107,    88,    29,    30,     3,
       3,    47,    34,    35,    36,     1,    78,    97,    80,    81,
     113,     3,    84,    70,     3,   147,   116,   142,    88,   103,
      35,     3,    87,   174,     3,   128,    70,   412,    74,    44,
      45,    68,   164,    67,    81,    72,   169,    85,    72,    12,
      13,    72,    71,    75,   147,   117,   348,   349,    66,    83,
     201,    66,    67,    89,     3,    71,    74,    72,    89,    74,
     299,   164,    72,   188,   215,   208,    70,   192,    86,   103,
     259,   143,    71,   201,    89,   305,    72,    66,    70,    89,
     205,    71,    72,   153,    66,    74,     3,    66,    67,   214,
     279,    71,   182,    89,    87,   207,   143,   209,   194,    88,
     203,   204,   214,    67,   229,    69,    72,   191,    81,    82,
       3,     4,     5,     6,   265,   266,    72,    66,    67,    72,
       1,    68,    88,    87,   208,    74,   251,   259,   261,   201,
     263,    73,    88,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   283,   279,   299,    66,
     275,   307,    71,    72,    35,    83,   259,    74,   283,   191,
     316,   317,   318,    44,    45,    16,   198,    68,    43,   294,
      84,   299,    70,   293,   286,   287,   279,    86,    53,   269,
      86,   293,    86,   334,    77,    78,   298,     3,    86,    87,
      88,    66,   343,    66,    66,    67,    75,    76,   310,    10,
      11,    76,    74,    78,   307,    80,    81,    66,   341,    84,
      14,    15,    66,   316,   317,   318,   319,   320,    88,   356,
     304,    66,    67,   257,    74,    71,    72,   299,    88,    79,
      80,   356,   344,   345,    66,    67,     3,   388,   389,   390,
       3,   116,   117,   238,   239,   240,   241,   372,     3,   374,
      71,    72,   364,   386,   387,   319,   320,   394,   370,   236,
     237,   293,    85,     7,     8,     9,    68,   142,   143,   394,
     242,   243,   304,   385,   407,   412,   409,   389,   390,    68,
      86,   414,    66,   416,    59,   418,     3,   412,    88,   421,
       1,    68,    68,   405,   406,    68,   408,     1,   431,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    68,   421,    66,
      68,    70,    66,    67,    28,    69,   201,    68,    68,    72,
     205,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    86,
      88,    57,     1,   244,     3,    57,   245,    68,   246,    67,
      71,    72,    73,    74,    75,    76,   248,    71,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,   247,    78,    58,   198,   257,   372,
     284,   182,    36,    -1,     1,    -1,     3,    66,    67,    -1,
      -1,    -1,    -1,    72,   299,    74,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,
      89,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,     3,    66,
      67,    -1,    -1,    -1,    -1,    72,    -1,    74,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    88,    89,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,
       3,    66,    67,    -1,    -1,    -1,    -1,    72,    -1,    74,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    88,    89,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       1,    -1,     3,    66,    67,    -1,    -1,    -1,    -1,    72,
       1,    74,     3,     4,     5,     6,    -1,     8,     9,    -1,
      -1,    -1,    -1,    -1,    -1,    88,    89,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     1,    -1,    -1,    66,    67,    -1,    -1,    -1,
      -1,    -1,    -1,    74,    -1,    66,    67,    -1,    69,    70,
      71,    -1,    73,    74,    75,    76,    77,    78,    89,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    -1,     3,    66,    67,    -1,
      -1,    -1,    -1,    -1,    -1,    74,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,
      89,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    -1,    -1,    -1,     1,    -1,     3,    -1,    -1,    -1,
      -1,    -1,    89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    -1,    -1,    -1,    -1,    -1,    89,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    -1,    -1,    -1,     1,
      -1,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,
      67,    -1,    -1,    -1,    -1,    -1,     1,    74,     3,     4,
       5,     6,    -1,     8,     9,    -1,    28,    -1,    -1,    86,
      -1,    -1,    89,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,     1,    -1,     3,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    66,    67,    -1,    -1,    -1,    -1,
      -1,     1,    74,     3,     4,     5,     6,    -1,     8,     9,
      -1,    66,    -1,    -1,    86,    35,    -1,    89,    73,    74,
      75,    76,    77,    78,    44,    45,    -1,    -1,    -1,    -1,
      -1,    31,    -1,    -1,    89,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    66,    67,    -1,    -1,
      -1,    -1,    72,     1,    74,     3,     4,     5,     6,    -1,
       8,     9,    -1,    -1,    -1,    -1,    66,    -1,    68,    89,
      -1,    -1,    -1,    73,    74,    75,    76,    77,    78,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    -1,    54,    55,    56,    -1,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    -1,
      -1,    -1,    70,    71,    -1,    73,    74,    75,    76,    77,
      78,     1,    -1,     3,     4,     5,     6,    -1,     8,     9,
      88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    -1,    54,    55,    56,    -1,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    -1,    -1,    -1,
      70,    -1,    -1,    73,    74,    75,    76,    77,    78,     1,
      -1,     3,     4,     5,     6,    -1,     8,     9,    88,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       1,    -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,
      -1,    73,    74,    75,    76,    77,    78,     1,    -1,     3,
       4,     5,     6,    -1,     8,     9,    88,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,     1,    -1,     3,     4,     5,     6,    -1,     8,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
       1,    72,     3,     4,     5,     6,    -1,     8,     9,    -1,
      -1,    -1,    66,    -1,    -1,    -1,    87,    88,    -1,    73,
      74,    75,    76,    77,    78,     1,    -1,     3,     4,     5,
       6,    -1,     8,     9,    88,    54,    55,    56,    -1,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    -1,
      -1,    70,    -1,    -1,    73,    74,    75,    76,    77,    78,
       3,     4,     5,     6,    -1,    66,    -1,    -1,    -1,    88,
      -1,    -1,    73,    74,    75,    76,    77,    78,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,    -1,    88,    -1,    -1,
      66,    67,    -1,    69,    70,    71,    -1,    73,    74,    75,
      76,    77,    78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    54,    55,    56,    35,    58,    59,    60,    61,    62,
      63,    64,    65,    44,    45,    68,    -1,    70,    71,    -1,
      -1,    -1,    -1,    -1,    77,    78,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    86,     1,    88,     3,     4,     5,     6,
      -1,     8,     9,    -1,    -1,    -1,    77,    78,    -1,     1,
      -1,     3,     4,     5,     6,    -1,     8,     9,    -1,    -1,
      -1,    28,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,     1,    -1,     3,     4,
       5,     6,    -1,     8,     9,    -1,    -1,    -1,    -1,    66,
      -1,    -1,    -1,    -1,    -1,    -1,    73,    74,    75,    76,
      77,    78,    -1,    -1,    66,    67,    31,    69,    70,    -1,
      35,    73,    74,    75,    76,    77,    78,    -1,    -1,    44,
      45,     1,    -1,     3,     4,     5,     6,    -1,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    66,    -1,    68,    -1,    -1,    -1,    -1,    73,    74,
      75,    76,    77,    78,     1,    35,     3,     4,     5,     6,
      -1,     8,     9,    -1,    44,    45,    -1,     1,    -1,     3,
       4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,    -1,
       1,    -1,     3,     4,     5,     6,    66,     8,     9,    -1,
      -1,    -1,    -1,    73,    74,    75,    76,    77,    78,     1,
      -1,     3,     4,     5,     6,    -1,     8,     9,    -1,    -1,
      -1,    -1,    -1,     1,    -1,     3,     4,     5,     6,    66,
       8,     9,    -1,    70,    -1,    -1,    73,    74,    75,    76,
      77,    78,    66,    -1,    68,    -1,    -1,    -1,    -1,    73,
      74,    75,    76,    77,    78,    66,    -1,    68,    -1,    -1,
      -1,    -1,    73,    74,    75,    76,    77,    78,     1,    -1,
       3,     4,     5,     6,    66,     8,     9,    -1,    70,    -1,
       1,    73,    74,    75,    76,    77,    78,    -1,    66,    -1,
      -1,    -1,    -1,    -1,    -1,    73,    74,    75,    76,    77,
      78,     1,    -1,     3,     4,     5,     6,    28,     8,     9,
      -1,    -1,    -1,    -1,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,
      73,    74,    75,    76,    77,    78,    -1,    -1,    -1,    -1,
      71,    -1,    -1,    -1,     3,     4,     5,     6,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,
      -1,    -1,    -1,    73,    74,    75,    76,    77,    78,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    -1,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,     3,     4,     5,
       6,    70,    71,    -1,    -1,    -1,    -1,    -1,    77,    78,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    -1,    54,    55,
      56,    -1,    58,    59,    60,    61,    62,    63,    64,    65,
       3,     4,     5,     6,    70,    71,    -1,    -1,    -1,    -1,
      -1,    77,    78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      -1,     3,     4,     5,     6,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    77,    78,    28,    -1,    -1,    -1,
      -1,    -1,    -1,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,     1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    77,    78,    -1,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,     0,     1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,     1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    28,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,   123,   124,   128,
     129,   130,   131,   137,   140,   141,   175,   176,   177,     3,
      70,     3,    66,    74,    88,   125,   126,   142,   143,   144,
     124,   124,     3,    70,   124,   124,     0,   176,    70,     3,
     138,   139,   142,     1,   140,   144,   145,    72,    88,    70,
      87,   123,   124,   160,   178,    66,    67,   143,    70,     1,
     129,   132,   133,   134,   140,   138,    87,    71,    72,     1,
      89,   172,   140,   144,   126,   142,   161,   162,   127,   123,
     160,     1,     3,   124,   146,   147,   148,   149,   172,     1,
       3,     4,     5,     6,     8,     9,    31,    66,    68,    73,
      74,    75,    76,    77,    78,    91,    92,    94,    97,    98,
      99,   103,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   119,   145,   132,   134,    71,   133,    86,   135,   136,
     142,   134,    71,    72,     1,    74,    94,   114,   122,    71,
     139,    71,     1,     3,    54,    55,    56,    58,    59,    60,
      61,    62,    63,    64,    65,    88,   119,   121,   123,   158,
     159,   160,   163,   164,   165,   166,   173,   174,    70,   119,
     153,    66,    67,   142,   144,   151,   152,   172,    72,    72,
     172,    66,    94,    95,    96,   145,     1,   121,   134,   150,
      68,     7,     8,     9,    66,    67,    69,     1,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    87,   120,
      98,    74,    79,    80,    75,    76,    10,    11,    12,    13,
      81,    82,    14,    15,    73,    83,    84,    16,    17,   115,
      68,    31,    68,    74,   119,    71,   122,    72,    88,    86,
      71,    86,   122,    86,   167,    66,    66,     1,   158,    66,
       3,    88,    88,    88,   121,    72,    88,    71,   164,    67,
      69,   153,   154,   155,   156,   157,   146,   151,   172,    68,
      74,   119,   152,    66,    67,    53,   148,     3,   150,    66,
      94,    94,   119,   172,    66,   144,   151,   172,     3,     1,
      93,   119,   172,   121,     3,   119,   100,   101,   102,   104,
     105,   103,   103,   106,   106,   106,   106,   107,   107,   108,
     109,   110,   111,   112,    85,   119,    68,    68,   136,   122,
     158,    86,   158,    66,   121,   121,    59,     1,   123,   165,
      88,    88,   119,   122,     3,    71,    72,   153,    87,   157,
     172,   172,    68,    68,   146,   172,    68,    74,   119,   172,
     150,    68,    70,    98,    72,   172,    68,    98,    98,    98,
      99,    99,   121,    68,   158,   121,   172,   172,    66,   165,
     165,    68,    71,   153,   155,   172,    68,    68,   172,   154,
     119,   116,   172,   158,   158,   121,   121,   172,   121,   172,
     153,    71,    72,    86,   168,   172,   172,   158,   172,   158,
      71,   117,   158,   169,    88,   158,   158,   114,   170,   118,
      57,   171,   158
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    90,    91,    91,    91,    91,    91,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    93,    93,    94,
      95,    94,    96,    94,    94,    94,    94,    97,    97,    97,
      97,    97,    97,    97,    98,    98,    99,   100,    99,   101,
      99,   102,    99,   103,   104,   103,   105,   103,   106,   106,
     106,   107,   107,   107,   107,   107,   108,   108,   108,   109,
     109,   110,   110,   111,   111,   112,   112,   113,   113,   114,
     115,   116,   117,   118,   114,   119,   119,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   121,
     121,   122,   123,   123,   124,   124,   124,   124,   124,   124,
     124,   124,   125,   125,   126,   127,   126,   128,   128,   128,
     128,   128,   128,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   130,
     130,   130,   131,   131,   131,   132,   132,   133,   134,   134,
     134,   134,   135,   135,   136,   136,   136,   137,   137,   137,
     137,   137,   138,   138,   139,   139,   140,   140,   140,   140,
     141,   142,   142,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   144,   144,   144,   144,
     145,   145,   146,   146,   147,   147,   148,   148,   148,   149,
     149,   150,   150,   151,   151,   151,   152,   152,   152,   152,
     152,   152,   152,   152,   152,   152,   152,   153,   153,   153,
     154,   154,   154,   154,   155,   156,   156,   157,   157,   158,
     158,   158,   158,   158,   158,   159,   159,   159,   161,   160,
     162,   160,   163,   163,   164,   164,   165,   165,   167,   168,
     166,   166,   170,   171,   169,   169,   172,   172,   173,   173,
     173,   173,   173,   173,   174,   174,   174,   174,   174,   174,
     175,   175,   176,   176,   177,   177,   178,   178
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     1,     4,     3,
       4,     3,     3,     2,     2,     6,     7,     1,     3,     1,
       0,     3,     0,     3,     2,     2,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     1,     0,     4,     0,
       4,     0,     4,     1,     0,     4,     0,     4,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       0,     0,     0,     0,     9,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     2,     3,     1,     2,     1,     2,     1,     2,
       1,     2,     1,     3,     1,     0,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     5,
       4,     2,     1,     1,     1,     1,     2,     3,     2,     1,
       2,     1,     1,     3,     1,     2,     3,     4,     5,     5,
       6,     2,     1,     3,     1,     3,     1,     1,     1,     1,
       1,     2,     1,     1,     3,     5,     4,     4,     6,     6,
       5,     4,     3,     4,     4,     3,     1,     2,     2,     3,
       1,     2,     1,     3,     1,     3,     2,     2,     1,     1,
       3,     1,     2,     1,     1,     2,     3,     2,     3,     3,
       4,     3,     4,     2,     3,     3,     4,     1,     3,     4,
       1,     2,     3,     4,     2,     1,     2,     3,     2,     1,
       1,     1,     1,     1,     1,     3,     4,     3,     0,     3,
       0,     4,     1,     2,     1,     1,     1,     2,     0,     0,
       7,     5,     0,     0,     5,     1,     1,     1,     5,     7,
       6,     7,     6,     7,     3,     2,     2,     2,     3,     1,
       1,     2,     1,     1,     4,     3,     1,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        YY_LAC_DISCARD ("YYBACKUP");                              \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
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
  unsigned long yylno = yyrline[yyrule];
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
                       &yyvsp[(yyi + 1) - (yynrhs)]
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

/* Given a state stack such that *YYBOTTOM is its bottom, such that
   *YYTOP is either its top or is YYTOP_EMPTY to indicate an empty
   stack, and such that *YYCAPACITY is the maximum number of elements it
   can hold without a reallocation, make sure there is enough room to
   store YYADD more elements.  If not, allocate a new stack using
   YYSTACK_ALLOC, copy the existing elements, and adjust *YYBOTTOM,
   *YYTOP, and *YYCAPACITY to reflect the new capacity and memory
   location.  If *YYBOTTOM != YYBOTTOM_NO_FREE, then free the old stack
   using YYSTACK_FREE.  Return 0 if successful or if no reallocation is
   required.  Return 1 if memory is exhausted.  */
static int
yy_lac_stack_realloc (YYSIZE_T *yycapacity, YYSIZE_T yyadd,
#if YYDEBUG
                      char const *yydebug_prefix,
                      char const *yydebug_suffix,
#endif
                      yytype_int16 **yybottom,
                      yytype_int16 *yybottom_no_free,
                      yytype_int16 **yytop, yytype_int16 *yytop_empty)
{
  YYSIZE_T yysize_old =
    (YYSIZE_T) (*yytop == yytop_empty ? 0 : *yytop - *yybottom + 1);
  YYSIZE_T yysize_new = yysize_old + yyadd;
  if (*yycapacity < yysize_new)
    {
      YYSIZE_T yyalloc = 2 * yysize_new;
      yytype_int16 *yybottom_new;
      /* Use YYMAXDEPTH for maximum stack size given that the stack
         should never need to grow larger than the main state stack
         needs to grow without LAC.  */
      if (YYMAXDEPTH < yysize_new)
        {
          YYDPRINTF ((stderr, "%smax size exceeded%s", yydebug_prefix,
                      yydebug_suffix));
          return 1;
        }
      if (YYMAXDEPTH < yyalloc)
        yyalloc = YYMAXDEPTH;
      yybottom_new =
        (yytype_int16*) YYSTACK_ALLOC (yyalloc * sizeof *yybottom_new);
      if (!yybottom_new)
        {
          YYDPRINTF ((stderr, "%srealloc failed%s", yydebug_prefix,
                      yydebug_suffix));
          return 1;
        }
      if (*yytop != yytop_empty)
        {
          YYCOPY (yybottom_new, *yybottom, yysize_old);
          *yytop = yybottom_new + (yysize_old - 1);
        }
      if (*yybottom != yybottom_no_free)
        YYSTACK_FREE (*yybottom);
      *yybottom = yybottom_new;
      *yycapacity = yyalloc;
    }
  return 0;
}

/* Establish the initial context for the current lookahead if no initial
   context is currently established.

   We define a context as a snapshot of the parser stacks.  We define
   the initial context for a lookahead as the context in which the
   parser initially examines that lookahead in order to select a
   syntactic action.  Thus, if the lookahead eventually proves
   syntactically unacceptable (possibly in a later context reached via a
   series of reductions), the initial context can be used to determine
   the exact set of tokens that would be syntactically acceptable in the
   lookahead's place.  Moreover, it is the context after which any
   further semantic actions would be erroneous because they would be
   determined by a syntactically unacceptable token.

   YY_LAC_ESTABLISH should be invoked when a reduction is about to be
   performed in an inconsistent state (which, for the purposes of LAC,
   includes consistent states that don't know they're consistent because
   their default reductions have been disabled).  Iff there is a
   lookahead token, it should also be invoked before reporting a syntax
   error.  This latter case is for the sake of the debugging output.

   For parse.lac=full, the implementation of YY_LAC_ESTABLISH is as
   follows.  If no initial context is currently established for the
   current lookahead, then check if that lookahead can eventually be
   shifted if syntactic actions continue from the current context.
   Report a syntax error if it cannot.  */
#define YY_LAC_ESTABLISH                                         \
do {                                                             \
  if (!yy_lac_established)                                       \
    {                                                            \
      YYDPRINTF ((stderr,                                        \
                  "LAC: initial context established for %s\n",   \
                  yytname[yytoken]));                            \
      yy_lac_established = 1;                                    \
      {                                                          \
        int yy_lac_status =                                      \
          yy_lac (yyesa, &yyes, &yyes_capacity, yyssp, yytoken); \
        if (yy_lac_status == 2)                                  \
          goto yyexhaustedlab;                                   \
        if (yy_lac_status == 1)                                  \
          goto yyerrlab;                                         \
      }                                                          \
    }                                                            \
} while (0)

/* Discard any previous initial lookahead context because of Event,
   which may be a lookahead change or an invalidation of the currently
   established initial context for the current lookahead.

   The most common example of a lookahead change is a shift.  An example
   of both cases is syntax error recovery.  That is, a syntax error
   occurs when the lookahead is syntactically erroneous for the
   currently established initial context, so error recovery manipulates
   the parser stacks to try to find a new initial context in which the
   current lookahead is syntactically acceptable.  If it fails to find
   such a context, it discards the lookahead.  */
#if YYDEBUG
# define YY_LAC_DISCARD(Event)                                           \
do {                                                                     \
  if (yy_lac_established)                                                \
    {                                                                    \
      if (yydebug)                                                       \
        YYFPRINTF (stderr, "LAC: initial context discarded due to "      \
                   Event "\n");                                          \
      yy_lac_established = 0;                                            \
    }                                                                    \
} while (0)
#else
# define YY_LAC_DISCARD(Event) yy_lac_established = 0
#endif

/* Given the stack whose top is *YYSSP, return 0 iff YYTOKEN can
   eventually (after perhaps some reductions) be shifted, return 1 if
   not, or return 2 if memory is exhausted.  As preconditions and
   postconditions: *YYES_CAPACITY is the allocated size of the array to
   which *YYES points, and either *YYES = YYESA or *YYES points to an
   array allocated with YYSTACK_ALLOC.  yy_lac may overwrite the
   contents of either array, alter *YYES and *YYES_CAPACITY, and free
   any old *YYES other than YYESA.  */
static int
yy_lac (yytype_int16 *yyesa, yytype_int16 **yyes,
        YYSIZE_T *yyes_capacity, yytype_int16 *yyssp, int yytoken)
{
  yytype_int16 *yyes_prev = yyssp;
  yytype_int16 *yyesp = yyes_prev;
  YYDPRINTF ((stderr, "LAC: checking lookahead %s:", yytname[yytoken]));
  if (yytoken == YYUNDEFTOK)
    {
      YYDPRINTF ((stderr, " Always Err\n"));
      return 1;
    }
  while (1)
    {
      int yyrule = yypact[*yyesp];
      if (yypact_value_is_default (yyrule)
          || (yyrule += yytoken) < 0 || YYLAST < yyrule
          || yycheck[yyrule] != yytoken)
        {
          yyrule = yydefact[*yyesp];
          if (yyrule == 0)
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
        }
      else
        {
          yyrule = yytable[yyrule];
          if (yytable_value_is_error (yyrule))
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
          if (0 < yyrule)
            {
              YYDPRINTF ((stderr, " S%d\n", yyrule));
              return 0;
            }
          yyrule = -yyrule;
        }
      {
        YYSIZE_T yylen = yyr2[yyrule];
        YYDPRINTF ((stderr, " R%d", yyrule - 1));
        if (yyesp != yyes_prev)
          {
            YYSIZE_T yysize = (YYSIZE_T) (yyesp - *yyes + 1);
            if (yylen < yysize)
              {
                yyesp -= yylen;
                yylen = 0;
              }
            else
              {
                yylen -= yysize;
                yyesp = yyes_prev;
              }
          }
        if (yylen)
          yyesp = yyes_prev -= yylen;
      }
      {
        yytype_int16 yystate;
        {
          const int yylhs = yyr1[yyrule] - YYNTOKENS;
          const int yyi = yypgoto[yylhs] + *yyesp;
          yystate = ((yytype_int16)
                     (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyesp
                      ? yytable[yyi]
                      : yydefgoto[yylhs]));
        }
        if (yyesp == yyes_prev)
          {
            yyesp = *yyes;
            *yyesp = yystate;
          }
        else
          {
            if (yy_lac_stack_realloc (yyes_capacity, 1,
#if YYDEBUG
                                      " (", ")",
#endif
                                      yyes, yyesa, &yyesp, yyes_prev))
              {
                YYDPRINTF ((stderr, "\n"));
                return 2;
              }
            *++yyesp = yystate;
          }
        YYDPRINTF ((stderr, " G%d", (int) yystate));
      }
    }
}


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
            else
              goto append;

          append:
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

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.  In order to see if a particular token T is a
   valid looakhead, invoke yy_lac (YYESA, YYES, YYES_CAPACITY, YYSSP, T).

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store or if
   yy_lac returned 2.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyesa, yytype_int16 **yyes,
                YYSIZE_T *yyes_capacity, yytype_int16 *yyssp, int yytoken)
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
       In the first two cases, it might appear that the current syntax
       error should have been detected in the previous state when yy_lac
       was invoked.  However, at that time, there might have been a
       different syntax error that discarded a different initial context
       during error recovery, leaving behind the current lookahead.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      YYDPRINTF ((stderr, "Constructing syntax error message\n"));
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          int yyx;

          for (yyx = 0; yyx < YYNTOKENS; ++yyx)
            if (yyx != YYTERROR && yyx != YYUNDEFTOK)
              {
                {
                  int yy_lac_status = yy_lac (yyesa, yyes, yyes_capacity,
                                              yyssp, yyx);
                  if (yy_lac_status == 2)
                    return 2;
                  if (yy_lac_status == 1)
                    continue;
                }
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
# if YYDEBUG
      else if (yydebug)
        YYFPRINTF (stderr, "No expected tokens.\n");
# endif
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
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
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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

    yytype_int16 yyesa[20];
    yytype_int16 *yyes;
    YYSIZE_T yyes_capacity;

  int yy_lac_established = 0;
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

  yyes = yyesa;
  yyes_capacity = sizeof yyesa / sizeof *yyes;
  if (YYMAXDEPTH < yyes_capacity)
    yyes_capacity = YYMAXDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
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
# else /* defined YYSTACK_RELOCATE */
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
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
    {
      YY_LAC_ESTABLISH;
      goto yydefault;
    }
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      YY_LAC_ESTABLISH;
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
  YY_LAC_DISCARD ("shift");

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
| yyreduce -- do a reduction.  |
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
  {
    int yychar_backup = yychar;
    switch (yyn)
      {
  case 2:
#line 51 "parser-bison.y" /* yacc.c:1652  */
    {process_id();}
#line 2232 "parser-bison.tab.c" /* yacc.c:1652  */
    break;

  case 3:
#line 52 "parser-bison.y" /* yacc.c:1652  */
    {process_literal();}
#line 2238 "parser-bison.tab.c" /* yacc.c:1652  */
    break;

  case 13:
#line 65 "parser-bison.y" /* yacc.c:1652  */
    {process_op();eval_unary();}
#line 2244 "parser-bison.tab.c" /* yacc.c:1652  */
    break;

  case 14:
#line 66 "parser-bison.y" /* yacc.c:1652  */
    {process_op();eval_unary();}
#line 2250 "parser-bison.tab.c" /* yacc.c:1652  */
    break;

  case 20:
#line 78 "parser-bison.y" /* yacc.c:1652  */
    {process_op();}
#line 2256 "parser-bison.tab.c" /* yacc.c:1652  */
    break;

  case 21:
#line 78 "parser-bison.y" /* yacc.c:1652  */
    {eval_unary();}
#line 2262 "parser-bison.tab.c" /* yacc.c:1652  */
    break;

  case 22:
#line 79 "parser-bison.y" /* yacc.c:1652  */
    {process_op();}
#line 2268 "parser-bison.tab.c" /* yacc.c:1652  */
    break;

  case 23:
#line 79 "parser-bison.y" /* yacc.c:1652  */
    {eval_unary();}
#line 2274 "parser-bison.tab.c" /* yacc.c:1652  */
    break;

  case 37:
#line 102 "parser-bison.y" /* yacc.c:1652  */
    {process_op();}
#line 2280 "parser-bison.tab.c" /* yacc.c:1652  */
    break;

  case 38:
#line 102 "parser-bison.y" /* yacc.c:1652  */
    {eval_binary();}
#line 2286 "parser-bison.tab.c" /* yacc.c:1652  */
    break;

  case 39:
#line 103 "parser-bison.y" /* yacc.c:1652  */
    {process_op();}
#line 2292 "parser-bison.tab.c" /* yacc.c:1652  */
    break;

  case 40:
#line 103 "parser-bison.y" /* yacc.c:1652  */
    {eval_binary();}
#line 2298 "parser-bison.tab.c" /* yacc.c:1652  */
    break;

  case 41:
#line 104 "parser-bison.y" /* yacc.c:1652  */
    {process_op();}
#line 2304 "parser-bison.tab.c" /* yacc.c:1652  */
    break;

  case 42:
#line 104 "parser-bison.y" /* yacc.c:1652  */
    {eval_binary();}
#line 2310 "parser-bison.tab.c" /* yacc.c:1652  */
    break;

  case 44:
#line 109 "parser-bison.y" /* yacc.c:1652  */
    {process_op();}
#line 2316 "parser-bison.tab.c" /* yacc.c:1652  */
    break;

  case 45:
#line 109 "parser-bison.y" /* yacc.c:1652  */
    {eval_binary();}
#line 2322 "parser-bison.tab.c" /* yacc.c:1652  */
    break;

  case 46:
#line 110 "parser-bison.y" /* yacc.c:1652  */
    {process_op();}
#line 2328 "parser-bison.tab.c" /* yacc.c:1652  */
    break;

  case 47:
#line 110 "parser-bison.y" /* yacc.c:1652  */
    {eval_binary();}
#line 2334 "parser-bison.tab.c" /* yacc.c:1652  */
    break;

  case 70:
#line 160 "parser-bison.y" /* yacc.c:1652  */
    {eval_if();}
#line 2340 "parser-bison.tab.c" /* yacc.c:1652  */
    break;

  case 71:
#line 160 "parser-bison.y" /* yacc.c:1652  */
    {endIFdec();}
#line 2346 "parser-bison.tab.c" /* yacc.c:1652  */
    break;

  case 72:
#line 160 "parser-bison.y" /* yacc.c:1652  */
    {process_else();}
#line 2352 "parser-bison.tab.c" /* yacc.c:1652  */
    break;

  case 73:
#line 160 "parser-bison.y" /* yacc.c:1652  */
    {eval_else();}
#line 2358 "parser-bison.tab.c" /* yacc.c:1652  */
    break;

  case 74:
#line 160 "parser-bison.y" /* yacc.c:1652  */
    {printf("if ternario\n");}
#line 2364 "parser-bison.tab.c" /* yacc.c:1652  */
    break;

  case 76:
#line 165 "parser-bison.y" /* yacc.c:1652  */
    {fin_assign();}
#line 2370 "parser-bison.tab.c" /* yacc.c:1652  */
    break;

  case 77:
#line 169 "parser-bison.y" /* yacc.c:1652  */
    {push(&pila, TOKEN, "=");}
#line 2376 "parser-bison.tab.c" /* yacc.c:1652  */
    break;

  case 93:
#line 194 "parser-bison.y" /* yacc.c:1652  */
    {
		if(as == 0){fin_decl();}
		else{fin_declas();}
			}
#line 2385 "parser-bison.tab.c" /* yacc.c:1652  */
    break;

  case 104:
#line 217 "parser-bison.y" /* yacc.c:1652  */
    {printf("\n");}
#line 2391 "parser-bison.tab.c" /* yacc.c:1652  */
    break;

  case 105:
#line 218 "parser-bison.y" /* yacc.c:1652  */
    {as = 1; push(&pila, TOKEN, "=");}
#line 2397 "parser-bison.tab.c" /* yacc.c:1652  */
    break;

  case 116:
#line 234 "parser-bison.y" /* yacc.c:1652  */
    {guardar_tipo();}
#line 2403 "parser-bison.tab.c" /* yacc.c:1652  */
    break;

  case 163:
#line 325 "parser-bison.y" /* yacc.c:1652  */
    {guardar_id();}
#line 2409 "parser-bison.tab.c" /* yacc.c:1652  */
    break;

  case 228:
#line 442 "parser-bison.y" /* yacc.c:1652  */
    {open_scope();pila = clearStack(pila);}
#line 2415 "parser-bison.tab.c" /* yacc.c:1652  */
    break;

  case 229:
#line 442 "parser-bison.y" /* yacc.c:1652  */
    {close_scope();}
#line 2421 "parser-bison.tab.c" /* yacc.c:1652  */
    break;

  case 230:
#line 443 "parser-bison.y" /* yacc.c:1652  */
    {open_scope();pila = clearStack(pila);}
#line 2427 "parser-bison.tab.c" /* yacc.c:1652  */
    break;

  case 231:
#line 443 "parser-bison.y" /* yacc.c:1652  */
    {close_scope();}
#line 2433 "parser-bison.tab.c" /* yacc.c:1652  */
    break;

  case 237:
#line 458 "parser-bison.y" /* yacc.c:1652  */
    {pila = clearStack(pila);}
#line 2439 "parser-bison.tab.c" /* yacc.c:1652  */
    break;

  case 238:
#line 462 "parser-bison.y" /* yacc.c:1652  */
    { process_if(); }
#line 2445 "parser-bison.tab.c" /* yacc.c:1652  */
    break;

  case 239:
#line 462 "parser-bison.y" /* yacc.c:1652  */
    { eval_if(); }
#line 2451 "parser-bison.tab.c" /* yacc.c:1652  */
    break;

  case 242:
#line 468 "parser-bison.y" /* yacc.c:1652  */
    {endIFdec();}
#line 2457 "parser-bison.tab.c" /* yacc.c:1652  */
    break;

  case 243:
#line 468 "parser-bison.y" /* yacc.c:1652  */
    { process_else(); }
#line 2463 "parser-bison.tab.c" /* yacc.c:1652  */
    break;

  case 244:
#line 468 "parser-bison.y" /* yacc.c:1652  */
    { eval_else(); }
#line 2469 "parser-bison.tab.c" /* yacc.c:1652  */
    break;

  case 245:
#line 469 "parser-bison.y" /* yacc.c:1652  */
    {endIFdec(); process_else(); eval_else();  }
#line 2475 "parser-bison.tab.c" /* yacc.c:1652  */
    break;


#line 2479 "parser-bison.tab.c" /* yacc.c:1652  */
        default: break;
      }
    if (yychar_backup != yychar)
      YY_LAC_DISCARD ("yychar change");
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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
                                        yyesa, &yyes, &yyes_capacity, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        if (yychar != YYEMPTY)
          YY_LAC_ESTABLISH;
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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

  /* If the stack popping above didn't lose the initial context for the
     current lookahead token, the shift below will for sure.  */
  YY_LAC_DISCARD ("error recovery");

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


#if 1
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
  if (yyes != yyesa)
    YYSTACK_FREE (yyes);
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 515 "parser-bison.y" /* yacc.c:1918  */


void fin_assign(){
	struct semantic_record* assin = retrieve(pila,TOKEN);
	struct semantic_record* val;
	int b = 0;
	if(retrieve(pila,DATAO) != NULL){
		val = retrieve(pila,DATAO);
	}
	else{
		val = top(pila);
		pila = pop2(&pila);
		b = 1;
	}
	while(retrieve(pila, ID) != NULL){
		struct semantic_record* identificador = retrieveDelete(pila,ID);
		struct symbolT* smb = topSymbol(&symbolStck);
		if(!(lookup(smb, identificador->name)) == 1){
			printf("%s","Error semántico, ");
			printf("%s",identificador->name);
			printf("%s\n"," no ha sido declarado antes, este error solo será reportado 1 vez por cada variable");
			insert(&smb, "error",identificador->name);
			symbolStck = popSymbol(&symbolStck);
			pushSymbol(&symbolStck, smb);
		}
		printf("%s ",identificador->name);
		printf("%s ",assin->name);
		printf("%s\n",val->name);
		free(identificador);
	}
	pila = clearStack(pila);
	if(b == 1)free(val);
}

void endIFdec(){
	printf("%s\n","JMP exit_if");
}

void process_if(){
	push(&pila, DATAO, yytext);
	//crear etiquetas ensamblador
}

void eval_if(){
	/* printStack(pila); */
	struct semantic_record* Res = top(pila);
	pila = pop2(&pila);
	//pila = pop(&pila);
	/* printStack(pila); */
	printf("%s","CMP 0 ");
	printf("%s\n",Res->name);
	printf("%s\n","JZ ELSE");
	free(Res);

	//código para if ensamblador
}

void process_else(){
	push(&pila, DATAO, yytext);
	printf("%s\n","LABEL: ESLE");
	//crear etiquetas ensamblador
}

void eval_else(){
	pila = pop(&pila);
	printf("%s\n","exit_if");
	//etiqueta de salida
}

void eval_binary(){
	struct semantic_record* OP1 = top(pila);
	pila = pop2(&pila);
	struct semantic_record* OPERATOR = top(pila);
	pila = pop2(&pila);
	struct semantic_record* OP2 = top(pila);
	pila = pop2(&pila);

	//crear funcion que crea temporales
	createTemp();
	if(OP1->type == ERROR){
		push(&pila,ERROR,temporal);
		return;
	}
	else if(OP2->type == ERROR){
		push(&pila,ERROR,temporal);
		return;
	}
	else{
		push(&pila,DATAO,temporal);
	}

	if(!strcmp(OPERATOR->name,"-")||!strcmp(OPERATOR->name,"/")){
		struct semantic_record* temp = OP1;
		OP1 = OP2;
		OP2 = temp;
	}
	//generar codigo ensamblador para OP1 OPERATOR OUTPUT2 = TEMP1
	printf("%s = ",temporal);
	printf("%s ",OP1->name);
	printf("%s ",OPERATOR->name);
	printf("%s\n",OP2->name);
	free(OP1);
	free(OPERATOR);
	free(OP2);
}

void clear_temp(){//borra el contenido de token_buffer y lo resetea a un string vacio
    memset(temporal, 0, sizeof(temporal));
}

void createTemp(){
	clear_temp();
	char buffer [200];
	snprintf(buffer, 200, "%d", ++tempAct);
	strcat(temporal, "Temp");
	strcat(temporal, buffer);
}

void eval_unary(){
	struct semantic_record* OP1 = top(pila);
	pila = pop2(&pila);
	struct semantic_record* OPERATOR = top(pila);
	pila = pop2(&pila);

	//crear funcion que crea temporales
	createTemp();
	if(OP1->type == ERROR){
		push(&pila,ERROR,temporal);
		return;
	}

	if(OP1->type == TOKEN){
		//generar codigo ensamblador para a++
		// el OPERATOR contiene el id
		// el OP1 contiene el ++
		printf("%s = ",temporal);
		printf("%s ",OPERATOR->name);
		printf("%s\n",OP1->name);
	}
	else{
		//generar codigo ensamblador para ++a
		// el OPERATOR contiene el ++
		// el OP1 contiene el id
		printf("%s = ",temporal);
		printf("%s ",OPERATOR->name);
		printf("%s\n",OP1->name);
	}
	free(OP1);
	free(OPERATOR);
}

void process_literal(){
	push(&pila, DATAO, yytext);
}

void process_op(){
	push(&pila, TOKEN, yytext);
}

void process_id(){
	struct tableRegister* smb = symbolStck;
	//DECISION isnertar variable que no ha sido declarada a la tabla de simbolos
	//y dejar que si se usa de nuevo se pueda usar?
	//o agregarle una AND al if y que pregunte si el tipo de la variable es != de error
	int ban = 0;
	while(smb->next != NULL){
		if(!(lookup(smb->symbolT, idActual) != 1)){
			push(&pila, ID, idActual);
			ban = 1;
			break;
		}
		smb = smb->next;
	}
	if(ban == 0){
		push(&pila, ERROR, idActual);
		struct semantic_record* identificador = top(pila);
		printf("%s","Error semántico, ");
		printf("%s",identificador->name);
		printf("%s\n"," no ha sido declarado antes, este error solo será reportado 1 vez por cada variable");
		insert(&smb, "error",identificador->name);
		symbolStck = popSymbol(&symbolStck);
		pushSymbol(&symbolStck, smb);
	}
}

void guardar_id(){
	push(&pila, ID, yytext);
}

void guardar_tipo(){
	push(&pila, TIPO, yytext);
}

void fin_decl(){
	struct semantic_record* tipo = retrieve(pila,TIPO);
	while(top(pila)->type==ID){
		struct semantic_record* identificador = retrieve(pila,ID);
		struct symbolT* smb = topSymbol(&symbolStck);
		if(lookup(smb, identificador->name) == 1){
			printf("Error semántico, %s ya ha sido declarado antes.\n", identificador->name);
			exit(1);
		}
		insert(&smb, tipo->name,identificador->name);
		symbolStck = popSymbol(&symbolStck);
		pushSymbol(&symbolStck, smb);
		pila = pop(&pila);
	}
	pila = pop(&pila);
	pila = clearStack(pila);
}

void fin_declas(){
	if(retrieve(pila,DATAO) != NULL){
		struct semantic_record* tipo = retrieve(pila,TIPO);
		struct semantic_record* assin = retrieve(pila,TOKEN);
		struct semantic_record* val = retrieve(pila,DATAO);
		while(retrieve(pila, ID) != NULL){
			struct semantic_record* identificador = retrieveDelete(pila,ID);
			struct symbolT* smb = topSymbol(&symbolStck);
			if(lookup(smb, identificador->name) == 1){
				printf("Error semántico, %s ya ha sido declarado antes.\n", identificador->name);
				exit(1);
			}
			insert(&smb, tipo->name,identificador->name);
			symbolStck = popSymbol(&symbolStck);
			pushSymbol(&symbolStck, smb);
			printf("%s ",identificador->name);
			printf("%s ",assin->name);
			printf("%s\n",val->name);
			free(identificador);
		}
		as = 0;
		pila = clearStack(pila);
	}
}

void open_scope(){
	struct symbolT* newSymbolTable = NULL;
	pushSymbol(&symbolStck, newSymbolTable);
}

void close_scope(){
	symbolStck = popSymbol(&symbolStck);
}

extern char *yytext;

extern int column;

void yyerror(char *s){
	fflush(stdout);
	if(beamer == 1){
		fprintf(fileOut, "\\\\\\setstcolor{er}\\sethlcolor{er}\\Oricolor\\hl{Syntax Error, in line:");
		fprintf(fileOut, "%d",yylineno);
		fprintf(fileOut, "}\\\\");
	}
	printf("%s",linea);
	printf("\n%*s\n%*s ", column, "^", column, s);
	if(conteo == 1){
		printf("in line: %d\n\n", yylineno);
	}
	else{
		printf("%s", "\n\n");
	}
	errores++;
}
