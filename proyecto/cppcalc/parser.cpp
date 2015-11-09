#include "parser.h"
#include "calcex.h"
#include "calculator.h"
#include <string>
#include <sstream>

string resultExtl = "";

Parser::Parser(istream* in) {
   scan = new Scanner(in);
}

Parser::~Parser() {
   try {
      delete scan;
   } catch (...) {}
}

AST* Parser::parse() {
   return Prog();
}

AST* Parser::Prog() {
   AST* result = Expr();
   Token* t = scan->getToken();

   if (t->getType() != eof) {
     cout << "Syntax Error: Expected EOF,found token at column " <<
       t->getCol() << endl;
     throw ParseError;
   }
   
   return result;
}

AST* Parser::Expr() {
  return RestExpr(Term());
}

AST* Parser::RestExpr(AST* e) {
  
  
  Token* t = scan->getToken();
  
  if (t->getType() == add) {
    return RestExpr(new AddNode(e,Term()));
   }
  
  if (t->getType() == sub)
    return RestExpr(new SubNode(e,Term()));
  
  if(t->getType() == mod)
    return RestExpr(new ModNode(e,Term()));
  
  scan->putBackToken();

  return e;
}

AST* Parser::Term() {
  
  return RestTerm(Storable());
  
}

AST* Parser::RestTerm(AST* e) {
  Token* t = scan->getToken();
  
  if (t->getType() == times) {
    return RestTerm(new TimesNode(e,Storable()));
  }
  
  if (t->getType() == divide)
    return RestTerm(new DivideNode(e,Storable()));
  
  scan->putBackToken();
  
  return e;
  
  
  throw ParseError; 
}

AST* Parser::MemOperation() {
  AST *result = Factor();
  
  Token *t = scan -> getToken();
  
  if(t -> getType() == keyword)
    if(t -> getLex() == "S")
      return new StoreNode(result);
    else if(t -> getLex() == "P"){
      return new PlusNode(result);
    }else if(t -> getLex() == "M"){
      return new MinusNode(result);
    }else{
      cout << "Syntax Error: found other keyword at pos " 
	   << t -> getCol()
	   << endl;
      throw ParseError;
    }
  scan -> putBackToken();
  return result;
  
  
}

AST* Parser::Storable(){
  return MemOperation();
} 

AST* Parser::Factor() {
  Token* t = scan->getToken();
  
  if (t->getType() == number) {
    istringstream in(t->getLex());
    int val;
    in >> val;
    return new NumNode(val);
  }else if(t -> getType() == identifier){
    istringstream in(t->getLex());
    string val;
    in >> val;
    return (Assignable(val));
  }
    
  
  if(t -> getType() == keyword){
    if(t -> getLex() == "R"){
      return new RecallNode();
    }else if( t -> getLex() == "C"){
      return new ClearNode();
    }
    else{
      cout << "Syntax error Keyword"
	   << t -> getLex()
	   << "at line " << t -> getLine()
	   << "col : " << t -> getCol() << endl;
      throw ParseError;
    }
  }
  
  if(t -> getType() == lparen){
    AST *result = Expr();
    t = scan -> getToken();
    if( t -> getType() == rparen){
      return result;
    }
    cout << "Syntax error expected ) at line:  " <<
      t -> getLine()<< "col : " <<
      t -> getCol() << endl;
    throw ParseError;
  }
  
  cout << "Syntax error expected number, R , ( at line " <<
    t -> getLine()<< "col : " <<
    t -> getCol() << endl;
  
  throw ParseError;
}

AST* Parser::Assignable(string n){
  // cout << "me llego a asignable"<< endl;  
  return Assign(n);
}

AST* Parser::Assign(string n){
  //cout << "me llego a asign"<< endl;
  Token *t = scan -> getToken();
  NumNode* result = new NumNode(0);
  stringstream stream;
  if(t -> getType() == equals){
    scan -> putBackToken();
    t = scan -> getToken();
    result = new NumNode(Expr() -> evaluate());
    result -> assignate(n,result -> evaluate());
    stream << result -> evaluate();
    resultExtl += n + " <- " + "," +  stream.str();
    resultExtl += result -> evaluate();
  }else{
    // cout << "me entro al esle de assign" << endl;
    int prueba = result -> search(n);
    // cout <<"else prueba " <<  prueba << endl;
    result  =  new NumNode(prueba);
    result -> assignate(n,prueba);
  }
  scan -> putBackToken();
  return result;
}
