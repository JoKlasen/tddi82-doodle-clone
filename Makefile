#Vars

CC := g++
FLAGS := -std=c++17 -Wall -Wextra -pedantic -Weffc++ -Wold-style-cast -Woverloaded-virtual -fmax-errors=3 -g
LIB := -lsfml-window -lsfml-graphics -lsfml-system


SRCDIR := src
BUILDDIR := build
TARGET := bin/spelnamn
INC := -I include

#Moduler
#Alla moduler som behövs för kompilering måste läggas till här när dom skapas och ska med
OBJECTS := $(BUILDDIR)/Game.o $(BUILDDIR)/Menu_State.o

#Huvudmål
main: $(OBJECTS)
	$(CC) $(INC) $(FLAGS) $(SRCDIR)/main.cc $(OBJECTS) -o $(TARGET) $(LIB)

#Delmål
$(BUILDDIR)/Game.o: $(SRCDIR)/Game.cc dir
	$(CC) $(INC) $(FLAGS) -c $(SRCDIR)/Game.cc -o $(BUILDDIR)/Game.o

$(BUILDDIR)/Menu_State.o: $(SRCDIR)/Menu_State.cc dir
	$(CC) $(INC) $(FLAGS) -c $(SRCDIR)/Menu_State.cc -o $(BUILDDIR)/Menu_State.o

$(BUILDDIR)/Platform.o: $(SRCDIR)/Platform.cc dir
	$(CC) $(INC) $(FLAGS) -c $(SRCDIR)/Platform.cc -o $(BUILDDIR)/Platform.o

dir:
	@mkdir -p $(BUILDDIR) bin

#Extra
.PHONY: clean
clean:
	@ \rm -rf $(OBJDIR)/*.o *.gch bin/*

.PHONY: run
run:
	./$(TARGET)
