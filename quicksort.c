//
//  quicksort.c
//  
//
//  Created by Adam Morton on 9/24/14.
//
//

#include <stdlib.h>
#include "sort.h"

//function declarationthingies to make compiler happy.

long int partition(long int *a, int lo, int hi);
void sort(long int *a, int lo, int hi);
void exch(long int *a, long int index1, long int index2);
void median3 (long int *a, long int lo, long int hi);

    
void quicksort(long int *a, long int n){
    if (n<=42) {
        insertion_sort(a,n);
    }
    else{
    sort(a, 0, n-1);
    }
}

void sort(long int *a, int lo, int hi){
    if(hi<=lo){
        return;
    }
    long int j = partition(a, lo, hi);
    
    sort(a, lo, j-1);
    sort(a, j, hi);
    
}

long int partition(long int *a, int lo, int hi){

    long int i = lo-1, j = hi+1;
    
    //set lo to median3
    median3(a,lo,hi);
    
    //v is pivot
    long int v = a[lo];
    
    while(1){
        while(a[++i] < v){
            if (i==hi){
                break;
            }
        }
        while(v < a[--j]){
            if (j==lo){
                break;
            }
        }
        if (i>=j){
            break;
        }
        else{
            exch(a,i,j);
        }
    }
    exch(a,lo,j);
    return (j+1);
}

void median3 (long int *a, long int lo, long int hi){
    long int mid = ((lo+hi)/2);
    
    if (a[lo] > a[hi]){
        exch(a, lo, hi);
    }
    if (a[mid] < a[lo]){
        exch(a,mid,lo);
    }
    if (a[hi] < a[mid]){
        exch(a, mid, hi);
    }
    
    exch(a,lo, mid);
    
}

void exch(long int *a, long int index1, long int index2){
    long int tmp = a[index1];
    a[index1] = a[index2];
    a[index2] = tmp;
}