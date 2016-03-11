#ifndef NODO_H
#define NODO_H
#include <iostream>
#include <string.h>
using std::cout;
using std::ostream;


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
