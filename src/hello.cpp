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

const int sortSize = 9;

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

void swapVec(Vector<int> & vec, int i, int j) {
    int temp = vec[i];
    vec[i] = vec[j];
    vec[j] = temp;
}

// Arrange the vector so that it fulfills max heap property
void heapify(Vector<int> & vec, int index, int length) {
    //max heap property: parent node is larger than its parents
    int maxNode = index;
    int leftChild = index*2 + 1;
    int rightChild = index*2 + 2;

    if (leftChild < length && vec[leftChild] > vec[maxNode]) {
        maxNode = leftChild;
    }

    if (rightChild < length && vec[rightChild] > vec[maxNode]) {
        maxNode = rightChild;
    }

    //If changes needed to achieve max heap property, check to maintain max heap property after swap
    if (maxNode != index) {
        swapVec(vec, index, maxNode);
        heapify(vec, maxNode, length);
    }
}

void HeapSort(Vector<int> & v) {
//Build a max heap:
    //First index to consider is floor((n-2)/2)
    int n = v.size();
    for(int i = (n-2)/2; i>=0; i--) {
        heapify(v, i, n);
    }

    //Then sort, by removing the max heap, moving it to sorted part of the vector
    //and re-heapifying the other part until the entire vector has been sorted
    for (int i = n-1; i>0; i--) {
        swapVec(v, 0, i);
        //heapifies one shorter vector, excluding the sorted part
        heapify(v, 0, i);
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

    //HeapSort(vecToSort);
    printVec(vecToSort);
    cout << endl;

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


