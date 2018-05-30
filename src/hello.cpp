/*
 * Author: Valtteri Ranta, github: waldeog
 * DONE: Tested with ints, chars, and self-created structs (coordT)
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

struct coordT {
    double x, y;
};

//These are directly from CS106B slides
int coordCmp(coordT a, coordT b) {
    if (a.x < b.x) return -1;
    else if (a.x > b.x) return 1;
    else if (a.y < b.y) return -1;
    else if (a.y > b.y) return 1;
    else return 0;
}

void coordPrint(coordT a) {
    cout << "[" << a.x << "," << a.y << "]" << endl;
}

template <typename Type>
    int reverseCmp(Type a, Type b) {
        if (a == b) return 0;
        return (a < b ? 1 : -1);
    }

template <typename Type>
    int operatorCmp(Type a, Type b) {
        if (a == b) return 0;
        return (a < b ? -1 : 1);
    }

template <typename Type>
    void normalPrint(Type a) {
        cout << a << endl;
    }

template <typename Type>
    void Swap(Type & a, Type & b) {
        Type temp = a;
        a = b;
        b = temp;
    }

// Arrange the vector so that it fulfills max heap property, takes the comparison operator directly from
    // the call to heapsort
template <typename Type>
    void heapify(Vector<Type> & vec, int index, int length, int(cmp)(Type, Type) = operatorCmp) {
        //max heap property: parent node is larger than its parents
        int maxNode = index;
        int leftChild = index*2 + 1;
        int rightChild = index*2 + 2;

        if (leftChild < length && cmp(vec[leftChild], vec[maxNode]) > 0) {
            maxNode = leftChild;
        }

        if (rightChild < length && cmp(vec[rightChild], vec[maxNode]) > 0) {
            maxNode = rightChild;
        }

        //If changes needed to achieve max heap property, check to maintain max heap property after swap
        if (maxNode != index) {
            Swap(vec[index], vec[maxNode]);
            heapify(vec, maxNode, length, cmp);
        }
    }

//Sorts the Vector using heapsort algorithm, general so works for any datatypes.
    // When normal comparison operators cannot be used, a comparison function must be given
template <typename Type>
    void HeapSort(Vector<Type> & v, int (cmp)(Type, Type) = operatorCmp) {
    //Build a max heap:
        //First index to consider is floor((n-2)/2)
        int n = v.size();
        for(int i = (n-2)/2; i>=0; i--) {
            heapify(v, i, n, cmp);
        }

        //Then sort, by removing the max heap, moving it to sorted part of the vector
        //and re-heapifying the other part until the entire vector has been sorted
        for (int i = n-1; i>0; i--) {
            Swap(v[0], v[i]);
            //heapifies one shorter vector, excluding the sorted part
            heapify(v, 0, i, cmp);
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

Vector<char> charVecGenerator(int length) {
    Vector<char> v;
    for (int i = 0; i < length; i++) {
        char ch = getChar("Enter a char: ");
        v.push_back(ch);
    }
    return v;
}

template <typename Type>
    void printVec(Vector<Type> & v, void (prnt)(Type) = normalPrint) {
        for (int i = 0; i < v.size(); i++) {
            prnt(v[i]);
        }
    }

int main() {

    //Vector<int> vecToSort = intVecGenerator(sortSize);
    //Vector<char> vecToSort = charVecGenerator(sortSize);
    //Vector<coordT> vecToSort = coordVecGenerator(sortSize);
    Vector<coordT> vecToSort;
    for (int i = 0; i < sortSize; i++) {
        coordT coordinate;
        coordinate.x = randomInteger(-10, 10);
        coordinate.y = randomInteger(-10, 10);
        vecToSort.push_back(coordinate);
    }

    cout << "Vector size: " << vecToSort.size() << endl;

    //HeapSort(vecToSort);
    printVec(vecToSort, coordPrint);
    cout << endl;

    HeapSort(vecToSort, coordCmp);
    printVec(vecToSort, coordPrint);

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


