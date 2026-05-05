// Programa simple demonstration of using vectors in C++
#include <iostream>
#include <vector>
//namespace std;

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    int numero;
    //llenar datos desde el teclado
    for (int i=0; i < 5; i++) {
        std::cout << "Ingrese un numero: ";
        std::cin >> numero;
        if (numero < 0) {
            std::cout << "Numero negativo, no se agregara al vector." << std::endl;
            break;
        }
    }

    //mostrar datos
    for (int i=0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    


    return 0;
}