#include <iostream>
using namespace std;
#define null NULL;
#define MAX 100


typedef struct node
{
    struct node *next;
    char value;
} node;

node *top = null;

void insert(char value)
{
    node *newnode = (struct node*) malloc(sizeof(node));
    newnode->value = value;

    if (top == NULL)
        top = newnode;
    else
    {
        node *temp = top;
        while (temp->next)
            temp = temp->next;
        temp->next = newnode;
    }
}
void show()
{
    node *temp = top;
    while (temp)
    {
        cout << temp->value;
        temp = temp->next;
    }
}

char arr[MAX];
void check()
{
       int i = 0;
       node *temp = top;
       bool isPalindrome = true;
       
    while (temp)
    {
        arr[i] = temp->value;
        temp = temp->next;
        i++;
    }
   temp=top;

    for (i=i-1; i > -1; i--)
    {
        if (temp->value != arr[i])
        {
            isPalindrome = false;
        }
        temp = temp->next;
    }
    if (isPalindrome)
        cout << " is a palindrome";
    else
        cout << " is not a palindrome";
}
int main()
{
    insert('l');
    insert('e');
    insert('a');
    insert('e');
    insert('l');
    show();
    check();
    return 0;
}