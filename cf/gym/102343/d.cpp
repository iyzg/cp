#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MX = 500;

int n, p;
map<string, int> specials;
map<string, set<int>> nxt;

int loc[10];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> p;
    for (int i = 1; i <= n - 1; ++i) {
        string col; cin >> col;
        if (col.substr(0, 7) == "SPECIAL") {
            specials[col] = i;
        } else {
            if (nxt.find(col) != nxt.end()) {
                nxt[col].insert(i);
            } else {
                nxt[col] = set<int>();
                nxt[col].insert(i);
            }
        }
    }

    int c; cin >> c;
    vector<pair<int, string>> cards(c);
    for (auto& i : cards) {
        cin >> i.first >> i.second;
    }

    int player = -1, card = -1;
    while (true) {
        player = (player + 1) % p;
        card = (card + 1) % c;
        int ct = cards[card].first; string cc = cards[card].second;

        if (ct == 3) {
            loc[player] = specials[cc];
        } else if (ct == 1) {
            auto it = nxt[cc].upper_bound(loc[player]);
            if (it == nxt[cc].end()) {
                cout << player + 1;
                return 0;
            }
            loc[player] = *it;
        } else {
            auto it = nxt[cc].upper_bound(loc[player]);
            if (it != nxt[cc].end()) it = next(it);
            if (it == nxt[cc].end()) {
                cout << player + 1;
                return 0;
            }
            loc[player] = *it;
        }
    }
}
