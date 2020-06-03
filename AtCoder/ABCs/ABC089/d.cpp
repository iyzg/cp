#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX = 90000;

int h, w, d, a, q, l ,r;
pair<int, int> coord[MX];

int cost[MX];

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    cin >> h >> w >> d;
    for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> a; --a;
			coord[a] = {i, j};
		}
	}
	
	for (int i = 0; i < h * w; i++) {
		if (i < d) {
			cost[i] = 0;
		} else {
			int last = i - d;
			cost[i] = cost[last] + abs(coord[i].first - coord[last].first) + abs(coord[i].second - coord[last].second); 
			// cout << i <<  " " << cost[last] << " " << cost[i] << "\n";
		}
	}
    
    cin >> q;
    while(q--) {
		cin >> l >> r;
		--l; --r;
		cout << cost[r] - cost[l] << "\n";
	}
    return 0;
}
