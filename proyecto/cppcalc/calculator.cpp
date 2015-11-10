#include "calculator.h"
#include "parser.h"
#include "ast.h"
#include <string>
#include <iostream>
#include <sstream>


Calculator::Calculator():
   memory(0)
{}

int Calculator::eval(string expr) {
 
   Parser* parser = new Parser(new istringstream(expr));
   
   AST* tree = parser->parse();
   
   int result = tree->evaluate();
   
   calc -> Print(expr, result);
 
   delete tree;
   
   delete parser;
   
   return result;
}

void Calculator::store(int val) {
   memory = val;
}

int Calculator::recall() {
   return memory;
}

int Calculator::plus(int val){
  return  memory += val;
}

int Calculator::minus(int val){
  return memory -= val;
}
int Calculator::clear(){
  memory = 0;
  return memory;
}

void Calculator::Print(string expr, int result){
  size_t find = expr.find("=");
  if(find != string::npos){
    resultExtl = resultExtl.substr(0,resultExtl.size()-1);
    cout << "=>" << result << " [" << resultExtl << "]" << endl;
    resultExtl = "";
  }else
    cout << "=>" << result << endl;
}

