#include <iostream>
#include <string>
#include <array>
#include "exSearch.h"
using namespace std;

int main(int argc, char * argv[]){
  // Initializing values accepted from the command line
  bool arith = false;
  int target = 0;
  array<int, 5> validInts;
  for (int i = 0; i < argc; i++){
    string flag = argv[i];
    if (flag == "-a"){
      arith = true;
    }
    if (flag == "-b"){
      arith = false;
    }
    if (flag == "-e"){
      target = stoi(argv[i+1]);
    }
    if (flag == "-v"){
      for (int j = 0; j < 5; j++){
	validInts[j] = stoi(argv[i + (j + 1)]);
      }
    }
  }
  if (arith){
    runArithmetic(target, validInts);
  }
  if (!arith){
    getPerms(validInts, target);
  }
  return 0;
}
