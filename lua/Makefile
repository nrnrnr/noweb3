include ../nwconfig

NOTANGLE=notangle

.SUFFIXES: .cfg .nw .nws

.nw.nws: ;	$(NOTANGLE) -L'$$file %F%N$$line %L%N' $*.nw > $*.nws

CONFIG=pipes.cfg sys.cfg noweb.cfg util.cfg  list.nws set.nws
FILTERS=cat.nws stripconds.nws xchunks.nws lines.nws
STAGES=totex.nws tohtml.nws noidx.nws elide.nws unmarkup.nws $(FILTERS)
SCRIPTS=tangle.nws weave.nws

all: $(CONFIG) $(STAGES) $(SCRIPTS)

test: $(CONFIG) $(STAGES) $(SCRIPTS)
	@echo 'write("Scripts load from .\n")' | NWPATH=. no
	@echo 'argv = {"-internaldefaults", "-n", "-html", "/dev/null"}; do_nwfile("weave.nws"); write("Null weave OK.\n")' | NWPATH=. no
	@echo 'argv = {"-internal", "test.nw"}; do_nwfile("tangle.nws"); write("Null tangle OK.\n")' | NWPATH=. no

htmltest: $(CONFIG) $(STAGES) $(SCRIPTS)
	@echo 'testfile("/home/nr/www/noweb/index.html")' | NWPATH=. no

clean:
	rm -f *~ *.cfg *.nws
	rm -f *.dvi *.aux *.html *.log *.toc *.tex *.ps
	rm -f core
	rm -f luac.out

clobber: clean

install: $(SCRIPTS) $(CONFIG) $(STAGES)
	for i in $(CONFIG) $(STAGES); do sed 's@|LIBDIR|@$(LIB2)@g' $$i > $(LIB3)/$$i; done
	for i in $(SCRIPTS); do cp $$i $(LIB3)/`basename $$i .nws`; done

pipes.cfg: config.nw;	$(NOTANGLE) -L'$$file %F%N$$line %L%N' -R$@ config.nw > $@
sys.cfg: config.nw;	$(NOTANGLE) -L'$$file %F%N$$line %L%N' -R$@ config.nw > $@
noweb.cfg: config.nw;	$(NOTANGLE) -L'$$file %F%N$$line %L%N' -R$@ config.nw > $@
util.cfg: config.nw;	$(NOTANGLE) -L'$$file %F%N$$line %L%N' -R$@ config.nw > $@

################################################################
#

noidx.tex: noidx.nw
	noweave -delay -x -filter 'elide hackers:*' noidx.nw > noidx.tex

