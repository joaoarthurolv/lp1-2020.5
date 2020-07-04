#ifndef DIARY_H
#define DIARY_H

#include "Message.h"

#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

struct Diary {

    Diary(const std::string& filename);
    std::string filename;
    std::vector<Message> messages;

    void add(const std::string& message);
    void write();
    bool verificaSeDataExiste(std::string dataHoje, std::ifstream &file);    
    std::vector<Message> search(std::string msg);
};
#endif