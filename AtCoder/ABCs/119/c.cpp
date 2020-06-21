#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;

ll mp;
bitset<8> taken, val;

int main() {
    cin >> n;
    vector<ll> target(3), bamboo;
    for (auto& i : target) cin >> i;
    for (int i = 0; i < n; ++i) {
        int bam; cin >> bam;
        bamboo.push_back(bam);
    }

    sort(target.begin(), target.end(), greater<ll>());

    val.set();
    for (int t = 0; t < 3; ++t) {
        int mn = 10000;
        taken.reset();
        for (int i = 1; i < (1 << n); ++i) {
            int used = 0, length = 0, tmptaken = 0;
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j) && val[j]) {
                    tmptaken += (1 << j);
                    if (length > 0) used += 10;
                    length += bamboo[j];
                }
            }

            if (!length) continue;
            used += abs(length - target[t]);
            if (used < mn) {
                taken = tmptaken;
                mn = used;
            }
        }

        cout << t << ' ' << mn << '\n';
        mp += mn;
        cout << taken << '\n';
        for (int i = 0; i < 8; ++i) {
            if (taken[i]) val[i] = false;
        }
    }
    
    cout << mp;
}
