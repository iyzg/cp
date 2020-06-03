#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 50;

int n, m;
string s;

int a[N][N], b[N][N];

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < n; j++) {
			a[i][j] = (s[j] == '#');
		} 
	}
	
    for (int i = 0; i < m; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			b[i][j] = (s[j] == '#');
		} 
	}
	
	bool ans = false;
	for (int i = 0; i <= n - m; i++) {
		for (int j = 0; j <= n - m; j++) {
			bool valid = true;
			for (int k = 0; k < m; k++) {
				for (int l = 0; l < m; l++) {
					if (b[k][l] != a[i + k][j + l]) {
						valid = false;
						break;
					} 
				}
				if (!valid) break;
			}
			if (valid) {
				ans = true;
				break;
			}
		}
		if (ans) break;
	} 

	ans ? cout << "Yes" : cout << "No";
    return 0;
}
