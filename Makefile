# Define compiler
CXX 		= g++

# Define compiler flags
CXXFLAGS 	= -g -Werror

# Define folders
IDIR 		= inc
SDIR 		= src

BUILD_DIR 	= build
BIN_DIR 	= $(BUILD_DIR)/bin

# Define include files
_DEPS 		= DungeoonsAndDragoons.h Character.h
DEPS 		= $(patsubst %,$(IDIR)/%,$(_DEPS))

# Define source files
_SRCS 		= DungeoonsAndDragoons.cpp Character.cpp
SRCS 		= $(patsubst %,$(SDIR)/%,$(_SRCS))

# Define object files
_BINS 		= DungeoonsAndDragoons.o Character.o
BINS 		= $(patsubst %,$(BIN_DIR)/%,$(_BINS))

# Define make messages
CLEAN 		= Build removal complete

# Create program executable
DungeoonsAndDragoons: $(BUILD_DIR) $(BINS)
	$(CXX) $(CXXFLAGS) -o DungeoonsAndDragoons.exe $(BINS)

# Create build and object directories
$(BUILD_DIR):
	@mkdir $(BUILD_DIR)
	@mkdir $(BIN_DIR)

# Create build folder and define object (binary) files
$(BIN_DIR)/%.o: $(SDIR)/%.cpp $(IDIR)/%.h
	$(CXX) $(CXXFLAGS) -c $< -o $@ -I $(IDIR)

.PHONY: clean

# Remove build
clean:
	@rm -f -r $(BUILD_DIR)
	@rm -f DungeoonsAndDragoons
	@echo ${CLEAN}