#include <stdio.h>
#include <stdlib.h>
#define MAX 5
#define INF 999999

typedef int AdjMatrix[MAX][MAX];

void initGraph(AdjMatrix A);
void addEdges(AdjMatrix A, int V, int U, int weight);
void printMatrix(AdjMatrix A);


// MAIN
int main(){
    AdjMatrix Matrix;

    initGraph(Matrix);
    addEdges(Matrix, 0, 1, 20); // A - B
    addEdges(Matrix, 1, 2, 5); // B - C
    addEdges(Matrix, 1, 4, 30); // B - E
    addEdges(Matrix, 2, 3, 10); // C - D
    addEdges(Matrix, 3, 4, 30); // D - E

    printMatrix(Matrix);


    return 0;
}

// we PUT infinity, as its better
void initGraph(AdjMatrix A){
    for (int i = 0; i < MAX; ++i){
        for (int j = 0; j < MAX; ++j){
            A[i][j] = INF;
        }
    }
}

// Adds connection to vertices
// vertices are proportional in the MATRIX when undirected
void addEdges(AdjMatrix A, int V, int U, int weight){
    A[V][U] = weight;
    A[U][V] = weight;
}

void printMatrix(AdjMatrix A){
    for (int i = 0; i < MAX; ++i){
        printf("%5d", i);
    }
    printf("\n");
    
    for (int i = 0; i < MAX; ++i) {
        printf("%2d |", i);  // Row label (i) with separator
        for (int j = 0; j < MAX; ++j) {
            // Print "INF" if the value is INFINITY, else print the number
            if (A[i][j] == INF) {
                printf("%5s", "INF");
            } else {
                printf("%5d", A[i][j]);  // Print matrix elements
            }
        }
        printf("\n");
    }
}

