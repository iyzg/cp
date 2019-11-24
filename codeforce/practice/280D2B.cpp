#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, l; cin >> n >> l;
    int p[n];

    for (int i = 0; i < n; ++i)
        cin >> p[i];

    sort(p, p + n);

    long double d = 0;
    d = max(p[0], l - p[n - 1]);
    for (int i = 1; i < n; ++i)
    {
        if ((p[i] - p[i - 1]) / (long double)2 > d)
            d = (long double)((p[i] - p[i - 1]) / (long double)2);
    }

    cout << fixed << setprecision(9) << d;
}
