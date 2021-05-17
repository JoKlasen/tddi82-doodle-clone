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
OBJECTS := $(BUILDDIR)/Game.o $(BUILDDIR)/Menu_State.o $(BUILDDIR)/High_Score_State.o $(BUILDDIR)/Game_State.o $(BUILDDIR)/Game_World.o $(BUILDDIR)/Entity.o $(BUILDDIR)/Player.o $(BUILDDIR)/Platform.o $(BUILDDIR)/Power_Up.o

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

$(BUILDDIR)/Entity.o: $(SRCDIR)/Entity.cc dir
	$(CC) $(INC) $(FLAGS) -c $(SRCDIR)/Entity.cc -o $(BUILDDIR)/Entity.o

$(BUILDDIR)/Player.o: $(SRCDIR)/Player.cc dir
	$(CC) $(INC) $(FLAGS) -c $(SRCDIR)/Player.cc -o $(BUILDDIR)/Player.o

$(BUILDDIR)/Platform.o: $(SRCDIR)/Platform.cc dir
	$(CC) $(INC) $(FLAGS) -c $(SRCDIR)/Platform.cc -o $(BUILDDIR)/Platform.o

$(BUILDDIR)/Power_Up.o: $(SRCDIR)/Power_Up.cc dir
	$(CC) $(INC) $(FLAGS) -c $(SRCDIR)/Power_Up.cc -o $(BUILDDIR)/Power_Up.o	

	

dir:
	@mkdir -p $(BUILDDIR) bin

#Extra
.PHONY: clean
clean:
	@ \rm -rf $(BUILDDIR)/*.o *.gch bin/*

.PHONY: run
run:
	./$(TARGET)

.PHONY: test
test:
	make; ./$(TARGET)
