#include <stdio.h>
#include <string.h>

/*
  A very fragile tool.
  This will only work for generating todo.html.
  That is why it is called l2htodo rather than just l2h.
  If todo.html is changed too much, this tool may need to be updated to match.
  Or, just be very careful about the format of todo.html.

  It does not generate ``good'' html, just sufficient for viewing todo.html.
*/

int main(int argc, char** argv) {
  int c;
  char token[40] = { 0 };
  char tocopy[2] = { 0 };
  char closing[10] = { 0 };
  while( (c=fgetc(stdin)) != EOF) {
    if(c=='\n') {
      c=fgetc(stdin);
      if(c=='\n') {
        fputs("</p>\n\n<p>",stdout);
      }
      else {
        fputc('\n',stdout);
      }
    }
    if(c=='&') {
      fputs("</td><td align=left valign=top>",stdout);
    }
    else if(c=='\\') {
      token[0] = '\\';
      token[1] = 0;
      while( !0 ) {
        c=fgetc(stdin);
        if(c==EOF) {
          fprintf(stderr,"End of input reached unexpectedly after reading %s!",token);
          return -1;
        }
        tocopy[0] = c;
        strcat(token,tocopy);
        if(strlen(token)>=sizeof(token)-1) {
          fprintf(stderr,"Token too long '%s'!",token);
          return -1;
        }
        if(strcmp(token,"\\\\")==0) {
          fputs("</td></tr>\n<tr><td align=center valign=top>",stdout);
          break;
        }
        if(strcmp(token,"\\begin{center}")==0) {
          fputs("<blockquote>",stdout);
          break;
        }
        if(strcmp(token,"\\begin{rawhtml}")==0) {
          break;
        }
        if(strcmp(token,"\\begin{tabularx}{\\textwidth}{l|l|l|X}")==0) {
          fputs("<table border><!-- alignment is l|l|l|X--><!-- 4 columns--><tr><td align=left valign=top>",stdout);
          break;
        }
        if(strcmp(token,"\\emph{")==0) {
          fputs("<em>",stdout);
          strcpy(closing, "</em>");
          break;
        }
        if(strcmp(token,"\\end{center}")==0) {
          fputs("</blockquote>",stdout);
          break;
        }
        if(strcmp(token,"\\end{rawhtml}")==0) {
          fputs("</blockquote>",stdout);
          break;
        }
	if(strcmp(token,"\\end{tabularx}")==0) {
          fputs("</td></tr></table>\n",stdout);
          break;
        }
        if(strcmp(token,"\\hline")==0) {
          break;
        }
        if(strcmp(token,"\\ldots")==0) {
          fputs("...",stdout);
          break;
        }
        if(strcmp(token,"\\multicolumn4{c}{")==0) {
          fputs("<td align=center colspan=4>",stdout);
          break;
        }
        if(strcmp(token,"\\section{")==0) {
          fputs("<h2>",stdout);
          strcpy(closing, "</h2>");
          break;
        }
        if(strcmp(token,"\\textbf{")==0) {
          fputs("<b>",stdout);
          strcpy(closing, "</b>");
          break;
        }
        if(strcmp(token,"\\texttt{")==0) {
          fputs("<tt>",stdout);
          strcpy(closing, "</tt>");
          break;
        }
      }
    }
    else if(c=='}') {
      fputs(closing,stdout);
      closing[0]=0;
    }
    else if(c!='$') {
      fputc(c,stdout);
    }
    fflush(stdout);
  }
}
