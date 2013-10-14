#ifndef CONJUNTO_HPP_
#define CONJUNTO_HPP_

#include <iostream>
#include "Lista.hpp"
using namespace std;

template <class T>
class Conjunto
{
	public:

		// Constructor. Genera un conjunto vacío.
		Conjunto();

		// Destructor. Debe dejar limpia la memoria.
		~Conjunto();

		// Decide si un elemento pertenece al conjunto o no.
		bool pertenece(const T&) const;

		// Inserta un elemento en el conjunto. Si éste ya existe,
		// el conjunto no se modifica.
		void insertar(const T&);

		// borra un elemento del conjunto. Si éste no existe,
		// el conjunto no se modifica.
		void remover(const T&);

		// devuelve el mínimo elemento del conjunto según <.
		const T& minimo() const;

		// devuelve el máximo elemento del conjunto según <.
		const T& maximo() const;

		// devuelve la cantidad de elementos que tiene el conjunto.
		unsigned int cardinal() const;

		// muestra el conjunto.
		void mostrar() const;

	private:

		// la representación de un nodo interno.
		struct Nodo
		{
			// el constructor, toma el elemento al que representa el nodo.
			Nodo(const T& v) : valor(v), izq(NULL), der(NULL) {}
			// el elemento al que representa el nodo.
			T valor;
			// puntero a la raíz del subárbol izquierdo.
			Nodo* izq;
			// puntero a la raíz del subárbol derecho.
			Nodo* der;
		};

		// puntero a la raíz de nuestro árbol.
		Nodo* raiz;
		unsigned int card;
		Lista<T> lista;
};


template <class T>
Conjunto<T>::Conjunto() : raiz(NULL),card(0),lista(){}



template <class T>
Conjunto<T>::~Conjunto() {
	while(raiz!= NULL){
		remover(raiz->valor);
	}
}

template <class T>
bool Conjunto<T>::pertenece(const T& t) const {
	Nodo* aux = raiz;
	while(aux!=NULL && aux->valor != t){
		if(t< aux->valor){
			aux = aux->izq;
		}
		else{
			aux = aux->der;
		}
	}
	return aux != NULL;
}

template <class T>
void Conjunto<T>::insertar(const T& t) {
	if(!(pertenece(t))){
		Nodo* nuevo = new Nodo(t);
		if (raiz == NULL){
			raiz = nuevo;
		}
		else{

			Nodo* aux = raiz;
			Nodo* aux2 = NULL;
			while(aux!=NULL){
				aux2 = aux;
				if(t < aux->valor){
					aux = aux->izq;
				}
				else{
					aux = aux->der;
				}
			}
			if(t< aux2->valor){
				aux2->izq = nuevo;
			}
			else{
				aux2->der = nuevo;
			}
		}
		card++;
		lista.agregar(t);
	}
}

template <class T>
void Conjunto<T>::remover(const T& t){
	if(pertenece(t)){
		if (t==raiz->valor){
			if(raiz->izq == NULL && raiz->der == NULL){
				delete raiz;
				raiz = NULL;
			}
			else if (raiz->izq == NULL){
				Nodo* aux = raiz->der;
				Nodo* aux2 = NULL;
				while(aux->izq != NULL){
					aux2 = aux;
					aux = aux->izq;
				}
				if(aux2 == NULL){
					raiz->valor = aux->valor;
					raiz->der = aux->der;
					delete aux;
				}
				else{
					raiz->valor = aux->valor;
					aux2->izq = aux->der;
					delete aux;
				}
			}
			else{
				Nodo* sarasa = raiz->izq;
				Nodo* sarasa2 = NULL;
				while(sarasa->der != NULL){
					sarasa2 = sarasa;
					sarasa = sarasa->der;
				}
				if(sarasa2 == NULL){
					raiz->valor = sarasa->valor;
					raiz->izq = sarasa->izq;
					delete sarasa;
				}
				else{
					raiz->valor = sarasa->valor;
					sarasa2->der = sarasa->izq;
					delete sarasa;
				}
			}
		}
		else{
			Nodo* actual = raiz;
			Nodo* pactual = NULL;
			while(actual->valor != t){
				pactual = actual;
				if (t<actual->valor){
					actual = actual->izq;
				}
				else{
					actual = actual->der;
				}
			}
			if(actual->der == NULL && actual->izq == NULL){
				if(pactual->izq == actual){
					pactual->izq = NULL;
				}
				else{
					pactual->der = NULL;
				}
				delete actual;
			}
			else if (actual->izq == NULL){
				Nodo* auxiliar = actual->der;
				Nodo* pauxiliar = NULL;
				while(auxiliar->izq != NULL){
					pauxiliar = auxiliar;
					auxiliar = auxiliar->izq;
				}
				if(pauxiliar == NULL){
					actual->valor = auxiliar->valor;
					actual->der = auxiliar->der;
					delete auxiliar;
				}
				else{
					actual->valor = auxiliar->valor;
					pauxiliar->izq = auxiliar->der;
					delete auxiliar;
				}
			}
			else{
				Nodo* sanata = actual->izq;
				Nodo* psanata = NULL;
				while(sanata->der != NULL){
					psanata = sanata;
					sanata = sanata->der;
				}
				if(psanata == NULL){
					actual->valor = sanata->valor;
					actual->izq = sanata->izq;
					delete sanata;
				}
				else{
					actual->valor = sanata->valor;
					psanata->der = sanata->izq;
					delete sanata;
				}
			}
		}
		lista.quitar(t);
		card--;
	}
}

template <class T>
const T& Conjunto<T>::minimo() const {
	Nodo* aux = raiz;
	while(aux->izq != NULL){
		aux = aux->izq;
	}
	return aux->valor;
}

template <class T>
const T& Conjunto<T>::maximo() const {
	Nodo* aux = raiz;;
	while(aux->der != NULL){
		aux = aux->der;
	}
	return aux->valor;
}

template <class T>
unsigned int Conjunto<T>::cardinal() const {
	return card;
}

template <class T>
void Conjunto<T>::mostrar() const {
	cout << lista; 
}

#endif // CONJUNTO_HPP_
