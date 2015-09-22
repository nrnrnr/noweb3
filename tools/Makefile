include ../nwconfig

TANGLEOBJS=$(OUTPUT)$(P)notangle$(O) \
	$(OUTPUT)$(P)getline$(O) \
	$(OUTPUT)$(P)match$(O) \
	$(OUTPUT)$(P)modules$(O) \
	$(OUTPUT)$(P)modtrees$(O) \
	$(OUTPUT)$(P)strsave$(O) \
	$(OUTPUT)$(P)main$(O) \
	$(OUTPUT)$(P)errors$(O) \
	$(OUTPUT)$(P)columns$(O)

MARKUPOBJS=$(OUTPUT)$(P)markmain$(O) \
	$(OUTPUT)$(P)strsave$(O) \
	$(OUTPUT)$(P)markup$(O) \
	$(OUTPUT)$(P)errors$(O) \
	$(OUTPUT)$(P)getline$(O) \
	$(OUTPUT)$(P)columns$(O)

OBJS=$(TANGLEOBJS) $(MARKUPOBJS) $(OUTPUT)$(P)nocond$(O) $(OUTPUT)$(P)tie$(O)

TARGETS=$(OUTPUT)$(P)markup$(E) \
	$(OUTPUT)$(P)nocond$(E) \
	$(OUTPUT)$(P)nt$(E) \
	$(OUTPUT)$(P)tie$(E)

all: $(TARGETS)

$(OUTPUT)$(P)markup$(E): $(MARKUPOBJS)
	$(LD) $(LFLAGS)$@ $(MARKUPOBJS)

$(OUTPUT)$(P)nocond$(E): $(OUTPUT)$(P)nocond$(O)
	$(LD) $(LFLAGS)$@ $(OUTPUT)$(P)nocond$(O)

$(OUTPUT)$(P)nt$(E): $(TANGLEOBJS)
	$(LD) $(LFLAGS)$@ $(TANGLEOBJS)

$(OUTPUT)$(P)tie$(E): $(OUTPUT)$(P)tie$(O)
	$(LD) $(LFLAGS)$@ $(OUTPUT)$(P)tie$(O)

clean:
	-$(RM) $(OBJS)

clobber: clean
	-$(RM) $(TARGETS)

$(OUTPUT)$(P)columns$(O):	columns.c columns.h
	$(CC) $(CFLAGS)$@ columns.c
$(OUTPUT)$(P)errors$(O):	errors.c errors.h
	$(CC) $(CFLAGS)$@ errors.c
$(OUTPUT)$(P)getline$(O): getline.c columns.h errors.h getline.h
	$(CC) $(CFLAGS)$@ getline.c
$(OUTPUT)$(P)main$(O):	main.c columns.h errors.h modtrees.h modules.h notangle.h
	$(CC) $(CFLAGS)$@ main.c
$(OUTPUT)$(P)markmain$(O):	markmain.c columns.h errors.h getline.h markup.h
	$(CC) $(CFLAGS)$@ markmain.c
$(OUTPUT)$(P)markup$(O):	markup.c errors.h markup.h strsave.h
	$(CC) $(CFLAGS)$@ markup.c
$(OUTPUT)$(P)match$(O):	match.c match.h
	$(CC) $(CFLAGS)$@ match.c
$(OUTPUT)$(P)modtrees$(O):	modtrees.c errors.h modtrees.h modules.h strsave.h
	$(CC) $(CFLAGS)$@ modtrees.c
$(OUTPUT)$(P)modules$(O):	modules.c columns.h errors.h modtrees.h modules.h strsave.h
	$(CC) $(CFLAGS)$@ modules.c
$(OUTPUT)$(P)nocond$(O):	nocond.c
	$(CC) $(CFLAGS)$@ nocond.c
$(OUTPUT)$(P)notangle$(O):	notangle.c errors.h getline.h modtrees.h modules.h notangle.h strsave.h
	$(CC) $(CFLAGS)$@ notangle.c
$(OUTPUT)$(P)strsave$(O):	strsave.c errors.h strsave.h
	$(CC) $(CFLAGS)$@ strsave.c
$(OUTPUT)$(P)tie$(O):	tie.c
	$(CC) $(CFLAGS)$@ tie.c
