#ifndef _MY_MAT_H_
#define _MY_MAT_H_

#define N 10
#define NXN 100
// #define T 2
#define TRUE 1
#define FALSE 0
#define DIS 0
#define Z 0
#define MAX_NUM 2147483648
#define MIN_NUM -2147483648

/* function A:
    gets input 
*/
// FUNCTION A: Initialize and generate a matrix from input
int func_A(int mat[N][N]);

// FUNCTION B: Prints "True" if there's a path from i to j, else- prints "False"
int func_B(int mat[N][N]);

// FUNCTION C: Prints the shortest path from i to j
int func_C(int mat[N][N]);

#endif