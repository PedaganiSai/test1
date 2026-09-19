#include <stdio.h>

#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

void enqueue()
{
    int value;

    if(rear == SIZE - 1)
    {
        printf("Queue is full\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &value);

    if(front == -1)
        front = 0;

    rear++;

    queue[rear] = value;
}

void dequeue()
{
    if(front == -1 || front > rear)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Deleted: %d\n", queue[front]);

    front++;

    if(front > rear)
    {
        front = -1;
        rear = -1;
    }
}

void display()
{
    if(front == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");

    for(int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }

    printf("\n");
}

int main()
{
    int choice;

    while(1)
    {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}