#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

namespace io {
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0);
        if (s.size()) { setIn(s+".in"), setOut(s+".out"); }
    }
}

using namespace io;

int N, N_i, A, B, ans = 0;


void input() {
	setIO("triangles");
}

void solve() {
	input();
}

int main() {
	solve();
    return 0;
}
