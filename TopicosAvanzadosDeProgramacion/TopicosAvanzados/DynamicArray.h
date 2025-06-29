// Este archivo define la clase DynamicArray como plantilla para manejar arreglos din�micos
#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#include <iostream>

#define COUNT_DYNAMIC_ARRAY_COPIES 1 // Define el contador de copias al inicio

template <typename T>
class DynamicArray {
private:
    T* data;                    // Puntero al arreglo din�mico
    size_t capacity;            // Capacidad total del arreglo
    size_t size;                // N�mero de elementos actuales
#if COUNT_DYNAMIC_ARRAY_COPIES != 0
    int copyCounter;            // Contador de copias durante resize
#endif

public:
    DynamicArray() : data(nullptr), capacity(0), size(0) {
#if COUNT_DYNAMIC_ARRAY_COPIES != 0
        copyCounter = 0;        // Inicializa el contador de copias
#endif
    }
    ~DynamicArray();            // Libera la memoria asignada
    void Append(const T& value); // A�ade un elemento al final
    void push_back(const T& value); // A�ade un elemento al final
    void pop_back();            // Elimina el �ltimo elemento
    void shrink_to_fit();       // Ajusta la capacidad al tama�o actual
    T& operator[](size_t index); // Sobrecarga del operador [] para acceso
    size_t getSize() const { return size; } // Devuelve el n�mero de elementos
#if COUNT_DYNAMIC_ARRAY_COPIES != 0
    int getCopyCounter() const { return copyCounter; } // Devuelve el contador de copias
#endif
};

// Implementaci�n de las funciones
template <typename T>
DynamicArray<T>::~DynamicArray() {
    // Libera la memoria asignada al arreglo
    delete[] data;
}

template <typename T>
void DynamicArray<T>::Append(const T& value) {
    // Si el tama�o es igual a la capacidad, redimensiona
    if (size == capacity) {
        capacity = (capacity == 0) ? 1 : capacity * 2;
        T* newData = new T[capacity];
        for (size_t i = 0; i < size; ++i) {
            newData[i] = data[i];
#if COUNT_DYNAMIC_ARRAY_COPIES != 0
            copyCounter++;      // Incrementa el contador por cada copia
#endif
        }
        delete[] data;
        data = newData;
    }
    data[size++] = value;       // A�ade el nuevo elemento
}

template <typename T>
void DynamicArray<T>::push_back(const T& value) {
    // A�ade un elemento al final, similar a Append
    Append(value);              // Reutiliza la l�gica de Append
}

template <typename T>
void DynamicArray<T>::pop_back() {
    // Elimina el �ltimo elemento si la lista no est� vac�a
    if (size > 0) {
        --size;                 // Reduce el tama�o
    }
}

template <typename T>
void DynamicArray<T>::shrink_to_fit() {
    // Ajusta la capacidad al tama�o actual para ahorrar memoria
    if (capacity > size) {
        capacity = size;
        T* newData = new T[capacity];
        for (size_t i = 0; i < size; ++i) {
            newData[i] = data[i];
#if COUNT_DYNAMIC_ARRAY_COPIES != 0
            copyCounter++;      // Incrementa el contador por cada copia
#endif
        }
        delete[] data;
        data = newData;
    }
}

template <typename T>
T& DynamicArray<T>::operator[](size_t index) {
    // Sobrecarga del operador [] para acceder a elementos
    if (index >= size) {
        throw std::out_of_range("�ndice fuera de rango");
    }
    return data[index];         // Devuelve la referencia al elemento
}

#endif