#include <bits/stdc++.h>

using namespace std;

int main() {
    char steps[100];
    cin >> steps;
    
    
    bool easy = true;
    for (int i = 0; i < strlen(steps); i++)
    {
        if (i % 2 != 0)
        {
            if (steps[i] != 'L' && steps[i] != 'U' && steps[i] != 'D') {
                easy = false; 
                break;
            }
        } else {
            if (steps[i] != 'R' && steps[i] != 'U' && steps[i] != 'D') {
                easy = false;
                break;
            }
        }
    }
    
    if (easy) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}
