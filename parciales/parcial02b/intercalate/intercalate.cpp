#include "intercalate.h"
#include <iostream>
using namespace std;

int*
intercalate(const int arr1[],
	    const int arr2[],
	    const int nbr,
	    const int fact) {
  int arr1cont, pos  = 0;
  int arr2cont;
  int *final =  new int[nbr];
  
  nbr == fact ? arr2cont = 0:arr2cont = fact;
    
  while(pos < nbr){ 
    for(int i = 0; i < fact; i++){
      final[pos] = arr2[arr2cont];
      pos++;
      arr2cont++;
    }
    
    if(pos >= nbr) break;
    
    for(int j = 0; j < fact;j++){
      final[pos] = arr1[arr1cont];
      pos++;
      arr1cont++;
    }
    
    if(((arr1cont+fact) < nbr) && ((arr2cont+fact) < nbr)){
      arr1cont += fact;
      arr2cont += fact;
    }else{
      arr1cont = 0;
      arr2cont = 0;
    }
  }
  return final;
}

