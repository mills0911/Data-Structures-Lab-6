CXX ?= g++
CXXFLAGS ?= -std=c++17 -Wall -Wextra -pedantic
TARGET := app
SOURCES := main.cpp AVL_tree.cpp node.cpp
OBJECTS := $(SOURCES:.cpp=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJECTS)
	cmd /C del /Q $(subst /,\\,$(OBJECTS))

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	cmd /C del /Q $(subst /,\\,$(OBJECTS)) $(TARGET).exe 2>NUL
