#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
int L[2000];

void input() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for(int i = 0; i < N; ++i) cin >> L[i];
}

void solve() {
	input();
	vector<int> a(N);
	for(int i = 0; i < N; ++i) a[i] = L[i];
	sort(a.begin(), a.end());
	ll ans = 0;
	for(int mid = N - 1; mid >= 0; mid--)
	{
		for(int low = mid - 1; low >= 0; low--)
		{
			auto itr = lower_bound(a.begin(), a.end(), a[mid] + a[low]);
			int ng = distance(itr, a.end());
			ans += (N - 1 - mid) - ng;
		}
	}
	
	cout << ans;
}

int main() {
	solve();		
}
