#ifndef DIARIO_H
#define DIARIO_H

#include <iostream>
#include <string>
#include "Mensagem.h"

struct Diario {
    Mensagem mensagens[100];

    void adicionar_mensagem(const Mensagem &mensagem){
        for(int i = 0; i < 100; i++){
            
            if(mensagens[i].conteudo.empty() && mensagens[i].data.empty() && mensagens[i].hora.empty()){
                mensagens[i].conteudo = mensagem.conteudo;
                mensagens[i].data = mensagem.data;
                mensagens[i].hora = mensagem.hora;
            }
        }
    }

    void listarMensagens(){
        for(int i = 1; i <= 100; i++){
            std::cout << i << ". " << mensagens[i].conteudo << std::endl;
        }
    }
};

#endif