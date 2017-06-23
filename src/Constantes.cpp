#ifndef _CONSTANTES_
#define _CONSTANTES_

#include <string>

//Arquivo reservado para definição de constantes

#define NAME "Name:"
#define PAI "PPid:"
#define USUARIO "Uid:"
#define MEMORIA "VmSize:"
#define MEMPICO "VmPeak:"
#define MEMDATA "VmData:"
#define MEMPILHA "VmStk:"
#define MEMPILHA "VmStk:"
#define MEMSGTX "VmExe:"
#define MEMSWAP "VmSwap:"
#define TAMETPG "VmPTE:"
#define TAMSTPG "VmPMD:"
//================================
#define MJFAULTS "MjFaults:"
#define MJFAULTSNUMBER 11
//================================
#define MIFAULTS "MiFaults:"
#define MIFAULTSNUMBER 9
//================================
#define CPUSPERM "Cpus_allowed_list:"
#define ESTADOB "State:"
#define TRCONTV "voluntary_ctxt_switches:"
#define TRCONTF "nonvoluntary_ctxt_switches:"
#define THREADS "Threads:"
#define SINPEND "ShdPnd:"
//================================
#define PRIORI "Priori:"
#define PRIORINUMBER 18
//================================
#define TEMPINIC "TempInic:"
#define TEMPINICNUMBER 22  
//================================

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

std::string EstadoParaString(ESTADO estado){
	
	std::string nomeEstado;

	switch(estado){
		case RUNNING:
			nomeEstado = "RUNNING";
		break;
		case SLEEPING:
			nomeEstado = "SLEEPING";
		break;
		case DISK_SLEPP:
			nomeEstado = "DISK_SLEPP";
		break;
		case STOPPED:
			nomeEstado = "STOPPED";
		break;
		case TRACING_STOP:
			nomeEstado = "TRACING_STOP";
		break;
		case ZOMBIE:
			nomeEstado = "ZOMBIE";
		break;
		case DEAD:
			nomeEstado = "DEAD";
		break;			
	}

	return nomeEstado;
}
#endif