VPATH = rshell/src

all: Argument.h Connector.h And.h Or.h Command.h
	g++ -Wall -Werror -ansi -pedantic Argument.cpp Command.cpp Connector.cpp And.cpp Or.cpp rshell.cpp
rshell: Argument.h Connector.h And.h Or.h Command.h
	g++ -Wall -Werror -ansi -pedantic Argument.cpp Command.cpp Connector.cpp And.cpp Or.cpp rshell.cpp
