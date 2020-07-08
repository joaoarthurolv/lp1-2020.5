#include <string>
#include "Motor.hpp"

using namespace std;

class Carro{
    public:
    string tipo;
    string placa;
    int numPortas;
    int velocidade;
    string cor;
    Motor motor;
    static int quantidade_carros;

    Carro(string cor);
    Carro();

    void acelera(int velocidade);
    void freia(int velocidade);
    void ligaCarro();
};
