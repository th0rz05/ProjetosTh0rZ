
#include <iostream>
#include "src/Empresa.h"

int main() {
    Empresa empresa;
    int opcao,opcao2,opcao3,nr_encomendas;
    std::cout << "1 - Simular a entrega de encomendas normais" << std::endl;
    std::cout << "2 - Simular a entrega de encomendas expresso" << std::endl << std::endl;
    std::cin >> opcao;
    std::cout << std::endl;
    switch(opcao){
        case 1 : {
            std::cout << "1 - Minimizar o numero de estafetas usados" << std::endl;
            std::cout << "2 - Maximizar o lucro da empresa" << std::endl << std::endl;
            std::cin >> opcao2;
            std::cout << std::endl;
            std::cout << "Com quantas encomendas pretende simular?" << std::endl << std::endl;
            std::cin >> nr_encomendas;
            std::cout << std::endl;
            switch(opcao2){
                case 1: {
                    empresa.cenario1(nr_encomendas);
                }break;
                case 2: {
                    std::cout << "1 - Maximizar o lucro total (podendo ficar muitas encomendas por entregar)" << std::endl;
                    std::cout << "2 - Maximizar o lucro total (entregando o maior numero de encomendas)" << std::endl << std::endl;
                    std::cin >> opcao3;
                    std::cout << std::endl;
                    empresa.cenario2(nr_encomendas,opcao3);
                }break;
                default: std::cout << "Input invalido" << std::endl;
            }
        }break;
        case 2 : {
            std::cout << "Com quantas encomendas pretende simular?" << std::endl << std::endl;
            std::cin >> nr_encomendas;
            std::cout << std::endl;
            std::cin.ignore(9999,'\n');
            empresa.cenario3(nr_encomendas);
        }break;
        default: std::cout << "Input invalido" << std::endl;
    }
    return 0;
}
