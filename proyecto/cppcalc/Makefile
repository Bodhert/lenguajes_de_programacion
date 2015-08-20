calc: calc.o scanner.o token.o ast.o parser.o calculator.o
	g++ -g -o $@ calc.o scanner.o token.o ast.o parser.o calculator.o

calc.o: calc.cpp scanner.h token.h
	g++ -g -c $<

calculator.o: calculator.cpp calculator.h parser.h ast.h
	g++ -g -c $<

scanner.o: scanner.cpp scanner.h token.h
	g++ -g -c $<

token.o: token.cpp token.h
	g++ -g -c $<

ast.o: ast.cpp ast.h
	g++ -g -c $<

parser.o: parser.cpp parser.h
	g++ -g -c $<

clean:
	rm -f *.o
	rm -f calc


