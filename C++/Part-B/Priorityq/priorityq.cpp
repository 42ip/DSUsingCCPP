#include <iostream>
using namespace std;
#include <queue>
#define null NULL;

int main()
{
    priority_queue <int> pq;
    pq.push(60);
    pq.push(30);
    pq.push(20);
    pq.push(40);
    pq.push(50);


    if(pq.empty())
    {
        exit(1);
    }
    while(!pq.empty())
    {
        cout << "\n"<< pq.top();
        pq.pop();
    }
}