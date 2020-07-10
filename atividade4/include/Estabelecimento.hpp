#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Cliente.hpp"

class Estabelecimento {
    public:
    std::vector<Produto> produtos;
    std::vector<Cliente> clientes;
    
    Estabelecimento();
    Estabelecimento(const std::string& filename);
    ~Estabelecimento();

    void listar();
    void venda(int codigo);
    void caixa();
    Produto procurarProduto(int codigo);
};