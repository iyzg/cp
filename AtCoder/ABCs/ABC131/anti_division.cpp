#include <bits/stdc++.h>

using namespace std;

int gcd(int u, int v)
{
    return (v != 0) ? gcd(v, u % v) : u;
}


int main() {
    long long int A, B, C, D;
    cin >> A >> B >> C >> D;
    A = A - 1;

    cout << (B - (((B / C) + (B / D)) - (B / ((C * D) / gcd(C, D))))) - (A - (((A / C) + (A / D)) - (A / ((C * D) / gcd(C, D)))));
}
