#include <iostream>
using namespace std;

// node structure
struct Node
{
    int data;
    Node *next;
};

Node *head = NULL;

// reverse linked list fuction
void reverse()
{
    Node *a, *b;
    a = NULL;
    b = head;

    Node *n;

    while (b != NULL)
    {

        n = b->next;
        b->next = a;
        a = b;
        b = n;
    }
    head = a;
}

// insertion at the end of the LL
void insert(int val)
{

    Node *ptr = new Node(); // memory is allocated in heap
    ptr->data = val;
    ptr->next = NULL;

    if (head != NULL)
    {
        Node *si = head;
        while (si->next != NULL)
        {
            si = si->next;
        }
        si->next = ptr;
    }
    else
    {
        head = ptr;
    }
}

//Function to display linked list
void display()
{
    Node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << "\n"; // spacing b/w the display and reverse
}

int main()
{
    insert(4);
    insert(9);
    insert(3);
    insert(2);
    insert(5);
    insert(1);
    insert(0);

    cout << "\n";
    display();
    reverse();
    display();
    cout << "\n";
    return 0;
}