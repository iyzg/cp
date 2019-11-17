#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    set<int> in_office, entered_today;
    int days_needed = 0;
    vector<int> events;
    int input, last_event = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        if (input > 0)
        {
            if (entered_today.find(input) != entered_today.end() || !in_office.insert(input).second)
            {
                cout << "-1";
                return 0;
            } else {
                entered_today.insert(input);
            }
        } else {
            int number = input * -1;
            set<int>::iterator it = in_office.find(number);
            if (it == in_office.end()) {
                cout << "-1";
                return 0;
            } else {
                in_office.erase(it);
                if (in_office.empty())
                {
                    entered_today.clear();
                    days_needed++;
                    events.push_back(i - last_event);
                    last_event = i;
                }
            }
        }
    }

    if (!in_office.empty())
    {
        cout << "-1";
        return 0;
    } else {
        cout << days_needed << "\n";
        for (int i = 0; i < (int)events.size(); i++)
        {
            cout << events[i] << " ";
        }
    }
}
