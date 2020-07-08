#include <iostream>
#include "../include/Carro.hpp"

using namespace std;

int main(){
    Carro c;
    c.tipo = "Sedan";
    c.numPortas = 4;
    c.placa = "XYZ-0102";

    Carro d("Vermelho");
    d.tipo = "Hatch";
    d.numPortas = 2;
    d.placa = "MZH-1234";

    cout << "Tipo do carro: " << c.tipo << endl;
    cout << "Quantidade de portas: " << c.numPortas << endl;
    cout << "Placa do carro: " << c.placa << endl;
    cout << "A cor do carro é: " << c.cor << endl;

    cout << "\nTipo do carro: " << d.tipo << endl;
    cout << "Quantidade de portas: " << d.numPortas << endl;
    cout << "Placa do carro: " << d.placa << endl;
    cout << "A cor do carro é: " << d.cor << endl;

    c.ligaCarro();
    c.acelera(50);
    cout << "\nA velocidade atual é: " << c.velocidade << "KM/H" << endl;
    c.freia (20);
    cout << "A velocidade atual é: " << c.velocidade << "KM/H\n" << endl;

    cout << "A quantidade de carros é: " << c.quantidade_carros << endl;

    return 0;
}
