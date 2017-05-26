#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <unistd.h>

#include "API_Processos.cpp"

using namespace std;

int main(int argc, char const *argv[]){	
	
	vector<Processo> processos = API_Processos::obterProcessos();
	
	for(Processo p : processos){

		cout << "=============================================" << endl;

		cout << p.toString() << endl;

		cout << "=============================================" << endl;
	}
	
}	