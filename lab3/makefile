# "executables" associated with the lab.
EXECUTABLES = catcher
SRC = catcher.c
OBJ = catcher.o

# The CC and CFLAGS variables are defined to ensure I'm using the native compiler and
# that the correct command-line options are set
CC = gcc
CFLAGS = -g -Wall -Wextra

# Here is my default target for the Makefile.  When I type make, this first target will
# be created. I.e., all the executables
all: $(EXECUTABLES)

# On the following lines (which _must_ start with a tab), are the commands I need to type --
# each time my source file is modified.
$(EXECUTABLES):
	$(CC) $(CFLAGS) -c $(SRC) $(CFLAGS)
	$(CC) $(CFLAGS) -o $(EXECUTABLES) $(OBJ)


# CLEANS of all Executables and OBJ
# or intermediates.
clean:
	rm -f $(EXECUTABLES) $(OBJ) *~
