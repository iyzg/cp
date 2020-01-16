#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    getline(cin, s);

    int digits[4];
    for (int i = 0; i < 4; i++)
    {
        digits[i] = ((int)s[i]) - ((int)'0');
    }

    bool YYMM = false, MMYY = false;
    int MMxx = digits[0] * 10 + digits[1], xxMM = digits[2] * 10 + digits[3];
    if (MMxx <= 12 && MMxx >= 1)
    {
        MMYY = true;
    }

    if (xxMM <= 12 && xxMM >= 1)
    {
        YYMM = true;
    }

    if (YYMM && MMYY)
    {
        cout << "AMBIGUOUS";
    } else if (YYMM && !MMYY)
    {
        cout << "YYMM";
    } else if (!YYMM & MMYY)
    {
        cout << "MMYY";
    } else {
        cout << "NA";
    }
}
