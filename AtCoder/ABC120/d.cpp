#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    long long int incon = 0;
    vector<int> connections[N];
    pair<int, int> bridges[M];

    int island_one, island_two;
    for (int i = 0; i < M; i++)
    {
        cin >> island_one >> island_two;
        connections[island_one - 1].push_back(island_two - 1);
        connections[island_two - 1].push_back(island_one - 1);
        bridges[i] = make_pair(island_one - 1, island_two - 1);
    }

    for (int i = 0; i < M; i++)
    {   
        
    }
}
