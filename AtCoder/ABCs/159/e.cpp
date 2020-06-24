#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
 
template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}
 
const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);
//const ll mod = 1000000007;
int H, W, K;
string field[10];
 
int main() {
    cin >> H >> W >> K;
    for(int h = 0; h < H; h++) cin >> field[h];
    int ans = 1e9;
    for(int bits = 0; bits < (1 << (H-1)); bits++) {
        vector<vector<int>> v;
        v.push_back({0});
        for(int i = 1; i < H; i++) {
            if(!(bits & (1 << (i-1)))) v.back().push_back(i);
            else v.push_back({i});
        }
        int n = v.size();
        int val = __builtin_popcount(bits);
        vector<int> num(n);
        //cerr << "n:" << bits << " " << n << endl;
        for(int w = 0; w < W; w++) {
            vector<int> now(n);
            for(int i = 0; i < v.size(); i++) {
                for(auto tmp : v[i]) {
                    if(field[tmp][w] == '1') now[i]++;
                }
                if(now[i] > K) {
                    w = W;
                    val = 1e9;
                    break;
                }
            }
            bool cut = false;
            if(val == 1e9) break;
            for(int i = 0; i < n; i++) {
                num[i] += now[i];
                //cerr << "now:" << i << " " << now[i] << endl;
                if(num[i] > K) cut = true;
            }
            if(cut) {
                //cerr << bits << " " << w << endl;
                val++;
                for(int i = 0; i < n; i++) {
                    num[i] = 0;
                }
                w--;
            }
        }
        //cerr << bits << " "<< val << endl;
        chmin(ans, val);
    }
    cout << ans << endl;
    return 0;
}

