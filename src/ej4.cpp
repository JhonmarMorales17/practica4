#include <iostream>
#include <cstdlib> // Para rand() y srand()
#include <ctime>   // Para time()
using namespace std;

// Funcion que realiza un proceso cualquiera
void procesoCualquiera() {
    static int contador = 0;
    contador++;
    cout << "Ejecutando el proceso. Esta funcion ha sido llamada " << contador << " veces." << endl;
}

// Funcion para obtener el número de veces que se llamó a la función anterior
int obtenerContador() {
    static int contador = 0;
    return contador;
}

int main() {
    // Inicializar la semilla para numeros aleatorios
    srand(static_cast<unsigned>(time(0)));

    // Generar un número aleatorio entre 1 y 10
    int numeroLlamadas = rand() % 10 + 1;

    cout << "Llamando a la funcion " << numeroLlamadas << " veces:" << endl;

    // Llamar a la funcion aleatoriamente entre 1 y 10 veces
    for (int i = 0; i < numeroLlamadas; i++) {
        procesoCualquiera();
    }

    return 0;
}

