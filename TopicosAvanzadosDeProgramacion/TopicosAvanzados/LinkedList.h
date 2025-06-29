// Este archivo define la clase LinkedList como plantilla para manejar listas enlazadas
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>

template <typename T>
class LinkedList {
private:
    // Estructura interna para los nodos de la lista
    struct Node {
        T data;        // Almacena el dato del nodo
        Node* next;    // Puntero al siguiente nodo
        Node(const T& value) : data(value), next(nullptr) {}
    };
    Node* head;    // Puntero al inicio de la lista

public:
    LinkedList() : head(nullptr) {}    // Inicializa la lista vacía
    void push_front(const T& value);   // Inserta un elemento al inicio
    void pop_front();                 // Elimina el elemento del inicio
    void print() const;               // Imprime todos los elementos
};

// Implementación de las funciones
template <typename T>
void LinkedList<T>::push_front(const T& value) {
    // Crea un nuevo nodo con el valor dado
    Node* newNode = new Node(value);
    // El nuevo nodo apunta al antiguo head
    newNode->next = head;
    // Actualiza head al nuevo nodo
    head = newNode;
}

template <typename T>
void LinkedList<T>::pop_front() {
    // Verifica si la lista no está vacía
    if (head) {
        Node* temp = head;    // Guarda el nodo a eliminar
        head = head->next;    // Actualiza head al siguiente
        delete temp;          // Libera la memoria del nodo
    }
}

template <typename T>
void LinkedList<T>::print() const {
    // Apunta al inicio de la lista
    Node* current = head;
    // Recorre e imprime cada elemento hasta el final
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;    // Nueva línea al final
}

#endif