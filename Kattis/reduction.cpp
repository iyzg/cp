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

int N, M, L, A, B;
str in, agency;
stringstream ss;

bool sortbysec(const pair<int,int> &a, 
              const pair<int,int> &b) 
{ 
    return (a.second < b.second); 
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	int TC; cin >> TC;
	F0R(i, TC)
	{
		cin >> N >> M >> L;
		vector<pair<string, int>> agencys;
		F0R(i, L)
		{
			int dp[N + 1];
			F0R(i, N + 1) dp[i] = -1;
			dp[N] = 0;
			
			cin >> in;
			agency = in.substr(0, in.find(':'));
			ss << in.substr(in.find(':') + 1, in.find(','));
			ss << in.substr(in.find(',') + 1);
			ss >> A;
			ss >> B;
			cout << agency << " " << A << " " << B;
			
			ROF(i, 1, N + 1)
			{
				if (dp[i / 2] == -1) dp[i / 2] = dp[i] + B;
				else dp[i / 2] = min(dp[i / 2], dp[i] + B);
				
				if (dp[i - 1] == -1) dp[i] + A;
				else dp[i - 1] = min(dp[i - 1], dp[i] + A);
			}
			
			agencys.pb(mp(agency, dp[M]);
		}
		
		sort(all(agencys), sortbysec);
		// Go through agencys and print them in order
		cout << "Case " << i + 1 << "\n";
		F0R(i, L)
		{
			cout << agencys[i].f << " " << agencys[i].s << "\n";
		}
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
