CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -Wuninitialized -std=c++23 -g

TARGET = main
SRC = main.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -rf $(TARGET) $(TARGET).dSYM

re: clean all

.PHONY: all clean re
