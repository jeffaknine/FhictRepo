PROJECT_NAME=ass3

CFLAGS= -g -Wall -Werror -ggdb -O0 -Iproduct 

SHARED_SOURCES= Car.h Truck.h Wheel.h Car.cpp Truck.cpp Wheel.cpp


TEST_SOURCES=Ass3Test.cpp

TEST_LIBS=-lgtest -lgtest_main -lpthread

GCC=g++

all: $(PROJECT_NAME)

$(PROJECT_NAME):
	@$(GCC) $(CFLAGS) $(SHARED_SOURCES) -o $@

$(PROJECT_NAME)Test: 
	@$(GCC) $(CFLAGS) $(TEST_SOURCES) -o $@ $(TEST_LIBS) -Itest	
clean:
	@rm -rf $(PROJECT_NAME)Test $(PROJECT_NAME)

test: $(PROJECT_NAME)Test
	@./$(PROJECT_NAME)Test