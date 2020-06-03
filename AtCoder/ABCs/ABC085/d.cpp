#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, h, a, b;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> h;
    
    // Damage, 0 = slash, 1 = throw
    vector<pair<ll, ll>> katanas;
    for (int i = 0; i < n; i++) {
		cin >> a >> b;
		katanas.push_back({a, 0});
		katanas.push_back({b, 1});
	}
	sort(katanas.begin(), katanas.end(), greater<pair<ll, ll>>());
	
	ll damage = 0, hits = 0;
	for (int i = 0; i < 2*n; i++) {
		if (damage >= h) break;
		if (katanas[i].second == 1) {
			damage += katanas[i].first;
			hits++;
		} else {
			hits += ceil((h - damage) / (long double)katanas[i].first);
			break;
		}
	}
	cout << hits;
    return 0;
}
