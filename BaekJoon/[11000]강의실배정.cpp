#include <iostream>
#include <queue>
using namespace std;
int S, T, N;
struct cmp {
	bool operator()(pair<int, int> &a, pair<int, int> &b) {
		if (a.first == b.first)
			return a.second > b.second;
		else
			return a.first > b.first;
	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	priority_queue <pair<int, int>, vector<pair<int, int>>, cmp> pq;
	priority_queue <int, vector<int>, greater<int>> tq;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> S >> T;
		pq.push({ S,T });
	}
	while (!pq.empty())
	{
		int st = pq.top().first, et = pq.top().second;
		pq.pop();
		if (tq.empty()) {
			tq.push(et);
		}
		else {
			if (st >= tq.top()) {
				tq.pop();
				tq.push(et);
			}
			else {
				tq.push(et);
			}
		}
	}
	cout << tq.size();
	return 0;
}