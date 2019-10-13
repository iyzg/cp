#include <bits/stdc++.h>

using namespace std;

void apply_points(vector<int> tree[], int counters[], int node, int value)
{
    counters[node - 1] += value;
    for (int child : tree[node - 1])
    {
        apply_points(tree, counters, child, value);
    }
}

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> tree[N];
    int counters[N] = { 0 };
    int parent, child;
    for (int i = 0; i < N - 1; i++)
    {
        cin >> parent >> child;
        tree[parent - 1].push_back(child);
    }
    
    int node, value;
    for (int i = 0; i < Q; i++)
    {
        cin >> node >> value;
        apply_points(tree, counters, node, value);
    }

    for (int node : counters)
    {
        cout << node << " ";
    }
}
