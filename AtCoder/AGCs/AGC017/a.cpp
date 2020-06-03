#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, p;
ll ans;

int even, odd;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> p;
    vector<int> a(n);
    for (auto& i : a) {
		cin >> i;
		i % 2 ? odd++ : even++;
	}
    
    if (even == n) {
		if (p) cout << 0;
		else cout << fixed << setprecision(0) << pow(2, n);
	} else {
		cout << fixed << setprecision(0) << pow(2ll, n - 1);
	}
    return 0;
}
