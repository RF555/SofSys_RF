#include <stdio.h>
#include "my_mat.h"

int main()
{
    int mat[N][N];
    int path_mat[N][N];
    int(*mat_ptr)[N];
    mat_ptr = mat;
    int(*path_mat_ptr)[N];
    path_mat_ptr = path_mat;
    init_mat(mat_ptr, path_mat_ptr);
    char select;
    scanf("%c", &select);
    char *sel_p = &select;
    while (select != 'D')
    {
        // printf("Enter A, B, C or D:\n");
        if (*sel_p == 'A')
        {
            // Function A
            init_mat(mat_ptr, path_mat_ptr);
            generate_mat_from_input(mat_ptr, path_mat_ptr);
            floydWarshall(path_mat_ptr);
            *sel_p = 'E';
        }
        // Function B
        else if (*sel_p == 'B')
        {
            func_B(path_mat_ptr);
            *sel_p = 'E';
        }
        // Function C
        else if (*sel_p == 'C')
        {
            func_C(mat_ptr, path_mat_ptr);
            *sel_p = 'E';
        }
        else if (*sel_p == 'D') // select == 'D'
        {
            // printf("Bye-Bye!\n");
            break;
        }
        scanf("%c", sel_p);
    }
    return 0;
}