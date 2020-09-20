#include <bits/stdc++.h>
using namespace std;

struct Queue
{
	int rear, front;

	int size;
	int *arr;

	Queue(int s)
	{
		front = rear = -1;
		size = s;
		arr = new int[s];
	}
	// Abstract functions to be Implemented later
	void enQueue(int value);
	int deQueue();
	void displayQueue();
};

void Queue::enQueue(int value)
{
	if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
	{
		printf("\nQueue is Full\nHence to element is not Enqueued\n\n");
		return;
	}

	else if (front == -1)
	{
		front = rear = 0;
		arr[rear] = value;
	}

	else if (rear == size - 1 && front != 0)
	{
		rear = 0;
		arr[rear] = value;
	}

	else
	{
		rear++;
		arr[rear] = value;
	}
}

int Queue::deQueue()
{
	if (front == -1)
	{
		printf("\nQueue is Empty\n");
		return INT_MIN;
	}

	int data = arr[front];
	arr[front] = -1;
	if (front == rear)
	{
		front = -1;
		rear = -1;
	}
	else if (front == size - 1)
		front = 0;
	else
		front++;

	return data;
}

void Queue::displayQueue()
{
	if (front == -1)
	{
		printf("\nQueue is Empty\n");
		return;
	}
	printf("\nElements in Circular Queue are: ");
	if (rear >= front)
	{
		for (int i = front; i <= rear; i++)
			printf("%d ", arr[i]);
	}
	else
	{
		for (int i = front; i < size; i++)
			printf("%d ", arr[i]);

		for (int i = 0; i <= rear; i++)
			printf("%d ", arr[i]);
	}
	printf("\n");
}
int main()
{
	int size, n = 0;
	cout << "Enter the size of circular stack:  ";
	cin >> size;
	Queue queue(size);
	while (n != 4)
	{
		cout << "Enter one of the four options\n1)Enqueue\n2)Dequeue\n3)Display elements in the Queue\n4)Exit\nEnter an option:  ";
		cin >> n;
		if (n == 1)
		{
			int temp;
			cout << "Enter the element you want to enqueue: ";
			cin >> temp;
			queue.enQueue(temp);
		}
		if (n == 2)
		{
			int x = queue.deQueue();
			if (x != INT_MIN)
				cout << "The element dequeued is " << x << "\n\n";
			else
				cout << "Hence not dequeued \n\n";
		}
		if (n == 3)
		{
			queue.displayQueue();
		}
	}
	return 0;
}
