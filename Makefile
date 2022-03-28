#pragma once

CC = g++
FLAGS = -Wall -pedantic-errors

main: main.o BinaryTree.o
	$(CC) $(FLAGS) -o main main.o BinaryTree.o

main.o: main.cpp BinaryTree.h
	$(CC) $(FLAGS) -c main.cpp

BinaryTree.o: BinaryTree.cpp BinaryTree.h
	$(CC) $(FLAGS) -c BinaryTree.cpp

run: compile
	./main

clean:
	rm -f *.o *.gch main