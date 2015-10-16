#include"funcionesCadena.h"
#include <iostream>
using namespace std;

char* saltarbalcosinincio(char *s){
  int cont = 0;
  while(*s == 32){
    *s = '\0';
     cont++;
     s += 1;
  }
  return s - cont;  
}

const char* indiceAlaDerecha(const char *s, int c){
  const char* poscicion;
  while(*s != '\0'){
    if(*s == c ){
      poscicion = s; 
      s = s + 1;
    }else
      s = s + 1;
  }
  if(*poscicion == c) return poscicion; 
  return s;
}


int main(){
  char arr[] = {"hola"};
  cout << indiceAlaDerecha(arr, 5);
}
