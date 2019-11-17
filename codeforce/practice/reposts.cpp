#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;

    // Construct a tree, then find the longest length tree there
    // Maybe store a number of the chain along with the name so you can just do it in one go.
    
    // String of name, chain length, prev
    vector<tuple<string, int, int>> tree;
    tree.push_back(make_tuple("polycarp", 1, -1));

    string n1, g, n2;
    int parent, parent_chain, longest_chain = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> n1 >> g >> n2;
        transform(n1.begin(), n1.end(), n1.begin(), ::tolower);
        transform(n2.begin(), n2.end(), n2.begin(), ::tolower);

        for (int i = 0; i < (int)tree.size(); i++)
        {
            if (n2 == get<0>(tree[i]))
            {
                parent = i;
                parent_chain = get<1>(tree[i]);
                break;
            }
        }

        tree.push_back(make_tuple(n1, parent_chain + 1, parent));
        if (parent_chain + 1 > longest_chain)
        {
            longest_chain = parent_chain + 1;
        }
    }

    cout << longest_chain;
}
