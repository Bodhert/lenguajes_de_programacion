#include "ast.h"
#include <iostream>
#include "calculator.h"
#include <map>

// for debug information uncomment
//#define debug

AST::AST() {}

AST::~AST() {}

BinaryNode::BinaryNode(AST* left, AST* right):
   AST(),
   leftTree(left),
   rightTree(right)
{}

BinaryNode::~BinaryNode() {
#ifdef debug
   cout << "In BinaryNode destructor" << endl;
#endif

   try {
      delete leftTree;
   } catch (...) {}

   try {
      delete rightTree;
   } catch(...) {}
}
   
AST* BinaryNode::getLeftSubTree() const {
   return leftTree;
}

AST* BinaryNode::getRightSubTree() const {
   return rightTree;
}

UnaryNode::UnaryNode(AST* sub):
   AST(),
   subTree(sub)
{}

UnaryNode::~UnaryNode() {
#ifdef debug
   cout << "In UnaryNode destructor" << endl;
#endif

   try {
      delete subTree;
   } catch (...) {}
}
   
AST* UnaryNode::getSubTree() const {
   return subTree;
}

AddNode::AddNode(AST* left, AST* right):
   BinaryNode(left,right)
{}

int AddNode::evaluate() {
   return getLeftSubTree()->evaluate() + getRightSubTree()->evaluate();
}


SubNode::SubNode(AST* left, AST* right):
   BinaryNode(left,right)
{}

int SubNode::evaluate() {
   return getLeftSubTree()->evaluate() - getRightSubTree()->evaluate();
}

TimesNode::TimesNode(AST* left, AST* right):
   BinaryNode(left,right)
{}

int TimesNode::evaluate() {
   return getLeftSubTree()->evaluate() * getRightSubTree()->evaluate();
}


DivideNode::DivideNode(AST* left, AST* right):
   BinaryNode(left,right)
{}

int DivideNode::evaluate() {
   return getLeftSubTree()->evaluate() / getRightSubTree()->evaluate();
}


ModNode::ModNode(AST* left, AST* right): 
  BinaryNode(left,right)
{}

int ModNode::evaluate(){
  return getLeftSubTree() -> evaluate() % getRightSubTree()->evaluate();
}


StoreNode::StoreNode(AST* sub):
   UnaryNode(sub)
{}

int StoreNode::evaluate() {
  
  calc -> store(getSubTree() -> evaluate());
  return calc -> recall();
}

RecallNode :: RecallNode() : AST() {}
 
int RecallNode :: evaluate(){
  return calc -> recall();
}


NumNode::NumNode(int n) :
   AST(),
   val(n)
{}

int NumNode::evaluate() {
   return val;
}

void NumNode::assignate(string n, int val){
  calc -> assignate(n,val);
 }

 int NumNode::search(string n){
   std::map<string,int>::iterator it; 
   // cout << "search de numnode"<<endl;
   it = calc -> asign.find(n);
   if(it != calc -> asign.end()){ 
     // cout << calc -> asign.find(n) -> second << endl;
     return  calc -> asign.find(n) -> second ;
   }
   // cout<< 0 << endl;
   return 0;
 }


PlusNode::PlusNode(AST *sub): UnaryNode(sub){}

int PlusNode::evaluate(){
  return calc -> plus((getSubTree() -> evaluate())); 
} 

MinusNode::MinusNode(AST *sub): UnaryNode(sub){} 

int MinusNode::evaluate(){
  return calc -> minus((getSubTree() -> evaluate()));
}

ClearNode::ClearNode():AST(){}

int ClearNode::evaluate(){  
  return calc -> clear();
}
