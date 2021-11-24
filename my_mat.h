#ifndef _MY_MAT_H_
#define _MY_MAT_H_

#define N 10
#define TRUE 1
#define FALSE 0
#define DIS 0
#define Z 0
#define INIT 1
#define MAX_NUM 2147483648
#define MIN_NUM -2147483648
#define ERR -1

int init_mat(int *mat, int *path_mat);
// FUNCTION A: Initialize and generate a matrix from input
int func_A(int *mat, int *path_mat);

// FUNCTION B: Prints "True" if there's a path from i to j, else- prints "False"
int bool_B(int *path_mat);
int func_B(int *mat, int *path_mat);

// FUNCTION C: Prints the shortest path from i to j
int prev_C(int *path_mat);
int func_C(int *mat, int *path_mat);

#endif