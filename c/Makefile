# Copyright 1991-1998 by Norman Ramsey.  All rights reserved.
# See file COPYRIGHT for more information.
#
# don't edit this file; edit ../nwconfig instead

include ../nwconfig

################################################################
# CII is directory where you installed CII ($BUILDDIR)

CII=../cii
LUA=../lua-2.5+nw

INCS=-I$(CII)$(P)include -I$(LUA)$(P)include

# after installation, make doc for literate version

# list of object files for each target

NOOBJS= $(OUTPUT)$(P)columns$(O) $(OUTPUT)$(P)cpif$(O) \
	$(OUTPUT)$(P)env-lua$(O) $(OUTPUT)$(P)errors$(O) \
	$(OUTPUT)$(P)finduses$(O) $(OUTPUT)$(P)fromascii$(O) \
	$(OUTPUT)$(P)getline$(O) \
	$(OUTPUT)$(P)ipipe$(O) $(OUTPUT)$(P)ipipe-lua$(O) \
	$(OUTPUT)$(P)lua-help$(O) $(OUTPUT)$(P)lua-main$(O) \
	$(OUTPUT)$(P)main$(O) $(OUTPUT)$(P)markparse$(O) $(OUTPUT)$(P)markup$(O) \
	$(OUTPUT)$(P)misc-lua$(O) $(OUTPUT)$(P)modtrees$(O) $(OUTPUT)$(P)modules$(O) \
	$(OUTPUT)$(P)mpipe$(O) $(OUTPUT)$(P)mpipe-lua$(O) \
	$(OUTPUT)$(P)notangle$(O) $(OUTPUT)$(P)noweb-lua$(O) $(OUTPUT)$(P)nwbuffer$(O) \
	$(OUTPUT)$(P)nwbuffer-lua$(O) $(OUTPUT)$(P)nwprocess$(O) $(OUTPUT)$(P)nwtime$(O) \
	$(OUTPUT)$(P)recognize$(O) \
	$(OUTPUT)$(P)stages$(O) $(OUTPUT)$(P)strsave$(O) $(OUTPUT)$(P)sys$(O) \
	$(OUTPUT)$(P)util$(O) \
	$(OUTPUT)$(P)xpipe$(O) $(OUTPUT)$(P)xpipe-lua$(O)

NWMTIMEOBJS=$(OUTPUT)$(P)columns$(O) \
	$(OUTPUT)$(P)errors$(O) \
	$(OUTPUT)$(P)getline$(O) \
	$(OUTPUT)$(P)nwmtime$(O)

FILES=	columns.nw cpif.nw \
	errors.nw \
	finduses.nw \
	getline.nw \
	ipipe.nw ipipe-lua.nw \
	lua-main.nw \
	main.nw markparse.nw markup.nw match.nw modtrees.nw modules.nw mpipe.nw mpipe-lua.nw \
	notangle.nw nwbuffer.nw nwbuffer-lua.nw nwmtime.nw nwprocess.nw nwtime.nw \
	recognize.nw \
	strsave.nw \
	xpipe.nw xpipe-lua.nw

# sources to build when distributing C code
#   (add all generated .c and .h files to this list)

SRCS=	$(OUTPUT)$(P)cargs.h $(OUTPUT)$(P)columns.c $(OUTPUT)$(P)columns.h $(OUTPUT)$(P)cpif.c \
	$(OUTPUT)$(P)cpif.h \
	$(OUTPUT)$(P)env-lua.c $(OUTPUT)$(P)env-lua.h $(OUTPUT)$(P)errors.c $(OUTPUT)$(P)errors.h \
	$(OUTPUT)$(P)finduses.c $(OUTPUT)$(P)fromascii.c $(OUTPUT)$(P)fromascii.h \
	$(OUTPUT)$(P)getline.c $(OUTPUT)$(P)getline.h \
	$(OUTPUT)$(P)ipipe-lua.c $(OUTPUT)$(P)ipipe-lua.h $(OUTPUT)$(P)ipipe.c $(OUTPUT)$(P)ipipe.h \
	$(OUTPUT)$(P)lua-help.c $(OUTPUT)$(P)lua-help.h $(OUTPUT)$(P)lua-main.c $(OUTPUT)$(P)lua-main.h \
	$(OUTPUT)$(P)main.c $(OUTPUT)$(P)markparse.c $(OUTPUT)$(P)markparse.h $(OUTPUT)$(P)markup.c \
	$(OUTPUT)$(P)markup.h $(OUTPUT)$(P)match.c $(OUTPUT)$(P)match.h $(OUTPUT)$(P)misc-lua.c \
	$(OUTPUT)$(P)misc-lua.h $(OUTPUT)$(P)modtrees.c $(OUTPUT)$(P)modtrees.h $(OUTPUT)$(P)modules.c \
	$(OUTPUT)$(P)modules.h $(OUTPUT)$(P)mpipe-lua.c $(OUTPUT)$(P)mpipe-lua.h $(OUTPUT)$(P)mpipe.c \
	$(OUTPUT)$(P)mpipe.h \
	$(OUTPUT)$(P)notangle.c	$(OUTPUT)$(P)notangle.h $(OUTPUT)$(P)noweb-lua.c $(OUTPUT)$(P)noweb-lua.h \
	$(OUTPUT)$(P)nwbuffer-lua.c $(OUTPUT)$(P)nwbuffer.c $(OUTPUT)$(P)nwbuffer.h \
	$(OUTPUT)$(P)nwmtime.c $(OUTPUT)$(P)nwprocess.c $(OUTPUT)$(P)nwprocess.h $(OUTPUT)$(P)nwtime.c \
	$(OUTPUT)$(P)nwtime.h \
	$(OUTPUT)$(P)precompiled.h \
	$(OUTPUT)$(P)recognize.c $(OUTPUT)$(P)recognize.h \
	$(OUTPUT)$(P)stages.c $(OUTPUT)$(P)stages.h $(OUTPUT)$(P)strsave.c $(OUTPUT)$(P)strsave.h \
	$(OUTPUT)$(P)sys.c $(OUTPUT)$(P)sys.h \
	$(OUTPUT)$(P)util.c $(OUTPUT)$(P)util.h \
	$(OUTPUT)$(P)xpipe-lua.c $(OUTPUT)$(P)xpipe-lua.h $(OUTPUT)$(P)xpipe.c $(OUTPUT)$(P)xpipe.h

NAME='name of RCS version'

# metarule so you don't need a new rule for each object file

.c$(O):;	$(CC) $(INCS) $(XCFLAGS) $(CFLAGS)$@ $*.c

all:	$(OUTPUT)$(P)no$(E) $(OUTPUT)$(P)nwmtime$(E)

doc:	$(OUTPUT)$(P)doc.tex $(OUTPUT)$(P)allcode.tex
	pdflatex -output-directory=$(OUTPUT) doc.tex
	pdflatex -output-directory=$(OUTPUT) doc.tex
	pdflatex -output-directory=$(OUTPUT) doc.tex

$(OUTPUT)$(P)nwmtime$(E):	$(NWMTIMEOBJS)
	$(LD) $(LFLAGS)$@ $(NWMTIMEOBJS)

$(OUTPUT)$(P)no$(E):	$(NOOBJS) $(LIB3)$(P)cii$(P)memchk$(O) $(LIB3)$(P)cii$(P)libcii$(A) $(LIB3)$(P)lua-2.5+nw$(P)liblua$(A) $(LIB3)$(P)lua-2.5+nw$(P)liblualib$(A)
	$(LD) $(LFLAGS)$@ $(NOOBJS) $(LIBPROLOG) $(LIB3)$(P)cii$(P)libcii$(A) $(LIB3)$(P)lua-2.5+nw$(P)liblua$(A) $(LIB3)$(P)lua-2.5+nw$(P)liblualib$(A) $(LIBEPILOG)

touch: $(SRCS)
	touch $(SRCS)

clean:
	-$(RM) $(NOOBJS)
	-$(RM) $(NWMTIMEOBJS)
	-$(RM) $(SRCS)
	-$(RM) $(OUTPUT)$(P)nwbuffer-lua.0
	-$(RM) $(OUTPUT)$(P)allcode.tex
	-$(RM) $(OUTPUT)$(P)doc.aux
	-$(RM) $(OUTPUT)$(P)doc.log
	-$(RM) $(OUTPUT)$(P)doc.out
	-$(RM) $(OUTPUT)$(P)doc.pdf
	-$(RM) $(OUTPUT)$(P)doc.tex
	-$(RM) $(OUTPUT)$(P)doc.toc

clobber:	clean
	-$(RM) $(OUTPUT)$(P)nwmtime$(E) $(OUTPUT)$(P)no$(E)
	-$(RM) $(OUTPUT)$(P)doc.pdf

checkin:	$(FILES) doc.nw
		ci $(CINAME) $(CIMSG) -l $(FILES) doc.nw

$(OUTPUT)$(P)doc.tex:	doc.nw
	$(CP) doc.nw $@

$(OUTPUT)$(P)allcode.tex:	$(FILES)
	$(OUTPUT)$(P)no weave -ifilter "Stages.elide, 'hackers:*'" -n -index $(FILES) > $@

################################################################

$(OUTPUT)$(P)cargs.h:		cargs.nw;	$(NOTANGLE) cargs.nw		$(TANGLEOPTS) -L"#line %L "\"cargs.nw"\"%N"		-Rheader $(CPIF) $@
$(OUTPUT)$(P)columns.h:		columns.nw;	$(NOTANGLE) columns.nw		$(TANGLEOPTS) -L"#line %L "\"columns.nw"\"%N"		-Rheader $(CPIF) $@
$(OUTPUT)$(P)cpif.h:		cpif.nw;	$(NOTANGLE) cpif.nw		$(TANGLEOPTS) -L"#line %L "\"cpif.nw"\"%N"		-Rheader $(CPIF) $@
$(OUTPUT)$(P)env-lua.h:		env-lua.nw;	$(NOTANGLE) env-lua.nw		$(TANGLEOPTS) -L"#line %L "\"env-lua.nw"\"%N"		-Rheader $(CPIF) $@
$(OUTPUT)$(P)errors.h:		errors.nw;	$(NOTANGLE) errors.nw		$(TANGLEOPTS) -L"#line %L "\"errors.nw"\"%N"		-Rheader $(CPIF) $@
$(OUTPUT)$(P)fromascii.h:	fromascii.nw;	$(NOTANGLE) fromascii.nw	$(TANGLEOPTS) -L"#line %L "\"fromascii.nw"\"%N"		-Rheader $(CPIF) $@
$(OUTPUT)$(P)getline.h:		getline.nw;	$(NOTANGLE) getline.nw		$(TANGLEOPTS) -L"#line %L "\"getline.nw"\"%N"		-Rheader $(CPIF) $@
$(OUTPUT)$(P)ipipe.h:		ipipe.nw;	$(NOTANGLE) ipipe.nw		$(TANGLEOPTS) -L"#line %L "\"ipipe.nw"\"%N"		-Rheader $(CPIF) $@
$(OUTPUT)$(P)ipipe-lua.h:	ipipe-lua.nw;	$(NOTANGLE) ipipe-lua.nw	$(TANGLEOPTS) -L"#line %L "\"ipipe-lua.nw"\"%N"		-Rheader $(CPIF) $@
$(OUTPUT)$(P)lua-help.h:	lua-help.nw;	$(NOTANGLE) lua-help.nw		$(TANGLEOPTS) -L"#line %L "\"lua-help.nw"\"%N"		-Rheader $(CPIF) $@
$(OUTPUT)$(P)lua-main.h:	lua-main.nw;	$(NOTANGLE) lua-main.nw		$(TANGLEOPTS) -L"#line %L "\"lua-main.nw"\"%N"		-Rheader $(CPIF) $@
$(OUTPUT)$(P)markparse.h:	markparse.nw;	$(NOTANGLE) markparse.nw	$(TANGLEOPTS) -L"#line %L "\"markparse.nw"\"%N"		-Rheader $(CPIF) $@
$(OUTPUT)$(P)markup.h:		markup.nw;	$(NOTANGLE) markup.nw		$(TANGLEOPTS) -L"#line %L "\"markup.nw"\"%N"		-Rheader $(CPIF) $@
$(OUTPUT)$(P)match.h:		match.nw;	$(NOTANGLE) match.nw		$(TANGLEOPTS) -L"#line %L "\"match.nw"\"%N"		-Rheader $(CPIF) $@
$(OUTPUT)$(P)misc-lua.h:	misc-lua.nw;	$(NOTANGLE) misc-lua.nw		$(TANGLEOPTS) -L"#line %L "\"misc-lua.nw"\"%N"		-Rheader $(CPIF) $@
$(OUTPUT)$(P)modtrees.h:	modtrees.nw;	$(NOTANGLE) modtrees.nw		$(TANGLEOPTS) -L"#line %L "\"modtrees.nw"\"%N"		-Rheader $(CPIF) $@
$(OUTPUT)$(P)modules.h:		modules.nw;	$(NOTANGLE) modules.nw		$(TANGLEOPTS) -L"#line %L "\"modules.nw"\"%N"		-Rheader $(CPIF) $@
$(OUTPUT)$(P)mpipe.h:		mpipe.nw;	$(NOTANGLE) mpipe.nw		$(TANGLEOPTS) -L"#line %L "\"mpipe.nw"\"%N"		-Rheader $(CPIF) $@
$(OUTPUT)$(P)mpipe-lua.h:	mpipe-lua.nw;	$(NOTANGLE) mpipe-lua.nw	$(TANGLEOPTS) -L"#line %L "\"mpipe-lua.nw"\"%N"		-Rheader $(CPIF) $@
$(OUTPUT)$(P)notangle.h:	notangle.nw;	$(NOTANGLE) notangle.nw		$(TANGLEOPTS) -L"#line %L "\"notangle.nw"\"%N"		-Rheader $(CPIF) $@
$(OUTPUT)$(P)noweb-lua.h:	noweb-lua.nw;	$(NOTANGLE) noweb-lua.nw	$(TANGLEOPTS) -L"#line %L "\"noweb-lua.nw"\"%N"		-Rheader $(CPIF) $@
$(OUTPUT)$(P)nwbuffer.h:	nwbuffer.nw;	$(NOTANGLE) nwbuffer.nw		$(TANGLEOPTS) -L"#line %L "\"nwbuffer.nw"\"%N"		-Rheader $(CPIF) $@
$(OUTPUT)$(P)nwprocess.h:	nwprocess.nw;	$(NOTANGLE) nwprocess.nw	$(TANGLEOPTS) -L"#line %L "\"nwprocess.nw"\"%N"		-Rheader $(CPIF) $@
$(OUTPUT)$(P)nwtime.h:		nwtime.nw;	$(NOTANGLE) nwtime.nw		$(TANGLEOPTS) -L"#line %L "\"nwtime.nw"\"%N"		-Rheader $(CPIF) $@
$(OUTPUT)$(P)precompiled.h:	precompiled.nw;	$(NOTANGLE) precompiled.nw	$(TANGLEOPTS) -L"#line %L "\"precompiled.nw"\"%N"	-Rheader $(CPIF) $@
$(OUTPUT)$(P)recognize.h:	recognize.nw;	$(NOTANGLE) recognize.nw	$(TANGLEOPTS) -L"#line %L "\"recognize.nw"\"%N"		-Rheader $(CPIF) $@
$(OUTPUT)$(P)stages.h:		stages.nw;	$(NOTANGLE) stages.nw		$(TANGLEOPTS) -L"#line %L "\"stages.nw"\"%N"		-Rheader $(CPIF) $@
$(OUTPUT)$(P)strsave.h:		strsave.nw;	$(NOTANGLE) strsave.nw		$(TANGLEOPTS) -L"#line %L "\"strsave.nw"\"%N"		-Rheader $(CPIF) $@
$(OUTPUT)$(P)sys.h:		sys.nw;		$(NOTANGLE) sys.nw		$(TANGLEOPTS) -L"#line %L "\"sys.nw"\"%N"		-Rheader $(CPIF) $@
$(OUTPUT)$(P)util.h:		util.nw;	$(NOTANGLE) util.nw		$(TANGLEOPTS) -L"#line %L "\"util.nw"\"%N"		-Rheader $(CPIF) $@
$(OUTPUT)$(P)xpipe.h:		xpipe.nw;	$(NOTANGLE) xpipe.nw		$(TANGLEOPTS) -L"#line %L "\"xpipe.nw"\"%N"		-Rheader $(CPIF) $@
$(OUTPUT)$(P)xpipe-lua.h:	xpipe-lua.nw;	$(NOTANGLE) xpipe-lua.nw	$(TANGLEOPTS) -L"#line %L "\"xpipe-lua.nw"\"%N"		-Rheader $(CPIF) $@

################################################################

$(OUTPUT)$(P)columns.c:		columns.nw;	$(NOTANGLE) columns.nw		$(TANGLEOPTS) -L"#line %L "\"columns.nw"\"%N"	$(CPIF) $@
$(OUTPUT)$(P)cpif.c:		cpif.nw;	$(NOTANGLE) cpif.nw		$(TANGLEOPTS) -L"#line %L "\"cpif.nw"\"%N"	$(CPIF) $@
$(OUTPUT)$(P)errors.c:		errors.nw;	$(NOTANGLE) errors.nw		$(TANGLEOPTS) -L"#line %L "\"errors.nw"\"%N"	$(CPIF) $@
$(OUTPUT)$(P)env-lua.c:		env-lua.nw;	$(NOTANGLE) env-lua.nw		$(TANGLEOPTS) -L"#line %L "\"env-lua.nw"\"%N"	$(CPIF) $@
$(OUTPUT)$(P)finduses.c:	finduses.nw;	$(NOTANGLE) finduses.nw		$(TANGLEOPTS) -L"#line %L "\"finduses.nw"\"%N"	$(CPIF) $@
$(OUTPUT)$(P)fromascii.c:	fromascii.nw;	$(NOTANGLE) fromascii.nw	$(TANGLEOPTS) -L"#line %L "\"fromascii.nw"\"%N"	$(CPIF) $@
$(OUTPUT)$(P)getline.c:		getline.nw;	$(NOTANGLE) getline.nw		$(TANGLEOPTS) -L"#line %L "\"getline.nw"\"%N"	$(CPIF) $@
$(OUTPUT)$(P)ipipe.c:		ipipe.nw;	$(NOTANGLE) ipipe.nw		$(TANGLEOPTS) -L"#line %L "\"ipipe.nw"\"%N"	$(CPIF) $@
$(OUTPUT)$(P)ipipe-lua.c:	ipipe-lua.nw;	$(NOTANGLE) ipipe-lua.nw	$(TANGLEOPTS) -L"#line %L "\"ipipe-lua.nw"\"%N"	$(CPIF) $@
$(OUTPUT)$(P)lua-help.c:	lua-help.nw;	$(NOTANGLE) lua-help.nw		$(TANGLEOPTS) -L"#line %L "\"lua-help.nw"\"%N"	$(CPIF) $@
$(OUTPUT)$(P)lua-main.c:	lua-main.nw;	$(NOTANGLE) lua-main.nw		$(TANGLEOPTS) -L"#line %L "\"lua-main.nw"\"%N"	$(CPIF) $@
$(OUTPUT)$(P)main.c:		main.nw;	$(NOTANGLE) main.nw		$(TANGLEOPTS) -L"#line %L "\"main.nw"\"%N"	$(CPIF) $@
$(OUTPUT)$(P)markup.c:		markup.nw;	$(NOTANGLE) markup.nw		$(TANGLEOPTS) -L"#line %L "\"markup.nw"\"%N"	$(CPIF) $@
$(OUTPUT)$(P)markparse.c:	markparse.nw;	$(NOTANGLE) markparse.nw	$(TANGLEOPTS) -L"#line %L "\"markparse.nw"\"%N"	$(CPIF) $@
$(OUTPUT)$(P)misc-lua.c:	misc-lua.nw;	$(NOTANGLE) misc-lua.nw		$(TANGLEOPTS) -L"#line %L "\"misc-lua.nw"\"%N"	$(CPIF) $@
$(OUTPUT)$(P)modtrees.c:	modtrees.nw;	$(NOTANGLE) modtrees.nw		$(TANGLEOPTS) -L"#line %L "\"modtrees.nw"\"%N"	$(CPIF) $@
$(OUTPUT)$(P)modules.c:		modules.nw;	$(NOTANGLE) modules.nw		$(TANGLEOPTS) -L"#line %L "\"modules.nw"\"%N"	$(CPIF) $@
$(OUTPUT)$(P)mpipe.c:		mpipe.nw;	$(NOTANGLE) mpipe.nw		$(TANGLEOPTS) -L"#line %L "\"mpipe.nw"\"%N"	$(CPIF) $@
$(OUTPUT)$(P)mpipe-lua.c:	mpipe-lua.nw;	$(NOTANGLE) mpipe-lua.nw	$(TANGLEOPTS) -L"#line %L "\"mpipe-lua.nw"\"%N"	$(CPIF) $@
$(OUTPUT)$(P)notangle.c:	notangle.nw;	$(NOTANGLE) notangle.nw		$(TANGLEOPTS) -L"#line %L "\"notangle.nw"\"%N"	$(CPIF) $@
$(OUTPUT)$(P)noweb-lua.c:	noweb-lua.nw;	$(NOTANGLE) noweb-lua.nw	$(TANGLEOPTS) -L"#line %L "\"noweb-lua.nw"\"%N"	$(CPIF) $@
$(OUTPUT)$(P)nwbuffer.c:	nwbuffer.nw;	$(NOTANGLE) nwbuffer.nw		$(TANGLEOPTS) -L"#line %L "\"nwbuffer.nw"\"%N"	$(CPIF) $@
$(OUTPUT)$(P)nwbuffer-lua.0:	nwbuffer-lua.nw
	$(NOTANGLE) nwbuffer-lua.nw $(TANGLEOPTS) -R"key macros header" >$(OUTPUT)$(P)nwbuffer-lua.0
$(OUTPUT)$(P)nwbuffer-lua.1:	nwbuffer.nw
	$(NOTANGLE) nwbuffer.nw $(TANGLEOPTS) -R"key macros" >$(OUTPUT)$(P)nwbuffer-lua.1
$(OUTPUT)$(P)nwbuffer-lua.2:	nwbuffer-lua.nw
	$(NOTANGLE) nwbuffer-lua.nw $(TANGLEOPTS) -R"key macros footer" >$(OUTPUT)$(P)nwbuffer-lua.2
$(OUTPUT)$(P)nwbuffer-lua.3:	$(OUTPUT)$(P)nwbuffer-lua.0 $(OUTPUT)$(P)nwbuffer-lua.1 $(OUTPUT)$(P)nwbuffer-lua.2
	more $(OUTPUT)$(P)nwbuffer-lua.0 | $(TOOLS)$(P)tie $(OUTPUT)$(P)nwbuffer-lua.1 $(OUTPUT)$(P)nwbuffer-lua.2 nwbuffer-lua.nw >$(OUTPUT)$(P)nwbuffer-lua.3
$(OUTPUT)$(P)nwbuffer-lua.c: $(OUTPUT)$(P)nwbuffer-lua.3
	$(NOTANGLE) $(OUTPUT)$(P)nwbuffer-lua.3 $(TANGLEOPTS) $(CPIF) $@
$(OUTPUT)$(P)nwprocess.c:	nwprocess.nw;	$(NOTANGLE) nwprocess.nw	$(TANGLEOPTS) -L"#line %L "\"nwprocess.nw"\"%N"	$(CPIF) $@
$(OUTPUT)$(P)nwmtime.c:		nwmtime.nw;	$(NOTANGLE) nwmtime.nw		$(TANGLEOPTS) -L"#line %L "\"nwmtime.nw"\"%N"	$(CPIF) $@
$(OUTPUT)$(P)nwtime.c:		nwtime.nw;	$(NOTANGLE) nwtime.nw		$(TANGLEOPTS) -L"#line %L "\"nwtime.nw"\"%N"	$(CPIF) $@
$(OUTPUT)$(P)recognize.c:	recognize.nw;	$(NOTANGLE) recognize.nw	$(TANGLEOPTS) -L"#line %L "\"recognize.nw"\"%N"	$(CPIF) $@
$(OUTPUT)$(P)stages.c:		stages.nw;	$(NOTANGLE) stages.nw		$(TANGLEOPTS) -L"#line %L "\"stages.nw"\"%N"	$(CPIF) $@
$(OUTPUT)$(P)strsave.c:		strsave.nw;	$(NOTANGLE) strsave.nw		$(TANGLEOPTS) -L"#line %L "\"strsave.nw"\"%N"	$(CPIF) $@
$(OUTPUT)$(P)sys.c:		sys.nw;		$(NOTANGLE) sys.nw		$(TANGLEOPTS) -L"#line %L "\"sys.nw"\"%N"	$(CPIF) $@
$(OUTPUT)$(P)util.c:		util.nw;	$(NOTANGLE) util.nw		$(TANGLEOPTS) -L"#line %L "\"util.nw"\"%N"	$(CPIF) $@
$(OUTPUT)$(P)xpipe.c:		xpipe.nw;	$(NOTANGLE) xpipe.nw		$(TANGLEOPTS) -L"#line %L "\"xpipe.nw"\"%N"	$(CPIF) $@
$(OUTPUT)$(P)xpipe-lua.c:	xpipe-lua.nw;	$(NOTANGLE) xpipe-lua.nw	$(TANGLEOPTS) -L"#line %L "\"xpipe-lua.nw"\"%N"	$(CPIF) $@

################################################################

$(OUTPUT)$(P)columns$(O): $(OUTPUT)$(P)cargs.h $(OUTPUT)$(P)columns.c $(OUTPUT)$(P)columns.h
	echo columns.obj start
	$(CC) $(INCS) $(XCFLAGS) $(CFLAGS)$@ $*.c
	echo columns.obj end
$(OUTPUT)$(P)cpif$(O): $(OUTPUT)$(P)cpif.c $(OUTPUT)$(P)cpif.h $(OUTPUT)$(P)errors.h $(OUTPUT)$(P)strsave.h
$(OUTPUT)$(P)env-lua$(O): $(OUTPUT)$(P)env-lua.c $(OUTPUT)$(P)env-lua.h $(OUTPUT)$(P)lua-help.h
$(OUTPUT)$(P)errors$(O): $(OUTPUT)$(P)errors.c $(OUTPUT)$(P)errors.h
$(OUTPUT)$(P)finduses$(O): $(OUTPUT)$(P)errors.h $(OUTPUT)$(P)finduses.c $(OUTPUT)$(P)getline.h $(OUTPUT)$(P)match.h $(OUTPUT)$(P)nwbuffer.h $(OUTPUT)$(P)recognize.h
$(OUTPUT)$(P)fromascii$(O): $(OUTPUT)$(P)errors.h $(OUTPUT)$(P)fromascii.c $(OUTPUT)$(P)fromascii.h $(OUTPUT)$(P)getline.h $(OUTPUT)$(P)nwbuffer.h
$(OUTPUT)$(P)getline$(O): $(OUTPUT)$(P)columns.h $(OUTPUT)$(P)errors.h $(OUTPUT)$(P)getline.c $(OUTPUT)$(P)getline.h
$(OUTPUT)$(P)ipipe$(O): $(OUTPUT)$(P)ipipe.c $(OUTPUT)$(P)ipipe.h $(OUTPUT)$(P)nwbuffer.h $(OUTPUT)$(P)nwtime.h
$(OUTPUT)$(P)ipipe-lua$(O): $(OUTPUT)$(P)ipipe-lua.c $(OUTPUT)$(P)ipipe-lua.h
$(OUTPUT)$(P)lua-help$(O): $(OUTPUT)$(P)lua-help.c $(OUTPUT)$(P)lua-help.h
$(OUTPUT)$(P)lua-main$(O): $(OUTPUT)$(P)env-lua.h $(OUTPUT)$(P)ipipe-lua.h $(OUTPUT)$(P)lua-main.c $(OUTPUT)$(P)lua-main.h $(OUTPUT)$(P)misc-lua.h $(OUTPUT)$(P)mpipe-lua.h $(OUTPUT)$(P)noweb-lua.h $(OUTPUT)$(P)stages.h $(OUTPUT)$(P)util.h $(OUTPUT)$(P)xpipe-lua.h
$(OUTPUT)$(P)main$(O): $(OUTPUT)$(P)cargs.h $(OUTPUT)$(P)columns.h $(OUTPUT)$(P)cpif.h $(OUTPUT)$(P)errors.h $(OUTPUT)$(P)main.c $(OUTPUT)$(P)modtrees.h $(OUTPUT)$(P)modules.h $(OUTPUT)$(P)notangle.h $(OUTPUT)$(P)nwbuffer.h
$(OUTPUT)$(P)markparse$(O): $(OUTPUT)$(P)columns.h $(OUTPUT)$(P)errors.h $(OUTPUT)$(P)getline.h $(OUTPUT)$(P)markparse.c $(OUTPUT)$(P)markparse.h $(OUTPUT)$(P)markup.h $(OUTPUT)$(P)nwbuffer.h
$(OUTPUT)$(P)markup$(O): $(OUTPUT)$(P)errors.h $(OUTPUT)$(P)markup.c $(OUTPUT)$(P)markup.h $(OUTPUT)$(P)strsave.h
$(OUTPUT)$(P)misc-lua$(O): $(OUTPUT)$(P)lua-help.h $(OUTPUT)$(P)misc-lua.c $(OUTPUT)$(P)misc-lua.h
$(OUTPUT)$(P)modtrees$(O): $(OUTPUT)$(P)errors.h $(OUTPUT)$(P)modtrees.c $(OUTPUT)$(P)modtrees.h $(OUTPUT)$(P)modules.h $(OUTPUT)$(P)strsave.h
$(OUTPUT)$(P)modules$(O): $(OUTPUT)$(P)columns.h $(OUTPUT)$(P)errors.h $(OUTPUT)$(P)modtrees.h $(OUTPUT)$(P)modules.c $(OUTPUT)$(P)modules.h $(OUTPUT)$(P)strsave.h
$(OUTPUT)$(P)mpipe$(O): $(OUTPUT)$(P)fromascii.h $(OUTPUT)$(P)ipipe.h $(OUTPUT)$(P)mpipe.c $(OUTPUT)$(P)mpipe.h $(OUTPUT)$(P)nwbuffer.h $(OUTPUT)$(P)xpipe.h
$(OUTPUT)$(P)mpipe-lua$(O): $(OUTPUT)$(P)lua-help.h $(OUTPUT)$(P)mpipe.h $(OUTPUT)$(P)mpipe-lua.c $(OUTPUT)$(P)mpipe-lua.h
$(OUTPUT)$(P)notangle$(O): $(OUTPUT)$(P)errors.h $(OUTPUT)$(P)getline.h $(OUTPUT)$(P)match.h $(OUTPUT)$(P)modtrees.h $(OUTPUT)$(P)modules.h $(OUTPUT)$(P)notangle.c $(OUTPUT)$(P)notangle.h $(OUTPUT)$(P)nwbuffer.h $(OUTPUT)$(P)strsave.h
$(OUTPUT)$(P)noweb-lua$(O): $(OUTPUT)$(P)lua-help.h $(OUTPUT)$(P)noweb-lua.c $(OUTPUT)$(P)noweb-lua.h $(OUTPUT)$(P)util.h
$(OUTPUT)$(P)nwbuffer$(O): $(OUTPUT)$(P)nwbuffer.c $(OUTPUT)$(P)nwbuffer.h
$(OUTPUT)$(P)nwbuffer-lua$(O): $(OUTPUT)$(P)lua-help.h $(OUTPUT)$(P)nwbuffer.h $(OUTPUT)$(P)nwbuffer-lua.c
$(OUTPUT)$(P)nwmtime$(O): $(OUTPUT)$(P)getline.h $(OUTPUT)$(P)nwmtime.c
$(OUTPUT)$(P)nwprocess$(O): $(OUTPUT)$(P)nwprocess.c $(OUTPUT)$(P)nwprocess.h
$(OUTPUT)$(P)nwtime$(O): $(OUTPUT)$(P)nwtime.c $(OUTPUT)$(P)nwtime.h
$(OUTPUT)$(P)recognize$(O): $(OUTPUT)$(P)recognize.c
$(OUTPUT)$(P)stages$(O): $(OUTPUT)$(P)cargs.h $(OUTPUT)$(P)fromascii.h $(OUTPUT)$(P)lua-help.h $(OUTPUT)$(P)markparse.h $(OUTPUT)$(P)notangle.h $(OUTPUT)$(P)nwbuffer.h $(OUTPUT)$(P)stages.c $(OUTPUT)$(P)stages.h
$(OUTPUT)$(P)strsave$(O): $(OUTPUT)$(P)errors.h $(OUTPUT)$(P)strsave.c $(OUTPUT)$(P)strsave.h
$(OUTPUT)$(P)sys$(O): $(OUTPUT)$(P)sys.c $(OUTPUT)$(P)sys.h
$(OUTPUT)$(P)util$(O): $(OUTPUT)$(P)precompiled.h $(OUTPUT)$(P)sys.h $(OUTPUT)$(P)util.c $(OUTPUT)$(P)util.h
$(OUTPUT)$(P)xpipe$(O): $(OUTPUT)$(P)errors.h $(OUTPUT)$(P)nwprocess.h $(OUTPUT)$(P)sys.h $(OUTPUT)$(P)util.h $(OUTPUT)$(P)xpipe.c $(OUTPUT)$(P)xpipe.h
$(OUTPUT)$(P)xpipe-lua$(O): $(OUTPUT)$(P)cargs.h $(OUTPUT)$(P)lua-help.h $(OUTPUT)$(P)xpipe.h $(OUTPUT)$(P)xpipe-lua.c $(OUTPUT)$(P)xpipe-lua.h
