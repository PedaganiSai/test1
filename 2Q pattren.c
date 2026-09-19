#include <stdio.h>

int main()
{
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    // Upper half
    for(int i = n; i >= 1; i--)
    {
        for(int j = 1; j <= i; j++)
        {
            printf("*");
        }

        if(i != n)
        {
            for(int j = 1; j <= 2 * (n - i); j++)
            {
                printf(" ");
            }

            for(int j = 1; j <= i; j++)
            {
                printf("*");
            }
        }

        printf("\n");
    }

    // Lower half
    for(int i = 2; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            printf("*");
        }

        for(int j = 1; j <= 2 * (n - i); j++)
        {
            printf(" ");
        }

        for(int j = 1; j <= i; j++)
        {
            printf("*");
        }

        printf("\n");
    }

    return 0;
}