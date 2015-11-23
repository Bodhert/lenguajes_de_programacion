require 'parser'
require 'ast'

class Calculator
  attr_accessor :memory
  attr_accessor :map
  
  def initialize()
    @memory = 0
    @map = Hash.new
  end
  
  def eval(expr)
    parser = Parser.new(StringIO.new(expr))
    ast = parser.parse()
    return ast.evaluate()
  end
  
  def search(var)
    if @map.has_key?(var)
      return @map[var]
    else
      return 0
    end
  end
  
  def assign(var,result) 
    @map[var] = result
  end

  def enviroment
    ENV.each_pair do |k, v|
      tempVar = "#{tempVar}#{k}"
      prueba = "#{v}\n"
      tempVar.to_s
      if tempVar.start_with?("CALCVAR")
        variable = tempVar[7,tempVar.length]
        assign(variable,prueba.to_i)
      end
    end
  end

  def argumentos 
    name = ARGV.first
    
    puts "Hello #{name}, good day!"
  end

end
