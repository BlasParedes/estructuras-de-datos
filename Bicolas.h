#ifndef BICOLAS_H
#define BICOLAS_H
#include "Nodo.h"
#include <iostream>
using std::cout;
template <class T>
class Nodo{
    private:
        T info;
        Nodo<T> *Sig,*Ant;
    public:
        Nodo() : Sig(NULL),Ant(NULL){
        }
        void set_info(T val){info = val;}   
        void set_sig(Nodo<T> *p){Sig = p;}    
        void set_Ant(Nodo<T> *p){Ant = p;}        
        T get_inf(){return info;}
        Nodo<T>* get_sig(){return Sig;}
        Nodo<T>* get_Ant(){return Ant;}
};
template <class T>
class Bicolas
{
	private:
		Nodo<T> *fteI,*fteD;
	public:
		Bicolas() : fteD(NULL),fteI(NULL){
		}
		int Insertar(T,int lado = 1);
		int Eliminar(T&,int lado = 1);
		int Imprimir(int lado = 1);
		bool is_vacia(){return fteI == NULL && fteD == NULL;}
		T get_fteI(){return fteI->get_inf();}
		T get_fetD(){return fteD->get_inf();}
		int Elim_Bicola();
	protected:
};
template <class T>
int Bicolas<T>::Elim_Bicola(){
	T nodo;
	while(fteI)
		Eliminar(nodo);
		return 1;
}
template <class T>
int Bicolas<T>::Insertar(T nuevo,int lado){
	Nodo<T> *pnuev;
	pnuev = new Nodo<T>;
	if(pnuev){
		pnuev->set_info(nuevo);
		if(!fteI)
			fteI = fteD = pnuev;
		else if(lado == 1){ //Izquierda
			pnuev->set_sig(fteI);
			fteI->set_Ant(pnuev);
			pnuev->set_Ant(NULL);
			fteI = pnuev;
		}else{//Derecha
			pnuev->set_Ant(fteD);
			fteD->set_sig(pnuev);
			pnuev->set_sig(NULL);
			fteD = pnuev;
		}
		return 1;
	}
	return 0;
}

template <class T>
int Bicolas<T>::Eliminar(T &salida,int lado){
	Nodo<T> *eliminar;
	if(fteI){
		if(fteI == fteD){
			eliminar = fteI;
			salida = eliminar->get_inf();
			fteI = fteD = NULL;
		}else{
			if(lado == 1){//Izquierda
				eliminar = fteI;
				fteI = fteI->get_sig();
				fteI->set_Ant(NULL);
			}else{//Derecha
				eliminar = fteD;
				fteD=fteD->get_Ant();
				fteD->set_sig(NULL);
			}
		}
		salida = eliminar->get_inf();
		delete eliminar;
		return 1;
	}
	return 0;
}

template <class T>
int Bicolas<T>::Imprimir(int lado){
	Nodo<T> *recor;
	if(lado == 1 && fteI){//Izquierda
		recor = fteI;
		while(recor){
			cout<<recor->get_inf()<<"\n";
			recor= recor->get_sig();
			if(recor == fteI)
				break;
		}
	}else if(lado != 1 && fteD){//Derecha
		recor = fteD;
		while(recor){
			cout<<recor->get_inf()<<"\n";
			recor = recor->get_Ant();
			if(recor == fteD)
				break;
		}
	}else
		return 0;
}
#endif
