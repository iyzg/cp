#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string n;
int k;

bitset<10> avail;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    avail.set();
    vector<int> a(k);
    for (auto& i : a) {
        cin >> i;
        avail[i] = 0;
    }

    vector<bool> overload((int)n.size(), false);
    for (int i = n.size() - 1; i >= 0; --i) {
        if (i < n.size() - 1) {
            if (overload[i + 1] && n[i] == '9') {
                overload[i] = true;
                continue;
            } else if (overload[i + 1]) {
                n[i]++;
            }
        }

        int pos = false;
        for (int j = n[i] - '0'; j < 10; ++j) {
            if (avail[j]) pos = true;
        }
        if (!pos) overload[i] = true;
    }   

    string ans;
    bool overloaded = false;
    for (int i = 0; i < n.size(); i++) {
        if (overload[i]) {
            if (i == 0) {
                for (int j = 1; j < 10; j++) {
                    if (avail[j]) {
                        ans += j + '0';
                        break;
                    }
                }
            }
            overloaded = true;
        }
        if (overloaded) {
            for (int j = 0; j < 10; ++j) {
                if (avail[j]) {
                    ans += j + '0';
                    break;
                }
            }
        } else {
            for (int j = n[i] - '0'; j < 10; ++j) {
                if (avail[j]) {
                    ans += j + '0';
                    if (j + '0' != n[i]) overloaded = true;
                    break;
                }
            }
        }
    }
    cout << ans;
}   


