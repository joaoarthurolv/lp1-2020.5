#ifndef CONFIG_FILE_H
#define CONFIG_FILE_H

#include <iostream>
#include <string>
#include <fstream>

struct ConfigFile {
    ConfigFile();

    std::string nome_diario(const std::string& filename);
};

#endif