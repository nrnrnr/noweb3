# makefile for lua distribution (compiler)

LUA=../..

include ../../../nwconfig
include ../../config

INCS= -I$(INC) $(EXTRA_INCS) -I..
OBJS= dump.o luac.o print.o
SRCS= dump.c luac.c print.c luac.h print.h
T=$(BIN)/luac

all: $T

$T: $(OBJS) $(LIB)/liblua.a
	$(CC) -o $@ $(OBJS) -L$(LIB) -llua $(LIBEXTRA)

clean:
	rm -f $(OBJS) $T

co:
	co -f -M $(SRCS)

klean:	clean
	rm -f $(SRCS)
