// Este archivo contiene el punto de entrada del programa
#include <iostream>
#include "Utils.h" // Incluye las funciones utilitarias

int main() {
    // Define un array de enteros para probar la función
    int intArray[] = { 1, 2, 3, 4, 5 };
    size_t intSize = sizeof(intArray) / sizeof(intArray[0]);

    // Define un array de doubles para probar con otro tipo
    double doubleArray[] = { 1.1, 2.2, 3.3 };
    size_t doubleSize = sizeof(doubleArray) / sizeof(doubleArray[0]);

    // Llama a PrintArray con el array de enteros
    std::cout << "Array de enteros: ";
    PrintArray(intArray, intSize);

    // Llama a PrintArray con el array de doubles
    std::cout << "Array de doubles: ";
    PrintArray(doubleArray, doubleSize);
    std::cin.get(); // Pausa la consola
    return 0; // Termina el programa
}