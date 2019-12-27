#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);

    int n; cin >> n;
    string road; getline(cin, road);
    getline(cin, road);

    int ans = 1;
    vector<string> seqs;
    bool valid = false;
    while (!valid)
    {
        valid = true;
        for(int i = 0; i < (int)road.length() - (ans - 1); i++)
        {
            string section = road.substr(i, ans);
            for(int j = 0; j < (int)seqs.size(); j++)
            {
                if (section == seqs[j])
                {
                    valid = false;
                    break;
                }
            }
            if (!valid) break;
            else seqs.push_back(section);
        }

        if (!valid)
        {
            seqs.clear();
            ++ans;
        }
    }

    cout << ans << "\n";
}

