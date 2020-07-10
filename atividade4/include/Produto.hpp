#include <string>

class Produto{
    public:
    int codigo;
    std::string nome;
    std::string unidade_medida;
    double preco;

    Produto();
    ~Produto();
};