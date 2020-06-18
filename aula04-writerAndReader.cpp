#include <iostream>
#include <string>
#include <fstream>

void show_usage(std::string const prog_name);
void adicionarMensagem(int qtdParametros, std::string mensagem, std::ofstream &file);
void listar(std::ifstream &file);

int main(int argc, char *argv[]){
    std::ifstream file_read("arquivo.txt"); 
    std::ofstream file_write("arquivo.txt", std::ios::app);

    if(argc == 1){
        show_usage(argv[0]);
        return -1;
    }

    std::string action = argv[1];

    if(action != "add" && action != "list") {
        show_usage(argv[0]);
    }

    if(action == "add"){
        std::string mensagem = (argv[2]) ? argv[2] : "";
        adicionarMensagem(argc, mensagem, file_write); 
    }

    if(action == "list"){
        listar(file_read);
    }

    return 0;
}

void show_usage(std::string const prog_name){
    std::cout << "Usos: " << std::endl;
    std::cout << "1. " << prog_name << " add <mensagem>" << std::endl;
    std::cout << "2. " << prog_name << " list " << std::endl;
}

void adicionarMensagem(int qtdParametros, std::string mensagem, std::ofstream &file){
    
    if(file.fail()){
        std::cout << "Arquivo não encontrado." << std::endl;
    }

    if(qtdParametros == 2){
        std::cout << "Informe a mensagem a ser adicionada: " << std::endl;
        std::getline(std::cin, mensagem);
    }

    file << mensagem << std::endl;
    std::cout << "Mensagem adicionada!" << std::endl;
}

void listar(std::ifstream &file){

    if(!file.is_open()){
        std::cerr << "Arquivo não existente ou sem permissão de acesso." << std::endl;
    }

    int line_number = 0;
    std::string message;

    //eof -> end of file
    while(!file.eof()){
        ++line_number;
        std::getline(file, message);
        
        if (message.size() == 0){
            continue;
        }
        std::cout << line_number << ". " << message << std::endl;
    }
}