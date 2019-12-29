#include <iostream>
#include <string>
#include <array>
#include "exSearch.h"
using namespace std;
int counter = 0;
/*
If a single combination of validInputs with the operators equals target, expression is printed
along with the number of solutions that have been identified. Combinations are found by 9 nested for-loops.
*/
void runArithmetic(int target, array<int, 5> validInputs){
  int temp[5];
  int guess = 0;
  char operators[] = {'+', '-', '*', '/', '%'};
  char tempOp[4];

  // Finds all possible permutation of numbers
  for(int i = 0; i < 5; i++){
    temp[0] = validInputs[i];
    for(int j = 0; j < 5; j++){
      if((validInputs[j] == temp[0]) && (j != 4)){
	j++;
      } //if
      temp[1] = validInputs[j];
      for(int k = 0; k < 5; k++){
	if((validInputs[k] == temp[0]) && (k != 4)){
	  k++;
	}//if
	if((validInputs[k] == temp[1]) && (k != 4)){
	  k++;
	}//if
	temp[2] = validInputs[k];
	for(int l = 0; l < 5; l++){
	  if((validInputs[l] == temp[0]) && (l != 4)){
	    l++;
	  }//if
	  if((validInputs[l] == temp[1]) && (l != 4)){
	    l++;
	  }//if
	  if((validInputs[l] == temp[2]) && (l != 4)){
	    l++;
	  }//if
	  temp[3] = validInputs[l];
	  for(int m = 0; m < 5; m++){
	    if((validInputs[m] == temp[0]) && (m != 4)){
	      m++;
	    }//if
	    if((validInputs[m] == temp[1]) && (m != 4)){
	      m++;
	    }//if
	    if((validInputs[m] == temp[2]) && (m != 4)){
	      m++;
	    }//if
	    if((validInputs[m] == temp[3]) && (m != 4)){
	      m++;
	    }//if
	    temp[4] = validInputs[m];
	    // End permutation of numbers

	    // Finds all permutations of operators with all permutations of numbers
	    for(int n = 0; n < 5; n++){
	      tempOp[0] = operators[n];
	      tempOp[1] = operators[n];
	      tempOp[2] = operators[n];
	      tempOp[3] = operators[n];
	      for(int o = 0; o < 5; o++){
		tempOp[1] = operators[o];
		tempOp[2] = operators[o];
		tempOp[3] = operators[o];
		for(int p = 0; p < 5; p++){
		  tempOp[2] = operators[p];
		  tempOp[3] = operators[p];
		  for(int q = 0; q < 5; q++){
		    tempOp[3] = operators[q];
		    // End permutation for operators
		    
		    // Printing the output
		    guess = temp[0];
		    int s = 1;
		    for (int r = 0; r < 4; r++) {
		      if(tempOp[r] == '+') {
			guess += temp[s];
		      }//if
		      if(tempOp[r] == '-') {
			guess -= temp[s];
		      }//if
		      if(tempOp[r] == '*') {
			guess *= temp[s];
		      }//if
		      if(tempOp[r] == '/') {
			guess /= temp[s];
		      }//if
		      if(tempOp[r] == '%') {
			guess %= temp[s];
		      }//if
		      s++;
		    }//for
		    // Ensures no duplicates of a single number; comment out if-statement if solutions with duplicate numbers is desired 
		    if (guess == target && temp[0] != temp[1] && temp[0] != temp[2] && temp[0] != temp[3] &&
			temp[0] != temp[4] && temp[1] != temp[2] && temp[1] != temp[3] && temp[1] != temp[4]
			&& temp[2] != temp[3] && temp[2] != temp[4] && temp[3] != temp[4]) {
		      counter++;
		      cout << "((((" << temp[0] << tempOp[0] << temp[1] << ")" << tempOp[1] << temp[2] << ")" << tempOp[2] << temp[3] << ")" << tempOp[3] << temp[4] << ")" << endl;
		    }//if
		  }//for
		}//for
	      }//for
	    }//for
	  }//for
	}//for
      }//for
    }//for
  }//for
  cout << counter << " arithmetic expressions found that evaluate to " << target << endl;
}//function



/*
 Function used for the outer most expression. If value in hold is
 equivalent to the value in eval, a string representing the 
 full expression will be printed. The counter is also incremented
 to keep track of expressions that evaluate to the desired integer.
 */
void fourthLevel(string s, int hold, int e, int eval, array<int,4> operators){
    string build = s;

    if(operators[3]==1){
        hold = (hold << e);
        build += "<<" + to_string(e);
    }//if
    else if(operators[3] == 2){
        hold = (hold >> e);
        build += ">>" + to_string(e);
    }//else if
    else if(operators[3] == 3){
        hold = (hold & e);
        build += "&" + to_string(e);
    }//else if
    else if(operators[3] == 4){
        hold = (hold | e);
        build += "|" + to_string(e);
    }//else if
    else{
        hold = (hold ^ e);
        build += "^" + to_string(e);
    }//else

    if(hold == eval){//checking that the expression evaluates to the proper value
        cout << build << endl;//printing the string representing the expression
        counter++;//keeping track of valid expressions
    }//if
}//fourthLevel

/*
 Function used for the second to last expression. Performs different operations 
 depending on the value held in the 3rd spot of the operators parameter array.
 After completing the desired operation, a call is made to get the outermost
 operation.
 */
void thirdLevel(string s, int hold, int d, int e, int eval, array<int,4> operators){
    string build = s;

    if(operators[2]==1){
        hold = (hold << d);
        build += "<<" + to_string(d) + ")";
        fourthLevel(build, hold, e, eval, operators);
    }//if
    else if(operators[2] == 2){
        hold = (hold >> d);
        build += ">>" + to_string(d) + ")";
        fourthLevel(build, hold, e, eval, operators);
    }//else if
    else if(operators[2] == 3){
        hold = (hold & d);
        build += "&" + to_string(d) + ")";
        fourthLevel(build, hold, e, eval, operators);
    }//else if
    else if(operators[2] == 4){
        hold = (hold | d);
        build += "|" + to_string(d) + ")";
        fourthLevel(build, hold, e, eval, operators);
    }//else if
    else{
        hold = (hold ^ d);
        build += "^" + to_string(d) + ")";
        fourthLevel(build, hold, e, eval, operators);
    }//else

}//thirdLevel

/*
 Function used for the second expression. Performs different operations 
 depending on the value held in the 2nd spot of the operators parameter array.
 After completing the desired operation, a call is made to get the second to
 last operation.
 */
void secondLevel(string s, int hold, int c, int d, int e, int eval, array<int,4> operators){
    string build = s;

    if(operators[1]==1){
        hold = (hold << c);
        build += "<<" + to_string(c) + ")";
        thirdLevel(build, hold, d, e, eval, operators);
    }//if
    else if(operators[1] == 2){
        hold = (hold >> c);
        build += ">>" + to_string(c) + ")";
        thirdLevel(build, hold, d, e, eval, operators);
    }//else if
    else if(operators[1] == 3){
        hold = (hold & c);
        build += "&" + to_string(c) + ")";
        thirdLevel(build, hold, d, e, eval, operators);
    }//else if
    else if(operators[1] == 4){
        hold = (hold | c);
        build += "|" + to_string(c) + ")";
        thirdLevel(build, hold, d, e, eval, operators);
    }//else if
    else{
        hold = (hold ^ c);
        build += "^" + to_string(c) + ")";
        thirdLevel(build, hold, d, e, eval, operators);
    }//else

}//secondLevel

/*
 Function used for the innermost expression. Performs different operations 
 depending on the value held in the 1st spot of the operators parameter array.
 After completing the desired operation, a call is made to get the second 
 operation.
 */
void firstLevel(int a, int b, int c, int d, int e, int eval, array<int,4> operators){
    string build = "(((";//building a string as the program executes
    int hold = 0;//used to hold the value after each operation

    if(operators[0]==1){
        hold = (a << b);
        build = build + to_string(a) + "<<" + to_string(b) + ")";
        secondLevel(build, hold, c, d, e, eval, operators);
    }//if
    else if(operators[0] == 2){
        hold = (a >> b);
        build = build + to_string(a) + ">>" + to_string(b) + ")";
        secondLevel(build, hold, c, d, e, eval, operators);
    }//else if
    else if(operators[0] == 3){
        hold = (a & b);
        build = build + to_string(a) + "&" + to_string(b) + ")";
        secondLevel(build, hold, c, d, e, eval, operators);
    }//else if
    else if(operators[0] == 4){
        hold = (a | b);
        build = build + to_string(a) + "|" + to_string(b) + ")";
        secondLevel(build, hold, c, d, e, eval, operators);
    }//else if
    else{
        hold = (a ^ b);
        build = build + to_string(a) + "^" + to_string(b) + ")";
        secondLevel(build, hold, c, d, e, eval, operators);
    }//else

}//firstLevel

/*
 Generates an array containing 4 integer values, used later
 to control what operator is used. Every array created
 represents a combination of operators.
 */
void genOperators(int a, int b, int c, int d, int e, int eval){
    array<int,4> operators;
    for(int o1=0;o1<5;o1++){//looping to get all possible combinations
        for(int o2=0;o2<5;o2++){//looping to get all possible combinations
            for(int o3=0;o3<5;o3++){//looping to get all possible combinations
                for(int o4=0;o4<5;o4++){//looping to get all possible combinations
                    operators[0]=o1+1;
                    operators[1]=o2+1;
                    operators[2]=o3+1;
                    operators[3]=o4+1;
                    firstLevel(a, b, c, d, e, eval, operators);
                }//for l
            }//for k
        }//for j
    }//for i
}//genOperators

/*
 This function is used to get a permutation of the values from the
 values parameter array. Calls the genOperators() function when
 a valid permutation exists.
 */
void getPerms(array<int,5> values, int eval){

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(i!=j){//making sure the values hasn't been used yet
                for(int k=0;k<5;k++){
                    if(k!=i && k!=j){//making sure the value hasn't been used yet
                        for(int l=0;l<5;l++){
                            if(l!=i  && l!=j && l!=k){//making sure the value hasn't been used yet
                                for(int m=0;m<5;m++){
                                    if(m!=i && m!=j && m!=k && m!=l){//making sure the value hasn't been used yet
                                        genOperators(values[i], values[j], values[k], values[l], values[m], eval);
                                    }//if
                                }//for
                            }//if
                        }//for
                    }//if
                }//for
            }//if
        }//for
    }//for
    cout << counter << " bitwise expressions found that evaluate to " << eval << endl ;
}//getCombos
