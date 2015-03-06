//
//  recursive_mergesort.c
//  
//
//  Created by Adam Morton on 9/24/14.
//
//

#include <stdlib.h>
#include "sort.h"

void merge(long int *a, int lo, int mid, int hi);
void sort(long int *a, int lo, int hi);


void recursive_mergesort(long int *a, long int n)
{
    if (n<=42){
        insertion_sort(a,n);
    }
    else{
	sort(a, 0, n-1);
    }
}

void sort(long int *a, int lo, int hi)
{
	if (hi<= lo){
        return;
    }
    
	int mid = lo + (hi-lo) / 2;
	sort(a, lo, mid);
	sort(a, mid+1, hi);
	merge(a, lo, mid, hi);
}