#include <iostream>  // Incluye la biblioteca para entrada y salida estándar

int main() {  // Función principal donde comienza la ejecución del programa
    int num;  // Declara una variable entera para almacenar el número
    std::cout << "Ingrese un número: ";  // Pide al usuario que ingrese un número
    std::cin >> num;  // Lee el número desde la entrada estándar
    if (num % 2 == 0) {  // Verifica si el número es divisible por 2 (par)
        std::cout << "El número es par." << std::endl;  // Imprime que es par
    } else {  // Si no es par, entonces es impar
        std::cout << "El número es impar." << std::endl;  // Imprime que es impar
    }
    return 0;  // Indica que el programa terminó correctamente
}