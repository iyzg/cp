#include <bits/stdc++.h>

using namespace std;

// long long int fri(long long int n)
// {
    // return (n == 1 || n == 0) ? n : n + fri(n - 1);
// }

// int main() {
    // long long int n, m; cin >> n >> m;
    
    // if (n % m == 0)
    // {
        // cout << fri((n / m) - 1) * m;
    // } else {
        // long long int friends = 0;
        // long long int tn = n;
        // for (long long int i = m; i > 0; --i)
        // {
            // long long int gs = ceil((long double)tn / i);
            // friends += fri(gs - 1);
            // tn -= gs;
        // }
        // cout << friends;
    // }

    // cout << " ";
    // // max
    // cout << fri(n - m);
// }

long long n,m;
 
int main(){
    cin>>n>>m;
    cout<<(n/m)*(n/m-1)/2*(m-n%m)+(n/m+1)*(n/m)/2*(n%m)<<' '<<(n-m+1)*(n-m)/2<<endl;
    return 0;
}
