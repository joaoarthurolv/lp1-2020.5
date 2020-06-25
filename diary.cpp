#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

void show_usage(std::string const prog_name);
void adicionarMensagem(int qtdParametros, std::string mensagem, std::ofstream &file, std::ifstream &file_read);
void listar(std::ifstream &file);
bool verificaSeDataExiste(std::string dataHoje, std::ifstream &file);
std::string get_current_time();
std::string get_current_date();

int main(int argc, char *argv[]){
    std::ifstream file_read("diary.md"); 
    std::ofstream file_write("diary.md", std::ios::app);

    if(argc == 1){
        show_usage(argv[0]);
        return -1;
    }

    std::string action = argv[1];

    if(action != "add" && action != "list") {
        show_usage(argv[0]);
    }

    if(action == "add"){
        std::string mensagem = (argv[2]) ? argv[2] : "";
        adicionarMensagem(argc, mensagem, file_write, file_read); 
    }

    if(action == "list"){
        listar(file_read);
    }

    return 0;
}

void show_usage(std::string const prog_name){
    std::cout << "Usos: " << std::endl;
    std::cout << "1. " << prog_name << " add <mensagem>" << std::endl;
    std::cout << "2. " << prog_name << " list " << std::endl;
}

void adicionarMensagem(int qtdParametros, std::string mensagem, std::ofstream &file, std::ifstream &file_read){
    
    if(file.fail()){
        std::cout << "Arquivo não encontrado." << std::endl;
    }

    if(qtdParametros == 2){
        std::cout << "Informe a mensagem a ser adicionada: " << std::endl;
        std::getline(std::cin, mensagem);
    }

    bool dataExiste = verificaSeDataExiste(get_current_date(), file_read);

    if (dataExiste) {
        file << " - " << get_current_time() << " " << mensagem << std::endl;
    }

    else {
        file << "\n# " << get_current_date() << "\n\n";
        file << " - " << get_current_time() << " " << mensagem << std::endl;
    }

    std::cout << "Mensagem adicionada!" << std::endl;
}

void listar(std::ifstream &file){

    if(!file.is_open()){
        std::cerr << "Arquivo não existente ou sem permissão de acesso." << std::endl;
    }

    std::string message;

    //eof -> end of file
    while(!file.eof()){
        std::getline(file, message);
        
        std::cout << message << std::endl;
    }
}

bool verificaSeDataExiste(std::string dataHoje, std::ifstream &file){
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

std::string format_current_date(const std::string &format) {
    std::time_t time = std::time(nullptr);
    char result[1024];

    std::strftime(result, sizeof(result), format.c_str(), std::localtime(&time));

    return std::string(result);
}

std::string get_current_date() { return format_current_date("%d/%m/%Y"); }

std::string get_current_time() { return format_current_date("%H:%M:%S"); }