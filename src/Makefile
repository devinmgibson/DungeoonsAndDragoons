# Compiler
CC = g++

# Important folders
IDIR = inc # Include (.h) files
ODIR = obj # Object (.o) files
SDIR = src # Source (.cpp) files

# Compiler flags
CFLAGS = -I$(IDIR) -g -Wall

_DEPS = DungeoonsAndDragoons.h Character.h Dungeoon.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_SRC = DungeoonsAndDragoons.cpp Character.cpp Dungeoon.cpp
SRC = $(patsubst %,$(SDIR)/%,$(_SRC))

# Put object files into obj directory
../obj/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)