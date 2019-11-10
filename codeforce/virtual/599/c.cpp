#include <bits/stdc++.h>

using namespace std;

int main() {
    long long int n;
    cin >> n;

    /*
     * Idea for how to solve C
     * First find the factors of n
     * Have a bitset representing whether a tile is colored or not
     * Start with first tile, increment up smallest factor (might have to be largest valid factor that way we can get the maximum number of colors to use) 
     * that's not 1 and set it as colored and increment color count by 1. 
     * You can do this by finding the factors of the number, sort, then loop down to find the largest valid factor. If this ends up being 1, just return the
     * number of tiles as each tile can be uniquelly colored.
     * If the tile is already colored, skip it.
     *
     * 
     */
}
