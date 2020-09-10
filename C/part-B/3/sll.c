#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;
Node *head = NULL;
void appendInsert(int data)
{
    Node *link = malloc(sizeof(Node));
    link->data = data;
    if (head == NULL)
        head = link;
    else
    {
        Node *temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = link;
    }
}
int listLength()
{
    int i = 0;
    Node *temp = head;
    while (temp)
    {
        i++;
        temp = temp->next;
    }
    return i;
}
void insertPos(int data, int pos)
{
    int len = listLength();
    if (len < pos)
    {
        printf("Cant insert");
        return;
    }
    Node *link = malloc(sizeof(Node));
    link->data = data;
    Node *temp = head;
    if (pos == 0)
    {
        link->next=head;
        head=link;
    }
    else
    {
        while (pos > 1 && temp->next)
        {
            temp = temp->next;
            pos--;
        }
        link->next = temp->next;
        temp->next = link;
    }
}
void printList()
{
    Node *temp = head;
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
int main()
{
    appendInsert(10);
    appendInsert(20);
    appendInsert(30);
    appendInsert(40);
    appendInsert(50);
    appendInsert(60);
    appendInsert(70);
    appendInsert(80);
    insertPos(15, 8);
    printList();
    return 0;
}