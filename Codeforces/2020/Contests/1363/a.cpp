#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int T;
int X, N;
 
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    cin >> T;
    while(T--) {
		cin >> N >> X;
		int even = 0, odd = 0;
		vector<ll> a(N);
		for (auto& i : a) {
			cin >> i;
			if (i % 2) odd++;
			else even++;
		}
		
		if (!odd) {
			cout << "No\n";
			continue;
		}
		
		bool found = false;
		for (int i = 1; i <= min(X, odd); i += 2) {
			if (i + even >= X) {
				found = true;
				cout << "Yes\n";
				break;
			}
		}
		if (!found) cout << "No\n";
	}
    return 0;
}
