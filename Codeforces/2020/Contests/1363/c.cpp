#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int T;
int N, X, U, V;


int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    cin >> T;
    while (T--) {
		cin >> N >> X;
		if (N == 1) {
			cout << "Ayush\n";
			continue;
		}
		
		int cc = 0;
		for (int i = 0; i < N - 1; i++) {
			cin >> U >> V;
			if (U == X || V == X) cc++;
		}
		
		if (cc == 1) {
			cout << "Ayush\n";
			continue;
		}
			
		if ((N - 2) % 2 == 0) {
			cout << "Ayush\n";
		} else cout << "Ashish\n";
	}
    return 0;
}
