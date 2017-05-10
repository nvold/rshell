CC=g++
CC_FLAGS=: -Wall -Werror -ansi -pedantic
EXEC=rshell.out
SOURCES=$(src *.cpp)
OBJECTS=$(SOURCES:.cpp=.o)

$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXEC)

%.o: %.cpp
	$(CC) -c $(CC_FLAGS) $< -o $@

clean:
	rm -f $(EXEC) $(OBJECTS)
