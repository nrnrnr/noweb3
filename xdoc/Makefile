SHELL=/bin/sh
.SUFFIXES: .1 .7 .txt .ps
.1.txt: ;	nroff -man $*.1 > $*.txt
.1.ps: ;	psroff -t -man $*.1 > $*.ps
.7.txt: ;	nroff -man $*.7 > $*.txt
.7.ps: ;	psroff -t -man $*.7 > $*.ps

MANPAGES=notangle.1   noweb.1   nodefs.1   noroots.1   noindex.1   \
         nowebstyle.7   nowebfilters.7   nuweb2noweb.1   sl2h.1 htmltoc.1   \
	 noroff.1
TXTPAGES=notangle.txt noweb.txt nodefs.txt noroots.txt noindex.txt \
         nowebstyle.txt nowebfilters.txt nuweb2noweb.txt sl2h.txt htmltoc.txt   \
	 noroff.txt
SRCS=$(MANPAGES) $(TXTPAGES)
DOVERSION=./doversion

all: guide.ps $(SRCS)

notangle.1: manpage.nw ../shell/noweave.nw docdate.nw
	notangle -t8 -Rnotangle.1  manpage.nw ../shell/noweave.nw docdate.nw | $(DOVERSION) > notangle.1

nowebstyle.7: manpage.nw ../tex/support.nw docdate.nw
	notangle -t8 -Rnowebstyle.7 manpage.nw ../tex/support.nw docdate.nw | $(DOVERSION) > nowebstyle.7

nowebfilters.7: nowebfilters.nw docdate.nw
	notangle -t8 nowebfilters.nw docdate.nw | $(DOVERSION) > nowebfilters.7

noweb.1: manpage.nw docdate.nw
	notangle -t8 -Rnoweb.1 manpage.nw docdate.nw | $(DOVERSION) > noweb.1

nodefs.1: nodefs.nw docdate.nw
	notangle -t8 nodefs.nw docdate.nw | $(DOVERSION) > nodefs.1

noroots.1: noroots.nw docdate.nw
	notangle -t8 noroots.nw docdate.nw | $(DOVERSION) > noroots.1

noindex.1: noindex.nw docdate.nw
	notangle -t8 noindex.nw docdate.nw | $(DOVERSION) > noindex.1

sl2h.1: sl2h.nw docdate.nw
	notangle -t8 sl2h.nw docdate.nw | $(DOVERSION) > sl2h.1

htmltoc.1: htmltoc.nw docdate.nw
	notangle -t8 htmltoc.nw docdate.nw | $(DOVERSION) > htmltoc.1

nuweb2noweb.1: manpage.nw docdate.nw
	notangle -t8 -Rnuweb2noweb.1  manpage.nw docdate.nw | $(DOVERSION) > nuweb2noweb.1

noroff.1: noroff.nw docdate.nw
	notangle -t8 noroff.nw docdate.nw | $(DOVERSION) > noroff.1

# existing noweb 3 makefile from here down
guide.ps: guide.dvi
	dvips -D 300 -o guide.ps guide

guide.tex: guide.nw
	notangle -R"hackers guide" guide.nw ../c/*.nw ../lua/*.nw > guide.tex

guide.dvi: guide.tex
	latex '\scrollmode \input '"guide"
	while grep -s 'Rerun to get cross-references right' guide.log; do latex '\scrollmode \input '"guide"; done

guide.html: guide.dvi
	sl2h guide.tex | htmltoc > guide.html

clean: ;	/bin/rm -f *.dvi *.log *.blg *~ wc.tex *.ps *.gz *.uu *.html
clobber: clean
	rm -f *.1 *.7 *.txt *.aux *.lot *.toc

