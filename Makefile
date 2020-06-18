CC = g++
CFLAGS = -O3 -ffast-math
VFLAGS = --std=c++17
LDFLAGS = -pthread  -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -lGL
CDFLAGS = -g
TARGET = a.out
DTARGET = d_a.out
WARNINGS = -pedantic -Wall -Wextra
CPP = main.cpp

all:
	$(CC) $(WARNINGS) $(VFLAGS) $(CFLAGS) $(CPP) $(LDFLAGS) -o $(TARGET)

debug:
	$(CC) $(WARNINGS) $(VFLAGS) $(CDFLAGS) $(CPP) $(LDFLAGS) -o $(DTARGET)

clean:
	rm -rf $(TARGET) $(DTARGET)
