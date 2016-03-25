CFLAGS = -O2 -Wall -Werror

LDFLAGS = -lusb-1.0

SOURCES = xpadtest.c

TARGET = xpadtest

TRANSFER = scp

REMOTE = root@10.0.0.42:/bin

PASSWORD =ROOT

CC = '/home/jeff/buildroot/output/host/usr/bin/i586-linux-gcc'

GCC = gcc

# all: host
all: $(SOURCES) $(TARGET) upload

upload:
	scp $(TARGET) $(REMOTE)



$(TARGET): $(SOURCES)
	$(CC) $(SOURCES) -o $@ $(LDFLAGS)

host:
	$(GCC) $(SOURCES) -o $@ $(LDFLAGS)

clean:
	rm -f $(TARGET)