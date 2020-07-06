#include <bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 1)
    {
        cout << "Moved disk 1 from rod " << from_rod << " to rod " << to_rod << "\n";
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    cout << "Moved disk " << n << " from rod " << from_rod << " to rod " << to_rod << endl;
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}
int main()
{
    int n;
    cout << "Enter the number of disks to be moved from A to C: ";
    cin >> n;
    towerOfHanoi(n, 'A', 'C', 'B');
    cout<<"Moved "+n+" disks from A to C";
    return 0;
}
