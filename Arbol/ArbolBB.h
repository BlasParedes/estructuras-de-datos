#ifndef ARBOLBB_H
#define ARBOLBB_H
#include <iostream>
#include "ColaD.h"
#include "PilaD.h"
#include "Bicolas.h"
#include <math.h>
using std::cout;
using std::ostream;
//Nodo Estatico, serà usado como clase generica que manejarà el arbol
class NodoE{
	private:
		/*
		* Campo info
		Este NodoE puede ser Usado en caso de que se usen cadenas de caracteres como parametro T en las listas ya vistas
		*/
		char cad[30];
	public:
		NodoE(char *c){
			strcpy(cad,c);
		}
		friend ostream& operator<<(ostream &os,NodoE nodo){
			/*os<<imrprimir la info;*/
			return os;
		}
		/*Aqui se decide cual va a ser el parametro de comparacion*/
		bool operator<(NodoE &c){
			return strcmpi(this->cad,c.cad);//para que no distinga entre mayusculas y minusculas
			//return this->cod < c.cod;
		}
		
		bool operator>(NodoE &c){
			return strcmpi(this->cad,c.cad);//para que no distinga entre mayusculas y minusculas
		}
		
		bool operator==(NodoE &c){
			return strcmpi(this->cad,c.cad)==0;//para que no distinga entre mayusculas y minusculas
		}
		bool operator!=(NodoE &c){
			return strcmpi(this->cad,c.cad)!=0;//para que no distinga entre mayusculas y minusculas
		}
		
};
//Es el objeto que el arbol usarà como nodos
template <class T>
class NodoA{
		 T inf;
        NodoA<T>* HI;
		NodoA<T>* HD;		
		int Nivel;
	public:
       
		NodoA(): HI(NULL),HD(NULL){}
		void set_HI(NodoA<T>*p){HI=p;}
		void set_HD(NodoA<T>*p){HD=p;}
		NodoA<T>* get_HI(){return HI;}
		NodoA<T>* get_HD(){return HD;}
		T get_inf(){return inf;}
		void set_inf(T i){ inf = i;}
		int get_nivel(){return Nivel;}
		void set_nivel(int xn){Nivel = xn;}
		
};


template <class T>
class ArbolBB
{	
	NodoA<T> *raiz;

	public:
		ArbolBB() : raiz(NULL){             
        }
		bool is_vacio(){return raiz == NULL;}
		NodoA<T>* get_raiz(){return raiz;}
		int Agre_Busc(T,bool band = false);//false = solo agregar/ true = solo buscar
		void ImpPro_PreOrd(NodoA<T> *p,int nivel = 0);
		void ImpPro_Orden(NodoA<T> *p,int nivel = 0);
		void ImpPro_PostOrd(NodoA<T> *p,int nivel = 0);
		void ImpExten();
		NodoA<T>* find_nodo(T ele,ColaD<bool> &cola);
		void set_raiz(NodoA<T> *r){raiz = r;}
		bool comparar_simetria(ArbolBB);
		void Simetria(NodoA<T>*,PilaD<int>&);//llenar la pila de simetría en la cual se guardará el lado en el cual está cada nodo		
		PilaD<int> pilaG;
		bool is_simetrico();	
		int Eliminar(T);
		T nodo_op_sim(T);
		bool is_equilibrado(NodoA<T>*);//OJO: este metodo tiene loogica invertida
		bool is_completo();
	protected:
        int eliminarBB(NodoA<T>*&,T);
        void reemplazar(NodoA<T> **);
};
template <class T>
bool ArbolBB<T>::is_completo(){
	int band = -1,sal,cont=0;
	pilaG.borrar_pila();
	Simetria(get_raiz(),pilaG);
	PilaD<int> stack;
	stack = pilaG;
	while(!stack.is_vacia()){
		stack.Eliminar(sal);
		if(sal > band)
			band = sal;
	}
	while(!pilaG.is_vacia()){
		pilaG.Eliminar(sal);
		if(sal == band)
			cont++;
	}
	return cont == pow(band,2);
}
template <class T>
bool ArbolBB<T>::is_equilibrado(NodoA<T>* arbol){
	if(arbol){
         if(is_equilibrado(arbol->get_HI())){
            return is_equilibrado(arbol->get_HI());
         }else if(is_equilibrado(arbol->get_HD())){
                 return is_equilibrado(arbol->get_HD()); 
         }else return abs(altura(arbol->get_HI())-altura(arbol->get_HD())) > 1;                     
     }else return false;
}
template <class T>
NodoA<T>* ArbolBB<T>::find_nodo(T ele,ColaD<bool> &cola){
     NodoA<T>* recor;
	 recor = raiz;
	 while(recor){
		if(ele == recor->get_inf()){

			return recor;
		}else{
			if(ele < recor->get_inf()){
                cola.Insertar(true);     
				recor = recor->get_HI();
			}else{
                cola.Insertar(false);           
				recor = recor->get_HD();
            }
		}
	}	
    cola.EliminarCola(); 
    return NULL;
}

template <class T>
T ArbolBB<T>::nodo_op_sim(T nodo){                           
      ColaD<bool> cola;
      bool sal;
      find_nodo(nodo,cola);
      NodoA<T>* recor;
	  recor = raiz;  
      
      while(recor && !cola.is_vacia()){
           cola.Eliminar(sal);          
           if(sal)
              recor = recor->get_HD();      
           else
              recor = recor->get_HI();      
      }
      return recor == NULL && recor != raiz?NULL:recor->get_inf();                   
}
template <class T>
int ArbolBB<T>::Eliminar(T dat){
    NodoA<T> *recor;
    recor = get_raiz();
    eliminarBB(recor,dat);
    set_raiz(recor);
}
template <class T>
int ArbolBB<T>::eliminarBB(NodoA<T>* &r,T dato){
     NodoA<T>* recor;
     if(!r)
        return 0;
     else if(dato < r->get_inf()){
       recor = r->get_HI();    
       eliminarBB(recor,dato);
       r->set_HI(recor);
     }else if(dato > r->get_inf()){   
       recor = r->get_HD();    
       eliminarBB(recor,dato);
       r->set_HD(recor);
     }else{
       NodoA<T> *q;
       q=r;
       if(q->get_HI()==NULL)
         r=q -> get_HD();
       else if(q -> get_HD()==NULL)
         r=q -> get_HI(); 
       else{
          reemplazar(&q);               
       }
       free(q);
     }
     return 1;
}
template <class T>
void ArbolBB<T>::reemplazar(NodoA<T> **act){
     NodoA<T> *a,*p;
     p =*act;
     a=(*act)->get_HI();
     while(a->get_HD()){
       p=a;
       a=a->get_HD();             
     }
     (*act)->set_inf(a->get_inf());
     if(p==(*act))
       p->set_HI(a->get_HI());
     else
       p->set_HD(a->get_HI());
     (*act)=a;
}
template <class T>
void ArbolBB<T>::ImpExten(){
	NodoA<T> *p;
	int band;
	ColaD<NodoA<T>*> cola;
	cola.Insertar(raiz);
	band = 0;
	while(!cola.is_vacia()){
		cola.Eliminar(p);
		if(p->get_nivel() > band){
			band++;
			cout<<"\n";
		}
		cout<<p->get_inf()<<" ";		
		if(p->get_HI()) cola.Insertar(p->get_HI());
		if(p->get_HD()) cola.Insertar(p->get_HD());
	}	
}


template <class T>
int ArbolBB<T>::Agre_Busc(T ele, bool band){
	NodoA<T> *pnuev,*recor,*antes;
	int enc = 0,nivel = 0;
	recor = raiz;
	while(recor && !enc){
		antes = recor;
		if(ele == recor->get_inf())
			enc = 1;
		else{
			if(ele < recor->get_inf())
				recor = recor->get_HI();
			else
				recor = recor->get_HD();
		}
		nivel++;
	}	
	if(band)
		return enc;
	if(enc) return 0;
       
	    pnuev = new NodoA<T>;
	    if(!pnuev) return -1;		
     	pnuev->set_inf(ele);
	    pnuev->set_nivel(nivel);
	    if(is_vacio()) 
              raiz = pnuev;
        else{
		      if(ele < antes->get_inf())
			      antes->set_HI(pnuev);
		      else
			      antes->set_HD(pnuev);
        }

	return 1;
}

template <class T>
void ArbolBB<T>::ImpPro_PreOrd(NodoA<T> *p,int nivel){
	for(int i=0;i<nivel;i++) cout<<"  ";
	cout<<p->get_inf()<<"\n";
	if(p->get_HI()) ImpPro_PreOrd(p->get_HI(),nivel+1);
	if(p->get_HD()) ImpPro_PreOrd(p->get_HD(),nivel+1);	
}

template <class T>
void ArbolBB<T>::ImpPro_Orden(NodoA<T> *p,int nivel){
	if(p->get_HI()) ImpPro_Orden(p->get_HI(),nivel+1);
	for(int i=0;i<nivel;i++) cout<<"  ";
	cout<<p->get_inf()<<"\n";	
	if(p->get_HD()) ImpPro_Orden(p->get_HD(),nivel+1);	
}

template <class T>
void ArbolBB<T>::ImpPro_PostOrd(NodoA<T> *p,int nivel){
	if(p->get_HI()) ImpPro_PostOrd(p->get_HI(),nivel+1);
	if(p->get_HD()) ImpPro_PostOrd(p->get_HD(),nivel+1);	
	for(int i=0;i<nivel;i++) cout<<"  ";
	cout<<p->get_inf()<<"\n";	
}
template <class T>
void ArbolBB<T>::Simetria(NodoA<T> *recor,PilaD<int> &pilaG){
   if(recor){
   		   Simetria(recor->get_HI(),pilaG);
           pilaG.Insertar(recor->get_nivel());           
           Simetria(recor->get_HD(),pilaG);
     }  
}
template <class T>
bool ArbolBB<T>::comparar_simetria(ArbolBB arb){
	int i1,i2;
	pilaG.borrar_pila();
	arb.pilaG.borrar_pila();
	Simetria(raiz,pilaG);
	Simetria(arb.get_raiz(),arb.pilaG);
	while(!pilaG.is_vacia()){
		pilaG.Eliminar(i1);
		arb.pilaG.Eliminar(i2);
		if( i1 != i2 )
			return false;
	}
	return true;
}
template <class T>
bool ArbolBB<T>::is_simetrico(){
     Bicolas<int> cola;
     pilaG.borrar_pila();
     Simetria(raiz,pilaG);
     while(!pilaG.is_vacia()){
             int S;
             pilaG.Eliminar(S);
             if(S != 0)cola.Insertar(S);
     }
     while(!cola.is_vacia()){
             int S1,S2;
             cola.Eliminar(S1);
             cola.Eliminar(S2,0);
             if(S1 != S2)
                   return false;
     }
     return true;
}
#endif
