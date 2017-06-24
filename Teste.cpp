#include <iostream>

#include "includes/API_Processos.h"

using namespace std;

int main(int argc, char const *argv[]){	
	
	API_Processos proc;
	
	std::cout << proc.getProcessos()[3].getNome() << std::endl;

    std::cout << "\n" << proc.quantProcNoEstado(SLEEPING) << std::endl;
    std::cout << "\n" << proc.buscarPorNome("bamfdaemon").toString() << std::endl;
    std::cout << "\n" << proc.buscarPorId(1).toString() << std::endl;
    std::cout << "\n" << proc.buscarProcsPorUsu(121)[0].toString() << std::endl;

    proc.imprimirArvore();
    proc.imprimirSubArvore(proc.buscarPorNome("bamfdaemon"));

	return 0;
}	