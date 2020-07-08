#include "../include/Conta.hpp"
#include <iostream>

int main(int argc, char* argv[]){
    
    Conta a;
    std::cout << a.quantidade_contas << std::endl;
    Conta b;
    std::cout << a.quantidade_contas << std::endl;
    Conta c;
    std::cout << a.quantidade_contas << std::endl;

    Agencia ag;
    Cliente cl1;
    std::cout << cl1.quantidade_clientes << std::endl;
    Cliente cl2;
    std::cout << cl1.quantidade_clientes << std::endl;
    Cliente cl3;
    std::cout << cl1.quantidade_clientes << std::endl;

    ag.nome = "Agência 1";
    ag.numero = 444;

    cl1.nome = "João";
    cl1.cpf = "123.456.789-10";

    cl2.nome = "Arthur";
    cl2.cpf = "222.222.222-22";

    cl3.nome = "Victor";
    cl3.cpf = "999.999.999-99";

    a.numero = 123;
    a.saldo = 0;
    a.titular = cl1;
    a.agencia = ag;

    b.numero = 222;
    b.saldo = 50;
    b.titular = cl2;
    b.agencia = ag;

    c.numero = 999;
    c.saldo = 2900;
    c.titular = cl3;
    c.agencia = ag;

    std::cout << "Dados da conta: \n" << std::endl;
    std::cout << "Titular: " << a.titular.nome << std::endl;
    std::cout << "Conta: " << a.numero << std::endl;
    std::cout << "Agência: " << a.agencia.numero << std::endl;
    std::cout << "Saldo atual: R$ " << a.saldo << std::endl;

    std::cout << "\nDados da conta: \n" << std::endl;
    std::cout << "Titular: " << b.titular.nome << std::endl;
    std::cout << "Conta: " << b.numero << std::endl;
    std::cout << "Agência: " << b.agencia.numero << std::endl;
    std::cout << "Saldo atual: R$ " << b.saldo << std::endl;

    std::cout << "\nDados da conta: \n" << std::endl;
    std::cout << "Titular: " << c.titular.nome << std::endl;
    std::cout << "Conta: " << c.numero << std::endl;
    std::cout << "Agência: " << c.agencia.numero << std::endl;
    std::cout << "Saldo atual: R$ " << c.saldo << std::endl;

    std::cout << "Quantidade de contas: " << a.quantidade_contas << std::endl;
    std::cout << "Quantidade de clientes: " << cl1.quantidade_clientes << std::endl;
    return 0;
}