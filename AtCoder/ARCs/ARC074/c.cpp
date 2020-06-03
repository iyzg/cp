#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
ll h, w, ans = INF;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    cin >> h >> w;
    
    // Either two horiz cuts, two vert cuts, or one each
    if (!(h % 3)) ans = 0;
    else ans = min(ans, w);
    
    if (!(w % 3)) ans = 0;
    else ans = min(ans, h);
    
    for (int i = 1; i < w; i++) {
		ans = min(ans, max(h * i, (ll)ceil((long double)h / 2) * (w - i)) - min(h * i, h / 2 * (w - i)));
		// cout << h * i << " " << (ll)ceil((long double)h / 2) * (w - i) << " " << h / 2 * (w - i) << "\n";
		// cout << max(h * i, (ll)ceil(h / 2) * (w - i)) - min(h * i, h / 2 * (w - i)) << "\n";
	}
	
	for (int i = 1; i < h; i++) {
		ans = min(ans, max(w * i, (ll)ceil((long double)w / 2) * (h - i)) - min(w * i, w / 2 * (h - i)));
	}
    
    cout << ans;
    return 0;
}
