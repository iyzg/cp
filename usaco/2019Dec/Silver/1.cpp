#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("moobuzz.in", "r", stdin);
	freopen("moobuzz.out", "w", stdout);
		
	long long n; cin >> n;
	// Doesn't work because you don't detect any more you need to remove
	// FIgure out mathematically how many are divisible by 3 or 5
	// Figure out how many in range of [n, n + to_add] then add that to n and to_add
	// This doesn't calculate for the ones in between
	long long ans = n;
	long long removed = (n / 3) + (n / 5) - (n / 15), left = removed;
	long long nn = n + removed, nremoved = (nn / 3) + (nn / 5) - (nn / 15);
	while (removed != nremoved && left > 0)
	{
		ans = nn;
		left -= min(left, (nn - n) - (nremoved - removed));
		n = nn;
		nn = nn + (nremoved - removed);
		removed = nremoved;
		nremoved = (nn / 3) + (nn / 5) - (nn / 15);
	}
	
	while (left > 0)
	{
		++ans;
		while (ans % 3 == 0 || ans % 5 == 0) ++ans;
		--left;
	}
	cout << ans << "\n";
}
