OBJS = And.cpp Argument.cpp Command.cpp Or.cpp rshell.cpp Connector.cpp
CC = g++
CFLAGS = -Wall -Werror -ansi -pedantic $(DEBUG)

$(MAKE) -C $(CODE_DIR)

rshell: $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o rshell
all : $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o all