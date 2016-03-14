PROJECT_NAME=MemoryManagement

# flags -Wall and -Werror are omitted with a reason :)
CFLAGS=-ggdb -O0 -Iproduct

MAIN_SOURCES=product/*.cpp

GCC=g++

all: $(PROJECT_NAME)

$(PROJECT_NAME): $(MAIN_SOURCES) Makefile product/*.h
	@$(GCC) $(CFLAGS) $(MAIN_SOURCES) -o $@

clean:
	@rm -rf $(PROJECT_NAME)
