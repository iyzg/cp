#include <bits/stdc++.h>

using namespace std;

/* Plan
 * ----
 * Run through half of the smaller number to get al the common multiples, for each number check if its a divisor to both numbers
 * then check the corresponding larger multiple to see if it also works.
 *
 * The next step is to check how many are all coprimes of each other. We could use a loop
 */

int main() {
    long long int a, b;
    vector<long long int> multiples;

    cin >> a >> b;
    
    multiples.push_back(1);
    for (long long int i = 2; i <= sqrt(min(a, b)); i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            bool coprime = true;
            // Check if it's going to be co prime 
            for (long unsigned int j = 1; j < multiples.size(); j++)
            {
                if (i % multiples[j] == 0) {
                    coprime = false;
                    break;
                }
            }
            
            if (coprime) 
            {
                multiples.push_back(i);
            }
        }
    }
    
    cout << multiples.size();
}
