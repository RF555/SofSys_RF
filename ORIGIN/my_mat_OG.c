#include <stdio.h>
#include "my_mat_OG.h"

/*

Reset all the metrics to -1 instead of zero 

When you get the metrics input every duration check whether the other state has already value if so mark the value of both as a minimum of the value of the new input in the previous one else just enter the same input 

When entering an input of a new metrics create a new metrics called path mat which represents the know the path of all the nodes firstly his path every every path is just a path between its nodes if there if they exist one in this be value if not they'll be zero. Edit every slot of IG after I received over a minimum of the previous original metrics then add a JNJ which are equal 

Initiate the path metrics at the same time as the original metrics all the values of it will be -1

*/

// FUNCTION A:
int init_mat(int (*mat_ptr)[N], int (*path_mat_ptr)[N]);
int generate_mat_from_input(int (*mat_ptr)[N], int (*path_mat_ptr)[N]);

// FUNCTION B:
int bool_Z_is_false(int val);
int bool_B(int (*path_mat_ptr)[N]);
int path_exists(int i, int j, int (*mat_ptr)[N], int (*path_mat_ptr)[N]);

// FUNCTION C:
int prev_C(int (*path_mat_ptr)[N]);

int floydWarshall(int i, int j, int (*mat_ptr)[N], int (*path_mat_ptr)[N]);
int scan_i();
int scan_j();

// Initialize and generate a matrix from input
int func_A(int (*mat_ptr)[N], int (*path_mat_ptr)[N])
{
    init_mat(mat_ptr, path_mat_ptr);
    generate_mat_from_input(mat_ptr, path_mat_ptr);
    return 0;
}

// Prints "True" if there's a path from i to j, else- prints "False"
int func_B(int (*mat_ptr)[N], int (*path_mat_ptr)[N])
{
    int path_mat_ij = MIN_NUM;
    int i = scan_i();
    int j = scan_j();
    path_mat_ij = path_exists(i, j, mat_ptr,path_mat_ptr);
    bool_Z_is_false(path_mat_ij);
    return 0;
}

// Prints "True" if there's a path from i to j, else- prints "False"
int func_C(int (*mat_ptr)[N], int (*path_mat_ptr)[N])
{
    int i = scan_i();
    int j = scan_j();
    int path = floydWarshall(i, j, mat_ptr,path_mat_ptr);
    if (path == 0)
    {
        /* code */
        printf("%d\n", ERR);
    }
    else
    {
        printf("%d\n", path);
    }

    return 0;
}

// remember pointers and memory usage of arrays

// because the graph is undirected: mat[i][j]=mat[j][i]
int init_mat(int (*mat_ptr)[N], int (*path_mat_ptr)[N])
{
    for (int i = Z; i < N; i++)
    {
        for (int j = i; j < N; j++)
        {
            (*(*(mat_ptr + i) + j)) = ERR;
            (*(*(mat_ptr + j) + i)) = ERR;
            (*(*(path_mat_ptr + i) + j)) = ERR;
            (*(*(path_mat_ptr + j) + i)) = ERR;
        }
    }
    return 0;
}

int min_func(int ij, int ji)
{
    if (ij < ji)
    {
        return ij;
    }
    else
    {
        return ji;
    }
}

int generate_mat_from_input(int (*mat_ptr)[N], int (*path_mat_ptr)[N])
{
    for (int i = Z; i < N; i++)
    {
        for (int j = Z; j < N; j++)
        {
            int w;
            printf("Enter value of mat[%d][%d]\n", i, j);
            scanf("%d", &w);
            if ((*(*(mat_ptr + i) + j)) == ERR)
            {
                (*(*(mat_ptr + i) + j)) = w;
            }
            else
            {
                int min = min_func(w, (*(*(mat_ptr + j) + i)));
                (*(*(mat_ptr + i) + j)) = min;
                (*(*(mat_ptr + j) + i)) = min;
                (*(*(path_mat_ptr + i) + j)) = min;
                (*(*(path_mat_ptr + j) + i)) = min;
            }
        }
    }
    return 0;
}

int bool_Z_is_false(int val)
{
    if (val < Z)
    {
        printf("ERROR!!!\n");
    }
    else if (val == Z)
    {
        printf("False\n");
    }
    else
    {
        printf("True\n");
    }
    return 0;
}

// if B OR C were alredy called, all we need is to check path_mat[i][j]
int bool_B(int (*path_mat_ptr)[N])
{
    int i = scan_i();
    int j = scan_j();
    bool_Z_is_false((*(*(path_mat_ptr + i) + j)));
    return 0;
}

// returns the value of the first path generated from i to j
int path_exists(int i, int j, int (*mat_ptr)[N], int (*path_mat_ptr)[N])
{
    int path_ij = MIN_NUM;
    /*
    search if there is a path from i to j,
    if so- return TRUE(=1)
    else- return FALSE(=0)
    */
    return path_ij;
}

// int return_init_mat_0_0(int mat[N][N])
// {
//     int *p = &mat[Z][Z];
//     return p;
// }

int prev_C(int (*path_mat_ptr)[N])
{
    int i = scan_i();
    int j = scan_j();
    printf("%d\n", (*(*(path_mat_ptr + i) + j)));
    return 0;
}

int floydWarshall(int i, int j, int (*mat_ptr)[N], int (*path_mat_ptr)[N])
{
    // int min_dist[N][N]; //initialize min_dist as a copy of mat
    // for (int i = Z; i < N; ++i)
    // {
    //     for (int j = i; j < N; ++j)
    //     {
    //         min_dist[i][j] = mat[i][j];
    //         min_dist[j][i] = mat[j][i];
    //     }
    // }

    /*
    Continue:
    create a matrix 10X10 of current shortest PATH (NOT edge) from i to j
    
    */
    return 0;
}

int scan_i()
{
    printf("Enter i:\n");
    int i = MIN_NUM;
    scanf("%d", &i);
    return i;
}

int scan_j()
{
    printf("Enter j:\n");
    int j = MIN_NUM;
    scanf("%d", &j);
    return j;
}