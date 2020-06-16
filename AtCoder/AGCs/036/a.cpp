#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll LIM = 1e9;

ll s;
bitset<10000> val;
vector<ll> primes;

void sieve() {
    val.set();
    for (int i = 2; i < 10000; i++) {
        if (val[i]) {
            primes.push_back(i);
            for (int j = 2 * i; j < 10000; j += i) val[j] = false;
        }
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    sieve();
    cin >> s;
    ll x2 = 1, x3, y2 = 1, y3;
    
    if (s % 10 == 0) x3 = 0;
    else x3 = 10 - (s % 10);

    y3 = (s + x3);
    
    // reverse(primes.begin(), primes.end()) c
    for (auto prime : primes) {
        while (y3 > LIM && y3 % prime == 0 && x2 * prime <= LIM) {
            cout << y3 << ' ' << prime << '\n';
            y3 /= prime;
            x2 *= prime;
        }
        if (y3 <= LIM) break;
    }
    
    // cout << x2 * y3 - x3 * y2 << '\n';
    cout << "0 0 " << x2 << ' ' << y2 << ' ' << x3 << ' ' << y3;
}
