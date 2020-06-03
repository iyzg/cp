#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int sx, sy, tx, ty;
string f, b;
string ans;

set<pair<int, int>> vis;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    cin >> sx >> sy >> tx >> ty;
    int curx = sx, cury = sy;
    while (curx != tx || cury != ty) {
		if (cury < ty) {
			cury++;
			f += 'U';
			vis.insert({curx, cury});
		}
		
		if (curx < tx - 1 || cury == ty) {
			curx++;
			f += 'R';
			vis.insert({curx, cury});
		}
	}
	
	ans += f;
	
    while (curx != sx || cury != sy) {
		if (cury > sy && vis.find({curx, cury - 1}) == vis.end()) {
			cury--;
			b += 'D';
		}
		
		if (curx > sx && vis.find({curx - 1, cury}) == vis.end()) {
			curx--;
			b += 'L';
		}

	}
    ans += b;
    ans += "LU" + f + "RD";
    ans += "RD" + b + "LU";
    
	cout << ans;
    return 0;
}
