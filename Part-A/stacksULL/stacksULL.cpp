#include <iostream>
using namespace std;
struct Node {
   int data;
   struct Node *yes;
};
struct Node* top = NULL;
void push(int value) {
   struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
   temp->data = value;
   temp->yes = top;
   top = temp;
}
void pop() {
   if(top==NULL)
   cout<<"stack underflow"<<"\n";
   else {
      cout<<"popped element is "<< top->data <<"\n";
      top = top->yes;
   }
}
void display() {
   struct Node* si;
   if(top==NULL)
   cout<<"stack is empty";
   else {
      si = top;
      cout<<"the elements present in the stack are: ";
      while (si != NULL) {
         cout<< si->data <<" ";
         si = si->yes;
      }
   }
   cout<<"\n";
}
int main() {
   int choice, value;
   cout<<"1) push the data in the stack"<<"\n";
   cout<<"2) pop from stack"<<"\n";
   cout<<"3) display stack"<<"\n";
   cout<<"4) exit"<<"\n";
   do {
      cout<<"enter anyone: "<<"\n";
      cin>>choice;
      switch(choice) {
         case 1: {
            cout<<"enter value to be pushed:"<<"\n";
            cin>>value;
            push(value);
            break;
         }
         case 2: {
            pop();
            break;
         }
         case 3: {
            display();
            break;
         }
         case 4: {
            cout<<"exit"<<"\n";
            break;
         }
         default: {
            cout<<"invalid Choice"<<"\n";
         }
      }
   }while(choice!=4);
   return 0;
}