#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int N, card, answer;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	priority_queue<int, vector<int>, greater<int>> pq;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> card;
		pq.push(card);
	}
	while (pq.size() != 1) {
		int A = pq.top(); pq.pop();
		int B = pq.top(); pq.pop();
		
		answer += (A + B);
		pq.push(A + B);
	}
	cout << answer;
	return 0;
}