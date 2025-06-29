// Este archivo contiene el punto de entrada del programa para probar LinkedList
#include <iostream>
#include "LinkedList.h"

int main() {
    // Crea una lista de enteros
    LinkedList<int> lista;
    // Inserta elementos al inicio
    lista.push_front(20);    // Primero 20
    lista.push_front(10);    // Luego 10
    // Imprime la lista
    std::cout << "Lista: ";
    lista.print();           // Debería mostrar: 10 20
    // Elimina el primer elemento
    lista.pop_front();
    std::cout << "Después de pop_front: ";
    lista.print();           // Debería mostrar: 20
    std::cin.get();          // Pausa la consola
    return 0;
}