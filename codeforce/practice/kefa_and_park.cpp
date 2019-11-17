#include <bits/stdc++.h>

using namespace std;

vector<int> null_fill;
vector<int> tree[100000];
int has_cat[100000];
int m;

int visit(int node, int parent, int consecutive_cats)
{
    int places_to_go = 0;
    bool node_infected = false;
    if (has_cat[node] == 1)
        node_infected = true;

    if (consecutive_cats + has_cat[node] > m)
        return 0;

    if ((int)tree[node].size() == 1 && tree[node][0] == parent) {
        if (consecutive_cats + has_cat[node] > m)
        {
            return 0;
        } else {
            return 1;
        }
    }

    for (int child : tree[node])
    {
        if (child != parent)
        {
            if (node_infected)
            {
                places_to_go += visit(child, node, consecutive_cats + 1);
            } else {
                places_to_go += visit(child, node, 0);
            }
        }
    }

    return places_to_go;
}

int main() {
    int n, resteraunts; cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> has_cat[i];
        tree[i] = null_fill;
    }
    
    int a, b;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        tree[a - 1].push_back(b - 1);
        tree[b - 1].push_back(a - 1);
    }
    
    resteraunts = visit(0, -1, 0);
    cout << resteraunts;
}
