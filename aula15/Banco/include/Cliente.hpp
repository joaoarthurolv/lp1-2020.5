#include <string>

class Cliente{
    public:
    std::string nome;
    std::string cpf;
    static int quantidade_clientes;

    Cliente();
    ~Cliente();
};