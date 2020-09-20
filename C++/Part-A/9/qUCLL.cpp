#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void enqueue(int val)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = top;
    top = newnode;
}

void display()
{

    struct node *temp;

    if (top == NULL)
        cout << "empty";
    else
    {
        temp = top;
        cout << "stack elements are: ";

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    cout << "\n";
}

void dequeue()
{
    if (top == NULL)
        cout << "underflow" << endl;
    else
    {
        cout << "popped element: " << top->data << endl;
        top = top->next;
    }
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);
    display();
    dequeue();
    dequeue();
    dequeue();
    display();
    return 0;
}