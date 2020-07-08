#include "../include/Cliente.hpp"

int Cliente::quantidade_clientes;

Cliente::Cliente(){
    this->quantidade_clientes += 1;
}

