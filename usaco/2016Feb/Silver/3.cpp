#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi; 
 
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)
 
#define pb push_back
 
void setIO(string name) {
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
	ios_base::sync_with_stdio(0);
}

int X, Y, K, M, opt = -1;

int main() {
	setIO("pails");
	
	cin >> X >> Y >> K >> M;
	
	// Make sure X is always the smallest
	if (Y < X)
	{
		int temp = X;
		X = Y;
		Y = temp;
	}
	
	if (M >= X + Y)
	{
		cout << M - X - Y;
		return 0;
	}
	
	opt = M;
	int xf = 0, yf = 0;
	F0R(k, K)
	{
		if (k % 2 == 0) xf += X;
		else 
		{
			yf += max(Y - yf, X);
			
		}
		
		opt = min(opt, abs(M - xf - yf));	
	}
	
	// Reset xf & yf
	xf = yf = 0;
	F0R(k, K)
	{
		if (yf == 0) yf += Y;
		else {
			if (k % 2 == 0) xf = 0;
			else {
				int diff = min(yf, X);
				yf -= diff;
				xf += diff;
			}
		}
		
		opt = min(opt, abs(M - xf - yf));
	}
	
	
	
	
	cout << opt;
	cout << "\n";
	return 0;
}
