#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 5;

int n;
bitset<N> val, seen;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    sort(a.begin(), a.end());
    
    val.set(); seen.reset();
    int ans = 0;
    for (auto i : a) {
        if (!val[i]) continue;
        else {
            if (seen[i]) {
                val[i] = false;
                ans--;
                continue;
            }

            ans++;
            seen[i] = true;
            for (int j = i + i; j < N; j += i) val[j] = false;
        }
    }

    cout << ans;
}
