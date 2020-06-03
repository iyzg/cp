#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, a;
map<int, int> oc, ec;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (i % 2) oc[a]++;
		else ec[a]++;
	}
    
    int en, em = 0, on, om = 0;
    for (auto& i : ec) {
		if (i.second > em) {
			em = i.second;
			en = i.first;
		}
	}
    for (auto& i : oc) {
		if (i.second > om) {
			om = i.second;
			on = i.first;
		}
	}
	
	int es = 0, os = 0;
    for (auto& i : ec) {
		if (i.second > es && i.first != en) {
			es = i.second;
		}
	}
    for (auto& i : oc) {
		if (i.second > os && i.first != on) {
			os = i.second;
		}
	}
	
	if (en == on) {
		if (em + os > om + es) {
			om = os;
		} else {
			em = es;
		}
	}
	
    cout << n - em - om;
    return 0;
}
