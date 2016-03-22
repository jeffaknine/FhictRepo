CFLAGS = -O2 -Wall -Werror

LDFLAGS = -lusb-1.0 -lncurses

SOURCES = main_program.c ncursesVersion1.c ncursesVersion1.h xpadtest.c xpadtest.h

TARGET = xpadtest

GCC = gcc

all: $(TARGET)

upload:
	scp $(TARGET) $(REMOTE)



$(TARGET): $(SOURCES)
	$(GCC) $(SOURCES) -o $@ $(LDFLAGS)

host:
	$(GCC) $(SOURCES) -o $@ $(LDFLAGS)

clean:
	rm -f $(TARGET)
