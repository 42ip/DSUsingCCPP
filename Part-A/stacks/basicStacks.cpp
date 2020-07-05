#include <iostream>

#define max 1000

using namespace std;

static int top = -1;
int *stack = new int[max];

void push(int data){
    if(top==max){
        cout << "Stack overflow" << "\n";
    }

    top++;
    stack[top] = data;
}

void pop(){
    if(top == -1){
        cout << "Stack underflow" << "\n";
    }else{
        cout << "The popped element is "<< stack[top] << "\n";
        top--;
    }
}

bool isFullStack(){
    return ( top == max ) ? true:false;
}

bool isEmptyStack(){
    return ( top== -1 ) ? true:false;
}

int main()
{
    int yup,val;
    cout << "1. push " << "\n"; 
    cout << "2. pop " << "\n"; 
    cout << "3. isFullStack " << "\n"; 
    cout << "4. isEmptyStack " << "\n"; 
    do {
        cout << "Enter Anyone: " << "\n";
        cin >> yup;
        
        switch(yup) {
            case 1: 
            cout << "Enter the val." << "\n";
            cin >> val;
            push(val);
            break;

            case 2:
            pop();
            break;

            case 3:
            isFullStack();
            break;

            case 4:
            isEmptyStack();
            break;

            default: 
            cout << "Nope";
        }

    }while(yup != 4);
    
    return 0;
}
