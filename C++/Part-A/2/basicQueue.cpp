#include <bits/stdc++.h>
using namespace std;

class Queue
{
    int front, rear, capacity;
    int *queue;

public:
    Queue(int total)
    {
        front = rear = 0;
        capacity = total;
        queue = new int;
    }
    void enqueue(int temp)
    {
        if (capacity == rear)
        {
            printf("\nQueue is full Hence Value not added .....\n");
            return;
        }
        else
        {
            queue[rear] = temp;
            rear++;
        }
        return;
    }
    void Dequeue()
    {
        if (front == rear)
        {
            printf("\nQueue is empty ...... \n");
            return;
        }
        else
        {
            cout<<"\nDequed "<<queue[0]<<" from the Queue";
            for (int i = 0; i < rear - 1; i++)
            {
                queue[i] = queue[i + 1];
            }
            rear--;
        }
        return;
    }

    void displayAll()
    {
        int i;
        if (front == rear)
        {
            printf("\nQueue is Empty\n");
            return;
        }
        cout<<"The elements in the Queue are \n";
        for (i = front; i < rear; i++)
        {
            printf("%d ", queue[i]);
        }
        cout<<"\n";
        return;
    }
    void Front()
    {
        if (front == rear)
        {
            printf("\nQueue is Empty\n");
            return;
        }
        printf("\nFront Element is: %d\n", queue[front]);
        return;
    }
};
int main()
{
    int max, choice;
    cout << "Enter the max Size of Queue:  ";
    cin >> max;
    Queue queue(max);
    cout << "1. Enqueue \n";
    cout << "2. Dequeue \n";
    cout << "3. Peek from Queue\n";
    cout << "4. Display full queue\n";
    cout << "5. Exit\n" ;
    do
    {
        cout << "Enter Anyone: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the value to Enqueue: \n";
            int val;
            cin >> val;
            queue.enqueue(val);
            break;

        case 2:
            queue.Dequeue();
            break;

        case 3:
            queue.Front();
            break;

        case 4:
            queue.displayAll();
            break;
        case 5:
            exit(0);
        default:
            cout << "Default Option try running the program again ......";
        }
    }
    while (choice != 5);
}