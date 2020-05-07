#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld; 
typedef double db; 
typedef string str; 

typedef pair<int, int> pi;
typedef pair<ll,ll> pl; 
typedef pair<ld,ld> pd; 

typedef vector<int> vi; 
typedef vector<ll> vl;
typedef vector<ld> vd; 
typedef vector<str> vs; 
typedef vector<pi> vpi;
typedef vector<pl> vpl; 

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound 
#define ub upper_bound 

const int MOD = 998244353;
const ll INF = 1e18;
const int MX = 1000001;

namespace io {
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0);
        if (s.size()) { setIn(s+".in"), setOut(s+".out"); }
    }
}

using namespace io;

ll N, A, B, ans = 1, maxB = -INF, maxBI;

int main() {
	// setIO("moop");
    cin >> N;
    vpl particles;
    vl prefMin(N), suffMax(N);
    vl sections;
    
    F0R(i, N) {
        cin >> A >> B;
        particles.pb(mp(A, B));
    }
    sort(all(particles));
  
    maxB = particles[0].s;
    maxBI = 0;
    prefMin[0] = particles[0].s;
    FOR(i, 1, N) {
        if (particles[i].s >= maxB) {
            maxB = particles[i].s;
            maxBI = i;
        }
        prefMin[i] = min(prefMin[i - 1], particles[i].s);
    }
    
    // Index of largest 
    suffMax[N - 1] = N - 1;
    R0F(i, N - 1) {
        particles[i].s > particles[suffMax[i + 1]].s ? suffMax[i] = i : suffMax[i] = suffMax[i + 1];
    }
    
    
    ll end = maxBI;
    ll lastEnd = INF;
    bool jumped = false;
    while(end < N - 1) {
        // Assimilate the ones where the Bs are >= min
        FOR(j, end + 1, N) {
            if (particles[j].s >= prefMin[end]) end++;
            else break;
        }
        
        if (!sz(sections)) {
            sections.pb(prefMin[end]);
        } else {
            // cout << lastEnd << " " << end << "\n";
            ll minOverLast = INF;
            FOR(i, lastEnd + 1, end + 1) {
                if (particles[i].s < minOverLast && particles[i].s >= sections[sz(sections) - 1]) {
                    minOverLast = particles[i].s;
                }
            }
            
            if (minOverLast == INF) {
                sections.pb(prefMin[end]);
            } else {
                sections.pb(minOverLast);
            }
        }
        
        if (end < N - 1) {
            // find new end
            int newEnd = suffMax[end + 1];
            // cout << "SET END TO " << newEnd << "\n";
            lastEnd = end;
            end = newEnd;
            jumped = true;
        }
    }
    
    if (jumped) {
        ll minOverLast = INF;
        // cout << lastEnd << " " << end << "\n";

        FOR(i, lastEnd + 1, end + 1) {
            if (particles[i].s < minOverLast && particles[i].s >= sections[sz(sections) - 1]) {
                minOverLast = particles[i].s;
            }
        }
        
        if (minOverLast == INF) {
            sections.pb(prefMin[end]);
        } else {
            sections.pb(minOverLast);
        }
    }
    
    FOR(i, 1, sz(sections)) {
        // Also try without changing it 
        if (sections[i - 1] <= sections[i]) {
            sections[i] = sections[i - 1];
        } else {
            ans++;
        }
    }
    
    // trav(i, sections) cout << i << " ";
    // cout << "\n";
    cout << ans << "\n";
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
