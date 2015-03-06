#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <assert.h>

#include "sort.h"

/***************************************************************
 * Insertion sort
 */

void insertion_sort (long int *a, long int n) {
  if (n <= 0) { /* Watch out for tricks! */
    return;
  }

  for (long int i = 1; i < n; i++) {
    for (long int j = i; (j > 0) && (a[j] < a[j-1]); j--) {
      long int tmp = a[j]; a[j] = a[j-1]; a[j-1] = tmp;
    }
  }
}

int is_sorted (long int *a, long int n)
{
  for (long int i = 0; i < n-1; i++) {
    if (a[i] > a[i+1]) {
      return 0;
    }
  }
  return 1;
}

int are_identical (long int *a, long int *b, long int n)
{
  long int sum = 0;
  for (int k = 0; k < n; k++) {
    sum += abs(a[k] - b[k]);
  }
  return (!sum);
}

void merge(long int *a, int lo, int mid, int hi){
    int i = lo, j = mid+1;
    
    long int *aux = malloc((hi+1)*sizeof(long int));
    
    for (int k = lo; k <= hi; k++){
        aux[k] = a[k];
    }
    
    for (int k = lo; k <= hi; k++){
        if (i > mid){
            a[k] = aux[j++];
        }
        else if(j>hi){
            a[k] = aux[i++];
        }
        else if(aux[j] < aux[i]){
            a[k] = aux[j++];
        }
        else{
            a[k] = aux[i++];
        }
        
    }
    free(aux);
}