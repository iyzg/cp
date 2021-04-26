#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, k;
string s;

char winner(char a, char b) {
    if (a == b) return a;
    if (a > b) swap(a, b);
    // PRS
    if (a == 'P' && b == 'S') return 'S';
    if (a == 'P' && b == 'R') return 'P';
    if (a == 'R' && b == 'S') return 'R';
    return 'X';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k >> s;

    for (int i = 0; i < k; ++i) {
        string t;
        for (int i = 0; i < n; i += 2) {
            if (i != n - 1) t += winner(s[i], s[i + 1]);
            else t += winner(s[i], s[0]);
        }

        if (n % 2 == 1) {
            for (int i = 1; i < n; i += 2) {
                if (i != n - 1) t += winner(s[i], s[i + 1]);
                else t += winner(s[i], s[0]);
            }
        } else {
            for (int i = 0; i < n; i += 2) {
                if (i != n - 1) t += winner(s[i], s[i + 1]);
                else t += winner(s[i], s[0]);
            }
        }
        
        s = t;
        // cout << i << ": " << s << '\n';
    }
    
    cout << s[0];
}
