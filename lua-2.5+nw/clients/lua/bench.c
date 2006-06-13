/*
** lua.c
** Linguagem para Usuarios de Aplicacao
*/

char *rcs_lua="$Id$";

#include <stdio.h>
#include <string.h>

#include "lua.h"
#include "lualib.h"


#ifdef _POSIX_SOURCE
#include <unistd.h>
#else
#define isatty(x)       (x==0)  /* assume stdin is a tty */
#endif


int main (int argc, char *argv[])
{
  int i;
  int result = 0;
  iolib_open ();
  strlib_open ();
  mathlib_open ();
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <filename> <arguments>\n", argv[0]);
    exit(1);
  } else {
    lua_Object lua_arg;
    lua_arg = lua_createtable();
    for (i=2; i<argc; i++) {
      lua_pushobject(lua_arg);
      lua_pushnumber((double)(i-1));
      lua_pushstring(argv[i]);
      lua_storesubscript();
    }
    lua_pushobject(lua_arg);
    lua_storeglobal("arg");
    result = lua_dofile (argv[1]);
    if (result) {
      if (result == 2) {
        fprintf(stderr, "lua: cannot execute file `%s' - ", argv[i]);
        perror(NULL);
      }
      return 1;
    }
  }
  return result;
}

