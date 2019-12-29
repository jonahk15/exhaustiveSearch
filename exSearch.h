#ifndef EXSEARCH_H
#define EXSEARCH_H
#include <array>
#include <string>
using namespace std;
// Arithmetic
void runArithmetic(int, array<int,5>);

// Bitwise
void getPerms(array<int,5>, int);
void genOperators(int, int, int, int, int, int);
void firstLevel(int, int, int, int, int, int, array<int,4>);
void secondLevel(string, int, int, int, int, int, array<int,4>);
void thirdLevel(string, int, int, int, int, array<int,4>);
void fourthLevel(string, int, int, int, array<int,4>);
#endif
