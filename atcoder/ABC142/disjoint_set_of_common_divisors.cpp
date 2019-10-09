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
    vector<int> multiples;

    cin >> a >> b;
    
    multiples.push_back(1);
    for (int i = 2; i < (min(a,b) / 2) + 1; i++)
    {
        if (a % i == 0 && b % i == 0 && find(multiples.begin(), multiples.end(), i) == multiples.end())
        {
            multiples.push_back(i);
            int ci = a / i;
            if (b % ci == 0 && find(multiples.begin(), multiples.end(), i) == multiples.end()) 
            {
                multiples.push_back(ci);
            }
        }
    }
    
    // Start at one because 1 will always be coprime, and index 1 because 0 would be 1
    int c = 1;
    for (int i = multiples.size() - 1; i > 0; i--)
    {
        bool is_coprime = true;
        for (int j = i - 1; j > 0; j--)
        {
            if (multiples[i] % multiples[j] == 0)
            {
                is_coprime = false;
                break;
            }
        }

        if (is_coprime)
        {
            c++;
        }
    }

    cout << c;
}
