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

// FUNCTION A: Initialize and generate a matrix from input
int init_mat(int (*mat)[N], int (*path_mat)[N]);
int generate_mat_from_input(int (*mat)[N], int (*path_mat)[N]);
int floydWarshall(int (*path_mat)[N]);

// FUNCTION B: Prints "True" if there's a path from i to j, else- prints "False"
int bool_B(int (*path_mat)[N]);
int bool_Z_is_false(int val);
int func_B(int (*path_mat)[N]);

// FUNCTION C: Prints the shortest path from i to j
int func_C(int (*mat)[N], int (*path_mat)[N]);

#endif