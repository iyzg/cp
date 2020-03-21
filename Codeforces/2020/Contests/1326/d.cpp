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
const int MX = 1000001;

int T;
str S;

bool is_palindrome(str s) {
	str r = s;
	reverse(all(r));
	return s == r;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> T;
	while(T--) {
		cin >> S;
		if (sz(S) == 1) {
			cout << S << "\n";
			continue;
		}
		
		str prefix[sz(S)], suffix[sz(S)];
		str ans = S[0];
		
		prefix[0] = S[0];
		FOR(i, 1, sz(S)) {
			prefix[i] = prefix[i - 1] + S[i];
			if (is_palindrome(prefix[i]) 
		suffix[sz(S) - 1] = S[sz(S) - 1];
		R0F(i, sz(S) - 1) suffix[i] = S[i] + suffix[i + 1];
		
		F0R(i, sz(S)) {
			if (is_palindrome(prefix[i]) && sz(prefix[i]) > sz(ans)) ans = prefix[i];
			if (is_palindrome(suffix[i]) && sz(suffix[i]) > sz(ans)) ans = suffix[i];
			
			FOR(j, i + 2, sz(S)) {
				str newStr = prefix[i] + suffix[j];
				if (is_palindrome(newStr) && sz(newStr) > sz(ans)) ans = newStr;
			}
		}
		
		cout << ans << "\n";
	}
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
