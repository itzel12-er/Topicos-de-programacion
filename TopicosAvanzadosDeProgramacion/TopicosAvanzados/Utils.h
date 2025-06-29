// Este archivo contiene funciones utilitarias gen�ricas
#ifndef UTILS_H
#define UTILS_H

// Declaraci�n de la funci�n plantilla PrintArray
template <typename T>
void PrintArray(const T* arr, size_t size) {
    // Verifica si el array y su tama�o son v�lidos
    if (arr == nullptr || size == 0) {
        return; // Sale si no hay datos que imprimir
    }

    // Itera desde el inicio hasta el final del array e imprime cada elemento
    for (size_t i = 0; i < size; ++i) {
        std::cout << arr[i] << " "; // Imprime el elemento actual
    }
    std::cout << std::endl; // Agrega una nueva l�nea al final
}

#endif