#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
      
} 

int main() {
    int t, a, b;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        scanf("%i %i", &a, &b);
        
        if (gcd(a, b) != 1)
        {
            cout << "Infinite" << "\n";
        } else {
            cout << "Finite" << "\n";
        }
    }
}
