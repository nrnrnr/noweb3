#line 112 "spawnvpe.nw"
#ifndef WIN32
#line 197 "spawnvpe.nw"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <assert.h>
#include "nwprocess.h"
#line 114 "spawnvpe.nw"
int 
_spawnvpe (
	int mode, 
	const char *filename, 
	char *const argv[], 
	char *const envp[] )
{
	extern char **environ;
	pid_t pid;
	
#line 137 "spawnvpe.nw"
assert (filename != NULL);
assert (argv != NULL);
assert (argv[0] != NULL);
assert (envp != NULL);
#line 124 "spawnvpe.nw"
	pid = fork();
	if (mode == P_WAIT)
	{
		
#line 142 "spawnvpe.nw"
int status;
if (pid == 0)
{
	
#line 195 "spawnvpe.nw"
environ = (char **) envp;
#line 146 "spawnvpe.nw"
	execvp (filename, argv);
}
else
{
	pid = waitpid (pid, &status, 0);
	if (pid == -1)
	{
		return pid;
	}
	if (WIFEXITED (status))
	{
		return ((signed char)WEXITSTATUS (status));
	}
	else
	{
		return 0;
	}
}
#line 128 "spawnvpe.nw"
	}
	else
	{
		
#line 165 "spawnvpe.nw"
if (pid == 0)
{
	
#line 195 "spawnvpe.nw"
environ = (char **) envp;
#line 168 "spawnvpe.nw"
	execvp (filename, argv);
}
else
{
	return pid;
}
#line 132 "spawnvpe.nw"
	}
	return -1;
}
#endif
