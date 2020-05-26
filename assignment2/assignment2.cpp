// Johnathan Torres Jan 26, 2020

#include <iostream>
using namespace std;

/*
    In the main function, create variables of at least 3 data types.

    Create at least 2 functions. Each function should take 3 parameters.
    The first is an iterator/counter, the 2nd is a starting value,
    the 3rd is an increment value:

    1 function should use a while loop.  The loop should add the
    incrementer to the starting value iterator times.  Return the result.

    1 function should do the same using a for loop and output the
    new value each iteration through the loop.  Return the final result.

    1 of those functions should have default parameter values such that
    it could be called with only one parameter.

    In your main function use a(n) if/then/else statement(s) to output
    whether the results of the first function call were greater than,
    less than or equal to the result of the 2nd function
*/



float whileLoop(int iterator, double startVal, float incVal)
{
    /* this function should use a while loop. the loop should add
       the incrementer to the starting vlaue iterator times return the result.
    */

	int count = 0;
	while (count < iterator) {
		startVal += incVal;
		count++;
	}
	return startVal;
}

float forLoop(double startVal, int iterator = 5, float incVal = 5.0)
{
    /*
	1 function should do the same using a for loop and output
	the new value each iteration through the loop. Return the final result.

        1 of those functions should have default parameter values such that
        it could be called with only one parameter.
    */

	for (int count = 0; count < iterator; ++count) {
	    startVal += incVal;
	    if (count << iterator)
		cout << startVal << ", ";
	    cout << startVal;
	}
	cout << "\n";
	return startVal;
}

int main () {

    int iterator = 5;
    float numTo_add = 5.0;
    double pi = 3.1416;
    double whileReturn = whileLoop (iterator, pi , numTo_add);
    double aLoop = forLoop(pi);
	
    if (whileReturn > aLoop) {
	cout << whileReturn << "\n";
        cout << "First function is bigger !\n";
    }
    else if (whileReturn < aLoop) {
	cout << whileReturn << "\n";
        cout << "Second function is bigger !\n";
    } 
    else{
	cout << "While loop is equal to: " <<  whileReturn << "\n";
	cout << "Both function values are equivalent !\n";
    }
    return 0;
}
