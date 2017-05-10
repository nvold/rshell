OBJS = And.cpp Argument.cpp Command.cpp Or.cpp rshell.cpp Connector.cpp
CC = g++
CFLAGS = -Wall -Werror -ansi -pedantic $(DEBUG)

SOURCES = $(rshell find $(src) -name '*.$(cpp)')
rshell: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o rshell
all : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o all