#ifndef COLAD_H
#define COLAD_H
#include "Nodo.h"
#include <iostream>
using std::cout;
template <class T>
class ColaD
{
	private:
		Nodo<T> *fte,*fin;
	public:
		ColaD() : fte(NULL),fin(NULL){
		}
		~ColaD();
		int Insertar(T);  
        int Eliminar(T&);
        void Imprimir();
        bool is_vacia();
        void EliminarCola();
        Nodo<T>* get_fin(){return fin;}
		Nodo<T>* get_fte(){return fte;}
	protected:
};
template <class T>
bool ColaD<T>::is_vacia(){
	return fte == NULL;
}
template <class T>
int ColaD<T>::Insertar(T nuevo){
	Nodo<T> *pnuev;
	pnuev = new Nodo<T>;
	if(pnuev){
		pnuev->set_info(nuevo);
		if(!fte)
			fte = pnuev;
		else
			fin->set_Ant(pnuev);
		fin = pnuev;
		return 1;
	}
	return 0;
}
template <class T>
int ColaD<T>::Eliminar(T &salida){
	Nodo<T> *eliminar;
	if(!is_vacia()){
		salida = fte->get_inf();
		eliminar = fte;
		if(fte == fin)
			fte = fin = NULL;
		else
			fte = fte->get_Ant();
		delete eliminar;
		return 1;
	}
	return 0;
}
template <class T>
void ColaD<T>::Imprimir(){
	Nodo<T> *recor;
	recor = fte;
	while(recor){
		cout<<recor->get_inf()<<" ";
		recor = recor->get_Ant();
	}
}
template <class T>
ColaD<T>::~ColaD(){
	T salida;
	while(fte && fin){
		Eliminar(salida);
	}
}
#endif
