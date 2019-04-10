#ifndef ES_ARBOL_TERNARIO_HPP
#define	ES_ARBOL_TERNARIO_HPP

#include "agenCelEnlazadas.hpp"
// En esta cabecera está declarada la función 'cuentaHijos()'.
#include "grado.hpp"


/*		Ejercicio 4 de la práctica 5 de EDNL		*/

template <typename T>
bool esArbolTernario(const Agen<T>& Arbol)
{
	return esArbolTernario(Arbol.raiz(), Arbol);
}

template <typename T>
bool esArbolTernario(typename Agen<T>::nodo n, const Agen<T>& Arbol)
{
	int nHijos;

	if (nodo == Agen<T>::NODO_NULO)
	{
		return true;
	}
	else
	{
		nHijos = cuentaHijos(n, Arbol);
		if (nHijos == 0)
		{
			return true;
		}
		else
		{
			if (nHijos != 3)
			{
				return false;
			}
			else
			{
				return (esArbolTernario(Arbol.hijoIzqdo(n), Arbol) &&
					esArbolTernario(Arbol.hermDrcho(Arbol.hijoIzqdo(n)), Arbol) &&
					esArbolTernario(Arbol.hermDrcho(Arbol.hermDrcho(Arbol.hijoIzqdo(n))), Arbol));
			}
		}
	}
}

#endif // !ES_ARBOL_TERNARIO_HPP
