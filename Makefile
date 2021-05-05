#Vars

CC := g++
FLAGS := -std=c++17 -Wall -Wextra -pedantic -Weffc++ -Wold-style-cast -Woverloaded-virtual -fmax-errors=3 -g
LIB := -lsfml-window -lsfml-graphics -lsfml-system


#Mål
main:
	$(CC) $(FLAGS) main.cc -o bin/main $(LIB)


#Extra
.PHONY: run
run:
	./bin/main
