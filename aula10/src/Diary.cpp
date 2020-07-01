#include "../include/Diary.h"
#include "../include/Diary.h"
#include "../include/Date.h"

#include <iostream>
#include <fstream>
#include <string>

#include <sstream>

Diary::Diary(const std::string& filename) : 
    filename(filename),
    messages(nullptr),
    messages_size(0), 
    messages_capacity(10)
{
    messages = new Message[messages_capacity];
    
    std::ifstream file_read(filename);
    std::string line;

    std::string dt;
    std::string hr;
    std::string tipo;
    std::string msg;
    
    Date d;
    Time t;

    int index = 0;

    while(!file_read.eof()){
        
        getline(file_read,line);

        std::stringstream stream(line);

        stream >> tipo;

        if(tipo.compare("#") == 0){
            stream >> dt;
        }

        if (tipo.compare("-") == 0) {
            stream >> hr;
            stream >> msg;

            d.set_from_string(dt);
            t.set_from_string(hr);
        
            messages[index].content = msg;
            messages[index].date = d;
            messages[index].time = t;
            messages[index].alreadyOnFile = true;

            ++index;
            ++messages_size;
        }
        
        else {
            
        }    
        
    }

}

Diary::~Diary(){
    delete[] messages;
}

void Diary::add(const std::string& message){
    
    Message m;
    
    if (messages_size == messages_capacity) {
        std::cout << " entrou aqui " << std::endl;
        messages_capacity = messages_capacity*2;
        Message* new_messages = new Message[messages_capacity];

        for(size_t i = 0; i < messages_size; ++i){
            
            new_messages[i] = messages[i];

        }
        
        // Não soube fazer o processo de apontar o ponteiro antigo pro novo
        messages = new_messages;
    }
    
    Date d;
    d.set_from_string(d.get_current_date());

    Time t;
    t.set_from_string(t.get_current_time());

    m.content = message;
    m.date = d;
    m.time = t;
    m.alreadyOnFile = false;
    messages[messages_size] = m;
    messages_size++;

}

void Diary::write(){
    std::ifstream file_read(filename); 
    std::ofstream file_write(filename, std::ios::app);

    if(file_write.fail()){
        std::cout << "Arquivo não encontrado." << std::endl;
    }

    for(size_t i = 0; i < messages_size; ++i){


        if(messages[i].alreadyOnFile == true){
            continue;
        }

        else {
            bool dataExiste = verificaSeDataExiste(messages[i].date.to_string(), file_read);

            if(dataExiste){
                file_write << "- " << messages[i].time.to_string() << " " << messages[i].content << std::endl;
            }
            else {
                file_write << "\n# " << messages[i].date.to_string() << "\n\n";
                file_write << "- " << messages[i].time.to_string() << " " << messages[i].content << std::endl;
            }
            
        }
    }
}

bool Diary::verificaSeDataExiste(std::string dataHoje, std::ifstream &file){
    std::string line;
    dataHoje = "# " + dataHoje;
    bool valor;

    while(!file.eof()){

        getline(file,line);
        
        if (line.find(dataHoje) != std::string::npos) {
            valor = true;
            break;
        }
        else{
            valor = false;
        }
    }

    return valor;
}

Message* Diary::search(std::string msg){

    for(size_t i = 0; i < messages_size; ++i){
        std::size_t mensagem_encontrada = messages[i].content.find(msg);

        if(mensagem_encontrada < messages[i].content.npos) {
            return &messages[i];
        }
    }
    return nullptr;
}