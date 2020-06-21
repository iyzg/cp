#include <bits/stdc++.h>
using namespace std;
using ll = long long;

long double n, m, d;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> d;
    long double bpairs;
    
    d ? bpairs = (2 * (n - d)) / (n * n) : bpairs = 1 / n;
    cout << fixed << setprecision(6) << bpairs * (m - 1);
    // m - 1 slots that could contribute to the beauty.
    // no mod means that wouldn't be able to calculate factorials so can't be just combo.
    // Maybe use the denom (n * m) so you don't have to use mod?
    //
    //
}
