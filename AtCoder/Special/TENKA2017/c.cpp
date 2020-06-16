#include <bits/stdc++.h>
using namespace std;
using ll = long long;

long double n;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (ll i = 1; i <= 3500; i++) {
        for (ll j = 1; j <= 3500; j++) {
            ll t = n * i * j;
            ll b = 4*i*j - n*j - n*i;
            if (b > 0 && !(t % b)) {
                cout << i << ' ' <<  j << ' ' << t / b;
                return 0;
            }
        }
    }
}

