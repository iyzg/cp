#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string s; 
vector<int> oc[26];

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> s;

    int n = s.size();
    for (int i = 0; i < n; i++) {
        oc[s[i] - 'a'].push_back(i);
    }
    
    int ans = n;
    for (int i = 0; i < 26; i++) {
        if (oc[i].size() == 0) continue;
        else {
            int mxdist = 0;
            for (int j = 0; j < (int)oc[i].size(); j++) {
                if (j == 0) mxdist = max(mxdist, oc[i][j]);
                if (j > 0) mxdist = max(mxdist, oc[i][j] - oc[i][j - 1] - 1);
                if (j == oc[i].size() - 1) mxdist = max(mxdist, n - oc[i][j] - 1);
            }
            ans = min(mxdist, ans);
        }
    }
    cout << ans;
}

