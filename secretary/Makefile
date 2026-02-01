CC = gcc
CFLAGS = -std=c11 -Wall
LDFLAGS = -lm

TARGET = bin/main

SOURCES = src/main.c \
					src/list.c \
					src/glbs.c

HEADERS = $(SOURCES:.c=.h)
OBJECTS = $(SOURCES:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(SDL_FLAGS)

clean:
	rm -f $(OBJECTS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

debug: CFLAGS += -g -O0 -DDEBUG
debug: $(TARGET)

release: CFLAGS += -DNDEBUG
release: $(TARGET)

asan: CFLAGS += -g -O1 -fsanitize=address
asan: LDFLAGS += -fsanitize=address
asan: $(TARGET)
