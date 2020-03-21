#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld; 
typedef double db; 
typedef string str; 

typedef pair<int, int> pi;
typedef pair<ll,ll> pl; 
typedef pair<ld,ld> pd; 

typedef vector<int> vi; 
typedef vector<ll> vl;
typedef vector<ld> vd; 
typedef vector<str> vs; 
typedef vector<pi> vpi;
typedef vector<pl> vpl; 

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound 
#define ub upper_bound 

namespace io {
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0);
        if (s.size()) { setIn(s+".in"), setOut(s+".out"); }
    }
}

using namespace io;

ll N, K, M, ans = -1;

bool valid(ll X) {
	ll given = 0;
	for(ll i = 0; i < K; ++i)
	{
		ll Y = (N - given) / X;
		if (Y < M) {
			given += (M * (K - i));
			break;
		}
		given += Y;
		if (given >= N) return true;
	}
	
	return given >= N;
}

ll binSearch(ll low, ll high) {
	if (low == high) return low;
	if (low + 1 == high) {
		if (valid(high)) return high;
		else return low;
	}
	int mid = (low + high) / 2;
	if (valid(mid)) return binSearch(mid, high);
	else return binSearch(low, mid - 1);
}

int main() {
	//setIO("loan");
	cin >> N >> K >> M;
	cout << binSearch(1, N) << "\n";
}
