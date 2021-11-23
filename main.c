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
    init_mat(mat, path_mat);
    char select = 'E';
    int firstA = Z;
    int firstB = Z;
    int firstC = Z;
    while (select != 'D')
    {
        printf("Enter A, B, C or D:\n");
        scanf("%c", select);
        if (select == 'A')
        {
            // Function A
            func_A(mat, path_mat);
            firstA = INIT;
            firstB = INIT;
            firstC = INIT;
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
                bool_B(path_mat);
            }
            else
            {
                func_B(mat, path_mat);
                ++firstB;
            }
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
                return prev_C(path_mat);
            }
            else
            {
                ++firstC;
                func_C(mat, path_mat);
            }
        }
        else if (select == 'D')
        {
            break;
        }
    }
    printf("Bye-Bye!\n");
    return 0;
}