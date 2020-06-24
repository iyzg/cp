#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, c;
int rec[30];

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> c;
    vector<pair<int, pair<int, int>>> a;
    for (int i = 0; i < n; ++i) {
        int s, t, ch;
        cin >> s >> t >> ch;
        --ch;
        a.push_back({s, {0, ch}});
        a.push_back({t, {1, ch}});
    }
    sort(a.begin(), a.end());
    
    int ans = 0, avail = 0;
    for (auto i : a) {
        int mode = i.second.first, channel = i.second.second;
        if (!mode) {
            if (rec[channel]) {
                ++rec[channel];
            } else if (avail) {
                ++rec[channel];
                --avail;
            } else {
                ++ans;
                ++rec[channel];
            }
        } else {
            --rec[channel];
            if (!rec[channel]) 
                ++avail;
        }
    }
    cout << ans;
}
