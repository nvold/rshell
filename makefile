compile = g++
flags = -Wall -Werror -ansi -pedantic

all:
	mkdir -p ./bin
	$(compile) $(flags) ./src/*.cpp -o ./bin/rshell
	
rshell:
	$(compile) $(flags) ./src/*.cpp -o ./bin/rshell
	
clean:
	rm -rf ./bin
