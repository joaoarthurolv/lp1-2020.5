#include "../include/App.h"
#include "../include/Config.h"

int main(int argc, char* argv[]){
    Config config;

    std::string path = config.nome_diario("diary.config");
    App aplicativo("/home/joaoarthur/lp1-2020.5/atividade3/diary.md");
    return aplicativo.run(argc, argv);
}