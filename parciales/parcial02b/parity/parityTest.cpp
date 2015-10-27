#include "parityTest.h"

Parity parityTest(const char word[], int& nEven, int &nOdd) {
  nEven = 0;
  nOdd = 0;
  int  iterator = 0;
  while(word[iterator] != '\0'){
    if(isEvenParity(word[iterator])){
      nEven++;
    }
    else if(isOddParity(word[iterator])){
      nOdd++;
    }
  iterator++;
  }  

  if(nEven>nOdd){
    return even;
  }else if(nEven==nOdd){
    return none;
  }else{
    return odd;
  }
 
  
}
