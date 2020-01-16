#include <bits/stdc++.h>
using namespace std;

namespace io {
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0);
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
    }
}

using namespace io;

int N, M, C, ans = 0;

int main() {
	setIO("convention");
	cin >> N >> M >> C;
	vector<int> a(N);
	for(int i = 0; i < N; ++i) cin >> a[i];
	sort(a.begin(), a.end());
	
	
	cout << ans;
    return 0;
}

