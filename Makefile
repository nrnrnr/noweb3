# Copyright 1995-1998 by Norman Ramsey.  All rights reserved.
# See file COPYRIGHT for more information.
#
# Edit nwconfig before running

include nwconfig

# Stop editing.  No user-serviceable parts below.

all:
	-mkdir $(LIB3)$(P)tools 2>$(NUL)
	cd tools && $(MK) "OUTPUT=$(LIB3)$(P)tools" && cd ..
	-mkdir $(LIB3)$(P)cii 2>$(NUL)
	cd cii && $(MK) "OUTPUT=$(LIB3)$(P)cii" && cd ..
	-mkdir $(LIB3)$(P)lua-2.5+nw
	cd lua-2.5+nw && $(MK) $(LuaMakefile) "OUTPUT=$(LIB3)$(P)lua-2.5+nw" && cd ..
	$(LuaCpCommand)
# Makefile and Makefile.win are to be identical up through this line!
	cd c; make all 
	cd lua; make all

everything: all todo.html

install: all install-code install-scripts

install-code:
	-mkdir $(BINDIR) 2>/dev/null || true
	-mkdir $(LIB3) 2>/dev/null || true
	cp c/no $(BINDIR)/.
	cp c/nwmtime $(LIB3)/.

install-scripts:
	-mkdir $(LIB3) 2>/dev/null || true
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
