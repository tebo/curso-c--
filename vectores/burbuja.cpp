//Algoritmo burbuja pra ordenar un vector de enteros
#include <iostream>
#include <vector>

using namespace std;

int main() {   
    int numeros[100]; // Vector para almacenar hasta 100 números
    int numero;
    int i = 0;
    while (true) {
        cout << "Ingrese numeros enteros (ingrese 0 para terminar): " << endl;
        cin >> numero;
        if (numero == 0) {
            break;  
        }
        numeros[i]= numero;
        i++;
    }
    //Ordenar el vector usando el algoritmo de burbuja
    for (int i = 0; i < numeros.size() - 1; i++) {
        for (int j = 0; j < numeros.size() - i - 1; j++) {
            if (numeros[j] > numeros[j + 1]) {
                int temp = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = temp;
            }
        }
    }

    //Mostrar el vector ordenado
    cout << "Numeros ordenados: " << endl;
    for (int i = 0; i < numeros.size(); i++) {
        cout << numeros[i] << " ";
    }
    cout << endl;
    return 0;
}