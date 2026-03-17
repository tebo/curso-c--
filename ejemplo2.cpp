#include <iostream>  // Incluye la biblioteca para entrada y salida estándar

int main() {  // Función principal donde comienza la ejecución del programa
    int a, b;  // Declara dos variables enteras para almacenar los números
    std::cout << "Ingrese dos números: ";  // Pide al usuario que ingrese dos números
    std::cin >> a >> b;  // Lee dos números desde la entrada estándar y los asigna a a y b
    int suma = a + b;  // Calcula la suma de a y b
    std::cout << "La suma es: " << suma << std::endl;  // Imprime el resultado de la suma
    return 0;  // Indica que el programa terminó correctamente
}