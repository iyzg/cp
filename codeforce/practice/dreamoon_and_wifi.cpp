#include <bits/stdc++.h>

using namespace std;

queue<int> odds;
void fill_odds(int curr, int target)
{
    if (curr <= target)
    {
        int original_size = (int)odds.size(), element;
        for (int i = 0; i < original_size; i++)
        {
            element = odds.front();
            odds.pop();
            odds.push(element - 1);
            odds.push(element + 1);
        }

        fill_odds(curr + 1, target);
    }
}

int main() {
    cout << fixed << setprecision(12);
    odds.push(-1);
    odds.push(1);
    string send, received;
    int ss = 0, rs = 0, qm = 0;
    getline(cin, send);
    getline(cin, received);
    for (int i = 0; i < (int)send.length(); i++)
    {
        if (send[i] == '+')
            ss++;
        else
            ss--;
    }

    for (int i = 0; i < (int)received.length(); i++)
    {
        if (received[i] == '+')
        {
            rs++;
        } else if (received[i] == '-') {
            rs--;
        } else {
            qm++;
        }
    }
    
    if (qm == 0)
    {
        if (ss == rs)
            cout << (double)1;
        else 
            cout << (double)0;
    } else {
        if (abs(ss - rs) > qm) {
            cout << (double)0;
            return 0;
        } 
        int difference = abs(ss - rs), qmv = 0;
        int tc = pow(2, qm);
        fill_odds(2, qm);
        int front;
        while (!odds.empty())
        {
            front = odds.front();
            if (front == difference)
                qmv++;
            odds.pop();
        }
        double answer = (double)qmv / tc;
        // printf("%.12f\n", answer);
        cout << answer;
    }
}
