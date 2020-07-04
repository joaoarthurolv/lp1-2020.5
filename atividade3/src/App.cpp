#include "../include/App.h"
#include "../include/Diary.h"

App::App(const std::string& filename) : diary(filename)
{
}
    
    
int App::run(int argc, char* argv[])
{
    if(argc == 1){
        return show_usage();
    }

    std::string action = argv[1];

    if(action == "add"){
        if(argc == 2){
            add();
        } 
        else{
            add(argv[2]);
        }
    }
    else if(action == "list"){
        list_messages();
    }

    else if(action == "search"){
        search(argv[2]);
    }

    else if(action == "interactive"){
        menu_interativo();
    }

    else {
        return show_usage();
    }

    return 0;
}

void App::add()
{
    std::string message;
    std::cout << "Enter your message:" << std::endl;
    std::getline(std::cin, message);

    add(message);
}

void App::add(const ::std::string message)
{
    diary.add(message);
    diary.write();
}

void App::list_messages(){


    std::string data = "%d";
    std::string hora = "%t";
    std::string mensagem = "%m";

    for (size_t i = 0; i < diary.messages.size(); ++i){
        std::string formato = procura_e_armazena_formato_lista();

        size_t start_pos = formato.find("%d");

        if(start_pos != std::string::npos) {
            formato.replace(start_pos, data.length(), diary.messages[i].date.to_string());
        }

        start_pos = formato.find("%t");
        
        if(start_pos != std::string::npos) {
            formato.replace(start_pos, hora.length(), diary.messages[i].time.to_string());
        }

        start_pos = formato.find("%m");
        
        if(start_pos != std::string::npos) {
            formato.replace(start_pos, mensagem.length(), diary.messages[i].content);
        }

        std::cout <<  formato << std::endl;
    }
}

int App::show_usage()
{
    return 1;
}

void App::search(std::string msg){
    std::vector<Message> mensagem = diary.search(msg);

    if (mensagem.empty()) {
        std::cout << "Mensagem não encontrada!" << std::endl;
    }

    else {

        if (mensagem.size() > 1) {
            std::cout << "Mensagens encontradas!" << std::endl;
        }
        
        else {
            std::cout << "Mensagem encontrada!" << std::endl;
        }

        for (Message i: mensagem){
            std::cout << i.time.to_string() << " " << i.content << std::endl;
        }
    }
}

std::string App::procura_e_armazena_formato_lista(){
    std::string line;
    std::string tipo;
    std::string format;
    std::ifstream file_read("diary.config");

    if (file_read.fail()) {
        
    }

    // Código para a leitura do arquivo de configuração voltar ao seu início.
    file_read.clear();
    file_read.seekg(0, std::ios::beg);

    while(!file_read.eof()){
        
        getline(file_read,line);

        std::stringstream stream(line);
        char c;
        char igual = '=';
        while (!stream.eof()) {
            stream >> std::noskipws >> c;

            if(c == igual){
                break;
            }
            else {
                tipo = tipo + c;
            }
            
        }
        getline(stream, format);
    }
    return format;
}

void App::menu_interativo(){
    int escolha = 0;

    do {
        std::cout << "Diário 1.0\n" << std::endl;

        std::cout << "Selecione uma opção:\n" << std::endl;

        std::cout << "1) Listar mensagens" << std::endl;
        std::cout << "2) Adicionar nova mensagem\n" << std::endl;

        std::cout << "0) Finalizar" << std::endl;
        std::cin >> escolha;

        if (escolha == 1){
            list_messages();
        }

        if (escolha == 2) {
            std::cin.ignore();
            add();
        }

    } while(escolha != 0);
}