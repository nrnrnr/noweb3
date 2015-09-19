#include <stdio.h>

void putfile(FILE* file) {
  int c;
  while( (c=fgetc(file)) != EOF) {
    putc(c,stdout);
  }
  fflush(stdout);
}

int main(int argc, char** argv) {
  putfile(stdin);
  for(int i=1;i<=argc;i++) {
    FILE* current = fopen(argv[i], "r");
    putfile(current);
    fclose(current);
  }
}
