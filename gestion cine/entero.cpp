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

    // Validacion ingreso de double
    double numeroDecimal;
    cout << "Ingresa un número decimal: ";
    while (!(cin >> numeroDecimal)) {
        cout << "Error: Ingresa un valor numérico decimal válido.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Intenta de nuevo: ";
    }
    cout << "Número decimal ingresado correctamente: " << numeroDecimal << endl;
    

    return 0;
}
