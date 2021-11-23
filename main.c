#include <stdio.h>
#include "my_mat.h"

#define N 10
#define NXN 100
#define TRUE 1
#define FALSE 0
#define DIS 0
#define Z 0
#define INIT 1
#define MAX_NUM 2147483648
#define MIN_NUM -2147483648
#define ERR -1

int main()
{
    int mat[N][N], path_mat[N][N];
    int(*mat_ptr)[N];
    int(*path_mat_ptr)[N];
    mat_ptr = mat;
    path_mat_ptr = path_mat;
    init_mat(mat_ptr, path_mat_ptr);
    char select= 'E';
    int firstA = Z;
    int firstB = Z;
    int firstC = Z;
    while (select != 'D')
    {
        printf("Enter A, B, C or D:\n");
        scanf("%c", &select);
        // char select = sel;
        if (select== 'A')
        {
            firstA = INIT;
            firstB = INIT;
            firstC = INIT;
            // Function A
            func_A(mat_ptr, path_mat_ptr);
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
                bool_B(path_mat_ptr);
            }
            else
            {
                ++firstB;
                func_B(mat_ptr, path_mat_ptr);
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
                return prev_C(path_mat_ptr);
            }
            else
            {
                ++firstC;
                func_C(mat_ptr, path_mat_ptr);
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