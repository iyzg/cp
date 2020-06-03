#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int k, t, ai;
 
int ans;
 
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    cin >> k >> t;
    vector<int> a(t);
    for(auto& i : a) cin >> i;
    sort(a.begin(), a.end(), greater<int>());
    
    int tot = 0;
    for (int i = 1; i < t; i++) tot += a[i];
    cout << max(0, a[0] - 1 - tot);
    return 0;
}
