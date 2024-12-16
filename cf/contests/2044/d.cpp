#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int t, n;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n;
        set<int> filler;
        set<int> seen;

        vi ar(n);
        for (int j = 0; j < n; ++j) {
            cin >> ar[j];
            filler.insert(j + 1);
        }

        // Create set of valid filler (can't be in array that you read in)
        for (int j = 0; j < n; ++j) {
            filler.erase(ar[j]);
        }

        // cout << *filler.begin() << '\n';
        // Create set of #s you've seen?

        // Loop through, if new number then must be, else filler
        for (int j = 0; j < n; ++j) {
            // Haven't seen it yet
            if (seen.find(ar[j]) == seen.end()) {
                cout << ar[j] << ' ';
                seen.insert(ar[j]);
            } else {
                cout << *filler.begin() << ' ';
                filler.erase(filler.begin());
            }
        }
        cout << '\n';
    }
}
