#include "lst.h"


typedef char* string;

qvec(string,0) *listM;
qvec(string,1) *listI;



int main(void)
{
    
 	listM = qvec_new(string,0, "7","2","5","d","1", "2", "Hola", "4", "5","d","L","g","d","ds","sas","sds","sas","sds");
 	listI = qvec_new(string,1);
 	qvec_push(listI,"H");
 	qvec_push(listI,"F");
 	
 	printf("%d\n",listI->len );
 	qvec_print(listM);
 	qvec_print(listI);
    qvec_free(listM);
    qvec_free(listI);
    
}
