#ifndef DESEQUILIBRIO_H
#define DESEQUILIBRIO_H



//Función llamadora de desequilibrioNodo
template <typename T>
    int desequilibrio(Agen<T>& Arbol)
    {
        return desequilibrio(Arbol.raiz(), Arbol);
    }



//Precondición: ninguna.
//Postcondición: devuelve el desequilibrio del nodo 'n' del árbol 'Arbol'.
template <typename t>
    int desequilibrioNodo(Agen<T>::nodo n, Agen<T>& Arbol)
    {
        int altMaxima, altMinima;
        nodo hijo;

        if(n == Agen<T>::NODO_NULO)
        {
            return -1;
        }
        else{
            hijo = Arbol.hijoizqdo(n);
            altMinima = desequilibrioNodo(hijo, Arbol);
            altMaxima = 0;

            while(hijo != NODO_NULO)
            {
                altMaxima = std::max(altMaxima, desequilibrioNodo(hijo, Arbol));
                altMinima = std::min(altMinima, desequilibrioNodo(hijo, Arbol));
                hijo = Arbol.hermDrcho(hijo);
            }
            return (alMaxima -altMinima +1);
        }
    }



#endif  //DESEQUILIBRIO