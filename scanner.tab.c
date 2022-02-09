/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "scanner.y"

#define YYPARSER /* distinguishes Yacc output from other code files */

#include "globals.h"
#include "util.h"
#include "scan.h"
#include "parse.h"

#define YYSTYPE TreeNode *
static int savedNumber;
static char * savedName; /* for use in assignments */
static int savedLineNo;  /* ditto */
static TreeNode * savedTree; /* stores syntax tree for later return */
static int yylex(void); // added 11/2/11 to ensure no conflict with lex
int yyerror(char *message);

#line 88 "scanner.tab.c"

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

#include "scanner.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IF = 3,                         /* IF  */
  YYSYMBOL_ELSE = 4,                       /* ELSE  */
  YYSYMBOL_INT = 5,                        /* INT  */
  YYSYMBOL_RETURN = 6,                     /* RETURN  */
  YYSYMBOL_VOID = 7,                       /* VOID  */
  YYSYMBOL_WHILE = 8,                      /* WHILE  */
  YYSYMBOL_ID = 9,                         /* ID  */
  YYSYMBOL_NUM = 10,                       /* NUM  */
  YYSYMBOL_SOM = 11,                       /* SOM  */
  YYSYMBOL_SUB = 12,                       /* SUB  */
  YYSYMBOL_MUL = 13,                       /* MUL  */
  YYSYMBOL_DIV = 14,                       /* DIV  */
  YYSYMBOL_MENOR = 15,                     /* MENOR  */
  YYSYMBOL_MENORIGUAL = 16,                /* MENORIGUAL  */
  YYSYMBOL_MAIOR = 17,                     /* MAIOR  */
  YYSYMBOL_MAIORIGUAL = 18,                /* MAIORIGUAL  */
  YYSYMBOL_IGUALIGUAL = 19,                /* IGUALIGUAL  */
  YYSYMBOL_DIFERENTE = 20,                 /* DIFERENTE  */
  YYSYMBOL_VIRGULA = 21,                   /* VIRGULA  */
  YYSYMBOL_LCHAVE = 22,                    /* LCHAVE  */
  YYSYMBOL_RCHAVE = 23,                    /* RCHAVE  */
  YYSYMBOL_LCOLCHETE = 24,                 /* LCOLCHETE  */
  YYSYMBOL_RCOLCHETE = 25,                 /* RCOLCHETE  */
  YYSYMBOL_IGUAL = 26,                     /* IGUAL  */
  YYSYMBOL_SEMICOL = 27,                   /* SEMICOL  */
  YYSYMBOL_LPAREN = 28,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 29,                    /* RPAREN  */
  YYSYMBOL_FIM = 30,                       /* FIM  */
  YYSYMBOL_ERROR = 31,                     /* ERROR  */
  YYSYMBOL_YYACCEPT = 32,                  /* $accept  */
  YYSYMBOL_programa = 33,                  /* programa  */
  YYSYMBOL_decl_lista = 34,                /* decl_lista  */
  YYSYMBOL_decl = 35,                      /* decl  */
  YYSYMBOL_id = 36,                        /* id  */
  YYSYMBOL_num = 37,                       /* num  */
  YYSYMBOL_var_decl = 38,                  /* var_decl  */
  YYSYMBOL_tipo = 39,                      /* tipo  */
  YYSYMBOL_fun_decl = 40,                  /* fun_decl  */
  YYSYMBOL_41_1 = 41,                      /* @1  */
  YYSYMBOL_params = 42,                    /* params  */
  YYSYMBOL_param_lista = 43,               /* param_lista  */
  YYSYMBOL_param = 44,                     /* param  */
  YYSYMBOL_composto_decl = 45,             /* composto_decl  */
  YYSYMBOL_local_decl = 46,                /* local_decl  */
  YYSYMBOL_stmt_lista = 47,                /* stmt_lista  */
  YYSYMBOL_stmt = 48,                      /* stmt  */
  YYSYMBOL_expressao_decl = 49,            /* expressao_decl  */
  YYSYMBOL_selecao_decl = 50,              /* selecao_decl  */
  YYSYMBOL_iteracao_decl = 51,             /* iteracao_decl  */
  YYSYMBOL_retorno_decl = 52,              /* retorno_decl  */
  YYSYMBOL_expressao = 53,                 /* expressao  */
  YYSYMBOL_var = 54,                       /* var  */
  YYSYMBOL_55_2 = 55,                      /* @2  */
  YYSYMBOL_simples_expressao = 56,         /* simples_expressao  */
  YYSYMBOL_relacional = 57,                /* relacional  */
  YYSYMBOL_soma_expressao = 58,            /* soma_expressao  */
  YYSYMBOL_soma = 59,                      /* soma  */
  YYSYMBOL_termo = 60,                     /* termo  */
  YYSYMBOL_mult = 61,                      /* mult  */
  YYSYMBOL_fator = 62,                     /* fator  */
  YYSYMBOL_ativacao = 63,                  /* ativacao  */
  YYSYMBOL_64_3 = 64,                      /* @3  */
  YYSYMBOL_args = 65,                      /* args  */
  YYSYMBOL_arg_lista = 66                  /* arg_lista  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   97

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  68
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  107

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   286


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

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
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    26,    26,    29,    40,    43,    45,    48,    53,    58,
      64,    73,    77,    82,    82,    94,    96,   101,   111,   113,
     118,   124,   130,   140,   142,   152,   154,   155,   156,   157,
     158,   160,   161,   163,   168,   175,   181,   185,   190,   195,
     197,   201,   201,   210,   216,   218,   222,   226,   230,   234,
     238,   243,   249,   251,   255,   260,   266,   268,   272,   277,
     278,   279,   280,   286,   286,   294,   295,   297,   307
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IF", "ELSE", "INT",
  "RETURN", "VOID", "WHILE", "ID", "NUM", "SOM", "SUB", "MUL", "DIV",
  "MENOR", "MENORIGUAL", "MAIOR", "MAIORIGUAL", "IGUALIGUAL", "DIFERENTE",
  "VIRGULA", "LCHAVE", "RCHAVE", "LCOLCHETE", "RCOLCHETE", "IGUAL",
  "SEMICOL", "LPAREN", "RPAREN", "FIM", "ERROR", "$accept", "programa",
  "decl_lista", "decl", "id", "num", "var_decl", "tipo", "fun_decl", "@1",
  "params", "param_lista", "param", "composto_decl", "local_decl",
  "stmt_lista", "stmt", "expressao_decl", "selecao_decl", "iteracao_decl",
  "retorno_decl", "expressao", "var", "@2", "simples_expressao",
  "relacional", "soma_expressao", "soma", "termo", "mult", "fator",
  "ativacao", "@3", "args", "arg_lista", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-68)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-64)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      11,   -68,   -68,    38,    11,   -68,   -68,    41,   -68,   -68,
     -68,   -68,   -21,    42,   -68,    30,   -68,    34,    12,    35,
      43,    41,    44,    50,   -68,   -68,    46,    52,    11,    51,
     -68,   -68,   -68,   -68,    11,   -68,    41,    -1,   -21,    47,
      15,    53,   -68,   -68,     3,     9,   -68,   -68,   -68,   -68,
     -68,   -68,   -68,    55,    54,   -68,    49,    31,   -68,   -68,
       3,   -68,    56,     3,    48,    60,    57,   -68,     3,   -68,
     -68,   -68,   -68,   -68,   -68,   -68,   -68,     3,     3,   -68,
     -68,     3,    58,   -68,    59,   -68,     3,     3,   -68,   -68,
      45,    31,   -68,    26,    26,    61,   -68,    62,    68,    74,
     -68,   -68,   -68,     3,    26,   -68,   -68
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    11,    12,     0,     2,     4,     5,     0,     6,     1,
       3,     7,    13,     0,     9,     0,     8,     0,     0,     0,
      12,     0,     0,    15,    18,    10,    19,     0,     0,     0,
      23,    14,    17,    20,    25,    22,     0,     0,     0,     0,
       0,     0,    21,    32,     0,    40,    62,    27,    24,    26,
      28,    29,    30,     0,    60,    39,    44,    52,    56,    61,
       0,    36,     0,     0,     0,     0,     0,    31,     0,    53,
      54,    45,    46,    47,    48,    49,    50,     0,     0,    57,
      58,     0,     0,    37,     0,    59,     0,    66,    38,    60,
      43,    51,    55,     0,     0,     0,    68,     0,    65,    33,
      35,    42,    64,     0,     0,    67,    34
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -68,   -68,   -68,    75,    -6,    77,    63,    21,   -68,   -68,
     -68,   -68,    64,    66,   -68,   -68,   -53,   -68,   -68,   -68,
     -68,   -40,   -67,   -68,   -68,   -68,    17,   -68,    18,   -68,
      14,   -68,   -68,   -68,   -68
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,     5,    45,    46,     6,     7,     8,    15,
      22,    23,    24,    47,    34,    37,    48,    49,    50,    51,
      52,    53,    54,    65,    55,    77,    56,    78,    57,    81,
      58,    59,    66,    97,    98
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      62,    12,    39,    13,    64,    40,    14,    41,    11,    16,
      89,    89,    11,    16,    89,    26,     1,     1,     2,    20,
      82,    30,    42,    84,    11,    16,    43,    44,    88,    39,
      38,    44,    40,   -41,    41,    11,    16,   -63,     9,    21,
      99,   100,    61,    44,    79,    80,    95,    96,    30,    21,
      11,   106,    16,    43,    44,    36,    69,    70,    18,    19,
      69,    70,    25,   105,    71,    72,    73,    74,    75,    76,
      29,    28,   -16,    27,    30,    60,    33,    85,   104,    10,
      68,    63,    67,    83,    86,    87,   101,    93,    94,   103,
      17,   102,    32,    31,    90,    92,    91,    35
};

static const yytype_int8 yycheck[] =
{
      40,     7,     3,    24,    44,     6,    27,     8,     9,    10,
      77,    78,     9,    10,    81,    21,     5,     5,     7,     7,
      60,    22,    23,    63,     9,    10,    27,    28,    68,     3,
      36,    28,     6,    24,     8,     9,    10,    28,     0,    18,
      93,    94,    27,    28,    13,    14,    86,    87,    22,    28,
       9,   104,    10,    27,    28,    34,    11,    12,    28,    25,
      11,    12,    27,   103,    15,    16,    17,    18,    19,    20,
      24,    21,    29,    29,    22,    28,    25,    29,     4,     4,
      26,    28,    27,    27,    24,    28,    25,    29,    29,    21,
      13,    29,    28,    27,    77,    81,    78,    34
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,     7,    33,    34,    35,    38,    39,    40,     0,
      35,     9,    36,    24,    27,    41,    10,    37,    28,    25,
       7,    39,    42,    43,    44,    27,    36,    29,    21,    24,
      22,    45,    44,    25,    46,    38,    39,    47,    36,     3,
       6,     8,    23,    27,    28,    36,    37,    45,    48,    49,
      50,    51,    52,    53,    54,    56,    58,    60,    62,    63,
      28,    27,    53,    28,    53,    55,    64,    27,    26,    11,
      12,    15,    16,    17,    18,    19,    20,    57,    59,    13,
      14,    61,    53,    27,    53,    29,    24,    28,    53,    54,
      58,    60,    62,    29,    29,    53,    53,    65,    66,    48,
      48,    25,    29,    21,     4,    53,    48
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    32,    33,    34,    34,    35,    35,    36,    37,    38,
      38,    39,    39,    41,    40,    42,    42,    43,    43,    44,
      44,    45,    46,    46,    47,    47,    48,    48,    48,    48,
      48,    49,    49,    50,    50,    51,    52,    52,    53,    53,
      54,    55,    54,    56,    56,    57,    57,    57,    57,    57,
      57,    58,    58,    59,    59,    60,    60,    61,    61,    62,
      62,    62,    62,    64,    63,    65,    65,    66,    66
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     3,
       6,     1,     1,     0,     7,     1,     1,     3,     1,     2,
       4,     4,     2,     0,     2,     0,     1,     1,     1,     1,
       1,     2,     1,     5,     7,     5,     2,     3,     3,     1,
       1,     0,     5,     3,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     3,     1,     1,     1,     3,
       1,     1,     1,     0,     5,     1,     0,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* programa: decl_lista  */
#line 27 "scanner.y"
                    { savedTree = yyvsp[0]; }
#line 1211 "scanner.tab.c"
    break;

  case 3: /* decl_lista: decl_lista decl  */
#line 30 "scanner.y"
                    { 
                      YYSTYPE t = yyvsp[-1];
                      if (t != NULL) {
                        while (t->sibling != NULL) { t = t->sibling; }
                        t->sibling = yyvsp[0];
                        yyval = yyvsp[-1];
                      } else {
                        yyval = yyvsp[0];
                      }
                    }
#line 1226 "scanner.tab.c"
    break;

  case 4: /* decl_lista: decl  */
#line 41 "scanner.y"
                      { yyval = yyvsp[0]; }
#line 1232 "scanner.tab.c"
    break;

  case 5: /* decl: var_decl  */
#line 44 "scanner.y"
                    { yyval = yyvsp[0]; }
#line 1238 "scanner.tab.c"
    break;

  case 6: /* decl: fun_decl  */
#line 46 "scanner.y"
                    { yyval = yyvsp[0]; }
#line 1244 "scanner.tab.c"
    break;

  case 7: /* id: ID  */
#line 49 "scanner.y"
                    { savedName = copyString(tokenString);
                      savedLineNo = lineno;
                    }
#line 1252 "scanner.tab.c"
    break;

  case 8: /* num: NUM  */
#line 54 "scanner.y"
                    { savedNumber = atoi(tokenString);
                      savedLineNo = lineno;
                    }
#line 1260 "scanner.tab.c"
    break;

  case 9: /* var_decl: tipo id SEMICOL  */
#line 59 "scanner.y"
                    { yyval = newDeclNode(varK);
                      yyval->child[0] = yyvsp[-2];
                      yyval->lineno = lineno;
                      yyval->attr.name = savedName;
                    }
#line 1270 "scanner.tab.c"
    break;

  case 10: /* var_decl: tipo id LCOLCHETE num RCOLCHETE SEMICOL  */
#line 65 "scanner.y"
                    { yyval = newDeclNode(vectvarK);
                      yyval->child[0] = yyvsp[-5];
                      yyval->lineno = lineno;
                      yyval->type = VectInt;
                      yyval->attr.arr.name = savedName;
                      yyval->attr.arr.size = savedNumber;
                    }
#line 1282 "scanner.tab.c"
    break;

  case 11: /* tipo: INT  */
#line 74 "scanner.y"
                    { yyval = newExpNode(typeK);
                      yyval->type = Integer;
                    }
#line 1290 "scanner.tab.c"
    break;

  case 12: /* tipo: VOID  */
#line 78 "scanner.y"
                    { yyval = newExpNode(typeK);
                      yyval->type = Void;
                    }
#line 1298 "scanner.tab.c"
    break;

  case 13: /* @1: %empty  */
#line 82 "scanner.y"
                            {
                    yyval = newDeclNode(funcK);
                    yyval->lineno = lineno;
                    yyval->attr.name = savedName;
                  }
#line 1308 "scanner.tab.c"
    break;

  case 14: /* fun_decl: tipo id @1 LPAREN params RPAREN composto_decl  */
#line 88 "scanner.y"
                  { yyval = yyvsp[-4];
                    yyval->child[0] = yyvsp[-6];
                    yyval->child[1] = yyvsp[-2];
                    yyval->child[2] = yyvsp[0];
                  }
#line 1318 "scanner.tab.c"
    break;

  case 15: /* params: param_lista  */
#line 95 "scanner.y"
                      { yyval = yyvsp[0]; }
#line 1324 "scanner.tab.c"
    break;

  case 16: /* params: VOID  */
#line 97 "scanner.y"
                    { yyval = newDeclNode(paramK);
                      yyval->type = Void;
                    }
#line 1332 "scanner.tab.c"
    break;

  case 17: /* param_lista: param_lista VIRGULA param  */
#line 102 "scanner.y"
                    { YYSTYPE t = yyvsp[-2];
                      if (t != NULL) {
                        while (t->sibling != NULL) { t = t->sibling; }
                        t->sibling = yyvsp[0];
                        yyval = yyvsp[-2];
                      } else {
                        yyval = yyvsp[-1];
                      }
                    }
#line 1346 "scanner.tab.c"
    break;

  case 18: /* param_lista: param  */
#line 111 "scanner.y"
                          { yyval = yyvsp[0]; }
#line 1352 "scanner.tab.c"
    break;

  case 19: /* param: tipo id  */
#line 114 "scanner.y"
                    { yyval = newDeclNode(paramK);
                      yyval->child[0] = yyvsp[-1];
                      yyval->attr.name = savedName;
                    }
#line 1361 "scanner.tab.c"
    break;

  case 20: /* param: tipo id LCOLCHETE RCOLCHETE  */
#line 119 "scanner.y"
                    { yyval = newDeclNode(vectparamK);
                      yyval->child[0] = yyvsp[-3];
                      yyval->attr.name = copyString(savedName);
                    }
#line 1370 "scanner.tab.c"
    break;

  case 21: /* composto_decl: LCHAVE local_decl stmt_lista RCHAVE  */
#line 125 "scanner.y"
                    { yyval = newStmtNode(compostoK);
                      yyval->child[0] = yyvsp[-2];
                      yyval->child[1] = yyvsp[-1];
                    }
#line 1379 "scanner.tab.c"
    break;

  case 22: /* local_decl: local_decl var_decl  */
#line 131 "scanner.y"
                    { YYSTYPE t = yyvsp[-1];
                      if (t != NULL) {
                        while (t->sibling != NULL) { t = t->sibling; }
                        t->sibling = yyvsp[0];
                        yyval = yyvsp[-1];
                      } else {
                        yyval = yyvsp[0];
                      }
                    }
#line 1393 "scanner.tab.c"
    break;

  case 23: /* local_decl: %empty  */
#line 140 "scanner.y"
                    { yyval = NULL; }
#line 1399 "scanner.tab.c"
    break;

  case 24: /* stmt_lista: stmt_lista stmt  */
#line 143 "scanner.y"
                    { YYSTYPE t = yyvsp[-1];
                      if (t != NULL) {
                        while (t->sibling != NULL) { t = t->sibling; }
                      t->sibling = yyvsp[0];
                      yyval = yyvsp[-1];
                      } else {
                        yyval = yyvsp[0];
                      }
                    }
#line 1413 "scanner.tab.c"
    break;

  case 25: /* stmt_lista: %empty  */
#line 152 "scanner.y"
                    { yyval = NULL; }
#line 1419 "scanner.tab.c"
    break;

  case 26: /* stmt: expressao_decl  */
#line 154 "scanner.y"
                                   { yyval = yyvsp[0]; }
#line 1425 "scanner.tab.c"
    break;

  case 27: /* stmt: composto_decl  */
#line 155 "scanner.y"
                                  { yyval = yyvsp[0]; }
#line 1431 "scanner.tab.c"
    break;

  case 28: /* stmt: selecao_decl  */
#line 156 "scanner.y"
                                 { yyval = yyvsp[0]; }
#line 1437 "scanner.tab.c"
    break;

  case 29: /* stmt: iteracao_decl  */
#line 157 "scanner.y"
                                  { yyval = yyvsp[0]; }
#line 1443 "scanner.tab.c"
    break;

  case 30: /* stmt: retorno_decl  */
#line 158 "scanner.y"
                                 { yyval = yyvsp[0]; }
#line 1449 "scanner.tab.c"
    break;

  case 31: /* expressao_decl: expressao SEMICOL  */
#line 160 "scanner.y"
                                      { yyval = yyvsp[-1]; }
#line 1455 "scanner.tab.c"
    break;

  case 32: /* expressao_decl: SEMICOL  */
#line 161 "scanner.y"
                            { yyval = NULL; }
#line 1461 "scanner.tab.c"
    break;

  case 33: /* selecao_decl: IF LPAREN expressao RPAREN stmt  */
#line 164 "scanner.y"
                    { yyval = newStmtNode(ifK);
                      yyval->child[0] = yyvsp[-2];
                      yyval->child[1] = yyvsp[0];
                    }
#line 1470 "scanner.tab.c"
    break;

  case 34: /* selecao_decl: IF LPAREN expressao RPAREN stmt ELSE stmt  */
#line 169 "scanner.y"
                    { yyval = newStmtNode(ifK);
                      yyval->child[0] = yyvsp[-4];
                      yyval->child[1] = yyvsp[-2];
                      yyval->child[2] = yyvsp[0];
                    }
#line 1480 "scanner.tab.c"
    break;

  case 35: /* iteracao_decl: WHILE LPAREN expressao RPAREN stmt  */
#line 176 "scanner.y"
                    { yyval = newStmtNode(whileK);
                      yyval->child[0] = yyvsp[-2];
                      yyval->child[1] = yyvsp[0];
                    }
#line 1489 "scanner.tab.c"
    break;

  case 36: /* retorno_decl: RETURN SEMICOL  */
#line 182 "scanner.y"
                    { yyval = newStmtNode(returnK);
                      yyval->type = Void;
                    }
#line 1497 "scanner.tab.c"
    break;

  case 37: /* retorno_decl: RETURN expressao SEMICOL  */
#line 186 "scanner.y"
                    { yyval = newStmtNode(returnK);
                      yyval->child[0] = yyvsp[-1];
                    }
#line 1505 "scanner.tab.c"
    break;

  case 38: /* expressao: var IGUAL expressao  */
#line 191 "scanner.y"
                    { yyval = newStmtNode(assignK);
                      yyval->child[0] = yyvsp[-2];
                      yyval->child[1] = yyvsp[0];
                    }
#line 1514 "scanner.tab.c"
    break;

  case 39: /* expressao: simples_expressao  */
#line 195 "scanner.y"
                                      { yyval = yyvsp[0]; }
#line 1520 "scanner.tab.c"
    break;

  case 40: /* var: id  */
#line 198 "scanner.y"
                    { yyval = newExpNode(IdK);
                      yyval->attr.name = savedName;
                    }
#line 1528 "scanner.tab.c"
    break;

  case 41: /* @2: %empty  */
#line 201 "scanner.y"
                       {
                      yyval = newExpNode(vectIdK);
                      yyval->attr.name = savedName;
                    }
#line 1537 "scanner.tab.c"
    break;

  case 42: /* var: id @2 LCOLCHETE expressao RCOLCHETE  */
#line 205 "scanner.y"
                    {
                      yyval = yyvsp[-3];
                      yyval->child[0] = yyvsp[-1];
                    }
#line 1546 "scanner.tab.c"
    break;

  case 43: /* simples_expressao: soma_expressao relacional soma_expressao  */
#line 211 "scanner.y"
                    { yyval = newExpNode(calcK);
                      yyval->child[0] = yyvsp[-2];
                      yyval->child[1] = yyvsp[-1];
                      yyval->child[2] = yyvsp[0];
                    }
#line 1556 "scanner.tab.c"
    break;

  case 44: /* simples_expressao: soma_expressao  */
#line 216 "scanner.y"
                                   { yyval = yyvsp[0]; }
#line 1562 "scanner.tab.c"
    break;

  case 45: /* relacional: MENOR  */
#line 219 "scanner.y"
                    { yyval = newExpNode(opK);
                      yyval->attr.op = MENOR;
                    }
#line 1570 "scanner.tab.c"
    break;

  case 46: /* relacional: MENORIGUAL  */
#line 223 "scanner.y"
                    { yyval = newExpNode(opK);
                      yyval->attr.op = MENORIGUAL;
                    }
#line 1578 "scanner.tab.c"
    break;

  case 47: /* relacional: MAIOR  */
#line 227 "scanner.y"
                    { yyval = newExpNode(opK);
                      yyval->attr.op = MAIOR;
                    }
#line 1586 "scanner.tab.c"
    break;

  case 48: /* relacional: MAIORIGUAL  */
#line 231 "scanner.y"
                    { yyval = newExpNode(opK);
                      yyval->attr.op = MAIORIGUAL;
                    }
#line 1594 "scanner.tab.c"
    break;

  case 49: /* relacional: IGUALIGUAL  */
#line 235 "scanner.y"
                    { yyval = newExpNode(opK);
                      yyval->attr.op = IGUALIGUAL;
                    }
#line 1602 "scanner.tab.c"
    break;

  case 50: /* relacional: DIFERENTE  */
#line 239 "scanner.y"
                    { yyval = newExpNode(opK);
                      yyval->attr.op = DIFERENTE;
                    }
#line 1610 "scanner.tab.c"
    break;

  case 51: /* soma_expressao: soma_expressao soma termo  */
#line 244 "scanner.y"
                    { yyval = newExpNode(calcK);
                      yyval->child[0] = yyvsp[-2];
                      yyval->child[1] = yyvsp[-1];
                      yyval->child[2] = yyvsp[0];
                    }
#line 1620 "scanner.tab.c"
    break;

  case 52: /* soma_expressao: termo  */
#line 249 "scanner.y"
                          { yyval = yyvsp[0]; }
#line 1626 "scanner.tab.c"
    break;

  case 53: /* soma: SOM  */
#line 252 "scanner.y"
                    { yyval = newExpNode(opK);
                      yyval->attr.op = SOM;
                    }
#line 1634 "scanner.tab.c"
    break;

  case 54: /* soma: SUB  */
#line 256 "scanner.y"
                    { yyval = newExpNode(opK);
                      yyval->attr.op = SUB;
                    }
#line 1642 "scanner.tab.c"
    break;

  case 55: /* termo: termo mult fator  */
#line 261 "scanner.y"
                    { yyval = newExpNode(calcK);
                      yyval->child[0] = yyvsp[-2];
                      yyval->child[1] = yyvsp[-1];
                      yyval->child[2] = yyvsp[0];
                    }
#line 1652 "scanner.tab.c"
    break;

  case 56: /* termo: fator  */
#line 266 "scanner.y"
                          { yyval = yyvsp[0]; }
#line 1658 "scanner.tab.c"
    break;

  case 57: /* mult: MUL  */
#line 269 "scanner.y"
                    { yyval = newExpNode(opK);
                      yyval->attr.op = MUL;
                    }
#line 1666 "scanner.tab.c"
    break;

  case 58: /* mult: DIV  */
#line 273 "scanner.y"
                    { yyval = newExpNode(opK);
                      yyval->attr.op = DIV;
                    }
#line 1674 "scanner.tab.c"
    break;

  case 59: /* fator: LPAREN expressao RPAREN  */
#line 277 "scanner.y"
                                            { yyval = yyvsp[-1]; }
#line 1680 "scanner.tab.c"
    break;

  case 60: /* fator: var  */
#line 278 "scanner.y"
                        { yyval = yyvsp[0]; }
#line 1686 "scanner.tab.c"
    break;

  case 61: /* fator: ativacao  */
#line 279 "scanner.y"
                             { yyval = yyvsp[0]; }
#line 1692 "scanner.tab.c"
    break;

  case 62: /* fator: num  */
#line 281 "scanner.y"
                    { yyval = newExpNode(ConstK);
                      yyval->type = Integer;
                      yyval->attr.val = atoi(tokenString);
                    }
#line 1701 "scanner.tab.c"
    break;

  case 63: /* @3: %empty  */
#line 286 "scanner.y"
                       {
                      yyval = newExpNode(callK);
                      yyval->attr.name = savedName;
                      }
#line 1710 "scanner.tab.c"
    break;

  case 64: /* ativacao: id @3 LPAREN args RPAREN  */
#line 289 "scanner.y"
                                           {
                        yyval = yyvsp[-3];
                        yyval->child[0] = yyvsp[-1];
                    }
#line 1719 "scanner.tab.c"
    break;

  case 65: /* args: arg_lista  */
#line 294 "scanner.y"
                              { yyval = yyvsp[0]; }
#line 1725 "scanner.tab.c"
    break;

  case 66: /* args: %empty  */
#line 295 "scanner.y"
                    { yyval = NULL; }
#line 1731 "scanner.tab.c"
    break;

  case 67: /* arg_lista: arg_lista VIRGULA expressao  */
#line 298 "scanner.y"
                    { YYSTYPE t = yyvsp[-2];
                      if (t != NULL) {
                        while (t->sibling != NULL) { t = t->sibling; }
                        t->sibling = yyvsp[0];
                        yyval = yyvsp[-2];
                      } else {
                        yyval = yyvsp[0];
                      }
                    }
#line 1745 "scanner.tab.c"
    break;

  case 68: /* arg_lista: expressao  */
#line 307 "scanner.y"
                              { yyval = yyvsp[0]; }
#line 1751 "scanner.tab.c"
    break;


#line 1755 "scanner.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 309 "scanner.y"


int yyerror(char * message) {
  fprintf(listing,"Syntax error at line %d: %s\n",lineno,message);
  fprintf(listing,"Current token: ");
  printToken(listing, yychar,tokenString);
  Error = TRUE;
  return 0;
}

/* yylex calls getToken to make Yacc/Bison output
 * compatible with ealier versions of the TINY scanner
 */
static int yylex(void) {
  return getToken();
}

TreeNode * parse(void) {
  yyparse();
  return savedTree;
}
