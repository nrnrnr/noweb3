#define WRONGTOKEN 257
#define NIL 258
#define IF 259
#define THEN 260
#define ELSE 261
#define ELSEIF 262
#define WHILE 263
#define DO 264
#define REPEAT 265
#define UNTIL 266
#define CASE 267
#define GLOBMATCH 268
#define OF 269
#define END 270
#define RETURN 271
#define LOCAL 272
#define FUNCTION 273
#define DOTS 274
#define ARROW 275
#define NUMBER 276
#define STRING 277
#define NAME 278
#define AND 279
#define OR 280
#define EQ 281
#define NE 282
#define LE 283
#define GE 284
#define CONC 285
#define UNARY 286
#define NOT 287
typedef union 
{
 int   vInt;
 float vFloat;
 char *pChar;
 Word  vWord;
 Long  vLong;
 TFunc *pFunc;
 TaggedString *pTStr;
} YYSTYPE;
extern YYSTYPE luaY_lval;
