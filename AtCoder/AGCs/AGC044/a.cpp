#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;

template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
 
template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

const ll INF = 1e18;
const ll MOD = 998244353;
const ll MX = 1000001;

ll N;
long double A, B, C, D;
ll ans = INF;

void solve() {
	ans = INF;
    cin >> N >> A >> B >> C >> D;
	long double twoAvg = 0, threeAvg = 0, fiveAvg = 0;
	twoAvg = ((N / 2) / A);
	threeAvg = ((2*N / 3) / B);
	fiveAvg = ((4*N / 5) / C);
	
	int fmove = 2;
	long double bestAvg = twoAvg;
	
	if (threeAvg >= bestAvg) {
		fmove = 3;
		bestAvg = threeAvg;
	}
	if (fiveAvg >= bestAvg) {
		fmove = 5;
		bestAvg = fiveAvg;
	}
	
	int move;
    ll n = N - (N % fmove), tmp = (N - n) * D;
    cout << "N: " <<  n << endl;
    // Problem of going backwards, is you don't know where to start 
    while (n > 0) {
		twoAvg = 0, threeAvg = 0, fiveAvg = 0;
		long double twoCost, twoDest, threeCost, threeDest, fiveCost, fiveDest, dist;
		if (n >= 2) {
			cout << "HU2H\n";
			dist = n % 2;
			twoCost = dist * D + A;
			twoDest = (n - dist) / 2;
			twoAvg = (((n - dist) / 2) / twoCost);
			cout << dist << " " << twoCost << " " << twoDest << " " << twoAvg << "\n";
		}
		if (n >= 3) {
			cout << "HU3H\n";

			dist = n % 3;
			threeCost = dist * D + B;
			threeDest = (n - dist) / 3;
			threeAvg = ((2 * (n - dist) / 3) / threeCost);
		}
		if (n >= 5) {
			cout << "HU5H\n";

			dist = n % 5;
			fiveCost = dist * D + C;
			fiveDest = (n - dist) / 5;
			fiveAvg = ((4 * (n - dist) / 5) / fiveCost);
		}
		cout << "n: " << n << " " << twoAvg << " " << threeAvg << " " << fiveAvg << "\n";
		
		if (!twoAvg && !threeAvg && !fiveAvg) {
			n--;
			tmp += D;
			continue;
		}
		
		bestAvg = 0;
		if (twoAvg >= bestAvg) {
			move = 2;
			bestAvg = twoAvg;
		}
		if (threeAvg >= bestAvg) {
			move = 3;
			bestAvg = threeAvg;
		}
		if (fiveAvg >= bestAvg) {
			move = 5;
			bestAvg = fiveAvg;
		}
		
		if (move == 2) {
			cout << "2: " << twoDest << " " << twoCost << "\n";
			n = twoDest;
			tmp += twoCost;
		} else if (move == 3) {
			cout << "3: " << threeDest << " " << threeCost << "\n";
			n = threeDest;
			tmp += threeCost;
		} else {
			cout << "5: " << fiveDest << " " << fiveCost << "\n";
			n = fiveDest;
			tmp += fiveCost;
		}
	}
	
	cout << "tmp: " << tmp << "\n";
	chmin(ans, tmp);
	
    // n = N - (N % fmove) + fmove, tmp = (n - N) * D;
    // cout << "N: " <<  n << endl;
	// while (n > 0) {
		// twoAvg = 0, threeAvg = 0, fiveAvg = 0;
		// int twoCost, twoDest, threeCost, threeDest, fiveCost, fiveDest, dist;
		// if (n >= 2) {
			// dist = n % 2;
			// twoCost = dist * D + A;
			// twoDest = (n - dist) / 2;
			// twoAvg = (((n - dist) / 2) / twoCost);
		// }
		// if (n >= 3) {
			// dist = n % 3;
			// threeCost = dist * D + B;
			// threeDest = (n - dist) / 3;
			// threeAvg = ((2 * (n - dist) / 3) / threeCost);
		// }
		// if (n >= 5) {
			// dist = n % 5;
			// fiveCost = dist * D + C;
			// fiveDest = (n - dist) / 5;
			// twoAvg = ((4 * (n - dist) / 5) / fiveCost);
		// }
		cout << "n: " << n << " " << twoAvg << " " << threeAvg << " " << fiveAvg << "\n";
		
		// if (!twoAvg && !threeAvg && !fiveAvg) {
			// n--;
			// tmp += D;
			// continue;
		// }
		
		// bestAvg = 0;
		// if (twoAvg >= bestAvg) {
			// move = 2;
			// bestAvg = twoAvg;
		// }
		// if (threeAvg >= bestAvg) {
			// move = 3;
			// bestAvg = threeAvg;
		// }
		// if (fiveAvg >= bestAvg) {
			// move = 5;
			// bestAvg = fiveAvg;
		// }
		
		// if (move == 2) {
			// cout << "2: " << twoDest << " " << twoCost << "\n";
			// n = twoDest;
			// tmp += twoCost;
		// } else if (move == 3) {
			// cout << "3: " << threeDest << " " << threeCost << "\n";
			// n = threeDest;
			// tmp += threeCost;
		// } else {
			// cout << "5: " << fiveDest << " " << fiveCost << "\n";
			// n = fiveDest;
			// tmp += fiveCost;
		// }
	// }
	
	// cout << "tmp: " << tmp << "\n";
	// chmin(ans, tmp);
	cout << ans << "\n";
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    ll T; cin >> T;
    while (T--) solve();
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
