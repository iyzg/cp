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

int N, K;
str num;
vi digitCount(10), changeSum(10);
int minChange = MX, minNum = -1;

// For digits 0 - 9, change of 1 to 9, no 0 change obv.
int changeCount[10][10];

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> N >> K >> num;
	F0R(i, N) digitCount[num[i] - '0']++;
	F0R(i, 10) {
		if (digitCount[i] >= K) {
			cout << "0\n" << num;
			return 0;
		}
	}  
	
	F0R(i, N) {
		F0R(j, 10) {
			if (num[i] - '0' != j) changeCount[j][abs(j - (num[i] - '0'))]++;
		}
	}
	
	F0R(i, 10) {
		int changed = digitCount[i];
		FOR(j, 1, 10) {
			changeSum[i] += min(K - changed, changeCount[i][j]) * j;
			changed += min(K - changed, changeCount[i][j]);
		}
	}
	
	vs results(10);
	F0R(i, 10) results[i] = num;
	F0R(j, 10) {
		vi actualChange(10);
		int toChange = K - digitCount[j];
		FOR(i, 1, 10) {
			actualChange[i] = min(toChange, changeCount[j][i]);
			toChange -= min(toChange, changeCount[j][i]);
		}
		
		F0R(i, N) {
			if (results[j][i] - '0' > j && actualChange[abs(j - (results[j][i] - '0'))]) {
				actualChange[abs(j - (results[j][i] - '0'))]--;
				results[j][i] = j + '0';
			}
		}
		
		R0F(i, N) {
			if (results[j][i] - '0' < j && actualChange[abs(j - (results[j][i] - '0'))]) {
				actualChange[abs(j - (results[j][i] - '0'))]--;
				results[j][i] = j + '0';
			}
		}
	}
	
	F0R(i, 10) {
		if (changeSum[i] < minChange) {
			minChange = changeSum[i];
			minNum = i;
			num = results[i];
		} else if (changeSum[i] == minChange) {
			if (results[i] < num) {
				minChange = changeSum[i];
				minNum = i;
				num = results[i];
			}
		}
	}

	cout << minChange << "\n" << num;
	
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
