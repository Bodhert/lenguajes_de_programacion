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
    if t.type == :mod then
        return RestTerm(ModNode.new(e,Storable()))
    end    
    @scan.putBackToken
    return e
   
  end
   
  def Storable()
    result = Factor()
    return MemOperation(result)
  end

  def MemOperation(result)
    t = @scan.getToken
    if t.type == :keyword then
      if t.lex == "S" 
        return StoreNode.new(result)
      elsif t.lex == "M"
        return MinusNode.new(result)
      elsif t.lex == "P"
        return PlusNode.new(result)
      end

      puts "Expected S or M or P  found #{t.type} at line #{t.line}"
      raise ParseError.new   
    end
    @scan.putBackToken
    result
  end
   
  def Assignable
    t = @scan.getToken
    Assign(t.lex.to_s)
  end
  
  def Assign lex
    t = @scan.getToken
    #result = NumNode.new(0)
    if t.type == :equals
      result = NumNode.new(Expr().evaluate())
      result.assign lex
    else
      @scan.putBackToken
      result = NumNode.new(0)
      result.search lex    
    end
    return result
  end

  def Factor() 
    t = @scan.getToken
    
    if t.type == :number then
      return NumNode.new t.lex.to_i
    end
    
    if t.type == :identifier then
      @scan.putBackToken
      return Assignable()
    end
    
    if t.type == :keyword then
      if t.lex == "R" 
        return RecallNode.new
      elsif t.lex == "C"
        return ClearNode.new
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
      puts "at line: " + t.line.to_s + "col: " + t.col.to_s
      raise ParseError.new
    end
  
    print "Parse "
    puts "at line: " + t.line.to_s + "col: " + t.col.to_s
    raise ParseError.new
  end
end
