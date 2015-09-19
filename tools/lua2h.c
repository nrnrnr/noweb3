#include <stdio.h>

int main(int argc, char** argv) {

  printf("char %s[] = \n",argv[1]);
  printf("\"");

  int c;

  while( (c = fgetc(stdin)) != EOF ) {
    if( c == '"')
      printf("\\\"");
    else if( c =='\n' || c == '\r' )
      printf("\\n\"\n\"");
    else if( c == '\\')
      printf("\\\\");
    else
      printf("%c",c);
    }

  printf("\";");
}
