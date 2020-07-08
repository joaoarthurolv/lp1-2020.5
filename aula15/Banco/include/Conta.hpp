#include <string>
#include "Cliente.hpp"
#include "Agencia.hpp"

class Conta{
    public:
    int numero;
    Agencia agencia;
    Cliente titular;
    double saldo;
    static int quantidade_contas;

    Conta();

    void saca(double valor);
    void deposita(double valor);
    void transfere(double valor, Conta &c);
};