#include <stdio.h>
#include "my_mat_OG.h"

int main()
{
    int mat[N][N], path_mat[N][N];
    init_mat(&mat[0][0], &path_mat[0][0]);
    char select= 'E';
    int firstA = Z;
    int firstB = Z;
    int firstC = Z;
    while (select != 'D')
    {
        printf("Enter A, B, C or D:");
        scanf("%c", &select);
        // char select = sel;
        if (select== 'A')
        {
            firstA = INIT;
            firstB = INIT;
            firstC = INIT;
            // Function A
            func_A(&mat[0][0], &path_mat[0][0]);
        }
        // Function B
        else if (select == 'B')
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
            select = 'E';
        }
        // Function C
        else if (select == 'C')
        {
            if (firstA == Z)
            {
                printf("Matrix not initialized yet! please type A!");
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
            select = 'E';
        }
        else
        {
            select = 'E';
            break;
        }
    }
    printf("Bye-Bye!\n");
    return 0;
}