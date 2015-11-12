#include "calculator.h"
#include "parser.h"
#include "ast.h"
#include <string>
#include <iostream>
#include <sstream>
#include <map>

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
    cout << "=> " << result << " [" << resultExtl << "]" << endl;
    resultExtl = "";
  }else
    cout << "=> " << result << endl;
}

string Calculator::getN(string expr){
   Parser* parser = new Parser(new istringstream(expr));
   return expr;
   delete parser;
}

bool Calculator::searchF(string expr){
  map<string,int>::iterator it;
  it = asign.find(expr);
  if(it != asign.end()) return true;
  return false;
}

void Calculator::assignate(string n,int val){
  map<string,int>::iterator it;
  it = asign.find(n);
  if(it != asign.end()){
    it -> second = val;
  }else
    asign.insert(pairs(n,val));
}

void Calculator::amb(char *env[]){
  string toEval;
  for (int j = 1; env[j] != NULL; j++){
    string envi = env[j];
    if(envi.find("CALCVAR")==0){
      toEval = envi.substr(7,envi.size());
      size_t cut = toEval.find("=");
      if(cut != string::npos ){
	string temp1 = toEval.substr(0,cut);
	string temp2 = toEval.substr(cut+1,toEval.size());
	istringstream buffer(temp2);
	int value;
	//buffer >> value;
	if((buffer >> value).fail()){
	  cout << "error" << endl;
	 }else
	  assignate(temp1,value);
      }
    }
  }
}

bool Calculator::vars(string n){
  string toEval = n;
  size_t cut = toEval.find("=");
  if(cut != string::npos){
    toEval = toEval.substr(0,cut);
    //cout << "toEval es  " << toEval;
  }
  if(searchF(toEval)) return true;
  return false;
}



