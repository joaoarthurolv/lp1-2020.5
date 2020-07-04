#include "../include/ConfigFile.h"

ConfigFile::ConfigFile()
{

}

std::string nome_diario(std::string &filename){
    std::string line = "";
    std::ifstream file_read("diary.config"); 

    if (file_read.fail()) {
        std::cout << "Arquivo não encontrado!"  << std::endl;
    }

    else {
        std::ofstream file_write(filename, std::ios::app);

        if (file_write.fail()) {
            std::cout << "Arquivo não encontrado!"  << std::endl;
        }

        file_write << "path=" << "/home/joaoarthur/lp1-2020.5/atividade3/diary.md" << std::endl;
        file_write << "default_format=" << "[%d %t] %m" << std::endl;

    }
    
    while(!file_read.eof()){

        getline(file_read,line);
        
        if (line.find("path") != std::string::npos) {
            std::cout << line << std::endl;
            break;
        }

        else{

        }
    }

    return line;
}

