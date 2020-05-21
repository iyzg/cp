#include <bits/stdc++.h>

using namespace std;

int main() {
    int airplanes[3];
    cin >> airplanes[0] >> airplanes[1] >> airplanes[2];

    sort(airplanes, airplanes + 3);
    cout << airplanes[0] + airplanes[1];
}
