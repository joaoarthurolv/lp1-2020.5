#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
    int numero1, numero2, soma;

    cout << "PROGRAMINHA DE SOMA" << endl;
    cout << "-------------------" << endl;

    cout << "Digite um numero: " << endl;
    cin >> numero1;

    cout << "Digite mais um numero: " << endl;
    cin >> numero2;

    soma = numero1 + numero2;

    cout << "A soma dos dois números digitados é: " << soma << endl;
}