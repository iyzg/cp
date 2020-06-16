#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string s;
int k;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> s >> k;
    set<string> substrings;
    vector<string> a;
    for (int i = 0; i < (int)s.size(); i++) {
        a.push_back(s.substr(i, s.size() - i));
    }

    sort(a.begin(), a.end());
    for (auto& i : a) {
        for (int j = 1; substrings.size() < k && j <= s.size(); j++) {
            substrings.insert(i.substr(0, j));
        }
    }

    auto it = substrings.begin();
    int num = 1;
    while (num < k) {
        num++;
        it++;
    }
    cout << *it;
}

