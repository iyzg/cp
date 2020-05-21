#include <bits/stdc++.h>

using namespace std;

int N, M, A, B;
long long ans;
// Store only the payout since we'll make sure it finishes before
priority_queue<int> highestPayingJobs; 
// Days it takes and payout
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> jobs;

int main() {
    cin >> N >> M;
	for(int i = 0; i < N; i++) {
		cin >> A >> B;
		jobs.push(make_pair(A, B));
	}
	
	for(int daysBefore = 1; daysBefore <= M; daysBefore++) {
		while (!jobs.empty() && jobs.top().first <= daysBefore) {
			highestPayingJobs.push(jobs.top().second);
			jobs.pop();
		}
		
		if (!highestPayingJobs.empty()) {
			ans += highestPayingJobs.top();
			highestPayingJobs.pop();
		}
	}
	
	cout << ans;
}
