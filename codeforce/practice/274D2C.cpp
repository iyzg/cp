#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    pair<long long, long long> exams[n];
    long long int a, b;
    bool valid = true;

    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b;
        exams[i] = make_pair(a, b);
    }

    sort(exams, exams + n);
    long long int best = -1;
    for (int i = 0; i < n; ++i)
    {
        if (best <= exams[i].second)
        {
            best = exams[i].second;
        } else {
            best = exams[i].first;
        }
    }

    cout << best;
}

