#ifndef CONFIG_FILE_H
#define CONFIG_FILE_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

struct Config {

    Config();

    std::string nome_diario(const std::string& filename);
    bool fileIsEmpty(std::ifstream &file);
    std::string findDiaryPath(std::ifstream &file);

};

#endif