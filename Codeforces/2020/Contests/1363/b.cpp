#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int T;
string S;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    cin >> T;
    while (T--) {
		cin >> S;
		int N = S.size();
		
		int ans = N;
		
		int swaps = 0;
		int oc[N] = { 0 }, zc[N] = { 0 };
		for (int i = 0; i < N; i++) {
			if (S[i] == '0') zc[i]++;
			else oc[i]++;
			
			if (i > 0 && S[i] != S[i - 1]) swaps++;
			if (i > 0) {
				oc[i] += oc[i - 1];
				zc[i] += zc[i - 1];
			}
		}
		
		if (swaps <= 1) {
			cout << "0\n";
			continue;
		}
		
		for (int i = 0; i < N; i++) {
			int cost = 0;
			cost += (i + 1) - oc[i];
			cost += oc[N - 1] - oc[i];
			ans = min(ans, cost);
			
			cost = 0;
			cost += (i + 1) - zc[i];
			cost += zc[N - 1] - zc[i];
			ans = min(ans, cost);
		}
		cout << ans << "\n";
	}
    return 0;
}
