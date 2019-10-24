#include <bits/stdc++.h>

using namespace std;

int main() {
    int b, m, n, p = 0;
    cin >> n;

    int boys[n];
    for(int i = 0; i < n; i++)
    {
        cin >> boys[i];
    }

    cin >> m;
    vector<int> girls;
    for(int i = 0; i < m; i++)
    {
        cin >> b;
        girls.push_back(b);
    }

    sort(boys, boys + n);
    sort(girls.begin(), girls.end());

    for(int i = 0; i < n; i++)
    {
        for (long unsigned int j = 0; j < girls.size(); j++)
        {
            if (girls[j] - boys[i] > 1)
            {
                break;
            } 

            if (abs(girls[j] - boys[i]) <= 1)
            {
                girls.erase(girls.begin() + j);
                p++;
                break;
            }
        }
    }

    cout << p;
}
