#include <stdio.h>
int main()
{
    int rows,i,j;

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    for (j = 1; j <= rows; j++)
    {
        for (i = 1; i <= rows - j; i++)
            printf(" ");

        for (i = 1; i  <= 2 * j - 1; i++)
            printf("*");

        printf("\n");
    }

    for (j = 1; j <= rows - 1; j++)
    {
        for (i = 1; i <= j; i++)
            printf(" ");

        for (i = 1; i <= 2 * (rows - j) - 1; i++)
            printf("*");

        printf("\n");
    }

    return 0;
}