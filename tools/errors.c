#line 17 "errors.nw"
static char rcsid[] = "$Id: errors.nw,v 2.23 2006/06/12 21:03:53 nr Exp nr $";
static char rcsname[] = "$Name: v2_11b $";
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "errors.h"

#line 34 "errors.nw"
enum errorlevel errorlevel = Normal;
int finalstage = 0;
char *progname = NULL;
#line 44 "errors.nw"
void nowebexit(char *msg) {
  if (!finalstage && errorlevel > Normal)
    printf("@fatal %s %s\n", progname != NULL ? progname : "a-noweb-filter",
	   msg != NULL ? msg : "an unspecified error occurred");
  exit(errorlevel);
}
#line 58 "errors.nw"
void errormsg(enum errorlevel level, char *s,...) {     
    va_list args;                       /* see K&R, page 174 */
    va_start(args,s);
    
#line 79 "errors.nw"
if (level > errorlevel)
    errorlevel = level;
vfprintf(stderr, s, args);
fprintf(stderr,"\n");
#line 62 "errors.nw"
    va_end(args);
    if (level >= Fatal)
        nowebexit(s);
}
#line 69 "errors.nw"
void errorat(char *filename, int lineno, enum errorlevel level, char *s, ...) {     
    va_list args;                       /* see K&R, page 174 */
    va_start(args,s);
    fprintf(stderr, "%s:%d: ", filename, lineno);
    
#line 79 "errors.nw"
if (level > errorlevel)
    errorlevel = level;
vfprintf(stderr, s, args);
fprintf(stderr,"\n");
#line 74 "errors.nw"
    va_end(args);
    if (level >= Fatal)
        nowebexit(s);
}
