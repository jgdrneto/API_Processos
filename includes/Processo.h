#ifndef _PROCESSO_
#define _PROCESSO_

#include <string>
#include <vector>
#include <sstream>

#include "../src/Constantes.cpp"        //Arquivo com constantes

//Classe representativa de um processo
class Processo{

private:
  	//Atributos
  	int id;                                  //ID único do processo
  	std::string nome;                        //Nome do processo
  	std::vector<Processo*> filhos;           //Vetor de ponteiros com os endereços dos filhos do processo
  	int usuario;                             //ID do Usuário do processo
  	int pai;                                 //ID do pai do processo
    unsigned int memoria;                    //Quantidade de memória virtual utilizada
    unsigned int memPico;                    //Quantidade pico de memória virtual utilizada
    unsigned int memDados;                   //Quantidade de memória sendo utilizada para dados
    unsigned int memPilha;                   //Quantidade de memória sendo utilizada para pilha
    unsigned int memSegText;                 //Quantidade de memória sendo utilizada para segmentos de texto
    unsigned int memSwap;                    //Quantidade de memória sendo utilizada em swap
    unsigned int tamEntTabPag;               //Tamanho da entrada da tabela de páginas
    unsigned int tamSegTabPag;               //Tamanho da tabela de página de segundo nível
    unsigned int mjfaults;                   //Quantidade de Major Faults
    unsigned int mifaults;                   //Quantidade de Minor Faults
    std::vector<unsigned int> cpusPermitidas;//Lista de CPU's que o processo pode executar
    ESTADO estado;                           //Estado do processo
    unsigned int trocaContVol;               //Quantidade de troca de contexto voluntárias
    unsigned int trocaContFor;               //Quantidade de troca de contexto forçadas
    unsigned int threads;                    //Quantidade de threads do processo
    unsigned long int numSinPend;            //Quantidade de sinais pendentes no processo
    int prioridade;                          //Prioridade do processo
    unsigned long long int tempDeInic;       //Tempo de inicio, em segundos, do processo após o boot
public:
    
//===========================================================================

    //CONSTRUTORES    

//===========================================================================

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

//===========================================================================

    //GET's    

//===========================================================================
    
    /*  Descrição   : Obter o id do processo
     *
     *  @return int : Id do processo
     */
  	int getId();

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

    /*  Descrição   : Obter o id do pai do processo
     *
     *  @return int : Id do pai do processo
     */
    int getPai();

    /*  Descrição            : Obter a memória usada pelo processo
     *
     *  @return unisgned int : Valor em KB de memória usada no processo
     */
    unsigned int getMemoria();

    /*  Descrição            : Obter o valor de pico de memória usada pelo processo
     *
     *  @return unisgned int : Valor em KB do pico de memória do processo
     */
    unsigned int getMemPico();

    /*  Descrição            : Obter o valor da memória de dados usada pelo processo
     *
     *  @return unisgned int : Valor em KB da memória de dados
     */
    unsigned int getMemDados();

    /*  Descrição            : Obter o valor da memória de pilha usada pelo processo
     *
     *  @return unisgned int : Valor em KB da memória de pilha
     */
    unsigned int getMemPilha();

    /*  Descrição            : Obter o valor da memória de segmentos de textos usada pelo processo
     *
     *  @return unisgned int : Valor em KB da memória de segmento de texto
     */
    unsigned int getMemSegText();

    /*  Descrição            : Obter o valor da memória do processo em Swap
     *
     *  @return unsigned int : Valor da memória em swap
     */
    unsigned int getMemSwap();

    /*  Descrição            : Obter o tamanho da entrada da tabela de páginas
     *
     *  @return unsigned int : Valor do tamanho da entrada da tabela de páginas
     */
    unsigned int getTamEntTabPag();

    /*  Descrição            : Obter o tamanho da tabela de páginas de segundo nível
     *
     *  @return unsigned int : Valor do tamanho da tabela de páginas de segundo nível
     */
    unsigned int getTamSegTabPag();

    /*  Descrição            : Obter o valor de major faults do processo
     *
     *  @return unsigned int : Valor de major faults do processo
     */
    unsigned int getMjfaults();

    /*  Descrição            : Obter o valor de minor faults do processo
     *
     *  @return unsigned int : Valor de minor faults do processo
     */
    unsigned int getMifaults();

    /*  Descrição                    : Obter lista das cpus permitidas para execução do processo
     *
     *  @return vector<unsigned int> : Lista de CPU's permitidas
     */
    std::vector<unsigned int> getCpusPermitidas();

    /*  Descrição       : Obter o estado do processo
     *
     *  @return ESTADO  : Estado atual do processo
     */
    ESTADO getEstado();

    /*  Descrição       : Obter a quantidade de trocas de contexto voluntárias
     *
     *  @return int     : Quantidade de trocas de contexto voluntárias
     */
    unsigned int getTrocaContVol();

    /*  Descrição       : Obter a quantidade de trocas de contexto forçadas
     *
     *  @return int     : Quantidade de trocas de contexto forçadas
     */
    unsigned int getTrocaContFor();

    /*  Descrição            : Obter a quantidade de threads do processo
     *
     *  @return unsigned int : Quantidade de threads
     */
    unsigned int getThreads();

    /*  Descrição                 : Obter a quantidade de sinais pendentes
     *
     *  @return unsigned long int : Quantidade de sinais pendentes
     */
    unsigned long int getNumSinPend();

    /*  Descrição   : Obter a prioridade de execução do processo
     *
     *  @return int : Prioridade de execução do processo
     */
    int getPrioridade();

    /*  Descrição                      : Obter o tempo de inicio do processo em relação ao boot
     *
     *  @return unsigned long long int : Tempo em segundos
     */
    unsigned long long int getTempDeInic();

//===========================================================================

    //SET's    

//===========================================================================

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

    /*  Descrição   : Adicionar novo pai para o processo
     *
     *  @param int  : Novo id do pai do processo
     */  
    void setPai(int);

    /*  Descrição           : Adicionar novo valor de memória para o processo
     *
     *  @param unsigned int : Nova memória do processo
     */  
    void setMemoria(unsigned int);

    /*  Descrição           : Adicionar novo valor do pico de memória de swap no processo
     *
     *  @param unsigned int : Novo valor de pico de memória
     */  
    void setMemPico(unsigned int);

    /*  Descrição           : Adicionar novo valor da memória de dados no processo
     *
     *  @param unsigned int : Novo valor da memória de dados
     */  
    void setMemDados(unsigned int);

    /*  Descrição           : Adicionar novo valor da memória de pilha no processo
     *
     *  @param unsigned int : Novo valor da memória de pilha
     */  
    void setMemPilha(unsigned int);

    /*  Descrição           : Adicionar novo valor da memória de segmentos de texto
     *
     *  @param unsigned int : Novo valor da memória de segmento de textos
     */  
    void setMemSegText(unsigned int);

    /*  Descrição           : Adicionar novo valor da memória de swap no processo
     *
     *  @param unsigned int : Novo valor para a memória de swap
     */  
    void setMemSwap(unsigned int);

    /*  Descrição           : Adicionar novo valor do tamanho da entrada da tabela de páginas
     *
     *  @param unsigned int : Novo valor para o tamanho da entrada da tabela de páginas
     */  
    void setTamEntTabPag(unsigned int);

    /*  Descrição           : Adicionar novo valor do tamanho da tabela de páginas de segundo nível
     *
     *  @param unsigned int : Novo valor para o tamanho da tabela de páginas de segundo nível
     */  
    void setTamSegTabPag(unsigned int);

    /*  Descrição           : Adicionar novo valor de major faults para o processo
     *
     *  @param unsigned int : Novo valor de major faults do processo
     */ 
    void setMjfaults(unsigned int);

    /*  Descrição           : Adicionar novo valor de minor faults para o processo
     *
     *  @param unsigned int : Novo valor de minor faults do processo
     */ 
    void setMifaults(unsigned int);

    /*  Descrição           : Adicionar nova quantidade de cpus permitidas
     *
     *  @param unsigned int : Nova lista de cpus permitidas
     */ 
    void setCpusPermitidas(std::vector<unsigned int>);    

    /*  Descrição     : Adicionar ESTADO para o processo
     *
     *  @param ESTADO : Novo ESTADO do processo
     */  
    void setESTADO(ESTADO);

    /*  Descrição           : Adicionar quantidade de trocas de contexto voluntárias no processo
     *
     *  @param unsigned int : Nova quantidade de trocas de contexto voluntárias
     */  
    void setTrocaContVol(unsigned int);

    /*  Descrição           : Adicionar quantidade de trocas de contexto forçadas no processo
     *
     *  @param unsigned int : Nova quantidade de trocas de contexto forçadas
     */  
    void setTrocaContFor(unsigned int);    

    /*  Descrição           : Adicionar quantidade de threads no processo
     *
     *  @param unsigned int : Nova quantidade de threads
     */  
    void setThreads(unsigned int); 

    /*  Descrição           : Adicionar quantidade de sinais pendentes no processo
     *
     *  @param unsigned int : Nova quantidade de sinais pendentes do processo
     */  
    void setNumSinPend(unsigned long int); 

    /*  Descrição   : Adicionar prioridade do processo
     *
     *  @param int  : Novo valor de prioridade do processo
     */  
    void setPrioridade(int); 

    /*  Descrição                     : Adicionar novo tempo de inicio do processo em relação ao boot
     *
     *  @param unsigned long long int : Novo valor de tempo de inicio
     */  
    void setTempDeInic(unsigned long long int); 

//===========================================================================

    //OUTROS MÉTODOS    

//===========================================================================

    /*  Descrição       : Converte a classe em informações de String
     *
     *  @return string  : String com os valores do objeto
     */
    std::string toString();

//===========================================================================

};	

#include "../src/Processo.cpp"

#endif