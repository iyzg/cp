#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m; cin >> n >> m;
    int tasks[m];
    long long int time = 0;
    int last = 1;
    for (int i = 0; i < m; i++)
        cin >> tasks[i];

    for (int i = 0; i < m; i++)
    {
        if (tasks[i] >= last)
        {
            time += tasks[i] - last;
        } else {
            time += n - (last - tasks[i]);
        }
        last = tasks[i];
    }

    cout << time;
}
