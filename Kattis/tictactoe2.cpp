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

int main() {
	setIO();
	int T; cin >> T;
	str input;
	F0R(t, T)
	{
		char board[3][3];
		int xc = 0, oc = 0;
		bool xw = false, ow = false;
		
		F0R(i, 3)
		{
			//cout << input << "\n";
			F0R(c, 3)
			{
				if (input[c] == '.') board[i][c] = 0;
				else if (input[c] == 'X')
				{
					 board[i][c] = 1;
					 ++xc;
				}
				else if (input[c] == 'O') 
				{
					board[i][c] = 2;
					oc++;
				}
			}
		}
				
		if (xc != oc && xc != oc + 1)
		{
			if (t != T - 1) 
			{
				getline(cin, input);
			}
			cout << "no\n";
			continue;
		}
		
		F0R(i, 3)
		{
			if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
			{
				if (board[i][0] == 1) xw = true;
				if (board[i][0] == 2) ow = true;
			}
		}
		
		F0R(i, 3)
		{
			if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
			{
				if (board[i][0] == 1) xw = true;
				if (board[i][0] == 2) ow = true;
			}
		}
		
		if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
		{
			if (board[0][0] == 1) xw = true;
			if (board[0][0] == 2) ow = true;
		}
		
		if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
		{
			if (board[0][2] == 1) xw = true;
			if (board[0][2] == 2) ow = true;
		}
		
		
		if (xw && ow) cout << "no\n";
		else cout << "yes\n";
		
		
		if (t != T - 1) 
		{
			getline(cin, input);
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
