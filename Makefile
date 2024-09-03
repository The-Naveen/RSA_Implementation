# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -O2 -Wall -std=c++11
DEBUGFLAGS = -g
CXXFLAGS_DEBUG = $(CXXFLAGS) $(DEBUGFLAGS)

# Linker flags
LDFLAGS = 

# Source files
SRCS = main.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Library
LIB = Lib/core.a

# Executable
TARGET = main

# Default rule
all: $(TARGET)

# Rule to build the executable with optimization
$(TARGET): $(OBJS) $(LIB)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS) $(LIB) $(LDFLAGS)

# Rule to build object files from source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Rule to build the executable with debugging
debug: CXXFLAGS = $(CXXFLAGS_DEBUG)
debug: $(TARGET)

# Rule to clean up generated files
clean:
	rm -f $(OBJS) $(TARGET)
