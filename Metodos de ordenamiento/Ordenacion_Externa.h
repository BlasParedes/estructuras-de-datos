#ifndef ORDENACION_EXTERNA_H
#define ORDENACION_EXTERNA_H
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
class Ordenacion_Externa{
      public:
             Ordenacion_Externa(){}
             void fusion(char *,char *);
             void imprimir(FILE*);
             int particion(char *,int);
             void fusion(char*,char*,char*);
             void MDirecta(char*);
             void inicializar(char*);
};
class registro{
      public:
             char codClient[20];
             char nomClient[50];     
};
void Ordenacion_Externa::inicializar(char *arch){
     FILE *fp,*fp2;
     registro vec[10];
     if(!(fp=fopen(arch,"wb"))){
         return;                       
     }     
     strcpy(vec[0].codClient,"BBKAI");
     strcpy(vec[0].nomClient,"Jose");
     strcpy(vec[1].codClient,"GGOHU");
     strcpy(vec[1].nomClient,"Alejandra");
     strcpy(vec[2].codClient,"TTYOU");
     strcpy(vec[2].nomClient,"victor");
     strcpy(vec[3].codClient,"EERUG");
     strcpy(vec[3].nomClient,"manuel");
     strcpy(vec[4].codClient,"BBFJD");
     strcpy(vec[4].nomClient,"Jesus");
     strcpy(vec[5].codClient,"CCONT");
     strcpy(vec[5].nomClient,"Carlos");
     strcpy(vec[6].codClient,"PORFG");
     strcpy(vec[6].nomClient,"Andres");
     strcpy(vec[7].codClient,"IITMT");
     strcpy(vec[7].nomClient,"Maria");
     strcpy(vec[8].codClient,"RREFG");
     strcpy(vec[8].nomClient,"Vanesa");
     strcpy(vec[9].codClient,"TKHJK");
     strcpy(vec[9].nomClient,"Blas");
     fwrite(vec,sizeof(registro),10,fp);
     fclose(fp);
     if(!(fp2=fopen(arch,"rb"))){
         return;                       
     }//imprimir(fp2);
     fclose(fp2);
}
int Ordenacion_Externa::particion(char *arc,int partir){
    FILE *fp,*fp1,*fp2,*fptem;
    registro buf;
    int parar=-1,van;
    char arc1[]="temp1.dat";
    char arc2[]="temp2.dat";
    char arc3[]="temp.dat";
    fptem=fopen(arc3,"wb");
    if(!(fp=fopen(arc,"rb"))){
        cout<<"\nError";
        return -1;                                                
    }
    fread(&buf,sizeof(registro),1,fp);
    while(!feof(fp)){
         parar++;
         if(!(fp1=fopen(arc1,"wb"))||!(fp2=fopen(arc2,"wb"))){
             cout<<"\nError";
             return -1;                                                 
         }   
         van=0;
         while(!feof(fp)&&van<partir){
              van++;
              fwrite(&buf,sizeof(registro),1,fp1);
              fread(&buf,sizeof(registro),1,fp);                 
         }
         van=0;
         while(!feof(fp)&&van<partir){
              van++;
              fwrite(&buf,sizeof(registro),1,fp2);
              fread(&buf,sizeof(registro),1,fp);                        
         }
         fclose(fp1);fclose(fp2);
         fusion(arc1,arc2,arc3);
    }
    fclose(fp);fclose(fptem);
    remove(arc);
    remove(arc1);
    remove(arc2);
    rename(arc3,arc);
    return parar;
}
void Ordenacion_Externa::MDirecta(char *archi){
     int fin=1,part=1;
     while(fin){
          fin=particion(archi,part);
          part=2*part;                 
     }
}
void Ordenacion_Externa::fusion(char *nf1,char *nf2){//este es solo para fusionar
     FILE *f1,*f2,*f3;
     registro buf1,buf2;
     if(!(f1=fopen(nf1,"rb"))||!(f2=fopen(nf2,"rb"))||!(f3=fopen("fusion.DAT","wb"))){
            cout<<"Error"<<endl;
            return;                                                                                 
     }
     cout<<"Archivo 1"<<endl;
     //imprimir(f1);
     cout<<"Archivo 2"<<endl;
     //imprimir(f2);     
     system("PAUSE");
     system("CLS");
     fread(&buf1,sizeof(registro),1,f1);
     fread(&buf2,sizeof(registro),1,f2);
     
     while(!feof(f1) && !feof(f2)){
               cout<<"Archivo 3"<<endl;      
          if(strcmp(buf1.codClient , buf2.codClient) < 0){
                      
                fwrite(&buf1,sizeof(registro),1,f3);
                fread(&buf1,sizeof(registro),1,f1);      
          
          }   
          else{
               
               fwrite(&buf2,sizeof(registro),1,f3);
               fread(&buf2,sizeof(registro),1,f2);
                    
          }           
          
     }while(!feof(f1)){
                           
              fwrite(&buf1,sizeof(registro),1,f3);
              fread(&buf1,sizeof(registro),1,f1);             
          
     }while(!feof(f2)){
                           
              fwrite(&buf2,sizeof(registro),1,f3);
              fread(&buf2,sizeof(registro),1,f2);             
          
     }     
     fclose(f1);fclose(f2);fclose(f3);
}
void Ordenacion_Externa::fusion(char *nf1,char *nf2,char *nf3){//este es para mezcla directa
     FILE *f1,*f2,*f3;
     registro buf1,buf2;
     if(!(f1=fopen(nf1,"rb"))||!(f2=fopen(nf2,"rb"))||!(f3=fopen(nf3,"ab"))){
            cout<<"Error"<<endl;
            return;                                                                                 
     }
     fread(&buf1,sizeof(registro),1,f1);
     fread(&buf2,sizeof(registro),1,f2);     
     while(!feof(f1) && !feof(f2)){
               //cout<<"Archivo 3"<<endl;      
          if(strcmp(buf1.nomClient , buf2.nomClient) < 0){
                      
                fwrite(&buf1,sizeof(registro),1,f3);
                fread(&buf1,sizeof(registro),1,f1);      
          
          }   
          else{
               
               fwrite(&buf2,sizeof(registro),1,f3);
               fread(&buf2,sizeof(registro),1,f2);
                    
          }           
          
     }while(!feof(f1)){
                           
              fwrite(&buf1,sizeof(registro),1,f3);
              fread(&buf1,sizeof(registro),1,f1);             
          
     }while(!feof(f2)){
                           
              fwrite(&buf2,sizeof(registro),1,f3);
              fread(&buf2,sizeof(registro),1,f2);             
          
     }     
     fclose(f1);fclose(f2);fclose(f3);
}
void Ordenacion_Externa::imprimir(FILE *fp){
     registro bufR;
     fread(&bufR,sizeof(registro),1,fp);
     while(!feof(fp)){
          cout<<bufR.codClient<<" "<<bufR.nomClient<<"\n";            
          fread(&bufR,sizeof(registro),1,fp);   
     }
}
#endif
