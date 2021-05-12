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
OBJECTS := $(BUILDDIR)/Game.o $(BUILDDIR)/Menu_State.o $(BUILDDIR)/High_Score_State.o $(BUILDDIR)/Game_State.o $(BUILDDIR)/Game_World.o

#Huvudmål
main: $(OBJECTS)
	$(CC) $(INC) $(FLAGS) $(SRCDIR)/main.cc $(OBJECTS) -o $(TARGET) $(LIB)

#Delmål
$(BUILDDIR)/Game.o: $(SRCDIR)/Game.cc dir
	$(CC) $(INC) $(FLAGS) -c $(SRCDIR)/Game.cc -o $(BUILDDIR)/Game.o

$(BUILDDIR)/Menu_State.o: $(SRCDIR)/Menu_State.cc dir
	$(CC) $(INC) $(FLAGS) -c $(SRCDIR)/Menu_State.cc -o $(BUILDDIR)/Menu_State.o

$(BUILDDIR)/High_Score_State.o: $(SRCDIR)/High_Score_State.cc dir
	$(CC) $(INC) $(FLAGS) -c $(SRCDIR)/High_Score_State.cc -o $(BUILDDIR)/High_Score_State.o

$(BUILDDIR)/Game_State.o: $(SRCDIR)/Game_State.cc dir
	$(CC) $(INC) $(FLAGS) -c $(SRCDIR)/Game_State.cc -o $(BUILDDIR)/Game_State.o

$(BUILDDIR)/Game_World.o: $(SRCDIR)/Game_World.cc dir
	$(CC) $(INC) $(FLAGS) -c $(SRCDIR)/Game_World.cc -o $(BUILDDIR)/Game_World.o

dir:
	@mkdir -p $(BUILDDIR) bin

#Extra
.PHONY: clean
clean:
	@ \rm -rf $(BUILDDIR)/*.o *.gch bin/*

.PHONY: run
run:
	./$(TARGET)
