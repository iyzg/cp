#include <bits/stdc++.h>

using namespace std;

bool sortcol( const vector<int>& v1, 
               const vector<int>& v2 ) { 
 return v1[1] < v2[1]; 
}

int main() {
    int N;
    cin >> N;
    
    set <int, int> deadlines;

    long long int input, second_input;
    for (int i = 0; i < N; i++)
    {
        cin >> input >> second_input;
        deadlines.insert(input, second_input);
    }

    sort (deadlines.begin(), deadlines.end());

    for (int i = 0; i < N; i++)
    {
    }
}
