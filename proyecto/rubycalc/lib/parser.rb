urequire 'ast'
require 'scanner'
rxequire 'token'
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
    RestExpr(Term)
  end
   
  def RestExpr(e) 
    t = @scan.getToken
    
    if t.type == :add then
      return RestExpr(AddNode.new(e,Term))
    end
    
    if t.type == :sub then
      return RestExpr(SubNode.new(e,Term))
    end
      
    @scan.putBackToken()
    
    return e
  end
  
  def Term
    RestTerm(Storable)
    # # Write your Term() code here. This code is just temporary
    # # so you can try the calculator out before finishing it.
    
    # t = @scan.getToken()
    
    # if t.type == :number then
    #   val = t.lex.to_i
    #   return NumNode.new(val)
    # end
    
    # puts "Term not implemented\n"
    
    # raise ParseError.new
    
  end
   
  def RestTerm(e)
    t = @scan.getToken

    if t.type == :times then
      return ResTerm(TimesNode.new(e,Storable))
    end

    if t.type == :divide then
      return ResTerm(DivideNode.new(e,Storable))
    end
    
    @scan.putBackToken
    return e
    
    # puts "RestTerm not implemented"
    # raise ParseError.new # "Parse Error"
  end
   
  def Storable()
    result = Factor
    t = @scan.getToken
    if t.type == :keyword then
      if t.lex == "S" then
        return StoreNode.new(result)
      end
    end
    puts "Expected S found #{t.lex} at line #{t.line}"
    raise ParseError.new
  end
   
  def Factor() 
    result = Expr
    t = @scan.getToken

    if t.type == :number then
      return NumNode.new t.lex.to_i
    
    if t.type == :keyword then
      if t.lex == "R" then
        return RecallNode
      end
      puts "Parse Error: expected R found: " + t.lex
      puts "at line: " + t.line.to_s + "col: " + t.col.to_s
      raise ParseError.new
    end

    if t.type == :lparen then
      result = Expr
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
