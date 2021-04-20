#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 2 * 1e5 + 5;

int n;
int a[N], loc[N], to_l[N], to_r[N];

int main() {
	cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        loc[a[i]] = i;
        if (i < a[i] - 1) {
            ++to_r[i + 1], --to_r[a[i]];
        } else if (i > a[i] - 1) {
            ++to_l[i], --to_l[a[i] - 1];
        }
    }

    // for (int i = 2; i < n - 1)
    for (int i = 2; i < n - 1; ++i) {
        if (to_l[i] || to_r[i]) {
            cout << "-1";
            return 0;
        }
    }

    if (to_r[1] != 1 || to_l[n - 1] != 1) {
        cout << "-1";
        return 0;
    }

    vector<int> ops;
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] != i + 1) {
            for (int j = loc[i + 1]; j < i; ++j) {
                swap(a[j], a[j + 1]);
                ops.push_back(j + 1);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (a[i] != i + 1) {
            cout << "-1";
            return 0;
        }
    }

    for (auto i : ops) {
        cout << i << '\n';
    }
}
