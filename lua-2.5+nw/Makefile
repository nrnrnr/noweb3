# makefile for lua hierarchy

all:
	cd include; make $@
	cd src; make $@
	cd clients/lib; make $@
	cd clients/lib/old; make $@

co clean klean:
	cd include; make $@
	cd src; make $@
	cd src/luac; make $@
	cd clients/lib; make $@
	cd clients/lib/old; make $@
	cd clients/lua; make $@

install:
	cd src/luac; make all
	cd clients/lua; make all

old:
	cd clients/lib/old; make $@

clobber: clean
