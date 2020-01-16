#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    int students[N];

    int x;
    for (int i = 1; i < N + 1; i++) {
        cin >> x;
        
        students[x - 1] = i;
    }

    for (const int &student_number : students)
    {
        cout << student_number << " ";
    }
}
