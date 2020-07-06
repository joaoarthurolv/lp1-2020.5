#include <string>

class Conta{
    public:
    int numero;
    std::string titular;
    double saldo;

    void saca(double valor);
    void deposita(double valor);
    void transfere(double valor, Conta &c);
};