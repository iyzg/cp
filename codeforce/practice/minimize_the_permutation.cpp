#include <bits/stdc++.h>

using namespace std;

int main() {
    int Q; cin >> Q;
    for (int q = 0; q < Q; q++)
    {
        int n, im, m = 101; cin >> n;
        int numbers[n];
        for (int i = 0; i < n; i++)
            cin >> numbers[i];

        for (int i = 0; i < n; i++)
        {
            m = numbers[i];
            im = i;
            for (int j = i; j < n; j++)
            {
                if (numbers[j] < m) {
                    m = numbers[j];
                    im = j;
                }
            }

            for (int j = im; j > i; j--)
            {
                numbers[j] = numbers[j - 1];
                numbers[j - 1] = m;
            }
            
            if (im != i)
                i = im - 1;
        }

        for (int i = 0; i < n; i++)
        {
            cout << numbers[i] << " ";
        }
        cout << "\n";
    }
}

