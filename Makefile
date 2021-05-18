#Vars

CC := g++
FLAGS := -std=c++17 -Wall -Wextra -pedantic -Weffc++ -Wold-style-cast -Woverloaded-virtual -fmax-errors=3 -g
#FLAGS := -std=c++17  -Wfatal-errors   -fmax-errors=3 -g    #om error medellanden är längre än terminalen 

LIB := -lsfml-window -lsfml-graphics -lsfml-system


SRCDIR := src
BUILDDIR := build
TARGET := bin/spelnamn
INC := -I include

#Moduler
#Alla moduler som behövs för kompilering måste läggas till här när dom skapas och ska med
OBJECTS := $(BUILDDIR)/main.o $(BUILDDIR)/Game.o $(BUILDDIR)/Menu_State.o $(BUILDDIR)/High_Score_State.o $(BUILDDIR)/Game_State.o $(BUILDDIR)/Game_World.o $(BUILDDIR)/Entity.o $(BUILDDIR)/Player.o $(BUILDDIR)/Platform.o $(BUILDDIR)/Special_Platforms.o $(BUILDDIR)/Textfield.o

#Huvudmål
$(TARGET): $(OBJECTS) dir
	@echo "Linking..."
	@echo "$(OBJECTS)"; $(CC) $(INC) $(FLAGS) $(OBJECTS) -o $(TARGET) $(LIB)

#Delmål
$(BUILDDIR)/main.o: $(SRCDIR)/main.cc
	@echo "Compiling:"
	@echo "$@"; $(CC) $(INC) $(FLAGS) -c $< -o $@

$(BUILDDIR)/Game.o: $(SRCDIR)/Game.cc
	@echo "Compiling:"
	@echo "$@"; $(CC) $(INC) $(FLAGS) -c $< -o $@

$(BUILDDIR)/Menu_State.o: $(SRCDIR)/Menu_State.cc
	@echo "Compiling:"
	@echo "$@"; $(CC) $(INC) $(FLAGS) -c $< -o $@

$(BUILDDIR)/High_Score_State.o: $(SRCDIR)/High_Score_State.cc
	@echo "Compiling:"
	@echo "$@"; $(CC) $(INC) $(FLAGS) -c $< -o $@

$(BUILDDIR)/Game_State.o: $(SRCDIR)/Game_State.cc
	@echo "Compiling:"
	@echo "$@"; $(CC) $(INC) $(FLAGS) -c $< -o $@

$(BUILDDIR)/Game_World.o: $(SRCDIR)/Game_World.cc
	@echo "Compiling:"
	@echo "$@"; $(CC) $(INC) $(FLAGS) -c $< -o $@

$(BUILDDIR)/Entity.o: $(SRCDIR)/Entity.cc
	@echo "Compiling:"
	@echo "$@"; $(CC) $(INC) $(FLAGS) -c $< -o $@

$(BUILDDIR)/Player.o: $(SRCDIR)/Player.cc
	@echo "Compiling:"
	@echo "$@"; $(CC) $(INC) $(FLAGS) -c $< -o $@

$(BUILDDIR)/Platform.o: $(SRCDIR)/Platform.cc
	@echo "Compiling:"
	@echo "$@"; $(CC) $(INC) $(FLAGS) -c $< -o $@

$(BUILDDIR)/Special_Platforms.o: $(SRCDIR)/Special_Platforms.cc
	@echo "Compiling:"
	@echo "$@"; $(CC) $(INC) $(FLAGS) -c $< -o $@
	
$(BUILDDIR)/Textfield.o: $(SRCDIR)/Textfield.cc
	@echo "Compiling:"
	@echo "$@"; $(CC) $(INC) $(FLAGS) -c $< -o $@	

.PHONY: dir
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
