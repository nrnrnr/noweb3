# Copyright 1995-1998 by Norman Ramsey.  All rights reserved.
# See file COPYRIGHT for more information.
#
# Edit nwconfig before running

include nwconfig

# Stop editing.  No user-serviceable parts below.
SHELL=/bin/sh
CINAME=
CIMSG=

all: 
	cd cii; make all
	cd lua-2.5+nw; make "CC=$(CC) -g" all
	cd c; make all 
	cd lua; make all

everything: all todo.html

install: all install-code install-scripts

install-code:
	-mkdir $(BIN) 2>/dev/null
	cp c/no $(BIN)
	cp c/nwmtime $(LIB3)

install-scripts:
	-mkdir $(LIB3) 2>/dev/null
	cd lua; make LIB2=$(LIB2) LIB3=$(LIB3) install

todo.html: todo.nw
	noweave -filter l2h -html todo.nw > todo.html

www: todo.html
	cp todo.html /home/cellar/nr/www/noweb/todo3.html

clean:
	for i in lua-2.5+nw c lua xdoc; do (cd $$i; make clean); done
	(cd cii; make clobber)
	rm -f *~ */*~

clobber: clean
	for i in lua-2.5+nw c lua xdoc; do (cd $$i; make clobber); done
	rm -f *.html
