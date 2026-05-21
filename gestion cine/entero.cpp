#include <iostream>
#include <limits> // Necesario para numeric_limits

using namespace std;

int main() {
    int numero;
    cout << "Ingresa un número entero: ";

    // Bucle que se repite mientras la entrada sea incorrecta
    while (!(cin >> numero)) {
        cout << "Error: Ingresa un valor numérico entero válido.\n";
        
        // 1. Limpiar el estado de error de cin
        cin.clear(); 
        
        // 2. Descartar la entrada incorrecta del búfer
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        
        cout << "Intenta de nuevo: ";
    }

    cout << "Número ingresado correctamente: " << numero << endl;
    return 0;
}
