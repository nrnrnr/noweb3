#line 210 "spawnvpe.nw"
#ifndef NWPROCESS_INCLUDED
#define NWPROCESS_INCLUDED
	#ifdef WIN32
		#include <process.h>
	#else
		
#line 222 "spawnvpe.nw"
int _spawnvpe (
	int mode, 
	const char *filename, 
	char * const argv[], 
	char *const envp[] );

#define spawnvpe _spawnvpe
#define _spawnvp(mode, filename, argvect) \
	_spawnvpe ((mode), (filename), (argvect), environ);
#define spawnvp(mode, filename, argvect) \
	_spawnvpe ((mode), (filename), (argvect), environ);
#line 216 "spawnvpe.nw"
		
#line 240 "spawnvpe.nw"
#ifndef _P_WAIT
	#define _P_WAIT 0
#endif
#ifndef P_WAIT
	#define P_WAIT _P_WAIT
#endif

#ifndef _P_NOWAIT
	#define _P_NOWAIT 1
#endif
#ifndef P_NOWAIT
	#define P_NOWAIT _P_NOWAIT
#endif

#ifndef _P_NOWAITO
	#define _P_NOWAITO 3
#endif
#line 217 "spawnvpe.nw"
	#endif
#endif
