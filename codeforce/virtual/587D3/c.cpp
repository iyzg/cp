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
    int x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> x5 >> y5 >> x6 >> y6;
    
    // First check if either one is larger or equal then do a second check to see if they form a bigger area to cut it apart
    if ((x3 <= x1 && y3 <= y1 && x4 >= x2 && y4 >= y2) || (x5 <= x1 && y5 <= y1 && x6 >= x2 && y6 >= y2))
    {
        cout << "NO";
    } else {
        bool horiz1 = false, vert1 = false, horiz2 = false, vert2 = false; 
        if (x3 <= x1 && x4 >= x2)
        {
            horiz1 = true;
        }
        else if (y3 <= y1 && y4 >= y2)
            vert1 = true;

        if (x5 <= x1 && x6 >= x2)
            horiz2 = true;
        else if (y5 <= y1 && y6 >= y2)
            vert2 = true;
    
        if (!(horiz1 && horiz2) && !(vert1 && vert2))
        {
            cout << "YES";
            return 0;
        }

        if (horiz1 && horiz2)
        {
            if (y3 <= y1 && y4 > y1)
            {
                y1 = y4;
            } else if (y3 >= y1 && y3 < y2 && y4 >= y2)
            {
                y2 = y3;
            } else {
                cout << "YES";
                return 0;
            }

            if (x5 <= x1 && y5 <= y1 && x6 >= x2 && y6 >= y2)
            {
                cout << "NO";
            }
            else 
            {
                cout << "YES";
                return 0;
            }
        } else if (vert1 && vert2) {
            if (x3 <= x1 && x4 > x1)
            {
                x1 = x4;
            } else if (x3 >= x1 && x3 < x2 && x4 >= x2) {
                x2 = x3;
            } else {
                cout << "YES";
                return 0;
            }

            if (x5 <= x1 && y5 <= y1 && x6 >= x2 && y6 >= y2)
            {
                cout << "NO";
            }
            else 
            {
                cout << "YES";
                return 0;
            }
        }
    }
    return 0;
}
