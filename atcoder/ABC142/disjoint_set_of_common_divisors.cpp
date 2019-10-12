#include <bits/stdc++.h>

using namespace std;

/* Plan
 * ----
 * Run through half of the smaller number to get al the common multiples, for each number check if its a divisor to both numbers
 * then check the corresponding larger multiple to see if it also works.
 *
 * The next step is to check how many are all coprimes of each other. We could use a loop
 */

// int main() {
    // long long int a, b;
    // vector<long long int> multiples;

    // cin >> a >> b;
    
    // multiples.push_back(1);
    // for (long long int i = 2; i <= sqrt(min(a, b)); i++)
    // {
        // if (a % i == 0 && b % i == 0)
        // {
            // bool coprime = true;
            // // Check if it's going to be co prime 
            // for (long unsigned int j = 1; j < multiples.size(); j++)
            // {
                // if (i % multiples[j] == 0) {
                    // coprime = false;
                    // break;
                // }
            // }
            
            // if (coprime) 
            // {
                // multiples.push_back(i);
            // }
        // }
    // }   

    // if (max(a, b) % (min(a, b) / multiples[multiples.size() - 1]) == 0 && multiples.size() != 1 && (min(a, b) / multiples[multiples.size() - 1]) != multiples[multiples.size() - 1])
    // {
        // bool coprime = true;
        // // Check if it's going to be co prime 
        // for (long unsigned int j = 1; j < multiples.size() - 1; j++)
        // {
            // if (min(a, b) / multiples[multiples.size() - 1] % multiples[j] == 0) {
                // coprime = false;
                // break;
            // }
        // }
        
        // if (coprime) 
        // {
            // multiples.push_back(min(a, b) / multiples[multiples.size() - 1]);
        // }
    // }
    
    // cout << multiples.size();
// }

long long gcd(long long a, long long b) {
	if (a < b) return gcd(b, a);
	if (b == 0) return a;
	return gcd(b, a % b);
}
bitset<1000001> bs;
vector<long long> primes;
void sieve() {
	bs.set();
	bs[0] = bs[1] = 0;
	for (long long i = 2; i <= 1000000; ++i) {
		if (bs[i]) {
			primes.push_back(i);
			for (long long j = i * i; j <= 1000000; j += i) bs[j] = 0;
		}
	}
}
int main() {
	sieve();
	long long A, B, ans = 1;
	scanf("%lld %lld", &A, &B);
	A = gcd(A, B);
	for (long long i: primes) {
		if (A % i == 0) ++ans;
		while (A % i == 0) A /= i;
	}
	if (A != 1) ++ans;
	printf("%lld", ans);
	return 0;
}
