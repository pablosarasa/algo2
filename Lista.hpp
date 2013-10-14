#include <iostream>
using namespace std;


template <typename T>
class Lista{

	public:
		Lista();
		void agregar(const T&);
		void quitar(const T&);		//requiere que v esté en la lista parámetro
		bool pertenece(const T&);
		ostream& verLista(ostream& os) const;


	private:
		struct Nodo{
			Nodo(const T& v) : valor(v), psig(NULL){}
			T valor;
			Nodo* psig;
		};
		unsigned int cant;
		Nodo* primero;
};

template <typename T>
ostream& operator<<(ostream& out, const Lista<T>& l){
	return l.verLista(out);
}

template <typename T>
Lista<T>::Lista():primero(NULL),cant(0){}

template <typename T>
void Lista<T>::agregar(const T& v){
	Nodo* nuevo = new Nodo(v);
	if(cant == 0){
		primero = nuevo;
	}
	else{
		Nodo* aux = primero;
		while(aux->psig != NULL){
			aux = aux->psig;
		}
		aux->psig = nuevo;
	}
	cant++;
}

template <typename T>
bool Lista<T>::pertenece(const T& v){
	Nodo* aux = primero;
	bool res = false;
	while(aux!= NULL){
		if(aux->valor == v){
			res = true;
		}
		aux = aux->psig;
	}
	return res;
}


template <typename T>
void Lista<T>::quitar(const T& v){
	if(pertenece(v)){
		if(v == primero->valor){
			if(cant == 1){
				delete primero;
				primero == NULL;
			}
			else{
				Nodo* sarasa = primero;
				primero = primero->psig;
				delete sarasa;
			}
		}
		else{
			Nodo* aux = primero;
			Nodo* aux2 = NULL;
			while(aux->valor != v){
				aux2 = aux;
				aux = aux->psig;
			}
			aux2->psig = aux->psig;
			delete aux;
		}
		cant--;
	}
}

template <typename T>
ostream& Lista<T>::verLista(ostream& os) const{
	if(cant == 0){
		os << "{}";
	}
	else{
	os << "{";
		Nodo* aux = primero;
		while(aux != NULL){
			if(aux->psig == NULL){
				os << aux->valor << "}";
			}
			else{
				os << aux->valor << ",";
			}
			aux = aux->psig;
		}
	}
}
