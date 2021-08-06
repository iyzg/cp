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
    int n, d;
    cin >> n >> d;
    int total = 0;
    vi a(n);
    for (auto& i : a) {
        cin >> i;
        total += i;
    }
    for (auto i : a) {
        cout << i * (d / total) << '\n';
    }
}
