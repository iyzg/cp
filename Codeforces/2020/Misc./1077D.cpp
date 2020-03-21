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

const int MX = 200005;

int N, K;
vi cnts(MX), t(MX), a(MX);

bool can(int groups) {
	t.clear();
	F0R(i, MX)
	{
		int need = min(cnts[i] / groups, K - sz(t));
		F0R(j, need) t.pb(i);
	}
	return (sz(t) == K);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> K;
	
	F0R(i, N)
	{
		cin >> a[i];
		cnts[a[i]]++;
	}

	int L = 0, R = N;
	while (R - L > 1)
	{
		int mid = (L + R) / 2;
		if (can(mid)) L = mid;
		else R = mid;
	}
	
	if (!can(R)) can(L);
	trav(it, t) cout << it << " ";
 
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
