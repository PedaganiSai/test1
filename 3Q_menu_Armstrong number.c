#include <stdio.h>

int main()
{
    int choice;

    while(1)
    {
        printf("\n----- MENU -----\n");
        printf("1. Check Armstrong number\n");
        printf("2. Print range of Armstrong numbers\n");
        printf("3. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            {
                int n, temp, digit, sum = 0;

                printf("Enter number: ");
                scanf("%d", &n);

                temp = n;

                while(temp != 0)
                {
                    digit = temp % 10;
                    sum = sum + digit * digit * digit;
                    temp = temp / 10;
                }

                if(sum == n)
                    printf("%d is an Armstrong number\n", n);
                else
                    printf("%d is not an Armstrong number\n", n);

                break;
            }

            case 2:
            {
                int start, end;

                printf("Enter starting number: ");
                scanf("%d", &start);

                printf("Enter ending number: ");
                scanf("%d", &end);

                printf("Armstrong numbers:\n");

                for(int n = start; n <= end; n++)
                {
                    int temp = n;
                    int sum = 0;

                    while(temp != 0)
                    {
                        int digit = temp % 10;
                        sum = sum + digit * digit * digit;
                        temp = temp / 10;
                    }

                    if(sum == n)
                        printf("%d ", n);
                }

                printf("\n");
                break;
            }

            case 3:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}