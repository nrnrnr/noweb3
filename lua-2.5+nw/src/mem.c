/*
** mem.c
** TecCGraf - PUC-Rio
*/

char *rcs_mem = "$Id$";

#include <stdlib.h>

#include "mem.h"
#include "lua.h"
#include <mem.h>


void luaI_free (void *block)
{
  FREE(block);
#if 0
  if (block)
  {
    *((int *)block) = -1;  /* to catch errors */
    free(block);
  }
#endif
}


void *luaI_realloc (void *block, unsigned long size)
{
  size_t s = (size_t)size;
  if (s != size)
    lua_error("Allocation Error: Block too big");
  if (block)
    RESIZE (block, s);
  else
    block = ALLOC(s);
  if (block == NULL)
    lua_error(memEM);
  return block;
}


int luaI_growvector (void **block, unsigned long nelems, int size,
                       char *errormsg, unsigned long limit)
{
  if (nelems >= limit)
    lua_error(errormsg);
  nelems = (nelems == 0) ? 20 : nelems*2;
  if (nelems > limit)
    nelems = limit;
  *block = luaI_realloc(*block, nelems*size);
  return (int)nelems;
}


void* luaI_buffer (unsigned long size)
{
  static unsigned long buffsize = 0;
  static char* buffer = NULL;
  if (size > buffsize)
    buffer = luaI_realloc(buffer, buffsize=size);
  return buffer;
}

