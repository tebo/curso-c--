//Programa para determinar si dos palabras son anagramas, es decir, si contienen las mismas letras en diferente orden.
#include <iostream>
#include <string>
#include <algorithm> // Para usar sort
using namespace std;

// Función para verificar si dos palabras son anagramas con FOR
bool sonAnagramasFOR(string palabra1, string palabra2) {
    // Eliminar espacios y convertir a minúsculas
    if (palabra1.length() == palabra2.length()) {
        for (char &c : palabra1) {
            if (c != ' ') {
                c = tolower(c); // Convertir a minúscula
            }
        }
        for (char &c : palabra2) {
            if (c != ' ') {
                c = tolower(c); // Convertir a minúscula
            }
        }
        // Ordenar las palabras
        for (char &c : palabra1) {
            if (c != ' ') {
                sort(palabra1.begin(), palabra1.end()); // Ordenar la primera palabra
                break;
            }
        }
        for (char &c : palabra2) {
            if (c != ' ') {
                sort(palabra2.begin(), palabra2.end()); // Ordenar la segunda palabra
                break;
            }
        }

        if (palabra1 == palabra2) {
            return true; // Son anagramas
        } else {
            return false; // No son anagramas
        }
    } else {

        return false; // Si las palabras no tienen la misma longitud, no son anagramas
    }
}

int main() {
    string palabra1, palabra2;
    cout << "Ingresa la primera palabra: ";
    cin >> palabra1; // Lee la primera palabra ingresada por el usuario
    cout << "Ingresa la segunda palabra: ";
    cin >> palabra2; // Lee la segunda palabra ingresada por el usuario

    if (sonAnagramasFOR(palabra1, palabra2)) { // Verifica si las palabras son anagramas
        cout << "Las palabras '" << palabra1 << "' y '" << palabra2 << "' son anagramas." << endl;
    } else {
        cout << "Las palabras '" << palabra1 << "' y '" << palabra2 << "' no son anagramas." << endl;
    }

    return 0; // Indica que el programa terminó correctamente
}   