#include "lst.h"
#include <stdbool.h>
#include <stdio.h>
#include <omp.h>

bool esPrimo(int num);
bool isPair(int num);
bool verifica(int num, char (* ptr)(int));
bool isOdd(int num);



typedef char* string;
typedef qvec(int) vectorInt ; 
typedef qvec(string) vectorString;

typedef struct matroid{
  vectorInt *listaS;
  vectorInt *listaI;
  char (* fptr)(int);
  int largoS;
} matroid;

matroid vectorMatroid[3];
int vectorMatroidLen =0;
 matroid  new_matroid(vectorInt *S, vectorInt *I, int largo, char(*fpointer)(int)){
    matroid nuevo;
	nuevo.listaS=S;
	nuevo.listaI=I;
	nuevo.fptr=fpointer;
	nuevo.largoS=largo;
	return nuevo;
}

void evaluate(){
	#pragma omp for
	for(int index = 0; index < vectorMatroidLen;index++){
		secondEvaluate(&vectorMatroid[index]);
	}
	printf("%s\n", "|=================RESULTADO EVALUACION M.I====================|");
	for(int index = 0; index < vectorMatroidLen;index++){
		qvec_print(vectorMatroid[index].listaI);
	}
	
}
void secondEvaluate(matroid *actual){
	qvec_print(actual->listaS);
	#pragma omp for 
	for(int i = 0; i <actual->listaS->len ;i++){
		int j=qvec_at(actual->listaS,i);
		if(verifica(j,actual->fptr)){
 			qvec_push(actual->listaI,j);
 		}	
	}
	
}


int main(void)
{

	/////////// array of matroid
 	//First matroid
 	vectorInt *listM1 = qvec_new(int,41,86,95,31,52,71,19,21,22,11,15,10,12,18,19);
 	vectorInt *listI1 = qvec_new(int);
 	char (* fptr) (int);           
    fptr = isPair;  
 	matroid nuevo=new_matroid(listM1,listI1,listM1->len,fptr);
 	vectorMatroid[vectorMatroidLen++]=nuevo;
 	//Second matroid 
	vectorInt *listM2 = qvec_new(int,41,80,52,32,19);
 	vectorInt *listI2 = qvec_new(int);
 	char (* fptr2) (int);           
    fptr = esPrimo;  
 	matroid nuevo2=new_matroid(listM2,listI2,listM2->len,fptr);
 	vectorMatroid[vectorMatroidLen++]=nuevo2; 
 	
 	//third matroid
 	vectorInt *listM = qvec_new(int,8,7,9,5,2,1,4,6,8,9,7,4,5,2,10,12,15,14);
 	vectorInt *listI = qvec_new(int);
 	char (* fptr3) (int);           
    fptr = isOdd;  
 	matroid nuevo3=new_matroid(listM,listI,listM->len,fptr);
 	vectorMatroid[vectorMatroidLen++]=nuevo3;
 	evaluate();



 	vectorMatroidLen=0;
 	///////////second array of matroid
 	printf("%s\n","|===================Evaluación de segundo matroid======================|" );
 	
	vectorInt *listM4 = qvec_new(int,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15);
 	vectorInt *listI4 = qvec_new(int);
 	char (* fptr4) (int);           
    fptr4 = isPair;  
 	matroid nuevo4=new_matroid(listM4,listI4,listM4->len,fptr4);
 	vectorMatroid[vectorMatroidLen++]=nuevo4;
 	//Second matroid 
	vectorInt *listM5 = qvec_new(int,41,80,52,32,19);
 	vectorInt *listI5 = qvec_new(int);
 	char (* fptr5) (int);           
    fptr5 = isPair;  
 	matroid nuevo5=new_matroid(listM5,listI5,listM5->len,fptr);
 	vectorMatroid[vectorMatroidLen++]=nuevo5; 
 	
 	//third matroid
 	vectorInt *listM6 = qvec_new(int,8,78,95,98,63,65,64,72,78,96,93,91,92,100,154);
 	vectorInt *listI6 = qvec_new(int);
 	char (* fptr6) (int);           
    fptr6 = isPair;  
 	matroid nuevo6=new_matroid(listM6,listI6,listM6->len,fptr6);
 	vectorMatroid[vectorMatroidLen++]=nuevo6;

 	vectorInt *listM7 = qvec_new(int,7,8,10,12,14,16,95,92,93,97,94,95,98,99,12);
 	vectorInt *listI7 = qvec_new(int);
 	char (* fptr7) (int);           
    fptr7 = isPair;  
 	matroid nuevo7=new_matroid(listM7,listI7,listM7->len,fptr);
 	vectorMatroid[vectorMatroidLen++]=nuevo7;

 	vectorInt *listM8 = qvec_new(int,8,7,9,5,2,1,4,6,8,9,7,4,5,2,10,12,15,14);
 	vectorInt *listI8 = qvec_new(int);
 	char (* fptr8) (int);           
    fptr8 = isPair;  
 	matroid nuevo8=new_matroid(listM8,listI8,listM8->len,fptr);
 	vectorMatroid[vectorMatroidLen++]=nuevo8;
 	evaluate(); 	





 	qvec_print(vectorMatroid[0].listaI);
   	qvec_free(vectorMatroid[0].listaS);
   	qvec_free(vectorMatroid[0].listaI);
}

bool esPrimo(int num){
	int div=2;
	while (div<num/2) {
		if(num%div==0){
			return false;
		}
		div++;
	}
	return true;
}

bool isPair(int num){
	if(num%2==0){
		return true;
	}else{
		return false;
	}
}

bool isOdd(int num){
   if(num%2!=0){
      return true;
   }else{
   	  return false;
   }
}




bool verifica(int num, char(*fpointer)(int)){
	bool flag;
	flag=(*fpointer)(num);
	return flag;
}
