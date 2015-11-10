#ifndef calculator_h
#define calculator_h

#include <map>
#include <string>
 
using namespace std;

typedef pair<string, int> pairs;

class Calculator {
 public:
   Calculator();

   int eval(string expr);
   void store(int val);
   int recall();
   int plus(int val);
   int minus(int val);
   int clear();
   void Print(string expr, int result);
   map<string,int> asign;
 private:
   int memory;
   
};

extern Calculator* calc;
extern string resultExtl;
#endif
