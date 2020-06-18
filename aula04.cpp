#include <iostream>
#include <string>
#include <fstream>

void show_usage(std::string const prog_name);

int main(int argc, char *argv[]){
    // std::ifstream file("arquivo.txt");
    std::ifstream file;

    file.open("arquivo.txt");

    if(!file.is_open()){
        std::cerr << "Arquivo não existente ou sem permissão de acesso." << std::endl;
        return 1;
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

    file.close();

    return 0;
}
