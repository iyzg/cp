#include <bits/stdc++.h>
using namespace std;

namespace io {
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0);
        if (s.size()) { setIn(s+".in"), setOut(s+".out"); }
    }
}

using namespace io;

int N, M, C, ans = 0;
int a[100000];

bool pos(int time) {
	int wagons = 1;
	int firstArrival = a[0];
	int firstIndex = 0;
	for(int i = 1; i < N; ++i)
	{
		if (a[i] - firstArrival > time || i + 1 - firstIndex > C) {
			++wagons;
			firstArrival = a[i];
			firstIndex = i;
		}
	}
	
	return (wagons <= M);
}

int binSearch(int l, int r) {
	if (l == r) return l;
	if (l + 1 == r) {
		if (pos(l)) return l;
		return r;
	}
	int m = (l + r) / 2;
	if (pos(m)) return binSearch(l, m);
	else return binSearch(m + 1, r);
}

int main() {
	setIO("convention");
	cin >> N >> M >> C;
	for(int i = 0; i < N; ++i) cin >> a[i];
	sort(a, a + N);
	cout << binSearch(0, 1000000000);
    return 0;
}

