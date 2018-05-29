/*
 * Author: Valtteri Ranta, github: waldeog
 *
 * This project implements the CS106B assignment 5b: a general sorting algorithm other than selection,
 * insertion, merge, or quicksort
 *
 * The sorting algorithm will be heapsort, the third "efficient" sorting algorithm according to Wikipedia
 */

#include <iostream>
#include <ctime>

#include "console.h"
#include "simpio.h"
#include "vector.h"
#include "random.h"

using namespace std;

const int sortSize = 10000;

/* Code from the assignment to turn the sorting function to a general version
template <typename Type>
void Sort(Vector<Type> &v, int (cmpFn)(Type, Type) = OperatorCmp) {

}
*/

/*
 * heapsort consists of the following steps (source: https://en.wikipedia.org/wiki/Heapsort)
 *
 * 1) Call the buildMaxHeap() function on the list also referred to as heapify()
 *
 * 2) Swap the first element of the list with the final element. Decrease the
 * considered range of the list by one.
 *
 * 3) Call the siftDown() function on the list to sift the new element to its
 * appropriate index in the heap
 *
 * 4) Go to step 2 unless the considered range of the list is one element
 */

//Does not work

void swap(Vector<int> & vec, int i, int j) {
    int temp = vec[i];
    vec[i] = vec[j];
    vec[j] = temp;
}

void BuildMaxHeap(Vector<int> & vec, int n, int i) {
    int max = i; //largest initialized as root
    int left = 2*i + 1; //Left child position can be calculated from root with 2*i+1
    int right = 2*i + 2; //Right child position can be calculated from root with 2*i+2

    //If left child is larger than root
    if (left < n && vec[left] > vec[max]) {
        max = left;
    }

    //If right is larger than the largest so far
    if (right < n && vec[right] > vec[max]) {
        max = right;
    }

    //If max is not root
    if (max != i) {
        swap(vec, i, max);

        //Recursively heapify the affected sub-tree down
        BuildMaxHeap(vec, n, max);
    }
}

void HeapSort(Vector<int> & v) {
    //Build the heap (rearrange the vector so that at index i, left child = 2*i+1, right child = 2*i+2
    int n = v.size();
    for (int i = n/2-1; i >= 0; i--) {
        BuildMaxHeap(v, n, i);
    }

    //One by one extract an element from heap
    for (int i=n-1; i >= 0; i--) {
        //Current root to the end
        swap(v, 0, i);

        //Heapify the reduced heap
        BuildMaxHeap(v, n, 0);
    }
}


// Generates a vector full of random integers between 1 and 10000
Vector<int> intVecGenerator(int length) {
    Vector<int> vec;
    for (int i = 0; i < length; i++) {
        int randomInt = randomInteger(1, 10000);
        vec.push_back(randomInt);
    }
    return vec;
}

void printVec(Vector<int> & v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
}

int main() {
    Vector<int> vecToSort = intVecGenerator(sortSize);

    cout << "Vector size: " << vecToSort.size() << endl;

    HeapSort(vecToSort);
    printVec(vecToSort);

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


