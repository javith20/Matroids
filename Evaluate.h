#ifndef EVALUATE_H
#define EVALUATE_H
#include <stdlib.h>
#include <stdbool.h>
#include <omp.h>



#define Evaluate(M,N)         \
    struct Evaluate_##M_##N {   \
        qvec_base;      \
        T data[];       \
    }










bool verifica(int num, char(*fpointer)(int)){
	bool flag;
	flag=(*fpointer)(num);
	return flag;
}
#endif