//
// Created by Tiago Barbosa on 07/04/2022.
//

#ifndef PROJETO_DA_CARRINHA_H
#define PROJETO_DA_CARRINHA_H


#include <ostream>
#include "Encomenda.h"
#include <vector>

class Carrinha {
private:
    float volMax;
    float pesoMax;
    float custo;
    int id;
    std::vector<Encomenda> carga;
    float volRestante;
    float pesoRestante;
public:
    /**
     * Cria uma carrinha vazia
     */
    Carrinha();

    /**
     * Cria uma carrinha sem carga
     * @param volMax
     * @param pesoMax
     * @param custo
     * @param id
     */
    Carrinha(float volMax, float pesoMax, float custo, int id);

    /**
     * Obtém o volume máximo da carrinha
     * @return volume
     */
    float getVolMax() const;

    /**
     * Altera o volume máximo da carrinha
     * @param volMax Novo volume
     */
    void setVolMax(float volMax);

    /**
     * Obtém o peso máximo da carrinha
     * @return peso
     */
    float getPesoMax() const;

    /**
     * Altera o peso máximo da carrinha
     * @param pesoMax Novo peso
     */
    void setPesoMax(float pesoMax);

    /**
     * Obtém o custo diário da carrinha
     * @return custo
     */
    float getCusto() const;

    /**
     * Altera o custo diário da carrinha
     * @param custo Novo custo
     */
    void setCusto(float custo);

    /**
     * Obtém o id da carrinha
     * @return id
     */
    int getId() const;

    /**
     * Altera o id da carrinha
     * @param id Novo id
     */
    void setId(int id);

    /**
     * Obtém a carga da carrinha
     * @return vetor representativo da carga
     */
    std::vector<Encomenda> &getCarga();

    /**
     * Altera a carga da carrinha
     * @param carga Vetor com a nova carga
     */
    void setCarga(const std::vector<Encomenda> &carga);

    /**
     * Obtém o volume por ocupar na carrinha
     * @return volume
     */
    float getVolRestante() const;

    /**
     * Obtém o peso por ocupar na carrinha
     * @return peso
     */
    float getPesoRestante() const;

    /**
     * Mostra os dados da carrinha
     * @param os Stream que irá receber os dados da carrinha
     * @param carrinha Carrinha a apresentar
     * @return stream que recebeu os dados
     */
    friend std::ostream &operator<<(std::ostream &os, const Carrinha &carrinha);

    /**
     * Adiciona uma encomenda à carga da carrinha
     * @param encomenda Encomenda a adicionar
     * @return true se for possível adicionar e false caso não seja
     */
    bool adicionarEncomenda(const Encomenda &encomenda);

    /**
     * Verifica se uma carrinha tem carga ou não
     * @return true se tiver carga e false se não
     */
    bool usada() const;

    /**
     * Obtém o valor da carga da carrinha
     * @return valor monetário
     */
    float valorCarga() const;
};


#endif //PROJETO_DA_CARRINHA_H
