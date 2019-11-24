    #include <bits/stdc++.h>
     
    using namespace std;
     
    int main() {
        int n; cin >> n;
        int a[n];
        for (int i = 0; i < n; ++i)
            cin >> a[i];
     
        bool reversed = false, already = false, possible = true;
        int start = 0, end = 0;
            
        for (int i = 0; i < n - 1; ++i)
        {
            if (reversed)
            {
                if (a[i] > a[i + 1])
                {
                    end++;
                    if (start > 0)
                    {
                        if (a[end] < a[start - 1]){
                            possible = false;
                            break;
                        }
                    }
                } else {
                    if (a[start] < a[i + 1])
                        reversed = false;
                    else {
                        possible = false;
                        break;
                    }
                }
            } else {
                if (a[i] > a[i + 1])
                {
                    if (already)
                    {
                        possible = false;
                        break;
                    } else {
                        already = true;
                        reversed = true;
                        start = i;
                        end = i + 1;
                    }
                }
            }
     
        }
        
        if (possible)
        {
            cout << "yes\n";
            cout << start + 1 << " " << end + 1;
        } else {
            cout << "no";
        }
    }
