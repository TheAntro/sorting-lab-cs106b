/*
 * Author: Valtteri Ranta, github: waldeog
 *
 * This project implements the CS106B assignment 5b: a general sorting algorithm other than selection,
 * insertion, merge, or quicksort
 */

#include <iostream>
#include <ctime>

#include "console.h"
#include "simpio.h"
#include "vector.h"
#include "random.h"

using namespace std;

const int sortSize = 10000;

/*
template <typename Type>
void Sort(Vector<Type> &v, int (cmpFn)(Type, Type) = OperatorCmp) {

}
*/

// Generates a vector full of random integers between 1 and 10000
Vector<int> intVecGenerator(int length) {
    Vector<int> vec;
    for (int i = 0; i < length; i++) {
        int randomInt = randomInteger(1, 10000);
        vec.push_back(randomInt);
    }
    return vec;
}

int main() {
    Vector<int> vecToSort = intVecGenerator(sortSize);

    cout << "Vector size: " << vecToSort.size() << endl;

    /*
    // timing purposes: program start time in seconds
    double start = double(clock()) / CLOCKS_PER_SEC;


    // timing purposes: program finish time in seconds
    double finish = double(clock()) / CLOCKS_PER_SEC;


    double elapsed = finish - start;
    cout << "Time elapsed during program: " << elapsed << " seconds" << endl;
    */
    return 0;
}


