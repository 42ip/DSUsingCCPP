#include <iostream>
#include <cmath>
#include <stack>
using namespace std;
int Operator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        return 1; // if it is an operator
    return -1;    // if it is not an operator
}
int Operand(char ch)
{
    if (ch >= '0' && ch <= '9')
        return 1; // if it is an operand
    return -1;    // if it is not an operand
}

float con(char ch)
{
    int value;
    value = ch;
    return float(value - 48); // converting the character into integer and ascii value of 0 is 48
}

float operation(int a, int b, char op)
{
    if (op == '*')
        return b * a;
    else if (op == '/')
        return b / a;
    else if (op == '+')
        return b + a;
    else if (op == '-')
        return b - a;
    else if (op == '^')
        return pow(b, a);
    else
        return 0;
}
float PostfixEval(string post) // making a function for the evaluation of postfix
{
    int a, b;
    stack<float> postStack;
    string::iterator i; // towards a character
    for (i = post.begin(); i != post.end(); i++)
    {
        if (Operator(*i) != -1) // if the given stack is not empty
        {
            a = postStack.top();
            postStack.pop();
            b = postStack.top();
            postStack.pop();
            // for operator we have to pop 2 times
            postStack.push(operation(a, b, *i));
        }
        else if (Operand(*i) > 0)
        {
            postStack.push(con(*i)); // after converting the character into integer, we have to push the integer into stack.
        }
    }
    return postStack.top();
}
int main()
{
    char post[100];
    cout << "Enter a valid postfix Expression: "
         << "\n";
    cin >> post;
    cout << "The result is: " << PostfixEval(post) << "\n";
}