PROGRAMA = banco
FLAGS = -I include
CPP_VERSION = -std=c++11

diary: Conta.o Cliente.o Main.o 
	g++ -o $(PROGRAMA) $(CPP_VERSION) Conta.o Cliente.o Main.o

Conta.o: src/Conta.cpp
	g++ $(FLAGS) $(CPP_VERSION) -c src/Conta.cpp

Cliente.o: src/Cliente.cpp
	g++ $(FLAGS) $(CPP_VERSION) -c src/Cliente.cpp

Main.o: src/Main.cpp
	g++ $(FLAGS) $(CPP_VERSION) -c src/Main.cpp

clean:
	rm -f *.o
	rm $(PROGRAMA)