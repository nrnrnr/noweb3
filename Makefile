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
	-mkdir $(LIB3)$(P)lua-2.5+nw 2>$(NUL)
	cd lua-2.5+nw && $(MK) $(LuaMakefile) "OUTPUT=$(LIB3)$(P)lua-2.5+nw" && cd .. && $(LuaCpCommand)
	-mkdir $(LIB3)$(P)c 2>$(NUL)
	cd c && $(MK) "NOTANGLE=more" "TANGLEOPTS= | $(LIB3)$(P)tools$(P)nocond $(PIPE) | $(LIB3)$(P)tools$(P)markup | $(LIB3)$(P)tools$(P)nt" "CPIF=>" "TOOLS=$(LIB3)$(P)tools" "OUTPUT=$(LIB3)$(P)c" && cd ..
	-mkdir $(LIB3)$(P)lua 2>$(NUL)
	cd lua && $(MK) "NOTANGLE=more" "TANGLEOPTS= | $(LIB3)$(P)tools$(P)nocond $(PIPE) | $(LIB3)$(P)tools$(P)markup | $(LIB3)$(P)tools$(P)nt" "CPIF=>" "OUTPUT=$(LIB3)$(P)lua" && cd ..
	-mkdir $(LIB3)$(P)tex
	cd tex && $(MK) "NOTANGLE=more" "TANGLEOPTS= | $(LIB3)$(P)tools$(P)nocond $(PIPE) | $(LIB3)$(P)tools$(P)markup | $(LIB3)$(P)tools$(P)nt" "CPIF=>" "OUTPUT=$(LIB3)$(P)tex" && cd ..

careful:
	-$(RMDIR) $(LIB3)$(P)first 2>$(NUL)
	mkdir $(LIB3)$(P)first
	$(MK) clobber
# Makefile and Makefile.win are to be identical up through this line!

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
	cd tools && $(MK) "OUTPUT=$(LIB3)$(P)tools" clobber && cd ..
	-$(RMDIR) $(LIB3)$(P)tools 2>$(NUL)
	cd cii && $(MK) "OUTPUT=$(LIB3)$(P)cii" clobber && cd ..
	-$(RMDIR) $(LIB3)$(P)cii 2>$(NUL)
	cd lua-2.5+nw && $(MK) $(LuaMakefile) "OUTPUT=$(LIB3)$(P)lua-2.5+nw" clobber && cd ..
	-$(RMDIR) $(LIB3)$(P)lua-2.5+nw 2>$(NUL)
	cd c && $(MK) "OUTPUT=$(LIB3)$(P)c" clean && cd ..
	cd lua && $(MK) "OUTPUT=$(LIB3)$(P)lua" clean && cd ..
	cd tex && $(MK) "OUTPUT=$(LIB3)$(P)tex" clean && cd ..
	-$(RM) *~ 2>$(NUL)

clobber: clean
	cd c && $(MK) "OUTPUT=$(LIB3)$(P)c" clobber && cd ..
	-$(RMDIR) $(LIB3)$(P)c 2>$(NUL)
	cd lua && $(MK) "OUTPUT=$(LIB3)$(P)lua" clobber && cd ..
	-$(RMDIR) $(LIB3)$(P)lua 2>$(NUL)
	cd tex && $(MK) "OUTPUT=$(LIB3)$(P)tex" clobber && cd ..
	-$(RMDIR) $(LIB3)$(P)tex 2>$(NUL)
	-$(RM) *.html 2>$(NUL)

