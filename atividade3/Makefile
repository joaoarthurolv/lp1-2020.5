PROGRAMA = diary
FLAGS = -I include
CPP_VERSION = -std=c++11

diary: App.o main.o Date.o Time.o Diary.o Config.o
	g++ -o $(PROGRAMA) $(CPP_VERSION) App.o main.o Date.o Time.o Diary.o Config.o

App.o: src/App.cpp
	g++ $(FLAGS) $(CPP_VERSION) -c src/App.cpp

Date.o: src/Date.cpp
	g++ $(FLAGS) $(CPP_VERSION) -c src/Date.cpp

Time.o: src/Time.cpp
	g++ $(FLAGS) $(CPP_VERSION) -c src/Time.cpp

Diary.o: src/Diary.cpp
	g++ $(FLAGS) $(CPP_VERSION) -c src/Diary.cpp

Config.o: src/Config.cpp
	g++ $(FLAGS) $(CPP_VERSION) -c src/Config.cpp

main.o: src/main.cpp
	g++ $(FLAGS) $(CPP_VERSION) -c src/main.cpp

clean:
	rm -f *.o
	rm $(PROGRAMA)