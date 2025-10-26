#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct {
    int elem[MAX];
    int lastNdx;
}Heap, List;

// Write code for:

void initHeap(Heap *H); // set latndx to -1
void insert(Heap *H, int X); // insert elemenet X into given Heap H
int Deletemin(Heap *H); 
                        // Deletes the minimum element (element with the smallest priority number)
                        // smaller numbers = smaller priority number = higher priority
                        // from the heap and returns it to the calling function.
                        // After deletion, the heap is restructured to maintain the min-heap property.
void HeapSort(Heap *H); // Given unsorted list, Sort descending order using heapsort technique; big -> small

int main(){
    Heap ivan;

    
    return 0;
}                       

void initHeap(Heap *H){
    H->lastNdx = -1;
}

// MIN HEAP !!!
// Goal: parent node must be smaller than or equal to its children
void insert(Heap *H, int X){
    if (H->lastNdx + 1 < MAX){ // check if not full // we're inserting so add 1
        int child = H->lastNdx++;  // assign child with lastndx
        H->elem[child] = X; // insert element X at lastNdx (child)
        // always insert at the bottom most part, left most position - keeps the heap complete;

        int parent = (child - 1) / 2;   // formula to get parent

        // heapify up or percolate up
        while (child > 0 && H->elem[child] < H->elem[parent]){ // compare new element from its parent
                                                               // if new elem is smaller than parent, swap them
                                                               // repeat until: 1. parent is smaller or equal or 2. reach root (index 0)
            int temp = H->elem[parent]; // swap process
            H->elem[parent] = H->elem[child]; // swap process
            H->elem[child] = temp; // swap process
            child = parent; // the child's index becomes where its parent used to be
                            // continue to compare it with its new parent
                            // insert bottom, swap up toward top, child = parent continue checking upwards;
                            //“Move the index upward one level after a swap, so the newly moved element keeps checking if it needs to go higher.”
            parent = (child - 1) / 2;
        } 
    } else {
        printf("Full Priority queue!\n");
    }
}

//MIN HEAP - Root at index 0;
int Deletemin(Heap *H){
    if (H->lastNdx < 0){                                // check if heap is empty
        printf("Heap Empty!\n");                        // print message if empty
        return -1;                                      // return -1 as error code
    }

    int minValue = H->elem[0];                          // Step 1: store minimum value (root)
    H->elem[0] = H->elem[H->lastNdx--];                 // Step 2: move last element to root and reduce heap size

    int parent = 0;                                     // Step 3: start from the root
    int left = 2 * parent + 1;                          // compute left child index

    // Step 4: continue while there is at least one child
    while (left <= H->lastNdx){
        int right = 2 * parent + 2;                     // compute right child index
        int smallest = left;                            // assume left child is smaller first

        // Step 5: check if right child exists and is smaller than left
        if (right <= H->lastNdx && H->elem[right] < H->elem[left]){
            smallest = right;                           // update smallest to right child
        }

        // Step 6: if parent is greater than smaller child, swap them
        if (H->elem[parent] > H->elem[smallest]){
            int temp = H->elem[parent];                 // swap process
            H->elem[parent] = H->elem[smallest];
            H->elem[smallest] = temp;

            parent = smallest;                          // move parent down to swapped position
            left = 2 * parent + 1;                      // recompute left child for next iteration
        } else {
            break;                                      // Step 7: stop when heap property is satisfied
        }
    }

    return minValue;                                    // Step 8: return deleted minimum value
}

void HeapSort(Heap *H){
    if (H->lastNdx < 0){                                // check if heap is empty
        printf("Heap is empty, nothing to sort!\n");    
        return;
    }

    int n = H->lastNdx + 1;                             // get the number of elements in the heap
    int sorted[MAX];                                    // temporary array to store sorted values

    // Step 1: repeatedly delete the minimum element from the heap
    // Deletemin() returns smallest each time (ascending order)
    for (int i = 0; i < n; i++){                        
        sorted[i] = Deletemin(H);                       // extract smallest and store in sorted[]
    }

    // Step 2: copy the values from sorted[] back to heap in reverse order
    // This makes the array sorted in descending order (big -> small)
    for (int i = 0; i < n; i++){
        H->elem[i] = sorted[n - 1 - i];                 // reverse the order
    }

    H->lastNdx = n - 1;                                 // restore lastNdx to its original value
}

void displayHeap(Heap H){
    if (H.lastNdx < 0){                               // check if heap is empty
        printf("Heap is empty!\n");
        return;
    }

    printf("Heap elements: ");
    for (int i = 0; i <= H.lastNdx; i++){             // loop from 0 up to last index
        printf("%d ", H.elem[i]);                     // print each element
    }
    printf("\n");                                     // new line for neat output
}
