#include <bits/stdc++.h>
using namespace std;

int N, B, S, D;
int snow[250], lastUsed[250];
pair<int, int> boots[250];

namespace io {
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0);
        if (s.size()) { setIn(s+".in"), setOut(s+".out"); }
    }
}

using namespace io;

int main() {
	setIO("snowboots");
	cin >> N >> B;
	for(int i = 0; i < N; i++) lastUsed[i] = -1;
	for(int i = 0; i < N; i++) cin >> snow[i];
	for(int i = 0; i < B; i++) {
		cin >> D >> S;
		boots[i] = make_pair(D, S);
	}
	
	for(int boot = 0; boot < B; boot++) {
		lastUsed[0] = boot;
		for(int i = 0; i < N; i++) {
			if (lastUsed[i] != -1 && snow[i] <= boots[boot].first) {
				for(int steps = 1; steps < boots[boot].second + 1; steps++) {
					if (steps + i < N && snow[steps + i] <= boots[boot].first) {
						lastUsed[steps + i] = boot;
					}
				}
			}
		}
		
		//for(int i = 0; i < N; i++) {
			//cout << lastUsed[i] << " ";
		//} 
		//cout << endl;
		
		
		if (lastUsed[N - 1] != -1) {
			cout << lastUsed[N - 1] << "\n";
			return 0;
		}
	}
    return 0;
    // You should actually read the stuff at the bottom
}

/* Stuff to Look For
 * -----------------
 * Int overflow, array bounds
 * Initializing all variables, avoid weird behavior
 * Edge cases(n = 0, n = 1)
 * Just return 0 after result
 */
