#include "../include/Diary.h"

#include <iostream>

Diary::Diary(const std::string& filename) : filename(filename)
{
    
}

void Diary::add(const std::string& message){
    messages[messages_size].content = message;

    std::cout << "Mensagem '" << messages[messages_size].content << "' armazenada." << std::endl;

    messages_size++; 
}

void Diary::write()
{
}