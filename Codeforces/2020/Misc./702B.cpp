#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N;
ll a_i, ans = 0;
vector<int> p2;
map<ll, int> cnt;

void input() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> N;
}

void solve() {
	int temp = 1;
	for(int i = 0; i < 32; i++)
	{
		p2.push_back(temp);
		temp *= 2;
	}
	
	while(N--)
	{
		cin >> a_i;
		for(int p = 0; p < 32; p++)
		{
			ans += cnt[p2[p] - a_i];
		}
		cnt[a_i]++;
	}
	
	cout << ans;
}

int main() {
	input();
	solve();
    return 0;
}
