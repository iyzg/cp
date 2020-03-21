#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N;
string in = "", lead = "";
ll zeroes = 0;
bool beautiful, found = false;

void input() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> N;
}

void solve() {
	input();
	for(int i = 0; i < N; i++)
	{
		cin >> in;
		if (in == "0") {
			lead = "";
			found = true;
			zeroes = 1;
			break;
		} else {
			beautiful = true;
			if (!found) {
				if (in[0] != '1') {
					beautiful = false;
					found = true;
					lead = in;
				} else {
					for(int j = 1; j < (int)in.size(); j++)
					{
						if (in[j] != '0') {
							beautiful = false;
							found = true;
							lead = in;
							break;
						}
					}
				}
			} 
			
			if (beautiful) zeroes += in.size() - 1;
		}
	}
	
	found ? cout << lead : cout << 1;
	for(ll i = 0; i < zeroes; i++) cout << 0;
			
}

int main() {
	solve();
    return 0;
}
