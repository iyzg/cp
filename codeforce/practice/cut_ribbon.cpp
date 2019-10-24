#include <bits/stdc++.h>

using namespace std;

int max_pieces[4001] = { 0 };
int piece_lengths[3];
int n;

void calculate_pieces(int current)
{
    for (int i = 0; i < 3; i++)
    {
        if(current + piece_lengths[i] <= n)
        {   
            max_pieces[current + piece_lengths[i]] = max(max_pieces[i], max_pieces[current] + 1);
            calculate_pieces(current + piece_lengths[i]);
        }
    }
}


int main() {
    cin >> n;

    for (int i = 0; i < 3; i++)
    {
        cin >> piece_lengths[i];
    }
    
    calculate_pieces(0);
    cout << max_pieces[n];
}
