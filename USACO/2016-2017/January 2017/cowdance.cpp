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

ll N, T;
vector<int> a(10000);

bool valid(int K) {
	priority_queue<int, vector<int>, greater<int>> stage;
	for(int i = 0; i < K; i++) {
		stage.push(a[i]);
	}
	
	for(int i = K; i < N; i++) {
		stage.push(stage.top() + a[i]);
		stage.pop();
	}
	
	while(stage.size() > 1) stage.pop();
	return stage.top() <= T;
}

ll binSearch(ll low, ll high) {
	if (low == high) return low;
	if (low + 1 == high) {
		if (valid(low)) return low;
		else return high;
	}
	int mid = (low + high) / 2;
	if (valid(mid)) return binSearch(low, mid);
	else return binSearch(mid + 1, high);
}

int main() {
	setIO("cowdance");
	cin >> N >> T;
	for(int i = 0; i < N; i++) cin >> a[i];
	cout << binSearch(1, N) << "\n";
    return 0;
}
