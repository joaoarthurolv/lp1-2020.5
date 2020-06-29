diary: App.o main.o Date.o Time.o Diary.o
	g++ -o diary -std=c++11 App.o main.o Date.o Time.o Diary.o

App.o: src/App.cpp
	g++ -I include -std=c++11 -c src/App.cpp

Date.o: src/Date.cpp
	g++ -I include -std=c++11 -c src/Date.cpp

Time.o: src/Time.cpp
	g++ -I include -std=c++11 -c src/Time.cpp

Diary.o: src/Diary.cpp
	g++ -I include -std=c++11 -c src/Diary.cpp

main.o: src/main.cpp
	g++ -I include -std=c++11 -c src/main.cpp