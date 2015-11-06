#pragma once

#include "ast.h"
#include "scanner.h"

class Parser {
 public:
   Parser(istream* in);
   ~Parser();

   AST* parse();

 private:
   AST* Prog();
   AST* Expr();
   AST* RestExpr(AST* e);
   AST* Term();
   AST* RestTerm(AST* t);
   AST* Storable();
   AST* MemOperation();
   AST* Factor();
   AST* Assignable(string n);
   AST* Assign(string n);
   Scanner* scan;
};


