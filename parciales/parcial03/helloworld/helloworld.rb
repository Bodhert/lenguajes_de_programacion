
# implemente la funcion isHelloWorld que
# identifique si las palabras Hello World
# en cualquier formato de mayusculas y minusculas
# contiene Hello World

def isHelloWorld(a)
  s = a.chomp
  v = s.downcase
  return v == 'hello world'
end
