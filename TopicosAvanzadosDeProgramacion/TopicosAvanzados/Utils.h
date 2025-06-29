// Este archivo contiene funciones utilitarias genéricas
#ifndef UTILS_H
#define UTILS_H

// Declaración de la función plantilla PrintArray
template <typename T>
void PrintArray(const T* arr, size_t size) {
    // Verifica si el array y su tamaño son válidos
    if (arr == nullptr || size == 0) {
        return; // Sale si no hay datos que imprimir
    }

    // Itera desde el inicio hasta el final del array e imprime cada elemento
    for (size_t i = 0; i < size; ++i) {
        std::cout << arr[i] << " "; // Imprime el elemento actual
    }
    std::cout << std::endl; // Agrega una nueva línea al final
}

#endif