//
// Created by Tiago Barbosa on 07/04/2022.
//

#include "Carrinha.h"

Carrinha::Carrinha() {
    volMax = 0;
    pesoMax = 0;
    custo = 0;
    id =0;
    pesoRestante = 0;
    volRestante = 0;
}

Carrinha::Carrinha(float volMax, float pesoMax, float custo,int id) : volMax(volMax), pesoMax(pesoMax), custo(custo), id(id) {
    pesoRestante = pesoMax;
    volRestante = volMax;
}

float Carrinha::getVolMax() const {
    return volMax;
}

void Carrinha::setVolMax(float volMax) {
    Carrinha::volMax = volMax;
}

float Carrinha::getPesoMax() const {
    return pesoMax;
}

void Carrinha::setPesoMax(float pesoMax) {
    Carrinha::pesoMax = pesoMax;
}

float Carrinha::getCusto() const {
    return custo;
}

void Carrinha::setCusto(float custo) {
    Carrinha::custo = custo;
}

int Carrinha::getId() const {
    return id;
}

void Carrinha::setId(int id) {
    Carrinha::id = id;
}

std::vector<Encomenda> &Carrinha::getCarga(){
    return carga;
}

void Carrinha::setCarga(const std::vector<Encomenda> &carga) {
    Carrinha::carga = carga;
}

float Carrinha::getVolRestante() const {
    return volRestante;
}

float Carrinha::getPesoRestante() const {
    return pesoRestante;
}

std::ostream &operator<<(std::ostream &os, const Carrinha &carrinha) {
    os <<"id: " << carrinha.id << " volMax: " << carrinha.volMax << " pesoMax: " << carrinha.pesoMax << " custo: " << carrinha.custo;
    return os;
}

bool Carrinha::adicionarEncomenda(const Encomenda &encomenda) {
    if(encomenda.getVolume()<=volRestante && encomenda.getPeso()<=pesoRestante){
        carga.push_back(encomenda);
        volRestante -= encomenda.getVolume();
        pesoRestante -= encomenda.getPeso();
        return true;
    }

    return false;
}

bool Carrinha::usada() const {
    return carga.size()>0;
}

float Carrinha::valorCarga() const{
    float valor = 0;
    for (Encomenda encomenda : carga){
        valor+= encomenda.getRecompensa();
    }
    return valor;
}
