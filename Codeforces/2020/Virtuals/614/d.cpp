#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define f first
#define s second

ll N, A, CF, CM, M, a_i, currForce = 0, maxForce = -1;
vector<pair<int, int>> a;
// Optimal max min (number), optimum last index to max
ll omm, ommn = 0, oml = -1;

void input() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> N >> A >> CF >> CM >> M;
	for(int i = 0; i < N; i++)
	{
		cin >> a_i;
		a.push_back(make_pair(a_i, i));
	}
}

void solve() {
	input();
	vector<int> ans(N);
	sort(a.begin(), a.end(), greater<pair<int, int>>());

	ll tempMoney = M, ltm = 0, mm = a[N - 1].f;
	//First calc without maxing any
	for (int j = N - 1; j >= 0; j--)
	{
		if (a[j].f < M) {
			ltm++;
			if (a[j - 1].f == M) break;
			if (tempMoney >= ltm * (a[j].f - mm)) {
				tempMoney -= ltm * (a[j].f - mm);
				mm = a[j].f;
			} else {
				break;
			}
		}
	}
	
	if (ltm > 0) mm = min(A, mm + (tempMoney / ltm));
	currForce += CM * mm;
	if (currForce > maxForce) {
		maxForce = currForce;
		omm = mm;
		ommn = ltm;
		oml = -1;
	}
	
	for(int i = 0; i < N; i++)
	{
		//cout << "HERE " << i << "\n";
		int cost = A - a[i].f;
		if (cost > M) break;
		else {
			M -= cost;
		}
		currForce = CF * (i + 1);
		tempMoney = M;
		ltm = 0, mm = a[N - 1].f;
		if (i == N - 1) mm = A;
		// Calc Max min
		for (int j = N - 1; j > i; j--)
		{
			if (a[j].f < M) {
				ltm++;
				if (a[j - 1].f == M) break;
				if (tempMoney >= ltm * (a[j].f - mm)) {
					tempMoney -= ltm * (a[j].f - mm);
					mm = a[j].f;
				} else {
					break;
				}
			}
		}
		
		if (ltm > 0) mm = min(A, mm + (tempMoney / ltm));
		currForce += CM * mm;
		if (currForce > maxForce) {
			//cout << "UPDATING TO " << currForce << "\n";
			maxForce = currForce;
			omm = mm;
			ommn = ltm;
			oml = i;
		}
	}
	
	for(int i = 0; i < N; i++)
	{
		if (i <= oml) ans[a[i].s] = A;
		else if (i >= N - ommn) ans[a[i].s] = omm;
		else ans[a[i].s] = a[i].f;
	}
	
	cout << maxForce << "\n";
	for(int i = 0; i < N; i++) cout << ans[i] << " ";
}

int main() {
	solve();
    return 0;
}
