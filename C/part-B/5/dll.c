#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head;
struct Node *MakeNode(int x)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
void InsertFirst(int x)
{
    struct Node *newNode = MakeNode(x);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}
void InsertLast(int x)
{
    struct Node *temp = head;
    struct Node *newNode = MakeNode(x);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}
int length()
{
    int i = 0;
    struct Node *temp = head;
    while (temp)
    {
        temp = temp->next;
        i++;
    }
    return i;
}
void insert(int data, int pos)
{
    struct Node *newNode = MakeNode(data);
    if (head == NULL)
        head = newNode;
    else
    {
        if (pos == 0)
        {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
        else if (pos < length())
        {
            struct Node *temp = head;
            while (pos > 1 && temp->next)
            {
                temp = temp->next;
                pos--;
            }
            newNode->prev = temp;
            newNode->next = temp->next;
            temp->next->prev = newNode;
            temp->next = newNode;
        }
        else
        {
            struct Node *temp = head;
            while(temp->next)
            {
                temp=temp->next;
            }
            newNode->prev=temp;
            temp->next=newNode;
        }
    }
}
void PrintForward()
{
    struct Node *temp = head;
    printf("List from Forward: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void PrintReverse()
{
    struct Node *temp = head;
    if (temp == NULL)
        return;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    printf("List from Reverse: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main()
{

    head = NULL;
    InsertLast(2);
    InsertLast(4);
    InsertFirst(6);
    InsertLast(8);
    insert(10, 3);
    PrintForward();
    PrintReverse();
}