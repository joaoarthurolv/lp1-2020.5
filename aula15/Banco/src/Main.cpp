#include "../include/Conta.hpp"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]){

    Cliente clC;
    Cliente clD;

    cout << "Quantidade de clientes: " << clC.quantidade_clientes << endl;

    clC.nome = "João";
    clD.nome = "Maria";

    Conta c(clC);
    Conta d(clD);
    Conta e(d);

    cout << "Titular da conta C: " << c.titular.nome << endl;
    cout << "Titular da conta D: " << d.titular.nome << endl;
    cout << "Titular da conta E: " << e.titular.nome << endl;
    c.saldo = 20;
    c.saca(15);

    cout << "Saldo da conta C: " << c.saldo << endl;

    c.deposita(50);
    c.transfere(45, d);

    cout << "Saldo da conta C: " << c.saldo << endl;
    cout << "Saldo da conta D: " << d.saldo << endl;
    cout << "Quantidade de contas: " << c.quantidade_contas << endl;
    cout << "Quantidade de clientes: " << clC.quantidade_clientes << endl;

    return 0;
}