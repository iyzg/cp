#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    int n = N - 1, m = M, petya_score = 0, max = 0;
    bitset<200000> state;
    state[0] = 1;
    for (int i = 1; i < N + M; i++)
    {
        if (i % 2 == 1)
        {
            if (state[i - 1] == 0)
            {
                if (n != 0)
                {
                    state[i] = 1;
                    n--;
                } else {
                    state[i] = 0;
                    m--;
                    petya_score++;
                }
            } else {
                if (m != 0)
                {
                    state[i] = 0;
                    m--;
                } else {
                    state[i] = 1;
                    n--;
                    petya_score++;
                }
            }
        } else {
            if (state[i - 1] == 0)
            {
                if (m != 0)
                {
                    state[i] = 0;
                    m--;
                    petya_score++;
                } else {
                    state[i] = 1;
                    n--;
                }
            } else {
                if (n != 0)
                {
                    state[i] = 1;
                    n--;
                    petya_score++;
                } else {
                    state[i] = 0;
                    m--;
                }
            }
        }
    }
    
    if (petya_score > max) max = petya_score;
    petya_score = 0;
    n = N, m = M - 1;
    state.reset();
    state[0] = 0;
    for (int i = 1; i < N + M; i++)
    {
        if (i % 2 == 1)
        {
            if (state[i - 1] == 0)
            {
                if (n != 0)
                {
                    state[i] = 1;
                    n--;
                } else {
                    state[i] = 0;
                    m--;
                    petya_score++;
                }
            } else {
                if (m != 0)
                {
                    state[i] = 0;
                    m--;
                } else {
                    state[i] = 1;
                    n--;
                    petya_score++;
                }
            }
        } else {
            if (state[i - 1] == 0)
            {
                if (m != 0)
                {
                    state[i] = 0;
                    m--;
                    petya_score++;
                } else {
                    state[i] = 1;
                    n--;
                }
            } else {
                if (n != 0)
                {
                    state[i] = 1;
                    n--;
                    petya_score++;
                } else {
                    state[i] = 0;
                    m--;
                }
            }
        }
    }
    if (petya_score > max) max = petya_score;
    cout << max << " " << N + M - (max + 1);
}
