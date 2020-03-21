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

int N, M, X, Y, A, B;
vector<pair<pair<int, int>, int>> cows;
// bottom left Corner & top right
pair<pair<int, int>, pair<int, int>> corners[100005];
int perims[100005];
vector<int> graph[100005];
ll perim = 1e18, currComp;

void recolor(int v, int c) {
	cows[v].s = c;
	for(auto &u: graph[v])
	{
		if (cows[u].s != c && cows[u].s != -1) recolor(u, c);
	}
}

int main() {
	setIO("fenceplan");
	cin >> N >> M;
	
	for(int i = 0; i < N; i++) {
		cin >> X >> Y;
		cows.push_back(mp(mp(X, Y), -1));
	}
	
	// Don't forget to use ll when you get the perim to avoid overflow
	for(int i = 0; i < M; i++) {
		cin >> A >> B;
		A--; B--;
		graph[A].pb(B);
		graph[B].pb(A);
		if (cows[A].s == -1 && cows[B].s == -1) {
			currComp++;
			cows[A].s = cows[B].s = currComp;
		} else if (cows[A].s == -1 && cows[B].s != -1) {
			cows[A].s = cows[B].s;
		} else if (cows[A].s != -1 && cows[B].s == -1) {
			cows[B].s = cows[A].s;
		} else {
			if (cows[A].s < cows[B].s) {
				recolor(B, cows[A].s);
			} else if (cows[B].s < cows[A].s) {
				recolor(A, cows[B].s);
			}
		}
	}
	
	sort(cows.begin(), cows.end());

	for(int i = 0; i < N + 5; i++) corners[i].f = mp(-1, -1);
	for(int i = 0; i < N; i++) {
		if (corners[cows[i].s].f == mp(-1, -1)) {
			corners[cows[i].s].f = corners[cows[i].s].s = cows[i].f;
			perims[cows[i].s] = 0;
		} else {
			if (cows[i].f.s < corners[cows[i].s].f.s) corners[cows[i].s].f.s = cows[i].f.s;
			if (cows[i].f.s > corners[cows[i].s].s.s) corners[cows[i].s].s.s = cows[i].f.s;
			if (cows[i].f.f > corners[cows[i].s].s.f) corners[cows[i].s].s.f = cows[i].f.f;
		}
	}
	//for(int i = 0; i < N + 2; i++) {
		//if (corners[i].f != mp(-1, -1))
			//cout << corners[i].f.f << ", " << corners[i].f.s << " : " << corners[i].s.f << ", " << corners[i].s.s << "\n";
	//}
	for(int i = 0; i < N + 2; i++) {
		if (corners[i].f != mp(-1, -1)) {
			//cout << i << "\n";
			perim = min(perim, (ll)((corners[i].s.s - corners[i].f.s) * 2 + (corners[i].s.f - corners[i].f.f) * 2));
		}
	}
	
	cout << perim << "\n";
}
