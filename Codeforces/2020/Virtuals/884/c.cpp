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
const int MX = 100005;

int N, currGroup = 0;
int group[MX], groupSize[MX], groupPoint[MX];

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> N;
	vi a(N);
	F0R(i, N) cin >> a[i];
	F0R(i, N) {
		if (!group[i]) {
			currGroup++;
			group[i] = currGroup;
			groupSize[currGroup]++;
			groupPoint[currGroup] = i;
			int j = a[i] - 1;
			while(!group[j]) {
				group[j] = currGroup;
				groupSize[currGroup]++;
				j = a[j] - 1;
			}
		}
	}
	
	vpi groups;
	FOR(i, 1, currGroup + 1) {
		groups.pb(mp(groupSize[i], i));
	}
	sort(all(groups), greater<pair<int, int>>());
	if (sz(groups) > 1) {
		groupSize[groups[0].s] += groups[1].f;
		groupSize[groups[1].s] = 0;
	}

	ll ans = 0;
	FOR(i, 1, currGroup + 1) {
		ans += (ll)groupSize[i] * groupSize[i];
	}
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
