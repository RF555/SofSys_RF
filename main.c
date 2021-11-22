#include <stdio.h>
// #include "NumClass.h"

#define N 10
#define T 2
#define DIS 2147483647;
#define Z 0;
#define MIN_NUM -2147483648;

// remember pointers and memory usage of arrays

void init_mat(int mat[N][N]){
    for(int i=0;i<N;i++){
        mat[i][i]=Z;
        for(int j=i+1; j<N;j++){
            mat[i][j]=DIS;
            mat[j][i]=DIS;            
        }
    }
}

int return_init_mat(mat[N][N]){
    int *p; // initiate pointer
    return
}

int main(){
    int mat[N][N];
    init_mat(mat);

    return 0;
}