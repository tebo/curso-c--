// Programa demo para mostrar el uso de cadenas de texto en C++
#include <iostream>
#include <string>
using namespace std;
string mensaje = "¡Hola, mundo!";
int main() {
    // SAlida de texto
    cout << mensaje << endl; // Imprime el mensaje en la consola
    
    //Ingreso de texto
    string nombre;
    cout << "Ingresa tu nombre: ";
    cin >> nombre; // Lee el nombre ingresado por el usuario
    cout << "¡Hola, " << nombre << "!" << endl; // Saluda al usuario por su nombre

    // Concatenación de cadenas
    string saludo = "¡Bienvenido, " + nombre + "!";
    cout << saludo << endl; // Imprime el saludo concatenado 

    // Longitud de una cadena
    cout << "Tu nombre tiene " << nombre.length() << " caracteres." << endl;

    // Subcadena
    if (nombre.length() >= 3) {
        string subcadena = nombre.substr(0, 3); // Obtiene los primeros 3 caracteres del nombre
        cout << "Los primeros 3 caracteres de tu nombre son: " << subcadena << endl;
    } else {
        cout << "Tu nombre es muy corto para obtener una subcadena de 3 caracteres." << endl;
    }

    // Comparación de cadenas
    string otroNombre;
    cout << "Ingresa otro nombre para comparar: ";
    cin >> otroNombre; // Lee otro nombre ingresado por el usuario
    if (nombre == otroNombre) {
        cout << "¡Los nombres son iguales!" << endl;
    } else {
        cout << "Los nombres son diferentes." << endl;
    }

    // Conversión de mayúsculas a minúsculas
    string nombreMinusculas = nombre;
    for (char &c : nombreMinusculas) {
        c = tolower(c); // Convierte cada carácter a minúscula
    }
    cout << "Tu nombre en minúsculas es: " << nombreMinusculas << endl;

    // Conversión de minúsculas a mayúsculas
    string nombreMayusculas = nombre;
    for (char &c : nombreMayusculas) {
        c = toupper(c); // Convierte cada carácter a mayúscula
    }
    cout << "Tu nombre en mayúsculas es: " << nombreMayusculas << endl;

    // Reemplazo de caracteres
    string nombreReemplazado = nombre;
    for (char &c : nombreReemplazado) {
        if (c == 'a' || c == 'A') {
            c = '@'; // Reemplaza 'a' o 'A' por '@'
        }
    }
    cout << "Tu nombre con 'a' reemplazada por '@' es: " << nombreReemplazado << endl;

    // Verificación de si una cadena contiene un carácter específico
    char caracter;
    cout << "Ingresa un carácter para verificar si está en tu nombre: ";
    cin >> caracter; // Lee un carácter ingresado por el usuario
    if (nombre.find(caracter) != string::npos) {
        cout << "¡El carácter '" << caracter << "' está en tu nombre!" << endl;
    } else {
        cout << "El carácter '" << caracter << "' no está en tu nombre." << endl;
    }   
    
    return 0;

}
