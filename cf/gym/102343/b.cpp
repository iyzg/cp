#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    vi cnt(26, 100);
    for (auto c : s) {
        cnt[c - 'a']--;
    }

    vector<pair<int, char>> order;
    for (int i = 0; i < 26; ++i) {
        if (cnt[i] < 100) {
            order.push_back({cnt[i], (char)('a' + i)});
        }
    }
    sort(all(order));
    for (auto v : order) {
        for (int i = 0; v.first + i < 100; ++i) cout << v.second;
    }

}
