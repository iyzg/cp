#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define mp make_pair
#define pb push_back
#define f first
#define s second

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
string line; 
map<string, int> m;

int main() {
	setIO("leftout");
	cin >> N;
	vector<string> configs, lines;
	getline(cin, line);
	for (int i = 0; i < N; i++) {
		getline(cin, line);
		lines.pb(line);
		
		string config;
		int consec = 1;
		for(int j = 1; j < N; j++) {
			if (line[j] == line[j - 1]) consec++;
			else {
				config += to_string(consec);
				consec = 1;
			}
			if (j == N - 1) config += to_string(consec);
		}
		configs.pb(config);
		m[config]++;
	}
	
	if (m.size() > 2) {
		cout << "-1\n";
		return 0;
	}
	
	string magicConfig;
	int row, col = -1;
	for(auto &i : m) {
		if (i.s == 1) {
			magicConfig = i.f;
			break;
		}
	}
	
	for (int i = 0; i < N; i++) {
		if (configs[i] == magicConfig) {
			row = i;
			break;
		}
	}
	int cr;
	row > 0 ? cr = 0 : cr = 1;
	int index = -1;
	for(int i = 0; i < N; i++) {
		if (lines[cr][i] != lines[row][i]) {
			if (index == -1) {
				index = i;
			} else {
				index = -1;
				break;
			}
		}
	}
	if (index != -1) col = index;
	index = -1;
	for(int i = 0; i < N; i++) {
		if (lines[cr][i] == lines[row][i]) {
			if (index == -1) {
				index = i;
			} else {
				index = -1;
				break;
			}
		}
	}
	if (index != -1) {
		if (col == -1) {
			col = index;
		} else {
			col = min(col, index);
		}
	}
	
	if (col == -1) {
		cout << "-1\n";
		return 0;
	}
	
	cout << row + 1 << " " << col + 1 << "\n";		
}
