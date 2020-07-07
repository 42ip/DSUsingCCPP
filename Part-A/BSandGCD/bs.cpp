#include <iostream>

using namespace std;

void BS(int arr[], int x, int y, int num)
{
    int z;
 
    if (x > y)
    {
       cout << "number not found";
    }
    z = (x + y) / 2;
    if (arr[z] == num)
    {
       cout << z ;
    }
    else if (arr[z] < num)
    {
        BS(arr, z + 1, y, num);
    }
    else if (arr[z] > num)
    {
        BS(arr, x, z - 1, num);
    }
}


int main()
{
    int num, size;
    int arr[100];
 
   cout << "enter the size: ";
   cin >> size;
   cout << "enter the elements: ";
    for(int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << "enter the element to be searched: " << "\n";
    cin >> num;
    BS(arr, 0, size, num);
 
}


