include ../nwconfig

CONFIG=	$(OUTPUT)$(P)pipes.cfg \
	$(OUTPUT)$(P)sys.cfg \
	$(OUTPUT)$(P)noweb.cfg \
	$(OUTPUT)$(P)util.cfg \
	$(OUTPUT)$(P)list.nws \
	$(OUTPUT)$(P)set.nws

FILTERS=	$(OUTPUT)$(P)cat.nws \
		$(OUTPUT)$(P)stripconds.nws \
		$(OUTPUT)$(P)xchunks.nws \
		$(OUTPUT)$(P)lines.nws

STAGES=	$(OUTPUT)$(P)totex.nws \
	$(OUTPUT)$(P)tohtml.nws \
	$(OUTPUT)$(P)noidx.nws \
	$(OUTPUT)$(P)elide.nws \
	$(OUTPUT)$(P)unmarkup.nws \
	$(FILTERS)

SCRIPTS=	$(OUTPUT)$(P)tangle \
		$(OUTPUT)$(P)weave

all: $(CONFIG) $(STAGES) $(SCRIPTS)

test: $(CONFIG) $(STAGES) $(SCRIPTS)
	@echo 'write("Scripts load from .\n")' | NWPATH=. no
	@echo 'argv = {"-internaldefaults", "-n", "-html", "/dev/null"}; do_nwfile("weave.nws"); write("Null weave OK.\n")' | NWPATH=. no
	@echo 'argv = {"-internal", "test.nw"}; do_nwfile("tangle.nws"); write("Null tangle OK.\n")' | NWPATH=. no

htmltest: $(CONFIG) $(STAGES) $(SCRIPTS)
	@echo 'testfile("/home/nr/www/noweb/index.html")' | NWPATH=. no

clean:

clobber: clean
	-$(RM) $(CONFIG) $(FILTERS) $(STAGES) $(SCRIPTS) 2>$(NUL)

install: $(SCRIPTS) $(CONFIG) $(STAGES)
	for i in $(CONFIG) $(STAGES); do sed 's@|LIBDIR|@$(LIB2)@g' $$i > $(LIB3)/$$i; done
	for i in $(SCRIPTS); do cp $$i $(LIB3)/`basename $$i .nws`; done

$(OUTPUT)$(P)pipes.cfg:		config.nw;	$(NOTANGLE) config.nw		$(TANGLEOPTS) -Rpipes.cfg	$(CPIF) $@
$(OUTPUT)$(P)sys.cfg:		config.nw;	$(NOTANGLE) config.nw		$(TANGLEOPTS) -Rsys.cfg		$(CPIF) $@
$(OUTPUT)$(P)noweb.cfg:		config.nw;	$(NOTANGLE) config.nw		$(TANGLEOPTS) -Rnoweb.cfg	$(CPIF) $@
$(OUTPUT)$(P)util.cfg:		config.nw;	$(NOTANGLE) config.nw		$(TANGLEOPTS) -Rutil.cfg	$(CPIF) $@
$(OUTPUT)$(P)list.nws:		list.nw;	$(NOTANGLE) list.nw		$(TANGLEOPTS) $(CPIF) $@
$(OUTPUT)$(P)set.nws:		set.nw;		$(NOTANGLE) set.nw		$(TANGLEOPTS) $(CPIF) $@
$(OUTPUT)$(P)totex.nws:		totex.nw;	$(NOTANGLE) totex.nw		$(TANGLEOPTS) $(CPIF) $@
$(OUTPUT)$(P)tohtml.nws:	tohtml.nw;	$(NOTANGLE) tohtml.nw		$(TANGLEOPTS) $(CPIF) $@
$(OUTPUT)$(P)noidx.nws:		noidx.nw;	$(NOTANGLE) noidx.nw		$(TANGLEOPTS) $(CPIF) $@
$(OUTPUT)$(P)elide.nws:		elide.nw;	$(NOTANGLE) elide.nw		$(TANGLEOPTS) $(CPIF) $@
$(OUTPUT)$(P)unmarkup.nws:	unmarkup.nw;	$(NOTANGLE) unmarkup.nw		$(TANGLEOPTS) $(CPIF) $@
$(OUTPUT)$(P)cat.nws:		cat.nw;		$(NOTANGLE) cat.nw		$(TANGLEOPTS) $(CPIF) $@
$(OUTPUT)$(P)stripconds.nws:	stripconds.nw;	$(NOTANGLE) stripconds.nw	$(TANGLEOPTS) $(CPIF) $@
$(OUTPUT)$(P)xchunks.nws:	xchunks.nw;	$(NOTANGLE) xchunks.nw		$(TANGLEOPTS) $(CPIF) $@
$(OUTPUT)$(P)lines.nws:		lines.nw;	$(NOTANGLE) lines.nw		$(TANGLEOPTS) $(CPIF) $@
$(OUTPUT)$(P)tangle:		tangle.nw;	$(NOTANGLE) tangle.nw		$(TANGLEOPTS) $(CPIF) $@
$(OUTPUT)$(P)weave:		weave.nw;	$(NOTANGLE) weave.nw		$(TANGLEOPTS) $(CPIF) $@

################################################################
#

noidx.tex: noidx.nw
	noweave -delay -x -filter 'elide hackers:*' noidx.nw > noidx.tex
