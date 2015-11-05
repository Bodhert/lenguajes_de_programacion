class A
  attr_reader :valor
  def initialize(valor)
    @valor = valor
  end
  def metodo
    valor * 5
  end
end

class B < A
  def initialize(valor)
    super (valor)
  end
  def metodo
    valor * 10;
  end
end

class AP
  attr_reader :valor
  def initialize(valor)
    @valor = valor
  end
  def metodo
    valor * 5
  end
end

class BP
  attr_reader :valor
  def initialize(valor)
    @valor = valor
  end
  def metodo
    valor * 5
  end
end

def invocarMetodo a
  a.metodo
end
