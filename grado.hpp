#ifndef GRADO_H
#define GRADO_H

#include "agenCelEnlazadas.hpp"

//Función llamadora de gradoNodoRecursivo
template <typename T>
    int grado(Agen<T>& Arbol)
    {
        return gradoNodoRecursivo(Arbol.raiz(), Arbol);
    }


//Precondición: ninguna.
//Postcondición: devuelve el grado de un nodo 'n' del árbol 'Arbol'.
template <typename T>
    int gradoNodoRecursivo(typename Agen<T>::nodo n, Agen<T>& Arbol)
    {
        int hijo, maxGrado;
     
        if (n == Agen<T>::NODO_NULO)
        {
            return 0;
        }
        else
        {
            maxGrado = cuentaHijos(n, Arbol);
            hijo = Arbol.hijoIzqdo(n);
            while (hijo != NODO_NULO)
            {
                maxGrado = std::max(maxGrado, gradoNodoRecursivo(hijo, Arbol));
                hijo = Arbol.hermDrcho(n);
            }

            return grado;
        }
    }


//Precondición: 'n' no puede ser un nodo nulo.
//Postcondición: devuelve el número de hijos del nodo 'n'.
template <typename T>
    int cuentaHijos(typename Agen<T>::nodo n, Agen<T>& Arbol)
    {
        int numHijos;
        nodo hijo;

        numHijos = 0;
        hijo = Arbol.hijoIzqdo(n);

        while (n != NODO_NULO)
        {
            numHijos += 1;
            hijo = Arbol.hermDrcho(n);
        }

        return numHijos;
    }


//Precondición: 'n' no puede ser un nodo nulo.
//Postcondición: devuelve el grado más alto de entre todos los hijos del nodo 'n'.
template <typename T>
    int maximoGradoHijos(typename Agen<T>::nodo n, Agen<T>& Arbol)
    {
        int mayorActual, temp;
        nodo hijo;

        mayorActual = 0;
        hijo = Arbol.hijoIzqdo(n);

        while(hijo != NODO_NULO)
        {
            temp = gradoNodo(hijo, Arbol);
            if(temp > mayorActual)
            {
                mayorActual = temp;
            }
            hijo = Arbol.hermDrcho(hijo);
        }

        return mayorActual;
    }


#endif  //GRADO_H