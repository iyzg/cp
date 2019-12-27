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

const int MX = 100005;
int N, Q, A[MX], B[MX], C[MX];

// Left right sort of thing

int main() {
	setIO("bcount");
	cin >> N >> Q;
	F0R(i, N) 
	{
		int in; cin >> in;
		if (in == 1) A[i]++;
		else if (in == 2) B[i]++;
		else C[i]++;
		
		if (i > 0)
		{
			A[i] += A[i - 1];
			B[i] += B[i - 1];
			C[i] += C[i - 1];
		}
	}
	
	F0R(q, Q)
	{
		int a_i, b_i; cin >> a_i >> b_i;
		if (a_i == 1)
		{
			cout << A[b_i - 1] << " ";
			cout << B[b_i - 1] << " ";
			cout << C[b_i - 1];

		} else {
			cout << A[b_i - 1] - A[a_i - 2] << " ";
			cout << B[b_i - 1] - B[a_i - 2] << " ";
			cout << C[b_i - 1] - C[a_i - 2];
		}
		cout << "\n";
	}
		
	return 0;
}
