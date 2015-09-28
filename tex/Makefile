NAME="name of version checked in"
CIMSG="message for version checked in"
RCSFILES=support.nw Makefile

# don't edit this file; edit ../nwconfig instead

include ../nwconfig

all: $(OUTPUT)$(P)nwmac.tex $(OUTPUT)$(P)noweb.sty

source: nwmac.tex noweb.sty
touch: nwmac.tex noweb.sty
	touch nwmac.tex noweb.sty

checkin:
	ci -l $(CINAME) $(CIMSG) $(RCSFILES)

$(OUTPUT)$(P)nwmac.tex: support.nw
	$(NOTANGLE) support.nw $(TANGLEOPTS) -Rnwmac.tex $(CPIF) $@

$(OUTPUT)$(P)noweb.sty: support.nw
	$(NOTANGLE) support.nw $(TANGLEOPTS) -Rnoweb.sty $(CPIF) $@

support.tex: support.nw
	noweave -delay -x support.nw > support.tex

clean: 
	-$(RM) -f *~ *.dvi *.aux *.log *.blg *.bbl *.toc
	-$(RM) -f support.tex

clobber:
	-$(RM) -f $(OUTPUT)$(P)nwmac.tex
	-$(RM) -f $(OUTPUT)$(P)noweb.sty
