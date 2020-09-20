#include <iostream>
using namespace std;
struct node
{
   int data;
   struct node *next;
};

struct node *top = NULL;

void push(int val)
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

void pop()
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
   push(10);
   push(20);
   push(30);
   push(40);
   push(50);
   push(60);
   display();
   pop();
   pop();
   pop();
   display();
   return 0;
}