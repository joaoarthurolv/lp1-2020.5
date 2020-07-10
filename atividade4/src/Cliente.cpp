#include "../include/Cliente.hpp"

int Cliente::quantidade_clientes;

Cliente::Cliente(){
    this->quantidade_clientes += 1;
};

Cliente::~Cliente(){};

Cliente::Cliente(double saldo){
    this->saldo = saldo;
    this->quantidade_clientes += 1;
}

void Cliente::compra(Produto& produto, double preco){

}

void Cliente::verSacola(){
    for(auto const& i: this->sacola){
        std::cout << "Código: " << i.codigo << std::endl;
        std::cout << "Nome: " << i.nome << std::endl;
        std::cout << "Preço: R$ " << i.preco << std::endl;
        std::cout << "Unidade de medida: " << i.unidade_medida << std::endl;
        std::cout << "----------------------" << std::endl;
    }
}

void Cliente::registro(){

}

void Cliente::adicionarSaldo(double valor){
    this->saldo += valor;   
}