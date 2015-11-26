require 'set'

class BinaryNode
  attr_reader :left, :right
  
  def initialize(left,right)
    @left = left
    @right = right
  end
end
   
class UnaryNode
  attr_reader :subTree
   
  def initialize(subTree)
    @subTree = subTree
  end
end

class AddNode < BinaryNode
  def initialize(left, right)
    super(left,right)
  end
   
  def evaluate() 
    return @left.evaluate() + @right.evaluate()
  end
end

class SubNode < BinaryNode
  def initialize(left, right)
    super(left,right)
  end   
  def evaluate() 
    return @left.evaluate() - @right.evaluate()
  end
end

class TimesNode < BinaryNode
  def initialize(left, right)
    super(left,right)
  end
   
  def evaluate() 
    return @left.evaluate() * @right.evaluate()
  end
end

class DivideNode < BinaryNode
  def initialize(left, right)
    super(left,right)
  end
   
  def evaluate() 
    return @left.evaluate() / @right.evaluate()
  end
end

class ModNode < BinaryNode
  def initialize(left,right)
    super(left,right)
  end

  def evaluate()
    return @left.evaluate() % @right.evaluate()
  end
end

class StoreNode < UnaryNode
  def initialize(subTree)
    super(subTree)
  end
  
  def evaluate
    $calc.memory = subTree.evaluate()
  end
end

class RecallNode
  def evaluate
    $calc.memory
  end 
end

class MinusNode < UnaryNode
  def initialize(subTree)
    super(subTree)
  end
  
  def evaluate
    min = subTree.evaluate()
    $calc.memory -= min
  end
end

class PlusNode < UnaryNode
  def initialize(subTree)
    super(subTree)
  end

  def evaluate
    plus = subTree.evaluate()
    $calc.memory += plus
  end
end

class ClearNode
  def evaluate
    $calc.memory = 0
  end
end

class NumNode 
  def initialize(num)
    @num = num
  end

  def search var
    @num = $calc.search(var)
  end

  def assign (var)
    $calc.assign(var,@num)
  end

  def evaluate() 
    return @num
  end
end
