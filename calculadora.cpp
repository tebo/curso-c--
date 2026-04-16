// ejemplo de calucladora basico con dos parametros
#include <iostream>
using namespace std;
//funcion suma

double suma (double a, double b)
{
    return a + b;
}

double resta (double a, double b)
{
    return a - b;
}

double multiplicacion (double a, double b)
{
    return a * b;
}

double division (double a, double b)
{
    if (b != 0) {
        return a / b;
    } else {
        throw invalid_argument("No se puede dividir por cero");
    }
}

int main()
{
    double num1, num2;
    
    cout << "Ingrese el primer número: ";
    cin >> num1;
    cout << "Ingrese el segundo número: ";
    cin >> num2;
    cout << "Suma: " << suma(num1,num2) << endl;
    cout << "Resta: " << resta(num1,num2) << endl;
    cout << "Multiplicación: " << multiplicacion(num1,num2) << endl;
    try {
        cout << "División: " << division(num1,num2) << endl;
    } catch (const invalid_argument& e) {
        cout << "División: " << e.what() << endl;
    }
    
    
    return 0;
}
