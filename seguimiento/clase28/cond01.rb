
#!/usr/bin/ruby
#esto es un comentario en ruby 
s = gets.chomp
v = s.to_i

if v == 10 then
  puts "v: #{v} es 10"
elsif v == 20 then
  puts "v:",v,"es diferente de 20"
else
  puts "v:" + v.to_s + " es diferent ede 20 y 10"
end

