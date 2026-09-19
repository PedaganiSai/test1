#include <stdio.h>
#include <string.h>

int main()
{
    int choice;

    while(1)
    {
        printf("\n----- STRING MENU -----\n");
        printf("1. Reverse a string\n");
        printf("2. Check palindrome\n");
        printf("3. Compare two strings\n");
        printf("4. String copy\n");
        printf("5. String tokenizer\n");
        printf("6. String concatenate\n");
        printf("7. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            {
                char str[100];

                printf("Enter string: ");
                scanf("%s", str);

                printf("Reverse: ");

                for(int i = strlen(str) - 1; i >= 0; i--)
                {
                    printf("%c", str[i]);
                }

                printf("\n");
                break;
            }

            case 2:
            {
                char str[100];
                int flag = 1;

                printf("Enter string: ");
                scanf("%s", str);

                int len = strlen(str);

                for(int i = 0; i < len / 2; i++)
                {
                    if(str[i] != str[len - 1 - i])
                    {
                        flag = 0;
                        break;
                    }
                }

                if(flag)
                    printf("%s is a palindrome\n", str);
                else
                    printf("%s is not a palindrome\n", str);

                break;
            }

            case 3:
            {
                char str1[100], str2[100];

                printf("Enter first string: ");
                scanf("%s", str1);

                printf("Enter second string: ");
                scanf("%s", str2);

                if(strcmp(str1, str2) == 0)
                    printf("Both strings are equal\n");
                else
                    printf("Strings are not equal\n");

                break;
            }

            case 4:
            {
                char str1[100], str2[100];

                printf("Enter source string: ");
                scanf("%s", str1);

                strcpy(str2, str1);

                printf("Copied string: %s\n", str2);

                break;
            }

            case 5:
            {
                char str[100];

                printf("Enter string: ");
                scanf(" %[^\n]", str);

                char *token = strtok(str, " ");

                while(token != NULL)
                {
                    printf("%s\n", token);
                    token = strtok(NULL, " ");
                }

                break;
            }

            case 6:
            {
                char str1[200], str2[100];

                printf("Enter first string: ");
                scanf("%s", str1);

                printf("Enter second string: ");
                scanf("%s", str2);

                strcat(str1, str2);

                printf("Concatenated string: %s\n", str1);

                break;
            }

            case 7:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}