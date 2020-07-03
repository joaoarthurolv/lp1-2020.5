#include "../include/Diary.h"
#include "../include/Diary.h"
#include "../include/Date.h"

#include <iostream>
#include <fstream>
#include <string>

#include <sstream>

#include <vector>

Diary::Diary(const std::string& filename) : 
    filename(filename)
{
    
    std::ifstream file_read(filename);
    std::string line;

    std::string dt;
    std::string hr;
    std::string tipo;
    std::string msg;
    
    Date d;
    Time t;
    Message m;

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
        
            m.content = msg;
            m.date = d;
            m.time = t;
            m.alreadyOnFile = true;

            messages.push_back(m);
            ++index;
        }
        
        else {}     
    }

}

void Diary::add(const std::string& message){
    Message m;
    
    Date d;
    d.set_from_string(d.get_current_date());

    Time t;
    t.set_from_string(t.get_current_time());

    m.content = message;
    m.date = d;
    m.time = t;
    m.alreadyOnFile = false;

    messages.push_back(m);
}

void Diary::write(){
    std::ifstream file_read(filename); 
    std::ofstream file_write(filename, std::ios::app);

    if(file_write.fail()){
        std::cout << "Arquivo não encontrado." << std::endl;
    }

    for(size_t i = 0; i < messages.size(); ++i){


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

std::vector<Message> Diary::search(std::string msg){
    std::vector<Message> mensagens;

    for(size_t i = 0; i < messages.size(); ++i){
        std::size_t mensagem_encontrada = messages[i].content.find(msg);
        
        if(mensagem_encontrada < messages[i].content.npos) {
            
            Message m;      
            m.content = messages[i].content;
            m.time = messages[i].time;
            mensagens.push_back(m);
            
        }
    }

    return mensagens;
}