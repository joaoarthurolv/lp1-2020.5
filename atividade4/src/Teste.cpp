#include <iostream>

#include "../include/Estabelecimento.hpp"

#include <string>
#include <vector>

int main(int argc, char* argv[]){
    Estabelecimento e1("estoque.csv");
    Cliente c;
    int escolha;

    while(escolha != 0){
        std::cout << "        SUPERMERCADO " << std::endl;
        std::cout << " --------------------------- " << std::endl;
        std::cout << " 1. Verificar produtos " << std::endl;
        std::cout << " 2. Adicionar saldo ao cliente " << std::endl;
        std::cout << " 3. Adicionar produto à sacola " << std::endl;
        std::cout << " 4. Ver sacola " << std::endl;
        std::cout << " 0. Encerrar programa " << std::endl;
        std::cin >> escolha;

        if (escolha == 1) {
            e1.listar();
        }

        if (escolha == 2) {
            double valor;
            std::cin >> valor;
            c.adicionarSaldo(valor);
        }

        if (escolha == 3) {
            int codigo;
            std::cout << "Digite o código do produto " << std::endl;
            std::cin >> codigo;

            Produto produto = e1.procurarProduto(codigo);
            std::cout << produto.nome << std::endl;
            c.saldo -= produto.preco;
            c.sacola.push_back(produto);
        }

        if (escolha == 4) {
            c.verSacola();
        }
    }
    
}