std::vector<std::string> API_Processos::obterStringsDoComando(std::string comando){

    std::stringstream ss;

    ss << comando << " > " << arquivoTemp;
      
    //Executando comando
    system(ss.str().c_str());  

    //Vetor que terá as linhas do comando
    std::vector<std::string> linhas;
    std::string linha; 
    std::ifstream file;
    
    //Abrindo arquivo com as informações do comando executado pelo system()
    file.open(arquivoTemp);

    if (file.is_open()){
          
        while ( getline (file,linha) ) {
            //Adicionando linha no vetor de string
            linhas.push_back(linha);
        }
        file.close();
    } 
    
    //Retornando um vetor de string onde cada string é uma linha do resultado(no terminal) do comando system();
    return linhas;
}

std::string API_Processos::obterComInformacaoProcesso(std::string processo){

    //String no qual vai está o comando
    std::string comando;
    //String capaz de se fazer concatenação
    std::stringstream ss;
    //Concatenando string para gerar o comando
    ss << "cat /proc/" << processo << "/status";

    //Atribuindo o valor da concatenação em uma string
    return ss.str();
}

void API_Processos::construirArvore(){
    
    for(unsigned int pai=0;pai<this->processos.size();pai++){
        for(unsigned int filho=0;filho<this->processos.size();filho++){
            if(this->processos[pai].getId() == this->processos[filho].getPai()){
                this->processos[pai].getFilhos()->push_back(&(this->processos[filho]));
            }
        }
    }
}

std::vector<std::string> API_Processos::split(const std::string& str) {
    std::stringstream ss(str);
    return {std::istream_iterator<std::string>{ss}, std::istream_iterator<std::string>{}};
}

std::map<std::string,std::string> API_Processos::obterAtributosChaveValor(std::vector<std::string> informacoes){
    
    //Vetor com as inforamções relevantes
    std::map<std::string,std::string> atributos;

    //Interando entre todas as linhas do vetor das informações
    for(std::string s : informacoes){

        //Quebrando as informações
        std::vector<std::string> lexemas = split(s);
      
        if (lexemas[0] == NAME    ||
            lexemas[0] == PAI     ||
            lexemas[0] == USUARIO ||
            lexemas[0] == MEMORIA ||
            lexemas[0] == MEMPICO ||
            lexemas[0] == MEMDATA ||
            lexemas[0] == MEMPILHA||
            lexemas[0] == MEMSGTX ||
            lexemas[0] == MEMSWAP ||
            lexemas[0] == TAMETPG ||
            lexemas[0] == TAMSTPG ||
            lexemas[0] == CPUSPERM|| 
            lexemas[0] == TRCONTV ||
            lexemas[0] == TRCONTF ||
            lexemas[0] == THREADS ||
            lexemas[0] == SINPEND 
           ){
            atributos[lexemas[0]] = lexemas[1];  
        }else{
            if(lexemas[0] == ESTADOB){
                atributos[lexemas[0]] = lexemas[1]+ " " +lexemas[2];
            }
        }
    }

    return atributos;
}

std::map<std::string,std::string> API_Processos::obterAtributosValor(std::vector<std::string> informacoes){
    
    //Vetor com as inforamções relevantes
    std::map<std::string,std::string> atributos;
    std::vector<std::string> lexemas;
    std::vector<std::string> temp;

    //Interando entre todas as linhas do vetor das informações
    for(std::string s : informacoes){

        temp = split(s);

        //Quebrando as informações
        lexemas.insert(lexemas.end(),temp.begin(),temp.end());
    }
      
    atributos[MIFAULTS] = lexemas[MIFAULTSNUMBER];
    atributos[MJFAULTS] = lexemas[MJFAULTSNUMBER];  
    atributos[PRIORI] = lexemas[PRIORINUMBER];
    atributos[TEMPINIC] = lexemas[TEMPINICNUMBER];

    return atributos;
}

std::vector<std::string> API_Processos::verificarIntegridade(std::vector<std::string> processos){
    
    //Vetor resultante 
    std::vector<std::string> result;
    
    //Iterando entre todos os processos  
    for(std::string p : processos){

        std::ifstream obj;
        obj.open("/proc/"+p+"/status");

        //Aceitando apenas as strings que tem o arquivo status  
        if (obj.is_open()) {
            result.push_back(p);  
        }
        obj.close();
    }

    return result;
}

std::vector<std::string> API_Processos::obterinformacoesProcesso(std::string processo,std::string nomeArquivo){
    
    std::vector<std::string> linhas;
    
    std::string linha; 
    std::ifstream file;
    
    file.open("/proc/"+processo+"/"+nomeArquivo);
    
    if (file.is_open()){

        while ( getline (file,linha) ) {
            linhas.push_back(linha);
        }

    file.close();
    
    }else{
      std::vector<std::string> s;
      return s;
    } 
    
    //Resultado do comando
    return linhas;
}

std::vector<Processo> API_Processos::construirProcessos(){
    
    std::vector<Processo> resultado;

    //Criando processo Odin(Pai de todos)
    resultado.push_back(*(new Processo(0,"OS",-1,-1, (unsigned int)0)));

    //Obtendo os id de todos os processos  
    std::vector<std::string> processosString = verificarIntegridade(obterStringsDoComando("ls /proc | grep \"^[0-9]\""));  

    //Iterando entre todos os ids encontrados
    for(std::string p : processosString){
      
        //Obter inforamções do processo  
        std::vector<std::string> informacoesStatus = obterinformacoesProcesso(p,"status");
        std::vector<std::string> informacoesStat = obterinformacoesProcesso(p,"stat");

        //Se existir informações sobre ele adiciona-o para o vetor resultante
        if(!informacoesStatus.empty() && !informacoesStatus.empty()){

            //Obter os atributos relevantes
            std::map<std::string,std::string> atributosStatus = obterAtributosChaveValor(informacoesStatus);
        
            std::map<std::string,std::string> atributosStat = obterAtributosValor(informacoesStat);
        
            Processo* proc = new Processo(std::stoi(p,nullptr,0));
        
            if(!atributosStatus[NAME].empty()){
                proc->setNome(atributosStatus[NAME]);
            }
            
            if(!atributosStatus[USUARIO].empty()){
                proc->setUsuario(std::stoi(atributosStatus[USUARIO],nullptr,0));
            }
            
            if(!atributosStatus[PAI].empty()){
                proc->setPai(std::stoi(atributosStatus[PAI],nullptr,0));
            }
            
            if(!atributosStatus[MEMORIA].empty()){
                proc->setMemoria((unsigned int)std::strtoul(atributosStatus[MEMORIA].c_str(),nullptr,0));
            }
            
            if(!atributosStatus[MEMPICO].empty()){
                proc->setMemPico((unsigned int)std::strtoul(atributosStatus[MEMPICO].c_str(),nullptr,0));
            }
            
            if(!atributosStatus[MEMDATA].empty()){
                proc->setMemDados((unsigned int)std::strtoul(atributosStatus[MEMDATA].c_str(),nullptr,0));
            }
            
            if(!atributosStatus[MEMPILHA].empty()){
                proc->setMemPilha((unsigned int)std::strtoul(atributosStatus[MEMPILHA].c_str(),nullptr,0));
            }
            
            if(!atributosStatus[MEMSGTX].empty()){
                proc->setMemSegText((unsigned int)std::strtoul(atributosStatus[MEMSGTX].c_str(),nullptr,0));
            }
            
            if(!atributosStatus[MEMSWAP].empty()){
                proc->setMemSwap((unsigned int)std::strtoul(atributosStatus[MEMSWAP].c_str(),nullptr,0));
            }
            
            if(!atributosStatus[TAMETPG].empty()){
                proc->setTamEntTabPag((unsigned int)std::strtoul(atributosStatus[TAMETPG].c_str(),nullptr,0));
            }
            
            if(!atributosStatus[TAMSTPG].empty()){
                proc->setTamSegTabPag((unsigned int)std::strtoul(atributosStatus[TAMSTPG].c_str(),nullptr,0));
            }
            
            if(!atributosStat[MIFAULTS].empty()){
                proc->setMifaults((unsigned int)std::strtoul(atributosStat[MIFAULTS].c_str(),nullptr,0));  
            }
            
            if(!atributosStat[MJFAULTS].empty()){
                proc->setMjfaults((unsigned int)std::strtoul(atributosStat[MJFAULTS].c_str(),nullptr,0));
            }    
            
            if(!atributosStatus[CPUSPERM].empty()){
                
                unsigned int valor=0;

                if(atributosStatus[CPUSPERM].length()==1){
                    valor = 1;
                }else{
                    valor = (unsigned int)(std::strtoul(atributosStatus[CPUSPERM].substr(atributosStatus[CPUSPERM].length()-1).c_str(),nullptr,0));
                    valor+=1;
                }
                   
                proc->setCpusPermitidas(valor);
            }
            
            if(!atributosStatus[ESTADOB].empty()){
                proc->setEstado(stringParaEstado(atributosStatus[ESTADOB]));
            }

            if(!atributosStatus[TRCONTV].empty()){
                proc->setTrocaContVol((unsigned int)std::strtoul(atributosStatus[TRCONTV].c_str(),nullptr,0));
            }

            if(!atributosStatus[TRCONTF].empty()){
                proc->setTrocaContFor((unsigned int)std::strtoul(atributosStatus[TRCONTF].c_str(),nullptr,0));
            }

            if(!atributosStatus[THREADS].empty()){
                proc->setThreads((unsigned int)std::strtoul(atributosStatus[THREADS].c_str(),nullptr,0));
            }

            if(!atributosStatus[SINPEND].empty()){
                proc->setNumSinPend(std::strtoul(atributosStatus[SINPEND].c_str(),nullptr,0));
            }

            if(!atributosStatus[SINPEND].empty()){
                proc->setNumSinPend(std::strtoul(atributosStatus[SINPEND].c_str(),nullptr,0));
            }

            if(!atributosStat[PRIORI].empty()){
                proc->setPrioridade(std::stoi(atributosStat[PRIORI].c_str(),nullptr,0));  
            }

            if(!atributosStat[TEMPINIC].empty()){
                proc->setTempDeInic(std::strtoull(atributosStat[TEMPINIC].c_str(),nullptr,0));
            } 

            resultado.push_back(*proc);
        }
    }   
    return resultado;
}

bool API_Processos::contemUsuario(std::vector<int> usuarios,int s){

    for(int u : usuarios){
        if(u==s){
            return true;
        }
    }
    return false;
}

std::string API_Processos::obterNomeArqTemp(std::string nomeDoArquivo){
    
    std::ifstream obj;

    int ponto = nomeDoArquivo.find_last_of(".");    
    std::string nome = nomeDoArquivo.substr(0,ponto);
    std::string extensao = nomeDoArquivo.substr(ponto,nomeDoArquivo.size()-1);

    bool existeArquivo=true;

    while(existeArquivo){

        obj.open((nome + extensao));
    
        existeArquivo = obj.is_open();

        if(existeArquivo==true){
            nome=(nome+"t");
        }

        obj.close();
    }

    return (nome+extensao);   
}

API_Processos::API_Processos(){
    this->arquivoTemp = obterNomeArqTemp("temp.txt");

    processos = construirProcessos();
    construirArvore(); 
}

API_Processos::~API_Processos(){
    remove(arquivoTemp.c_str());
}

void imprimirSubArvore(Processo& processo){

}

Processo& API_Processos::buscaPorID(int id){

    for(unsigned int i=0;i<this->processos.size();i++){
        if(id==this->processos[i].getId()){
            return this->processos[i];
        } 
    }

    return *(new Processo(-1,"erro", -1, -1, (unsigned int)0));
}

std::vector<int> API_Processos::obterUsuarios(){
    
    std::vector<int> resultado;

    //Iterando entre os processos
    for(Processo p : this->processos){
        //Excluindo o processo Odin(Pai de todos)
        if(p.getUsuario()!=-1){
            //Adicionando apenas usuários que ainda não existe no vetor
            if(!contemUsuario(resultado,p.getUsuario())){
                resultado.push_back(p.getUsuario());
            }
        }
    }
    return resultado;
}

int API_Processos::quantidadeProcessosDoUsuario(int usuario){

    int cont=0;
    //Iterando entre todos os usuários
    for(Processo p : this->processos){
        //Contando apenas os que tem usuário igual
        if(p.getUsuario()==usuario){
            cont++;
        }
    }
    return cont;
}

void API_Processos::salvarInformacoes(std::string nomeDoArquivo){
    
    nlohmann::json j;

    //Iterando entre todos os processos
    for(Processo p : processos){

      //Ecluindo o processo Odin(pai de todos)
      if(p.getId()!=0){    
        //Salvar as informações no fim do arquivo json 
        j.push_back(nlohmann::json{{"ID", p.getId()}, 
                                   {"Nome", p.getNome()}, 
                                   {"Quantidade de Filhos", p.getFilhos()->size()},
                                   {"Usuário", p.getUsuario()},
                                   {"Pai", p.getPai()},
                                   {"Memória Utilizada", p.getMemoria()},
                                   {"Memória de Pico", p.getMemPico()},
                                   {"Memória de Dados", p.getMemDados()},
                                   {"Memória de Pilha", p.getMemPilha()},
                                   {"Memória de Segmento de texto", p.getMemSegText()},
                                   {"Memória em SWAP", p.getMemSwap()},
                                   {"Tamanho da entrada da tabela de páginas", p.getTamEntTabPag()}, 
                                   {"Tamanho da tabela de segundo nível", p.getTamSegTabPag()},
                                   {"Major Faults", p.getMjfaults()},
                                   {"Minor Faults", p.getMifaults()},
                                   {"Quantidade de CPUS permitidas", p.getCpusPermitidas()},
                                   {"Estado", EstadoParaString(p.getEstado())},
                                   {"Troca de contexto voluntárias", p.getTrocaContVol()},
                                   {"Troca de contexto forçadas", p.getTrocaContFor()},
                                   {"Threads", p.getThreads()},
                                   {"Numero de sinais pendentes", p.getNumSinPend()},
                                   {"Taxa de Prioridade", p.getPrioridade()},
                                   {"Tempo de inicio em relação ao boot", p.getTempDeInic()}    
                                  });
      }
    }
    
    //Escrita do objeto representante no JSON no arquivo JSON
    std::ofstream o((nomeDoArquivo+".json"));
    o << std::setw(4) << j << std::endl;
}

std::vector<Processo> API_Processos::getProcessos(){
    return this->processos;
}

//================================================================

    //FALTA IMPLEMENTAR

//================================================================

void imprimirSubArvore(Processo processo){

}

void imprimirArvore(){

}

Processo& buscarPorNome(){

    return *(new Processo(-1,"erro", -1, -1, (unsigned int)0));
}

std::vector<Processo> buscarProcsPorUsu(int){

    std::vector<Processo> procDoUsuario;

    return procDoUsuario;
}

int quantProcNoEstado(ESTADO){

    return 0;
}