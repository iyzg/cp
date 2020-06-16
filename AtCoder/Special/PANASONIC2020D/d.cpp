#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;

void f(string s) {
    if (s.size() == n) {
        cout << s << '\n';
        return;
    }
    s.push_back('a');
    f(s);
    s.pop_back();
    for (char a = 'b'; a <= 'z'; a++) {
        bool ok = false;
        for (auto& b : s) {
            if (a == b + 1) ok = true;
        }

        if (ok) {
            s.push_back(a);
            f(s);
            s.pop_back();
        }
    }
}


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    f("");
}
