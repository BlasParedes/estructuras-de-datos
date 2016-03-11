#ifndef LISTACDE_H
#define LISTACDE_H
#include "Nodo.h"

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
template <typename T>
class ListaCDE {
		Nodo<T> *cab;
      public:
        ListaCDE(): cab(NULL){
                    
        }
        int Insertar(T,int tipo = 0,int orden = 1);//tipo != 0 es la lista no guardará repetidos, orden = 1 todo ordenado orden = 0 todo como venga
        int Eliminar(T);
        Nodo<T>* buscar(T);
        bool hayList();
        bool List_vacia();
        void imprimir();
        Nodo<T>* get_cab(){return cab;}
        Nodo<T>* get_ultimo(){return cab->get_Ant();}
        void set_cab(Nodo<T>* new_cab){ cab = new_cab;}
        bool looking_for( T &bus, Nodo<T> **q=NULL);
};
template <class T>
bool ListaCDE<T>::looking_for( T &bus, Nodo<T> **q){
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
template <typename T>
void ListaCDE<T>::imprimir(){
	Nodo<T> *recor;
	recor = cab;
	do{
		cout<<recor->get_inf()<<"\n";
		recor = recor->get_sig();
		
	}while(recor->get_inf() != cab->get_inf());
}
template <typename T>
int ListaCDE<T>::Insertar(T tn,int tipo, int orden){
     Nodo<T> *nuevo,*recor,*antes;
     int enc=0;
     nuevo=new Nodo<T>();
     if(nuevo){          
     	  nuevo->set_info(tn);
          recor=cab;
          if(orden)
          while(recor&&!enc)
          	 if(recor->get_inf() == tn && tipo != 0)
          	 	return -99;
             else if(nuevo->get_inf() < recor->get_inf())
                enc=1;
             else/**/{                
                recor=recor->get_sig(); 
                if(recor==cab)
                  break; 
             }
        	else 
        	while(recor&&!enc)
          	 if(recor->get_inf() == tn && tipo != 0)
          	 	return -99;
             else {                
                recor=recor->get_sig(); 
                if(recor==cab)
                  break; 
             }
             //if(enc) return -1; // esto para que guarde sin repitencias
             if(!recor)
                recor=antes=cab=nuevo;
             else 
                antes=recor->get_Ant();
             nuevo->set_sig(recor);
			 nuevo->set_Ant(antes);
             antes->set_sig(nuevo);
             recor->set_Ant(nuevo);
             if(recor==cab&&enc)//primero de la lista
                cab=nuevo;
            return 1;
            
     }else return 0;
}

template <class T>
int ListaCDE<T>::Eliminar(T xnodo){
     Nodo<T> *recor,*antes;
     
     int enc=0;
     if(hayList()){
         recor = buscar(xnodo);
         
         if(recor){         	
              recor->get_Ant()->set_sig(recor->get_sig());
              recor->get_sig()->set_Ant(recor->get_Ant());
              if(cab==cab->get_sig())
                  cab=NULL;
              if(cab==recor)
                  cab=cab->get_sig();
              xnodo = recor->get_inf();
              delete recor;
              
			  return 1;                    
         }else return 0;                                     
     }else return -1;
}

template <typename T>
Nodo<T>* ListaCDE<T>::buscar(T t){
	Nodo<T> *recor;
	recor=cab;
	if(hayList())
	do{
		if(recor->get_inf()==t){
			return recor;
		}else
		   recor=recor->get_sig();
	}while(recor != cab);
	return NULL;
}
template <typename T>
bool ListaCDE<T>::hayList(){
	return cab;
}

#endif
