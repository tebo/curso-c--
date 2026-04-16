// programa demostracion de la libreria math en c++
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double numero = 16.05;

    // Calcular la raíz cuadrada
    double raizCuadrada = sqrt(numero);
    cout << "La raíz cuadrada de " << numero << " es: " << raizCuadrada << endl;

    // Calcular el valor absoluto
    double valorAbsoluto = fabs(-5.5);
    cout << "El valor absoluto de -5.5 es: " << valorAbsoluto << endl;

    // Calcular el seno de un ángulo (en radianes)
    double angulo = 45.0 * M_PI / 180.0; // Convertir a radianes
    double seno = sin(angulo);
    cout << "El seno de 45 grados es: " << seno << endl;

    // Calcular el coseno de un ángulo (en radianes)
    double coseno = cos(angulo);
    cout << "El coseno de 45 grados es: " << coseno << endl;

    // Calcular el logaritmo natural
    double logaritmoNatural = log(numero);
    cout << "El logaritmo natural de " << numero << " es: " << logaritmoNatural << endl;

    // Usar random para generar un número aleatorio entre 0 y 1
    double numeroAleatorio = static_cast<double>(rand()) / RAND_MAX;
    cout << "Número aleatorio entre 0 y 1: " << numeroAleatorio << endl;
    
    return 0;
}

