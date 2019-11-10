#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    // Name, Score, Index
    tuple <string, int, int> resteraunts[N];
    string temps;
    int tempi;
    for (int i = 0; i < N; i++)
    {
        cin >> temps >> tempi;
        resteraunts[i] = make_tuple(temps, tempi, i + 1);
    }

    sort (resteraunts, resteraunts + N,
            [](tuple<string, int, int> const &t1, tuple<string, int, int> const &t2) {
                if (get<0>(t1) == get<0>(t2))
                {
                    return get<1>(t1) > get<1>(t2);
                } else {
                    return get<0>(t1) < get<0>(t2);
                }
            }
    );

    for (int i = 0; i < N; i++)
    {
        cout << get<2>(resteraunts[i]) << "\n";
    }
}
