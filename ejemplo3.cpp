#include <iostream>  // Incluye la biblioteca para entrada y salida estándar

int main() {  // Función principal donde comienza la ejecución del programa
    // Bucle for: se ejecuta mientras i sea menor o igual a 10
    for (int i = 1; i <= 10; ++i) {  // Inicializa i en 1, condición i <= 10, incrementa i en 1 cada iteración
        std::cout << i << " ";  // Imprime el valor de i seguido de un espacio
    }
    std::cout << std::endl;  // Imprime un salto de línea al final
    return 0;  // Indica que el programa terminó correctamente
}