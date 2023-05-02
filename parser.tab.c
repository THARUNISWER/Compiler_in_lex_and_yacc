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
#line 1 "parser.y"

	#include <stdbool.h>
    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    #include<ctype.h>
	#include <stdarg.h>
	#include "header.h"

    int yywrap();
	int searchf(char *);
	int searchc(char *);
    int search(char *);
	int search_obj(char *clsname, char* obj_name) ;
	int search_obj_data(int cls_index, int obj_index, char* name, int data);
	void copyobj1(char* obj_name, char* cls_name);
	void copyobj2(char* obj_name, char* cls_name, nodeType* ptr);
	void addf(char *, nodeType *);
	void add_cls_data(nodeType *);
	void add_cls_func(nodeType *);
	void addmethpara(nodeType *);
	void addobjargs(int cls_index,int obj_index, nodeType *ptr);
	nodeType *obj_funccall_action(char* p1, char* p2, char* p3, nodeType* p4);
	nodeType *obj_value_access_action(char* p1, char* p2, char* p3);
	nodeType *obj_value_upd_action(char* p1, char* p2, char* p3, nodeType* p4);
	nodeType *funccall_action(char* p1, nodeType* p2);
	void cls_action(nodeType* p1, nodeType* p2);
	nodeType *opr(int oper, int nops, ...);
	nodeType *id(char* i);
	nodeType *con(double value);
	void freeNode(nodeType *p);
	double ex(nodeType *p);
	int yylex(void);
	void yyerror(char *s);
    extern int countn; 

	// arrays storing different types of errors like lexical, syntax and semantic
	int synerrs=0;
	char syntax_errors[10][200];
	int lex_cnt=0;
	char lex_errors[10][200];
	int sem_errors=0;	
	char errors[10][200]; 
	char reserved[15][10] = {"int", "float", "char", "void", "if", "else", "for", "main", "return", "while", "switch", "case", "default", "read" ,"write"};

	// 1.symbol table list is array of symbol tables.
	// 2.symbol_table_lst[0] is main function's symbol table 
	// 3.soon after a function is called, we maintain a new symbol table for that function call inserting all the functions args into this symbol table 
	int symbol_table_lst_itr=0;
	symtab symbol_table_lst[1000]; 

	// no of function definitions
	int function_cnt=0;	
	// all function parameters 
	char* func_parem_temp[10];
	int func_parem_temp_itr=0;
	// storing info about all defined functions like name, parameters, parsetree of the function body (used for execution of function calls)
	functab function_table[10];
	int args_count=0;

	//class
	int cls_cnt=0;
	cls class_table[10];
	object_node temp_obj[10];

#line 136 "parser.tab.c"

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
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
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
    VOID = 258,
    CONSTRUCTOR = 259,
    OBJV = 260,
    OBJD = 261,
    OBJF = 262,
    NEW = 263,
    CLASS = 264,
    ARROW = 265,
    WRITE = 266,
    WRITE_S = 267,
    READ = 268,
    ERROR = 269,
    FOR = 270,
    WHILE = 271,
    IF = 272,
    LE = 273,
    GE = 274,
    EQ = 275,
    NE = 276,
    RETURN = 277,
    MAIN = 278,
    PP = 279,
    SS = 280,
    PE = 281,
    SE = 282,
    ME = 283,
    DE = 284,
    DEF = 285,
    NUMBER = 286,
    ID = 287,
    STR = 288,
    NEWX = 289,
    IFX = 290,
    ELSE = 291,
    UMINUS = 292
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 67 "parser.y"

 double iValue; /* integer value */
 char* name; /* id_name */
 nodeType *nPtr; /* node pointer */

#line 232 "parser.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */



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
typedef yytype_int16 yy_state_t;

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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   625

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  122
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  285

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
       2,     2,     2,     2,     2,     2,     2,    52,     2,     2,
      47,    48,    38,    36,    49,    37,    53,    39,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    50,    46,
      35,    54,    34,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    51,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    44,     2,    45,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    40,
      41,    42,    43
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    87,    87,    88,    91,    95,    96,   100,   100,   101,
     101,   104,   108,   109,   110,   111,   115,   116,   120,   121,
     122,   122,   123,   127,   128,   129,   130,   133,   134,   137,
     137,   141,   142,   143,   146,   147,   148,   149,   152,   153,
     156,   157,   158,   159,   160,   161,   162,   166,   167,   168,
     169,   170,   171,   172,   176,   177,   178,   179,   180,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   197,
     198,   203,   204,   205,   206,   207,   208,   209,   213,   214,
     215,   218,   219,   220,   224,   225,   226,   226,   227,   228,
     229,   233,   234,   235,   238,   239,   242,   245,   246,   247,
     248,   249,   250,   251,   255,   256,   257,   258,   259,   263,
     264,   266,   267,   267,   269,   272,   276,   277,   279,   279,
     283,   284,   285
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VOID", "CONSTRUCTOR", "OBJV", "OBJD",
  "OBJF", "NEW", "CLASS", "ARROW", "WRITE", "WRITE_S", "READ", "ERROR",
  "FOR", "WHILE", "IF", "LE", "GE", "EQ", "NE", "RETURN", "MAIN", "PP",
  "SS", "PE", "SE", "ME", "DE", "DEF", "NUMBER", "ID", "STR", "'>'", "'<'",
  "'+'", "'-'", "'*'", "'/'", "NEWX", "IFX", "ELSE", "UMINUS", "'{'",
  "'}'", "';'", "'('", "')'", "','", "':'", "'^'", "'%'", "'.'", "'='",
  "$accept", "program", "main", "c_list", "cls", "$@1", "$@2", "cls_vars",
  "cls_funcs", "cls_meth", "$@3", "cls_paremlst", "functionlst",
  "function", "$@4", "paremlst", "bodylst", "body", "for", "while",
  "if_else", "write", "expression", "expr1", "expr2", "expr3", "$@5",
  "value", "read", "return", "condition", "statement", "t1", "t2", "$@6",
  "init", "t3", "t4", "functioncall", "$@7", "argslst", YY_NULLPTR
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
     285,   286,   287,   288,    62,    60,    43,    45,    42,    47,
     289,   290,   291,   292,   123,   125,    59,    40,    41,    44,
      58,    94,    37,    46,    61
};
# endif

#define YYPACT_NINF (-203)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -5,    -8,    19,    36,   141,  -203,    24,     1,  -203,   278,
    -203,  -203,    39,   105,   139,    24,  -203,   148,    51,    44,
    -203,    65,   151,   234,   149,    -3,   245,  -203,  -203,  -203,
    -203,  -203,  -203,  -203,   161,  -203,  -203,  -203,  -203,  -203,
     150,   138,   167,    86,  -203,  -203,    97,  -203,  -203,    33,
     174,   149,   149,   -20,    74,    72,  -203,  -203,  -203,   182,
     190,   143,   221,   -12,   278,   586,   542,   278,   555,   114,
    -203,  -203,   149,   191,     0,   195,  -203,  -203,  -203,  -203,
      97,    86,    86,  -203,  -203,   100,   198,   203,    34,   149,
     149,   149,   149,  -203,   219,  -203,  -203,    67,   210,   210,
    -203,   210,   210,   210,   210,  -203,  -203,   149,  -203,   149,
      -2,   302,   149,   149,   149,   149,   149,   149,   278,   337,
     349,   278,   142,  -203,   149,   202,   241,   154,   278,    34,
     177,   184,   238,   266,  -203,  -203,   122,   217,    57,  -203,
     154,   154,   154,   154,   250,  -203,   -38,    74,    74,    72,
      72,  -203,  -203,    25,    65,   263,  -203,   154,   154,   154,
     154,   154,   154,   374,  -203,   243,   189,   265,   269,   154,
     231,   282,   273,   386,    69,   284,  -203,   278,  -203,  -203,
     289,  -203,   187,   292,  -203,  -203,   308,    65,   297,   299,
     278,  -203,   300,   301,   304,   278,   312,  -203,   149,   303,
     149,   316,  -203,   278,   323,   278,   321,   187,  -203,  -203,
     235,   325,   568,   278,   278,   398,   278,   278,   581,   410,
     278,   154,   149,   239,   326,   278,   278,   328,   187,   248,
     330,   343,  -203,   278,   422,   434,   446,  -203,   458,   470,
     278,   482,  -203,   494,   154,  -203,   278,   331,   278,  -203,
     253,   334,   278,  -203,   149,   506,  -203,  -203,  -203,  -203,
    -203,   518,  -203,  -203,   530,  -203,   335,   339,   278,   278,
     257,  -203,  -203,  -203,  -203,   278,   278,   341,  -203,   278,
     347,  -203,   348,  -203,  -203
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      11,     0,     0,     0,     0,     3,    33,     6,     7,     0,
       9,     1,     0,     0,     0,    28,     5,     0,     0,     0,
     112,     0,   103,   103,     0,   103,     0,    39,    40,    45,
      41,    43,    44,    46,     0,   104,   105,   106,   107,   108,
       0,     0,     0,    37,     2,    27,    15,    93,    91,    92,
       0,     0,     0,     0,    73,    80,    83,    89,    85,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     116,   117,   118,     0,     0,     0,   111,     4,    38,    42,
      15,    37,    37,    36,    35,     0,     0,     0,    22,     0,
       0,     0,     0,   118,     0,    70,    90,     0,     0,     0,
      69,     0,     0,     0,     0,    95,    94,     0,   113,   103,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    57,
       0,     0,     0,    96,   122,     0,     0,   114,     0,    22,
       0,     0,     0,     0,    14,    13,     0,     0,     0,    17,
      74,    75,    76,    77,     0,    84,    92,    71,    72,    78,
      79,    81,    82,     0,     0,     0,    58,    99,   100,   101,
     102,    98,    97,    56,    55,     0,     0,     0,     0,   121,
       0,     0,   109,     0,     0,     0,    29,     0,    34,    20,
       0,    12,    26,     0,     8,    16,     0,     0,     0,     0,
       0,    54,     0,     0,    59,     0,     0,   119,     0,     0,
     122,     0,    10,     0,     0,     0,     0,    26,    25,    24,
       0,    88,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   120,     0,     0,     0,     0,     0,    46,    26,     0,
       0,     0,    86,     0,    53,     0,     0,    50,     0,     0,
       0,    68,    65,     0,   115,   110,     0,    46,     0,    31,
       0,     0,     0,    23,   122,    52,    51,    49,    48,    63,
      62,    67,    66,    61,     0,    32,    46,     0,     0,     0,
       0,    47,    60,    64,    30,     0,     0,    46,    87,     0,
      46,    19,    46,    18,    21
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -203,  -203,   365,   388,  -203,  -203,  -203,   318,   275,  -125,
    -203,  -155,   390,  -203,  -203,   188,   109,   -26,  -203,  -203,
    -203,  -203,    54,   232,   236,   229,  -203,  -203,  -203,  -202,
     -18,   -15,  -203,  -203,  -203,   346,  -203,  -203,    18,  -203,
    -199
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,     7,    17,    40,    88,   138,   139,
     206,   210,    14,    15,   204,    85,    26,    27,    28,    29,
      30,    31,    65,    54,    55,    56,   254,    57,    32,    33,
      66,    34,    35,    36,    61,    76,    37,    38,    39,   124,
     170
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      78,   223,    47,   227,     1,    68,    63,    75,   126,    93,
       1,    47,    20,   185,    47,    94,    98,    99,     2,    48,
      49,    70,    71,   247,     8,    51,   100,     3,    48,    49,
      62,    48,    49,     3,    51,    52,    58,    51,   109,    20,
      58,    58,    58,    58,    72,   110,   266,    52,   154,   185,
      73,    74,   229,    41,    12,   270,    13,    62,    59,    89,
      90,    91,    92,     9,   136,    47,   137,   277,    10,    58,
      58,    42,    53,   250,   280,   187,    60,   282,    69,    20,
      93,    58,    48,    49,    50,    78,    94,   136,    51,   183,
      58,   153,    58,    78,    78,   155,    78,    62,    52,   136,
      83,   183,   184,    98,    99,    96,    97,    58,    58,    58,
      58,    86,   101,   102,   202,   145,    58,    58,    84,    58,
      58,    58,    58,   103,   104,    58,    97,    58,   127,    87,
      58,    58,    58,    58,    58,    58,   179,    78,   188,   189,
      78,    11,    58,   140,   141,   142,   143,    78,   132,   133,
      98,    99,    43,    18,   180,    19,    20,    21,    22,    23,
     123,   127,     2,    47,    24,    47,   157,   158,   159,   160,
     161,   162,   212,   111,    25,   119,   120,   122,   169,    78,
      48,    49,    48,    49,   167,    81,    51,   168,    51,    78,
      98,    99,    46,    78,    80,    64,    52,   107,    52,    78,
      18,   208,    19,    20,    21,    22,    23,    79,    78,    78,
      78,    24,    78,    78,    82,    78,    58,    78,    58,   209,
      95,    25,    78,   125,    47,   175,   133,   163,   105,    78,
     166,   193,   176,   133,   194,    78,   106,   173,    78,   128,
      58,    48,   146,    78,   134,    70,    71,    51,    47,   135,
      78,   144,   221,    78,   169,   171,    18,    52,    19,    20,
      21,    22,    23,   181,   182,    48,    49,    24,    93,   130,
     131,    51,    58,   172,    73,    74,   244,    25,    67,   197,
     198,    52,   177,   230,   231,   192,   205,   245,   198,    18,
      77,    19,    20,    21,    22,    23,   251,   231,   178,   215,
      24,   267,   231,   186,   219,   278,   198,   190,   169,   195,
      25,   196,   225,    18,   199,    19,    20,    21,    22,    23,
     200,   234,   235,   236,    24,   238,   239,   241,   203,   243,
     147,   148,   151,   152,    25,   248,   207,   149,   150,   182,
     211,   213,   255,   214,   216,   217,   218,   156,    18,   261,
      19,    20,    21,    22,    23,   264,   220,   222,   224,    24,
      18,   269,    19,    20,    21,    22,    23,   226,   228,    25,
     246,    24,   232,   249,   252,   253,   265,   276,   268,    44,
     274,    25,   164,   275,   279,    18,   281,    19,    20,    21,
      22,    23,   283,   284,   165,    16,    24,    18,   129,    19,
      20,    21,    22,    23,   174,    45,    25,   108,    24,    18,
       0,    19,    20,    21,    22,    23,     0,     0,    25,   191,
      24,    18,     0,    19,    20,    21,    22,    23,     0,     0,
      25,   201,    24,    18,     0,    19,    20,    21,    22,    23,
       0,     0,    25,   237,    24,    18,     0,    19,    20,    21,
      22,    23,     0,     0,    25,   242,    24,    18,     0,    19,
      20,    21,    22,    23,     0,     0,    25,   256,    24,    18,
       0,    19,    20,    21,    22,    23,     0,     0,    25,   257,
      24,    18,     0,    19,    20,    21,    22,    23,     0,     0,
      25,   258,    24,    18,     0,    19,    20,    21,    22,    23,
       0,     0,    25,   259,    24,    18,     0,    19,    20,    21,
      22,    23,     0,     0,    25,   260,    24,    18,     0,    19,
      20,    21,    22,    23,     0,     0,    25,   262,    24,    18,
       0,    19,    20,    21,    22,    23,     0,     0,    25,   263,
      24,    18,     0,    19,    20,    21,    22,    23,     0,     0,
      25,   271,    24,    18,     0,    19,    20,    21,    22,    23,
       0,     0,    25,   272,    24,     0,    18,     0,    19,    20,
      21,    22,    23,     0,    25,   273,     0,    24,     0,    18,
       0,    19,    20,    21,    22,    23,   118,    25,     0,     0,
      24,     0,    18,     0,    19,    20,    21,    22,    23,   121,
      25,     0,     0,    24,   112,   113,   114,   115,     0,     0,
       0,     0,   233,    25,     0,     0,     0,     0,     0,     0,
     116,   117,    98,    99,     0,   240
};

static const yytype_int16 yycheck[] =
{
      26,   200,    14,   205,     9,    23,    21,    25,     8,    47,
       9,    14,    14,   138,    14,    53,    36,    37,    23,    31,
      32,    24,    25,   225,    32,    37,    46,    32,    31,    32,
      32,    31,    32,    32,    37,    47,    18,    37,    50,    14,
      22,    23,    24,    25,    47,    63,   248,    47,    50,   174,
      53,    54,   207,    14,    30,   254,    32,    32,    14,    26,
      27,    28,    29,    44,    30,    14,    32,   269,    32,    51,
      52,    32,    18,   228,   276,    50,    32,   279,    24,    14,
      47,    63,    31,    32,    33,   111,    53,    30,    37,    32,
      72,   109,    74,   119,   120,   110,   122,    32,    47,    30,
      14,    32,    45,    36,    37,    51,    52,    89,    90,    91,
      92,    14,    38,    39,    45,    48,    98,    99,    32,   101,
     102,   103,   104,    51,    52,   107,    72,   109,    74,    32,
     112,   113,   114,   115,   116,   117,    14,   163,   153,   154,
     166,     0,   124,    89,    90,    91,    92,   173,    48,    49,
      36,    37,    47,    11,    32,    13,    14,    15,    16,    17,
      46,   107,    23,    14,    22,    14,   112,   113,   114,   115,
     116,   117,   187,    64,    32,    66,    67,    68,   124,   205,
      31,    32,    31,    32,    42,    47,    37,    45,    37,   215,
      36,    37,    44,   219,    44,    44,    47,    54,    47,   225,
      11,    14,    13,    14,    15,    16,    17,    46,   234,   235,
     236,    22,   238,   239,    47,   241,   198,   243,   200,    32,
      46,    32,   248,    32,    14,    48,    49,   118,    46,   255,
     121,    42,    48,    49,    45,   261,    46,   128,   264,    44,
     222,    31,    32,   269,    46,    24,    25,    37,    14,    46,
     276,    32,   198,   279,   200,    53,    11,    47,    13,    14,
      15,    16,    17,    46,    47,    31,    32,    22,    47,    81,
      82,    37,   254,    32,    53,    54,   222,    32,    44,    48,
      49,    47,    44,    48,    49,    42,   177,    48,    49,    11,
      45,    13,    14,    15,    16,    17,    48,    49,    32,   190,
      22,    48,    49,    53,   195,    48,    49,    44,   254,    44,
      32,    42,   203,    11,    32,    13,    14,    15,    16,    17,
      47,   212,   213,   214,    22,   216,   217,   218,    44,   220,
      98,    99,   103,   104,    32,   226,    47,   101,   102,    47,
      32,    44,   233,    44,    44,    44,    42,    45,    11,   240,
      13,    14,    15,    16,    17,   246,    44,    54,    42,    22,
      11,   252,    13,    14,    15,    16,    17,    44,    47,    32,
      44,    22,    47,    45,    44,    32,    45,   268,    44,    14,
      45,    32,    45,    44,   275,    11,    45,    13,    14,    15,
      16,    17,    45,    45,    45,     7,    22,    11,    80,    13,
      14,    15,    16,    17,   129,    15,    32,    61,    22,    11,
      -1,    13,    14,    15,    16,    17,    -1,    -1,    32,    45,
      22,    11,    -1,    13,    14,    15,    16,    17,    -1,    -1,
      32,    45,    22,    11,    -1,    13,    14,    15,    16,    17,
      -1,    -1,    32,    45,    22,    11,    -1,    13,    14,    15,
      16,    17,    -1,    -1,    32,    45,    22,    11,    -1,    13,
      14,    15,    16,    17,    -1,    -1,    32,    45,    22,    11,
      -1,    13,    14,    15,    16,    17,    -1,    -1,    32,    45,
      22,    11,    -1,    13,    14,    15,    16,    17,    -1,    -1,
      32,    45,    22,    11,    -1,    13,    14,    15,    16,    17,
      -1,    -1,    32,    45,    22,    11,    -1,    13,    14,    15,
      16,    17,    -1,    -1,    32,    45,    22,    11,    -1,    13,
      14,    15,    16,    17,    -1,    -1,    32,    45,    22,    11,
      -1,    13,    14,    15,    16,    17,    -1,    -1,    32,    45,
      22,    11,    -1,    13,    14,    15,    16,    17,    -1,    -1,
      32,    45,    22,    11,    -1,    13,    14,    15,    16,    17,
      -1,    -1,    32,    45,    22,    -1,    11,    -1,    13,    14,
      15,    16,    17,    -1,    32,    45,    -1,    22,    -1,    11,
      -1,    13,    14,    15,    16,    17,    44,    32,    -1,    -1,
      22,    -1,    11,    -1,    13,    14,    15,    16,    17,    44,
      32,    -1,    -1,    22,    18,    19,    20,    21,    -1,    -1,
      -1,    -1,    44,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    35,    36,    37,    -1,    44
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     9,    23,    32,    56,    57,    58,    59,    32,    44,
      32,     0,    30,    32,    67,    68,    58,    60,    11,    13,
      14,    15,    16,    17,    22,    32,    71,    72,    73,    74,
      75,    76,    83,    84,    86,    87,    88,    91,    92,    93,
      61,    14,    32,    47,    57,    67,    44,    14,    31,    32,
      33,    37,    47,    77,    78,    79,    80,    82,    93,    14,
      32,    89,    32,    86,    44,    77,    85,    44,    85,    77,
      24,    25,    47,    53,    54,    85,    90,    45,    72,    46,
      44,    47,    47,    14,    32,    70,    14,    32,    62,    26,
      27,    28,    29,    47,    53,    46,    77,    77,    36,    37,
      46,    38,    39,    51,    52,    46,    46,    54,    90,    50,
      85,    71,    18,    19,    20,    21,    34,    35,    44,    71,
      71,    44,    71,    46,    94,    32,     8,    77,    44,    62,
      70,    70,    48,    49,    46,    46,    30,    32,    63,    64,
      77,    77,    77,    77,    32,    48,    32,    78,    78,    79,
      79,    80,    80,    85,    50,    86,    45,    77,    77,    77,
      77,    77,    77,    71,    45,    45,    71,    42,    45,    77,
      95,    53,    32,    71,    63,    48,    48,    44,    32,    14,
      32,    46,    47,    32,    45,    64,    53,    50,    86,    86,
      44,    45,    42,    42,    45,    44,    42,    48,    49,    32,
      47,    45,    45,    44,    69,    71,    65,    47,    14,    32,
      66,    32,    86,    44,    44,    71,    44,    44,    42,    71,
      44,    77,    54,    95,    42,    71,    44,    84,    47,    66,
      48,    49,    47,    44,    71,    71,    71,    45,    71,    71,
      44,    71,    45,    71,    77,    48,    44,    84,    71,    45,
      66,    48,    44,    32,    81,    71,    45,    45,    45,    45,
      45,    71,    45,    45,    71,    45,    84,    48,    44,    71,
      95,    45,    45,    45,    45,    44,    71,    84,    48,    71,
      84,    45,    84,    45,    45
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    55,    56,    56,    57,    58,    58,    60,    59,    61,
      59,    59,    62,    62,    62,    62,    63,    63,    64,    64,
      65,    64,    64,    66,    66,    66,    66,    67,    67,    69,
      68,    68,    68,    68,    70,    70,    70,    70,    71,    71,
      72,    72,    72,    72,    72,    72,    72,    73,    73,    73,
      73,    73,    73,    73,    74,    74,    74,    74,    74,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    76,
      76,    77,    77,    77,    77,    77,    77,    77,    78,    78,
      78,    79,    79,    79,    80,    80,    81,    80,    80,    80,
      80,    82,    82,    82,    83,    83,    84,    85,    85,    85,
      85,    85,    85,    85,    86,    86,    86,    86,    86,    87,
      87,    88,    89,    88,    90,    91,    92,    92,    94,    93,
      95,    95,    95
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     1,     4,     2,     1,     0,     7,     0,
       7,     0,     3,     2,     2,     0,     2,     1,     9,     8,
       0,    10,     0,     3,     1,     1,     0,     2,     1,     0,
      10,     8,     9,     0,     3,     1,     1,     0,     2,     1,
       1,     1,     2,     1,     1,     1,     1,     9,     8,     8,
       7,     8,     8,     7,     5,     4,     4,     3,     4,     5,
       9,     8,     8,     8,     9,     7,     8,     8,     7,     3,
       3,     3,     3,     1,     3,     3,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     1,     0,     9,     5,     1,
       2,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     0,     1,     1,     1,     1,     1,     4,
       7,     2,     0,     3,     2,     7,     2,     2,     0,     5,
       3,     1,     0
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
  case 4:
#line 91 "parser.y"
                                                                                                { if(lex_cnt + synerrs + sem_errors==0){ ex((yyvsp[-1].nPtr)); freeNode((yyvsp[-1].nPtr)); } }
#line 1665 "parser.tab.c"
    break;

  case 7:
#line 100 "parser.y"
         {class_table[cls_cnt].cls_name= (yyvsp[0].name);}
#line 1671 "parser.tab.c"
    break;

  case 8:
#line 100 "parser.y"
                                                                         { cls_action((yyvsp[-2].nPtr), (yyvsp[-1].nPtr)); }
#line 1677 "parser.tab.c"
    break;

  case 9:
#line 101 "parser.y"
        {
	sprintf(syntax_errors[synerrs], "syntax error in line %d , wrong declaration of the class \n", countn ); synerrs++;    
}
#line 1685 "parser.tab.c"
    break;

  case 10:
#line 103 "parser.y"
                                                                                        { ; }
#line 1691 "parser.tab.c"
    break;

  case 11:
#line 104 "parser.y"
                                                                        { (yyval.nPtr)= NULL;}
#line 1697 "parser.tab.c"
    break;

  case 12:
#line 108 "parser.y"
                                                                                {  (yyval.nPtr) = opr('^', 2, (yyvsp[-2].nPtr), id((yyvsp[-1].name))); }
#line 1703 "parser.tab.c"
    break;

  case 13:
#line 109 "parser.y"
                                                                                {  (yyval.nPtr) = opr('^', 2, NULL, id((yyvsp[-1].name))); }
#line 1709 "parser.tab.c"
    break;

  case 14:
#line 110 "parser.y"
                                                                                                                {  sprintf(lex_errors[lex_cnt], "Lexical error in line %d , Error in defining an Identifier/Function\n", countn); lex_cnt++;    }
#line 1715 "parser.tab.c"
    break;

  case 15:
#line 111 "parser.y"
                                                                                { ;}
#line 1721 "parser.tab.c"
    break;

  case 16:
#line 115 "parser.y"
                                                                        { (yyval.nPtr) = opr('^', 2, (yyvsp[-1].nPtr), (yyvsp[0].nPtr)); }
#line 1727 "parser.tab.c"
    break;

  case 17:
#line 116 "parser.y"
                                                                        { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1733 "parser.tab.c"
    break;

  case 18:
#line 120 "parser.y"
                                                                { (yyval.nPtr) = opr(';', 4, id((yyvsp[-7].name)), (yyvsp[-5].nPtr), (yyvsp[-2].nPtr), (yyvsp[-1].nPtr)); }
#line 1739 "parser.tab.c"
    break;

  case 19:
#line 121 "parser.y"
                                                                { sprintf(syntax_errors[synerrs], "syntax error in line %d , def is missing in front of function definition\n", countn); synerrs++; }
#line 1745 "parser.tab.c"
    break;

  case 20:
#line 122 "parser.y"
                                                                                                { sprintf(lex_errors[lex_cnt], "Lexical error in line %d , Error in naming a Function\n", countn); lex_cnt++;    }
#line 1751 "parser.tab.c"
    break;

  case 21:
#line 122 "parser.y"
                                                                                                                                                                                                                                                               { (yyval.nPtr) =  NULL;}
#line 1757 "parser.tab.c"
    break;

  case 22:
#line 123 "parser.y"
                                                                { (yyval.nPtr) =  NULL;}
#line 1763 "parser.tab.c"
    break;

  case 23:
#line 127 "parser.y"
                                                                                { (yyval.nPtr) = opr('!', 2, (yyvsp[-2].nPtr), id((yyvsp[0].name))); }
#line 1769 "parser.tab.c"
    break;

  case 24:
#line 128 "parser.y"
                                                                                { (yyval.nPtr) = opr('!', 2, NULL, id((yyvsp[0].name))); }
#line 1775 "parser.tab.c"
    break;

  case 25:
#line 129 "parser.y"
                                                                                                                { sprintf(lex_errors[lex_cnt], "Lexical error in line %d , Error in defining an Identifier/Function\n", countn); lex_cnt++;    }
#line 1781 "parser.tab.c"
    break;

  case 26:
#line 130 "parser.y"
                                                                                { (yyval.nPtr) = NULL;}
#line 1787 "parser.tab.c"
    break;

  case 29:
#line 137 "parser.y"
                                  {
															  function_table[function_cnt].func_name=strdup((yyvsp[-3].name));
															  function_table[function_cnt].num_parem= func_parem_temp_itr; function_cnt++; 
							    }
#line 1796 "parser.tab.c"
    break;

  case 30:
#line 140 "parser.y"
                                                                                        { (yyval.nPtr) = opr(';', 2, (yyvsp[-2].nPtr), (yyvsp[-1].nPtr)); addf((yyvsp[-8].name), (yyval.nPtr)); }
#line 1802 "parser.tab.c"
    break;

  case 31:
#line 141 "parser.y"
                                                                        { sprintf(syntax_errors[synerrs], "syntax error in line %d , def is missing in front of function definition\n", countn); synerrs++;    }
#line 1808 "parser.tab.c"
    break;

  case 32:
#line 142 "parser.y"
                                                                { sprintf(lex_errors[lex_cnt], "Lexical error in line %d , Error in defining an Identifier/Function\n", countn); lex_cnt++;    }
#line 1814 "parser.tab.c"
    break;

  case 33:
#line 143 "parser.y"
                                                                                                                        { ; }
#line 1820 "parser.tab.c"
    break;

  case 34:
#line 146 "parser.y"
                                                                                                { func_parem_temp[func_parem_temp_itr]= (yyvsp[0].name); func_parem_temp_itr++; }
#line 1826 "parser.tab.c"
    break;

  case 35:
#line 147 "parser.y"
                                                                                                                { func_parem_temp[func_parem_temp_itr]= (yyvsp[0].name); func_parem_temp_itr++;	}
#line 1832 "parser.tab.c"
    break;

  case 36:
#line 148 "parser.y"
                                                                                                                { sprintf(lex_errors[lex_cnt], "Lexical error in line %d , Error in defining an Argument\n", countn); lex_cnt++; }
#line 1838 "parser.tab.c"
    break;

  case 37:
#line 149 "parser.y"
                                                                                                                        { ; }
#line 1844 "parser.tab.c"
    break;

  case 38:
#line 152 "parser.y"
                                                                                                { (yyval.nPtr) = opr(';', 2, (yyvsp[-1].nPtr), (yyvsp[0].nPtr)); }
#line 1850 "parser.tab.c"
    break;

  case 47:
#line 166 "parser.y"
                                                                { (yyval.nPtr) = opr(FOR, 4, (yyvsp[-7].nPtr), (yyvsp[-5].nPtr), (yyvsp[-3].nPtr), (yyvsp[-1].nPtr)); }
#line 1856 "parser.tab.c"
    break;

  case 48:
#line 167 "parser.y"
                                                                { sprintf(syntax_errors[synerrs], "Syntax error in line %d , error in defining for loop : ':' missing \n", countn); synerrs++;    }
#line 1862 "parser.tab.c"
    break;

  case 49:
#line 168 "parser.y"
                                                            { sprintf(syntax_errors[synerrs], "Syntax error in line %d , error in defining for loop : ':' missing \n", countn); synerrs++;    }
#line 1868 "parser.tab.c"
    break;

  case 50:
#line 169 "parser.y"
                                                                    { sprintf(syntax_errors[synerrs], "Syntax error in line %d , error in defining for loop: ':' missing \n", countn); synerrs++;    }
#line 1874 "parser.tab.c"
    break;

  case 51:
#line 170 "parser.y"
                                                            { sprintf(syntax_errors[synerrs], "Syntax error in line %d , error in defining for loop : '{' missing \n", countn); synerrs++;    }
#line 1880 "parser.tab.c"
    break;

  case 52:
#line 171 "parser.y"
                                                                { sprintf(syntax_errors[synerrs], "Syntax error in line %d , error in defining for loop : '}' missing \n", countn); synerrs++;    }
#line 1886 "parser.tab.c"
    break;

  case 53:
#line 172 "parser.y"
                                                                { sprintf(syntax_errors[synerrs], "Syntax error in line %d , error in defining for loop : '{' and '}' missing  \n", countn); synerrs++;    }
#line 1892 "parser.tab.c"
    break;

  case 54:
#line 176 "parser.y"
                                                                                        { (yyval.nPtr) = opr(WHILE, 2, (yyvsp[-3].nPtr), (yyvsp[-1].nPtr));  }
#line 1898 "parser.tab.c"
    break;

  case 55:
#line 177 "parser.y"
                                                                                        { sprintf(syntax_errors[synerrs], "Syntax error in line %d , error in defining while loop : '{' missing \n", countn); synerrs++;    }
#line 1904 "parser.tab.c"
    break;

  case 56:
#line 178 "parser.y"
                                                                                        { sprintf(syntax_errors[synerrs], "Syntax error in line %d , error in defining while loop : '}' missing \n", countn); synerrs++;    }
#line 1910 "parser.tab.c"
    break;

  case 57:
#line 179 "parser.y"
                                                                                        { sprintf(syntax_errors[synerrs], "Syntax error in line %d , error in defining while loop : '{' and '}' missing \n", countn); synerrs++;    }
#line 1916 "parser.tab.c"
    break;

  case 58:
#line 180 "parser.y"
                                                                                                { sprintf(syntax_errors[synerrs], "Syntax error in line %d , error in defining while loop : condition missing \n", countn); synerrs++;    }
#line 1922 "parser.tab.c"
    break;

  case 59:
#line 184 "parser.y"
                                                                { (yyval.nPtr) = opr(IF, 2, (yyvsp[-3].nPtr), (yyvsp[-1].nPtr)); }
#line 1928 "parser.tab.c"
    break;

  case 60:
#line 185 "parser.y"
                                                                { (yyval.nPtr) = opr(IF, 3, (yyvsp[-7].nPtr), (yyvsp[-5].nPtr), (yyvsp[-1].nPtr)); }
#line 1934 "parser.tab.c"
    break;

  case 61:
#line 186 "parser.y"
                                                                { sprintf(syntax_errors[synerrs], "Syntax error in line %d , error in defining if statement : '{' missing \n", countn); synerrs++;    }
#line 1940 "parser.tab.c"
    break;

  case 62:
#line 187 "parser.y"
                                                                { sprintf(syntax_errors[synerrs], "Syntax error in line %d , error in defining if statement : '}' missing \n", countn); synerrs++;    }
#line 1946 "parser.tab.c"
    break;

  case 63:
#line 188 "parser.y"
                                                                        { sprintf(syntax_errors[synerrs], "Syntax error in line %d , error in defining if statement : condition missing \n", countn); synerrs++;    }
#line 1952 "parser.tab.c"
    break;

  case 64:
#line 189 "parser.y"
                                                                { sprintf(syntax_errors[synerrs], "Syntax error in line %d , error in defining if statement : \"if\" not written correctly \n", countn); synerrs++;    }
#line 1958 "parser.tab.c"
    break;

  case 65:
#line 190 "parser.y"
                                                                { sprintf(syntax_errors[synerrs], "Syntax error in line %d , error in defining if statement : '{' and '}' missing \n", countn); synerrs++;    }
#line 1964 "parser.tab.c"
    break;

  case 66:
#line 191 "parser.y"
                                                                { sprintf(syntax_errors[synerrs], "Syntax error in line %d , error in defining else statement : '{' missing \n", countn); synerrs++;    }
#line 1970 "parser.tab.c"
    break;

  case 67:
#line 192 "parser.y"
                                                                { sprintf(syntax_errors[synerrs], "Syntax error in line %d , error in defining else statement : '}' missing \n", countn); synerrs++;    }
#line 1976 "parser.tab.c"
    break;

  case 68:
#line 193 "parser.y"
                                                                { sprintf(syntax_errors[synerrs], "Syntax error in line %d , error in defining else statement : '{' and '}' missing \n", countn); synerrs++;    }
#line 1982 "parser.tab.c"
    break;

  case 69:
#line 197 "parser.y"
                                                                                                { (yyval.nPtr) = opr(WRITE, 1, (yyvsp[-1].nPtr)); }
#line 1988 "parser.tab.c"
    break;

  case 70:
#line 198 "parser.y"
                                                                                                        { (yyval.nPtr) = opr(WRITE_S, 1, id((yyvsp[-1].name))); }
#line 1994 "parser.tab.c"
    break;

  case 71:
#line 203 "parser.y"
                                                                                                { (yyval.nPtr) = opr('+', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 2000 "parser.tab.c"
    break;

  case 72:
#line 204 "parser.y"
                                                                                                { (yyval.nPtr) = opr('-', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 2006 "parser.tab.c"
    break;

  case 74:
#line 206 "parser.y"
                                                                                                { (yyval.nPtr) = opr(PE, 2, id((yyvsp[-2].name)), (yyvsp[0].nPtr)); }
#line 2012 "parser.tab.c"
    break;

  case 75:
#line 207 "parser.y"
                                                                                                { (yyval.nPtr) = opr(SE, 2, id((yyvsp[-2].name)), (yyvsp[0].nPtr)); }
#line 2018 "parser.tab.c"
    break;

  case 76:
#line 208 "parser.y"
                                                                                                { (yyval.nPtr) = opr(ME, 2, id((yyvsp[-2].name)), (yyvsp[0].nPtr)); }
#line 2024 "parser.tab.c"
    break;

  case 77:
#line 209 "parser.y"
                                                                                                { (yyval.nPtr) = opr(DE, 2, id((yyvsp[-2].name)), (yyvsp[0].nPtr)); }
#line 2030 "parser.tab.c"
    break;

  case 78:
#line 213 "parser.y"
                  { (yyval.nPtr) = opr('*', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 2036 "parser.tab.c"
    break;

  case 79:
#line 214 "parser.y"
                  { (yyval.nPtr) = opr('/', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 2042 "parser.tab.c"
    break;

  case 81:
#line 218 "parser.y"
                       { (yyval.nPtr) = opr('^', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 2048 "parser.tab.c"
    break;

  case 82:
#line 219 "parser.y"
                  { (yyval.nPtr) = opr('%', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 2054 "parser.tab.c"
    break;

  case 84:
#line 224 "parser.y"
                                                                                        { (yyval.nPtr) = (yyvsp[-1].nPtr); }
#line 2060 "parser.tab.c"
    break;

  case 85:
#line 225 "parser.y"
                                                                                                        { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 2066 "parser.tab.c"
    break;

  case 86:
#line 226 "parser.y"
                       { args_count=0;}
#line 2072 "parser.tab.c"
    break;

  case 87:
#line 226 "parser.y"
                                                                    { (yyval.nPtr) = obj_funccall_action((yyvsp[-8].name), (yyvsp[-6].name), (yyvsp[-4].name), (yyvsp[-1].nPtr)); }
#line 2078 "parser.tab.c"
    break;

  case 88:
#line 227 "parser.y"
                                                                                                        { (yyval.nPtr) = obj_value_access_action((yyvsp[-4].name), (yyvsp[-2].name), (yyvsp[0].name)); }
#line 2084 "parser.tab.c"
    break;

  case 89:
#line 228 "parser.y"
                                                                                                        { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 2090 "parser.tab.c"
    break;

  case 90:
#line 229 "parser.y"
                                                                                        { (yyval.nPtr) = opr(UMINUS, 1, (yyvsp[0].nPtr)); }
#line 2096 "parser.tab.c"
    break;

  case 91:
#line 233 "parser.y"
                                                                                                                { (yyval.nPtr) = con((yyvsp[0].iValue)); }
#line 2102 "parser.tab.c"
    break;

  case 92:
#line 234 "parser.y"
                                                                                                                { (yyval.nPtr) = id((yyvsp[0].name));	}
#line 2108 "parser.tab.c"
    break;

  case 93:
#line 235 "parser.y"
                                                                                                                { sprintf(lex_errors[lex_cnt], "Lexical error in line %d , Error in defining an Identifier/Function\n", countn); lex_cnt++; }
#line 2114 "parser.tab.c"
    break;

  case 94:
#line 238 "parser.y"
                                                                                                        { (yyval.nPtr)=opr(READ, 1, id((yyvsp[-1].name)));}
#line 2120 "parser.tab.c"
    break;

  case 95:
#line 239 "parser.y"
                                                                                                        { sprintf(lex_errors[lex_cnt], "Lexical error in line %d , Error in defining an Identifier/Function\n", countn); lex_cnt++; }
#line 2126 "parser.tab.c"
    break;

  case 96:
#line 242 "parser.y"
                                                                                        { (yyval.nPtr) = opr(RETURN, 1, (yyvsp[-1].nPtr)); }
#line 2132 "parser.tab.c"
    break;

  case 97:
#line 245 "parser.y"
                                                                                        { (yyval.nPtr) = opr('<', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 2138 "parser.tab.c"
    break;

  case 98:
#line 246 "parser.y"
                                                                                        { (yyval.nPtr) = opr('>', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 2144 "parser.tab.c"
    break;

  case 99:
#line 247 "parser.y"
                                                                                        { (yyval.nPtr) = opr(LE , 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 2150 "parser.tab.c"
    break;

  case 100:
#line 248 "parser.y"
                                                                                        { (yyval.nPtr) = opr(GE , 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 2156 "parser.tab.c"
    break;

  case 101:
#line 249 "parser.y"
                                                                                        { (yyval.nPtr) = opr(EQ , 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 2162 "parser.tab.c"
    break;

  case 102:
#line 250 "parser.y"
                                                                                        { (yyval.nPtr) = opr(NE , 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 2168 "parser.tab.c"
    break;

  case 103:
#line 251 "parser.y"
             { }
#line 2174 "parser.tab.c"
    break;

  case 109:
#line 263 "parser.y"
                                                                                                { (yyval.nPtr) = NULL; if(searchc((yyvsp[0].name))==-1){ sprintf(errors[sem_errors], "semantic error in line %d , class not defined \n", countn); sem_errors++; } else copyobj1((yyvsp[-3].name), (yyvsp[0].name));     }
#line 2180 "parser.tab.c"
    break;

  case 110:
#line 264 "parser.y"
                                                                                        { (yyval.nPtr) = (yyvsp[-1].nPtr)  ; if(searchc((yyvsp[-3].name))==-1){ sprintf(errors[sem_errors], "semantic error in line %d , class not defined \n", countn); sem_errors++; } else copyobj2((yyvsp[-6].name), (yyvsp[-3].name), (yyvsp[-1].nPtr)); }
#line 2186 "parser.tab.c"
    break;

  case 111:
#line 266 "parser.y"
                                                                                                        { (yyval.nPtr) = opr('=', 2, id((yyvsp[-1].name)), (yyvsp[0].nPtr)); }
#line 2192 "parser.tab.c"
    break;

  case 112:
#line 267 "parser.y"
                                                                                                                { sprintf(lex_errors[lex_cnt], "Lexical error in line %d , Error in defining an Identifier\n", countn); lex_cnt++; }
#line 2198 "parser.tab.c"
    break;

  case 113:
#line 267 "parser.y"
                                                                                                                                                                                                                                          {;}
#line 2204 "parser.tab.c"
    break;

  case 114:
#line 269 "parser.y"
                                                                                                { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 2210 "parser.tab.c"
    break;

  case 115:
#line 272 "parser.y"
                                                                        { (yyval.nPtr)= obj_value_upd_action((yyvsp[-6].name), (yyvsp[-4].name), (yyvsp[-2].name), (yyvsp[0].nPtr)); }
#line 2216 "parser.tab.c"
    break;

  case 116:
#line 276 "parser.y"
                                                                                                                { (yyval.nPtr)= opr(PP,1,id((yyvsp[-1].name))); }
#line 2222 "parser.tab.c"
    break;

  case 117:
#line 277 "parser.y"
                                                                                                                { (yyval.nPtr) = opr(SS,1,id((yyvsp[-1].name))); }
#line 2228 "parser.tab.c"
    break;

  case 118:
#line 279 "parser.y"
                      { args_count=0; }
#line 2234 "parser.tab.c"
    break;

  case 119:
#line 279 "parser.y"
                                                                { (yyval.nPtr) = funccall_action((yyvsp[-4].name), (yyvsp[-1].nPtr)); }
#line 2240 "parser.tab.c"
    break;

  case 120:
#line 283 "parser.y"
                                                                                        { args_count++; (yyval.nPtr) = opr(';', 2, (yyvsp[-2].nPtr)  , (yyvsp[0].nPtr)); }
#line 2246 "parser.tab.c"
    break;

  case 121:
#line 284 "parser.y"
                                                                                                { args_count++; (yyval.nPtr) = opr(';', 2, NULL, (yyvsp[0].nPtr)); }
#line 2252 "parser.tab.c"
    break;

  case 122:
#line 285 "parser.y"
                                                                                                { (yyval.nPtr)=NULL;}
#line 2258 "parser.tab.c"
    break;


#line 2262 "parser.tab.c"

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
#line 286 "parser.y"


int main(int arg_c , char**arg_v) {
	extern FILE* yyin;
	FILE* f = fopen(arg_v[1], "r"); 
	yyin =f;
    yyparse();
	int total_error = lex_cnt + synerrs + sem_errors;
	if(total_error>0){
		printf("\t\t\t---====<<<<<[       PHASE 1: LEXICAL ANALYSIS       ]>>>>>====--- \n\n");
		if(lex_cnt>0) {
			printf("Lexical errors found during Lexical analysis\n\n");
			for(int i=0; i<lex_cnt; i++){
				printf("\t - %s \n", lex_errors[i]);
			}
		}else {
			printf("Lexical analysis completed with ZERO Errors");
			printf("\n\n");	
		}
		printf("\n\n");
		printf("\t\t\t---====<<<<<[       PHASE 2:  SYNTAX ANALYSIS       ]>>>>>====--- \n\n");
		if(synerrs>0) {
			printf("Syntax errors found during syntax analysis\n\n");
			for(int i=0; i<synerrs; i++){
				printf("\t - %s\n", syntax_errors[i]);
			}
		} else {
			printf("Syntax analysis completed with ZERO Errors");
			printf("\n\n");	
		}
		printf("\n\n\n\n");
		printf("\t\t\t---====<<<<<[      PHASE 3:  SEMANTIC ANALYSIS      ]>>>>>====--- \n\n");
		
		if(sem_errors>0) {
			printf("Semantic analysis completed with %d errors\n\n", sem_errors);
			for(int i=0; i<sem_errors; i++){
				printf("\t - %s\n", errors[i]);
			}
		} else {
			printf("Semantic analysis completed with ZERO Errors");
		}

		
		printf("\n\n");
		if(total_error!=0) return 0;
	}

	return 0;
}

void cls_action(nodeType* p1, nodeType* p2){
	class_table[cls_cnt].obj_cnt=0;
	temp_obj[cls_cnt].data_index=0;
	temp_obj[cls_cnt].func_index=0;
	add_cls_data(p1); 
	add_cls_func(p2); 
	cls_cnt++; 
}

nodeType *obj_funccall_action(char* p1, char* p2, char* p3, nodeType* p4){
	int cls_index= searchc(p1);
	int obj_index= search_obj(p1, p2);
	if(cls_index==-1){ 
		sprintf(errors[sem_errors], "semantic error in line %d , class not defined \n", countn); sem_errors++; 
	}else if(obj_index==-1){
		sprintf(errors[sem_errors], "semantic error in line %d , object not created \n", countn); sem_errors++;
	}else if(search_obj_data(cls_index, obj_index, p3, 0)==-1){
		sprintf(errors[sem_errors], "semantic error in line %d , function not declared in the class \n", countn); sem_errors++;
	}else{
		bool valid_funcname=false, valid_args_count=false;
		for(int i=0; i<class_table[cls_index].objtab[obj_index].func_index ; i++){
			if(strcmp(p3, class_table[cls_index].objtab[obj_index].obj_func[i].func_name)==0){
				valid_funcname= true; 
				if(args_count== class_table[cls_index].objtab[obj_index].obj_func[i].num_parem){
					valid_args_count=true;
					break;
				}
				
			}
		}
		if(!valid_funcname){
			sprintf(errors[sem_errors], "semantic error in line %d , function not defined \n", countn); sem_errors++;   
		}else if(!valid_args_count){
			sprintf(errors[sem_errors], "semantic error in line %d , number of arguments not matched with function definition \n", countn); sem_errors++;   
		}else{
			return opr(OBJF, 4, id(p1), id(p2), id(p3), p4);
		}
	}
	return NULL;
}

nodeType *obj_value_access_action(char* p1, char* p2, char* p3){
	int cls_index= searchc(p1);
	int obj_index= search_obj(p1, p2);
	if(cls_index==-1){ 
		sprintf(errors[sem_errors], "semantic error in line %d , class not defined \n", countn); sem_errors++; 
	}else if(obj_index==-1){
		sprintf(errors[sem_errors], "semantic error in line %d , object not created \n", countn); sem_errors++;
	}else if(search_obj_data(cls_index, obj_index, p3, 1)==-1){
		sprintf(errors[sem_errors], "semantic error in line %d , variable not declared in the class \n", countn); sem_errors++;
	}else{
		return opr(OBJV, 3, id(p1), id(p2), id(p3) );
	}
	return NULL;
}

nodeType *obj_value_upd_action(char* p1, char* p2, char* p3, nodeType* p4){
	int cls_index= searchc(p1);
	int obj_index= search_obj(p1, p2);
	if(cls_index==-1){ 
		sprintf(errors[sem_errors], "semantic error in line %d , class not defined \n", countn); sem_errors++; 
	}else if(obj_index==-1){
		sprintf(errors[sem_errors], "semantic error in line %d , object not created \n", countn); sem_errors++;
	}else if(search_obj_data(cls_index, obj_index, p3, 1)==-1){
		sprintf(errors[sem_errors], "semantic error in line %d , variable not declared in the class \n", countn); sem_errors++;
	}else{
		return opr(OBJD, 4, id(p1),id(p2),id(p3),p4);
	}
	return NULL;
}

nodeType *funccall_action(char* p1, nodeType* p2){
	
	bool valid_funcname=false, valid_args_count=false;
	for(int i=0; i<function_cnt ; i++){
        if(strcmp(p1, function_table[i].func_name)==0){
			valid_funcname= true; 
			if(args_count== function_table[i].num_parem){
				valid_args_count=true;
				break;
			}
			
		}
	}
	if(!valid_funcname){
		sprintf(errors[sem_errors], "semantic error in line %d , function not defined \n", countn); sem_errors++;   
	}else if(!valid_args_count){
		sprintf(errors[sem_errors], "semantic error in line %d , number of arguments not matched with function definition \n", countn); sem_errors++;   
	}else{
		return opr(ARROW, 2, id(p1), p2);
	}
	return NULL;
}

void add_cls_data(nodeType *ptr){
   if(!ptr) return;
   switch(ptr->opr.oper){
      case '^':
         {  
            add_cls_data(ptr->opr.op[0]);
            temp_obj[cls_cnt].obj_data[temp_obj[cls_cnt].data_index].id_name = ptr->opr.op[1]->id.i;
			temp_obj[cls_cnt].obj_data[temp_obj[cls_cnt].data_index].value=0; 
			temp_obj[cls_cnt].data_index++;
         }
   }
}

void add_cls_func (nodeType *ptr){
   if(!ptr) return;

   switch(ptr->type){
      case typeOpr:
         {
            switch(ptr->opr.oper){
               case '^':
                  {
                     add_cls_func (ptr->opr.op[0]);
                     add_cls_func (ptr->opr.op[1]);
                  }

               case ';':
                  {
					temp_obj[cls_cnt].obj_func[temp_obj[cls_cnt].func_index].func_name = ptr->opr.op[0]->id.i;
                     temp_obj[cls_cnt].obj_func[temp_obj[cls_cnt].func_index].num_parem = 0;
                     addmethpara(ptr->opr.op[1]);

                     nodeType *p = opr(';', 2, ptr->opr.op[2], ptr->opr.op[3]);
                     temp_obj[cls_cnt].obj_func[temp_obj[cls_cnt].func_index].root = p;
					 temp_obj[cls_cnt].func_index++;
                  }
            }
         }
   }
}

void addmethpara(nodeType *ptr){
if(!ptr) return;

   switch(ptr->type){
      case typeOpr:
         {
            switch(ptr->opr.oper){
               case '!':
                  {
                     addmethpara(ptr->opr.op[0]);
					 int parem_ind= temp_obj[cls_cnt].obj_func[temp_obj[cls_cnt].func_index].num_parem;
					 temp_obj[cls_cnt].obj_func[temp_obj[cls_cnt].func_index].parem_list[parem_ind]= ptr->opr.op[1]->id.i;
					 temp_obj[cls_cnt].obj_func[temp_obj[cls_cnt].func_index].num_parem++;
                     
                  }
            }
         }
   }
}
void copyobj1(char* obj_name, char* cls_name){
	int cls_index= searchc(cls_name);
	int obj_index= class_table[cls_index].obj_cnt;
	class_table[cls_index].objtab[obj_index] = temp_obj[cls_index]; 
	class_table[cls_index].objtab[obj_index].obj_name= obj_name;
	class_table[cls_index].obj_cnt++;
	return;
}
void copyobj2(char* obj_name, char* cls_name, nodeType* ptr){
	int cls_index= searchc(cls_name);
	int obj_index= class_table[cls_index].obj_cnt;
	if(args_count != temp_obj[cls_index].data_index){
		printf("%d\n", args_count);
		sprintf(errors[sem_errors], "semantic error in line %d: number of arguments given doesn't match number of member variables defined in this class \n", countn);
		sem_errors++;
	}else{
		class_table[cls_index].objtab[obj_index] = temp_obj[cls_index]; 
		class_table[cls_index].objtab[obj_index].obj_name= obj_name;
		args_count=0;
		addobjargs(cls_index, obj_index, ptr);
		class_table[cls_index].obj_cnt++;
	}
	return;
}

void addobjargs(int cls_index,int obj_index, nodeType *ptr){
if(!ptr) return;

   switch(ptr->type){
      case typeOpr:
         {
            switch(ptr->opr.oper){
               case ';':
                  {
                     addobjargs(cls_index, obj_index, ptr->opr.op[0]); 
					 class_table[cls_index].objtab[obj_index].obj_data[args_count].value= ex(ptr->opr.op[1]);
                     args_count++;
                  }
            }
         }
   }
}

int search(char *type) {
	int i;
	for(i=0;i<symbol_table_lst[symbol_table_lst_itr].symbol_table_itr ;i++) {
		if(strcmp(symbol_table_lst[symbol_table_lst_itr].symbol_table[i].id_name, strdup(type))==0) {
			return i;
		}
	}
	return -1;
}

void addf(char* func_name, nodeType *root){
		for(int i=0; i<sizeof(reserved)/sizeof(reserved[0]); i++){
			if(!strcmp(reserved[i], strdup(func_name))){
        		sprintf(errors[sem_errors], "Line %d: function name \"%s\" is a reserved keyword!\n", countn+1, func_name);
				sem_errors++;   
				return;
			}
		}	
    //int q=searchf(func_name);
	int q=-1;
	if(q==-1) {
			function_cnt--;
			for(int i=0; i<func_parem_temp_itr; i++){
				function_table[function_cnt].parem_list[i]= func_parem_temp[i];
			}
			//reset func_parem values
			func_parem_temp_itr=0;

			function_table[function_cnt].root= root;
			function_cnt++;
    }		
}

int searchf(char *type) {
	int i;
	for(i=0;i<function_cnt;i++) {
		if(strcmp(function_table[i].func_name, strdup(type))==0) { //should search for parameters also
			return i;
		}
	}
	return -1;
}

int searchc(char *type) {
	int i;
	for(i=0;i<cls_cnt;i++) {
		if(strcmp(class_table[i].cls_name, strdup(type))==0) { //should search for parameters also
			return i;
		}
	}
	return -1;
}

int search_obj(char *cls_name, char* obj_name) {
	int i;
	int x=class_table[searchc(cls_name)].obj_cnt; 
	for(i=0;i<x;i++) {
		if(strcmp(class_table[searchc(cls_name)].objtab[i].obj_name, strdup(obj_name))==0) { //should search for parameters also
			return i;
		}
	}
	return -1;
}

int search_obj_data(int cls_index, int obj_index, char* name, int data) {
	int i;
	int x;
	if(data==1){ 
		x=class_table[cls_index].objtab[obj_index].data_index; 
	}
	else {
		x= class_table[cls_index].objtab[obj_index].func_index;
	}
	for(i=0;i<x;i++) {
		char* type;
		if(data==1){ 
			type=strdup(class_table[cls_index].objtab[obj_index].obj_data[i].id_name); 
		}
		else {
			type=strdup(class_table[cls_index].objtab[obj_index].obj_func[i].func_name); 
		}
		if(strcmp(name, strdup(type))==0) { //should search for parameters also
			return i;
		}
	}
	return -1;
}
#define SIZEOF_NODETYPE ((char *)&p->con - (char *)p)
nodeType *con(double value) {
    nodeType *p;
    /* allocate node */ 
    if ((p = malloc(sizeof(nodeType))) == NULL) yyerror("out of memory");
    /* copy information */
    p->type = typeCon;
    p->con.value = value;
    return p;
}
nodeType *id(char* i) { 
    nodeType *p;
    /* allocate node */
    if ((p = malloc(sizeof(nodeType))) == NULL)  yyerror("out of memory");
    /* copy information */
    p->type = typeId;
    p->id.i = strdup(i);
    return p; 
} 
nodeType *opr(int oper, int nops, ...) {
    va_list ap; 
    nodeType *p;
    int i; 
    /* allocate node */
    if ((p = malloc(sizeof(nodeType))) == NULL)  yyerror("out of memory");
    if ((p->opr.op = malloc(nops * sizeof(nodeType))) == NULL) yyerror("out of memory");
    /* copy information */
    p->type = typeOpr;
    p->opr.oper = oper;
    p->opr.nops = nops;
    va_start(ap, nops);
    for (i = 0; i < nops; i++) p->opr.op[i] = va_arg(ap, nodeType*);
    va_end(ap);
    return p;
} 
void freeNode(nodeType *p) {
    int i;
    if (!p) return;
    if (p->type == typeOpr) {
        for (i = 0; i < p->opr.nops; i++)
            freeNode(p->opr.op[i]);
        free(p->opr.op);
    }
    free (p);
} 

void yyerror(char* msg) { 
		sprintf(syntax_errors[synerrs], "%s in line no: %d\n", msg, countn);
		synerrs++;   
} 
