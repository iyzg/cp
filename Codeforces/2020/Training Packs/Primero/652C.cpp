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

const int MOD = 998244353;
const ll INF = 1e18;
const int MX = 300005;

int N, M, A, B, findex = 0;
ll ans = 0;
map<int, int> lindex;
int perm[MX], pindex[MX];
vector<pi> foes;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	ans += N;
	F0R(i, N)
	{
		cin >> perm[i];
		pindex[perm[i]] = i;
	}
	// Note whichever one is the one that occurs later
	F0R(i, M)
	{
		cin >> A >> B;
		int largestIndex = max(pindex[A], pindex[B]);
		lindex[largestIndex] = max(lindex[largestIndex], min(pindex[A], pindex[B]));
	}
	
	trav(i, lindex)
	{
		foes.pb(mp(i.f, i.s));
	}
	sort(all(foes));
	
	F0R(i, N)
	{
		while (findex < sz(foes) && (i >= foes[findex].f || i > foes[findex].s)) 
		{
			++findex;
		}
		
		if (findex == sz(foes)) {
			ans += N - i - 1;
		} else {
			ans += foes[findex].f - i - 1;
		}
	}
	// Store the max foe
	// O(n^2) solution?
	
	cout << ans;
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
