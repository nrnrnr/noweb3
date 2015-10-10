# Copyright 1995-1998 by Norman Ramsey.  All rights reserved.
# See file COPYRIGHT for more information.
#
# Edit nwconfig before running

include nwconfig

# Stop editing.  No user-serviceable parts below.

all: code scripts styles

bootstrap:
	-mkdir $(LIB3)$(P)tools 2>$(NUL)
	cd tools && $(MK) "OUTPUT=$(LIB3)$(P)tools" && cd ..

ciilib:
	-mkdir $(LIB3)$(P)cii 2>$(NUL)
	cd cii && $(MK) "OUTPUT=$(LIB3)$(P)cii" && cd ..

lualib:
	-mkdir $(LIB3)$(P)lua-2.5 2>$(NUL)
	cd lua-2.5 && $(MK) $(LuaMakefile) "OUTPUT=$(LIB3)$(P)lua-2.5" && cd .. && $(LuaCpCommand2)

code: bootstrap ciilib lualib
	-mkdir $(LIB3)$(P)c 2>$(NUL)
	cd c && $(MK) "NOTANGLE=more" "TANGLEOPTS= | $(NOCOND) $(PIPE) | $(LIB3)$(P)tools$(P)markup | $(LIB3)$(P)tools$(P)nt" "CPIF=>" "TOOLS=$(LIB3)$(P)tools" "LUA=..$(P)lua-2.5" "LUALIB=$(LIB3)$(P)lua-2.5" "OUTPUT=$(LIB3)$(P)c" && cd ..

scripts: bootstrap
	-mkdir $(LIB3)$(P)lua 2>$(NUL)
	cd lua && $(MK) "NOTANGLE=more" "TANGLEOPTS= | $(LIB3)$(P)tools$(P)markup | $(LIB3)$(P)tools$(P)nt" "CPIF=>" "OUTPUT=$(LIB3)$(P)lua" && cd ..

styles: bootstrap
	-mkdir $(LIB3)$(P)tex 2>$(NUL)
	cd tex && $(MK) "NOTANGLE=more" "TANGLEOPTS= | $(LIB3)$(P)tools$(P)markup | $(LIB3)$(P)tools$(P)nt" "CPIF=>" "OUTPUT=$(LIB3)$(P)tex" && cd ..


careful:
	$(MK) clobber
	$(MK) all clean
	-$(RMDIR) $(LIB3)$(P)first 2>$(NUL)
	mkdir $(LIB3)$(P)first
	mkdir $(LIB3)$(P)first$(P)c
	$(CPR) $(LIB3)$(P)c$(P)* $(LIB3)$(P)first$(P)c
	mkdir $(LIB3)$(P)first$(P)lua
	$(CPR) $(LIB3)$(P)lua$(P)* $(LIB3)$(P)first$(P)lua
	mkdir $(LIB3)$(P)first$(P)tex
	$(CPR) $(LIB3)$(P)tex$(P)* $(LIB3)$(P)first$(P)tex
	$(MK) clobber
	$(MK) bootstrap
	$(MK) ciilib
	$(MK) lualib
	-mkdir $(LIB3)$(P)c 2>$(NUL)
	cd c && $(MK) "NWPATH=$(LIB3)$(P)first$(P)lua" "NOTANGLE=more" "TANGLEOPTS= | $(NOCOND) $(PIPE) | $(LIB3)$(P)first$(P)c$(P)no tangle" "CPIF=>" "TOOLS=$(LIB3)$(P)tools" "LUA=..$(P)lua-2.5" "LUALIB=$(LIB3)$(P)lua-2.5" "OUTPUT=$(LIB3)$(P)c" && cd ..
	-mkdir $(LIB3)$(P)lua 2>$(NUL)
	cd lua && $(MK) "NWPATH=$(LIB3)$(P)first$(P)lua" "NOTANGLE=$(LIB3)$(P)first$(P)c$(P)no tangle" "TANGLEOPTS=" "CPIF=>" "OUTPUT=$(LIB3)$(P)lua" && cd ..
	-mkdir $(LIB3)$(P)tex 2>$(NUL)
	cd tex && $(MK) "NWPATH=$(LIB3)$(P)first$(P)lua" "NOTANGLE=$(LIB3)$(P)first$(P)c$(P)no tangle" "TANGLEOPTS=" "CPIF=>" "OUTPUT=$(LIB3)$(P)tex" && cd ..
	echo At this point we are attempting to build the literate version.
	echo It may fail if you have not previously installed noweb.sty.
	cd c && $(MK) "NWPATH=$(LIB3)$(P)first$(P)lua" "OUTPUT=$(LIB3)$(P)c" doc && cd ..
	-$(RMDIR) $(LIB3)$(P)first
	$(MK) all clean

pdf: install
	-mkdir $(LIB3)$(P)c 2>$(NUL)
	cd c && $(MK) "OUTPUT=$(LIB3)$(P)c" doc && cd ..

everything: all todo.html

install: install-code install-scripts install-styles

install-code: code
	$(CP) $(LIB3)$(P)c$(P)no$(E) $(BINDIR)
	$(CP) $(LIB3)$(P)c$(P)nwmtime$(E) $(BINDIR)

install-scripts: scripts
	$(CP) $(LIB3)$(P)lua$(P)* $(BINDIR)

install-styles: styles
	$(CP) $(LIB3)$(P)tex$(P)noweb.sty $(TEXINPUTS)$(P)latex$(P)misc$(P)noweb.sty
	$(CP) $(LIB3)$(P)tex$(P)nwmac.tex $(TEXINPUTS)$(P)generic$(P)misc$(P)nwmac.tex

$(LIB3)$(P)todo.html: bootstrap todo.nw
	no weave -html todo.nw | $(LIB3)$(P)tools$(P)l2htodo > $(LIB3)$(P)todo.html

# Not configurable by nwconfig because this is an author only command.
www: $(LIB3)$(P)todo.html
	$(CP) $(LIB3)$(P)todo.html /home/cellar/nr/www/noweb/todo3.html

clean:
	cd tools && $(MK) "OUTPUT=$(LIB3)$(P)tools" clobber && cd ..
	-$(RMDIR) $(LIB3)$(P)tools 2>$(NUL)
	cd cii && $(MK) "OUTPUT=$(LIB3)$(P)cii" clobber && cd ..
	-$(RMDIR) $(LIB3)$(P)cii 2>$(NUL)
	cd lua-2.5 && $(MK) $(LuaMakefile) "OUTPUT=$(LIB3)$(P)lua-2.5" clobber && cd ..
	-$(RMDIR) $(LIB3)$(P)lua-2.5 2>$(NUL)
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
