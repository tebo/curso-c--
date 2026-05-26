//Programa de validacion de ingreso de datos
#include <iostream>
using namespace std;

int main()
{
 // validar que es de tipo entero
 int numero;
 cout << "Ingrese un numero entero: ";
 cin >> numero;
 if (cin.fail()) {
     cout << "Error: No es un numero entero." << endl;
     return 1; // Salir con error
 }

 do {
    cout << "Ingrese un numero entero: ";
    cin >> numero;
  } while (cin.fail());
  
    
    return 0;
}