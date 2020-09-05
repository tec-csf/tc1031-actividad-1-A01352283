#include <iostream>
#include <algorithm>
#include <time.h>
#include <chrono>
#include <iterator>
#include <vector>

int busquedaSecuencial(std::vector<int> vect, int N, int valor){
    int i = 0;
    int encontrado = -1;
    while (encontrado == -1 && i < N){
        if ( valor == vect[i] ) {
            encontrado = i;
        }
         i++;
    }
    return encontrado;
}

int main() {

    //Establecer la semilla
    srand((unsigned int) time(nullptr));

    //Definir cantidad de elementos
    const int n = 100000;

    //Indice del numero buscado
    int foundIndex = 0;

    //Numero a buscar
    int numToFind;

    //Pedida del numero a buscar
    std::cout << "Escribe el numero a buscar: ";
    std::cin >> numToFind;

    //Definir un vector de enteros
    std::vector<int> numeros(n);

    //Generar un vector de números enteros utilizando una función Lambda
    std::generate(numeros.begin(), numeros.end(), [](){return rand() % 100;});

    /*
    Busqueda secuencial
    */

    //Referencia de tiempo antes
    auto t1 = std::chrono::high_resolution_clock::now();

    //Busqueda
    foundIndex = busquedaSecuencial(numeros, n, numToFind);

    //Representacion
    std::cout << "Indice encontrado: " << foundIndex << std::endl;
    std::cout << "Comprobacion: " << numeros[foundIndex] << std::endl;

    //Referencia de tiempo despues
    auto t2 = std::chrono::high_resolution_clock::now();

    //Duracion medida
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();

    //Imprime duracion
    std::cout << std::endl << "Duracion secuencial: " << duration << " microsegundos" << std::endl;

    return 0;
}
