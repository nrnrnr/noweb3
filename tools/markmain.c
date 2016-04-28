#line 66 "markmain.nw"
static char rcsid[] = "$Id: markmain.nw,v 2.26 2006/06/12 21:03:53 nr Exp nr $";
static char rcsname[] = "$Name: v2_11b $";
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include "errors.h"
#include "markup.h"
#include "getline.h"
#include "columns.h"

#line 35 "markmain.nw"
typedef enum state {Code=1, Docs=2, CodeIndex=3} State;
typedef enum mark {Begin=1, End=2} Mark;
typedef enum index {Defn=1, Use=2, Newline=3} Index;

static char *states[]  = { "bad state", "code", "docs", "code" };
static char *marks[]   = { "bad mark", "begin", "end" };
static char *indices[] = { "bad index", "defn", "use", "nl" };
static char low_at_sign = '@';

static void print_state(FILE *out, Mark be, State state, int count) {
    fprintf(out, "%c%s %s %d\n", low_at_sign, marks[be], states[state], count);
}

static void print_index(FILE *out, Index idx, char *arg) {
    if (arg)
        fprintf(out, "%cindex %s %s\n", low_at_sign, indices[idx], arg);
    else
        fprintf(out, "%cindex %s\n",    low_at_sign, indices[idx]);
}

static void print_pair(FILE *out, char *name, char *value) {
    if (value) {
        int last=strlen(value)-1;
        if (last>=0 && value[last]=='\n')
            fprintf(out, "%c%s %s%cnl\n", low_at_sign, name, value, low_at_sign);
        else
            fprintf(out, "%c%s %s\n", low_at_sign, name, value);
    } else
        fprintf(out, "%c%s\n", low_at_sign, name);
}

#line 80 "markmain.nw"
void markup (FILE* in, FILE *out, char *filename) {
    State state = Docs;         /* what we are reading */
    int quoting = 0;            /* currently quoting code? */
    int count = 0;              /* number of current chunk, from 0 */
    int missing_newline;        /* was last line missing a trailing \n? */
    int lineno = 0;             /* number of lines read */
    int last_open_quote;        /* line number of last unmatched open quote */

    char *line;                 /* part of line up to mark (or end) */
    char *mark;                 /* potentially marked part of line */
#define MAX_MODNAME 255
    char modname[MAX_MODNAME+1] = ""; /* name of module currently being read, 
                                         [[""]] if no module is being read */ 

    
#line 121 "markmain.nw"
print_pair(out, "file", filename);
print_state(out, Begin, state, count);
while ((line = getline_expand(in)) != NULL) {
    lineno++;
    
#line 172 "markmain.nw"
missing_newline = line[strlen(line)-1] != '\n';
#line 126 "markmain.nw"
    if (starts_code(line, filename, lineno)) {
        
#line 542 "markmain.nw"
if (quoting) {
    errorat(filename, last_open_quote, Warning, "open quote `[[' never closed");
    quoting = 0;
}
#line 128 "markmain.nw"
        print_state(out, End, state, count);
        count++;
        state = Code;
        print_state(out, Begin, state, count);
        getmodname(modname,MAX_MODNAME,line);
        print_pair(out,"defn",modname);
        print_pair(out,"nl",0);     /* could be implicit but this is better */
    } else if (is_def(line)) {
        
#line 528 "markmain.nw"
line = remove_def_marker(line);
while (*line && isspace(*line)) line++;
while (*line) {
  char tmp;
  char *s = line+1;
  while (*s && !isspace(*s)) s++;
  tmp = *s; *s = 0;
  print_index(out, Defn, line);
  *s = tmp;
  while (isspace(*s)) s++;
  line = s;
}
print_index(out, Newline, 0);
#line 137 "markmain.nw"
        if (state == Code)
            state = CodeIndex;
    } else {
        if (starts_doc(line) || state == CodeIndex) {
            
#line 542 "markmain.nw"
if (quoting) {
    errorat(filename, last_open_quote, Warning, "open quote `[[' never closed");
    quoting = 0;
}
#line 142 "markmain.nw"
            print_state(out, End, state, count);
            count++;
            state = Docs;       /* always reading docs after a stop */
            print_state(out, Begin, state, count);
            if (starts_doc(line))
                line = first_doc_line(line);
        }
        {   
#line 181 "markmain.nw"
char *p, *s, *t, c;
static char *buf;
static int buflen = 0;
#line 150 "markmain.nw"
            
#line 259 "markmain.nw"
#define LA1 '<'
#define LA2 '<'
#define RA1 '>'
#define RA2 '>'
#define LS1 '['
#define LS2 '['
#define RS1 ']'
#define RS2 ']'
#define ESC '@'
#line 272 "markmain.nw"
#define next(L) do {           c = *t++; goto L; } while (0)
#define copy(L) do { *s++ = c; c = *t++; goto L; } while (0)
#line 278 "markmain.nw"
#define lexassert(E) ((void)0)
#line 151 "markmain.nw"
            
#line 505 "markmain.nw"
if (buf == NULL)
  checkptr(buf = (char *) malloc(buflen = 128));
if (buflen < strlen(line) + 1 + 2) {
  while (buflen < strlen(line) + 1 + 2) 
    buflen *= 2;
  checkptr(buf = (char *) realloc(buf, buflen));
}
#line 186 "markmain.nw"
p = s = buf+2;
t = line;
c = *t++;
#line 152 "markmain.nw"
            
#line 206 "markmain.nw"
if (c == ESC && *t == ESC) { *s++ = ESC; c = *++t; ++t; }
#line 153 "markmain.nw"
            if (state == Code || quoting) 
                goto convert_code;
            else
                goto convert_docs;
            
#line 296 "markmain.nw"
convert_docs:
t: lexassert(state == Docs && !quoting);
   if (c == ESC) next(at);
   if (c == LA1) next(la);
   if (c == LS1) next(ls);
   
#line 242 "markmain.nw"
if (c == '\0') {
  
#line 513 "markmain.nw"
if (s > p) {
  *s = 0;
  print_pair(out, "text", p);
}
s = p = buf + 2;
#line 244 "markmain.nw"
  goto done_converting;
}
#line 302 "markmain.nw"
   copy(t);
#line 310 "markmain.nw"
at: if (c == LA1) next(atla);
    if (c == LS1) next(atls);
    if (c == RA1) next(atra);
    if (c == RS1) next(atrs);
    *s++ = ESC; goto t;
#line 319 "markmain.nw"
atls: if (c == LS2) { *s++ = LS1; *s++ = LS2; next(t); }
     *s++ = ESC; *s++ = LS1; goto t;
#line 325 "markmain.nw"
atla: if (c == LA2) { *s++ = LA1; *s++ = LA2; next(t); }
      *s++ = ESC; *s++ = LA1; goto t;
#line 331 "markmain.nw"
atrs: if (c == RS2) { *s++ = RS1; *s++ = RS2; next(t); }
     *s++ = ESC; *s++ = RS1; goto t;
#line 337 "markmain.nw"
atra: if (c == RA2) { *s++ = RA1; *s++ = RA2; next(t); }
      *s++ = ESC; *s++ = RA1; goto t;
#line 343 "markmain.nw"
la: if (c == LA2) {
      
#line 525 "markmain.nw"
errorat(filename, lineno, Error, "unescaped << in documentation chunk");
#line 345 "markmain.nw"
      *s++ = LA1; *s++ = LA2; next(t);
    }
    *s++ = LA1; goto t;
#line 355 "markmain.nw"
ls: lexassert(state == Docs);
    if (c == LS2) {
      
#line 513 "markmain.nw"
if (s > p) {
  *s = 0;
  print_pair(out, "text", p);
}
s = p = buf + 2;
#line 358 "markmain.nw"
      quoting = 1; last_open_quote = lineno; print_pair(out, "quote", 0); 
      next(c);
    }
    *s++ = LS1;
    goto t;
#line 372 "markmain.nw"
convert_code:
c: lexassert(state == Code || quoting);
   if (c == RS1 && quoting) next(crs);
   if (c == LA1) next(cla);
   if (c == ESC) next(cat);
   
#line 242 "markmain.nw"
if (c == '\0') {
  
#line 513 "markmain.nw"
if (s > p) {
  *s = 0;
  print_pair(out, "text", p);
}
s = p = buf + 2;
#line 244 "markmain.nw"
  goto done_converting;
}
#line 378 "markmain.nw"
   copy(c);
#line 386 "markmain.nw"
cat: if (c == LA1) next(catla);
     if (c == RA1) next(catra);
     *s++ = ESC; goto c;
#line 393 "markmain.nw"
catla: if (c == LA2) { *s++ = LA1; *s++ = LA2; next(c); }
       *s++ = ESC; *s++ = LA1; goto c;
#line 399 "markmain.nw"
catra: if (c == RA2) { *s++ = RA1; *s++ = RA2; next(c); }
       *s++ = ESC; *s++ = RA1; goto c;
#line 407 "markmain.nw"
crs: if (c == RS2) next(ce);
     *s++ = RS1; goto c;
#line 413 "markmain.nw"
ce: lexassert(quoting);
    if (c == RS2) copy(ce);
    quoting = 0; 
#line 513 "markmain.nw"
if (s > p) {
  *s = 0;
  print_pair(out, "text", p);
}
s = p = buf + 2;
#line 415 "markmain.nw"
                                                 print_pair(out, "endquote", 0);
    goto t;
#line 423 "markmain.nw"
cla: if (c == LA2) { 
#line 513 "markmain.nw"
if (s > p) {
  *s = 0;
  print_pair(out, "text", p);
}
s = p = buf + 2;
#line 423 "markmain.nw"
                                                     next(u); }
     *s++ = LA1; goto c;
#line 434 "markmain.nw"
u: lexassert(state == Code || quoting);
   if (c == LS1) copy(uls);
   if (c == RS1 && quoting) next(urs);
   if (c == RA1) next(ura);
   if (c == '\0') { /* premature end --- it's not a use after all */
     
#line 500 "markmain.nw"
lexassert(p == buf + 2);
p -= 2;
p[0] = LA1;
p[1] = LA2;
#line 440 "markmain.nw"
     goto c;
   }
   copy(u);
#line 447 "markmain.nw"
urs: lexassert(quoting);
     if (c == RS2) { /* premature end --- it's not a use after all */
       
#line 500 "markmain.nw"
lexassert(p == buf + 2);
p -= 2;
p[0] = LA1;
p[1] = LA2;
#line 450 "markmain.nw"
       next(ce); 
     }
     *s++ = RS1; goto u;
#line 457 "markmain.nw"
uls: if (c == LS2) copy(uc);
     goto u;
#line 464 "markmain.nw"
uc: lexassert(quoting || state == Code);
    if (c == RS1) copy(ucrs);
    if (c == '\0') {
      
#line 500 "markmain.nw"
lexassert(p == buf + 2);
p -= 2;
p[0] = LA1;
p[1] = LA2;
#line 468 "markmain.nw"
      goto c;
    }
    copy(uc);
#line 475 "markmain.nw"
ucrs: if (c == RS2) copy(uce);
      goto uc;
#line 481 "markmain.nw"
uce: if (c == RS2) copy(uce);
     goto u;
#line 487 "markmain.nw"
ura: if (c == RA2) { 
#line 520 "markmain.nw"
*s = 0;
print_pair(out, "use", p);
s = p = buf + 2;
#line 487 "markmain.nw"
                                                    next(c); }
     *s++ = RA1; goto u;
#line 158 "markmain.nw"
          done_converting: 
            (void)0;
        }
    }
}
#line 542 "markmain.nw"
if (quoting) {
    errorat(filename, last_open_quote, Warning, "open quote `[[' never closed");
    quoting = 0;
}
#line 174 "markmain.nw"
if (missing_newline) print_pair(out, "nl",0);
#line 165 "markmain.nw"
print_state(out, End, state, count);
#line 95 "markmain.nw"
}
#line 551 "markmain.nw"
main(int argc, char **argv) {
    FILE *fp;
    int i;

    progname = argv[0];	
    for (i = 1; i < argc && argv[i][0] == '-' && argv[i][1] != 0; i++)
        switch(argv[i][1]) {
            case 't': 
#line 582 "markmain.nw"
if (isdigit(argv[i][2]))
    tabsize = atoi(argv[i]+2);
else if (argv[i][2]==0)
    tabsize = 0;                /* no tabs */
else 
    errormsg(Error, "%s: ill-formed option %s", progname, argv[i]);
#line 558 "markmain.nw"
                                        break;
            default : errormsg(Error, "%s: unknown option -%c", progname, argv[i][1]);
                      break;
        }
    if (i < argc)
        for (; i < argc; i++) {
            if (!strcmp(argv[i], "-")) {
                markup(stdin,stdout,"");
            } else 
                if ((fp=fopen(argv[i],"r"))==NULL) {
                    errormsg(Error, "%s: couldn't open file %s", progname, argv[i]);
                    fprintf(stdout, "@fatal couldn't open file %s\n", argv[i]);
                } else {
                    markup(fp,stdout,argv[i]);
                    fclose(fp);
                }
        }
    else
        markup(stdin,stdout,"");
    nowebexit(NULL);
    return errorlevel;          /* slay warning */
}
