/*
 * 
 * Implementación del TAD Árbol General mediante
 * un celdas enlazadas.
 *
 */


#ifndef AGEN_CEL_ENLAZADAS_H
#define AGEN_CEL_ENLAZADAS_H



template <typename T> class AGEN_CEL_ENLAZADAS_H
{
    struct celda;

    public:
        typedef celda* nodo;
        static const nodo NODO_NULO;

        Agen();
        Agen(const Agen<T>& Arbol);
        ~Agen();
        Agen<T>& operator =(const Agen<T>& Arbol);

        void insertarRaiz(const T& e);
        void insertarHijoIzqdo(nodo n, const T& e);
        void insertarHermDrcho(nodo n, const T& e);

        bool arbolVacio();
        const T& elemento(nodo n) const;
        T& elemento(nodo n);

        nodo padre(nodo n) const;
        nodo raiz() const;
        nodo hijoIzqdo(nodo n) const;
        nodo hermDrcho(nodo n) const;

        void eliminarRaiz();
        void eliminarHijoIzqdo(nodo n);
        void eliminarHermDrcho(nodo n);

    private:
        struct celda
        {
            T elto;
            nodo padre, hizq, heder;

            celda(const T& e, nodo p = NODO_NULO) :
                elto(e),
                padre(p),
                hizq(NODO_NULO),
                heder(NODO_NULO)
            {}
        }
        nodo r;

        void destruirNodos(nodo& n);
        nodo copiar(nodo n);
};


/********************************/
/********************************/
/*  Definición del nodo nulo    */
/********************************/
/********************************/

template <typename T>
    const typename Agen<T>::nodo Agen<T>::NODO_NULO(0);


/********************************/
/********************************/
/*  Definición de los métodos   */
/********************************/
/********************************/


template <typename T>
    inline Agen<T>::Agen() :
        r(NODO_NULO)
    {}


template <typename T>
    Agen<T>::Agen(const Agen<T>& Arbol)
    {
        r = copiar(Arbol.r);
    }


template <typename T>
    inline Agen<T>::~Agen()
    {
        destruirNodos(r);
    }


template <typename T>
    Agen<T>& Agen<T>::operator =(const Agen<T>& Arbol)
    {
        if(this != &Arbol)
        {
            this->~Agen();
            r = copiar(Arbol.r);
        }
        return *this;
    }


template <typename T>
    inline void Agen<T>::insertarRaiz(const T& e)
    {
        assert(r == NODO_NULO);

        r = new celda(e);
    }


template <typename T>
    inline void Agen<T>::insertarHijoIzqdo(Agen<T>::nodo n, const T& e)
    {
        assert(n != NODO_NULO);

        //Guardamos el hijo izquierdo actual.
        nodo hizqdo = n->hizq;
        //En la posición del hijo izquierdo metemos el nuevo nodo.
        n->hizq = new celda(e, n);
        //El que antes era hijo izquierdo, se convierte en hermano derecho del nuevo nodo izquierdo.
        n->hizq->heder = hizqdo;
    }


template <typename T>
    inline void Agen<T>::insertarHermDrcho(Agen<T>::nodo n, const T& e)
    {
        assert(n != NODO_NULO);
        assert(n != r);

        //Guardamos el hermano derecho actual.
        nodo hedrcho = h->heder;
        //En la posición del hermano derecho metemos el nuevo nodo.
        n->heder = new celda(e, n->padre);
        //El antiguo nodo de ese lugar se convierte en el hermano derecho del nuevo nodo.
        n->heder->heder = hedrcho;
    }


template <typename T>
    inline void Agen<T>::eliminarRaiz()
    {
        assert(r != NODO_NULO);
        assert(r->hizq != NODO_NULO);

        delete(r);
        r = NODO_NULO);
    }

template <typename T>
    inline void Agen<T>::eliminarHijoIzqdo(Agen<T>::nodo n)
    {
        nodo hizqdo;

        assert(n != NODO_NULO);             //Nodo n existe;
        hizqdo = n->hizq;
        assert(hizqdo != NODO_NULO);        //Hijo izquierdo de nodo n existe;
        assert(hizqdo->hizq == NODO_NULO);  //Hijo izquierdo de nodo n es hoja.

        //El hermano derecho del nodo eliminado se convierte en el nuevo hijo izquierdo.
        n->hizq = hizqdo->heder;
        delete(hizqdo);
    }


template <typename T>
    inline void Agen<T>::eliminarHermDrcho(nodo n)
    {
        nodo hedrcho;

        assert(n != NODO_NULO);             //Nodo n existe;
        hedrcho = n->heder;
        assert(hedrcho != NODO_NULO);       //Hermano derecho de nodo n existe;
        assert(hedrcho->hizq == NODO_NULO); //Hermano derecho de nodo n es hoja.

        //El hermano derecho del nodo eliminado se convierte en el nuevo hermano derecho del nodo n.
        n->heder = hedrcho->heder;
        delete(hedrcho);
    }


template <typename T>
    inline bool Agen<T>::arbolVacio() const
    {
        return (r == NODO_NULO);
    }


template <typename T>
    inline const T& Agen<T>::elemento(Agen<T>::nodo n) const
    {
        assert(n != NODO_NULO);         //Nodo n existe;

        return n->elto;
    }


template <typename T>
    inline T& Agen<T>::elemento(Agen<T>::nodo n)
    {
        assert(n != NODO_NULO);         //Nodo n existe;

        return n->elto;
    }


template <typename T>
    inline typename Agen<T>::nodo Agen<T>::raiz() const
    {
        return r;
    }


template <typename T>
    inline typename Agen<T>::nodo Agen<T>::padre(Agen<T>::nodo n) const
    {
        assert(n != NODO_NULO);

        return n->padre;
    }

template <typename T>
    inline typename Agen<T>::nodo Agen<T>::hijoIzqdo(Agen<T>::nodo n) const
    {
        assert(n != NODO_NULO);

        return n->hizq;
    }


template <typename T>
    inline typename Agen<T>::nodo Agen<T>::hermDrcho(Agen<T>::nodo n) const
    {
        assert(n != NODO_NULO);

        return n->heder;
    }



template <typename T>
    void Agen<T>::destruirNodos(Agen<T>::nodo& n)
    {
        if(n != NODO_NULO)
        {
            if(n->hizq != NODO_NULO)
            {
                nodo hedrcho = n->hizq->heder;
                while(hedrcho != NODO_NULO)
                {
                    n->hizq->heder = hedrcho->heder;
                    destruirNodos(hedrcho);
                    hedrcho = n->hizq->heder;
                }
                destruirNodos(n->hizq);
            }
            delete(n);
            n = NODO_NULO;
        }
    }


template <typename T>
    typename Agen<T>::nodo Agen<T>::copiar(Agen<T>::nodo n)
    {
        nodo m = NODO_NULO;
        
        if(n != NODO_NULO)
        {
            m = new celda(n->elto);         //Copiar nodo n.
            if(n->hizq != NODO_NULO)        //Nodo n es hoja.
            {
                m->hizq = copiar(n->hizq);  //Copiar primer subárbol.
                m->hizq->padre = m;
                //Copiar el resto de subárboles.
                nodo hijo = m->hizq;                //Último subárbol copiado.
                nodo hedrcho = n->hizq->heder;      //Siguiente subárbol a copiar.

                while(hedrcho != NODO_NULO)
                {
                    hijo = hijo->heder = copiar(hedrcho);
                    hijo->padre = m;
                    hedrcho = hedrcho->heder;
                }
            }
        }
        return m;
    }

#endif  //AGEN_CEL_ENLAZADAS_H