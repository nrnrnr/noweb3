BASE=spawnvpe
RM=rm -f
ROOTS=spawntest.mak spawnchild.c spawnvpe.c spawntest.c nwprocess.h

all: base print

base: $(ROOTS)
	# ispell -t *.nw
	m4 < $(BASE).m4 > $(BASE).tmp
	noweb -o $(BASE).tmp
	noweave -index -t2 -delay $(BASE).tmp > $(BASE).tex

spawnvpe.c nwprocess.h: spawnvpe.nw
	no tangle -L -Rspawnvpe.c -cpif spawnvpe.c -Rnwprocess.h -cpif nwprocess.h \
		spawnvpe.nw

spawntest.mak spawnchild.c spawntest.c: spawntest.nw
	no tangle -Rspawntest.mak -cpif spawntest.mak \
		-L -Rspawnchild.c -cpif spawnchild.c -Rspawntest.c -cpif spawntest.c \
		spawntest.nw

print:
	latex $(BASE).tex
	dvips $(BASE).dvi -o $(BASE).ps 

pdf:
	ps2pdf $(BASE).ps

archive:
	tar -cvzf $(BASE).tar.z Makefile $(BASE).nw spawntest.nw $(BASE).m4

test:
	make -f spawntest.mak

clean:
	$(RM) *.tex *.aux *.log *.dvi *.pdf .s* *.c *.h *.exe *.tar.z *.ps *.toc *.tmp *.mak
