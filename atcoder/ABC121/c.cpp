#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    pair<int, int> stores[N];

    long long int cost, limit;
    for(int i = 0; i < N; i++)
    {
        cin >> cost >> limit;
        stores[i] = make_pair(cost, limit);
    }

    sort (stores, stores + N);
    
    long long int price = 0, to_buy = 0;
    for (int i = 0; i < N && M > 0; i++)
    {   
        to_buy = min(M, stores[i].second);
        M -= to_buy;
        price += to_buy * stores[i].first;
    }

    cout << price;
}
