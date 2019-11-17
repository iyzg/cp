#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int liked[M] = { 0 };
    int number_liked, food_liked;
    for (int i = 0; i < N; i++)
    {
        cin >> number_liked;
        for(int j = 0; j < number_liked; j++)
        {
            cin >> food_liked;
            liked[food_liked - 1]++;
        }
    }
    
    number_liked = 0;
    for (int i = 0; i < M; i++)
    {
        if (liked[i] == N)
        {
            number_liked++;
        }
    }

    cout << number_liked;
}
