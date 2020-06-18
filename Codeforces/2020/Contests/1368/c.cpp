#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, cur;
set<pair<int, int>> points;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void sim(int x, int y) {
    if (cur == n) return;
    cur++;

    points.insert({x, y});
    for (int i = 0; i < 4; i++) {
        points.insert({x + dx[i], y + dy[i]});
    }
    if (cur == 1) points.insert({x - 1, y - 1});
    if (cur == n) points.insert({x + 1, y + 1});

    sim(x + 1, y + 1);
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    sim(0, 0);

    cout << points.size() << '\n';
    for (auto point : points) {
        cout << point.first << ' ' << point.second << '\n';
    }
}
