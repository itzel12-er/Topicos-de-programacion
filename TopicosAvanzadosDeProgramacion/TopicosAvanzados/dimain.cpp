// Este archivo contiene el punto de entrada del programa para probar DynamicArray
#include <iostream>
#include "DynamicArray.h"

int main() {
    // Crea un DynamicArray de enteros
    DynamicArray<int> myDynamicArray;
    // Añade un elemento
    myDynamicArray.Append(1984);
    // Accede e imprime usando el operador []
    std::cout << "Elemento en índice 0: " << myDynamicArray[0] << std::endl; // Debería imprimir 1984
    // Añade más elementos
    myDynamicArray.push_back(2023);
    std::cout << "Elemento en índice 1: " << myDynamicArray[1] << std::endl; // Debería imprimir 2023
    // Elimina el último elemento
    myDynamicArray.pop_back();
    std::cout << "Tamaño después de pop_back: " << myDynamicArray.getSize() << std::endl; // Debería ser 1
    // Ajusta la capacidad
    myDynamicArray.shrink_to_fit();
    std::cout << "Tamaño después de shrink_to_fit: " << myDynamicArray.getSize() << std::endl; // Debería ser 1
#if COUNT_DYNAMIC_ARRAY_COPIES != 0
    std::cout << "Número de copias: " << myDynamicArray.getCopyCounter() << std::endl; // Usa el getter
#endif
    std::cin.get(); // Pausa la consola
    return 0;
}