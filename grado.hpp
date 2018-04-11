#ifndef GRADO_H
#define GRADO_H

#include "agenCelEnlazadas.hpp"


template <typename T>
    int grado(Agen<T>& Arbol)
    {
        return grado(Arbol.raiz(), Arbol);
    }


template <typename T>
    int gradoNodo(Agen<T>::nodo n, Agen<T>& Arbol)
    {
            int nHijos, mayorActual;
     
        if(n == Agen<T>::NODO_NULO)
        {
            return 0;
        }
        else
        {

            nHijos = cuentaHijos(n, Arbol);
            mayorActual = maximoGradoHijos(n, Arbol);

            if(nHijos > mayorActual)
            {
                return nHijos;
            }
            else
            {
                return mayorActual;
            }
        }
    }



template <typename T>
    int cuentaHijos(Agen<T>::nodo n, Agen<T>& Arbol)
    {
        int hijo, nHijos;

        nHijos = 0;
        hijo = Arbol.hijoIzqdo(n);

        while(n != NODO_NULO)
        {
            nHijos++;
            hijo = Arbol.hermDrcho(n);
        }

        return nHijos;
    }


template <typename T>
    int maximoGradoHijos(Agen<T>::nodo n, Agen<T>& Arbol)
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