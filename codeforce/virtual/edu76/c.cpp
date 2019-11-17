#include <bits/stdc++.h>

using namespace std;

int main() {
    int T; cin >> T;
    for (int t = 0; t < T; t++)
    {
        int n, input, current_shortest = 200001; cin >> n;
        int arr[n] = { 0 };
        for (int i = 1; i <= n; i++)
        {
            cin >> input;
            if (arr[input - 1] == 0)
            {
                arr[input - 1] = i;
            } else {
                if (i - arr[input - 1] + 1 < current_shortest)
                    current_shortest = i - arr[input - 1] + 1;
                arr[input - 1] = i;
            }
        }
            
        if (current_shortest == 200001)
        {
            cout << "-1\n";       
            continue;
        } else {
            cout << current_shortest << "\n";
        }
    }
}
