#include "Interfaces.h"

class Lampara: IEnergia,IPrender, IApagar {
 public: 
  float obtNivelEnergia();
  bool estaPrendida();
  float nivel;
 private:
  bool prendida;
 };
