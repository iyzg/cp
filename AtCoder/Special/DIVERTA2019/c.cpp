#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int bs, ae, both, ans;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    vector<string> a(n);
    for (auto& i : a) {
		cin >> i;
		for (int j = 0; j < i.size() - 1; j++) {
			ans += (i[j] == 'A' && i[j + 1] == 'B');
		}
		if (i[0] == 'B' && i[i.size() - 1] == 'A') {
			both++;
		} else if (i[0] == 'B') { 
			bs++; 
		} else if (i[i.size() - 1] == 'A') {
			ae++;
		}
	}
    if (ae) {
		ae--;
		ans += both;
		if (bs) {
			ans++;
			bs--;
		}
		ans += min(ae, bs);
	} else {
		if (both) ans += both - 1 + min(bs, 1);
	}
    cout << ans;
    return 0;
}
