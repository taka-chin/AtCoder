CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++17 -g

TARGET = main
SRC = main.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -rf $(TARGET) $(TARGET).dSYM

re: clean all

.PHONY: all clean re
