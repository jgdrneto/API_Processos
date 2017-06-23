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

std::string Processo::getNome(){
    return this->nome;
}

std::vector<Processo*>* Processo::getFilhos(){
    return &(this->filhos);
}

int Processo::getUsuario() {
    return this->usuario;
}

int Processo::getPai(){
    return this->pai;
}

unsigned int Processo::getMemoria(){
    return this->memoria;  
}

unsigned int Processo::getMemPico(){
    return this->memPico;  
}

unsigned int Processo::getMemDados(){
    return this->memDados;  
}

unsigned int Processo::getMemPilha(){
    return this->memPilha;  
}

unsigned int Processo::getMemSegText(){
    return this->memSegText;  
}

unsigned int Processo::getMemSwap(){
    return this->memSwap;
}

unsigned int Processo::getTamEntTabPag(){
    return this->tamEntTabPag;
}

unsigned int Processo::getTamSegTabPag(){
    return this->tamSegTabPag;
}

unsigned int Processo::getMjfaults() {
    return this->mjfaults;
}

unsigned int Processo::getMifaults() {
    return this->mifaults;
}

std::vector<unsigned int> Processo::getCpusPermitidas() {
    return this->cpusPermitidas;
}

ESTADO Processo::getEstado(){
    return this->estado;
}

unsigned int Processo::getTrocaContVol(){
    return this->trocaContVol;
}

unsigned int Processo::getTrocaContFor(){
    return this->trocaContFor;
}

unsigned int Processo::getThreads(){
    return this->threads;
}

unsigned long int Processo::getNumSinPend(){
    return this->numSinPend;
}

int Processo::getPrioridade(){
    return this->prioridade;
}

unsigned long long int Processo::getTempDeInic(){
    return this->tempDeInic;
}

//=================================================

void Processo::setId(int nId){
    this->id = nId;
}

void Processo::setNome(std::string nNome){
    this->nome = nNome;
}

void Processo::setUsuario(int nUsuario){
    this->usuario = nUsuario;
}

void Processo::setPai(int nPai){
    this->pai = nPai;
}

void Processo::setMemoria(unsigned int nMemoria){
    this->memoria = nMemoria;
}

void Processo::setMemPico(unsigned int nMemPico){
    this->memPico = nMemPico;
}

void Processo::setMemDados(unsigned int nMemDados){
    this->memDados = nMemDados;
}

void Processo::setMemPilha(unsigned int nMemPilha){
    this->memPilha = nMemPilha;
}

void Processo::setMemSegText(unsigned int nMemSegText){
    this->memSegText= nMemSegText;
}

void Processo::setMemSwap(unsigned int nMemSwap){
    this->memSwap = nMemSwap;
}

void Processo::setTamEntTabPag(unsigned int nTamEntTabPag){
    this->tamEntTabPag = nTamEntTabPag;
}

void Processo::setTamSegTabPag(unsigned int nTamSegTabPag){
    this->tamSegTabPag = nTamSegTabPag;
}

void Processo::setMifaults(unsigned int nMifaults){
    this->mifaults = nMifaults;
}

void Processo::setMjfaults(unsigned int nMjfaults){
    this->mjfaults = nMjfaults;
}

void Processo::setCpusPermitidas(std::vector<unsigned int> nCpusPermitidas){
    this->cpusPermitidas = nCpusPermitidas;
}    

void Processo::setESTADO(ESTADO nEstado){
    this->estado = nEstado;
}

void Processo::setTrocaContVol(unsigned int nTrocaContVol){
    this->trocaContVol = nTrocaContVol;
}

void Processo::setTrocaContFor(unsigned int nTrocaContFor){
    this->trocaContFor = nTrocaContFor;
}

void Processo::setThreads(unsigned int nThreads){
    this->threads = nThreads;
}

void Processo::setNumSinPend(unsigned long int nNumSinPend){
    this->numSinPend = nNumSinPend; 
}

void Processo::setPrioridade(int nPrioridade){
    this->prioridade = nPrioridade;
}

void Processo::setTempDeInic(unsigned long long int nTempDeInic){
    this->tempDeInic = nTempDeInic;
}

std::string Processo::toString(){

    std::stringstream ss;
    //Concatenando string para gerar o comando
    ss << "Id: " << this->id << "\n" << 
          "Nome: " << this->nome << "\n" << 
          "Usuario: " << this->usuario << "\n" << 
          "Pai: " << this->pai << "\n" <<
          "Quantidade de filhos: " << this->filhos.size() << "\n" <<  
          "Memória: " << this->memoria << "\n" <<
          "Memória de Pico: " << this->memPico << "\n" <<  
          "Memória de Pilha: " << this->memPilha << "\n" <<  
          "Memória de Dados: " << this->memDados << "\n" <<
          "Memória de SWAP: " << this->memSwap << "\n" <<
          "Tamanho da entrada da tabela de páginas: " << this->tamEntTabPag << "\n" <<
          "Tamanho da segunda tabela de páginas: " << this->tamSegTabPag << "\n" <<      
          "Minor Faults: " << this->mifaults << "\n"  <<
          "Major Faults: " << this->mjfaults << "\n" <<
          "Quantidade de CPUS permitidas: " << this->cpusPermitidas.size() << "\n" <<
          "ESTADO: " << this->estado << "\n" <<
          "Troca de contexto voluntárias: " << this->trocaContVol << "\n" <<
          "Troca de contexto forçadas: " << this->trocaContFor << "\n" <<
          "Threads: " << this->threads << "\n" <<
          "Número de sinais pendentes: " << this->numSinPend << "\n" <<
          "Pioridade: " << this->prioridade << "\n" <<
          "Tempo de inicio em relação ao boot: " << this->tempDeInic << "\n"; 
          
    return ss.str();        
}