PROGRAMA = carro
FLAGS = -I include
CPP_VERSION = -std=c++11

diary: Carro.o Motor.o Main.o 
	g++ -o $(PROGRAMA) $(CPP_VERSION) Carro.o Motor.o Main.o

Carro.o: src/Carro.cpp
	g++ $(FLAGS) $(CPP_VERSION) -c src/Carro.cpp

Motor.o: src/Motor.cpp
	g++ $(FLAGS) $(CPP_VERSION) -c src/Motor.cpp

Main.o: src/Main.cpp
	g++ $(FLAGS) $(CPP_VERSION) -c src/Main.cpp

clean:
	rm -f *.o
	rm $(PROGRAMA)