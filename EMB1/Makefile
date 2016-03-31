CFLAGS = -O2 -Wall -Werror

LDFLAGS = -lusb-1.0 -lncurses -g

SOURCES = main_program.c ncursesVersion1.c ncursesVersion1.h xpadtest.c xpadtest.h

TARGET = xpadtest

SOEKRIS = soekris

REMOTE = root@10.0.0.42:/bin

GCC = gcc

G = '/home/jeff/buildroot/output/host/usr/bin/i586-linux-gcc'

all: soekris upload

upload:
	scp $(SOEKRIS) $(REMOTE)



$(TARGET): $(SOURCES)
	$(GCC) $(SOURCES) -o $@ $(LDFLAGS)

host:
	$(GCC) $(SOURCES) -o $@ $(LDFLAGS)

soekris: 
	$(G) $(SOURCES) -o $@ $(LDFLAGS) 

clean:
	rm -f $(TARGET)
