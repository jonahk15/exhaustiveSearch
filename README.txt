# Exhaustive Search for Arithmetic and Bitwise Expressions (written in C++)

Jonah Kim

## Instructions

This program exhaustively searches all possible permutations of expressions (either bitwise or arithmetic), and prints out
only the expressions that evaluate to a target value chosen by the user.

A Linux/Unix environment was used to write and test this code, and a Makefile is provided to compile, run, and clean the
program.

Flags are used in the command line to run this program. Order of flags do not matter, and their significance is provided if
the user wants to adjust the Makefile for different test cases.

"-a" will signal the program to run an arithmetic search of expressions. Operators are {+,-,*,/,%}.
"-b" will signal the program to run a bitwise search of expressions. Operators are {<<,>>,&,|,^}.
**Each run of a program must contain either "-a" OR "-b" but may not contain both.
"-e" followed by a single integer. This integer is the target value of interest that the expression should equal to.
"-v" followed by 5 unique integers that are greater than 0. These are the numbers that will be used in coalition with the operators to make each expression.
