#include <stdio.h>
// #include "NumClass.h"

#define N 10
#define T 2
#define DIS 0
#define Z 0
#define MAX_NUM 2147483648
#define MIN_NUM -2147483648

// remember pointers and memory usage of arrays

// because the graph is undirected: mat[i][j]=mat[j][i]
void init_mat(int mat[N][N]){
    for(int i=Z;i<N;i++){
        mat[i][i]=Z;
        for(int j=i+1; j<N;j++){
            mat[i][j]=DIS;
            mat[j][i]=DIS;            
        }
    }
}

int return_init_mat_0_0(int mat[N][N]){
    int p=&mat[Z][Z];
    return p;
}

int main(){
    int mat[N][N];
    init_mat(mat);

    return 0;
}