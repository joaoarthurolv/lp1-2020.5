#include <iostream>
#include <string>

int main(int argc, char *argv[]){
    std::string arg = "add";

    if(argc == 1){
        std::cout << "Uso: " << argv[0] << " add <mensagem>" << std::endl;
        return -1;
    }

    std::string action = argv[1];

    if(action != "add"){
        std::cout << "Uso: " << argv[0] << " add <mensagem>" << std::endl;
        return -1;
    }
    
    std::string mensagem;

    if(argc == 2){
        std::cout << "Informe a mensagem a ser impressa: " << std::endl;
        std::cin >> mensagem; 
    }
    else{
        mensagem = argv[2];
    }

    std::cout << "Mensagem adicionada!" << std::endl;
}