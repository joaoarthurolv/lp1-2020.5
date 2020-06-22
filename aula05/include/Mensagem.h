#ifndef MENSAGEM_H
#define MENSAGEM_H

#include <string>

struct Mensagem {
    std::string data;
    std::string hora;
    std::string conteudo;

    bool verifica_data_existente(const Mensagem &segunda_mensagem){
        bool valor;

        if (data == segunda_mensagem.data){
            valor = true;
        }

        else {
            valor = false;
        }
        
        return valor;
    }
};

#endif