#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char ch)
{
    stack[++top] = ch;
}

char pop()
{
    return stack[top--];
}

char peek()
{
    return stack[top];
}

int precedence(char ch)
{
    if(ch == '^')
        return 3;

    if(ch == '*' || ch == '/')
        return 2;

    if(ch == '+' || ch == '-')
        return 1;

    return 0;
}

void reverse(char str[])
{
    int i, j;
    char temp;

    for(i = 0, j = strlen(str) - 1; i < j; i++, j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

/* Infix to Postfix */
void infixToPostfix(char infix[], char postfix[])
{
    int i, k = 0;
    char ch;

    top = -1;

    for(i = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];

        if(isalnum(ch))
        {
            postfix[k++] = ch;
        }
        else if(ch == '(')
        {
            push(ch);
        }
        else if(ch == ')')
        {
            while(top != -1 && peek() != '(')
                postfix[k++] = pop();

            pop();
        }
        else
        {
            while(top != -1 &&
                  peek() != '(' &&
                  precedence(peek()) >= precedence(ch))
            {
                postfix[k++] = pop();
            }

            push(ch);
        }
    }

    while(top != -1)
        postfix[k++] = pop();

    postfix[k] = '\0';
}

/* Infix to Prefix */
void infixToPrefix(char infix[], char prefix[])
{
    char rev[SIZE];
    char postfix[SIZE];

    strcpy(rev, infix);

    reverse(rev);

    for(int i = 0; rev[i] != '\0'; i++)
    {
        if(rev[i] == '(')
            rev[i] = ')';
        else if(rev[i] == ')')
            rev[i] = '(';
    }

    infixToPostfix(rev, postfix);

    strcpy(prefix, postfix);

    reverse(prefix);
}

/* Prefix to Postfix */
void prefixToPostfix(char prefix[], char postfix[])
{
    char s[SIZE][SIZE];
    int t = -1;

    for(int i = strlen(prefix) - 1; i >= 0; i--)
    {
        char ch = prefix[i];

        if(isalnum(ch))
        {
            s[++t][0] = ch;
            s[t][1] = '\0';
        }
        else
        {
            char op1[SIZE], op2[SIZE], temp[SIZE];

            strcpy(op1, s[t--]);
            strcpy(op2, s[t--]);

            strcpy(temp, op1);
            strcat(temp, op2);

            int len = strlen(temp);
            temp[len] = ch;
            temp[len + 1] = '\0';

            strcpy(s[++t], temp);
        }
    }

    strcpy(postfix, s[t]);
}

/* Prefix to Infix */
void prefixToInfix(char prefix[], char infix[])
{
    char s[SIZE][SIZE];
    int t = -1;

    for(int i = strlen(prefix) - 1; i >= 0; i--)
    {
        char ch = prefix[i];

        if(isalnum(ch))
        {
            s[++t][0] = ch;
            s[t][1] = '\0';
        }
        else
        {
            char op1[SIZE], op2[SIZE], temp[SIZE];

            strcpy(op1, s[t--]);
            strcpy(op2, s[t--]);

            temp[0] = '(';
            temp[1] = '\0';

            strcat(temp, op1);

            int len = strlen(temp);
            temp[len] = ch;
            temp[len + 1] = '\0';

            strcat(temp, op2);
            strcat(temp, ")");

            strcpy(s[++t], temp);
        }
    }

    strcpy(infix, s[t]);
}

/* Postfix to Prefix */
void postfixToPrefix(char postfix[], char prefix[])
{
    char s[SIZE][SIZE];
    int t = -1;

    for(int i = 0; postfix[i] != '\0'; i++)
    {
        char ch = postfix[i];

        if(isalnum(ch))
        {
            s[++t][0] = ch;
            s[t][1] = '\0';
        }
        else
        {
            char op1[SIZE], op2[SIZE], temp[SIZE];

            strcpy(op1, s[t--]);
            strcpy(op2, s[t--]);

            temp[0] = ch;
            temp[1] = '\0';

            strcat(temp, op2);
            strcat(temp, op1);

            strcpy(s[++t], temp);
        }
    }

    strcpy(prefix, s[t]);
}

/* Postfix to Infix */
void postfixToInfix(char postfix[], char infix[])
{
    char s[SIZE][SIZE];
    int t = -1;

    for(int i = 0; postfix[i] != '\0'; i++)
    {
        char ch = postfix[i];

        if(isalnum(ch))
        {
            s[++t][0] = ch;
            s[t][1] = '\0';
        }
        else
        {
            char op1[SIZE], op2[SIZE], temp[SIZE];

            strcpy(op1, s[t--]);
            strcpy(op2, s[t--]);

            temp[0] = '(';
            temp[1] = '\0';

            strcat(temp, op2);

            int len = strlen(temp);
            temp[len] = ch;
            temp[len + 1] = '\0';

            strcat(temp, op1);
            strcat(temp, ")");

            strcpy(s[++t], temp);
        }
    }

    strcpy(infix, s[t]);
}

int main()
{
    int choice;
    char exp[SIZE];
    char result[SIZE];

    while(1)
    {
        printf("\n----- EXPRESSION MENU -----\n");
        printf("1. Infix to Prefix\n");
        printf("2. Prefix to Postfix\n");
        printf("3. Prefix to Infix\n");
        printf("4. Postfix to Prefix\n");
        printf("5. Postfix to Infix\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter infix: ");
                scanf("%s", exp);

                infixToPrefix(exp, result);

                printf("Prefix: %s\n", result);
                break;

            case 2:
                printf("Enter prefix: ");
                scanf("%s", exp);

                prefixToPostfix(exp, result);

                printf("Postfix: %s\n", result);
                break;

            case 3:
                printf("Enter prefix: ");
                scanf("%s", exp);

                prefixToInfix(exp, result);

                printf("Infix: %s\n", result);
                break;

            case 4:
                printf("Enter postfix: ");
                scanf("%s", exp);

                postfixToPrefix(exp, result);

                printf("Prefix: %s\n", result);
                break;

            case 5:
                printf("Enter postfix: ");
                scanf("%s", exp);

                postfixToInfix(exp, result);

                printf("Infix: %s\n", result);
                break;

            case 6:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}