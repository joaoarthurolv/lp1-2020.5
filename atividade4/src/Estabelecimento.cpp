#include "../include/Estabelecimento.hpp"


Estabelecimento::Estabelecimento(){
}

Estabelecimento::Estabelecimento(const std::string& filename){
    std::string line;
    std::string tipo;
    std::ifstream file_read(filename);
    std::ofstream file_write(filename, std::ios::app);
    
    if (file_read.fail()) {
        std::cout << "Arquivo não encontrado" << std::endl;
    }

    else {
        while(!file_read.eof()){
            Produto p;
            p.nome = "aa";
            getline(file_read,line);

            std::stringstream stream(line);

            std::string delimitador = ",";

            auto start = 0U;
            auto end = line.find(delimitador);
            int index = 0;

            while (end != std::string::npos){
                if (index == 0) {
                    p.codigo = std::stoi(line.substr(start, end - start));
                }

                if (index == 1) {
                    p.nome = line.substr(start, end - start);   
                }
                
                if (index == 2) {
                    p.unidade_medida = line.substr(start, end - start);
                } 

                if (index == 3) {
                    auto start2 = 0U;
                    std::string delimitador2 = " ";
                    auto end2 = line.find(delimitador2);

                    while (end2 != std::string::npos){
                        start2 = end2 + delimitador2.length();
                        end2 = line.find(delimitador2, start2);
                    }
                    std::string line2 = line.substr(start2, end2 - start2);
                    std::size_t aspas = line2.find("\"");

                    double preco = std::stod(line2.substr(0, aspas));

                    p.preco = preco;
                }
                start = end + delimitador.length();
                end = line.find(delimitador, start);
                index++;
            }

            produtos.push_back(p);
        }
    }
    
}

Produto Estabelecimento::procurarProduto(int codigo){
    for(auto const& i: this->produtos){
        if (i.codigo == codigo) {
            return i;
        }
    }
}

Estabelecimento::~Estabelecimento(){

}

void Estabelecimento::listar(){

    for(auto const& i: this->produtos){
        std::cout << "Código: " << i.codigo << std::endl;
        std::cout << "Nome: " << i.nome << std::endl;
        std::cout << "Preço: R$ " << i.preco << std::endl;
        std::cout << "Unidade de medida: " << i.unidade_medida << std::endl;
        std::cout << "----------------------" << std::endl;
    }

}

void Estabelecimento::venda(int codigo){

}

void Estabelecimento::caixa(){

}