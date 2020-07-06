#include "../include/Conta.hpp"

#include <iostream>

int main(int argc, char* argv[]){

    Conta a;
    Conta b;

    a.numero = 123;
    a.titular = "João";
    a.saldo = 0.0;

    b.numero = 321;
    b.titular = "Pedro";
    b.saldo = 20;

    std::cout << "Numero da conta: " << a.numero << std::endl;
    std::cout << "Nome do titular: " << a.titular << std::endl;
    std::cout << "Saldo atual: R$ " << a.saldo << std::endl;

    std::cout << "---------------" << std::endl;

    std::cout << "Numero da conta: " << b.numero << std::endl;
    std::cout << "Nome do titular: " << b.titular << std::endl;
    std::cout << "Saldo atual: R$ " << b.saldo << std::endl;

    a.deposita(100);
    a.transfere(50, b);
    a.saca(20);


    std::cout << "\nDepois das transações: \n" << std::endl;
    
    std::cout << "Numero da conta: " << a.numero << std::endl;
    std::cout << "Nome do titular: " << a.titular << std::endl;
    std::cout << "Saldo atual: R$ " << a.saldo << std::endl;

    std::cout << "---------------" << std::endl;

    std::cout << "Numero da conta: " << b.numero << std::endl;
    std::cout << "Nome do titular: " << b.titular << std::endl;
    std::cout << "Saldo atual: R$ " << b.saldo << std::endl;

    return 0;
}