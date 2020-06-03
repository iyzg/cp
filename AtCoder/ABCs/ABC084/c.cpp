#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 500;

int n;
int c[N], s[N], f[N];

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> c[i] >> s[i] >> f[i];
	}
	
	for (int i = 0; i < n; i++) {
		ll t = 0;
		for (int station = i; station < n - 1; station++) {
			if (t <= s[station]) {
				t = s[station];
				t += c[station];
			} else {
				int wait = (t - s[station]) % f[station];
				if (wait) wait = f[station] - wait;
				t += wait;
				t += c[station];
			}
		}
		cout << t << "\n";
	}
    return 0;
}
