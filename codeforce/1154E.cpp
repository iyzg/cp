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
		cin.sync_with_stdio(0); cin.tie(0); // fast I/O
		// cin.exceptions(cin.failbit); // ex. throws exception when you try to read letter into int
		if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
	}
}
 
using namespace io;

struct Node
{
	int data;
	int next;
	int prev;
};

int main() {
	setIO();
	int n, k;
	cin >> n >> k;
	int ans[n];
	int original[n];
	vector<Node> students;
	set<int> left;
	F0R(i, n) 
	{
		int power; cin >> power;
		struct Node newNode;
		students.pb(newNode);
		students[i].data = power;
		students[i].next = i + 1;
		students[i].prev = i - 1;
		original[power - 1] = i;
		left.insert(power);
	}
	
	int team = 1;
	while (sz(left) > 0)
	{
		int it = *(--left.end()), index;
		F0R(i, n)
		{
			if (students[i].data == it) {
				index = i;
				break;
			}
		}
		
		ans[original[it - 1]] = team;
		left.erase(it);
		
		int lm = -1, rm = -1, added = 0; index = students[index].prev;
		while (added < k && index >= 0)
		{
			ans[original[students[index].data - 1]] = team;
			left.erase(students[index].data);
			rm = index;
			index = students[index].prev;
		}	
		
		added = 0; index = students[index].next;
		while (added < k && index < n)
		{
			ans[original[students[index].data - 1]] = team;
			left.erase(students[index].data);
			rm = index;
			index = students[index].next;
		}			
		
		students[lm].next = students[rm].next;
		students[rm].prev = students[lm].prev;
		
		team == 1 ? team = 2 : team = 1;
	}	
	
	F0R(i, n) cout << ans[i];
	
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
