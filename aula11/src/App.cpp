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
    for (size_t i = 0; i < diary.messages.size(); ++i){
        const Message& message = diary.messages[i];
        std::cout << "-" <<  message.content << std::endl;
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