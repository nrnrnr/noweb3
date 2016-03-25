# makefile for lua interpreter

LUA= ../..

include ../../../nwconfig
include ../../config

EXTRA_DEFS= $(POSIX)

OBJS= lua.o
SRCS= lua.c

T=$(BINDIR)/lua

all: $T

$T: $(OBJS) $(LIB)/liblua.a $(LIB)/liblualib.a
	$(CC) -o $@ $(OBJS) -L$(LIB) -llua -llualib $(LIBEXTRA) -lm 

lbench: bench.o $(LIB)/liblua.a $(LIB)/liblualib.a
	$(CC) -o $@ bench.o -L$(LIB) -llua -llualib $(LIBEXTRA) -lm 

dynamic:
	rm -f $T
	make

clean:
	rm -f $(OBJS)

co:
	co -f -M $(SRCS)

klean:	clean
	rm -f $(SRCS)
