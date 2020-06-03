#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string n;
ll K, ans;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> K;
	ll N = n.size();
    vector<ll> a(N);
    for (int i = 0; i < N; i++) {
		a[i] = n[i] - '0';
	}
	
	if (K == 1) {
		for (int i = N - 1; i >= 0; i--) {
			if (i == 0) {
				ans += a[i];
			} else {
				ans += 9;
			}
		}
	} else if (K == 2) {
		for (int i = N - 2; i >= 0; i--) {
			if (i == 0) {
				bool second = false;
				for (int j = i + 1; j < N; j++) {
					if (second) ans += a[i] * 9;
					else ans += (9 * (a[i] - 1)) + a[j];
					if (a[j]) second = true;
				}
			} else {
				for (int j = i + 1; j < N; j++) {
					ans += 81;
				}
			}
		}
	} else {
		for (int i = N - 3; i >= 0; i--) {
			if (i == 0) {
				bool second = false;
				for (int j = i + 1; j < N; j++) {
					if (!second && !a[j]) continue;
					bool third = false;
					for (int k = j + 1; k < N; k++) {
						if (second) {
							ans += a[i] * 9 * 9;
						} else {
							ans += (a[i] - 1) * 9 * 9;
							ans += max(0ll, (a[j] - 1)) * 9;
							if (third) ans += 9; 
							else ans += a[k];
						}

						if (a[k]) third = true;
					}
					if (a[j]) second = true;
				}
			} else {
				for (int j = i + 1; j < N; j++) {
					for (int k = j + 1; k < N; k++) {
						ans += (9 * 9 * 9);
					}
				}
			}
		}		
	}
	
	cout << ans;
    return 0;
}
