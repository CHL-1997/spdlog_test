CC = gcc
CXX = g++

C_SRC = $(wildcard ./*.c)
CXX_SRC = $(wildcard ./*.cpp)

OBJ = $(C_SRC:.c=.o) $(CXX_SRC:.cpp=.o)

all: $(OBJ)
	$(CXX) -o main $^

%.o: %.cpp
	$(CXX) -c $<

%.o: %.c
	$(CC) -c $<

clean:
	rm -f $(OBJ) main

.PHONY: all clean