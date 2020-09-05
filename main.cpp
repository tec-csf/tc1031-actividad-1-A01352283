#include <iostream>
#include <algorithm>
#include "Ordenamiento.h"
#include <time.h>
#include <iterator>


int main(int argc, const char * argv[]) {

    /* Establecer la semilla del generador */
    srand((unsigned int) time(nullptr));

    /* Definir cantidad de elementos */
    const int n = 10;

    /*
    * Ordenar n�meros enteros
    */

    std::cout << "- Ordenamiento de n�meros enteros -" << std::endl;

    /* Definir un vector de enteros */
    std::vector<int> numeros(n);

    /* Generar un vector de n�meros enteros utilizando una funci�n Lambda */
    std::generate(numeros.begin(), numeros.end(), [](){return rand() % 100;});

    /* Imprimir el vector original */
    copy(numeros.begin(), numeros.end(), std::ostream_iterator<int>(std::cout, " "));

    std::cout << std::endl;

    /* Ordenar el vector de n�meros */
    numeros = Ordenamiento<int>::insercion(numeros, Ordenamiento<int>::asc);

    /* Imprimir el vector ordenado */
    std::copy(numeros.begin(), numeros.end(), std::ostream_iterator<int>(std::cout, " "));

    std::cout << std::endl << std::endl;

    /*
     * Ordenar n�meros en punto flotante
     */

    std::cout << "- Ordenamiento de n�meros flotantes -" << std::endl;

    /* Definir un vector de flotantes */
    std::vector<float> numeros_f(n);

    /* Generar un vector de n�meros enteros utilizando una funci�n Lambda */
    std::generate(numeros_f.begin(), numeros_f.end(), [](){return rand() % 100 * 0.5;});

    /* Imprimir el vector original */
    std::copy(numeros_f.begin(), numeros_f.end(), std::ostream_iterator<float>(std::cout, " "));

    std::cout << std::endl;

    /* Ordenar el vector de n�meros */
    numeros_f = Ordenamiento<float>::seleccion(numeros_f, Ordenamiento<float>::desc);

    /* Imprimir el vector ordenado */
    std::copy(numeros_f.begin(), numeros_f.end(), std::ostream_iterator<float>(std::cout, " "));

    std::cout << std::endl << std::endl;

    return 0;
}
