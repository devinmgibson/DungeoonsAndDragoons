# Compiler
CC = g++

# Important folders
IDIR = inc # Include (.h) files
ODIR = obj # Object (.o) files
SDIR = src # Source (.cpp) files

# Compiler flags
CFLAGS = -I$(IDIR) -g -Wall

_DEPS = Chess.h GamePiece.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_SRC = Chess.cpp GamePiece.cpp
SRC = $(patsubst %,$(SDIR)/%,$(_SRC))

# Put object files into obj directory
../obj/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)