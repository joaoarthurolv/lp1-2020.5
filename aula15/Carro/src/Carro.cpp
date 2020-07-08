#include "../include/Carro.hpp"

int Carro::quantidade_carros;

Carro::Carro(string cor){
    this->cor = cor;
    this->quantidade_carros += 1;
}

Carro::Carro(){
    this->cor = "Branco";
    this->quantidade_carros += 1;
}

void Carro::acelera(int velocidade){
    this->velocidade += velocidade;
}

void Carro::freia(int velocidade){
    this->velocidade -= velocidade;
}

void Carro::ligaCarro(){
    motor.partida();
}
