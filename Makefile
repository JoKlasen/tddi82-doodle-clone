#Vars

CC := g++
FLAGS := -std=c++17 -Wall -Wextra -pedantic -Weffc++ -Wold-style-cast -Woverloaded-virtual -fmax-errors=3 -g
LIB := -lsfml-window -lsfml-graphics -lsfml-system


SRCDIR := src
BUILDDIR := build
TARGET := bin/spelnamn
INC := -I include

<<<<<<< HEAD
=======
#Moduler
#Alla moduler som behövs för kompilering måste läggas till här när dom skapas och ska med
OBJECTS := $(BUILDDIR)/Game.o

#Huvudmål
main: $(OBJECTS)
	$(CC) $(INC) $(FLAGS) main.cc -o $(TARGET) $(LIB)

#Delmål
$(BUILDDIR)/Game.o: $(SRCDIR)/Game.cc dir
	$(CC) $(INC) $(FLAGS) -c $(SRCDIR)/Game.cc -o $(BUILDDIR)/Game.o

dir:
	@mkdir -p $(BUILDDIR)

>>>>>>> 953babcb1009c94ec495d46f7d46b119991dd030
#Extra
.PHONY: run
run:
	./$(TARGET)
