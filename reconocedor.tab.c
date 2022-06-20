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

int numParam = 0;
int funcRunning = 0;
char * currentFuncName;

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

struct nodoTSF {
  char * nombre;
  int returnType;
  int numParams;
  struct nodoTS * tsl;
  ASR * cuerpo;
  union {
    int intVal;
    double doubleVal;
  } value;
  struct nodoTSF * next;
};




extern int yylex();
int yyerror(char const * s);
ASR * nuevoNodo(int, double, char*, int, int, ASR*,ASR*,ASR*,ASR*,ASR*);
extern char * yytext;
extern FILE *yyin;
//void findID(char * id);
struct nodoTS * insertID(char* id, int tipo);
void insertFunc(char*, int, int, struct nodoTS*, ASR*);
void insertIDFunc(struct nodoTS**, char*, int);
void printList();
void printListTsl(struct nodoTS * ptr, char * nombre);
void printListTsf();
void printTree(ASR * raiz);
void preTreePrinting(ASR * node, char * id);
struct nodoTSF * retrieveFromFunSymbolTable(char * id);
void interpreta(ASR * raiz);




struct nodoTS * head;
struct nodoTS * tslHead;
struct nodoTSF * functionSymbolTableHead;


#line 239 "reconocedor.tab.c"

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
    RES_FUN = 292,
    COMMA = 293,
    RES_RETURN = 294,
    ID = 295
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 182 "reconocedor.y"

   struct nodoTS * val;
   char * nombre;
   int entero;  // Para las constantes num�ricas
   double doubleVal;
   union valor *f;
   struct asr * arbol;  // Para los apuntadores a �rbol sint�ctico

#line 341 "reconocedor.tab.c"

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
#define YYLAST   113

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  59
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  127

#define YYUNDEFTOK  2
#define YYMAXUTOK   295


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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   209,   209,   228,   229,   233,   234,   237,   240,   241,
     246,   247,   250,   251,   253,   259,   264,   265,   267,   268,
     271,   275,   276,   279,   280,   283,   288,   296,   300,   309,
     315,   319,   324,   328,   332,   335,   338,   339,   341,   342,
     345,   346,   347,   350,   351,   352,   356,   357,   358,   359,
     360,   362,   366,   372,   376,   381,   382,   383,   384,   385
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
  "INTEGER", "FLOATING", "RES_FUN", "COMMA", "RES_RETURN", "ID", "$accept",
  "prog", "opt_decls", "decl_lst", "decl", "type", "opt_fun_decls",
  "fun_decls", "fun_decl", "oparams", "params", "param",
  "opt_decls_for_function", "decls_for_function", "dec_for_function",
  "stmt", "opt_stmts", "stmt_lst", "expr", "term", "factor", "opt_exprs",
  "expr_lst", "expression", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295
};
# endif

#define YYPACT_NINF (-57)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -25,   -29,    16,   -10,   -57,   -12,    -6,   -57,    13,    38,
       1,    45,    -6,   -57,   -10,   -15,    53,    28,   -57,   -57,
     -57,   -57,   -57,    24,    28,    31,    65,     0,    28,    33,
       0,     0,    56,    67,    68,   -57,    74,    78,   -57,    49,
      79,    69,     0,     0,   -57,   -57,    83,    66,    47,   -57,
      70,    62,   -57,    30,    30,     0,    28,   -57,   -15,    84,
      24,   -57,     0,    88,    15,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    28,    91,    30,   -57,   -57,
     -15,   -57,     9,    28,   -57,    30,    92,    61,    47,    47,
      30,    30,    30,    30,    30,   -57,   -57,    76,     0,    -2,
       0,   -57,   -57,     0,    28,    94,   -57,    63,    95,   -57,
      93,     5,    30,   -57,   -57,    96,    28,    77,     0,   -15,
      98,   -57,    11,   -57,   -57,    28,   -57
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     4,     1,     0,    11,     3,     6,     0,
       0,     0,    10,    13,     0,     0,     0,    37,    12,     5,
       8,     9,     7,    17,    37,     0,     0,     0,     0,     0,
       0,     0,     0,    39,     0,    36,     0,     0,    16,    19,
       0,     0,     0,     0,    48,    49,    47,     0,    42,    45,
       0,     0,    29,    33,    34,     0,     0,     2,     0,     0,
       0,    35,     0,     0,     0,    52,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    26,    38,    20,
       0,    18,     0,     0,    46,    54,     0,    51,    40,    41,
      57,    55,    56,    58,    59,    43,    44,    27,     0,    22,
       0,    31,    50,     0,     0,     0,    15,     0,     0,    21,
      24,     0,    53,    30,    32,     0,    37,     0,     0,     0,
       0,    23,     0,    25,    14,     0,    28
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -57,   -57,   -57,    97,   -57,   -56,   -57,   -57,   100,   -57,
      46,   -57,   -57,    -7,   -57,   -28,   -23,    57,   -26,    -9,
      -8,   -57,   -57,   -39
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     6,     7,     8,    22,    11,    12,    13,    37,
      38,    39,   108,   109,   110,    33,    34,    35,    47,    48,
      49,    86,    87,    50
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      51,    40,    79,    63,    53,    54,     1,    43,    66,    67,
     106,     3,    66,    67,    66,    67,     4,    64,    66,    67,
      20,    21,     5,    84,    99,    14,    44,    45,     9,    77,
     107,    10,   125,    66,    67,   118,    82,    24,   100,    85,
      46,    16,    90,    91,    92,    93,    94,    97,    25,    15,
      26,    27,    73,    74,    17,   101,    28,    88,    89,   105,
      23,    29,    30,   123,    36,    95,    96,    31,    32,    66,
      67,    41,    42,    52,   111,    55,   113,   112,    57,    56,
      68,    69,    70,    71,    72,    58,    59,    60,    62,    61,
      65,    76,   122,   120,    75,    80,    83,   126,    98,   103,
     102,   104,   114,   115,   116,   117,    81,   119,   124,   107,
     121,    19,    18,    78
};

static const yytype_int8 yycheck[] =
{
      28,    24,    58,    42,    30,    31,    31,     7,     3,     4,
      12,    40,     3,     4,     3,     4,     0,    43,     3,     4,
      35,    36,    32,     8,    80,    12,    26,    27,    40,    55,
      32,    37,    21,     3,     4,    30,    62,     9,    29,    65,
      40,    40,    68,    69,    70,    71,    72,    75,    20,    11,
      22,    23,     5,     6,     9,    83,    28,    66,    67,    98,
       7,    33,    34,   119,    40,    73,    74,    39,    40,     3,
       4,    40,     7,    40,   100,    19,   104,   103,    10,    12,
      14,    15,    16,    17,    18,    11,     8,    38,    19,    10,
       7,    29,   118,   116,    24,    11,     8,   125,     7,    38,
       8,    25,     8,    40,     9,    12,    60,    11,    10,    32,
     117,    14,    12,    56
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    31,    42,    40,     0,    32,    43,    44,    45,    40,
      37,    47,    48,    49,    12,    11,    40,     9,    49,    44,
      35,    36,    46,     7,     9,    20,    22,    23,    28,    33,
      34,    39,    40,    56,    57,    58,    40,    50,    51,    52,
      57,    40,     7,     7,    26,    27,    40,    59,    60,    61,
      64,    56,    40,    59,    59,    19,    12,    10,    11,     8,
      38,    10,    19,    64,    59,     7,     3,     4,    14,    15,
      16,    17,    18,     5,     6,    24,    29,    59,    58,    46,
      11,    51,    59,     8,     8,    59,    62,    63,    60,    60,
      59,    59,    59,    59,    59,    61,    61,    56,     7,    46,
      29,    56,     8,    38,    25,    64,    12,    32,    53,    54,
      55,    59,    59,    56,     8,    40,     9,    12,    30,    11,
      57,    54,    59,    46,    10,    21,    56
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    43,    43,    44,    44,    45,    46,    46,
      47,    47,    48,    48,    49,    49,    50,    50,    51,    51,
      52,    53,    53,    54,    54,    55,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    57,    57,    58,    58,
      59,    59,    59,    60,    60,    60,    61,    61,    61,    61,
      61,    62,    62,    63,    63,    64,    64,    64,    64,    64
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     7,     1,     0,     3,     1,     4,     1,     1,
       1,     0,     2,     1,    11,     8,     1,     0,     3,     1,
       3,     1,     0,     3,     1,     4,     3,     4,    10,     2,
       6,     5,     6,     2,     2,     3,     1,     0,     3,     1,
       3,     3,     1,     3,     3,     1,     3,     1,     1,     1,
       4,     1,     0,     3,     1,     3,     3,     3,     3,     3
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
#line 209 "reconocedor.y"
                                                                 {
						   ASR *nodoRoot;
						   nodoRoot = nuevoNodo(NOTHING, NOTHING, NULL, PROGRAM, NOTHING, (yyvsp[-1].arbol), NULL, NULL, NULL, NULL);
						   printf("\n programa valido \n\n");
						   printf("########## TABLA DE SIMBOLOS DE FUNCION main ############\n\n");
						   printList();
						    printf("########## ARBOL SINTACTICO REDUCIDO ############\n\n");
						   preTreePrinting(nodoRoot, "main");
                //printf("########## TABLA DE SIMBOLOS DE FUNCIONES ############\n\n");
                //printListTsl();
                printf("########## TABLA DE FUNCIONES ############\n\n");
                printListTsf();
                printf("########## START OF PROGRAM OUTPUT ############\n\n");
                interpreta(nodoRoot);
                printf("########## END OF PROGRAM OUTPUT ############\n\n");
						   exit(0);
						 }
#line 1613 "reconocedor.tab.c"
    break;

  case 7:
#line 237 "reconocedor.y"
                          {insertID((yyvsp[-2].nombre), (yyvsp[0].entero));}
#line 1619 "reconocedor.tab.c"
    break;

  case 8:
#line 240 "reconocedor.y"
                {(yyval.entero) = INTEGER_NUMBER_VALUE;}
#line 1625 "reconocedor.tab.c"
    break;

  case 9:
#line 241 "reconocedor.y"
                {(yyval.entero) = FLOATING_POINT_NUMBER_VALUE;}
#line 1631 "reconocedor.tab.c"
    break;

  case 14:
#line 254 "reconocedor.y"
                                                                                            {
                                                                                              insertFunc((yyvsp[-9].nombre), (yyvsp[-4].entero), numParam, tslHead, (yyvsp[-1].arbol));
                                                                                              numParam = 0;
                                                                                              tslHead = NULL;
                                                                                            }
#line 1641 "reconocedor.tab.c"
    break;

  case 15:
#line 259 "reconocedor.y"
                                                       {
                                                        insertFunc((yyvsp[-6].nombre), (yyvsp[-1].entero), numParam, tslHead, NULL);
                                                        numParam = 0;
                                                        }
#line 1650 "reconocedor.tab.c"
    break;

  case 18:
#line 267 "reconocedor.y"
                            {numParam++;}
#line 1656 "reconocedor.tab.c"
    break;

  case 19:
#line 268 "reconocedor.y"
               {numParam++;}
#line 1662 "reconocedor.tab.c"
    break;

  case 20:
#line 271 "reconocedor.y"
                      {insertIDFunc(&tslHead, (yyvsp[-2].nombre),(yyvsp[0].entero));}
#line 1668 "reconocedor.tab.c"
    break;

  case 25:
#line 283 "reconocedor.y"
                                     {insertIDFunc(&tslHead, (yyvsp[-2].nombre), (yyvsp[0].entero));}
#line 1674 "reconocedor.tab.c"
    break;

  case 26:
#line 288 "reconocedor.y"
                      {

                          ASR *nodoID;
                          nodoID = nuevoNodo(NOTHING, NOTHING, (char *)(yyvsp[-2].nombre), ID_VALUE, SET, NULL, NULL, NULL, NULL, NULL);
                          (yyval.arbol) = nuevoNodo(NOTHING, NOTHING, NULL, SET, STMT, nodoID, (yyvsp[0].arbol), NULL, NULL, NULL);

                       }
#line 1686 "reconocedor.tab.c"
    break;

  case 27:
#line 296 "reconocedor.y"
                                   {
     				                         (yyval.arbol) = nuevoNodo(NOTHING, NOTHING, NULL, IF, IF_STMT, (yyvsp[-2].arbol), (yyvsp[0].arbol), NULL, NULL, NULL);
     				                       }
#line 1694 "reconocedor.tab.c"
    break;

  case 28:
#line 300 "reconocedor.y"
                                                                   {
     							   ASR *nodoID = nuevoNodo(NOTHING, NOTHING, (char *)(yyvsp[-8].nombre), ID_VALUE, FOR, NULL, NULL, NULL, NULL, NULL);
     							   ASR *nodoSet = nuevoNodo(NOTHING, NOTHING, NULL, SET, FOR, nodoID, (yyvsp[-6].arbol), NULL, NULL, NULL);
     							   ASR *nodoLt = nuevoNodo(NOTHING, NOTHING, NULL, LEQ, EXPRESION, nodoID, (yyvsp[-4].arbol), NULL, NULL, NULL);
     							   ASR *nodoStep = nuevoNodo(NOTHING, NOTHING, NULL, PLUS, EXPR, nodoID, (yyvsp[-2].arbol), NULL, NULL, NULL);
     							   ASR *nodoSet2 = nuevoNodo(NOTHING, NOTHING, NULL, SET, FOR, nodoID, nodoStep, NULL, NULL, NULL);
     							   (yyval.arbol) = nuevoNodo(NOTHING, NOTHING, NULL, FOR, ITER_STMT, nodoSet, nodoLt, nodoSet2, (yyvsp[0].arbol), NULL);
     							  }
#line 1707 "reconocedor.tab.c"
    break;

  case 29:
#line 309 "reconocedor.y"
                   {
     		ASR *nodoID;
     		nodoID = nuevoNodo(NOTHING,NOTHING, (char *)(yyvsp[0].nombre), ID_VALUE,READ, NULL, NULL, NULL, NULL, NULL);
     		(yyval.arbol) = nuevoNodo(NOTHING, NOTHING, NULL, READ, STMT, nodoID, NULL, NULL, NULL, NULL);
     		}
#line 1717 "reconocedor.tab.c"
    break;

  case 30:
#line 315 "reconocedor.y"
                                             {
     					                                  (yyval.arbol) = nuevoNodo(NOTHING,NOTHING,NULL, IFELSE , IF_STMT , (yyvsp[-4].arbol),(yyvsp[-2].arbol),(yyvsp[0].arbol), NULL, NULL);
     					                               }
#line 1725 "reconocedor.tab.c"
    break;

  case 31:
#line 320 "reconocedor.y"
                                        {
     					 (yyval.arbol) = nuevoNodo(NOTHING,NOTHING,NULL,WHILE, ITER_STMT, (yyvsp[-2].arbol), (yyvsp[0].arbol), NULL, NULL, NULL);
     					 }
#line 1733 "reconocedor.tab.c"
    break;

  case 32:
#line 324 "reconocedor.y"
                                                  {
     						 (yyval.arbol) = nuevoNodo(NOTHING, NOTHING, NULL, REPEAT, ITER_STMT, (yyvsp[-4].arbol), (yyvsp[-1].arbol), NULL, NULL, NULL);
     						}
#line 1741 "reconocedor.tab.c"
    break;

  case 33:
#line 328 "reconocedor.y"
                      {
     		   (yyval.arbol) = nuevoNodo(NOTHING, NOTHING, NULL, PRINT, STMT, (yyvsp[0].arbol), NULL, NULL, NULL, NULL);
     		   }
#line 1749 "reconocedor.tab.c"
    break;

  case 34:
#line 332 "reconocedor.y"
                       {
           (yyval.arbol) = nuevoNodo(NOTHING, NOTHING, NULL, RETURN, STMT, (yyvsp[0].arbol), NULL, NULL, NULL, NULL);
     }
#line 1757 "reconocedor.tab.c"
    break;

  case 35:
#line 335 "reconocedor.y"
                         {(yyval.arbol) = (yyvsp[-1].arbol);}
#line 1763 "reconocedor.tab.c"
    break;

  case 36:
#line 338 "reconocedor.y"
                     {(yyval.arbol) = (yyvsp[0].arbol);}
#line 1769 "reconocedor.tab.c"
    break;

  case 37:
#line 339 "reconocedor.y"
                   {(yyval.arbol) = NULL;}
#line 1775 "reconocedor.tab.c"
    break;

  case 38:
#line 341 "reconocedor.y"
                              {(yyval.arbol) = nuevoNodo(NOTHING,NOTHING,NULL,PYC, STMT_LST, (yyvsp[-2].arbol),(yyvsp[0].arbol), NULL, NULL, NULL);}
#line 1781 "reconocedor.tab.c"
    break;

  case 39:
#line 342 "reconocedor.y"
                {(yyval.arbol) = nuevoNodo(NOTHING,NOTHING,NULL,PYC_S, STMT_LST, (yyvsp[0].arbol), NULL, NULL, NULL, NULL);}
#line 1787 "reconocedor.tab.c"
    break;

  case 40:
#line 345 "reconocedor.y"
                       {(yyval.arbol) = nuevoNodo(NOTHING, NOTHING, NULL, PLUS, EXPR, (yyvsp[-2].arbol), (yyvsp[0].arbol), NULL, NULL, NULL);}
#line 1793 "reconocedor.tab.c"
    break;

  case 41:
#line 346 "reconocedor.y"
                        {(yyval.arbol) = nuevoNodo(NOTHING, NOTHING, NULL, MINUS, EXPR, (yyvsp[-2].arbol), (yyvsp[0].arbol), NULL, NULL, NULL);}
#line 1799 "reconocedor.tab.c"
    break;

  case 42:
#line 347 "reconocedor.y"
            {(yyval.arbol) = (yyvsp[0].arbol);}
#line 1805 "reconocedor.tab.c"
    break;

  case 43:
#line 350 "reconocedor.y"
                        {(yyval.arbol) = nuevoNodo(NOTHING, NOTHING, NULL, STAR, EXPR, (yyvsp[-2].arbol), (yyvsp[0].arbol), NULL, NULL, NULL);}
#line 1811 "reconocedor.tab.c"
    break;

  case 44:
#line 351 "reconocedor.y"
                       {(yyval.arbol) = nuevoNodo(NOTHING, NOTHING, NULL, FORWARD_SLASH, EXPR, (yyvsp[-2].arbol), (yyvsp[0].arbol), NULL, NULL, NULL);}
#line 1817 "reconocedor.tab.c"
    break;

  case 45:
#line 352 "reconocedor.y"
              {(yyval.arbol) = (yyvsp[0].arbol);}
#line 1823 "reconocedor.tab.c"
    break;

  case 46:
#line 356 "reconocedor.y"
                        {(yyval.arbol) = (yyvsp[-1].arbol);}
#line 1829 "reconocedor.tab.c"
    break;

  case 47:
#line 357 "reconocedor.y"
              {(yyval.arbol) = nuevoNodo(NOTHING, NOTHING, (char*)(yyvsp[0].nombre), ID_VALUE, FACTOR, NULL, NULL, NULL, NULL, NULL);}
#line 1835 "reconocedor.tab.c"
    break;

  case 48:
#line 358 "reconocedor.y"
              {(yyval.arbol) = nuevoNodo((int)(yyvsp[0].arbol), NOTHING, NULL, INTEGER_NUMBER_VALUE, TERM, NULL, NULL, NULL, NULL, NULL);}
#line 1841 "reconocedor.tab.c"
    break;

  case 49:
#line 359 "reconocedor.y"
               {(yyval.arbol) = nuevoNodo(NOTHING, doubleVal, NULL, FLOATING_POINT_NUMBER_VALUE, TERM, NULL, NULL, NULL, NULL, NULL);}
#line 1847 "reconocedor.tab.c"
    break;

  case 50:
#line 360 "reconocedor.y"
                                {(yyval.arbol) = nuevoNodo(NOTHING, NOTHING, (char *)(yyvsp[-3].nombre), FUNCTION_VALUE, TERM, (yyvsp[-1].arbol), NULL, NULL, NULL, NULL);}
#line 1853 "reconocedor.tab.c"
    break;

  case 51:
#line 363 "reconocedor.y"
          {
            (yyval.arbol) = (yyvsp[0].arbol);
          }
#line 1861 "reconocedor.tab.c"
    break;

  case 52:
#line 367 "reconocedor.y"
          {
            (yyval.arbol) = NULL;
          }
#line 1869 "reconocedor.tab.c"
    break;

  case 53:
#line 373 "reconocedor.y"
          {
            (yyval.arbol) = nuevoNodo(NOTHING, NOTHING, NULL, PARAMETER_VALUE, EXPR_LST, (yyvsp[0].arbol), (yyvsp[-2].arbol), NULL, NULL, NULL);
          }
#line 1877 "reconocedor.tab.c"
    break;

  case 54:
#line 377 "reconocedor.y"
          {
            (yyval.arbol) = nuevoNodo(NOTHING, NOTHING, NULL, PARAMETER_VALUE, EXPR_LST, (yyvsp[0].arbol), NULL, NULL, NULL, NULL);
          }
#line 1885 "reconocedor.tab.c"
    break;

  case 55:
#line 381 "reconocedor.y"
                              {(yyval.arbol) = nuevoNodo(NOTHING, NOTHING, NULL, LT, EXPRESION, (yyvsp[-2].arbol), (yyvsp[0].arbol), NULL, NULL, NULL);}
#line 1891 "reconocedor.tab.c"
    break;

  case 56:
#line 382 "reconocedor.y"
                               {(yyval.arbol) = nuevoNodo(NOTHING, NOTHING, NULL, GT, EXPRESION, (yyvsp[-2].arbol), (yyvsp[0].arbol), NULL, NULL, NULL);}
#line 1897 "reconocedor.tab.c"
    break;

  case 57:
#line 383 "reconocedor.y"
                             {(yyval.arbol) = nuevoNodo(NOTHING, NOTHING, NULL, EQ, EXPRESION, (yyvsp[-2].arbol), (yyvsp[0].arbol), NULL, NULL, NULL);}
#line 1903 "reconocedor.tab.c"
    break;

  case 58:
#line 384 "reconocedor.y"
                              {(yyval.arbol) = nuevoNodo(NOTHING, NOTHING, NULL, LEQ, EXPRESION, (yyvsp[-2].arbol), (yyvsp[0].arbol), NULL, NULL, NULL);}
#line 1909 "reconocedor.tab.c"
    break;

  case 59:
#line 385 "reconocedor.y"
                              {(yyval.arbol) = nuevoNodo(NOTHING, NOTHING, NULL, GEQ, EXPRESION, (yyvsp[-2].arbol), (yyvsp[0].arbol), NULL, NULL, NULL);}
#line 1915 "reconocedor.tab.c"
    break;


#line 1919 "reconocedor.tab.c"

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
#line 390 "reconocedor.y"




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

void printListTsl(struct nodoTS * ptr, char * nombre) {
  struct nodoTS * pointer = ptr;
  printf("#################### TABLA DE SIMBOLOS DE LA FUNCION %s #########################\n\n", nombre);
  printf("\n[ ");

	while(ptr != NULL) {
	 if(ptr->type == INTEGER_NUMBER_VALUE) printf("(%s, int, %d) ",ptr->nombre, ptr->value.intVal);
	 else if(ptr->type == FLOATING_POINT_NUMBER_VALUE) printf("(%s, float, %.2f) ", ptr->nombre, ptr->value.doubleVal);
	 ptr = ptr->next;
	}

	printf(" ] \n\n");
  printf("#################### FINAL DE LA TABLA DE SIMBOLO DE LA FUNCION %s  #########################\n\n", nombre);
}

void printListTsf() {

  struct nodoTSF * ptr = functionSymbolTableHead;



	while(ptr != NULL) {
    printf("\n[ ");
	 if(ptr->returnType == INTEGER_NUMBER_VALUE) printf("(%s, # params: %d, return type: int) ",ptr->nombre, ptr->numParams);
	 else if(ptr->returnType == FLOATING_POINT_NUMBER_VALUE) printf("(%s, # params: %d, return type: float) ", ptr->nombre, ptr->numParams);
   printf(" ] \n\n");
   printListTsl(ptr->tsl, ptr->nombre);
   preTreePrinting(ptr->cuerpo, ptr->nombre);
	 ptr = ptr->next;
	}


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
   else if(type == FUNCTION_VALUE){

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

void insertFunc(char * id, int returnType, int numParams, struct nodoTS * tsl, ASR * cuerpo){
  struct nodoTSF * newFunc = (struct nodoTSF *) malloc(sizeof(struct nodoTSF));

  newFunc->nombre = id;
  newFunc->returnType = returnType;
  newFunc->numParams = numParams;
  newFunc->tsl = tsl;
  newFunc->cuerpo = cuerpo;

  newFunc->next = functionSymbolTableHead;
  functionSymbolTableHead = newFunc;

}

void insertIDFunc(struct nodoTS** tslHead, char * id, int tipo){
  struct nodoTS * newNode = (struct nodoTS *) malloc(sizeof(struct nodoTS));

  newNode->type = tipo;
  newNode->value.intVal = 0;
  newNode->nombre = id;
  newNode->next = (struct nodoTS*)(*tslHead);
  *tslHead = newNode;

}

struct nodoTSF* retrieveFromFunSymbolTable(char * nombre){
  struct nodoTSF *currPtr = functionSymbolTableHead;

  while(currPtr != NULL){
    assert(currPtr->nombre);

    if(strcmp(currPtr->nombre, nombre) == 0)
      return currPtr;

      currPtr = currPtr->next;
  }

  return NULL;
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

struct nodoTS * retrieveFromTsl(char * simboloActual, struct nodoTS* headTsl){

  struct nodoTS* currPtr = headTsl;

  while(currPtr != NULL){

    assert(currPtr->nombre);

    if(strcmp(currPtr->nombre, simboloActual) == 0)
      return currPtr;

    currPtr = currPtr->next;
  }

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

void setIntValueToSymbolFunc(char * symbolName, int newIntegerValue, char * name){

  struct nodoTSF * currIdFunc = retrieveFromFunSymbolTable(name);
  struct nodoTS *symbolPtr = retrieveFromTsl(symbolName, currIdFunc->tsl);

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

void setDoubleValueToSymbolFunc(char * symbolName, double newDoubleValue, char * name){

  struct nodoTSF * currIdFunc = retrieveFromFunSymbolTable(name);
  struct nodoTS *symbolPtr = retrieveFromTsl(symbolName, currIdFunc->tsl);

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
    //printf("node name = %d\n", node->type);
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

int computeSubTreeNodeTypeCountFunc(int nodeType, ASR * node, char * name){
  //printf("node name = %d\n", node->type);
  if(node == NULL)
    return 0;
//  printf("ya entre 4\n");
  int count = 0;

  // In case it is a constant
  if(node->type == nodeType){

    count++;
  }

  // In case it is an ID
  else if(node->type == ID_VALUE){

    struct nodoTSF * currIdFunc = retrieveFromFunSymbolTable(name);
    struct nodoTS * currIdNode = retrieveFromTsl(node->value.idName, currIdFunc->tsl);

    if(currIdNode->type == nodeType)
      count++;
  }

  int i = 0;
  for(i = 0; i < 4; i++){

    count += computeSubTreeNodeTypeCountFunc(nodeType, node->arrPtr[i], name);
  }

  return count;
}

int exprIsTypeConsistent(ASR * exprNode){

  // Count the number of subtree nodes of both data type
  // If the expression is type-consistent, then one of those counts
  // will be zero
//  printf("ya entre a type\n");
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

int exprIsTypeConsistentFunc(ASR * exprNode, char * name){

  // Count the number of subtree nodes of both data type
  // If the expression is type-consistent, then one of those counts
  // will be zero
//  printf("ya entre \n");
  int intSubTreeNodeCount = computeSubTreeNodeTypeCountFunc(INTEGER_NUMBER_VALUE, exprNode, name);
  int doubleSubTreeNodeCount = computeSubTreeNodeTypeCountFunc(FLOATING_POINT_NUMBER_VALUE, exprNode, name);

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

int isIntegerExprFunc(ASR * exprNode, char * name){
  //printf("ya entre \n");
  return exprIsTypeConsistentFunc(exprNode, name) == INTEGER_NUMBER_VALUE;
}

int isIntegerExpr(ASR * exprNode){
//  printf("ya entre \n");
  return exprIsTypeConsistent(exprNode) == INTEGER_NUMBER_VALUE;
}

int isFloatingPointExprFunc(ASR * exprNode, char * name){

  return exprIsTypeConsistentFunc(exprNode, name) == FLOATING_POINT_NUMBER_VALUE;
}

int isFloatingPointExpr(ASR * exprNode){

  return exprIsTypeConsistent(exprNode) == FLOATING_POINT_NUMBER_VALUE;
}


int func_exprIntFunc(ASR * exprIntNode, char * name){

//  printf("volvi a entrar\n");
  // If we enter an EXPR node, we must at least one term.
  assert(exprIntNode != NULL);


  if(exprIntNode->type == PLUS){

    return func_exprIntFunc(exprIntNode->arrPtr[0], name)
      + func_exprIntFunc(exprIntNode->arrPtr[1], name);
  }
  else if(exprIntNode->type == MINUS){

    return func_exprIntFunc(exprIntNode->arrPtr[0], name)
      - func_exprIntFunc(exprIntNode->arrPtr[1], name);
  }
  else if(exprIntNode->type == STAR){

    return func_exprIntFunc(exprIntNode->arrPtr[0], name)
      * func_exprIntFunc(exprIntNode->arrPtr[1], name);
  }
  else if(exprIntNode->type == FORWARD_SLASH){

    return func_exprIntFunc(exprIntNode->arrPtr[0], name)
      / func_exprIntFunc(exprIntNode->arrPtr[1], name);
  }

  assert(exprIntNode->type == INTEGER_NUMBER_VALUE
    || exprIntNode->type == ID_VALUE
    || exprIntNode->type == FUNCTION_VALUE);

  int valToReturn = 0;

  if(exprIntNode->type == INTEGER_NUMBER_VALUE){

    valToReturn = exprIntNode->value.intVal;
  }
  else if(exprIntNode->type == ID_VALUE){

    struct nodoTSF * currIdFunc = retrieveFromFunSymbolTable(name);
    struct nodoTS * currNode = retrieveFromTsl(exprIntNode->value.idName, currIdFunc->tsl);
    assert(currNode->type == INTEGER_NUMBER_VALUE);

    //printSymbolTableNode(currNode);
    valToReturn = currNode->value.intVal;
  }
  /*else if(exprIntNode->type == FUNCTION_VALUE){

    (exprIntNode);
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

    (exprIntNode);
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

double func_exprDoubleFunc(ASR * exprDoubleNode, char * name){
  // If we enter an EXPR node, we must at least one term.
  assert(exprDoubleNode != NULL);

  if(exprDoubleNode->type == PLUS){

    return func_exprDoubleFunc(exprDoubleNode->arrPtr[0], name)
      + func_exprDoubleFunc(exprDoubleNode->arrPtr[1], name);
  }
  else if(exprDoubleNode->type == MINUS){

    return func_exprDoubleFunc(exprDoubleNode->arrPtr[0], name)
      - func_exprDoubleFunc(exprDoubleNode->arrPtr[1], name);
  }
  else if(exprDoubleNode->type == STAR){

    return func_exprDoubleFunc(exprDoubleNode->arrPtr[0], name)
      * func_exprDoubleFunc(exprDoubleNode->arrPtr[1], name);
  }
  else if(exprDoubleNode->type == FORWARD_SLASH){

    return func_exprDoubleFunc(exprDoubleNode->arrPtr[0], name)
      / func_exprDoubleFunc(exprDoubleNode->arrPtr[1], name);
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

    struct nodoTSF * currIdFunc = retrieveFromFunSymbolTable(name);
    struct nodoTS * currNode = retrieveFromTsl(exprDoubleNode->value.idName, currIdFunc->tsl);

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


int func_expressionFunc(ASR* nodeExpr){

  // If we enter an EXPRESION node, we must have two 'expr' terms
  assert(nodeExpr->arrPtr[0] != NULL);
  assert(nodeExpr->arrPtr[1] != NULL);

  if(isIntegerExprFunc(nodeExpr->arrPtr[0], currentFuncName)){

    // Assert that the second 'expr' term also contains an integer expression
    assert(isIntegerExpr(nodeExpr->arrPtr[1]));
    //printNodeType(nodeExpr->type, "hola");
    int intExpresionLeftSide = func_exprIntFunc(nodeExpr->arrPtr[0], currentFuncName);
    int intExpresionRightSide = func_exprIntFunc(nodeExpr->arrPtr[1], currentFuncName);

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

    assert(isFloatingPointExprFunc(nodeExpr->arrPtr[0], currentFuncName));

    // Assert that the second 'expr' term also contains an floating-point expression
    assert(isFloatingPointExprFunc(nodeExpr->arrPtr[1], currentFuncName));

    double doubleExpresionLeftSide = func_exprDoubleFunc(nodeExpr->arrPtr[0], currentFuncName);
    int doubleExpresionRightSide = func_exprDoubleFunc(nodeExpr->arrPtr[1], currentFuncName);

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

void preTreePrinting(ASR* node, char* nombre){
  printf("###################### INICIO ARBOL SINTACTICO REDUCIDO DE LA FUNCION %s #####################\n\n", nombre);
  printTree(node);
  printf("###################### FIN ARBOL SINTACTICO REDUCIDO DE LA FUNCION %s #####################\n\n", nombre);

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
  else if(node->type == FUNCTION_VALUE){
    printf("Node value = %s\n", node->value.idName);
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

int traverseTree(ASR * node, int c){
  if(!node)
   return 0;

  int count = 0;

  if(c <= 1)
    count += (node->type == PARAMETER_VALUE);

  for(int i = 0; i < 4; i++){
    count += traverseTree(node->arrPtr[i], c + (node->type == PARAMETER_VALUE));
  }

  return count;


}

void obtainType(struct nodoTS * tsl){
  struct nodoTS * ptr = tsl;

  while(ptr != NULL){
    if(ptr->type == INTEGER_NUMBER_VALUE) printf("(int, %d) ",ptr->value.intVal);
    else if(ptr->type == FLOATING_POINT_NUMBER_VALUE) printf("(float, %.2f) ", ptr->value.doubleVal);

    ptr = ptr->next;
  }
}

ASR * getNextPassedParameter(ASR ** ptrPtrFuncNodeSubStree){

  assert(*ptrPtrFuncNodeSubStree);
  ASR  *ptrNextPassedParameter = NULL;

  if((*ptrPtrFuncNodeSubStree)->type == FUNCTION_VALUE){

    assert((*ptrPtrFuncNodeSubStree)->arrPtr[0]);
    ptrNextPassedParameter = (*ptrPtrFuncNodeSubStree)->arrPtr[0]->arrPtr[0];
  }
  else{

    assert((*ptrPtrFuncNodeSubStree)->type == PARAMETER_VALUE);
    ptrNextPassedParameter = (*ptrPtrFuncNodeSubStree)->arrPtr[0];
  }

  (*ptrPtrFuncNodeSubStree) = (*ptrPtrFuncNodeSubStree)->arrPtr[0]->arrPtr[1];

  assert(ptrNextPassedParameter);
  return ptrNextPassedParameter;
}

int tslLength(struct nodoTS * tsl){
  struct nodoTS * ptr = tsl;
  int tslL = 0;

  while(ptr != NULL){
    tslL++;
    ptr = ptr->next;
  }
  //printf("length of tsl = %d\n", tslL);
  return tslL;
}

void moveTslForward(struct nodoTS ** ptrPtrTslHead, int moves){
  for(int i = 0; i < moves; i++){
    *ptrPtrTslHead = (*ptrPtrTslHead)->next;
  }
}


void func_func(ASR * nodeFunc){
  struct nodoTSF * currFunc = retrieveFromFunSymbolTable(nodeFunc->value.idName);
  //int count = 0;

  //PART TO CHECK THAT THE AMOUNT OF PARAMS PASSED ARE THE SAME AS AMOUNT OF PARAMS IN FORMAL FUNCTION
  assert(currFunc != NULL);
  int formalParams = currFunc->numParams;
//  printf("# params: %d\n", formalParams);

  int amountOfParamsPassed = traverseTree(nodeFunc, 0);

//  printf("# params passed: %d\n", amountOfParamsPassed);

  //obtainType(currFunc->tsl);
  assert(formalParams == amountOfParamsPassed);


  //PART THAT CHECKS THAT THE TYPE OF THE PARAMS PASSED ARE THE SAME AS THE TYPE FOR THE PARAMS OF THE FORMAL FUNCTION
  struct nodoTS * currParamPassed = NULL;

  ASR* ptrFuncNodeSubTree = nodeFunc;
  ASR * paramsPassed = NULL;

  currParamPassed = currFunc->tsl;

  for(int i = 0; i < amountOfParamsPassed; i++){
    paramsPassed = getNextPassedParameter(&ptrFuncNodeSubTree);
  //  printf("value of param func %d\n", currParamPassed->value.intVal);

  //  printf("value of params passed %d\n", paramsPassed->value.intVal);
    assert(currParamPassed->type == paramsPassed->type);

    currParamPassed = currParamPassed->next;
  }

  //PART THAT ASSIGNS THE PARAMS PASSED TO THE LST OF THE FORMAL FUNCTION

  int functionSymbolTableLength = tslLength(currFunc->tsl);
  //printf("length of tsl:  %d\n", functionSymbolTableLength);
  struct nodoTS * currParamValues = NULL;

  ASR* ptrFuncNodeTree = nodeFunc;
  ASR * paramsValue = NULL;

  currParamValues = currFunc->tsl;
  moveTslForward(&currParamValues, functionSymbolTableLength - formalParams);
  for(int i = 0; i < amountOfParamsPassed; i++){
    paramsPassed = getNextPassedParameter(&ptrFuncNodeTree);
  //  printf("value of param func %d\n", currParamPassed->value.intVal);

   if(currParamValues->type == INTEGER_NUMBER_VALUE){
     currParamValues->value.intVal = func_exprInt(paramsPassed);
     //printf("value of assigned params int %d  %s\n", currParamValues->value.intVal, currParamValues->nombre);
   }
   else if(currParamValues->type = FLOATING_POINT_NUMBER_VALUE){
     currParamValues->value.doubleVal = func_exprDouble(paramsPassed);
  //  printf("value of assigned params float %lf\n", currParamValues->value.doubleVal);
   }

    currParamValues = currParamValues->next;
  }


  struct nodoTSF * funcSymbol = retrieveFromFunSymbolTable(nodeFunc->value.idName);
  funcRunning = 1;
  currentFuncName = nodeFunc->value.idName;
  interpreta(funcSymbol->cuerpo);


}

void func_read(ASR * nodeRead){
  assert(nodeRead->arrPtr[0] != NULL);
  if(funcRunning == 0){
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
  } else if(funcRunning == 1){

    struct nodoTSF * currIdFunc = retrieveFromFunSymbolTable(currentFuncName);
    struct nodoTS * currNode = retrieveFromTsl(nodeRead->arrPtr[0]->value.idName, currIdFunc->tsl);

    int valueToSet;
    double doubleValueToSet;

    switch (currNode->type) {
      case INTEGER_NUMBER_VALUE:
      valueToSet = readInt();
      setIntValueToSymbolFunc(currNode->nombre,valueToSet, currentFuncName);
      assert(valueToSet == currNode->value.intVal);

      break;
      case FLOATING_POINT_NUMBER_VALUE:
      doubleValueToSet = readDouble();
      setDoubleValueToSymbolFunc(currNode->nombre, doubleValueToSet, currentFuncName);
      assert(doubleValueToSet == currNode->value.doubleVal);
      break;
    }

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
      //printf("yupiyupiyupo\n");

    if(printNode->arrPtr[0]->type == FUNCTION_VALUE){

      func_func(printNode->arrPtr[0]);


      struct nodoTSF * currIdFunc = retrieveFromFunSymbolTable(currentFuncName);

      if(currIdFunc->returnType == INTEGER_NUMBER_VALUE){
        printf("%d\n", currIdFunc->value.intVal);
      } else {
        assert(currIdFunc->returnType == FLOATING_POINT_NUMBER_VALUE);
        printf("%lf\n", currIdFunc->value.doubleVal);
      }
    }
      // As we know that this is a function, then we know that this symbol must exist in the symbol table
      // of the main function, so directly call the auxiliary method that looks in that specific symbol table.
      /*struct SymbolTableNode* currFunc = auxRetrieveFromSymbolTable(printNode->arrPtr[0]->value.idName, mainFunctionSymbolTableHead);

      if(currFunc->returnType == INTEGER_NUMBER_VALUE){

        // printf("%d\n", currFunc->value.intVal);
        printf("%d\n", ptrFunctionCallStackTop->value.intVal);
      }
      else{

        assert(currFunc->returnType == FLOATING_POINT_NUMBER_VALUE);
        // printf("%lf\n", currFunc->value.doubleVal);
        printf("%lf\n", ptrFunctionCallStackTop->value.doubleVal);
      }

      popFunctionCallToStack();
    }*/
    else{

      if(funcRunning == 0){
        if(isIntegerExpr(printNode->arrPtr[0])){

          printf("%d\n", func_exprInt(printNode->arrPtr[0]));
        }
        else{

          assert(isFloatingPointExpr(printNode->arrPtr[0]));
          printf("%lf\n", func_exprDouble(printNode->arrPtr[0]));
        }
      } else if(funcRunning == 1){

        if(isIntegerExprFunc(printNode->arrPtr[0], currentFuncName)){

          printf("%d\n", func_exprIntFunc(printNode->arrPtr[0], currentFuncName));
        }
        else{

          assert(isFloatingPointExprFunc(printNode->arrPtr[0], currentFuncName));
          printf("%lf\n", func_exprDoubleFunc(printNode->arrPtr[0], currentFuncName));
        }

        //funcRunning = 0;
      }
    }
  }
}

  void func_assign(ASR * setNode){

    // Each set statement must contain both the corresponding
    // id and the desired value
    assert(setNode->arrPtr[0] != NULL);
    assert(setNode->arrPtr[1] != NULL);
    if(funcRunning == 0){
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
    } else if(funcRunning == 1){

      struct nodoTSF * currIdFunc = retrieveFromFunSymbolTable(currentFuncName);
      struct nodoTS * currNode = retrieveFromTsl(setNode->arrPtr[0]->value.idName, currIdFunc->tsl);

    //  printf("current sybbol type %d\n", currNode->type);

      assert(currNode != NULL);

      int exprValueToSet;
      double exprDoubleValueToSet;

      switch(currNode->type){

        case INTEGER_NUMBER_VALUE:
        exprValueToSet = func_exprIntFunc(setNode->arrPtr[1], currentFuncName);
        setIntValueToSymbolFunc(currNode->nombre, exprValueToSet, currentFuncName);
        //printSymbolTableNode(currNode);
        assert(exprValueToSet == currNode->value.intVal);
        break;

        case FLOATING_POINT_NUMBER_VALUE:
        exprDoubleValueToSet = func_exprDoubleFunc(setNode->arrPtr[1], currentFuncName);
        setDoubleValueToSymbolFunc(currNode->nombre, exprDoubleValueToSet, currentFuncName);
        //printSymbolTableNode(currNode);
        assert(exprDoubleValueToSet == currNode->value.doubleVal);
        break;

      }
    }
  }




  void func_if(ASR * nodeIf){

    assert(nodeIf->arrPtr[0] != NULL);
    if(funcRunning == 0){
    if(func_expression(nodeIf->arrPtr[0])){
      if(nodeIf->arrPtr[1] != NULL){
        interpreta(nodeIf->arrPtr[1]);
      }
    }
  } else if(funcRunning == 1){
    if(func_expressionFunc(nodeIf->arrPtr[0])){
      if(nodeIf->arrPtr[1] != NULL){
        interpreta(nodeIf->arrPtr[1]);
      }
    }
  }
  }

  void func_ifElse(ASR * nodeIfElse){

    assert(nodeIfElse->arrPtr[0] != NULL);
    if(funcRunning == 0){
    if(func_expression(nodeIfElse->arrPtr[0])){
      interpreta(nodeIfElse->arrPtr[1]);
    } else {
      interpreta(nodeIfElse->arrPtr[2]);
    }
  } else if(funcRunning == 1){
    if(func_expressionFunc(nodeIfElse->arrPtr[0])){
      interpreta(nodeIfElse->arrPtr[1]);
    } else {
      interpreta(nodeIfElse->arrPtr[2]);
    }
  }
  }

  void func_while(ASR * nodeWhile){
    assert(nodeWhile->arrPtr[0] != NULL);
    if(funcRunning == 0){
    while(func_expression(nodeWhile->arrPtr[0])){
      interpreta(nodeWhile->arrPtr[1]);
    }
  } else if(funcRunning == 1){
    while(func_expressionFunc(nodeWhile->arrPtr[0])){
      interpreta(nodeWhile->arrPtr[1]);
    }
  }
  }

  void func_for(ASR * nodeFor){

    assert(nodeFor->arrPtr[0] != NULL);
    assert(nodeFor->arrPtr[1] != NULL);
    assert(nodeFor->arrPtr[2] != NULL);

    if(funcRunning == 0){
    func_assign(nodeFor->arrPtr[0]);

    while(func_expression(nodeFor->arrPtr[1])){
      interpreta(nodeFor->arrPtr[3]);
      func_assign(nodeFor->arrPtr[2]);
    }
  } else if(funcRunning == 1){
    func_assign(nodeFor->arrPtr[0]);
    while(func_expressionFunc(nodeFor->arrPtr[1])){
      interpreta(nodeFor->arrPtr[3]);
      func_assign(nodeFor->arrPtr[2]);
    }
  }
  }
 //preguntarle al profe a que se refefiere con el REPEAT

  void func_repeat(ASR * nodeRepeat){
    //assert(nodeRepeat->arrPtr[0] != NULL);
    assert(nodeRepeat->arrPtr[1] != NULL);
    if(funcRunning == 0){
    do {
      interpreta(nodeRepeat->arrPtr[0]);
    } while(func_expression(nodeRepeat->arrPtr[1]));
  } else if(funcRunning == 1){
    do {
      interpreta(nodeRepeat->arrPtr[0]);
    } while(func_expressionFunc(nodeRepeat->arrPtr[1]));
  }
  }

  void func_return(ASR * nodeReturn){
    assert(nodeReturn->arrPtr[0] != NULL);
    struct nodoTSF * currIdFunc = retrieveFromFunSymbolTable(currentFuncName);
    //printf("%d\n", currIdFunc->returnType);
    if (nodeReturn->arrPtr[0]->type == INTEGER_NUMBER_VALUE) {
      assert(currIdFunc->returnType == INTEGER_NUMBER_VALUE);
      currIdFunc->value.intVal = nodeReturn->arrPtr[0]->value.intVal;
    } else if(nodeReturn->arrPtr[0]->type == FLOATING_POINT_NUMBER_VALUE){
      assert(currIdFunc->returnType == FLOATING_POINT_NUMBER_VALUE);
      currIdFunc->value.doubleVal = nodeReturn->arrPtr[0]->value.doubleVal;
    } else if(nodeReturn->arrPtr[0]->parentNodeType == EXPR
    || nodeReturn->arrPtr[0]->parentNodeType == TERM
    || nodeReturn->arrPtr[0]->parentNodeType == FACTOR){
      if(isIntegerExprFunc(nodeReturn->arrPtr[0], currentFuncName)){
        assert(currIdFunc->returnType == INTEGER_NUMBER_VALUE);
        currIdFunc->value.intVal = func_exprIntFunc(nodeReturn->arrPtr[0], currentFuncName);
      } else {
        assert(isFloatingPointExprFunc(nodeReturn->arrPtr[0], currentFuncName));
        assert(currIdFunc->returnType == FLOATING_POINT_NUMBER_VALUE);
        currIdFunc->value.doubleVal = func_exprDoubleFunc(nodeReturn->arrPtr[0], currentFuncName);
      }
    }
  }

 void interpreta(ASR * node){

   /*struct nodoTSF * funcSymbol = retrieveFromFunSymbolTable("add");
   ASR * node = funcSymbol->cuerpo;*/
   if(node == NULL)
   return;

   switch (node->type) {
     case PROGRAM: // CHECK
     break;

     case PYC: // CHECK
     break;

     case PYC_S: // CHECK
     break;

     case PRINT: // CHECK
     func_print(node);
     break;

     case READ: // CHECK
     func_read(node);
     break;

     case SET: // CHECK
     func_assign(node);
     break;

     case IF: // CHECK
     func_if(node);
     break;

     case IFELSE: // CHECK
     func_ifElse(node);
     break;

     case WHILE: // CHECK
     func_while(node);
     break;

     case FOR: // CHECK
     func_for(node);
     break;

     case REPEAT: // CHECK
     func_repeat(node);
     break;

     case RETURN:
     func_return(node);
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
