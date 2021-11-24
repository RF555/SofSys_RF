#include <stdio.h>
#include "my_mat.h"

int main()
{
    int mat[N][N], path_mat[N][N];
    init_mat(&mat[0][0], &path_mat[0][0]);
    char select = 'E';
    char *sel_p = &select;
    int firstA = Z;
    int firstB = Z;
    int firstC = Z;
    while (select != 'D')
    {
        // printf("Enter A, B, C or D:\n");
        scanf("%c", sel_p);
        if (*sel_p == 'A')
        {
            firstA = INIT;
            firstB = INIT;
            firstC = INIT;
            // Function A
            func_A(&mat[0][0], &path_mat[0][0]);
            *sel_p = 'E';
        }
        // Function B
        else if (*sel_p == 'B')
        {
            if (firstA == Z)
            {
                printf("Matrix not initialized yet! please type A!");
            }
            else if (firstB != Z || firstC != Z)
            {
                bool_B(&path_mat[0][0]);
            }
            else
            {
                ++firstB;
                func_B(&mat[0][0], &path_mat[0][0]);
            }
            *sel_p = 'E';
        }
        // Function C
        else if (*sel_p == 'C')
        {
            if (firstA == Z)
            {
                // printf("Matrix not initialized yet! please type A!");
            }
            else if (firstC != Z)
            {
                ++firstC;
                prev_C(&path_mat[0][0]);
            }
            else
            {
                ++firstC;
                func_C(&mat[0][0], &path_mat[0][0]);
            }
            *sel_p = 'E';
        }
        else if (*sel_p == 'D') // select == 'D'
        {
            // printf("Bye-Bye!\n");
            break;
        }
    }
    return 0;
}