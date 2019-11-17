#include <bits/stdc++.h>

using namespace std;

char board[50][50];
vector<int> tree[2500];
bool visited[2500];

bool is_cyclic(int node, int parent)
{
    visited[node] = true;

    for (int child : tree[node])
    {
        if (!visited[child])
        {
            if (is_cyclic(child, node))
                return true;
        } else if (child != parent) {
            return true;
        }
    }

    return false;
}

int main() {
    int n, m; cin >> n >> m;

    string line;
    getline(cin, line);
    for(int i = 0; i < n; i++)
    {
        getline(cin, line);
        for (int c = 0; c < (int)line.size(); c++)
            board[i][c] = line[c];
    }

    for(int r = 0; r < n; r++)
    {
        for (int c = 0; c < m; c++)
        {
            if (r < n - 1)
                if (board[r][c] == board[r + 1][c])
                {
                    tree[(r * m) + c].push_back(((r + 1) * m) + c);
                    tree[((r + 1) * m) + c].push_back((r * m) + c);
                }
            if (c < m - 1)
                if (board[r][c] == board[r][c + 1])
                {
                    tree[(r * m) + c].push_back((r * m) + c + 1);
                    tree[(r * m) + c + 1].push_back((r * m) + c);
                }
        }
    }
    
    for(int i = 0; i < n * m; i++)
        visited[i] = false;

    bool possible = false;

    for (int i = 0; i < n * m; i++)
    {
        if (!visited[i])
            possible = is_cyclic(i, -1);
        if (possible) {
            cout << "Yes";
            return 0;
        }
    }
    
    cout << "No";
}
