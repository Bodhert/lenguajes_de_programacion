#!/usr/bin/ruby

def echo()
  s = gets
  puts s
end 


def echo2()
  s = gets
  puts s
  return s
end 

#definir una variable global

$count = 0

def genNroCons
  $count += 1
end

def suma(a,b)
  a + b
end 

def suma2 a,b
  a + b
end

class Estudiante
  attr_reader :nombre
  attr_accessor :edad
  def initialize(nombre,edad)
    @nombre = nombre
    @edad = edad
  end
  def imprimir
    salida = "nombre:#{@nombre} edad:#{@edad}"
    puts salida
  end
end

#Este es el supuesto main de ruby
# echo
# echo2o

print "Digite su nombre: "
nombre = gets.chomp
print "Edad: "
edad = gets.to_i

est1 = Estudiante.new(nombre, edad)
est1.imprimir
