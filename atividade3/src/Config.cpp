#include "../include/Config.h"

Config::Config()
{

}

std::string Config::nome_diario(const std::string& filename){
    std::string line = "";
    std::ifstream file_read(filename); 
    std::ofstream file_write(filename, std::ios::app);

    if (file_read.fail()) {
       std::cout << "Arquivo leitura não encontrado!"  << std::endl;
    }

    if (file_write.fail()) {
            std::cout << "Arquivo escrita não encontrado!"  << std::endl;
        }

    else {
        bool empty = fileIsEmpty(file_read);

        if (empty) {
            std::cout << fileIsEmpty(file_read) << std::endl;
            file_write << "path=" << "/home/joaoarthur/lp1-2020.5/atividade3/diary.md" << std::endl;
            file_write << "default_format=" << "[%d %t] %m" << std::endl;
        }

        else {

        }
        
    }
    std::string path = findDiaryPath(file_read);
    //std::cout << path << std::endl;
    return path;
}

bool Config::fileIsEmpty(std::ifstream &file){
    std::string line = "";
    bool valor;

    while(!file.eof()){

        getline(file,line);
        
        if (line.size() == 0) {
            valor = true;
        }

        else {
            valor = false;
            break;
        }
    }

    return valor;
}

std::string Config::findDiaryPath(std::ifstream &file){
    std::string line = "";
    std::string tipo = "";
    std::string path = "";

    // Código para a leitura do arquivo de configuração voltar ao seu início.
    file.clear();
    file.seekg(0, std::ios::beg);

    while(!file.eof()){
        
        getline(file,line);

        std::stringstream stream(line);

        stream >> tipo;
        if(tipo.compare("path=") == 0){
                stream >> path;
        }

        else {
            
        }
    }

    return path;
}
