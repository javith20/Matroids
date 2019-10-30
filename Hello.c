#include "lst.h"
#include <stdbool.h>
#include <stdio.h>
#include <omp.h>


typedef char* string;
typedef qvec(int,0) vector;
vector *listM;
vector *listI;
vector *matriz[20];
bool esPrimo(int num);
bool isVocal(string letra);
bool isPair(int num);
bool verifica(int num, char (* ptr)(int));
int main(void)
{
    
 	//listM = qvec_new(string,0, "7","2","5","d","1", "2", "Hola", "4", "5","d","L","g","d","ds","sas","sds","sas","sds");
 	//listI 	= qvec_new(string,1);
 	//qvec_push(listI,"H");
 	//qvec_push(listI,"F");
 	
 	listM = qvec_new(int,0,41,86,95,31,52,71,19,21,22,11);
 	listI = qvec_new(int,1);
 	matriz[0]= listM;
 	qvec_print(listM);
 	//matroid(int) *m=new_matroid(int,10,20,54,63,85);
 	qvec_print(matriz[0]);
 	//qvec_push(listI,71);
 	printf("%d\n",listM->len );
 	
 	   
    //paso de funciones por parametro
   /* char (* fptr) (int);             // M.1: declara fptr puntero-a-función
    fptr = isPair;                     // M.2: inicia fptr
    #pragma omp for 
    for(int i=0;i<10;i++){
    	int j=qvec_at(listM,i);
    	if(verifica(j,fptr)){
    		qvec_push(listI,j);
    		printf("%i\n",j );
    		printf("%s\n", "es par");
    	}else{
    		printf("%i\n",j );
    		printf("%s\n", "no es par");
    	}
    }*/
    //qvec_print(listI);

    qvec_free(listM);
   qvec_free(listI);
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

/*bool isVocal(string lyrics){
   char vowels[]={"a","e","i","o","u","A","E","I","O","U"};
   for(int i=0;i<sizeof(vowels) / sizeof(vowels[0]);i++){
   		if(lyrics==vowels[i]){
   			return true;
   		}
   }
   return false;

}*/
bool verifica(int num, char(*fpointer)(int)){
	bool flag;
	flag=(*fpointer)(num);
	return flag;
}
