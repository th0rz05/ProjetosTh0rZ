//
// Created by Tiago Barbosa on 07/04/2022.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <chrono>
#include "Empresa.h"

Empresa::Empresa() {
}

const std::vector<Carrinha> &Empresa::getCarrinhas() const {
    return carrinhas;
}

void Empresa::setCarrinhas(const std::vector<Carrinha> &carrinhas) {
    Empresa::carrinhas = carrinhas;
}

const std::vector<Encomenda> &Empresa::getEncomendas() const {
    return encomendas;
}

void Empresa::setEncomendas(const std::vector<Encomenda> &encomendas) {
    Empresa::encomendas = encomendas;
}

void Empresa::carregarEncomendas(std::string file) {
    std::ifstream fencomendas(file);

    int volume;
    int peso;
    int recompensa;
    int duracao;

    int id =1 ;

    std::string line;

    getline(fencomendas,line); //ignorar primeira linha

    while(getline(fencomendas,line)){
        std::istringstream iss( line );
        iss >> volume >> peso >> recompensa >> duracao;
        encomendas.emplace_back(volume,peso,recompensa,duracao,id);
        id++;
    }
}

void Empresa::carregarCarrinhas(std::string file) {
    std::ifstream fcarrinhas(file);

    int volMax;
    int pesoMax;
    int custo;

    int id = 1;
    std::string line;

    getline(fcarrinhas,line); //ignorar primeira linha

    while(getline(fcarrinhas,line)){
        std::istringstream iss( line );
        iss >> volMax >> pesoMax >> custo;;
        carrinhas.emplace_back(volMax,pesoMax,custo,id);
        id++;
    }
}

std::vector<Encomenda> Empresa::gerarEncomendas(int nr) {
    std::vector<Encomenda> encomendas_subset;

    unsigned seed = time(0);
    srand(seed);

    if(nr>encomendas.size()){ // maior que base de dados
        nr=encomendas.size();
    }

    while(encomendas_subset.size()<nr){
        int index = rand()% encomendas.size(); // gerar index random
        encomendas_subset.push_back(encomendas[index]);
        encomendas.erase(encomendas.begin()+index);
    }

    return encomendas_subset;
}

void Empresa::cenario1(int nr) {
    //std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now(); //start clock

    carregarEncomendas("database/encomendas.txt");
    carregarCarrinhas("database/carrinhas.txt");
    std::vector<Encomenda> encomendasDoDia = gerarEncomendas(nr); //gerar subset
    std::vector<Encomenda> encomendasNaoEntregues;

    std::vector<Carrinha> carrinhasUsadas;

    std::cout << "Encomendas normais para este dia:\n\n";
    gerarTabelaEncomendasDoDia(encomendasDoDia);

    std::sort(carrinhas.begin(), carrinhas.end(), compararCarrinhasCenario1); //ordenar carrinhas por volume*peso

    std::sort(encomendasDoDia.begin(), encomendasDoDia.end(), compararEncomendasCenario1); //ordenar encomendas por volume*peso

    encomendasNaoEntregues = carregarEncomendasParaCarrinhas(encomendasDoDia);

    double nr_encomendas = 0;

    for(Carrinha &carrinha : carrinhas){
        if(!carrinha.usada()) break;
        carrinhasUsadas.push_back(carrinha);
        nr_encomendas += carrinha.getCarga().size();
    }

    double fator = nr_encomendas / carrinhasUsadas.size();
    double fatorSemUltima = 0;
    std::vector<Encomenda> cargaUltimaCarrinha = carrinhasUsadas[carrinhasUsadas.size()-1].getCarga();
    if(carrinhasUsadas.size()>1) {
        fatorSemUltima = (nr_encomendas-cargaUltimaCarrinha.size()) / (carrinhasUsadas.size()-1);
    }
    if(fatorSemUltima>fator){ // se o fator for melhor sem a ultima carrinha
        for(Encomenda &encomenda : cargaUltimaCarrinha){
            encomendasNaoEntregues.push_back(encomenda);
        }
        carrinhasUsadas.erase(carrinhasUsadas.end()-1); // apagar carga
    }

    gerarTabelaCarrinhasComCarga(carrinhasUsadas);

    std::cout << "\nCarrinha usadas: " << carrinhasUsadas.size() << std::endl << std::endl;

    if(!encomendasNaoEntregues.empty()){
        gerarTabelaEncomendasNaoEntregues(encomendasNaoEntregues);
    }

    std:: cout << "\nEficiencia: " << std::setprecision(3) << (float(encomendasDoDia.size()-encomendasNaoEntregues.size())/encomendasDoDia.size())*100 << "%" << std::endl;

    //std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now(); //end clock
    //std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;

}

void Empresa::cenario2(int nr,int opcao) {
    //std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now(); //start clock

    carregarEncomendas("database/encomendas.txt");
    carregarCarrinhas("database/carrinhas.txt");
    std::vector<Encomenda> encomendasDoDia = gerarEncomendas(nr); //gerar subset
    std::vector<Encomenda> encomendasNaoEntregues;

    std::vector<Carrinha> carrinhasUsadas;

    std::cout << "Encomendas normais para este dia:\n\n";
    gerarTabelaEncomendasDoDia(encomendasDoDia);

    std::sort(carrinhas.begin(), carrinhas.end(), compararCarrinhasCenario2); //ordenar carrinhas por volume*peso

    if(opcao==1){
        std::sort(encomendasDoDia.begin(), encomendasDoDia.end(), compararEncomendasCenario2LucroMaximo);
    }
    else if(opcao==2){
        std::sort(encomendasDoDia.begin(), encomendasDoDia.end(), compararEncomendasCenario2LucroEquilibrado);
    }
    else{
        std::cout << "Input invalido" << std::endl;
        return;
    }

    encomendasNaoEntregues=carregarEncomendasParaCarrinhas(encomendasDoDia);

    int lucro  = 0;
    for(Carrinha &carrinha : carrinhas){
        if(!carrinha.usada()) break; //a partir do momento que já não são usadas
        if(carrinha.valorCarga()>carrinha.getCusto()){
            carrinhasUsadas.push_back(carrinha);
            lucro+= carrinha.valorCarga()-carrinha.getCusto();
        }
        else{ // carrinha nao da lucro
            for(Encomenda &encomenda : carrinha.getCarga()){
                encomendasNaoEntregues.push_back(encomenda);
            }
            carrinha.setCarga(std::vector<Encomenda>{});
        }
    }

    gerarTabelaCarrinhasComCarga(carrinhasUsadas);

    if(!encomendasNaoEntregues.empty()){
        gerarTabelaEncomendasNaoEntregues(encomendasNaoEntregues);
    }

    std::cout << "\nLucro: " << lucro << " euros" << std::endl;

    std:: cout << "\nEficiencia: " << std::setprecision(3) << (float(encomendasDoDia.size()-encomendasNaoEntregues.size())/encomendasDoDia.size())*100 << "%" << std::endl;

    //std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now(); //end clock
    //std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;

}

void waitEnter(){
    std::cout << std::endl << "Press enter to continue..." << std::endl;
    std::string str;
    std::getline(std::cin, str);
}

void Empresa::cenario3(int nr) {
    //std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now(); //start clock

    carregarEncomendas("database/encomendas.txt");
    carregarCarrinhas("database/carrinhas.txt");

    std::vector<Encomenda> encomendasDoDiaExpresso = gerarEncomendas(nr); //gerar subset
    std::vector<Encomenda> encomendasExpressoEntregues;
    std::vector<Encomenda> encomendasExpressoNaoEntregues;

    std::cout << std::endl << "Encomendas expresso para este dia:" << std::endl << std::endl;
    gerarTabelaEncomendasDoDia(encomendasDoDiaExpresso);

    std::sort(encomendasDoDiaExpresso.begin(), encomendasDoDiaExpresso.end(), [](Encomenda e1, Encomenda e2){return e1.getDuracao() < e2.getDuracao();}); // ordenar encomendas por duracao decrescente

    int intervaloTempoEntregas = 28800; // das 9:00 as 17:00
    int index = 0;
    while (intervaloTempoEntregas > 0 && index < encomendasDoDiaExpresso.size()){
        intervaloTempoEntregas -= encomendasDoDiaExpresso[index].getDuracao();
        encomendasExpressoEntregues.push_back(encomendasDoDiaExpresso[index]);
        index++;
    }

    for (int i = index; i < encomendasDoDiaExpresso.size(); ++i) {
        encomendasExpressoNaoEntregues.push_back(encomendasDoDiaExpresso[i]); //encomendas nao entregues
    }

    gerarTabelaEncomendasExpressoEntregues(encomendasExpressoEntregues);

    if (encomendasExpressoNaoEntregues.size()){
        std::cout <<std::endl<< "Numero de encomendas nao entregues : " << encomendasExpressoNaoEntregues.size() << std::endl;
    }

    std:: cout << std::endl << "Eficiencia: " << std::setprecision(3) << (float(encomendasDoDiaExpresso.size()-encomendasExpressoNaoEntregues.size())/encomendasDoDiaExpresso.size())*100 << "%" << std::endl;

    //std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now(); //end clock
    //std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;

    if (!encomendasExpressoNaoEntregues.empty()){
        waitEnter(); // pressionar tecla para continuar
        cenario3DiaSeguinte(encomendasExpressoNaoEntregues); //entregar as encomendas que restaram
    }
}

void Empresa::cenario3DiaSeguinte(std::vector<Encomenda> encomendasDoDiaAnterior) {

    std::vector<Encomenda> encomendasExpressoEntregues;
    std::vector<Encomenda> encomendasExpressoNaoEntregues;
    std::vector<Encomenda> encomendasDoDia;
    int nr_encomendas;
    if(!encomendas.empty()){
        std::cout << "Com quantas encomendas pretende simular?" << std::endl << std::endl;
        std::cin >> nr_encomendas;
        std::cin.ignore(9999,'\n');
        encomendasDoDia = gerarEncomendas(nr_encomendas);
    }
    std::cout << std::endl << "----------DIA SEGUINTE----------" << std::endl;
    std::cout << std::endl << "Encomendas expresso para este dia com prioridade:" << std::endl << std::endl;
    gerarTabelaEncomendasDoDia(encomendasDoDiaAnterior);

    std::cout << std::endl << "Encomendas expresso para este dia:" << std::endl << std::endl;
    gerarTabelaEncomendasDoDia(encomendasDoDia);

    std::sort(encomendasDoDia.begin(), encomendasDoDia.end(),
              [](Encomenda e1, Encomenda e2){return e1.getDuracao() < e2.getDuracao();});//ordenar pela duracao

    for (Encomenda &encomenda : encomendasDoDia) {
        encomendasDoDiaAnterior.push_back(encomenda); //juntar os dois vetores dando prioridade ao dia anterior
    }

    int intervaloTempoEntregas = 28800;
    int index = 0;
    while (intervaloTempoEntregas > 0 && index < encomendasDoDiaAnterior.size()){
        intervaloTempoEntregas -= encomendasDoDiaAnterior[index].getDuracao();
        encomendasExpressoEntregues.push_back(encomendasDoDiaAnterior[index]);
        index++;
    }

    for (int i = index; i < encomendasDoDiaAnterior.size(); ++i) {
        encomendasExpressoNaoEntregues.push_back(encomendasDoDiaAnterior[i]); //encomendas nao entregues
    }

    gerarTabelaEncomendasExpressoEntregues(encomendasExpressoEntregues);

    if (encomendasExpressoNaoEntregues.size()){
        std::cout <<std::endl<< "Numero de encomendas nao entregues : " << encomendasExpressoNaoEntregues.size() << std::endl;
    }

    std:: cout << std::endl<<"Eficiencia: " << std::setprecision(3) << (float(encomendasExpressoEntregues.size())/encomendasDoDiaAnterior.size())*100 << "%" << std::endl;

    if (!encomendasExpressoNaoEntregues.empty()){
        waitEnter();
        cenario3DiaSeguinte(encomendasExpressoNaoEntregues);
    }
}

bool Empresa::compararCarrinhasCenario1(Carrinha &lhs, Carrinha &rhs) {
    return lhs.getVolMax()*lhs.getPesoMax() > rhs.getVolMax()*rhs.getPesoMax();
}

bool Empresa::compararEncomendasCenario1(Encomenda &lhs, Encomenda &rhs) {
    return lhs.getVolume()*lhs.getPeso() > rhs.getVolume() * rhs.getPeso();
}

bool Empresa::compararCarrinhasCenario2(Carrinha &lhs, Carrinha &rhs) {
    return (lhs.getVolMax()*lhs.getPesoMax())/lhs.getCusto() > (rhs.getVolMax()*rhs.getPesoMax())/rhs.getCusto();
}

bool Empresa::compararEncomendasCenario2LucroMaximo(Encomenda &lhs, Encomenda &rhs) {
    return lhs.getRecompensa()/(lhs.getVolume()*lhs.getPeso()) > rhs.getRecompensa()/(rhs.getVolume() * rhs.getPeso());
}

bool Empresa::compararEncomendasCenario2LucroEquilibrado(Encomenda &lhs, Encomenda &rhs) {
    return lhs.getRecompensa()*lhs.getVolume()*lhs.getPeso() > rhs.getRecompensa()*rhs.getVolume() * rhs.getPeso();
}


std::vector<Encomenda> Empresa::carregarEncomendasParaCarrinhas(std::vector<Encomenda> encomendasDoDia) {

    std::vector<Encomenda> encomendasNaoEntregues;

    for (Encomenda &encomenda : encomendasDoDia) {
        bool adicionada = false;
        for (Carrinha &carrinha : carrinhas){
            if(encomenda.getVolume()>carrinha.getVolMax()){ //encomenda não cabe mesmo estando carrinha vazia
                break;
            }
            if(carrinha.adicionarEncomenda(encomenda)){
                adicionada = true;          //encomenda adicionada a carrinha
                break;
            }
        }
        if(!adicionada){ //entra aqui se todas as carrinhas estiverem cheias e esta encomenda não couber
            encomendasNaoEntregues.push_back(encomenda);
        }
    }

    return encomendasNaoEntregues;
}

void Empresa::gerarTabelaEncomendasDoDia(const std::vector<Encomenda> &encomendasDoDia) {
    std::cout << "############################################################################" << std::endl;
    std::cout << "#   ID    " << " # " << "    VOLUME    " << " # " << "    PESO    " << " # " << "   DURACAO   " << " # " << "  RECOMPENSA  #" << std::endl;
    std::cout << "############################################################################" << std::endl;
    for (Encomenda e: encomendasDoDia) {
        std::cout << "|" << std::setw(6) << e.getId() << std::setw(6) << " | " << std::setw(9) << e.getVolume() << std::setw(8) << " | " << std::setw(8) << e.getPeso() << std::setw(7) << " | " << std::setw(8) << e.getDuracao() << std::setw(7) << "|" << std::setw(9) << (int)e.getRecompensa() << std::setw(7) << "|" << std::endl;
        std::cout << "+--------------------------------------------------------------------------+" << std::endl;
    }
}

void Empresa::gerarTabelaEncomendasExpressoEntregues (const std::vector<Encomenda> &encomendasExpressoEntregues){

    std::cout << "\nEncomendas expresso entregues no dia de hoje:\n\n";

    int tempo = 32400; //9:00 em segundos

    std::cout << "####################################" << std::endl;
    std::cout << "#   HORA DE ENTREGA    " << " # " << "   ID    #" << std::endl;
    std::cout << "####################################" << std::endl;

    for (Encomenda encomenda : encomendasExpressoEntregues) {
        std::stringstream ss;
        ss <<  std::setfill('0') << std::setw(2) << int(tempo/3600) << ":" << std::setw(2) << int((tempo/60)%60);
        std::cout << "|" << std::setw(13) <<  ss.str() << std::setw(12) << " | " << std::setw(5) << encomenda.getId() << std::setw(5) << "|" << std::endl;
        std::cout << "+----------------------------------+" << std::endl;
        tempo += encomenda.getDuracao();
    }
}

void Empresa::gerarTabelaCarrinhasComCarga(const std::vector<Carrinha> &carrinhas) {
    std::cout << "\nCarrinhas usadas:\n";
    for (Carrinha c : carrinhas) {
        std::cout << std::endl;
        std::cout << "#############################" << std::endl;
        std::cout << "#   ID CARRINHA  :" << std::setw(5) << c.getId() << std::setw(6) << "#" << std::endl;
        std::cout << "#      LUCRO  :   " << std::setw(5) << c.valorCarga() - c.getCusto() << std::setw(6) << "#" << std::endl;
        std::cout << "#############################" << std::endl;
        for (int i = 0; i < c.getCarga().size() - (c.getCarga().size()%3); i+=3){
            std::cout << "|" << std::right << std::setw(4) << ">" << std::left << std::setw(4) << c.getCarga()[i].getId() << std::right << std::setw(4) << ">" << std::left << std::setw(4) << c.getCarga()[i+1].getId() << std::right << std::setw(4) << ">" << std::left << std::setw(4) << c.getCarga()[i+2].getId() << std::right << std::setw(4) << "|" <<std::endl;
        }
        std::cout << "+---------------------------+" << std::endl;
    }
}
void Empresa::gerarTabelaEncomendasNaoEntregues (const std::vector<Encomenda> &encomendasNaoEntregues){
    std::cout << std::endl;
    std::cout << "#################################" << std::endl;
    std::cout << "#  ID ENCOMENDAS NAO ENTREGUES  #" << std::endl;
    std::cout << "#################################" << std::endl;
    for (Encomenda e : encomendasNaoEntregues){
        std::cout << "|" << std::setw(16) << e.getId() << std::setw(16) << "|" << std::endl;
        std::cout << "+-------------------------------+" << std::endl;
    }
}