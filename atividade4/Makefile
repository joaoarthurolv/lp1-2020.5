PROGRAMA = supermercado
FLAGS = -I include
CPP_VERSION = -std=c++11

supermercado: Cliente.o Estabelecimento.o Produto.o Teste.o
	g++ -o $(PROGRAMA) $(CPP_VERSION) Cliente.o Estabelecimento.o Produto.o Teste.o 

Produto.o: src/Produto.cpp
	g++ $(FLAGS) $(CPP_VERSION) -c src/Produto.cpp

Cliente.o: src/Cliente.cpp
	g++ $(FLAGS) $(CPP_VERSION) -c src/Cliente.cpp

Estabelecimento.o: src/Estabelecimento.cpp
	g++ $(FLAGS) $(CPP_VERSION) -c src/Estabelecimento.cpp

Teste.o: src/Teste.cpp
	g++ $(FLAGS) $(CPP_VERSION) -c src/Teste.cpp

clean:
	rm -f *.o
	rm $(PROGRAMA)