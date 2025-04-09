CC := g++
CFLAGS := -Wall -std=c++14 -I. -IC:/raylib/raylib/src -IC:/raylib/raylib/src/external
LDFLAGS := -LC:/raylib/raylib/src -lraylib -lopengl32 -lgdi32 -lwinmm
TARGET := ADSK.exe
SRC := main.cpp ball.cpp 
OBJ := $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) -c $< -o $@ $(CFLAGS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)
