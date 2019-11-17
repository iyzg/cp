#include <bits/stdc++.h>

using namespace std;

int main() {
    int lights[3][3] = 
    {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}
    };
    
    int input;
    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            cin >> input;
            if (input % 2 == 0)
            {
                continue;
            } else {
                if (lights[r][c] == 0)
                {
                    lights[r][c] = 1;
                } else {
                    lights[r][c] = 0;
                }

                if (r > 0)
                {
                    if (lights[r - 1][c] == 0)
                    {
                        lights[r - 1][c] = 1;
                    } else {
                        lights[r - 1][c] = 0;
                    }
                }
                if (r < 2)
                {
                    if (lights[r + 1][c] == 0)
                    {
                        lights[r + 1][c] = 1;
                    } else {
                        lights[r + 1][c] = 0;
                    }
                }
                if (c < 2)
                {
                    if (lights[r][c + 1] == 0)
                    {
                        lights[r][c + 1] = 1;
                    } else {
                        lights[r][c + 1] = 0;
                    }
                }
                if (c > 0)
                {
                    if (lights[r][c - 1] == 0)
                    {
                        lights[r][c - 1] = 1;
                    } else {
                        lights[r][c - 1] = 0;
                    }
                }
            }
        }
    }

    for(int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            cout << lights[r][c];
        }
        cout << "\n";
    }
}
