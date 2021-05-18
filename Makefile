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
SRCEXT := cc
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))

#Huvudmål
$(TARGET): dir $(OBJECTS)
	@echo "Linking..."
	@echo "$(OBJECTS)"; $(CC) $(INC) $(FLAGS) $(OBJECTS) -o $(TARGET) $(LIB)
	@echo "Done!"

#Delmål
$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
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
