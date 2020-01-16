#include <bits/stdc++.h>

using namespace std;
    
bitset<1000001> sieve;
vector<long long> primes;

long long gcd(long long a, long long b) {
	if (a < b) return gcd(b, a);
	if (b == 0) return a;
	return gcd(b, a % b);
}

void find_primes()
{
    sieve.set();
    for (long long int i = 2; i < 1000000; i++)
    {
        if (sieve[i])
        {
            primes.push_back(i);
            for (int j = i * 2; j < 1000000; j += i) sieve[j] = 0;
        }
    }
}

int main() {
    find_primes();
    long long A, B, ans = 1;
    cin >> A >> B;
    
    A = gcd(A, B);
    for (long long i : primes)
    {
        if (A % i == 0) ++ans;
        while (A % i == 0) A /= i;
    }

    if (A != 1) ++ans;
    cout << ans;
}
