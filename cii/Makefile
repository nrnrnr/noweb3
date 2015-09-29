# $Id$

include ../nwconfig

I=include
MAXALIGN=-DMAXALIGN=$(CIIMAXALIGN)
CIIFLAGS=-I$I $(MAXALIGN)
B=$(OUTPUT)$(P)

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
		$(AR)$@ $(OBJS) && $(RANLIB) $@

$Barena$O:	src/arena.c;	$(CC) $(CIIFLAGS) $(CFLAGS)$@ src/arena.c
$Barray$O:	src/array.c;	$(CC) $(CIIFLAGS) $(CFLAGS)$@ src/array.c
$Bassert$O:	src/assert.c;	$(CC) $(CIIFLAGS) $(CFLAGS)$@ src/assert.c
$Batom$O:	src/atom.c;	$(CC) $(CIIFLAGS) $(CFLAGS)$@ src/atom.c
$Bexcept$O:	src/except.c;	$(CC) $(CIIFLAGS) $(CFLAGS)$@ src/except.c
$Bfmt$O:	src/fmt.c;	$(CC) $(CIIFLAGS) $(CFLAGS)$@ src/fmt.c
$Blist$O:	src/list.c;	$(CC) $(CIIFLAGS) $(CFLAGS)$@ src/list.c
$Bmem$O:	src/mem.c;	$(CC) $(CIIFLAGS) $(CFLAGS)$@ src/mem.c
$Bmemchk$O:	src/memchk.c;	$(CC) $(CIIFLAGS) $(CFLAGS)$@ src/memchk.c
$Bseq$O:	src/seq.c;	$(CC) $(CIIFLAGS) $(CFLAGS)$@ src/seq.c
$Bstr$O:	src/str.c;	$(CC) $(CIIFLAGS) $(CFLAGS)$@ src/str.c

clean::
		-$(RM) $(OBJS) 2>$(NUL)

clobber::	clean
		-$(RM) $Blibcii$A $B*$O 2>$(NUL)

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
