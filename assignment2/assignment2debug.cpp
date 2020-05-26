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
template <class T, class U, class V>
U whileFunct(T iterator, U startVal, V incVal) {
    /* this function should use a while loop. the loop should add
       the incrementer to the starting vlaue iterator times return the result.
    */
    int counter = 1; // our counter should start at 1 since its our first time
		// entering the while loop !
    while (counter <= iterator) {
	startVal += incVal;
	counter++;
    }
    return startVal;
}

T forFunction(T startVal, int iterator = 5,float incVal = 5.0) {
    /* 1 function should do the same using a for loop and output
       the new value each iteration through the loop. Return the final result.

        1 of those functions should have default parameter values such that
        it could be called with only one parameter.
    */
    for (int counter = 1; counter <= iterator; counter++) {
	startVal += incVal;
	if (counter < iterator)
	    cout << startVal << ", ";
	cout << startVal;
    }
    cout << "\n";
    return startVal;
}

int main () {
    int iterator = 5;
    float deci = 5.0;
    double pi = 3.1416;

    if (whileFunct (iterator, pi, deci) > forFunction(pi)) {
        //cout << whileFunct(iterator,pi,deci) << "\n";
	cout << "First function bigger\n";
    }
    else if (whileFunct (iterator, pi, deci) < forFunction(pi))
    {
	cout << "Second function bigger\n";
    }
    else {
	cout << "both function values are the same !\n";
    }
/* 
	In your main function use a(n) if/then/else statement(s) to output
    whether the results of the first function call were greater than,
     less than or equal to the result of the 2nd function.
    
*/
    return 0;
}
