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

/*
 * Pseudocode for the algorithm, from https://en.wikipedia.org/wiki/Heapsort
 *
 * procedure heapsort(a, count) is
    input: an unordered array a of length count

    (Build the heap in array a so that largest value is at the root)
    heapify(a, count)

    (The following loop maintains the invariants that a[0:end] is a heap and every element
     beyond end is greater than everything before it (so a[end:count] is in sorted order))
    end ← count - 1
    while end > 0 do
        (a[0] is the root and largest value. The swap moves it in front of the sorted elements.)
        swap(a[end], a[0])
        (the heap size is reduced by one)
        end ← end - 1
        (the swap ruined the heap property, so restore it)
        siftDown(a, 0, end)
 *
 * USES TWO SUBROUTINES; heapify(a, count) and siftDown(a, start, end):
 *
 * Heapify:
 *
 * (Put elements of 'a' in heap order, in-place)
procedure heapify(a, count) is
    (start is assigned the index in 'a' of the last parent node)
    (the last element in a 0-based array is at index count-1; find the parent of that element)
    start ← iParent(count-1)

    while start ≥ 0 do
        (sift down the node at index 'start' to the proper place such that all nodes below
         the start index are in heap order)
        siftDown(a, start, count - 1)
        (go to the next parent node)
        start ← start - 1
    (after sifting down the root all nodes/elements are in heap order)
 *
 *
 * siftDown:
 *
 * (Repair the heap whose root element is at index 'start', assuming the heaps rooted at its children are valid)
procedure siftDown(a, start, end) is
    root ← start

    while iLeftChild(root) ≤ end do    (While the root has at least one child)
        child ← iLeftChild(root)   (Left child of root)
        swap ← root                (Keeps track of child to swap with)

        if a[swap] < a[child]
            swap ← child
        (If there is a right child and that child is greater)
        if child+1 ≤ end and a[swap] < a[child+1]
            swap ← child + 1
        if swap = root
            (The root holds the largest element. Since we assume the heaps rooted at the
             children are valid, this means that we are done.)
            return
        else
            swap(a[root], a[swap])
            root ← swap            (repeat to continue sifting down the child now)
 *
 */

void HeapSort(vector<int> & v) {
    //TODO: Implement
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


