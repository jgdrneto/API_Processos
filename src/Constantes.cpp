#ifndef _CONSTANTES_
#define _CONSTANTES_

//Arquivo reservado para definição de constantes

#define NAME "Name:"
#define PAI "PPid:"
#define USUARIO "Uid:"
#define MEMORIA "VmData:"
#define MEMSWAP "VmSwap:"
#define MJFAULTS "MjFaults:"
#define MIFAULTS "MiFaults:"
#define MJFAULTSNUMBER 11
#define MIFAULTSNUMBER 9

enum ESTADO	
{
	RUNNING,
	SLEEPING,
	DISK_SLEPP,
	STOPPED,
	TRACING_STOP,
	ZOMBIE,
	DEAD
};

#endif