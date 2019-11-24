#include <bits/stdc++.h>

using namespace std;

int main() {
    long double r, x, y, x2, y2;
    cin >> r >> x >> y >> x2 >> y2;
    long double distance = sqrt(pow(x2 - x, 2) + pow(y2 - y, 2));
    cout << ceil(distance/r * 2);
}
