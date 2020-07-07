#include "../include/Conta.hpp"
#include <iostream>

int main(int argc, char* argv[]){

    Conta a;
    Agencia ag;
    Cliente cl1;

    ag.nome = "Agência 1";
    ag.numero = 444;

    cl1.nome = "João";
    cl1.cpf = "123.456.789-10";

    a.numero = 123;
    a.saldo = 0;
    a.titular = cl1;
    a.agencia = ag;

    std::cout << "Dados da conta: \n" << std::endl;
    std::cout << "Titular: " << a.titular.nome << std::endl;
    std::cout << "Conta: " << a.numero << std::endl;
    std::cout << "Agência: " << a.agencia.numero << std::endl;
    std::cout << "Saldo atual: R$ " << a.saldo << std::endl;
    return 0;
}