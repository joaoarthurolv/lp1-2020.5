#ifndef DIARY_H
#define DIARY_H

#include "Message.h"

#include <string>
#include <fstream>

struct Diary {

    Diary(const std::string& filename);

    ~Diary();

    std::string filename;
    Message* messages;
    size_t messages_size = 0;
    size_t messages_capacity;

    void add(const std::string& message);
    void write();

    bool verificaSeDataExiste(std::string dataHoje, std::ifstream &file);    
    Message* search(std::string msg);
};
#endif