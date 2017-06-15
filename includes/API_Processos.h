#ifndef _API_PROCESSOS_
#define _API_PROCESSOS_

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <iterator>
#include <unistd.h>
#include <map>

#include "../src/Constantes.cpp"		//Arquivo com constantes
#include "json.hpp"						//Arquivo para manipulação com JSON
#include "Processo.h"					//Arquivo com as classe de Processo 

//Classe da API de processos
class API_Processos{
private:
  	//Atributos
  	std::vector<Processo> processos;	//Lista de processos
  	std::string arquivoTemp;

  	/*  Decrição 				: Obtem um vetor de string resultante de um comando
   	 *
     *  @param string 			: Nome do arquivo
     *
     *  @return vector<string> 	: Vetor com string de cada linha do arquivo
     */ 
  	std::vector<std::string> obterStringsDoComando(std::string);

  	/*  Descrição 		: Obter o comando para ter as informações de um determinado processo
     *  
     *  @param string 	: Id do processo que se deseja ter as informações  
     *
     *  return string 	: Comando que retorna as informações de um processo
     */
  	std::string obterComInformacaoProcesso(std::string);

  	/*  Descrição 					: Construir a árvore
     *  
     *  @param vector<Processo>& 	: Endereço de vetor de processos de todos os processos
     */
  	void construirArvore();

  	/*  Descrição 				: Função que quebra string em varias string pelo caractere de " " 
     *
     *  @param const string& 	: String que se deseja quebrar
     *  
     *  @return vector<string> 	: Vetor de string resultantes da quebra
     */
	std::vector<std::string> split(const std::string&);

	/*  Descrição 					: Obtem os atributos relevantes das informações  
   	 *
     *  @param vector<string> 		: Vetor com as informações brutas
     *  
     *  @return map<string,string> 	: Mapa com as informações de chave e valor 
     */
  	std::map<std::string,std::string> obterAtributosChaveValor(std::vector<std::string>);

  	/*  Descrição 					: Obtem os atributos relevantes das informações  
     *
     *  @param vector<string> 		: Vetor com as informações brutas
     *  
     *  @return map<string,string> 	:  Mapa com as informações de chave e valor  
     */
  	std::map<std::string,std::string> obterAtributosValor(std::vector<std::string>);

  	/*  Descrição 				: Verificar integridade das informações
   	 *
     *  @param vector<string> 	: String com todos os processos
     *
     *  @return vector<string> 	: String que passaram no controle de integridade 
     *
     */
  	std::vector<std::string> verificarIntegridade(std::vector<std::string>);

  	/*  Descrição 				: Obter informações do processo
   	 *
     *  @param string 			: String com ID do processo
     *	
     *	@param String 			: Nome do arquivo a ser buscar as informações
     *	
     *  @return vector<string> 	: Obter infomrações do processo
   	 */
  	std::vector<std::string> obterinformacoesProcesso(std::string,std::string);

  	/*  Descrição 					: Construir os processos
     *
     *  @return vector<Processo> 	: Vetor com os processo presentes no sistema operacional
     */
  	std::vector<Processo> construirProcessos();

  	/*  Descrição 			: Verifica se existe um usuario em uma lista
     *
     *  @param vector<int> 	: Vetor com os usuários
     *  @param string 		: Usuário que se quer saber se já está no vetor
     *
     *  @return bool 		: Verdadeiro se id usuário está no vetor, e falso caso contrário
     */
  	bool contemUsuario(std::vector<int>,int);

  	/*  Descrição 		: Define o nome do arquivo temporário
     *
     *  @param string 	: Usuário que se quer saber se já está no vetor
     *
     *  @param string 	: Usuário que se quer saber se já está no vetor
     */
	std::string obterNomeArqTemp(std::string);  	

public:

	/*	Descrição : Construtor da classe
	 */
	API_Processos();

	/*	Descrição : Destrutor da classe
	 */
	virtual ~API_Processos();

	/*  Descrição 			: Imprimir a árvore em pré-ordem 
     *
     *  @param Processo& 	: Endereço do processo raiz
     */
  	void imprimirArvore(Processo&);

  	/*  Descrição 			: Buscar o processo pelo ID
   	 *
     *  @param string 		: ID do processo que se deseja obter 
     *
     *  @return Processo& 	: Processo que se deseja buscar
     */
  	Processo& buscaPorID(int);

  	/*  Descrição 			: Obter todos os usuários distintos dos processos
     *
     *  @return vector<int> : Vetor com todos os usuários distintos do processo
     */
  	std::vector<int> obterUsuarios();

  	/*  Descrição 	: Contar todos os processo de um determindado usuário
     *
     *  @param int 	: ID do usuário que se deseja ver a quantidade de procesos
     *
     *  @return int : Quantidade de processos de um usuário 
     */
	int quantidadeProcessosDoUsuario(int);

	/*  Descrição : Salvar as informações dos processos em um arquivo JSON
     */
  	void salvarArvore();

  	/*	Descrição 	: Obter o vetor com todos os processos
  	 *
  	 *	@return 	: Vetor com todos os processos
  	 */
  	std::vector<Processo> getProcessos();
};

#include "../src/API_Processos.cpp"

#endif