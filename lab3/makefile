# EXECUTABLES = catcher
# SRC = catcher.c
# OBJ = catcher.o
# CC = gcc
# CFLAGS = -g -Wall -Wextra
#
# all: $(EXECUTABLES)
# $(EXECUTABLES):
# 	$(CC) $(CFLAGS) -c $(SRC) $(CFLAGS)
# 	$(CC) $(CFLAGS) -o $(EXECUTABLES) $(OBJ)
#
# clean:
# 	rm -f $(EXECUTABLES) $(OBJ) *~
#
#



EXECUTABLES = catcher
OBJ = catcher.o
SRC = catcher.c
CC=gcc
CFLAGS=-g

all: catcher

catcher: catcher.c
	$(CC) $(CFLAGS) -c catcher.c
	$(CC) $(CFLAGS) -o $@ catcher.o

clean:
	rm -f $(EXECUTABLES1) $(OBJ) *~
