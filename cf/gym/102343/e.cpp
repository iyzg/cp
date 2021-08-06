#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MX = 2000000;

int* sieve(int lim) {
    int* primes = new int[MX];
    primes[0] = primes[1] = 0;
    for (int i = 2; i < MX; ++i) primes[i] = 1;
    for (int i = 2; i <= lim; ++i) {
        for (int j = 2 * i; j < MX; j += i) {
            primes[j] = 0;
        }
    }

    return primes;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    int* primes = sieve(MX - 1); int* val = sieve(n);
    int fake = 0;
    for (int i = 0; i < MX; ++i) {
        if (val[i] && !primes[i]) {
            ++fake;
            // cout << fake << ' ' << i << '\n';
            if (fake == k) {
                cout << i;
                return 0;
            }
        }
    }
}
