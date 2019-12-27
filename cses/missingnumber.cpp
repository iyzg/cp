#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	long long n, total = 0, sum = 0; cin >> n;
	for(int i = 0; i < n - 1; ++i)
	{
		int a_i; cin >> a_i;
		sum += a_i;
		total += i + 1;
	}
	total += n;
	cout << total - sum;
}
