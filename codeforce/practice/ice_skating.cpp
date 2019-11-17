#include <bits/stdc++.h>
 
using namespace std;
 
vector<int> null_fill;
int indiv = 0;
vector<int> coordinates[2000];

void visit(int curr, int last)
{
    vector<int> copy = coordinates[curr];
    coordinates[curr] = null_fill;
    for (int i = 0; i < (int)copy.size(); i++)
    {
        if (last != copy[i] && coordinates[copy[i]] != null_fill)
        {
            visit(coordinates[curr][i], curr);
        }
    }
}

int main() {
    int n; cin >> n;

    for (int i = 0; i < 2000; i++)
    {
        coordinates[i] = null_fill;
    }
    
    int x, y;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        coordinates[x - 1].push_back(y + 999);
        coordinates[y + 999].push_back(x - 1);
    }

    for (int i = 0; i < 2000; i++)
    {
        if (coordinates[i] == null_fill)
        {
            continue;
        } else {
            visit(i, -1);
            indiv++;
        }
    }

    cout << indiv - 1;
}
