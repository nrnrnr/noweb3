# makefile for lua distribution

all:
	rm -f manual.id
	touch manual.id
	latex manual.tex
	latex manual.tex
	makeindex manual
	sort -df manual.idx | sed -e 's/_/\\_/g' >manual.id
	latex manual.tex
	dvips -o manual.ps manual.dvi
	gzip manual.ps
	mv manual.ps.gz refman.ps.gz
	rm -f manual.*

clean:
	rm -f manual.aux manual.toc manual.log manual.idx
	rm -f *~

co:
	co -f -M manual.tex luac.man

klean:	clean
	rm -f manual.ps manual.dvi
