CC=gcc -Wall -pedantic

all:
	${CC} -o spawntest.exe spawnvpe.c spawntest.c
	${CC} -o spawnchild.exe spawnchild.c
	./spawntest.exe
