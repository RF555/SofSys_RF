#include <stdio.h>
#include "my_mat.h"

#define N 10
#define T 2
#define DIS 0
#define Z 0
#define MAX_NUM 2147483648
#define MIN_NUM -2147483648

int main()
{
    int mat[N][N];
    init_mat(mat);
    char select = 'E';
    int first = 0;
    while (select != 'D')
    {
        printf("Enter A, B, C or D:\n");
        scanf("%c", select);
        if (select == 'A')
        {
            /* code */
            func_A(mat);
            ++first;
        }
        else if (select == 'B')
        {
            /* code */
            if (first == 0)
            {
                /* code */
                printf("Matrix not initialized yet! please type A!");
            }
            else
            {
                func_B(mat);
            }
        }
        else if (select == 'C')
        {
            /* code */
        }
        else if (select == 'D')
        {
            break;
        }
    }
    printf("Bye-Bye!\n");
    return 0;
}