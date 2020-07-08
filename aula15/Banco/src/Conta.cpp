#include "../include/Conta.hpp"

int Conta::quantidade_contas;

Conta::Conta(){
    this->quantidade_contas += 1;
}

void Conta::saca(double valor){
    this->saldo -= valor;
}

void Conta::deposita(double valor){
    this->saldo += valor;
}

void Conta::transfere(double valor, Conta &c){
    this->saldo -= valor;
    c.saldo += valor;
}