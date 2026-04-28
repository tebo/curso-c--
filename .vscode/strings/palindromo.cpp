// PAra verificar si una palabra es un palíndromo, es decir, se lee igual de izquierda a derecha que de derecha a izquierda.

#include <iostream>
#include <string>
using namespace std;
bool esPalindromo(const string& palabra) {
    int izquierda = 0; // Índice para el inicio de la palabra
    int derecha = palabra.length() - 1; // Índice para el final de la palabra

    while (izquierda < derecha) { // Mientras los índices no se crucen
        if (palabra[izquierda] != palabra[derecha]) { // Si los caracteres no son iguales
            return false; // No es un palíndromo
        }
        izquierda++; // Mover el índice izquierdo hacia la derecha
        derecha--; // Mover el índice derecho hacia la izquierda
    }
    return true; // Es un palíndromo
}

bool esPalindromoFOR (string palabra) {
    for (int i = 0; i < palabra.length() / 2; i++) { // Itera hasta la mitad de la palabra
        if (palabra[i] != palabra[palabra.length() - 1 - i]) { // Compara el carácter actual con su correspondiente desde el final
            return false; // No es un palíndromo
        }
    }
    return true; // Es un palíndromo
}

int main() {
    string palabra;
    cout << "Ingresa una palabra para verificar si es un palíndromo: ";
    cin >> palabra; // Lee la palabra ingresada por el usuario

    if (esPalindromo(palabra)) { // Verifica si la palabra es un palíndromo
        cout << "La palabra '" << palabra << "' es un palíndromo." << endl;
    } else {
        cout << "La palabra '" << palabra << "' no es un palíndromo." << endl;
    }

    return 0; // Indica que el programa terminó correctamente
}