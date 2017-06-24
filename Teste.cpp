#include <iostream>

#include "includes/API_Processos.h"

using namespace std;

int main(int argc, char const *argv[]){	
	
	API_Processos proc;
	
	std::cout << proc.getProcessos()[3].toString() << std::endl;

	return 0;
}	