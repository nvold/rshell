OBJS = src/And.cpp src/Argument.cpp src/Command.cpp src/Or.cpp src/rshell.cpp src/Connector.cpp
CC = g++
CFLAGS = -Wall -Werror -ansi -pedantic $(DEBUG)


rshell: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o rshell
all : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o all