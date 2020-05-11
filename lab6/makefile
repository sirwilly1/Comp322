#
# EXECUTABLES = spiritd moles
# FILE1 = spiritd
# SRC1 = spiritd.c
# OBJ1 = spiritd.o
# FILE2 = moles
# SRC2 = mole.c
# OBJ2 = mole.o
# CC = gcc
# CFLAGS = -g
#
# all: $(EXECUTABLES)
#
# $(EXECUTABLES):
# spiritd:
# 	$(CC) $(CFLAGS) -c $(SRC1) -Wall -Wextra
# 	$(CC) $(CFLAGS) -o $(FILE1) $(OBJ1)
# moles:
# 	$(CC) $(CFLAGS) -c $(SRC2) -Wall -Wextra
# 	$(CC) $(CFLAGS) -o $(FILE2) $(OBJ2)
#
# clean:
# 	rm -f $(EXECUTABLES) $(OBJ1) $(OBJ2) *~
EXECUTABLES1=spiritd mole
EXECUTABLES2=spiritd
EXECUTABLES3=mole
SRC=spiritd.c mole.c
OBJ=spiritd.o mole.o
SRC1=spiritd.c
OBJ1=spiritd.o
SRC2=mole.c
OBJ2=mole.o


CC=gcc
CFLAGS=-g


all: spiritd mole
spiritd: spiritd.c
	$(CC) $(CFLAGS) -c spiritd.c
	$(CC) $(CFLAGS) -o $@ spiritd.o
mole: mole.c
	$(CC) $(CFLAGS) -c mole.c
	$(CC) $(CFLAGS) -o  $@ mole.o



clean:
	rm -f $(EXECUTABLES1) $(OBJ) *~
	rm -f $(EXECUTABLES2) $(OBJ1) *~
	rm -f $(EXECUTABLES3) $(OBJ2) *~
