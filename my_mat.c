#include <stdio.h>
#include "my_mat.h"

#define N 10
#define NXN 100
// #define T 2
#define TRUE 1
#define FALSE 0
#define DIS 0
#define Z 0
#define MAX_NUM 2147483648
#define MIN_NUM -2147483648
#define EROR -1

// FUNCTION A:
int init_mat(int mat[N][N]);
int generate_mat_from_input(int mat[N][N]);
// FUNCTION B:
int path_exists(int i, int j, int mat[N][N]);

// FUNCTION C:
int floydWarshall(int mat[][N]);

// Initialize and generate a matrix from input
int func_A(int mat[N][N])
{
    init_mat(mat);
    generate_mat_from_input(mat);
}

// Prints "True" if there's a path from i to j, else- prints "False"
int func_B(int mat[N][N])
{
    int bool = MIN_NUM;
    printf("Enter i:\n");
    int i = MIN_NUM;
    scanf("%d\n", i);
    printf("Enter j:\n");
    int j = MIN_NUM;
    scanf("%d\n", j);
    bool = path_exists(i, j, mat);
    if (bool == TRUE)
    {
        printf("True");
    }
    else
    {
        printf("False");
    }
    return 0;
}

// Prints "True" if there's a path from i to j, else- prints "False"
int func_C(int mat[N][N])
{
    printf("Enter i:\n");
    int i = MIN_NUM;
    scanf("%d\n", i);
    printf("Enter j:\n");
    int j = MIN_NUM;
    scanf("%d\n", j);
    int path = floydWarshall(i, j, mat);
    if (path == 0)
    {
        /* code */
        printf("%d\n", EROR);
    }
    else
    {
        printf("%d", path);
    }

    return 0;
}

// remember pointers and memory usage of arrays

// because the graph is undirected: mat[i][j]=mat[j][i]
int init_mat(int mat[N][N])
{
    for (int i = Z; i < N; i++)
    {
        mat[i][i] = Z;
        for (int j = i + 1; j < N; j++)
        {
            mat[i][j] = DIS;
            mat[j][i] = DIS;
        }
    }
    return 0;
}

int generate_mat_from_input(int mat[N][N])
{
    for (int i = Z; i < N; i++)
    {
        for (int j = Z; j < N; j++)
        {
            int w;
            printf("Enter value of mat[%d][%d]", i, j);
            scanf("%d", w);
            mat[i][j] = w;
        }
    }
    return 0;
}

int path_exists(int i, int j, int mat[N][N])
{
    /*
    search if there is a path from i to j,
    if so- return TRUE(=1)
    else- return FALSE(=0)
    */
}

// int return_init_mat_0_0(int mat[N][N])
// {
//     int *p = &mat[Z][Z];
//     return p;
// }

int floydWarshall(int mat[][N])
{
    int min_dist[N][N]; //initialize min_dist as a copy of mat
    for (int i = Z; i < N; ++i)
    {
        for (int j = i; j < N; ++j)
        {
            min_dist[i][j] = mat[i][j];
            min_dist[j][i] = mat[j][i];
        }
    }
    /*
    Continue:
    create a matrix 10X10 of current shortest PATH (NOT edge) from i to j
    
    */
    return 0;
}