#include <bits/stdc++.h>

using namespace std;

int main() {
    string input;
    getline(cin, input);
    
    long long int ways = 0;
    long long int count_in_row = 0;
    long long int dp[100000] = { 1, 2 };

    for (int i = 2; i < 100000; i++)
    {
        dp[i] = ((dp[i - 2] % (long long int)(pow(10, 9) + 7)) + (dp[i - 1] % (long long int)(pow(10, 9) + 7))) % (long long int)(pow(10, 9) + 7);
    }

    for(string::size_type character = 0; character < input.size(); character++)
    {
        if (input[character] == 'm' || input[character] == 'w')
        {
            cout << 0;
            return 0;
        }
        
        if (input[character] != 'w' && input[character] != 'u' && input[character] != 'm' && input[character] != 'n')
            continue;

        if (input[character] == 'u' && character != input.size() - 1 && input[character + 1] == 'u')
        {
            while(character < input.size() && input[character] == 'u')
            {
                count_in_row++;
                ++character;
            }
            
            character--;
            if (ways == 0)
            {
                ways += (dp[count_in_row - 1] % (long long int)(pow(10, 9) + 7));
            } else {
                ways = ((ways % (long long int)(pow(10, 9) + 7)) * (dp[count_in_row - 1] % (long long int)(pow(10, 9) + 7)) % (long long int)(pow(10, 9) + 7));
            }
            // cout << "Sequence of " << count_in_row << " U's finished, ways now equals " << ways << "\n";
            count_in_row = 0;
        } else if (input[character] == 'n' && character != input.size() - 1 && input[character + 1] == 'n') {
            while(character < input.size() && input[character] == 'n')
            {
                count_in_row++;
                ++character;
            }

            character--;
            
            if (ways == 0)
            {
                ways += (dp[count_in_row - 1] % (long long int)(pow(10, 9) + 7));
            } else {
                ways = ((ways % (long long int)(pow(10, 9) + 7)) * (dp[count_in_row - 1] % (long long int)(pow(10, 9) + 7)) % (long long int)(pow(10, 9) + 7));
            }
            // cout << "Sequence of " << count_in_row <<  " N's finished, ways now equals " << ways << "\n";
            count_in_row = 0;
        }
    }

    if (ways == 0)
    {
        cout << 1;
    } else {
        cout << ways;
    }
}
