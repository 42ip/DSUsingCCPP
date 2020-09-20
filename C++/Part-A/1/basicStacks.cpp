#include <iostream>

#define max 1000

using namespace std;

static int top = -1;
int *stack = new int[max];

void push(int data)
{
    if (top == max)
    {
        cout << "Stack overflow"
             << "\n";
    }

    top++;
    stack[top] = data;
}

void pop()
{
    if (top == -1)
    {
        cout << "Stack underflow"
             << "\n";
    }
    else
    {
        cout << "The popped element is " << stack[top] << "\n";
        top--;
    }
}
void showstack()
{
    cout << "The elements of stack are: \n";
    for (int i = 0; i <= top; i++)
    {
        cout << stack[i] << " ";
    }
}
void isFullStack()
{
    if (top == max)
        cout << "Stack is full";
}

void isEmptyStack()
{
    if (top == -1)
        cout << "Stack is full";
}

int main()
{
    int n, val;
    cout << "1. push "
         << "\n";
    cout << "2. pop "
         << "\n";
    cout << "3. isFullStack "
         << "\n";
    cout << "4. isEmptyStack "
         << "\n";
    cout << "5. show stack"
         << "\n";
    do
    {
        cout << "Enter Anyone: "
             << "\n";
        cin >> n;

        switch (n)
        {
        case 1:
            cout << "Enter the val."
                 << "\n";
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
        case 5:
            showstack();
            break;
        default:
            cout << "Nope";
        }

    } while (n != 4);

    return 0;
}
