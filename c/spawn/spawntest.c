#line 12 "spawntest.nw"
#include <stdlib.h> 
#include <stdio.h> 
#include <errno.h>
#include <string.h>
#include "nwprocess.h"

int 
main (void)
{
	char *environment[] = {
		"THIS=is",
		"THE=environment",
		"TO=be",
		"PASSED=to",
		"THE=child",
		"PROCESS=end",
		NULL
	};
	char *argvector[] = {
		"spawnchild.exe",
		"First Parameter",
		"Second Parameter",
		"Third Parameter",
		NULL
	};
	int retval;
	int wait_mode;
	char *program_name;
	
	program_name = "spawnchild.exe";

	wait_mode = P_NOWAIT;
	
#line 78 "spawntest.nw"
printf (
	"Spawning %s in mode _P_%sWAIT:\n",
	program_name,
	wait_mode == P_WAIT ? "" : "NO" );
retval = _spawnvpe (
	wait_mode,
	program_name,
	argvector,
	environment);
printf ("The return value was %d.\n",
	retval);
if (retval == -1)
{
	printf (
		"errno = %d: %s.\n", 
		errno,
		strerror (errno));
}
#line 45 "spawntest.nw"
	wait_mode = P_WAIT;
	
#line 78 "spawntest.nw"
printf (
	"Spawning %s in mode _P_%sWAIT:\n",
	program_name,
	wait_mode == P_WAIT ? "" : "NO" );
retval = _spawnvpe (
	wait_mode,
	program_name,
	argvector,
	environment);
printf ("The return value was %d.\n",
	retval);
if (retval == -1)
{
	printf (
		"errno = %d: %s.\n", 
		errno,
		strerror (errno));
}
#line 46 "spawntest.nw"
                                                   

	program_name = "ls";
	argvector[0] = program_name;
	argvector[1] = "-Flias";
	argvector[2] = NULL;
	
	wait_mode = _P_NOWAITO;
	
#line 78 "spawntest.nw"
printf (
	"Spawning %s in mode _P_%sWAIT:\n",
	program_name,
	wait_mode == P_WAIT ? "" : "NO" );
retval = _spawnvpe (
	wait_mode,
	program_name,
	argvector,
	environment);
printf ("The return value was %d.\n",
	retval);
if (retval == -1)
{
	printf (
		"errno = %d: %s.\n", 
		errno,
		strerror (errno));
}
#line 55 "spawntest.nw"
	wait_mode = P_WAIT;
	
#line 78 "spawntest.nw"
printf (
	"Spawning %s in mode _P_%sWAIT:\n",
	program_name,
	wait_mode == P_WAIT ? "" : "NO" );
retval = _spawnvpe (
	wait_mode,
	program_name,
	argvector,
	environment);
printf ("The return value was %d.\n",
	retval);
if (retval == -1)
{
	printf (
		"errno = %d: %s.\n", 
		errno,
		strerror (errno));
}
#line 56 "spawntest.nw"
                                                   

	program_name = "program_with_a_silly_name";
	argvector[0] = program_name;
	argvector[1] = NULL;
	
	wait_mode = _P_WAIT;
	
#line 78 "spawntest.nw"
printf (
	"Spawning %s in mode _P_%sWAIT:\n",
	program_name,
	wait_mode == P_WAIT ? "" : "NO" );
retval = _spawnvpe (
	wait_mode,
	program_name,
	argvector,
	environment);
printf ("The return value was %d.\n",
	retval);
if (retval == -1)
{
	printf (
		"errno = %d: %s.\n", 
		errno,
		strerror (errno));
}
#line 63 "spawntest.nw"
                                                   
	
	program_name = "sh";
    argvector[0] = program_name;
    argvector[1] = "-c";
    argvector[2] = "set";
    argvector[3] = NULL;

    wait_mode = _P_WAIT;
    
#line 78 "spawntest.nw"
printf (
	"Spawning %s in mode _P_%sWAIT:\n",
	program_name,
	wait_mode == P_WAIT ? "" : "NO" );
retval = _spawnvpe (
	wait_mode,
	program_name,
	argvector,
	environment);
printf ("The return value was %d.\n",
	retval);
if (retval == -1)
{
	printf (
		"errno = %d: %s.\n", 
		errno,
		strerror (errno));
}
#line 73 "spawntest.nw"
	
	return EXIT_SUCCESS;
}
