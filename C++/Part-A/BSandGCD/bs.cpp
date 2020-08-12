#include <iostream>

using namespace std;
int bs(int A[], int l, int h, int x)
{
    if (l > h)
        return -1;
    int mid = (l + h) / 2;
    if (x == A[mid])
        return mid;
    else if (x < A[mid])
        return bs(A, l, mid - 1, x);

    else
        return bs(A, mid + 1, h, x);
}

int main(void)
{
    int A[] = {1, 2, 4, 5, 7, 54};
    int target = 4;

    int n = sizeof(A) / sizeof(A[0]);

    int l = 0, h = n - 1;
    int index = bs(A, l, h, target);

    if (index != -1)
        cout << "element found at index " << index << "\n";
    else
        cout << "element not found in the array"
             << "\n";

    return 0;
}