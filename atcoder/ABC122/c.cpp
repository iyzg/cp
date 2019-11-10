#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    string s;
    getline(cin, s);
    getline(cin, s);
    int AC[N] = { 0 };
    int found = 0;
    for(int i = 1; i < N; i++)
    {
        if (s[i] == 'C' && s[i - 1] == 'A')
        {
            found++;
        }

        AC[i] = found;
    }
    
    int left, right;
    for (int q = 0; q < Q; q++)
    {   
        cin >> left >> right;
        
        cout << AC[right - 1] - AC[left - 1] << "\n";
    }
}
