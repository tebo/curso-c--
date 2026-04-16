// Ejemplo de mascota virtual con programacion estructurada y funciones
#include <iostream>
#include <string>
using namespace std;

void mostrarMascota()
{
    cout << "    /\\_/\\" << endl;
    cout << "   ( o.o )" << endl;
    cout << "    > ^ <" << endl;
    cout << "   /|   |\\" << endl;
    cout << "  (_|   |_)" << endl;
}

void mostrarMascotaFeliz()
{
    cout << "    /\\_/\\" << endl;
    cout << "   ( ^.^ )" << endl;
    cout << "    > ◡ <" << endl;
    cout << "   /|   |\\" << endl;
    cout << "  (_|   |_)" << endl;
}

void mostrarMascotaHambre()
{
    cout << "    /\\_/\\" << endl;
    cout << "   ( >.< )" << endl;
    cout << "    > ∧ <" << endl;
    cout << "   /|   |\\" << endl;
    cout << "  (_|   |_)" << endl;
}

int nacerMascota()
{
    cout << "¡Tu mascota ha nacido!" << endl;
    mostrarMascota();
    return 10;
}
int main()
{
    int energia = nacerMascota();

    // menu de acciones para la mascota
    int opcion;
    do {
        cout << "\n¿Qué quieres hacer con tu mascota?" << endl;
        cout << "1. Alimentar" << endl;
        cout << "2. Jugar" << endl;
        cout << "3. Ver estado" << endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese su opción: ";
        cin >> opcion;
        switch (opcion) {
            case 1:
                cout << "Alimentando a tu mascota..." << endl;
                energia += 5;
                mostrarMascotaFeliz();
                break;
            case 2:
                cout << "Jugando con tu mascota..." << endl;
                energia -= 5;
                mostrarMascotaHambre();
                break;
            case 3:
                cout << "Tu mascota tiene " << energia << " de energía." << endl;
                mostrarMascota();
                break;
            case 0:
                cout << "¡Adiós!" << endl;
                break;
            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
        }
    } while (opcion != 0);
    
    

    return 0;
}
