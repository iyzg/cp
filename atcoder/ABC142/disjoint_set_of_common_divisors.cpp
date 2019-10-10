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
    int a, b;
    vector<long long int> multiples;

    cin >> a >> b;
    
    multiples.push_back(1);
    int c = 1;
    for (long long int i = 2; i < min(a,b) + 1; i++)
    {
        if (a % i == 0 && b % i == 0 && find(multiples.begin(), multiples.end(), i) == multiples.end())
        {
            multiples.push_back(i);
            
            bool coprime = true;
            // Check if it's going to be co prime 
            for (long long int j = 1; j < multiples.size() - 2; j++)
            {
                if (i % multiples[j] == 0) {
                    coprime = false;
                    break;
                }
            }

            if (coprime) 
            {
                c++;
            }
        }
    }
    
    cout << c;
}
