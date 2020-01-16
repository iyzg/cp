#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    long long int N;
    cin >> N;
    long long int times[5];
    long long int capacity[5];
 
    for(int i = 0; i < 5; i++)
    {
        cin >> capacity[i];
    }
 
    times[0] = ceil((long double)N / (long double)capacity[0]);
    for(int i = 1; i < 5; i++)
    {
        times[i] = ceil((long double)N / (long double)capacity[i]);
    }
 
    for (int i = 4; i >= 1; i--)
    {
        if (times[i] <= times[i - 1])
        {
            times[i] = 1;
        } else {
            times[i] = times[i] - times[i - 1] + 1;
        }
    }
 
    long long int ans = 0;
    for (int i = 0; i < 5; i++)
    {
        ans += times[i];
    }
 
    cout << ans;
}
