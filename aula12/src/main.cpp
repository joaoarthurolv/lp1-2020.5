#include "../include/App.h"
#include "../include/ConfigFile.h"

int main(int argc, char* argv[]){
    ConfigFile config;

    config.nome_diario("diary.config");
    App aplicativo("diary.md");
    return aplicativo.run(argc, argv);
}