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
	-$(RM) *~ *.dvi *.aux *.log *.blg *.bbl *.toc 2>$(NUL)
	-$(RM) support.tex 2>$(NUL)

clobber:
	-$(RM) $(OUTPUT)$(P)nwmac.tex 2>$(NUL)
	-$(RM) $(OUTPUT)$(P)noweb.sty 2>$(NUL)
