CC = gcc

CFLAGS = -Wall -Wextra -std=c11 -Iinclude

LDLIBS = -lm

SRC = src/main.c src/algorithm.c src/utilities.c

TARGET = gps_simulator

TEST_TARGET = test_gps

.PHONY: all run test clean

all: $(TARGET)

$(TARGET): $(SRC) include/project.h
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LDLIBS)

run: $(TARGET)
	./$(TARGET)

$(TEST_TARGET): tests/test.c src/algorithm.c src/utilities.c include/project.h
	$(CC) $(CFLAGS) tests/test.c src/algorithm.c src/utilities.c -o $(TEST_TARGET) $(LDLIBS)

test: $(TEST_TARGET)
	./$(TEST_TARGET)

clean:
	rm -f $(TARGET) $(TEST_TARGET)
