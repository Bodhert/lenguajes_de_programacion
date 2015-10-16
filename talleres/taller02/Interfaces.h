#pragma Once
class IEnergia{
 public:
  IEnergia();
  IEnergia(float nivel);
  virtual void consumir(float nivel) = 0;
  virtual void cargar(float nivel) = 0;
 };

class IPrender{
 public:
  IPrender();
  virtual void prender() = 0;
};

class IApagar{
 public:
  IApagar();
  virtual void apagar() = 0;
};
