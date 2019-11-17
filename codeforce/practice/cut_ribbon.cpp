#include <bits/stdc++.h>

using namespace std;

int max_pieces[4001] = { 0 };

int main() {
    int n, a, b ,c;
    cin >> n >> a >> b >> c;
 
    max_pieces[a] = max_pieces[b] = max_pieces[c] = 1;

    for (int i = 0; i <= n; i++)
    {
        if (i - a >= 0)
        {
            if (max_pieces[i - a] != 0)
                max_pieces[i] = max(max_pieces[i - a] + 1, max_pieces[i]);
        } 
        if (i - b >= 0) {
            if (max_pieces[i - b] != 0)
                max_pieces[i] = max(max_pieces[i - b] + 1, max_pieces[i]);
        }
        if (i - c >= 0)
        {
            if (max_pieces[i - c] != 0)
                max_pieces[i] = max(max_pieces[i - c] + 1, max_pieces[i]);
        }
        
    }

    cout << max_pieces[n];
}
