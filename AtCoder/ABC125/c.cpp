#include <iostream>
#include <vector>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
 
int gcd(int x, int y) {
  if (y == 0) return x;
  return gcd(y, x%y);
}
 
int main() {
  int n;
  cin>>n;
  vector<int> a(n);
  rep(i,n) cin>>a[i];
  vector<int> l(n), r(n);
  rep(i,n-1) l[i+1] = gcd(l[i], a[i]);
  for (int i = n-1; i >= 1; --i) r[i-1] = gcd(r[i], a[i]);
  int ans = 1;
  rep(i,n) ans = max(ans, gcd(l[i],r[i]));
  cout<<ans<<endl;
  return 0;
}
