#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    vector<int> a(n), ans;
    for (auto& i : a) cin >> i;
    
    while (!a.empty()) {
        bool found = false;

        for (int i = (int)a.size() - 1; i >= 0; --i) {
            if (a[i] == i + 1) {
                ans.push_back(i + 1);
                a.erase(a.begin() + i);
                found = true;
                break;
            }
        }
        
        if (!found) {
            cout << -1 << "\n";
            return 0;
        }
    }

    reverse(ans.begin(), ans.end());
    for (int i = 0; i < n; i++) cout << ans[i] << "\n";

    return 0;
}
