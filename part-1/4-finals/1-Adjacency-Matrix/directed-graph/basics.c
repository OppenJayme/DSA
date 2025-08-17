#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef int Matrix[MAX][MAX];

void initMatrix(Matrix M){
    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++){
            M[i][j] = 0;
        }
    }
}

void addEdge(Matrix M, int u, int v){
    // first dimension is row, 2nd is column
    // add 1 if edge (e.g A->b)
    M[u][v] = 1; 
}

void removeEdge(Matrix M, int u, int v){
    // first dimension is row, 2nd is column
    // add 1 if edge (e.g A->b)
    M[u][v] = 0; 
}

void printMatrix(Matrix M, int n){
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++)
        printf("%d ", M[i][j]);
      printf("\n");
    }
  }
  

int main(){
    Matrix AdjM;
    int numOfVertices, numEdges
    

    initMatrix(AdjM);

    

}
