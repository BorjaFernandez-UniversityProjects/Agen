#ifndef PROFUNDIDAD_NODO_H
#define PROFUNDIDAD_NODO_H


#include "agenCelEnlazadas.hpp"


//Postcondición: devuelve la profundidad de un nodo dado ('n') del árbol general ('Arbol').
template <typename T>
    int profundidadNodo(typename Abin<T>::nodo n, Agen<T>& Arbol)
    {
        if(n == Agen<T>::NODO_NULO)
        {
            return -1;
        }
        else
        {
            if(n == Arbol.raiz())
            {
                return 0;
            }
            else
            {
                return 1 + profundidadNodo(Arbol.padre(n), Arbol);
            }
        }
    }


#endif  //PROFUNDIDAD_NODO_H