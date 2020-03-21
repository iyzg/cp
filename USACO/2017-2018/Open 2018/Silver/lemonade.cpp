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

int N;

int main() {
	setIO("lemonade");
	cin >> N;
	vector<long long> a(N);
	for(int i = 0; i < N; i++) cin >> a[i];
	sort(a.begin(), a.end(), greater<long long>());
	
	int i = 0;
	while (i < N && a[i] >= i) i++;
	cout << i;
    return 0;
}
