#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll K, sscore, tscore;
string S, T;

ll cnt[10];
ll scnt[10], tcnt[10];

int main() {
	cin.tie(0)->sync_with_stdio(0);
    cin >> K >> S >> T;
    for (int x = 0; x <= 9; ++x) {
        int scnt = 0, tcnt = 0;
        for (int i = 0; i < 5; ++i) {
            if (S[i] - '0' == x) ++scnt;
            if (T[i] - '0' == x) ++tcnt;
        }
        sscore += x * pow(10, scnt);
        tscore += x * pow(10, tcnt);
    }

    for (int i = 0; i < 10; ++i) cnt[i] = K;
    for (int i = 0; i < 4; ++i) {
        cnt[S[i] - '0']--;
        scnt[S[i] - '0']++;
        cnt[T[i] - '0']--;
        tcnt[T[i] - '0']++;
    }

    ll tot = 0;
    ll cumm = 0;

    for (int i = 1; i <= 9; ++i) {
        for (int j = 1; j <= 9; ++j) {
            if (i != j) tot += cnt[i] * cnt[j];
            else tot += cnt[i] * (cnt[i] - 1);
            if (!cnt[i] || !cnt[j] || (i == j && cnt[i] < 2)) continue;
            ll sadd = (i * pow(10, scnt[i] + 1)) - (i * pow(10, scnt[i]));
            ll tadd = (j * pow(10, tcnt[j] + 1)) - (j * pow(10, tcnt[j]));
            if (sscore + sadd > tscore + tadd) {
                if (i != j) {
                    cumm += cnt[i] * cnt[j];
                } else {
                    cumm += cnt[i] * (cnt[i] - 1);
                }
            }
        }
    }

    cout << (long double)cumm / tot;
}
