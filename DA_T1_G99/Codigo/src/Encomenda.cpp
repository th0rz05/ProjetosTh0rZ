//
// Created by Tiago Barbosa on 07/04/2022.
//

#include "Encomenda.h"

Encomenda::Encomenda() {
    volume = 0;
    peso = 0;
    recompensa = 0;
    duracao = 0;
    id = 0;
}


Encomenda::Encomenda(float volume, float peso, float recompensa, int duracao, int id) : volume(volume), peso(peso),
                                                                          recompensa(recompensa), duracao(duracao), id(id) {}

float Encomenda::getVolume() const {
    return volume;
}

void Encomenda::setVolume(float volume) {
    Encomenda::volume = volume;
}

float Encomenda::getPeso() const {
    return peso;
}

void Encomenda::setPeso(float peso) {
    Encomenda::peso = peso;
}

float Encomenda::getRecompensa() const {
    return recompensa;
}

void Encomenda::setRecompensa(float recompensa) {
    Encomenda::recompensa = recompensa;
}

int Encomenda::getDuracao() const {
    return duracao;
}

void Encomenda::setDuracao(int duracao) {
    Encomenda::duracao = duracao;
}

int Encomenda::getId() const {
    return id;
}

void Encomenda::setId(int id) {
    Encomenda::id = id;
}

std::ostream &operator<<(std::ostream &os, const Encomenda &encomenda) {
    os << "id: " << encomenda.id << " volume: " << encomenda.volume << " peso: " << encomenda.peso << " recompensa: " << encomenda.recompensa
       << " duracao: " << encomenda.duracao;
    return os;
}

bool Encomenda::operator==(const Encomenda &rhs) const {
    return volume == rhs.volume &&
           peso == rhs.peso &&
           recompensa == rhs.recompensa &&
           duracao == rhs.duracao &&
           id == rhs.id;
}
