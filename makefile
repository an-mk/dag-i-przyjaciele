CXX = g++

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

########

all: a.exe

a.exe: $(OBJ)
	$(CXX) $^ -o $@ -Wall -Wextra -std=c++17 -O3

clean:
	rm -f $(OBJ) a.exe
		
rebuild: clean all

.PHONY: all clean rebuild
	
debug:
	echo $(SRC) $(OBJ)