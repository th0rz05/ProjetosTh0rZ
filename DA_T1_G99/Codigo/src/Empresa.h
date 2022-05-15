//
// Created by Tiago Barbosa on 07/04/2022.
//

#ifndef PROJETO_DA_EMPRESA_H
#define PROJETO_DA_EMPRESA_H


#include "Carrinha.h"
#include <string>
#include <ctime>
#include <algorithm>

class Empresa {
private:
    std::vector<Carrinha> carrinhas;
    std::vector<Encomenda> encomendas;

public:
    /**
     * Cria uma empresa vazia
     */
    Empresa();

    /**
     * Carrega a partir de um ficheiro as encomendas
     * @param file ficheiro com os dados
     */
    void carregarEncomendas(std::string file);

    /**
     * Carregar a partir de um ficheiro as carrinhas
     * @param file ficheiro com os dados
     */
    void carregarCarrinhas(std::string file);

    /**
     * Gera um subset com um número de encomendas
     * @param nr Número de encomendas a gerar
     * @return vetor com as encomendas geradas
     */
    std::vector<Encomenda>  gerarEncomendas(int nr) ;

    /**
     * Compara as carrinhas pelo peso x volume por ordem decrescente
     * @param lhs primeira carrinha a comparar
     * @param rhs segunda carrinha a comparar
     * @return true se a primeira for maior e false se não for
     */
    static bool compararCarrinhasCenario1( Carrinha &lhs,  Carrinha &rhs);

    /**
     * Compara as encomendas pelo peso x volume por ordem decrescente
     * @param lhs primeira encomenda a comparar
     * @param rhs segunda encomenda a comparar
     * @return true se a primeira for maior e false se não for
     */
    static bool compararEncomendasCenario1( Encomenda &lhs,  Encomenda &rhs);

    /**
     * Compara as carrinhas pelo (peso x volume)/custo por ordem decrescente
     * @param lhs primeira carrinha a comparar
     * @param rhs segunda carrinha a comparar
     * @return true se a primeira for maior e false se não for
     */
    static bool compararCarrinhasCenario2( Carrinha &lhs,  Carrinha &rhs);

    /**
     * Compara as encomendas pelo recompensa/(peso x volume) por ordem decrescente
     * @param lhs primeira encomenda a comparar
     * @param rhs segunda encomenda a comparar
     * @return true se a primeira for maior e false se não for
     */
    static bool compararEncomendasCenario2LucroMaximo( Encomenda &lhs,  Encomenda &rhs);

    /**
     * Compara as encomendas pelo recompensa x peso x volume por ordem decrescente
     * @param lhs primeira encomenda a comparar
     * @param rhs segunda encomenda a comparar
     * @return true se a primeira for maior e false se não for
     */
    static bool compararEncomendasCenario2LucroEquilibrado( Encomenda &lhs,  Encomenda &rhs);

    /**
     * Carregar as encomendas do dia para as carrinhas
     * @param encomendasDoDia Encomendas a entregar
     * @return vetor de encomendas não entregues
     */
    std::vector<Encomenda>  carregarEncomendasParaCarrinhas(std::vector<Encomenda> encomendasDoDia);

    /**
     * Simula o cenário 1 do enunciado (minimizar estafetas)
     * @param nr Número de encomendas a gerar
     */
    void cenario1(int nr);

    /**
     * Simula o cenário 2 do enunciado (maximizar lucro)
     * @param nr Número de encomendas a gerar
     * @param opcao Opção para definir o modo de maximização do lucro
     */
    void cenario2(int nr,int opcao);

    /**
     * Simula o cenário 3 do enunciado (otimizar entregas expresso)
     * @param nr Número de encomendas a gerar
     */
    void cenario3(int nr);

    /**
     * Simula quando sobra encomendas do cenário 3 e passam para o dia seguinte
     * @param encomendasDoDiaSeguinte Encomendas que sobraram do dia anterior
     */
    void cenario3DiaSeguinte(std::vector<Encomenda> encomendasDoDiaAnterior);

    /**
     * Obtém as carrinhas da empresa
     * @return vetor com as carrinhas
     */
    const std::vector<Carrinha> &getCarrinhas() const;

    /**
     * Alterar as carrinhas da empresa
     * @param carrinhas Novas carrinhas
     */
    void setCarrinhas(const std::vector<Carrinha> &carrinhas);

    /**
     * Obtém as encomendas da empresa
     * @return vetor com as encomendas
     */
    const std::vector<Encomenda> &getEncomendas() const;

    /**
     * Alterar as encomendas da empresa
     * @param encomendas Novas encomendas
     */
    void setEncomendas(const std::vector<Encomenda> &encomendas);

    /**
     * Gera uma tabela para mostrar as encomendas planeadas para entrega no dia
     * @param encomendasDoDia Encomendas a entregar
     */
    void gerarTabelaEncomendasDoDia(const std::vector<Encomenda> &encomendasDoDia);

    /**
     * Gera uma tabela para mostrar as encomendas expresso entregues no dia
     * @param encomendasExpressoEntregues Encomendas entregues
     */
    void gerarTabelaEncomendasExpressoEntregues (const std::vector<Encomenda> &encomendasExpressoEntregues);

    /**
     * Gera uma tabela para mostrar as carrinhas usadas e a respetiva carga
     * @param carrinhas Carrinhas usadas
     */
    void gerarTabelaCarrinhasComCarga(const std::vector<Carrinha> &carrinhas);

    /**
     * Gera uma tabela para mostrar as encomendas que não foram entregues
     * @param encomendasNaoEntregues Encomendas não entregues
     */
    void gerarTabelaEncomendasNaoEntregues(const std::vector<Encomenda> &encomendasNaoEntregues);

};


#endif //PROJETO_DA_EMPRESA_H
