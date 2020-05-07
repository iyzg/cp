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

const ll INF = 1e18;
const ll MOD = 998244353;
const ll MX = 1000001;

ll N, A, B, C;
vector<string> actions;
vector<char> ans;
queue<int> a, b, c;

void solve() {
    cin >> N >> A >> B >> C;
    actions.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> actions[i];
        if (actions[i] == "AB") {
            a.push(i);
            b.push(i);
        } else if (actions[i] == "AC") {
            a.push(i);
            c.push(i);
        } else {
            b.push(i);
            c.push(i);            
        }
    }
    
    for (int i = 0; i < N; i++) {
        if (actions[i] == "AB") {
            if (!A && !B) {
                cout << "No";
                return;
            }
            a.pop();
            b.pop();
            if (A && !B) {
                ans.push_back('B');
                A--; B++;
            } else if (!A && B) {
                ans.push_back('A');
                A++; B--;
            } else if (a.empty()) {
                ans.push_back('B');
                A--; B++;
            } else if (b.empty()) {
                ans.push_back('A');
                B--; A++;
            } else if (a.front() <= b.front()) {
                ans.push_back('A');
                A++; B--;
            } else {
                ans.push_back('B');
                A--; B++;
            }
        } else if (actions[i] == "AC") {
            if (!A && !C) {
                cout << "No";
                return;
            }
            a.pop();
            c.pop();
            if (A && !C) {
                ans.push_back('C');
                A--; C++;
            } else if (!A && C) {
                ans.push_back('A');
                A++; C--;
            } else if (a.empty()) {
                ans.push_back('C');
                A--; C++;
            } else if (c.empty()) {
                ans.push_back('A');
                C--; A++;
            } else if (a.front() <= c.front()) {
                ans.push_back('A');
                A++; C--;
            } else {
                ans.push_back('C');
                A--; C++;
            }
        } else {
            if (!C && !B) {
                cout << "No";
                return;
            }
            b.pop();
            c.pop();   
            if (C && !B) {
                ans.push_back('B');
                C--; B++;
            } else if (!C && B) {
                ans.push_back('C');
                C++; B--;
            } else if (c.empty()) {
                ans.push_back('B');
                C--; B++;
            } else if (b.empty()) {
                ans.push_back('C');
                B--; C++;
            } else if (c.front() <= b.front()) {
                ans.push_back('C');
                C++; B--;
            } else {
                ans.push_back('B');
                C--; B++;
            }
        }
    }
    
    cout << "Yes\n";
    for (auto& i : ans) cout << i << "\n";
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    ll T = 1; // cin >> T;
    while (T--) solve();
    return 0;
    // You should actually read the stuff at the bottom
}

/* Stuff to Look For
 * -----------------
 * Int overflow, array bounds
 * Initializing all variables, avoid weird behavior
 * Edge cases(n = 0, n = 1)
 * Just return 0 after result
 */
