#ifndef NODO_H
#define NODO_H
#include <iostream>
#include <string.h>
using std::cout;
using std::ostream;
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


class NodoE{
	private:
		/*
		* Campo info
		Este NodoE puede ser Usado en caso de que se usen cadenas de caracteres como parametro T en las listas ya vistas
		*/
		char cad[30];
	public:
		NodoE(){
			
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
#endif
