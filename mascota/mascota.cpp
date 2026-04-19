// Ejemplo de mascota virtual con programacion estructurada y funciones
#include <iostream>
#include <string>
using namespace std;
int energia;
string nombre;


int ramdomvida() {
    return rand() % 10 + 1; // Genera un número aleatorio entre 1 y 10
}

bool estaViva() {
    if (energia <= 0) {
        // asscii art ataud 
        cout << "    _______" << endl;
        cout << "   /       \\" << endl;
        cout << "  /         \\" << endl;
        cout << "  |  R.I.P. |" << endl;
        cout << "  |         |" << endl;            
        cout << "Tu mascota ha fallecido." << endl;

        // PREGUNTAR SI QUIERE REANIMARLA
        char opcion;
        cout << "¿Quieres reanimar a tu mascota? (s/n): ";
        cin >> opcion;
        if (opcion == 's' || opcion == 'S') {
            energia = 10; // reanimar con energia inicial
            cout << "¡Tu mascota ha sido reanimada!" << endl;
            mostrarMascota();
        } else {
            // Si no quiere reanimar, el programa termina
            cout << "¡Adiós!" << endl;
            exit(0);
        }

        return false;
    }   
    return true;
}
void mostrarMascota()
{
    cout << "    /\\_/\\" << endl;
    cout << "   ( o.o )" << endl;
    cout << "    > ^ <" << endl;
    cout << "   /|   |\\" << endl;
    cout << "  (_|   |_)" << endl;
    cout << " " << nombre << " Energia " << energia << endl;
}

void mostrarMascotaFeliz()
{
    cout << "    /\\_/\\" << endl;
    cout << "   ( ^.^ )" << endl;
    cout << "    > ◡ <" << endl;
    cout << "   /|   |\\" << endl;
    cout << "  (_|   |_)" << endl;
    cout << " " << nombre << " Energia " << energia << endl;
}

void mostrarMascotaHambre()
{
    cout << "    /\\_/\\" << endl;
    cout << "   ( >.< )" << endl;
    cout << "    > ∧ <" << endl;
    cout << "   /|   |\\" << endl;
    cout << "  (_|   |_)" << endl;
    cout << " " << nombre << " Energia " << energia << endl;
}

int nacerMascota()
{
    cout << "Ingresa el nombre de tu mascota: ";
    cin >> nombre;
    energia=10;
    cout << "¡Tu mascota ha nacido!" << endl;
    mostrarMascota();
    return 0;
}
int main()
{
    energia = nacerMascota();

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
        if (!estaViva()) {
            break; // Si la mascota no está viva, salir del bucle
        } else {
            // Si la mascota está viva, mostrar su estado actual
            energia = ramdomvida(); // Simula la vida de la mascota con un valor aleatorio
        }
    } while (opcion != 0);
    
    

    return 0;
}
