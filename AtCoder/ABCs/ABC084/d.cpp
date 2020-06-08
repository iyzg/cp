#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 100005;

int q, l, r;
int psum[N];

bitset<N> val;
set<int> primes;

void sieve() {
    val.set();
    for (int i = 2; i < N; i++) {
        if (val[i]) {
            primes.insert(i);
            for (int j = i + i; j < N; j += i) val[j] = false;
        }
    }
}

void precomp() {
    for (int i = 3; i < N; i++) {
        if (i % 2) {
            if (primes.find(i) != primes.end() && primes.find((i + 1) / 2) != primes.end()) psum[i]++;
        }
        
        psum[i] += psum[i - 1];
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    sieve();
    precomp();
    
    cin >> q;
    while (q--) {
        cin >> l >> r;
        cout << psum[r] - psum[l - 1] << '\n';
    }
}
