//
//  iterative_mergesort.c
//  
//
//  Created by Adam Morton on 9/24/14.
//
//
#include "sort.h"
#include <stdlib.h>

void merge(long int *a, int lo, int mid, int hi);



void iterative_mergesort(long int *a, long int n)
{
    if (n<=0){
        return;
    }
    int hi;
    for (int sz = 1; sz <n; sz = sz+sz){
        for (int lo = 0; lo < n-sz; lo+=(sz+sz)){
            if ((lo+sz+sz-1)<=(n-1)){
                int hi = (lo+sz+sz-1);
                merge(a, lo, lo+sz-1, hi);
            }
            else{
                int hi = n-1;
                merge(a, lo, lo+sz-1, hi);
            }
            
        }
    }
}
