#pragma Once

class Difusor {
 public:
  Difusor();
  Difusor(float anguloDifusion);
  float obtAnguloDifusion();
  virtual bool potenciaDifusion(float potencia);
  void estAnguloDifusion(float anguloDifusion);
  virtual ~Difusor(); 
 private : 
  float anguloDifusion; 
};

 class DifusorCentral : public Difusor{
 public:
  DifusorCentral();
  DifusorCentral(float difusorCentral,float anguloDifusion);
  bool potenciaDifusion(float potencia);
  void establecerDifusorCentral(float difusorCentral);
  ~DifusorCentral();
 private:
  float difusorCentral; 
};

class DifusorBivalente : public Difusor {
 public: 
  DifusorBivalente();
  DifusorBivalente(float anguloPost, float anguloDifusion);
  void estAnguloPost(float anguloPost);
  float obtAnguloPost();
  ~DifusorBivalente();
 private:
  float anguloPost;
};

class DifusorBivalenteCentral : public DifusorBivalente {
 public:
  DifusorBivalenteCentral();
  DifusorBivalenteCentral(float difusorBic, float anguloPost,float anguloDifusion);
  void establecerDifusorBic(float difusorBic);
  bool potenciaDifusion(float potencia); 
  ~DifusorBivalenteCentral();
 private:
  float difusorBic ;
};
