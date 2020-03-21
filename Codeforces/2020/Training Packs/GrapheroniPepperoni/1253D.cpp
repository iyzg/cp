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
const int MX = 200000;

int N, M, A, B, curr = 0, until = -1, ans = 0;
int parent[MX], tSize[MX], maxNode[MX];

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (tSize[a] < tSize[b])
            swap(a, b);
        parent[b] = a;
        tSize[a] += tSize[b];
        maxNode[a] = max(maxNode[a], maxNode[b]);
    }
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	F0R(i, N) 
	{
		parent[i] = i;
		tSize[i] = 1;
		maxNode[i] = i;
	}
	
	F0R(i, M)
	{
		cin >> A >> B;
		union_sets(--A, --B);
	}
			
	curr = until = -1;
	// Loop through all the nodes and add any
	F0R(i, N)
	{
		if (i > until) {
			curr = -1;
			until = -1;
		}
		
		if (tSize[find_set(i)] == 1 && curr == -1) continue;
		
		if (curr == -1 && tSize[find_set(i)] != 1) {
			curr = find_set(i);
			until = maxNode[curr];
			continue;
		}
		
		if (tSize[find_set(i)] != 1 && find_set(i) != curr) {
			ans++;
			union_sets(curr, i);
			curr = find_set(i);
			until = maxNode[curr];
		} else if (tSize[find_set(i)] == 1) {
			ans++;
		}
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
