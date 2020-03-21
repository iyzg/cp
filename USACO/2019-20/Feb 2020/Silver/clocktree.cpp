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
//vi times;
//vi tree[2505];

void input() {
	setIO("clocktree");
	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> N_i;
		times.push_back(N_i);
	}
	
	for(int i = 0; i < N - 1; i++) {
		cin >> A >> B;
		A--; B--;
		tree[A].push_back(B);
		tree[B].push_back(A);
	}
}

void solve() {
	input();
	 //Test them all as the root and see if its valid
	F0R(i, N) {
		 //Make sure the root will be 12
		if ((sz(tree[i] - 1) + times[i]) % 12) continue;
		valid = true;
		queue<int> q;
		vector<bool> used(N);
		vector<int> d(N), p(N);
		
	}
	cout << 1 << "\n";
}

int main() {
	solve();
    return 0;
}
