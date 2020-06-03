#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    cin >> N;
    vector<ll> a(N);
    for (auto& i : a) cin >> i;
    sort(a.begin(), a.end());
    ll ub = a[0];
    for (int i = 1; i < N - 1; i++) {
		if (a[i] <= a[N - 1] / 2) {
			if (a[N - 1] / 2 - a[i] < a[N - 1] / 2 - ub) {
				ub = a[i];
			}
		} else {
			if (abs(a[i] - ceil(a[N - 1] / (double)2)) < abs(ub - ceil(a[N - 1] / (double)2))) {
				ub = a[i];
			}
		}
	}
    cout << a[N - 1] << " " << ub;
    return 0;
}
