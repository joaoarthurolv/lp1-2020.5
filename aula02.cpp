#include <iostream>
#include <string>

int main(int argc, char *argv[]){
    std::string arg = "add";

    if(argc == 1){
        std::cout << "Uso: " << argv[0] << " add <mensagem>" << std::endl;
        return -1;
    }

    if(argc == 2 && arg.compare(argv[1]) == 0){
        std::string mensagem;

        std::cout << arg.compare(argv[1]);
        std::cout << "Informe a mensagem a ser impressa: " << std::endl;
        std::cin >> mensagem;

        std::cout << mensagem << std::endl; 
    }

    if(argc == 3 && arg.compare(argv[1]) == 0){
        std::cout << argv[2] << std::endl;
    }

    else{
        return -1;
    }
}