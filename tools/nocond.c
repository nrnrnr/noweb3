#include <stdio.h>

typedef enum state {
  Start = 1,
  Space = 2,
  FirstOpenPar = 3,
  SecondOpenPar = 4,
  Match = 5,
  FirstClosePar = 6
} State;

/*
  The smallest power of two bigger than the biggest condition required
  to build Noweb 3
  -----
  This is not a general purpose tool!
*/
char match[8];

int main(int argc, char** argv) {
  State state = Start;
  strncpy(match,argv[1],sizeof(match)/sizeof(char));
  int c;
  int place=0;
  while( (c=fgetc(stdin)) != EOF) {
    switch(state) {
      case Start:
        if(c==' ')
          state = Space;
        else
          fputc(c,stdout);
        break;
      case Space:
        if(c=='(')
          state = FirstOpenPar;
        else {
          fputc(' ',stdout);
          fputc(c,stdout);
          state = Start;
        }
        break;
      case FirstOpenPar:
        if(c=='(') {
          state = SecondOpenPar;
          place=0;
        }
        else {
          fputc(' ',stdout);
          fputc('(',stdout);
          fputc(c,stdout);
          state = Start;
        }
        break;
      case SecondOpenPar:
        if(c==match[place]) {
          place++;
          if(match[place]==0)
            state=Match;
        }
        else {
          fputc(' ',stdout);
          fputc('(',stdout);
          fputc('(',stdout);
          for(int i=0;i<place;i++)
             fputc(match[i],stdout);
          fputc(c,stdout);
          state = Start;
        }
        break;
      case Match:
        if(c==')')
          state = FirstClosePar;
        else {
          fputc(' ',stdout);
          fputc('(',stdout);
          fputc('(',stdout);
          fputs(match,stdout);
          fputc(c,stdout);
          state = Start;
        }
        break;
      case FirstClosePar:
        if(c!=')') {
          fputc(' ',stdout);
          fputc('(',stdout);
          fputc('(',stdout);
          fputs(match,stdout);
          fputc(')',stdout);
          fputc(c,stdout);
        }
        state = Start;
        break;
    }
    fflush(stdout);
  }
}
