#line 104 "spawntest.nw"
#include <stdlib.h> 
#include <stdio.h> 
#ifndef WIN32
	#include <unistd.h> 
#else
	#define sleep(x) (void)0
#endif

int 
main (int argc, char *argv[], char *envp[])
{
	sleep (1);
	puts ("Environment in spawnchild.exe:");
	
#line 132 "spawntest.nw"
while (*envp)
{
	printf ( "%s\n", *envp);
	envp++;
}
#line 118 "spawntest.nw"
	puts ("\nParameters in spawnchild.exe:");
	
#line 126 "spawntest.nw"
while (*argv)
{
	printf ( "%s\n", *argv);
	argv++;
}
#line 120 "spawntest.nw"
	puts ("\nVariable \"THIS\" in spwanchild:");
	printf ("%s\n", getenv ("THIS"));
	return EXIT_SUCCESS;
}
