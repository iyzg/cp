#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;
typedef long long ll;

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

int N, A, T, ci = 1;
pair<pi, int> cows[100000];
ll currtime, ans = 0;
priority_queue<pair<int, pi>, vector<pair<int, pi>>, greater<pair<int, pi>>> q;

int main() {
	setIO("convention2");
	cin >> N;
	for(int i = 0; i < N; ++i)
	{
		cin >> A >> T;
		cows[i] = {{A, T}, i};
	}
	stable_sort(cows, cows + N);
	currtime = cows[0].f.f + cows[0].f.s;
	while(!q.empty() || ci < N)
	{
		while (ci < N && cows[ci].f.f <= currtime)
		{
			q.push({cows[ci].s, {cows[ci].f.f, cows[ci].f.s}});
			ci++;
		}
		
		if (q.empty() && ci < N) {
			currtime = cows[ci].f.f + cows[ci].f.s;
			ci++;
		} else {
			pair<int, pi> v = q.top();
			//cout << "TOP IS " << v.f << "\n";
			q.pop();
			ans = max(ans, currtime - v.s.f);
			currtime += v.s.s;
		}
	}
	
	cout << ans;
}
