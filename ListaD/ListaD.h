#ifndef LISTAD_H
#define LISTAD_H
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "Nodo.h"
using std::cout;
using std::ostream;

template <class T>
class ListaD
{
	private:
		Nodo<T> *cab;
	public:
		ListaD(){cab = NULL;}
		~ListaD(){}
		int Agregar(T,int tipo=0);//si tipo es diferente de cero la lista no guardará repetidos
		int Eliminar(T);
		void Imprimir();
		T get_cabezera(){return cab->get_inf();}
		Nodo<T>* get_cab(){return cab;}
		bool buscar(T&,Nodo<T> **q=NULL);
		bool is_vacia(){return !cab;}
		bool looking_for(T&,Nodo<T> **q = NULL);
};
template <class T>
bool ListaD<T>::looking_for( T &bus, Nodo<T> **q){
      Nodo<T> *p;
      int cont = 0;
      p = cab;
      while(p){
          if ( bus==p->get_inf() )
          {
               if ( q!=NULL ) *q= p;
               bus= p->get_inf();
               return true;
          }
          p= p->get_sig();
          if(p == cab)
               break;
          cont++;
      }
      return false;
}
template <class T>
bool ListaD<T>::buscar( T &bus, Nodo<T> **q)
{
      Nodo<T> *p;
      for (p=cab; p; p= p->get_sig())
          if ( bus==p->get_inf() )
          {
               if ( q!=NULL ) *q= p;
               bus= p->get_inf();
               return true;
          }
      return false;
}
template <class T>
int ListaD<T>::Agregar(T nuevo,int tipo){
	Nodo<T> *pnue, *p, *q; // p = equivalente de recor en el codigo de rodriguez, q = variable que controla el 
	pnue = new Nodo<T>;	
	if(!pnue) return 0;
	pnue->set_info(nuevo);
	p = cab;
	while(p){
		if(p->get_inf() == nuevo && tipo != 0)
			return -99;	
		else if(nuevo < p->get_inf())
			break;
		else{
			q=p;
			p = p->get_sig();			
		}
	}
	pnue->set_sig(p);
	if(p == cab){
		if(p)
			cab->set_Ant(pnue);	
		cab=pnue;
	}else{
		pnue->set_Ant(q);
		q->set_sig(pnue);		
		if(p) p->set_Ant(pnue);			
	}
	return 1;	
}
template <class T>
int ListaD<T>::Eliminar(T nuevo){
	
	Nodo<T> *recor,*eliminar,*antes;
	int enc=0;
	if(cab){
        recor=cab;     
	    if(nuevo ==cab->get_inf() ){
            cab=cab->get_sig();
            free(recor);                                                    
        }
        else{
           recor=cab->get_sig();
           antes=cab;
           enc=0;
           while((recor)&&(!enc)){
                if(nuevo == recor->get_inf() )
                    enc=1;
                else{
                    antes=recor;
                    recor=recor->get_sig();      
                } 
		   }  
        	if(enc){
                if(recor->get_sig()==NULL)
                    antes->set_sig(NULL);
                else 
                    antes->set_sig(NULL);
                free(recor);        
            }else                 
                return 0;
             
        }
	}else return -1;
	return 1;	
}
template <class T>
void ListaD<T>::Imprimir(){
	Nodo<T> *recor,*antes;
	recor = cab;
	while(recor){
		cout<<recor->get_inf()<<"\n";
		antes = recor;
		recor = recor->get_sig();
	}
}
#endif
