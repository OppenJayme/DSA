#include <stdio.h>
#include <stdlib.h>

#define MAX   5
#define INF   99999

typedef int Matrix[MAX][MAX];

// 1) Initialize the matrix to INF (meaning “no edge”)
void initMatrix(Matrix M){
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            M[i][j] = INF;
        }
    }
}

// 2) Add a single directed edge u → v with given weight
void addEdge(Matrix M, int u, int v, int weight){
    M[u][v] = weight;
}

// 3) Print only the [0..n-1] submatrix
void printMatrix(const Matrix M, int n){
    // column headers
    printf("    ");
    for(int j = 0; j < n; j++)
        printf("%5d", j);
    putchar('\n');

    for(int i = 0; i < n; i++){
        printf("%2d |", i);
        for(int j = 0; j < n; j++){
            if(M[i][j] == INF) 
                printf("%5s", "INF");
            else
                printf("%5d", M[i][j]);
        }
        putchar('\n');
    }
}

int main(void){
    Matrix G;

    // 1. Build graph in code
    initMatrix(G);

    // 2. Manually add your edges (directed, weighted):
    addEdge(G, 0, 1, 20);   // A → B (weight 20)
    addEdge(G, 1, 2,  5);   // B → C (weight 5)
    addEdge(G, 1, 4, 30);   // B → E (weight 30)
    addEdge(G, 2, 3, 10);   // C → D (weight 10)
    addEdge(G, 3, 4, 30);   // D → E (weight 30)

    // 3. Print the adjacency matrix for the first 5 vertices
    printf("Directed, weighted adjacency matrix:\n");
    printMatrix(G, 5);

    return 0;
}
