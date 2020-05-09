
EXECUTABLES = spiritd moles
FILE1 = spiritd
SRC1 = spiritd.c
OBJ1 = spiritd.o
FILE2 = moles
SRC2 = mole.c
OBJ2 = mole.o
CC = gcc
CFLAGS = -g

all: $(EXECUTABLES)

$(EXECUTABLES):
spiritd:
	$(CC) $(CFLAGS) -c $(SRC1) -Wall -Wextra
	$(CC) $(CFLAGS) -o $(FILE1) $(OBJ1)
moles:
	$(CC) $(CFLAGS) -c $(SRC2) -Wall -Wextra
	$(CC) $(CFLAGS) -o $(FILE2) $(OBJ2)

clean:
	rm -f $(EXECUTABLES) $(OBJ1) $(OBJ2) *~
