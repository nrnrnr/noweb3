# $Id$

include ../nwconfig

A=.a
O=.o
E=
I=include
MAXALIGN=-DMAXALIGN=$(CIIMAXALIGN)
CFLAGS=-g -I$I $(MAXALIGN) $(XCFLAGS)
AR=ar ruv
RANLIB=ranlib
RM=rm -f
BUILDDIR=.
B=$(BUILDDIR)/

# $Id$
OBJS=	$Barena$O \
	$Barray$O \
	$Bassert$O \
	$Batom$O \
	$Bexcept$O \
	$Bfmt$O \
	$Blist$O \
	$Bmem$O \
	$Bseq$O \
	$Bstr$O


all::		$Blibcii$A $Bmemchk$O

$Blibcii$A::	$(OBJS)
		$(AR) $@ $(OBJS); $(RANLIB) $@ || true

$Barena$O:	src/arena.c;	$(CC) $(CFLAGS) -c -o $@ src/arena.c
$Barray$O:	src/array.c;	$(CC) $(CFLAGS) -c -o $@ src/array.c
$Bassert$O:	src/assert.c;	$(CC) $(CFLAGS) -c -o $@ src/assert.c
$Batom$O:	src/atom.c;	$(CC) $(CFLAGS) -c -o $@ src/atom.c
$Bexcept$O:	src/except.c;	$(CC) $(CFLAGS) -c -o $@ src/except.c
$Bfmt$O:	src/fmt.c;	$(CC) $(CFLAGS) -c -o $@ src/fmt.c
$Blist$O:	src/list.c;	$(CC) $(CFLAGS) -c -o $@ src/list.c
$Bmem$O:	src/mem.c;	$(CC) $(CFLAGS) -c -o $@ src/mem.c
$Bmemchk$O:	src/memchk.c;	$(CC) $(CFLAGS) -c -o $@ src/memchk.c
$Bseq$O:	src/seq.c;	$(CC) $(CFLAGS) -c -o $@ src/seq.c
$Bstr$O:	src/str.c;	$(CC) $(CFLAGS) -c -o $@ src/str.c


clean::
		$(RM) $(OBJS)

clobber::	clean
		$(RM) $Blibcii$A $B*$O



# DO NOT DELETE THIS LINE -- make depend depends on it.

$Barena$O:	$I/assert.h $I/except.h $I/arena.h
$Barray$O:	$I/assert.h $I/except.h $I/array.h $I/arrayrep.h $I/mem.h
$Bassert$O:	$I/assert.h $I/except.h
$Batom$O:	$I/atom.h $I/assert.h $I/except.h $I/mem.h
$Bexcept$O:	$I/assert.h $I/except.h
$Bfmt$O:	$I/assert.h $I/except.h $I/fmt.h $I/mem.h
$Blist$O:	$I/assert.h $I/except.h $I/mem.h $I/list.h
$Bmem$O:	$I/assert.h $I/except.h $I/mem.h
$Bmemchk$O:	$I/assert.h $I/except.h $I/mem.h
$Bseq$O:	$I/assert.h $I/except.h $I/seq.h $I/array.h $I/arrayrep.h $I/mem.h
$Bstr$O:	$I/assert.h $I/except.h $I/fmt.h $I/str.h $I/mem.h
