#ifndef MATROID_H
#define MATROID_H
#include <stdlib.h>
#include <stdbool.h>
#include "lst.h"

int id=0;

#define matroid(T)         				  \
    struct matroid_##T{ 					  \
        qvec(T,0) *listM;  \
		qvec(T,1) *listI;      \
         										  \
    }


#define new_matroid(T,xs...)	\
({								\			
    listM=qvec_new(T,0,xs);     \
    listI=qvec_new(T,1);        \
})								\

















#endif