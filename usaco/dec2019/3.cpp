#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);

    int n; cin >> n;
    vector<string> order;
    order.push_back("Beatrice");
    order.push_back("Belinda");
    order.push_back("Bella");
    order.push_back("Bessie");
    order.push_back("Betsy");
    order.push_back("Blue");
    order.push_back("Buttercup");
    order.push_back("Sue");
    vector<vector<string>> groups;
    string con; getline(cin, con);

    for(int i = 0; i < n; ++i)
    {
        getline(cin, con);
        string f = con.substr(0, con.find(' '));
        string s = con.substr(con.find_last_of(' ') + 1);
        bool fin = false, sin = false;
        int fj, fk, sj, sk;
        fj = fk = sj = sk = -1;
        // Remove from group
        order.erase(remove(order.begin(), order.end(), f), order.end());
        order.erase(remove(order.begin(), order.end(), s), order.end());

        for(int j = 0; j < (int)groups.size(); ++j)
        {
            for(int k = 0; k < (int)groups[j].size(); ++k)
            {
                if (groups[j][k] == f) 
                {
                    fin = true;
                    fj = j;
                    fk = k;
                }
                if (groups[j][k] == s)
                {
                    sin = true;
                    sj = j;
                    sk = k;
                }
            }
        }

        if (!fin && !sin)
        {
            vector<string> ng;
            ng.push_back(f);
            ng.push_back(s);
            sort(ng.begin(), ng.end());
            groups.push_back(ng);
        } else if (!fin && sin) {
            if (sk == 0) groups[sj].insert(groups[sj].begin(), f);
            else groups[sj].push_back(f);
        } else  if (fin && !sin) {
            if (fk == 0) groups[fj].insert(groups[fj].begin(), s);
            else groups[fj].push_back(s);
        } else {
            // If they're both the first one, reverse a group
            if (fk == 0 && sk == 0)
            {
                if (groups[fj][groups[fj].size() - 1] < groups[sj][groups[sj].size() - 1])
                {
                    reverse(groups[fj].begin(), groups[fj].end());
                    fk = -1;
                } else {
                    reverse(groups[sj].begin(), groups[sj].end());
                    sk = -1;
                }       
            } else if (fk != 0 && sk != 0) {
                if (groups[fj][0] < groups[sj][0]) 
                {
                    reverse(groups[sj].begin(), groups[sj].end());
                    sk = -1;
                } else {
                    reverse(groups[fj].begin(), groups[fj].end());
                    fk = -1;
                }
            }

            if (fk == 0)
            {
                groups[fj].insert(groups[fj].begin(), groups[sj].begin(), groups[sj].end());
                groups.erase(groups.begin() + sj);
                // erase old group
            } else {
                groups[sj].insert(groups[sj].begin(), groups[fj].begin(), groups[fj].end());
                groups.erase(groups.begin() + fj);
            }
        }
    }
    
    for(int i = 0; i < (int)groups.size(); ++i)
    {
        if (groups[i][0] > groups[i][groups[i].size() - 1]) reverse(groups[i].begin(), groups[i].end());
    }

    sort(order.begin(), order.end());
    sort(groups.begin(), groups.end());
    
    // make final list
    while(order.size() || groups.size())
    {
        if (order.size() && groups.size())
        {
            if (order[0] < groups[0][0])
            {
                cout << order[0] << "\n";
                order.erase(order.begin());
            } else {
                for (int i = 0; i < (int)groups[0].size(); i++)
                {
                    cout << groups[0][i] << "\n"; 
                }
                groups.erase(groups.begin());
            }
        } else if (order.size())
        {
            cout << order[0] << "\n";
            order.erase(order.begin());
        } else {
            for (int i = 0; i < (int)groups[0].size(); i++)
            {
                cout << groups[0][i] << "\n"; 
            }
            groups.erase(groups.begin());
        }
    }
}
