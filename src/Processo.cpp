Processo::Processo(){/*NULO*/}

Processo::Processo(int nId){
    this->id = nId;
    this->memoria=0;
    this->memSwap = 0;
    this->mjfaults=0;
    this->mifaults=0;
}

Processo::Processo(int nId,std::string nNome, int nUsuario, int nPai, unsigned int nMemoria){
    this->id = nId;
    this->nome = nNome;
    this->usuario = nUsuario;
    this->pai = nPai;
    this->memoria = nMemoria;
    this->memSwap = 0;
    this->mjfaults=0;
    this->mifaults=0;
}

int Processo::getId(){
    return this->id;  
}

unsigned int Processo::getMemoria(){
    return this->memoria;  
}

int Processo::getPai(){
    return this->pai;
}

unsigned int Processo::getMemSwap(){
    return this->memSwap;
}

std::string Processo::getNome(){
    return this->nome;
}

std::vector<Processo*>* Processo::getFilhos(){
    return &(this->filhos);
}

int Processo::getUsuario() {
    return this->usuario;
}

unsigned int Processo::getMjfaults() {
    return this->mjfaults;
}

unsigned int Processo::getMifaults() {
    return this->mifaults;
}

void Processo::setPai(int nPai){
    this->pai = nPai;
}

void Processo::setMemSwap(unsigned int nMemSwap){
    this->memSwap = nMemSwap;
}

void Processo::setMemoria(unsigned int nMemoria){
    this->memoria = nMemoria;
}

void Processo::setId(int nId){
    this->id = nId;
}

void Processo::setNome(std::string nNome){
    this->nome = nNome;
}

void Processo::setUsuario(int nUsuario){
    this->usuario = nUsuario;
}

void Processo::setMifaults(unsigned int nMifaults){
    this->mifaults = nMifaults;
}

void Processo::setMjfaults(unsigned int nMjfaults){
    this->mjfaults = nMjfaults;
}

std::string Processo::toString(){

    std::stringstream ss;
    //Concatenando string para gerar o comando
    ss << "Id: " << this->id << "\n" << 
          "Nome: " << this->nome << "\n" << 
          "Usuario: " << this->usuario << "\n" << 
          "Pai: " << this->pai << "\n" <<
          "Memória: " << this->memoria << "\n" << 
          "Swap: " << this->memSwap << "\n" <<
          "Quantidade de filhos: " << this->filhos.size() << "\n" <<
          "Minor Faults: " << this->mifaults << "\n"  <<
          "Major Faults: " << this->mjfaults << "\n"; 
            
    return ss.str();        
}