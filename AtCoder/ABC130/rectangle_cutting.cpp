#include <bits/stdc++.h>

using namespace std;

int main() {
    int W, H, x, y;
    
    scanf("%d%d%d%d", &W, &H, &x, &y);
    printf("%lf %d\n", double(W)*double(H) / 2, x + x == W && y + y == H);
}
