#include <iostream>

int main(int argc, char *argv[]){
    int *a = new int;

    *a = 1;

    std::cout << a << std::endl;
    std::cout << *a << std::endl;


    delete a;
    
    return 0;
}