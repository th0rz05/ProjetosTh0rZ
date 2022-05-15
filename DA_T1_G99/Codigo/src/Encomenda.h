//
// Created by Tiago Barbosa on 07/04/2022.
//

#ifndef PROJETO_DA_ENCOMENDA_H
#define PROJETO_DA_ENCOMENDA_H


#include <ostream>

class Encomenda {
private:
    float volume;
    float peso;
    float recompensa;
    int duracao;
    int id;
public:
    /**
     * Cria uma encomenda vazia
     */
    Encomenda();

    /**
     * Cria uma encomenda
     * @param volume
     * @param peso
     * @param recompensa
     * @param duracao
     * @param id
     */
    Encomenda(float volume, float peso, float recompensa, int duracao, int id);

    /**
     * Obtém o volume da encomenda
     * @return volume
     */
    float getVolume() const;

    /**
     * Altera o volume da encomenda
     * @param volume Novo volume
     */
    void setVolume(float volume);

    /**
     * Obtém o peso da encomenda
     * @return peso
     */
    float getPeso() const;

    /**
     * Altera o peso da encomenda
     * @param peso Novo peso
     */
    void setPeso(float peso);

    /**
     * Obtém a recompensa da entrega da encomenda
     * @return recompensa
     */
    float getRecompensa() const;

    /**
     * Altera a recompensa da entrega da encomenda
     * @param recompensa Nova recompensa
     */
    void setRecompensa(float recompensa);

    /**
     * Obtém a duração da entrega da encomenda
     * @return duração
     */
    int getDuracao() const;

    /**
     * Altera a duração da entrega da encomenda
     * @param duração Nova duração
     */
    void setDuracao(int duracao);

    /**
     * Obtém o id da encomenda
     * @return id
     */
    int getId() const;

    /**
     * Altera o id da encomenda
     * @param id Novo id
     */
    void setId(int id);

    /**
     * Mostra os dados da encomenda
     * @param os Stream que irá receber os dados da encomenda
     * @param encomenda Encomenda a apresentar
     * @return stream que recebeu os dados
     */
    friend std::ostream &operator<<(std::ostream &os, const Encomenda &encomenda);

    /**
     * Verifica se outra encomenda é igual a esta
     * @param rhs Encomenda a comparar
     * @return true se forem iguais e false se não
     */
    bool operator==(const Encomenda &rhs) const;
};


#endif //PROJETO_DA_ENCOMENDA_H
