#include <iostream>  // Incluye la biblioteca para entrada y salida estándar

int main() {  // Función principal donde comienza la ejecución del programa
    int contador = 1;  // Inicializa el contador en 1
    while (contador <= 5) {  // Bucle while: se ejecuta mientras contador sea menor o igual a 5
        std::cout << contador << " ";  // Imprime el valor del contador seguido de un espacio
        ++contador;  // Incrementa el contador en 1
    }
    std::cout << std::endl;  // Imprime un salto de línea al final
    return 0;  // Indica que el programa terminó correctamente
}