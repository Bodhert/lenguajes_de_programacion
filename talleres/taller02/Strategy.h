#pragma Once
class Strategy{
 public:
  Strategy();
  virtual ~Strategy();
   virtual void operation() = 0;
};

class ConcreteStrategyA : public Strategy {
 public:
  ConcreteStrategyA();
 ~ConcreteStrategyA();
  void operation();
};

class ConcreteStrategyB : public Strategy {
 public:
  ConcreteStrategyB();
 ~ConcreteStrategyB();
  void operation();
};

class StrategyClient {
 private:
  Strategy* strategy;
 public:
  StrategyClient();
  ~StrategyClient();
  void setStrategy(Strategy* strategy);
  void performOperation();
  
};


