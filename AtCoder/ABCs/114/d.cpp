#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MX = 10000;

int n;

bitset<MX> val;
vector<int> primes;

map<int, int> cnt;

void sieve() {
    val.set();
    for (int i = 2; i < MX; ++i) {
        if (val[i]) {
            primes.push_back(i);
            for (int j = i + i; j < MX; j += i) 
                val[j] = 0;
        }
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    sieve();
    cin >> n;
    
    for (int i = 2; i <= n; ++i) {
        int num = i;
        for (auto prime : primes) {
            while (!(num % prime)) {
                num /= prime;
                cnt[prime]++;
            }
        }
        
        if (num != 1) cnt[num]++;
    }
    
    // int fours = 0, twos = 0;
    
    int count[5] = { 0 };
    for (auto i : cnt) {
        // cout << i.first << ' ' << i.second << '\n';
        if (i.second >= 74) count[4]++;
        else if (i.second >= 24) count[3]++;
        else if (i.second >= 14) count[2]++;
        else if (i.second >= 4) count[1]++;
        else if (i.second >= 2) count[0]++;
    }
    
    // if (fours < 2 || fours + twos < 3) {
        // cout << 0;
        // return 0;
    // }
    
    for (int i = 3; i >= 0; --i) count[i] += count[i + 1];

    if (count[1] < 2 || count[0] < 3) {
        cout << 0;
        return 0;
    }

    int ans = 0;
    ans += count[4];
    ans += count[3] * (count[0] - 1);
    ans += count[2] * (count[1] - 1);
    ans += count[1] * (count[1] - 1) / 2 * (count[0] - 2);

    cout << ans;
}
