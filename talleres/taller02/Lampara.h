#include "Interfaces.h"

class Lampara: IEnergia,IPrender, IApagar {
 public:
  Lampara(bool prendida, float nivel);
  ~Lampara();
  float obtNivelEnergia();
  bool estaPrendida();
  void consumir(float nivel);
  void cargar(float nivel);
  void prender();
  void apagar();

  float nivel;

  
 private:
  bool prendida;
 };
