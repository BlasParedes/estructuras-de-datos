#ifndef METODOS_ORDENACION_INTERNA_H
#define METODOS_ORDENACION_INTERNA_H
#include <iostream>
#include <string.h>
using namespace std;

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

template <class T>
class Metodos_Ordenacion_Interna{
      public:
      Metodos_Ordenacion_Interna(){};
      void Insercion_Directa(T*,int);
      void Insercion_Binaria(T*,int);
      void Shaker_Sort(T*,int);
      void Seleccion_Directa(T*,int);
      void Metodo_Shell(T*,int);
      void Metodo_Quick_Sort(T*,int,int);
      void Crear_Monticulo(T*,int);   
      void Eliminar_Monticulo(T*,int);
      void imprimir_Matriz(T*,int);  
      void Burbuja(T*,int);
};
template <class T>
void Metodos_Ordenacion_Interna<T>::Metodo_Quick_Sort(T *ve, int li, int ld){     
	int i, j, pvt;	
	T aux;
	pvt = ve[(int)(li+ld)/2];
    i = li; j = ld;	
	do{
		while(ve[i] < pvt) i++;
		while(ve[j] > pvt ) j--;		
		if(i <= j){			
			aux = ve[i];
			ve[i] = ve[j];
			ve[j] = aux;			
			i++; j--;
		}
	}while(i < j);	
	if(li < j)
		Metodo_Quick_Sort(ve, li, j);
	if(i < ld)
		Metodo_Quick_Sort(ve, i, ld);
}


template <class T>
void Metodos_Ordenacion_Interna<T>::Burbuja(T *vec,int nu){
    int aux;
	int sw=1;
	int xnu=nu;
	while(sw){
		sw=0;
		for(int j=0;j<xnu;j++){
			if(vec[j]>vec[j+1]){
				sw=1;
                aux=vec[j];
				vec[j]=vec[j+1];
				vec[j+1]=aux;				
			}
		}
		xnu--;
	}
}
template <class T>
void Metodos_Ordenacion_Interna<T>::imprimir_Matriz(T *ve,int nu){
     for(int i=0;i<nu;i++)
           cout<<ve[i]<<endl;          
}
template <class T>
void Metodos_Ordenacion_Interna<T>::Insercion_Directa(T *ve,int nu){
     int aux,k;
     for(int i=1;i<nu;i++){
            aux=ve[i];         
            k=i-1;
            while(k>=0&&aux<ve[k]/*Cambiar a aux>ve[k] si se quiere ordenar de menor a mayor*/){
                  ve[k+1]=ve[k];
                  k--;                                        
            }
            ve[k+1]=aux;
     }     
}

template <class T>
void Metodos_Ordenacion_Interna<T>::Insercion_Binaria(T *ve,int nu){
    int ls,li,pm,aux;
     for(int i=1;i<nu;i++){
         li=0;
         ls=i-1;
         aux=ve[i];
         while(li<=ls){
              pm=(int)((ls+li)/2); 
              if(aux<ve[pm])
                 ls=pm-1;
              else
                 li=pm+1;        
         }    
         for(int j=i;j>li;j--)
            ve[j]=ve[j-1];
         ve[li]=aux;
     }//for 
}
//
template <class T>
void Metodos_Ordenacion_Interna<T>::Shaker_Sort(T *ve,int MAX){
     int li=0,ls=MAX-1,pos=MAX-1,aux;
     while(li<ls){
          for(int j=ls;j>li;j--)        
              if(ve[j]<ve[j-1]){
                     aux=ve[j];
                     ve[j]=ve[j-1];
                     ve[j-1]=aux;
                     pos=j;                             
              }   
              li=pos;
              for(int j=li;j<ls;j++)
                  if(ve[j]>ve[j+1]){
                       aux=ve[j];
                       ve[j]=ve[j+1];
                       ve[j+1]=aux;
                       pos=j;
                  }
          ls=pos;
     }
}
template <class T>
void Metodos_Ordenacion_Interna<T>::Seleccion_Directa(T *ve,int nu){
     int may,pos,i,j;
     for(int i=nu-1;i>0;i--){
         may=ve[0];
         pos=0;
         for(j=1;j<=i;j++)
            if(ve[j]>may){
                 may=ve[j];
                 pos=j;                        
            }   
            ve[pos]=ve[i];
            ve[i]=may;         
     }
}
template <class T>
void Metodos_Ordenacion_Interna<T>:: Metodo_Shell(T *ve,int nu){
     int aux,k,sec,i,MAX=nu;
     sec=(int)(nu/2);
     while(sec>0){
          for(i=sec;i<MAX;i++){
              aux=ve[i];
              k=i-sec;
              while(k>=0&&aux<ve[k]){
                   ve[k+sec]=ve[k];
                   k-=sec;   
              }           
              ve[k+sec]=aux;                           
          }                 
          sec=(int)(sec/2);    
     }     
}
template <class T>
void Metodos_Ordenacion_Interna<T>::Crear_Monticulo(T *ve,int nu){
     int ele,padre,hijo;
     for(int i=1;i<nu;i++){
        ele=ve[i];
        hijo=i;
        padre=(int)((hijo-1)/2);
        while(hijo>0&&ve[padre]<ele){
             ve[hijo]=ve[padre];
             hijo=padre;
             padre=(int)((hijo-1)/2);   
        }             
        ve[hijo]=ele;
     }
}   
template <class T>
void Metodos_Ordenacion_Interna<T>::Eliminar_Monticulo(T *ve,int nu){
     int elem,hiz,hde,padre,k,may,sw;
     for(int i=nu-1;i>0;i--){
        sw=1;
        elem=ve[i];
        ve[i]=ve[0];
        hiz=1;
        hde=2;
        k=0;
        while(hiz<i&&sw){
             may=ve[hiz];
             padre=hiz;
             if(ve[hde]>may&&i!=hde){
               may=ve[hde];
               padre=hde;                                              
             }   
             if(elem<may){
               ve[k]=may;
               k=padre;
               hiz=2*k+1;
               hde=hiz+1;           
             }else
               sw=0;
        }   
        ve[k]=elem;
     }     
}    
#endif
