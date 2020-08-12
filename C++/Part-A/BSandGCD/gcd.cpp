#include <iostream>

using namespace std;



int gcd(int a, int b)
{
    if(a==b)
    return a;
    else if(a==0 || b==0)
        return -1;
    else if(a<b)
        return gcd(a,b-a);
    else
        return gcd(a-b,b);
    
 
}

int main()
{   int a,b;
    cout << "Enter the two values: ";
    cin >> a >> b; 

    cout << "gcd of "<< a << " and " << b << " is "<< gcd(a,b) << "\n";
    return 0;
}
