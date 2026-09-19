#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int i, j;
    int len;

    if (argc != 2)
    {
        printf("Usage: %s <word>\n", argv[0]);
        return 1;
    }

    len = strlen(argv[1]);
// printf("len:%d\n",len);
// printf("sizeof:%d\n",sizeof(argv[1]));
    /* Top row */
    for (i = 0; i < len; i++)
    {
        printf("%c ", argv[1][i]);
    }
    printf("\n");

    // /* Left and right sides */
    for (i = 1; i < len - 1; i++)
    {
        printf("%c", argv[1][i]);

        for (j = 0; j < (len * 2 - 3); j++)
        {
            printf("1");
        }

        printf("%c\n", argv[1][len - i - 1]);
    }

    /* Bottom row */
    for (i = len - 1; i >= 0; i--)
    {
        printf("%c ", argv[1][i]);
    }

    printf("\n");

    return 0;
}