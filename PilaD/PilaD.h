#ifndef PILAD_H
#define PILAD_H
#include <iostream>
#include "Nodo.h"
using std::cout;
template <class T>
class PilaD
{
	private:
		Nodo<T> *tope;
	public:
		PilaD() : tope(NULL){
		}
		int Insertar(T);
		int Eliminar(T&);
		bool is_vacia();
		void imprimir();
		T get_tope();
		int borrar_pila();
	protected:
};
template <class T>
T PilaD<T>::get_tope(){
	return tope->get_inf();
}
template <class T>
int PilaD<T>::Insertar(T nuevo){
	Nodo<T> *pnuev;
	pnuev = new Nodo<T>;	
	if(pnuev){
		pnuev->set_info(nuevo);
		pnuev->set_Ant(tope);
		tope = pnuev;
		return 1;
	}
	return 0;
}

template <class T>
int PilaD<T>::Eliminar(T &nuevo){
	if(is_vacia()) return 0;
	nuevo = tope->get_inf();
	tope = tope->get_Ant();
	return 1;
}

template <class T>
bool PilaD<T>::is_vacia(){
	return tope == NULL;
}

template <class T>
void PilaD<T>::imprimir(){
	Nodo<T> *recor;
	recor = tope;
	while(recor){
		cout<<"->"<<recor->get_inf();
		recor = recor->get_Ant();
	}
}
template <class T>
int PilaD<T>::borrar_pila(){
	T info;
	while(tope) Eliminar(info);
	return 1;
}
#endif
