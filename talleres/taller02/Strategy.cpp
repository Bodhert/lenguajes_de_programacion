#include "Strategy.h"
#include <iostream>

using namespace std;

Strategy::Strategy(){}
Strategy:: ~Strategy(){}


ConcreteStrategyA::ConcreteStrategyA(){}

void ConcreteStrategyA::operation(){
  cout << "Hello Strategy A" << endl;
}

ConcreteStrategyB::ConcreteStrategyB(){}
void ConcreteStrategyB :: operation(){
  cout << "Hello Strategy B" << endl;
}

StrategyClient::StrategyClient(){
}
void StrategyClient::setStrategy(Strategy* strategy){
   strategy = strategy;
}

void StrategyClient::performOperation(){
  strategy -> operation();
}
StrategyClient::~StrategyClient(){}

