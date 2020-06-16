#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int h, w;

map<char, int> cnt;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            char c; cin >> c;
            cnt[c]++;
        }
    }
    
    vector<int> needed;
    for (int i = 0; i < ceil((double)h / 2); i++) {
        for (int j = 0; j < ceil((double)w / 2); j++) {
            int cnt = 4;
            if (h % 2 && i == h / 2) cnt /= 2;
            if (w % 2 && j == w / 2) cnt /= 2;
            needed.push_back(cnt);
        }
    }
    sort(needed.begin(), needed.end(), greater<int>());

    priority_queue<int, vector<int>> pq;
    for (auto i : cnt) {
        pq.push(i.second);
    }
    
    for (auto i : needed) {
        int v = pq.top();
        pq.pop();
        if (v < i) {
            cout << "No";
            return 0;
        } else {
            v -= i;
            if (v) pq.push(v);
        }
    }
    cout << "Yes";
}
