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


int main() {
    int n, m; cin >> n >> m;
    bool covered[n][m];
    int board[n][m];
    vector<tuple<int, int, int>> stars;
    char in;
    F0R(i, n)
    {
        F0R(j, m)
        {
            covered[i][j] = false;
            cin >> in;
            in == '*' ? board[i][j] = 1 : board[i][j] = 0;
        }
    }

    // Don't forget to add 1 to the index for coord
    FOR(row, 1, n)
    {
        FOR(column, 1, m)
        {
            if (board[row][column] == 1)
            {
                int size = 0;
                while(column + size < m && column - size >= 0 && row + size < n && row - size >= 0 && board[row][column + size] && board[row][column - size] && board[row + size][column] && board[row - size][column])
                {
                    ++size;
                }
                --size;
                if (size > 0)
                {
                    stars.pb(make_tuple(row + 1, column + 1, size));
                    FOR(i, column - size, column + size + 1)
                    {
                        covered[row][i] = true;
                    }
                    FOR(i, row - size, row + size + 1)
                    {
                        covered[i][column] = true;
                    }
                }
            }
        }
    }
    
    // Check if legal
    F0R(row, n)
    {
        F0R(column, m)
        {
            if (board[row][column] && !covered[row][column])
            {
                cout << -1;
                return 0;
            }
        }
    }

    cout << sz(stars) << "\n";
    F0R(i, sz(stars))
    {
        cout << get<0>(stars[i]) << " " << get<1>(stars[i]) << " " << get<2>(stars[i]) << "\n";
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
