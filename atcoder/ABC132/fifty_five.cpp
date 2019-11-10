#include <bits/stdc++.h>

using namespace std;

int main() {
    char s[10];
    scanf("%s",s);
    sort(s,s+ 4);
    printf((s[0] ==s[1] &&s[1] !=s[2] &&s[2] ==s[3])? "Yes\n" : "No\n");
}
