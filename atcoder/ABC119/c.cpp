#include <bits/stdc++.h>

using namespace std;

int main() {

    int N;
    vector<int> bamboo, lengths;
    cin >> N;
    int length;
    for (int i = 0; i < 3; i++)
    {
        cin >> length;
        lengths.push_back(length);
    }
    for (int i = 0; i < N; i++)
    {
        cin >> length;
        bamboo.push_back(length);
        if (find(lengths.begin(), lengths.end(), length) != lengths.end())
        {
            lengths.erase(find(lengths.begin(), lengths.end(), length));
            bamboo.erase(find(bamboo.begin(), bamboo.end(), length));
        }
    }

    sort(bamboo.begin(), bamboo.end(), greater<int>());
    sort(lengths.begin(), lengths.end(), greater<int>());

    int magic = 0;
    int current_magic = 0, current_length = 0;
    for (int i = 0; i < (int)lengths.size(); i++)
    {   
        current_length = current_magic = 0;
        // Don't forget to cover the edge case that you can't combine all the bamboo shoots into one or else this will fail, have to leave some behind
        for (int j = 0; j < (int)bamboo.size(); j++)
        {
            if (bamboo[j] > lengths[i] && bamboo[j] > 10)
                continue;
            
            // Remember to handle edge case that none of them are greater than 10
            if (current_length + bamboo[j] <= lengths[i] || lengths[i] - current_length > 10 + (current_length + bamboo[j] - lengths[i]))
            {
                if (current_length != 0)
                    current_magic += 10;

                cout << "Added Bamboo " << j << " to requirement " << lengths[i] << " which is " << bamboo[j] << " length\n";
                current_length += bamboo[j];
                bamboo.erase(find(bamboo.begin(), bamboo.end(), bamboo[j]));
                j--;

            }

            if (current_length == lengths[i])
            {
                break;
            }
        }

        // None of the shoots are over 10
        if (current_length == 0)
        {
            for (int j = 0; j < (int)bamboo.size(); j++)
            {
                if (bamboo[j] <= lengths[i])
                {
                    current_length += bamboo[j];
                    current_magic += 10;
                    bamboo.erase(find(bamboo.begin(), bamboo.end(), bamboo[j]));
                }
            }
        }

        cout << "Adding " << current_magic + abs(lengths[i] - current_length) << " to magic for requirement " << lengths[i] << "\n";
        magic += current_magic + abs(lengths[i] - current_length);
    }
        
    cout << magic;
}
