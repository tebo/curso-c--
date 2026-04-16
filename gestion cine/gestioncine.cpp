/*
 * ============================================================================
 * PROGRAMA: SISTEMA DE GESTIÓN DE CINE
 * ============================================================================
 * Objetivo: Demostrar el uso de estructuras y funciones en C++
 * Nivel: Programación Estructurada
 * 
 * Conceptos desarrollados:
 * - Estructuras (struct)
 * - Funciones con paso de parámetros
 * - Arreglos de estructuras
 * - Entrada/Salida de datos
 * - Validación de información
 * - Menús interactivos
 * ============================================================================
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

using namespace std;

// ============================================================================
// DEFINICIÓN DE ESTRUCTURAS (TIPOS DE DATOS COMPUESTOS)
// ============================================================================

/**
 * Estructura para representar una película
 * Agrupa toda la información relacionada con una película
 */
struct Pelicula {
    int id;                  // Identificador único
    string titulo;           // Nombre de la película
    string genero;           // Género: Acción, Drama, Comedia, etc.
    float duracion;          // Duración en minutos
    string clasificacion;    // Clasificación: G, PG, PG-13, R
    float precioEntrada;     // Precio por entrada
};

/**
 * Estructura para representar una función (sesión) de cine
 * Una película puede tener múltiples funciones a diferentes horas
 */
struct Funcion {
    int id;                  // Identificador único de la función
    int idPelicula;          // Referencia a la película (clave foránea)
    string hora;             // Hora de inicio: "14:30", "18:00", "21:00"
    int salaNumero;          // Número de sala donde se proyecta
    int asientosDisponibles; // Cantidad de asientos sin vender
    int asientosVendidos;    // Cantidad de asientos vendidos
};

/**
 * Estructura para registrar la venta de una entrada
 * Permite llevar un historial de transacciones
 */
struct Venta {
    int idFuncion;           // Función para la cual se compró la entrada
    int cantidadAsientos;    // Número de asientos comprados
    float montoTotal;        // Monto pagado por la compra
};

// ============================================================================
// CONSTANTES GLOBALES
// ============================================================================
const int MAX_PELICULAS = 10;    // Máximo de películas en cartelera
const int MAX_FUNCIONES = 20;    // Máximo de funciones disponibles
const int MAX_VENTAS = 100;      // Máximo de registros de venta
const int ASIENTOS_POR_SALA = 50; // Capacidad estándar de las salas

// ============================================================================
// VARIABLES GLOBALES (Arrays para almacenar datos)
// ============================================================================
Pelicula peliculas[MAX_PELICULAS];
Funcion funciones[MAX_FUNCIONES];
Venta ventas[MAX_VENTAS];

int cantidadPeliculas = 0;
int cantidadFunciones = 0;
int cantidadVentas = 0;

// ============================================================================
// FUNCIONES AUXILIARES DE VALIDACIÓN
// ============================================================================

/**
 * Función para limpiar pantalla
 * Propósito: Mejorar la experiencia visual del usuario
 */
void limpiarPantalla() {
    system("clear");
}

/**
 * Función para pausar la ejecución
 * Propósito: Permitir que el usuario lea los mensajes antes de continuar
 */
void pausa() {
    cout << "\n\nPresione ENTER para continuar...";
    cin.ignore();
    cin.get();
}

/**
 * Función para validar que un número esté dentro de un rango
 * Parámetros:
 *   - valor: número a validar
 *   - minimo: límite inferior
 *   - maximo: límite superior
 * Retorna: true si está en rango, false si no
 */
bool estaEnRango(int valor, int minimo, int maximo) {
    return (valor >= minimo && valor <= maximo);
}

/**
 * Función para validar que un número flotante sea positivo
 * Parámetros:
 *   - numero: número a validar
 * Retorna: true si es positivo, false si no
 */
bool esPositivo(float numero) {
    return numero > 0;
}

// ============================================================================
// FUNCIONES DE INICIALIZACIÓN DE DATOS DE PRUEBA
// ============================================================================

/**
 * Función para cargar películas de ejemplo
 * Propósito: Poblar inicialmente la cartelera con datos
 * 
 * Demuestra:
 * - Cómo llenar un arreglo de estructuras
 * - Acceso a campos de estructuras
 * - Incremento de contadores
 */
void cargarPeliculasEjemplo() {
    // Primera película
    peliculas[0].id = 1;
    peliculas[0].titulo = "Aventura en la Galaxia";
    peliculas[0].genero = "Ciencia Ficción";
    peliculas[0].duracion = 148.0;
    peliculas[0].clasificacion = "PG-13";
    peliculas[0].precioEntrada = 15.00;
    
    // Segunda película
    peliculas[1].id = 2;
    peliculas[1].titulo = "El Misterio del Castillo";
    peliculas[1].genero = "Drama";
    peliculas[1].duracion = 125.0;
    peliculas[1].clasificacion = "PG";
    peliculas[1].precioEntrada = 14.00;
    
    // Tercera película
    peliculas[2].id = 3;
    peliculas[2].titulo = "Risas Garantizadas";
    peliculas[2].genero = "Comedia";
    peliculas[2].duracion = 98.0;
    peliculas[2].clasificacion = "G";
    peliculas[2].precioEntrada = 13.00;
    
    cantidadPeliculas = 3;
}

/**
 * Función para cargar funciones (sesiones) de ejemplo
 * Propósito: Asignar funciones a películas
 * 
 * Demuestra:
 * - Relación entre estructuras (función -> película)
 * - Inicialización de disponibilidad de asientos
 */
void cargarFuncionesEjemplo() {
    // Función 1: Primera película - Matinal
    funciones[0].id = 1;
    funciones[0].idPelicula = 1;
    funciones[0].hora = "14:30";
    funciones[0].salaNumero = 1;
    funciones[0].asientosDisponibles = ASIENTOS_POR_SALA;
    funciones[0].asientosVendidos = 0;
    
    // Función 2: Primera película - Nocturna
    funciones[1].id = 2;
    funciones[1].idPelicula = 1;
    funciones[1].hora = "21:00";
    funciones[1].salaNumero = 1;
    funciones[1].asientosDisponibles = ASIENTOS_POR_SALA;
    funciones[1].asientosVendidos = 0;
    
    // Función 3: Segunda película - Matinal
    funciones[2].id = 3;
    funciones[2].idPelicula = 2;
    funciones[2].hora = "16:00";
    funciones[2].salaNumero = 2;
    funciones[2].asientosDisponibles = ASIENTOS_POR_SALA;
    funciones[2].asientosVendidos = 0;
    
    // Función 4: Segunda película - Nocturna
    funciones[3].id = 4;
    funciones[3].idPelicula = 2;
    funciones[3].hora = "19:00";
    funciones[3].salaNumero = 2;
    funciones[3].asientosDisponibles = ASIENTOS_POR_SALA;
    funciones[3].asientosVendidos = 0;
    
    // Función 5: Tercera película - Vespertina
    funciones[4].id = 5;
    funciones[4].idPelicula = 3;
    funciones[4].hora = "18:30";
    funciones[4].salaNumero = 3;
    funciones[4].asientosDisponibles = ASIENTOS_POR_SALA;
    funciones[4].asientosVendidos = 0;
    
    cantidadFunciones = 5;
}

// ============================================================================
// FUNCIONES DE BÚSQUEDA
// ============================================================================

/**
 * Función para obtener una película por ID
 * Parámetros:
 *   - id: identificador de la película
 * Retorna: índice en el arreglo si existe, -1 si no existe
 * 
 * Demuestra:
 * - Búsqueda lineal en arreglo
 * - Retorno de valores
 */
int obtenerIndicePelicula(int id) {
    for (int i = 0; i < cantidadPeliculas; i++) {
        if (peliculas[i].id == id) {
            return i;  // Película encontrada
        }
    }
    return -1;  // Película no encontrada
}

/**
 * Función para obtener una función por ID
 * Parámetros:
 *   - id: identificador de la función
 * Retorna: índice en el arreglo si existe, -1 si no existe
 */
int obtenerIndiceFuncion(int id) {
    for (int i = 0; i < cantidadFunciones; i++) {
        if (funciones[i].id == id) {
            return i;
        }
    }
    return -1;
}

// ============================================================================
// FUNCIONES DE PRESENTACIÓN / VISUALIZACIÓN
// ============================================================================

/**
 * Función para mostrar el encabezado de la aplicación
 * Propósito: Presentación visual consistente
 */
void mostrarEncabezado() {
    cout << "╔════════════════════════════════════════════════════════════╗\n";
    cout << "║        SISTEMA DE GESTIÓN DE CINE - GRUPO CINEMAS         ║\n";
    cout << "╚════════════════════════════════════════════════════════════╝\n";
}

/**
 * Función para mostrar el menú principal
 * Propósito: Presentar opciones disponibles al usuario
 * 
 * Demuestra:
 * - Presentación de opciones
 * - Estructura de menú
 */
void mostrarMenuPrincipal() {
    cout << "\n┌─ MENÚ PRINCIPAL ─────────────────────────────────────────┐\n";
    cout << "│ 1. Ver cartelera de películas                             │\n";
    cout << "│ 2. Ver funciones disponibles                              │\n";
    cout << "│ 3. Comprar entrada                                        │\n";
    cout << "│ 4. Ver estado de salas                                    │\n";
    cout << "│ 5. Ver ventas realizadas                                  │\n";
    cout << "│ 0. Salir del sistema                                      │\n";
    cout << "└─────────────────────────────────────────────────────────────┘\n";
    cout << "Ingrese su opción: ";
}

/**
 * Función para mostrar todas las películas en cartelera
 * Propósito: Listar información de las películas disponibles
 * 
 * Demuestra:
 * - Iteración con bucle for
 * - Acceso a datos de estructura
 * - Formato de salida con iomanip
 */
void mostrarCartelera() {
    limpiarPantalla();
    mostrarEncabezado();
    
    if (cantidadPeliculas == 0) {
        cout << "\n⚠️  No hay películas en cartelera.\n";
        return;
    }
    
    cout << "\n📽️  CARTELERA DE PELÍCULAS\n";
    cout << "─────────────────────────────────────────────────────────────\n";
    
    for (int i = 0; i < cantidadPeliculas; i++) {
        cout << "\n[ID: " << peliculas[i].id << "] " << peliculas[i].titulo << "\n";
        cout << "  Género: " << peliculas[i].genero << " | Duración: " 
             << peliculas[i].duracion << " min\n";
        cout << "  Clasificación: " << peliculas[i].clasificacion 
             << " | Precio: $" << fixed << setprecision(2) << peliculas[i].precioEntrada << "\n";
    }
    
    cout << "\n" << string(60, '─') << "\n";
}

/**
 * Función para mostrar todas las funciones disponibles
 * Parámetros:
 *   - filtrarPorPelicula: si es >= 0, solo muestra funciones de esa película
 * 
 * Demuestra:
 * - Decisiones condicionales en presentación
 * - Cálculo de porcentaje de ocupación
 */
void mostrarFunciones(int filtrarPorPelicula = -1) {
    limpiarPantalla();
    mostrarEncabezado();
    
    if (cantidadFunciones == 0) {
        cout << "\n⚠️  No hay funciones disponibles.\n";
        return;
    }
    
    cout << "\n🎬 FUNCIONES DISPONIBLES\n";
    cout << "─────────────────────────────────────────────────────────────\n";
    
    int conteo = 0;
    
    for (int i = 0; i < cantidadFunciones; i++) {
        // Aplicar filtro si se requiere
        if (filtrarPorPelicula != -1 && funciones[i].idPelicula != filtrarPorPelicula) {
            continue;
        }
        
        int indicePeli = obtenerIndicePelicula(funciones[i].idPelicula);
        if (indicePeli == -1) continue;
        
        int porcentajeOcupacion = ((ASIENTOS_POR_SALA - funciones[i].asientosDisponibles) * 100)
                                  / ASIENTOS_POR_SALA;
        
        cout << "\n[Función ID: " << funciones[i].id << "]\n";
        cout << "  Película: " << peliculas[indicePeli].titulo << "\n";
        cout << "  Hora: " << funciones[i].hora << " | Sala: " << funciones[i].salaNumero << "\n";
        cout << "  Asientos disponibles: " << funciones[i].asientosDisponibles << " / " 
             << ASIENTOS_POR_SALA << " (Ocupación: " << porcentajeOcupacion << "%)\n";
        
        conteo++;
    }
    
    if (conteo == 0) {
        cout << "\n⚠️  No hay funciones disponibles.\n";
    }
    
    cout << "\n" << string(60, '─') << "\n";
}

/**
 * Función para mostrar el estado de todas las salas
 * Propósito: Visualizar ocupación de salas
 * 
 * Demuestra:
 * - Procesamiento de datos múltiples
 * - Estadísticas
 */
void mostrarEstadoSalas() {
    limpiarPantalla();
    mostrarEncabezado();
    
    cout << "\n📊 ESTADO DE SALAS\n";
    cout << "─────────────────────────────────────────────────────────────\n";
    
    // Asumir máximo 5 salas en el cine
    for (int sala = 1; sala <= 5; sala++) {
        int asientosUsados = 0;
        int funcionesSala = 0;
        
        // Calcular ocupación por sala
        for (int i = 0; i < cantidadFunciones; i++) {
            if (funciones[i].salaNumero == sala) {
                asientosUsados += funciones[i].asientosVendidos;
                funcionesSala++;
            }
        }
        
        if (funcionesSala > 0) {
            int capacidadTotal = funcionesSala * ASIENTOS_POR_SALA;
            int porcentaje = (asientosUsados * 100) / capacidadTotal;
            
            cout << "\nSala " << sala << ":\n";
            cout << "  Funciones: " << funcionesSala << "\n";
            cout << "  Asientos vendidos: " << asientosUsados << " / " << capacidadTotal << "\n";
            cout << "  Ocupación: " << porcentaje << "%\n";
            
            // Barra de ocupación visual
            cout << "  [";
            for (int j = 0; j < 20; j++) {
                if (j < (porcentaje / 5)) {
                    cout << "█";
                } else {
                    cout << "░";
                }
            }
            cout << "]\n";
        }
    }
    
    cout << "\n" << string(60, '─') << "\n";
}

/**
 * Función para mostrar todas las ventas realizadas
 * Propósito: Reporte de transacciones
 * 
 * Demuestra:
 * - Iteración y presentación de datos
 * - Cálculos aritméticos (suma de montos)
 */
void mostrarVentas() {
    limpiarPantalla();
    mostrarEncabezado();
    
    if (cantidadVentas == 0) {
        cout << "\n💰 REPORTE DE VENTAS\n";
        cout << "─────────────────────────────────────────────────────────────\n";
        cout << "\n⚠️  No hay ventas registradas.\n";
        return;
    }
    
    cout << "\n💰 REPORTE DE VENTAS\n";
    cout << "─────────────────────────────────────────────────────────────\n";
    
    float montoTotal = 0;
    int totalAsientos = 0;
    
    cout << left << setw(15) << "ID Función" << setw(15) << "Asientos" 
         << setw(15) << "Monto ($)" << "\n";
    cout << string(45, '─') << "\n";
    
    for (int i = 0; i < cantidadVentas; i++) {
        cout << left << setw(15) << ventas[i].idFuncion 
             << setw(15) << ventas[i].cantidadAsientos
             << setw(15) << fixed << setprecision(2) << ventas[i].montoTotal << "\n";
        
        montoTotal += ventas[i].montoTotal;
        totalAsientos += ventas[i].cantidadAsientos;
    }
    
    cout << string(45, '─') << "\n";
    cout << "Total: " << totalAsientos << " asientos vendidos por $" 
         << fixed << setprecision(2) << montoTotal << "\n";
    cout << "\n" << string(60, '─') << "\n";
}

// ============================================================================
// FUNCIONES DE OPERACIÓN / PROCESOS PRINCIPALES
// ============================================================================

/**
 * Función para realizar la compra de una entrada
 * Parámetros:
 *   - idFuncion: identificador de la función elegida
 *   - cantidadAsientos: número de asientos a comprar
 * 
 * Demuestra:
 * - Validación de disponibilidad
 * - Cálculo de monto a pagar
 * - Registro de venta
 * - Actualización de disponibilidad
 * - Paso de parámetros por valor
 */
void comprarEntrada(int idFuncion, int cantidadAsientos) {
    // Validar que la función existe
    int indiceFuncion = obtenerIndiceFuncion(idFuncion);
    if (indiceFuncion == -1) {
        cout << "\n❌ Error: Función no encontrada.\n";
        return;
    }
    
    // Validar cantidad de asientos
    if (cantidadAsientos <= 0) {
        cout << "\n❌ Error: Debe comprar al menos 1 asiento.\n";
        return;
    }
    
    Funcion& funcion = funciones[indiceFuncion];
    
    // Validar disponibilidad
    if (cantidadAsientos > funcion.asientosDisponibles) {
        cout << "\n❌ Error: Solo hay " << funcion.asientosDisponibles 
             << " asientos disponibles.\n";
        return;
    }
    
    // Obtener película para cálculo de precio
    int indicePelicula = obtenerIndicePelicula(funcion.idPelicula);
    if (indicePelicula == -1) {
        cout << "\n❌ Error: Película no encontrada.\n";
        return;
    }
    
    Pelicula& pelicula = peliculas[indicePelicula];
    
    // Calcular monto total
    float montoTotal = cantidadAsientos * pelicula.precioEntrada;
    
    // Actualizar información de la función
    funcion.asientosDisponibles -= cantidadAsientos;
    funcion.asientosVendidos += cantidadAsientos;
    
    // Registrar la venta
    if (cantidadVentas < MAX_VENTAS) {
        ventas[cantidadVentas].idFuncion = idFuncion;
        ventas[cantidadVentas].cantidadAsientos = cantidadAsientos;
        ventas[cantidadVentas].montoTotal = montoTotal;
        cantidadVentas++;
    }
    
    // Presentar confirmación
    cout << "\n✅ ENTRADA COMPRADA EXITOSAMENTE\n";
    cout << "─────────────────────────────────────────────────────────────\n";
    cout << "Película: " << pelicula.titulo << "\n";
    cout << "Función: " << funcion.hora << " (Sala " << funcion.salaNumero << ")\n";
    cout << "Asientos: " << cantidadAsientos << "\n";
    cout << "Precio unitario: $" << fixed << setprecision(2) << pelicula.precioEntrada << "\n";
    cout << "TOTAL A PAGAR: $" << fixed << setprecision(2) << montoTotal << "\n";
    cout << "\n¡Gracias por su compra!\n";
}

/**
 * Proceso interactivo para comprar entrada
 * Guía al usuario a través del proceso de compra
 * 
 * Demuestra:
 * - Flujo interactivo
 * - Validación de entrada del usuario
 * - Llamada a funciones de operación
 */
void procesarCompraEntrada() {
    limpiarPantalla();
    mostrarEncabezado();
    
    cout << "\n🎫 COMPRAR ENTRADA\n";
    cout << "─────────────────────────────────────────────────────────────\n";
    
    // Mostrar funciones disponibles
    mostrarFunciones(-1);
    cout << "\n";
    
    // Solicitar ID de función
    int idFuncion;
    cout << "Ingrese el ID de la función elegida (o 0 para cancelar): ";
    cin >> idFuncion;
    
    if (idFuncion == 0) {
        cout << "\nCompra cancelada.\n";
        return;
    }
    
    // Solicitar cantidad de asientos
    int cantidadAsientos;
    cout << "¿Cuántos asientos desea comprar? ";
    cin >> cantidadAsientos;
    
    // Procesar compra
    comprarEntrada(idFuncion, cantidadAsientos);
}

// ============================================================================
// FUNCIÓN PRINCIPAL
// ============================================================================

/**
 * Función main - Punto de entrada del programa
 * Propósito: Controlar el flujo principal de la aplicación
 * 
 * Demuestra:
 * - Estructura de programa con menú
 * - Bucle principal do-while
 * - Llamada a funciones
 * - Manejo de entrada del usuario
 */
int main() {
    // Inicializar datos de ejemplo
    cargarPeliculasEjemplo();
    cargarFuncionesEjemplo();
    
    int opcion;
    bool salir = false;
    
    // Bucle principal del programa
    do {
        limpiarPantalla();
        mostrarEncabezado();
        mostrarMenuPrincipal();
        
        cin >> opcion;
        cin.ignore();  // Limpiar buffer de entrada
        
        // Decidir qué hacer según la opción elegida
        switch(opcion) {
            case 1:
                mostrarCartelera();
                pausa();
                break;
                
            case 2:
                mostrarFunciones(-1);
                pausa();
                break;
                
            case 3:
                procesarCompraEntrada();
                pausa();
                break;
                
            case 4:
                mostrarEstadoSalas();
                pausa();
                break;
                
            case 5:
                mostrarVentas();
                pausa();
                break;
                
            case 0:
                limpiarPantalla();
                mostrarEncabezado();
                cout << "\n👋 ¡Gracias por usar el Sistema de Gestión de Cine!\n";
                cout << "Hasta pronto...\n\n";
                salir = true;
                break;
                
            default:
                cout << "\n❌ Opción inválida. Intente nuevamente.\n";
                pausa();
        }
        
    } while (!salir);
    
    return 0;  // El programa termina exitosamente
}

/*
 * ============================================================================
 * RESUMEN DE CONCEPTOS EDUCATIVOS DEMOSTRADOS
 * ============================================================================
 * 
 * 1. ESTRUCTURAS (structs):
 *    - Pelicula: Agrupa información sobre películas
 *    - Funcion: Agrupa información sobre sesiones
 *    - Venta: Agrupa información sobre transacciones
 * 
 * 2. ARREGLOS:
 *    - Arrays de estructuras para almacenar múltiples películas, funciones, ventas
 *    - Manejo de límites MAX_PELICULAS, MAX_FUNCIONES, etc.
 * 
 * 3. FUNCIONES:
 *    - Funciones con parámetros y retorno de valores
 *    - Paso de parámetros por valor y referencia
 *    - Funciones de validación, búsqueda, presentación y operación
 * 
 * 4. CONTROL DE FLUJO:
 *    - Bucles (for, do-while)
 *    - Condicionales (if-else, switch-case)
 *    - Decisiones lógicas
 * 
 * 5. ENTRADA/SALIDA:
 *    - cin: Lectura de datos del usuario
 *    - cout: Presentación de resultados
 *    - iomanip: Formato de salida
 * 
 * 6. VALIDACIÓN DE DATOS:
 *    - Verificación de existencia de datos
 *    - Validación de rangos
 *    - Verificación de disponibilidad
 * 
 * 7. MENÚ INTERACTIVO:
 *    - Presentación clara de opciones
 *    - Flujo de usuario amigable
 *    - Manejo de errores
 * 
 * ============================================================================
 */
