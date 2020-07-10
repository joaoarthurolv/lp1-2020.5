#include <string>
#include <vector>
#include <iostream>

#include "Produto.hpp"

class Cliente{
    public:
    int codigo;
    double saldo;
    std::vector<Produto> sacola;
    static int quantidade_clientes;

    Cliente();
    Cliente(double saldo);
    ~Cliente();

    void compra(Produto& produto, double preco);
    void verSacola();
    void registro();
    void adicionarSaldo(double valor);
};