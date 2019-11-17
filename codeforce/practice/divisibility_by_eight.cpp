#include <bits/stdc++.h>

using namespace std;

int main() {
    string num;
    getline(cin, num);
    char numDigits[num.length()];
    strcpy(numDigits, num.c_str());
    long long int converted = strtoll(numDigits, nullptr, 10);
    cout << converted;
    while (converted % 8 != 0)
    {
        for (int i = (int)num.size() - 1; i >= 0; i--)
        {
            if ((int)num[i] - (int)'0' % 2 == 1)
            {
                cout << "Erased " << (int)num[i] - (int)'0';
                num.erase(i, 1);
                break;
            }
        }
        converted = stoi(num);
    }
    cout << num;
}
