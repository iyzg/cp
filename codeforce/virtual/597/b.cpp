#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, n;
    cin >> t;

    int times[3];
    string hands;
    int won = 0;
    for(int i = 0; i < t; i++)
    {
        cin >> n >> times[0] >> times[1] >> times[2];
        getline(cin, hands);
        getline(cin, hands);
        char response[n];
        for (int j = 0; j < n; j++)
        {   
            char c = hands[j];
            if (c == 'R' && times[1] != 0)
            {
                won++;
                times[1]--;
                response[j] = 'P';
            } else if (c == 'P' && times[2] != 0)
            {
                won++;
                times[2]--;
                response[j] = 'S';
            } else if (c == 'S' && times[0] != 0)
            {
                won++;
                times[0]--;
                response[j] = 'R';
            } else {
                response[j] = 'F';
            }
        }  
        
        if (won >= ceil((double)n / 2))
        {
            cout << "Yes" << "\n";
            for(int k = 0; k < n; k++)
            {
                if (response[k] != 'F')
                {
                    cout << response[k];
                } else {
                    if (times[0] != 0)
                    {
                        cout << 'R';
                        times[0]--;
                    } else if (times[1] != 0)
                    {
                        cout << 'P';
                        times[1]--;
                    } else {
                        cout << 'S';
                    }
                }
            }
            cout << "\n";
        } else {
            cout << "No" << "\n";
        }


        won = 0;

    }
}
