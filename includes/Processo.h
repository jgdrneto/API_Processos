#ifndef _PROCESSO_
#define _PROCESSO_

#include <string>
#include <vector>
#include <sstream>

//Classe representativa de um processo
class Processo{

private:
  	//Atributos
  	int id;                      	//ID único do processo
  	std::string nome;               //Nome do processo
  	std::vector<Processo*> filhos;  //Vetor de ponteiros com os endereços dos filhos do processo
  	int usuario;                 	//ID do Usuário do processo
  	int pai;                     	//ID do pai do processo
    unsigned int memoria;        	//Quantidade de memória virtual utilizada
    int swap;                    	//Qunatidade de memória em swap
    int mjfaults;                	//Quantidade de Major Faults
    int mifaults;                	//Quantidade de Minor Faults

public:
    
	/*  Descrição   : Construtor vazio da classe
     */
    Processo();

    /*  Descrição   : Construtor da classe
     *
     *  @param int  : Inteiro com o ID do processo
     */
  	Processo(int);

    /*  Descrição             : Construtor da classe
     *
     *  @param int            : Inteiro com o ID do processo
     *  @param string         : Nome do processo
     *  @param int            : ID do usuário do processo
     *  @param int            : ID do pai do processo
     *  @param unsined int    : Quantidade de memória virtual usada
     */
    Processo(int,std::string, int, int , unsigned int);

    /*  Descrição   : Obter o id do processo
     *
     *  @return int : Id do processo
     */
  	int getId();

    /*  Descrição            : Obter a mémoria usada pelo processo
     *
     *  @return unisgned int : Valor em KB de memória usada no processo
     */
    unsigned int getMemoria();

    /*  Descrição   : Obter o id do pai do processo
     *
     *  @return int : Id do pai do processo
     */
  	int getPai();

    /*  Descrição   : Obter o valor da memória do processo em Swap
     *
     *  @return int : Valor da memória em swap
     */
    int getSwap();

    /*  Descrição      : Obter o nome do processo
     *
     *  @return string : Nome do processo
     */
  	std::string getNome();

    /*  Descrição                  : Obter os filhos do processo
     *
     *  @return vector<Processo*>* : Vetor com os endereços dos filhos do processo
     */
  	std::vector<Processo*>* getFilhos();

    /*  Descrição   : Obter o id do usuário do processo
     *
     *  @return int : Id do usuário do processo
     */
    int getUsuario();

    /*  Descrição   : Obter o valor de major faults do processo
     *
     *  @return int : Valor de major faults do processo
     */
    int getMjfaults();

    /*  Descrição   : Obter o valor de minor faults do processo
     *
     *  @return int : Valor de minor faults do processo
     */
    int getMifaults();

    /*  Descrição   : Adicionar novo pai para o processo
     *
     *  @param int  : Novo id do pai do processo
     */  
    void setPai(int);

    /*  Descrição   : Adicionar novo valor da memória de swap no processo
     *
     *  @param int  : Novo valor para a memória de swap
     */  
    void setSwap(int);

    /*  Descrição           : Adicionar novo valor de memória para o processo
     *
     *  @param unsigned int : Nova memória do processo
     */  
    void setMemoria(unsigned int);

    /*  Descrição : Adicionar novo id para o processo
     *
     * @param int : Novo id do processo
     */  
  	void setId(int);

    /* Descrição     : Adicionar novo nome para o processo
     *
     * @param string : Novo nome do processo
     */ 
  	void setNome(std::string);

    /*  Descrição   : Adicionar novo usuário para o processo
     *
     *  @param int  : Novo usuário do processo
     */ 
  	void setUsuario(int);

    /*  Descrição   : Adicionar novo valor de minor faults para o processo
     *
     *  @param int  : Novo valor de minor faults do processo
     */ 
    void setMifaults(int);

    /*  Descrição   : Adicionar novo valor de major faults para o processo
     *
     *  @param int  : Novo valor de major faults do processo
     */ 
    void setMjfaults(int);

    /*  Descrição       : Converte a classe em informações de String
     *
     *  @return string  : 
     */
    std::string toString();

};	

#include "../src/Processo.cpp"

#endif