#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int h, w, d;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> h >> w >> d;
    cout << max((w - (2 * d)), 0) * max((h - (2 * d)), 0);
}
