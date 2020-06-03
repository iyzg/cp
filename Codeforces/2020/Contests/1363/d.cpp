#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int T;
int mx;

set<int> subsets[1000];

// Check if max is in this subset range
bool query(int l, int r) {
	string q = "? ";
	int sz = 0;
	for (int i = l; i <= r; i++) {
		sz += subsets[i].size();
	}
	if (!sz) return true;
	
	q += to_string(sz) + " ";
	for (int i = l; i <= r; i++) {
		for (auto& s : subsets[i]) {
			q += to_string(s) + " ";
		}
	}
	cout << q << endl;
	int check; cin >> check;
	return (check == mx);
}

int bsearch(int l, int r) {
	if (l == r) return l;
	else if (l + 1 == r) {
		if (query(l, l)) return l;
		return r;
	} else {
		int m = (l + r) / 2;
		if (query(l, m)) return bsearch(l, m);
		else return bsearch(m + 1, r);
	}
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    cin >> T;
    while(T--) {
		int N, K, C, c;
		cin >> N >> K;
		
		for (int i = 0; i < K; i++) {
			subsets[i].clear();
			cin >> C;
			for (int j = 0; j < C; j++) {
				cin >> c;
				subsets[i].insert(c);
			}
		}
		
		// Step 1: Get overall max
		string q = "? " + to_string(N) + " ";
		for (int i = 1; i <= N; i++) {
			q += to_string(i) + " ";
		}
		cout << q << endl;
		cin >> mx;
		
		// Step 2: Find subset with max
		int maxsub = bsearch(0, K - 1);
		
		// Step 3: find max without that subset
		q = "? ";
		q += to_string(N - subsets[maxsub].size()) + " ";
		for (int i = 1; i <= N; i++) {
			if (subsets[maxsub].find(i) == subsets[maxsub].end()) q += to_string(i) + " ";
		}
		cout << q << endl;
		int mxWithout; cin >> mxWithout;
		
		q = "! ";
		for (int i = 0; i < K; i++) {
			if (i == maxsub) {
				q += to_string(mxWithout) + " ";
			} else q += to_string(mx) + " ";
		}
		cout << q << endl;
		
		string res; cin >> res;
		if (res == "Correct") continue;
		else break;
	}
    return 0;
}
