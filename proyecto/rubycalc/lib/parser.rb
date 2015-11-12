require 'ast'
require 'scanner'
require 'token'
require 'calcex'

class Parser
  def initialize(istream)
    @scan = Scanner.new(istream)
  end
   
  def parse()
    return Prog()
  end
  
  private
  def Prog()
    result = Expr()
    t = @scan.getToken()
    
    if t.type != :eof then
      print "Expected EOF. Found ", t.type, ".\n"
      raise ParseError.new
    end
  
     result
  end
  
  def Expr() 
    RestExpr(Term())
  end
  
  def RestExpr(e) 
    t = @scan.getToken
    
    if t.type == :add then
      return RestExpr(AddNode.new(e,Term()))
    end
    
    if t.type == :sub then
      return RestExpr(SubNode.new(e,Term()))
    end
    
    @scan.putBackToken
    
     e
  end
  
  def Term
    RestTerm(Storable())  
  end
   
  def RestTerm(e)
    t = @scan.getToken

    if t.type == :times then
      return RestTerm(TimesNode.new(e,Storable()))
    end

    if t.type == :divide then
      return RestTerm(DivideNode.new(e,Storable()))
    end
    
    @scan.putBackToken
    return e
   
  end
   
  def Storable()
    result = Factor()
    t = @scan.getToken
    if t.type == :keyword then
      if t.lex == "S" then
        return StoreNode.new(result)
      end
    
      puts "Expected S found #{t.type} at line #{t.line}"
      raise ParseError.new

    end
    @scan.putBackToken
    result
  end
   
  def Factor() 
    t = @scan.getToken
    
    if t.type == :number then
      return NumNode.new t.lex.to_i
    end
    
    if t.type == :keyword then
      if t.lex == "R" then
        return RecallNode.new
      end
      puts "Parse Error: expected R found: " + t.lex
      puts "at line: " + t.line.to_s + "col: " + t.col.to_s
      raise ParseError.new
    end
    
    if t.type == :lparen then
      result = Expr()
      t = @scan.getToken
      if t.type == :rparen then
        return result
      end
      puts "Parse Error "
      puts "at lune"
      raise ParseError.new
    end
    
    print "Parse "
    puts "at line"
    raise ParseError.new
  end
  
end
