guide.ps: guide.dvi
	dvips -D 300 -o guide.ps guide

guide.tex: guide.nw
	notangle -R"hackers' guide" guide.nw ../c/*.nw ../lua/*.nw > guide.tex

guide.dvi: guide.tex
	latex '\scrollmode \input '"guide"
	while grep -s 'Rerun to get cross-references right' guide.log; do latex '\scrollmode \input '"guide"; done

guide.html: guide.dvi
	sl2h guide.tex | htmltoc > guide.html

clean: ;	/bin/rm -f *.dvi *.log *.blg *~ wc.tex *.ps *.gz *.uu *.html
clobber: clean
	rm -f *.1 *.7 *.txt *.aux *.lot *.toc

