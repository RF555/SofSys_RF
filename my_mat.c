#include <stdio.h>
#include "my_mat.h"

int bool_Z_is_false(int val);

int scan_i();
int scan_j();

// Prints "True" if there's a path from i to j, else- prints "False"
int func_B(int (*path_mat)[N])
{
    int path_mat_ij = MIN_NUM;
    int i = scan_i();
    int j = scan_j();
    path_mat_ij = *(*(path_mat + i) + j);
    bool_Z_is_false(path_mat_ij);
    return 0;
}

int func_C(int (*mat)[N], int (*path_mat)[N])
{
    int i = scan_i();
    int j = scan_j();
    int path = *(*(path_mat + i) + j);
    if (path <= Z)
    {
        printf("%d\n", ERR);
    }
    else
    {
        printf("%d\n", path);
    }

    return 0;
}

// remember pointers and memory usage of arrays

int init_mat(int (*mat)[N], int (*path_mat)[N])
{
    for (int i = Z; i < N; i++)
    {
        for (int j = i; j < N; j++)
        {
            *(*(mat + i) + j) = ERR;
            *(*(mat + j) + i) = ERR;
            *(*(path_mat + i) + j) = ERR;
            *(*(path_mat + j) + i) = ERR;
        }
    }
    return 0;
}

int min_func(int ij, int ji)
{
    if (ij < ji)
    {
        if (ji == Z)
        {
            return Z;
        }
        else
        {
            return ij;
        }
    }
    else
    {
        if (ij == Z)
        {
            return Z;
        }
        else
        {
            return ji;
        }
    }
}

int generate_mat_from_input(int (*mat)[N], int (*path_mat)[N])
{
    for (int i = Z; i < N; i++)
    {
        for (int j = Z; j < N; j++)
        {
            int w;
            // printf("Enter value of mat[%d][%d]\n", i, j);
            scanf("%d", &w);
            *(*(mat + i) + j) = w;
            *(*(mat + j) + i) = w;
            *(*(path_mat + i) + j) = w;
            *(*(path_mat + j) + i) = w;
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

int floydWarshall(int (*path_mat)[N])
{

    for (int k = Z; k < N; ++k)
    {
        for (int a = Z; a < N; ++a)
        {
            for (int b = Z; b < N; ++b)
            {
                if ((*(*(path_mat + a) + b)) == 0 && a != b)
                {
                    if ((*(*(path_mat + a) + k) != 0 && *(*(path_mat + k) + b) != 0))
                    {
                        *(*(path_mat + a) + b) = *(*(path_mat + a) + k) + *(*(path_mat + k) + b);
                    }
                    else
                    {
                        continue;
                    }
                }
                if (*(*(path_mat + a) + b) != 0)
                {
                    if ((*(*(path_mat + a) + k) != 0 && *(*(path_mat + k) + b) != 0))
                    {
                        *(*(path_mat + a) + b) = min_func(*(*(path_mat + a) + b), *(*(path_mat + a) + k) + *(*(path_mat + k) + b));
                    }
                }
            }
        }
    }
    return 0;
}

int scan_i()
{
    // printf("Enter i:\n");
    int i = MIN_NUM;
    scanf("%d", &i);
    return i;
}

int scan_j()
{
    // printf("Enter j:\n");
    int j = MIN_NUM;
    scanf("%d", &j);
    return j;
}