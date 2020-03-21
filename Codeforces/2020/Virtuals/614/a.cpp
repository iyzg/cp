#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

unsigned long long L, R, K, A = 1;
bool valid = false;

void input() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> L >> R >> K;
}

void solve() {
	input();
	while (A <= R)
	{
		if (A >= L) {
			valid = true;
			cout << A << " ";
		}
		if (A > R / K) break;
		A *= K;
	}
	
	if (!valid) cout << -1;
}

int main() {
	solve();
    return 0;
}
