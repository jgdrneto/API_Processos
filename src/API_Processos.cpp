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
            lexemas[0] == MEMSWAP 
           ){
            atributos[lexemas[0]] = lexemas[1];  
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
      
    atributos[MIFAULTS] = lexemas[9];
    atributos[MJFAULTS] = lexemas[11];  

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
        
            /*
            cout << "ID: " << p << endl;
            cout << "Nome: " << atributos[NAME] << endl;
            cout << "Pai: " << atributos[PAI] << endl;
            cout << "Usuário: " << atributos[USUARIO] << endl;
            cout << "Memória: " << atributos[MEMORIA] << endl;
            cout << "SWAP: " << atributos[MEMSWAP] << endl;
            */

            if(!atributosStatus[NAME].empty()){
                proc->setNome(atributosStatus[NAME]);
            }
            if(!atributosStatus[PAI].empty()){
                proc->setPai(std::stoi(atributosStatus[PAI],nullptr,0));
            }
            if(!atributosStatus[USUARIO].empty()){
                proc->setUsuario(std::stoi(atributosStatus[USUARIO],nullptr,0));
            }
            if(!atributosStatus[MEMORIA].empty()){
                proc->setMemoria((unsigned int)std::stoi(atributosStatus[MEMORIA],nullptr,0));
            }
            if(!atributosStatus[MEMSWAP].empty()){
                proc->setMemSwap((unsigned int)std::stoi(atributosStatus[MEMSWAP],nullptr,0));
            }
            
            //Informação de falta de páginas
            proc->setMifaults((unsigned int)std::stoi(atributosStat[MIFAULTS],nullptr,0));  
            proc->setMjfaults((unsigned int)std::stoi(atributosStat[MJFAULTS],nullptr,0));
            
            resultado.push_back(*proc);
        }
    }   
    return resultado;
}

API_Processos::API_Processos(){
    this->arquivoTemp = obterNomeArqTemp("temp.txt");

    processos = construirProcessos();
    construirArvore(); 
}

Processo& API_Processos::buscaPorID(int id){

    for(unsigned int i=0;i<this->processos.size();i++){
        if(id==this->processos[i].getId()){
            return this->processos[i];
        } 
    }
    return *(new Processo(-1,"erro", -1, -1, (unsigned int)0));
}

bool API_Processos::contemUsuario(std::vector<int> usuarios,int s){

    for(int u : usuarios){
        if(u==s){
            return true;
        }
    }
    return false;
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

void API_Processos::salvarArvore(){
    
    nlohmann::json j;

    //Iterando entre todos os processos
    for(Processo p : processos){

      //Ecluindo o processo Odin(pai de todos)
      if(p.getId()!=0){    
        //Salvar as informações no fim do arquivo json 
        j.push_back(nlohmann::json{{"ID", p.getId()}, {"Nome", p.getNome()}, {"Pai", p.getPai()},{"Usuário", p.getUsuario()},{"Memória Utilizada", p.getMemoria()},{"Memória em SWAP", p.getMemSwap()}});
      }
    }
    
    //Escrita do objeto representante no JSON no arquivo JSON
    std::ofstream o("arvore.json");
    o << std::setw(4) << j << std::endl;
}

std::vector<Processo> API_Processos::getProcessos(){
    return this->processos;
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

API_Processos::~API_Processos(){
    remove(arquivoTemp.c_str());
}