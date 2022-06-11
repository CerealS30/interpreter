/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 13 "reconocedor.y"

#include<stdlib.h>
#include<stdio.h>
#include <assert.h>

#include <string.h>


#define NOTHING -99999

double doubleVal;

 enum SyntaxTreeNodeType {
  PROGRAM,
  PYC,
  PYC_S,
  STMT,
  ASSIGN_STMT,
  IF_STMT,
  ITER_STMT,
  CMP_STMT,
  SET,
  TO,
  EXPR,
  TERM,
  FACTOR,
  READ,
  PRINT,
  REPEAT,
  IF,
  EXPRESION,
  IFELSE,
  WHILE,
  FOR,
  STEP,
  DO,
  STMT_LST,
  PLUS,
  MINUS,
  STAR,
  FORWARD_SLASH,
  LT,
  GT,
  EQ,
  LEQ,
  GEQ,
  INTEGER_NUMBER_VALUE,
  FLOATING_POINT_NUMBER_VALUE,
  ID_VALUE,
  FUNCTION_VALUE,
  PARAMETER_VALUE,
  EXPR_LST,
  RETURN
};

char* SyntaxTreeNodeTypeName[] = {
  "PROGRAM",
  "PYC",
  "PYC_S",
  "STMT",
  "ASSIGN_STMT",
  "IF_STMT",
  "ITER_STMT",
  "CMP_STMT",
  "SET",
  "TO",
  "EXPR",
  "TERM",
  "FACTOR",
  "READ",
  "PRINT",
  "REPEAT",
  "IF",
  "EXPRESION",
  "IFELSE",
  "WHILE",
  "FOR",
  "STEP",
  "DO",
  "STMT_LST",
  "PLUS",
  "MINUS",
  "STAR",
  "FORWARD_SLASH",
  "LT",
  "GT",
  "EQ",
  "LEQ",
  "GEQ",
  "INTEGER_NUMBER_VALUE",
  "FLOATING_POINT_NUMBER_VALUE",
  "ID_VALUE",
  "FUNCTION_VALUE",
  "PARAMETER_VALUE",
  "EXPR_LST",
  "RETURN"
};


struct nodoTS {
    char * nombre;
    int type;
    union {
      int intVal;
      double doubleVal;
    }value;
    struct nodoTS * next;
};
// Definimos una estructura para hacer el árbol sintáctico reducIDo.
typedef struct asr ASR;
struct asr {
  int type;
  int parentNodeType;
  ASR *arrPtr[4];
  union {
    int intVal; /* Integer value */
    double doubleVal; /* Floating-point value */
    char *idName; /* Identifier name */
  } value;
  ASR *next;
};




extern int yylex();
int yyerror(char const * s);
ASR * nuevoNodo(int, double, char*, int, int, ASR*,ASR*,ASR*,ASR*,ASR*);
extern char * yytext;
extern FILE *yyin;
//void findID(char * id);
struct nodoTS * insertID(char* id, int tipo);
void printList();
void printTree(ASR * raiz);
void interpreta(ASR * raiz);




struct nodoTS * head;
struct nodoTS * current;

#line 213 "reconocedor.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
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
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_RECONOCEDOR_TAB_H_INCLUDED
# define YY_YY_RECONOCEDOR_TAB_H_INCLUDED
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
    SUMA = 258,
    RESTA = 259,
    MULT = 260,
    DIV = 261,
    PARI = 262,
    PARF = 263,
    BGN = 264,
    END = 265,
    COLON = 266,
    SEMI = 267,
    ASSIGN = 268,
    EQUAL = 269,
    LESSER = 270,
    GREATER = 271,
    LEQUAL = 272,
    GEQUAL = 273,
    LARROW = 274,
    RES_FOR = 275,
    RES_DO = 276,
    RES_WHILE = 277,
    RES_IF = 278,
    THEN = 279,
    ELSE = 280,
    INT = 281,
    FLOAT = 282,
    RES_REPEAT = 283,
    UNTIL = 284,
    RES_STEP = 285,
    RES_PROGRAM = 286,
    VAR = 287,
    RES_READ = 288,
    RES_PRINT = 289,
    INTEGER = 290,
    FLOATING = 291,
    ID = 292
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 156 "reconocedor.y"

   struct nodoTS * val;
   char * nombre;
   int entero;  // Para las constantes num�ricas
   double doubleVal;
   union valor *f;
   struct asr * arbol;  // Para los apuntadores a �rbol sint�ctico

#line 312 "reconocedor.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_RECONOCEDOR_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   83

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  13
/* YYNRULES -- Number of rules.  */
#define YYNRULES  37
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  87

#define YYUNDEFTOK  2
#define YYMAXUTOK   292


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      35,    36,    37
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   183,   183,   198,   199,   203,   204,   207,   210,   211,
     214,   221,   224,   233,   238,   241,   246,   249,   252,   255,
     256,   258,   259,   262,   263,   264,   267,   268,   269,   273,
     274,   275,   276,   279,   280,   281,   282,   283
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SUMA", "RESTA", "MULT", "DIV", "PARI",
  "PARF", "BGN", "END", "COLON", "SEMI", "ASSIGN", "EQUAL", "LESSER",
  "GREATER", "LEQUAL", "GEQUAL", "LARROW", "RES_FOR", "RES_DO",
  "RES_WHILE", "RES_IF", "THEN", "ELSE", "INT", "FLOAT", "RES_REPEAT",
  "UNTIL", "RES_STEP", "RES_PROGRAM", "VAR", "RES_READ", "RES_PRINT",
  "INTEGER", "FLOATING", "ID", "$accept", "prog", "opt_decls", "decl_lst",
  "decl", "type", "stmt", "opt_stmts", "stmt_lst", "expr", "term",
  "factor", "expression", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292
};
# endif

#define YYPACT_NINF (-29)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -22,   -26,    27,   -16,   -29,     1,    30,   -29,    39,    41,
      22,   -16,   -21,    22,    20,    46,     3,    22,    23,     3,
      35,    52,    56,   -29,   -29,   -29,   -29,   -29,    57,    50,
       3,     3,   -29,   -29,   -29,    59,    17,   -29,    47,    43,
     -29,    16,     3,    22,   -29,   -29,     3,    62,     4,     3,
       3,     3,     3,     3,     3,     3,     3,     3,    22,    71,
      16,   -29,    14,    22,   -29,    17,    17,    16,    16,    16,
      16,    16,   -29,   -29,    54,     3,     3,   -29,    22,    72,
       2,   -29,   -29,     3,     0,    22,   -29
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     4,     1,     0,     0,     3,     6,     0,
      20,     0,     0,    20,     0,     0,     0,     0,     0,     0,
       0,    22,     0,    19,     5,     8,     9,     7,     0,     0,
       0,     0,    31,    32,    30,     0,    25,    28,     0,     0,
      13,    17,     0,     0,     2,    18,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      10,    21,     0,     0,    29,    23,    24,    35,    33,    34,
      36,    37,    26,    27,    11,     0,     0,    15,     0,     0,
       0,    14,    16,     0,     0,     0,    12
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -29,   -29,   -29,    70,   -29,   -29,   -17,    69,    40,   -18,
     -24,    -8,   -28
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     6,     7,     8,    27,    21,    22,    23,    35,
      36,    37,    38
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      39,    41,    47,    49,    50,    49,    50,    49,    50,     1,
      31,     3,    64,    48,    25,    26,     5,    49,    50,    49,
      50,    85,    56,    57,    60,    65,    66,     4,    62,    32,
      33,    13,    83,    67,    68,    69,    70,    71,     9,    10,
      34,    74,    14,    76,    15,    16,    77,    79,    72,    73,
      17,    11,    12,    30,    42,    18,    19,    29,    80,    20,
      40,    81,    49,    50,    43,    84,    44,    45,    86,    46,
      63,    58,    59,    51,    52,    53,    54,    55,    75,    78,
      82,    24,    28,    61
};

static const yytype_int8 yycheck[] =
{
      17,    19,    30,     3,     4,     3,     4,     3,     4,    31,
       7,    37,     8,    31,    35,    36,    32,     3,     4,     3,
       4,    21,     5,     6,    42,    49,    50,     0,    46,    26,
      27,     9,    30,    51,    52,    53,    54,    55,    37,     9,
      37,    58,    20,    29,    22,    23,    63,    75,    56,    57,
      28,    12,    11,     7,    19,    33,    34,    37,    76,    37,
      37,    78,     3,     4,    12,    83,    10,    10,    85,    19,
       8,    24,    29,    14,    15,    16,    17,    18,     7,    25,
       8,    11,    13,    43
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    31,    39,    37,     0,    32,    40,    41,    42,    37,
       9,    12,    11,     9,    20,    22,    23,    28,    33,    34,
      37,    44,    45,    46,    41,    35,    36,    43,    45,    37,
       7,     7,    26,    27,    37,    47,    48,    49,    50,    44,
      37,    47,    19,    12,    10,    10,    19,    50,    47,     3,
       4,    14,    15,    16,    17,    18,     5,     6,    24,    29,
      47,    46,    47,     8,     8,    48,    48,    47,    47,    47,
      47,    47,    49,    49,    44,     7,    29,    44,    25,    50,
      47,    44,     8,    30,    47,    21,    44
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    38,    39,    40,    40,    41,    41,    42,    43,    43,
      44,    44,    44,    44,    44,    44,    44,    44,    44,    45,
      45,    46,    46,    47,    47,    47,    48,    48,    48,    49,
      49,    49,    49,    50,    50,    50,    50,    50
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     6,     1,     0,     3,     1,     4,     1,     1,
       3,     4,    10,     2,     6,     5,     6,     2,     3,     1,
       0,     3,     1,     3,     3,     1,     3,     3,     1,     3,
       1,     1,     1,     3,     3,     3,     3,     3
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
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
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
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
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
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

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
  switch (yyn)
    {
  case 2:
#line 183 "reconocedor.y"
                                                   {
						   ASR *nodoRoot;
						   nodoRoot = nuevoNodo(NOTHING, NOTHING, NULL, PROGRAM, NOTHING, (yyvsp[-1].arbol), NULL, NULL, NULL, NULL);
						   printf("\n programa valido \n\n");
						   printf("########## TABLA DE SIMBOLOS ############\n\n");
						   printList();
						    printf("########## ARBOL SINTACTICO REDUCIDO ############\n\n");
						   printTree(nodoRoot);
                printf("########## START OF PROGRAM OUTPUT ############\n\n");
                interpreta(nodoRoot);
                printf("########## END OF PROGRAM OUTPUT ############\n\n");
						   exit(0);
						 }
#line 1550 "reconocedor.tab.c"
    break;

  case 4:
#line 199 "reconocedor.y"
                   {(yyval.arbol) = NULL;}
#line 1556 "reconocedor.tab.c"
    break;

  case 7:
#line 207 "reconocedor.y"
                          {(yyval.val) = insertID((yyvsp[-2].nombre), (yyvsp[0].entero));}
#line 1562 "reconocedor.tab.c"
    break;

  case 8:
#line 210 "reconocedor.y"
                {(yyval.entero) = INTEGER_NUMBER_VALUE;}
#line 1568 "reconocedor.tab.c"
    break;

  case 9:
#line 211 "reconocedor.y"
                {(yyval.entero) = FLOATING_POINT_NUMBER_VALUE;}
#line 1574 "reconocedor.tab.c"
    break;

  case 10:
#line 214 "reconocedor.y"
                      {

                          ASR *nodoID;
                          nodoID = nuevoNodo(NOTHING, NOTHING, (char *)(yyvsp[-2].nombre), ID_VALUE, SET, NULL, NULL, NULL, NULL, NULL);
                          (yyval.arbol) = nuevoNodo(NOTHING, NOTHING, NULL, SET, STMT, nodoID, (yyvsp[0].arbol), NULL, NULL, NULL);

                       }
#line 1586 "reconocedor.tab.c"
    break;

  case 11:
#line 221 "reconocedor.y"
                                   {
     				                         (yyval.arbol) = nuevoNodo(NOTHING, NOTHING, NULL, IF, IF_STMT, (yyvsp[-2].arbol), (yyvsp[0].arbol), NULL, NULL, NULL);
     				                       }
#line 1594 "reconocedor.tab.c"
    break;

  case 12:
#line 224 "reconocedor.y"
                                                                   {
     							   ASR *nodoID = nuevoNodo(NOTHING, NOTHING, (char *)(yyvsp[-8].nombre), ID_VALUE, FOR, NULL, NULL, NULL, NULL, NULL);
     							   ASR *nodoSet = nuevoNodo(NOTHING, NOTHING, NULL, SET, FOR, nodoID, (yyvsp[-6].arbol), NULL, NULL, NULL);
     							   ASR *nodoLt = nuevoNodo(NOTHING, NOTHING, NULL, LEQ, EXPRESION, nodoID, (yyvsp[-4].arbol), NULL, NULL, NULL);
     							   ASR *nodoStep = nuevoNodo(NOTHING, NOTHING, NULL, PLUS, EXPR, nodoID, (yyvsp[-2].arbol), NULL, NULL, NULL);
     							   ASR *nodoSet2 = nuevoNodo(NOTHING, NOTHING, NULL, SET, FOR, nodoID, nodoStep, NULL, NULL, NULL);
     							   (yyval.arbol) = nuevoNodo(NOTHING, NOTHING, NULL, FOR, ITER_STMT, nodoSet, nodoLt, nodoSet2, (yyvsp[0].arbol), NULL);
     							  }
#line 1607 "reconocedor.tab.c"
    break;

  case 13:
#line 233 "reconocedor.y"
                   {
     		ASR *nodoID;
     		nodoID = nuevoNodo(NOTHING,NOTHING, (char *)(yyvsp[0].nombre), ID_VALUE,READ, NULL, NULL, NULL, NULL, NULL);
     		(yyval.arbol) = nuevoNodo(NOTHING, NOTHING, NULL, READ, STMT, nodoID, NULL, NULL, NULL, NULL);
     		}
#line 1617 "reconocedor.tab.c"
    break;

  case 14:
#line 238 "reconocedor.y"
                                             {
     					                                  (yyval.arbol) = nuevoNodo(NOTHING,NOTHING,NULL, IFELSE , IF_STMT , (yyvsp[-4].arbol),(yyvsp[-2].arbol),(yyvsp[0].arbol), NULL, NULL);
     					                               }
#line 1625 "reconocedor.tab.c"
    break;

  case 15:
#line 242 "reconocedor.y"
                                        {
     					 (yyval.arbol) = nuevoNodo(NOTHING,NOTHING,NULL,WHILE, ITER_STMT, (yyvsp[-2].arbol), (yyvsp[0].arbol), NULL, NULL, NULL);
     					 }
#line 1633 "reconocedor.tab.c"
    break;

  case 16:
#line 246 "reconocedor.y"
                                                  {
     						 (yyval.arbol) = nuevoNodo(NOTHING, NOTHING, NULL, REPEAT, ITER_STMT, (yyvsp[-4].arbol), (yyvsp[-1].arbol), NULL, NULL, NULL);
     						}
#line 1641 "reconocedor.tab.c"
    break;

  case 17:
#line 249 "reconocedor.y"
                      {
     		   (yyval.arbol) = nuevoNodo(NOTHING, NOTHING, NULL, PRINT, STMT, (yyvsp[0].arbol), NULL, NULL, NULL, NULL);
     		   }
#line 1649 "reconocedor.tab.c"
    break;

  case 18:
#line 252 "reconocedor.y"
                         {(yyval.arbol) = (yyvsp[-1].arbol);}
#line 1655 "reconocedor.tab.c"
    break;

  case 19:
#line 255 "reconocedor.y"
                     {(yyval.arbol) = (yyvsp[0].arbol);}
#line 1661 "reconocedor.tab.c"
    break;

  case 20:
#line 256 "reconocedor.y"
                   {(yyval.arbol) = NULL;}
#line 1667 "reconocedor.tab.c"
    break;

  case 21:
#line 258 "reconocedor.y"
                              {(yyval.arbol) = nuevoNodo(NOTHING,NOTHING,NULL,PYC, STMT_LST, (yyvsp[-2].arbol),(yyvsp[0].arbol), NULL, NULL, NULL);}
#line 1673 "reconocedor.tab.c"
    break;

  case 22:
#line 259 "reconocedor.y"
                {(yyval.arbol) = nuevoNodo(NOTHING,NOTHING,NULL,PYC_S, STMT_LST, (yyvsp[0].arbol), NULL, NULL, NULL, NULL);}
#line 1679 "reconocedor.tab.c"
    break;

  case 23:
#line 262 "reconocedor.y"
                       {(yyval.arbol) = nuevoNodo(NOTHING, NOTHING, NULL, PLUS, EXPR, (yyvsp[-2].arbol), (yyvsp[0].arbol), NULL, NULL, NULL);}
#line 1685 "reconocedor.tab.c"
    break;

  case 24:
#line 263 "reconocedor.y"
                        {(yyval.arbol) = nuevoNodo(NOTHING, NOTHING, NULL, MINUS, EXPR, (yyvsp[-2].arbol), (yyvsp[0].arbol), NULL, NULL, NULL);}
#line 1691 "reconocedor.tab.c"
    break;

  case 25:
#line 264 "reconocedor.y"
            {(yyval.arbol) = (yyvsp[0].arbol);}
#line 1697 "reconocedor.tab.c"
    break;

  case 26:
#line 267 "reconocedor.y"
                        {(yyval.arbol) = nuevoNodo(NOTHING, NOTHING, NULL, STAR, EXPR, (yyvsp[-2].arbol), (yyvsp[0].arbol), NULL, NULL, NULL);}
#line 1703 "reconocedor.tab.c"
    break;

  case 27:
#line 268 "reconocedor.y"
                       {(yyval.arbol) = nuevoNodo(NOTHING, NOTHING, NULL, FORWARD_SLASH, EXPR, (yyvsp[-2].arbol), (yyvsp[0].arbol), NULL, NULL, NULL);}
#line 1709 "reconocedor.tab.c"
    break;

  case 28:
#line 269 "reconocedor.y"
              {(yyval.arbol) = (yyvsp[0].arbol);}
#line 1715 "reconocedor.tab.c"
    break;

  case 29:
#line 273 "reconocedor.y"
                        {(yyval.arbol) = (yyvsp[-1].arbol);}
#line 1721 "reconocedor.tab.c"
    break;

  case 30:
#line 274 "reconocedor.y"
              {(yyval.arbol) = nuevoNodo(NOTHING, NOTHING, (char*)(yyvsp[0].nombre), ID_VALUE, FACTOR, NULL, NULL, NULL, NULL, NULL);}
#line 1727 "reconocedor.tab.c"
    break;

  case 31:
#line 275 "reconocedor.y"
              {(yyval.arbol) = nuevoNodo((int)(yyvsp[0].arbol), NOTHING, NULL, INTEGER_NUMBER_VALUE, TERM, NULL, NULL, NULL, NULL, NULL);}
#line 1733 "reconocedor.tab.c"
    break;

  case 32:
#line 276 "reconocedor.y"
               {(yyval.arbol) = nuevoNodo(NOTHING, doubleVal, NULL, FLOATING_POINT_NUMBER_VALUE, TERM, NULL, NULL, NULL, NULL, NULL);}
#line 1739 "reconocedor.tab.c"
    break;

  case 33:
#line 279 "reconocedor.y"
                              {(yyval.arbol) = nuevoNodo(NOTHING, NOTHING, NULL, LT, EXPRESION, (yyvsp[-2].arbol), (yyvsp[0].arbol), NULL, NULL, NULL);}
#line 1745 "reconocedor.tab.c"
    break;

  case 34:
#line 280 "reconocedor.y"
                               {(yyval.arbol) = nuevoNodo(NOTHING, NOTHING, NULL, GT, EXPRESION, (yyvsp[-2].arbol), (yyvsp[0].arbol), NULL, NULL, NULL);}
#line 1751 "reconocedor.tab.c"
    break;

  case 35:
#line 281 "reconocedor.y"
                             {(yyval.arbol) = nuevoNodo(NOTHING, NOTHING, NULL, EQ, EXPRESION, (yyvsp[-2].arbol), (yyvsp[0].arbol), NULL, NULL, NULL);}
#line 1757 "reconocedor.tab.c"
    break;

  case 36:
#line 282 "reconocedor.y"
                              {(yyval.arbol) = nuevoNodo(NOTHING, NOTHING, NULL, LEQ, EXPRESION, (yyvsp[-2].arbol), (yyvsp[0].arbol), NULL, NULL, NULL);}
#line 1763 "reconocedor.tab.c"
    break;

  case 37:
#line 283 "reconocedor.y"
                              {(yyval.arbol) = nuevoNodo(NOTHING, NOTHING, NULL, GEQ, EXPRESION, (yyvsp[-2].arbol), (yyvsp[0].arbol), NULL, NULL, NULL);}
#line 1769 "reconocedor.tab.c"
    break;


#line 1773 "reconocedor.tab.c"

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
                  yystos[+*yyssp], yyvsp);
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
#line 288 "reconocedor.y"




int yyerror(char const * s) {
  fprintf(stderr, "%s,%s\n", s,yytext);
}

void main(int argc, char * argv[]) {

  if(argc < 2) {
   printf("Error, falta nombre de archivo\n");
   exit(1);
  }

  yyin = fopen(argv[1], "r");

  if(yyin == NULL) {
    printf("Error, archivo no existe\n");
    exit(1);
  }

  yyparse();
}

/* La funci�n nuevoNodo crea un nuevo nodo para un �rbol sint�ctico reducIDo.
   Los par�metros son el tipo de nodo (operaci�n u operando), el valor que
   representa qu� operando se est� usando o el valor del n�mero en cuesti�n y
   los apuntadores a los sub�rboles correspondientes.
*/




void printList() {
	 struct nodoTS * ptr = head;

	printf("\n[ ");

	while(ptr != NULL) {
	 if(ptr->type == INTEGER_NUMBER_VALUE) printf("(%s, int, %d) ",ptr->nombre, ptr->value.intVal);
	 else if(ptr->type == FLOATING_POINT_NUMBER_VALUE) printf("(%s, float, %.2f) ", ptr->nombre, ptr->value.doubleVal);
	 ptr = ptr->next;
	}

	printf(" ] \n\n");

}

ASR * nuevoNodo(int iVal, double dVal, char* idName, int type, int parentNodeType, ASR * ptr1, ASR * ptr2, ASR * ptr3, ASR * ptr4, ASR * nextNode) {

   ASR * newNodePtr = (ASR *) malloc(sizeof(ASR));
   newNodePtr->type = type;
   newNodePtr->parentNodeType = parentNodeType;

   newNodePtr->arrPtr[0] = ptr1;
   newNodePtr->arrPtr[1] = ptr2;
   newNodePtr->arrPtr[2] = ptr3;
   newNodePtr->arrPtr[3] = ptr4;

   newNodePtr->next = nextNode;

   //printf("%p\n",ptr1);
   // Assign the values. They could be equal to NOTHING.
   if(type == INTEGER_NUMBER_VALUE){

     newNodePtr->value.intVal = iVal;
   }
   else if(type == FLOATING_POINT_NUMBER_VALUE){

     newNodePtr->value.doubleVal = dVal;
   }
   else if(type == ID_VALUE){

     // Malloc for the identifier's name
     newNodePtr->value.idName = (char *) malloc(strlen(idName) + 1);
     strcpy (newNodePtr->value.idName, idName);
   }
   return newNodePtr;
}

struct nodoTS * insertID(char * id, int tipo) {

	struct nodoTS * link = (struct nodoTS *) malloc(sizeof(struct nodoTS));

	link->type = tipo;
	link->value.intVal = 0;
	link->nombre = id;
	link->next = head;
	head = link;

}

struct nodoTS* auxRetrieveFromSymbolTable(char const *symbolName, struct nodoTS* symbolTableHead){

  struct nodoTS *currPtr = symbolTableHead;

  // Traverse the linked list and compare the name of the current symbol
  // with the name of the symbol that you're looking for.
  while(currPtr != NULL){

    assert(currPtr->nombre);

    if(strcmp(currPtr->nombre, symbolName) == 0)
      return currPtr;

    currPtr = currPtr->next;
  }

  // If the symbol was not found in the function's symbol table, it must be looked for
  // in the symbol table of the main function.
  // handleError(ERROR_CODE_SYMBOL_NOT_FOUND, ERROR_MESSAGE_SYMBOL_NOT_FOUND);
  return NULL;
}

struct nodoTS* retrieveFromSymbolTable(char const *symbolName){

  struct nodoTS *currPtr = NULL;



  // If a function is being executed but the symbol was not found in the function's
  // symbol table or if no function is being executed, then look for the symbol in
  // the main function's symbol table.
  if(!currPtr)
    currPtr = auxRetrieveFromSymbolTable(symbolName, head);



  return currPtr;
}

void setIntValueToSymbol(char const *symbolName, int newIntegerValue){

  struct nodoTS *symbolPtr = retrieveFromSymbolTable(symbolName);

  if(symbolPtr != NULL){

    // Check that the symbol does in fact store an integer
    if(symbolPtr->type == INTEGER_NUMBER_VALUE){

      symbolPtr->value.intVal = newIntegerValue;
    }
    else{

      // Error out and exit!
      printf("error");
    }
  }
  else{

    // Error out and exit!
    printf("error");
  }
}

void setDoubleValueToSymbol(char const *symbolName, double newDoubleValue){

  struct nodoTS *symbolPtr = retrieveFromSymbolTable(symbolName);

  if(symbolPtr != NULL){

    // Check that the symbol does in fact store a double
    if(symbolPtr->type == FLOATING_POINT_NUMBER_VALUE){

      symbolPtr->value.doubleVal = newDoubleValue;
    }
    else{

      // Error out and exit!
      printf("error");
    }
  }
}




int computeSubTreeNodeTypeCount(int nodeType, ASR * node){

  if(node == NULL)
    return 0;

  int count = 0;

  // In case it is a constant
  if(node->type == nodeType){

    count++;
  }

  // In case it is an ID
  else if(node->type == ID_VALUE){

    struct nodoTS * currIdNode = retrieveFromSymbolTable(node->value.idName);

    if(currIdNode->type == nodeType)
      count++;
  }

  int i = 0;
  for(i = 0; i < 4; i++){

    count += computeSubTreeNodeTypeCount(nodeType, node->arrPtr[i]);
  }

  return count;
}

int exprIsTypeConsistent(ASR * exprNode){

  // Count the number of subtree nodes of both data type
  // If the expression is type-consistent, then one of those counts
  // will be zero
  int intSubTreeNodeCount = computeSubTreeNodeTypeCount(INTEGER_NUMBER_VALUE, exprNode);
  int doubleSubTreeNodeCount = computeSubTreeNodeTypeCount(FLOATING_POINT_NUMBER_VALUE, exprNode);

  // printTree(exprNode);
  // printf("intSubTreeNodeCount: %d; doubleSubTreeNodeCount: %d\n", intSubTreeNodeCount, doubleSubTreeNodeCount);

  if(intSubTreeNodeCount > 0 && doubleSubTreeNodeCount == 0)
    return INTEGER_NUMBER_VALUE;

  else if(intSubTreeNodeCount == 0 && doubleSubTreeNodeCount > 0)
    return FLOATING_POINT_NUMBER_VALUE;

  // If the control gets here, there is a mistake: types are inconsistent
  // Error out and exit!
  //handleError(ERROR_CODE_DATA_TYPE_MISMATCH, ERROR_MESSAGE_DATA_TYPE_MISMATCH);

  return 0;
}

int isIntegerExpr(ASR * exprNode){

  return exprIsTypeConsistent(exprNode) == INTEGER_NUMBER_VALUE;
}

int isFloatingPointExpr(ASR * exprNode){

  return exprIsTypeConsistent(exprNode) == FLOATING_POINT_NUMBER_VALUE;
}



int func_exprInt(ASR * exprIntNode){

  // If we enter an EXPR node, we must at least one term.
  assert(exprIntNode != NULL);

  if(exprIntNode->type == PLUS){

    return func_exprInt(exprIntNode->arrPtr[0])
      + func_exprInt(exprIntNode->arrPtr[1]);
  }
  else if(exprIntNode->type == MINUS){

    return func_exprInt(exprIntNode->arrPtr[0])
      - func_exprInt(exprIntNode->arrPtr[1]);
  }
  else if(exprIntNode->type == STAR){

    return func_exprInt(exprIntNode->arrPtr[0])
      * func_exprInt(exprIntNode->arrPtr[1]);
  }
  else if(exprIntNode->type == FORWARD_SLASH){

    return func_exprInt(exprIntNode->arrPtr[0])
      / func_exprInt(exprIntNode->arrPtr[1]);
  }

  assert(exprIntNode->type == INTEGER_NUMBER_VALUE
    || exprIntNode->type == ID_VALUE
    || exprIntNode->type == FUNCTION_VALUE);

  int valToReturn = 0;

  if(exprIntNode->type == INTEGER_NUMBER_VALUE){

    valToReturn = exprIntNode->value.intVal;
  }
  else if(exprIntNode->type == ID_VALUE){

    struct nodoTS * currNode = retrieveFromSymbolTable(exprIntNode->value.idName);
    assert(currNode->type == INTEGER_NUMBER_VALUE);
    //printSymbolTableNode(currNode);
    valToReturn = currNode->value.intVal;
  }
  /*else if(exprIntNode->type == FUNCTION_VALUE){

    func_func(exprIntNode);
    // As we know that this is a function, then we know that this symbol must exist in the symbol table
    // of the main function, so directly call the auxiliary method that looks in that specific symbol table.
    struct SymbolTableNode* currFunc = auxRetrieveFromSymbolTable(exprIntNode->value.idName, mainFunctionSymbolTableHead);
    assert(currFunc->returnType == INTEGER_NUMBER_VALUE);
    // valToReturn = currFunc->value.intVal;
    valToReturn = ptrFunctionCallStackTop->value.intVal;
    popFunctionCallToStack();
  }*/

  return valToReturn;
}

double func_exprDouble(ASR * exprDoubleNode){
  // If we enter an EXPR node, we must at least one term.
  assert(exprDoubleNode != NULL);

  if(exprDoubleNode->type == PLUS){

    return func_exprDouble(exprDoubleNode->arrPtr[0])
      + func_exprDouble(exprDoubleNode->arrPtr[1]);
  }
  else if(exprDoubleNode->type == MINUS){

    return func_exprDouble(exprDoubleNode->arrPtr[0])
      - func_exprDouble(exprDoubleNode->arrPtr[1]);
  }
  else if(exprDoubleNode->type == STAR){

    return func_exprDouble(exprDoubleNode->arrPtr[0])
      * func_exprDouble(exprDoubleNode->arrPtr[1]);
  }
  else if(exprDoubleNode->type == FORWARD_SLASH){

    return func_exprDouble(exprDoubleNode->arrPtr[0])
      / func_exprDouble(exprDoubleNode->arrPtr[1]);
  }

  assert(exprDoubleNode->type == ID_VALUE
    || exprDoubleNode-> type == FLOATING_POINT_NUMBER_VALUE
    || exprDoubleNode-> type == FUNCTION_VALUE);

  // handleError(ERROR_CODE_DATA_TYPE_MISMATCH, ERROR_MESSAGE_DATA_TYPE_MISMATCH);

  double valToReturn = 0;

  if(exprDoubleNode->type == FLOATING_POINT_NUMBER_VALUE){
    valToReturn = exprDoubleNode->value.doubleVal;
  }
  else if(exprDoubleNode->type == ID_VALUE){

    struct nodoTS * currNode = retrieveFromSymbolTable(exprDoubleNode->value.idName);
    assert(currNode->type == FLOATING_POINT_NUMBER_VALUE);
    //printSymbolTableNode(currNode);
    valToReturn = currNode->value.doubleVal;
  }
  /*else if(exprDoubleNode-> type == FUNCTION_VALUE){

    func_func(exprDoubleNode);
    // As we know that this is a function, then we know that this symbol must exist in the symbol table
    // of the main function, so directly call the auxiliary method that looks in that specific symbol table.
    struct SymbolTableNode* currFunc = auxRetrieveFromSymbolTable(exprDoubleNode->value.idName, mainFunctionSymbolTableHead);
    assert(currFunc->returnType == FLOATING_POINT_NUMBER_VALUE);
    // valToReturn = currFunc->value.doubleVal;
    valToReturn = ptrFunctionCallStackTop->value.doubleVal;
    popFunctionCallToStack();
  }*/

  return valToReturn;
}


int func_expression(ASR* nodeExpr){

  // If we enter an EXPRESION node, we must have two 'expr' terms
  assert(nodeExpr->arrPtr[0] != NULL);
  assert(nodeExpr->arrPtr[1] != NULL);

  if(isIntegerExpr(nodeExpr->arrPtr[0])){

    // Assert that the second 'expr' term also contains an integer expression
    assert(isIntegerExpr(nodeExpr->arrPtr[1]));
    //printNodeType(nodeExpr->type, "hola");
    int intExpresionLeftSide = func_exprInt(nodeExpr->arrPtr[0]);
    int intExpresionRightSide = func_exprInt(nodeExpr->arrPtr[1]);

    switch(nodeExpr->type){

      case LT:
        return intExpresionLeftSide < intExpresionRightSide;

      case GT:
        return intExpresionLeftSide > intExpresionRightSide;

      case EQ:
        return intExpresionLeftSide == intExpresionRightSide;

      case LEQ:
        return intExpresionLeftSide <= intExpresionRightSide;

      case GEQ:
        return intExpresionLeftSide >= intExpresionRightSide;
    }
  }
  else{

    assert(isFloatingPointExpr(nodeExpr->arrPtr[0]));

    // Assert that the second 'expr' term also contains an floating-point expression
    assert(isFloatingPointExpr(nodeExpr->arrPtr[1]));

    double doubleExpresionLeftSide = func_exprDouble(nodeExpr->arrPtr[0]);
    int doubleExpresionRightSide = func_exprDouble(nodeExpr->arrPtr[1]);

    switch(nodeExpr->type){

      case LT:
        return doubleExpresionLeftSide < doubleExpresionRightSide;

      case GT:
        return doubleExpresionLeftSide > doubleExpresionRightSide;

      case EQ:
        return doubleExpresionLeftSide == doubleExpresionRightSide;

      case LEQ:
        return doubleExpresionLeftSide <= doubleExpresionRightSide;

      case GEQ:
        return doubleExpresionLeftSide >= doubleExpresionRightSide;
    }
  }

  // Control should never reach this part of the function.
  assert(NULL);
  return -1;
}

int readInt(){

  int intVal = -1;
  printf("escribe tu entero: ");
  int scanfReturnValue = scanf("%d", &intVal);
  assert(scanfReturnValue > 0);
  return intVal;
}


double readDouble(){

  double doubleVal = -1.0;
  printf("Escribe tu numero de punto flotante: ");
  int scanfReturnValue = scanf("%lf", &doubleVal);

  assert(scanfReturnValue > 0);
  return doubleVal;
}


/* La funci�n recorre es el int�rprtete en este caso. Simplemente recorre
   el �rbol en postorden para obtener los valores correspondientes.
*/

void printNodeType(int type, char* label){

  // If our names array contains an entry for this type
  if(type >= 0 && type < sizeof(SyntaxTreeNodeTypeName)){

    printf("%s: %s\n", label, SyntaxTreeNodeTypeName[type]);
  }
  else{

    printf("%s: %d\n", label, type);
  }
}

void printTree(ASR * node){

  if(node == NULL)
    return;

  printNodeType(node->type, "type");
  //printf("address = %p\n", node);
  printNodeType(node->parentNodeType, "parentNodeType");

  if(node->type == INTEGER_NUMBER_VALUE){

    printf("Node value = %d\n", node->value.intVal);
  }

  else if(node->type == ID_VALUE){

    printf("Node value = %s\n", node->value.idName);
  }

  else if(node->type == FLOATING_POINT_NUMBER_VALUE){

    printf("Node value = %f\n", node->value.doubleVal);
  }

  // Print the addresses of the current node's children
  int i = 0;
  /*
  for(i = 0; i < 4; i++)
    printf("ptr #%d: %p\n", i + 1, node->arrPtr[i]);
  */
  printf("\n");

  // Now call the printing of the current node's children
  for(i = 0; i < 4; i++)
    printTree(node->arrPtr[i]);
}

void func_read(ASR * nodeRead){
  assert(nodeRead->arrPtr[0] != NULL);

  struct nodoTS * currNode = retrieveFromSymbolTable(nodeRead->arrPtr[0]->value.idName);

  int valueToSet;
  double doubleValueToSet;

  switch (currNode->type) {
    case INTEGER_NUMBER_VALUE:
    valueToSet = readInt();
    setIntValueToSymbol(currNode->nombre,valueToSet);
    assert(valueToSet == currNode->value.intVal);

    break;
    case FLOATING_POINT_NUMBER_VALUE:
    doubleValueToSet = readDouble();
    setDoubleValueToSymbol(currNode->nombre, doubleValueToSet);
    assert(doubleValueToSet == currNode->value.doubleVal);
    break;
  }

}

void func_print(ASR * printNode){
  assert(printNode->arrPtr[0] != NULL);

  if(printNode->arrPtr[0]->type == INTEGER_NUMBER_VALUE){

    printf("%d\n", printNode->arrPtr[0]->value.intVal);
  }
  else if(printNode->arrPtr[0]->type == FLOATING_POINT_NUMBER_VALUE){
    printf("%.2f\n", printNode->arrPtr[0]->value.doubleVal);
  } else if(printNode->arrPtr[0]->parentNodeType == EXPR
    || printNode->arrPtr[0]->parentNodeType == TERM
    || printNode->arrPtr[0]->parentNodeType == FACTOR){
      if(isIntegerExpr(printNode->arrPtr[0])){

        printf("%d\n", func_exprInt(printNode->arrPtr[0]));
      }
      else{

        assert(isFloatingPointExpr(printNode->arrPtr[0]));
        printf("%lf\n", func_exprDouble(printNode->arrPtr[0]));
      }
    }
  }

  void func_assign(ASR * setNode){

    // Each set statement must contain both the corresponding
    // id and the desired value
    assert(setNode->arrPtr[0] != NULL);
    assert(setNode->arrPtr[1] != NULL);

    // printf("symbol to retrieve: %s\n", setNode->arrPtr[0]->value.idName);
    struct nodoTS * currNode = retrieveFromSymbolTable(setNode->arrPtr[0]->value.idName);

    assert(currNode != NULL);

    int exprValueToSet;
    double exprDoubleValueToSet;

    switch(currNode->type){

      case INTEGER_NUMBER_VALUE:
        exprValueToSet = func_exprInt(setNode->arrPtr[1]);
        setIntValueToSymbol(currNode->nombre, exprValueToSet);
        //printSymbolTableNode(currNode);
        assert(exprValueToSet == currNode->value.intVal);
        break;

      case FLOATING_POINT_NUMBER_VALUE:
        exprDoubleValueToSet = func_exprDouble(setNode->arrPtr[1]);
        setDoubleValueToSymbol(currNode->nombre, exprDoubleValueToSet);
        //printSymbolTableNode(currNode);
        assert(exprDoubleValueToSet == currNode->value.doubleVal);
        break;

    }
  }




  void func_if(ASR * nodeIf){

    assert(nodeIf->arrPtr[0] != NULL);

    if(func_expression(nodeIf->arrPtr[0])){
      if(nodeIf->arrPtr[1] != NULL){
        interpreta(nodeIf->arrPtr[1]);
      }
    }
  }

  void func_ifElse(ASR * nodeIfElse){

    assert(nodeIfElse->arrPtr[0] != NULL);

    if(func_expression(nodeIfElse->arrPtr[0])){
      interpreta(nodeIfElse->arrPtr[1]);
    } else {
      interpreta(nodeIfElse->arrPtr[2]);
    }
  }

  void func_while(ASR * nodeWhile){
    assert(nodeWhile->arrPtr[0] != NULL);

    while(func_expression(nodeWhile->arrPtr[0])){
      interpreta(nodeWhile->arrPtr[1]);
    }
  }

  void func_for(ASR * nodeFor){

    assert(nodeFor->arrPtr[0] != NULL);
    assert(nodeFor->arrPtr[1] != NULL);
    assert(nodeFor->arrPtr[2] != NULL);

    func_assign(nodeFor->arrPtr[0]);

    while(func_expression(nodeFor->arrPtr[1])){
      interpreta(nodeFor->arrPtr[3]);
      func_assign(nodeFor->arrPtr[2]);
    }
  }
 //preguntarle al profe a que se refefiere con el REPEAT

  void func_repeat(ASR * nodeRepeat){
    //assert(nodeRepeat->arrPtr[0] != NULL);
    assert(nodeRepeat->arrPtr[1] != NULL);

    do {
      interpreta(nodeRepeat->arrPtr[0]);
    } while(func_expression(nodeRepeat->arrPtr[1]));
  }

 void interpreta(ASR * node){

   if(node == NULL)
   return;

   switch (node->type) {
     case PROGRAM:
     break;

     case PRINT:
     func_print(node);
     break;

     case READ:
     func_read(node);
     break;

     case SET:
     func_assign(node);
     break;

     case IF:
     func_if(node);
     break;

     case IFELSE:
     func_ifElse(node);
     break;

     case WHILE:
     func_while(node);
     break;

     case FOR:
     func_for(node);
     break;

     case REPEAT:
     func_repeat(node);
     break;
   }


   if(node->type != IF
    && node->type != IFELSE
    && node->type != WHILE
    && node->type != FOR){

    int i;
    for(i = 0; i < 4; i++)
      interpreta(node->arrPtr[i]);
    }
 }
