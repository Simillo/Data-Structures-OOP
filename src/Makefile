CPP = g++
CPPFLAGS = -Wall

OBJ = main.o DeusesGregos.o

main: $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) -o main 

main.o: main.cpp
	$(CPP) $(CPPFLAGS) -c main.cpp -o main.o

DeusesGregos.o: DeusesGregos.cpp DeusesGregos.h
	$(CPP) $(CPPFLAGS) -c DeusesGregos.cpp -o DeusesGregos.o

all: main

clean:
	rm -f *.o