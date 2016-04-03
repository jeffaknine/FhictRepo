PROJECT_NAME=ass4

CFLAGS= -g -Wall -ggdb -O0 -Iproduct 

SHARED_SOURCES= Scan.cpp ScanList.cpp


TEST_SOURCES=Ass4Test.cpp

TEST_LIBS=-lgtest -lgtest_main -lpthread

GCC=g++

all: $(PROJECT_NAME)Test

$(PROJECT_NAME):
	@$(GCC) $(CFLAGS) $(SHARED_SOURCES) -o $@

$(PROJECT_NAME)Test:
	@$(GCC) $(CFLAGS) $(TEST_SOURCES) $(SHARED_SOURCES) -o $@ $(TEST_LIBS) -Itest	
clean:
	@rm -rf $(PROJECT_NAME)Test $(PROJECT_NAME)

test: $(PROJECT_NAME)Test
	@./$(PROJECT_NAME)Test