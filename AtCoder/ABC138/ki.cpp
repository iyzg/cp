#include <bits/stdc++.h>

using namespace std;

#define MAXN 200005

vector<int> tree[MAXN];
long long int differences[MAXN] = { 0 };

void results(int node, int last) {
    for (int child : tree[node])
    {
        if (child != last) {
            differences[child] += differences[node];
            results(child, node);
        }
    }
}


int main() {
    int N, Q;
    cin >> N >> Q;
    
    int a, b;
    for (int i = 0; i < N - 1; i++)
    {
        cin >> a >> b;
        tree[a - 1].push_back(b - 1);
        tree[b - 1].push_back(a - 1);
    }

    for (int i = 0; i < Q; i++)
    {
        cin >> a >> b;
        differences[a - 1] += b;
    }
    
    results(0, -1);
    for (int i = 0; i < N; i++)
    {
        cout << differences[i] << " ";
    }
}
