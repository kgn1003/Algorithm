#include <iostream>
#include <queue>

using namespace std;

struct cmp {
	bool operator()(int a, int b) {
		return a > b;
	}
};

int N, num;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	priority_queue <int, vector<int>,cmp> pq;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> num;
			pq.push(num);
		}
		if (pq.size() > N) {
			for (int i = 0; i < N; i++) {
				pq.pop();
			}
		}
	}
	
	cout << pq.top();
	return 0;
}

/////*vector sort and erase*//////////

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v;
int N, num;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> num;
			v.push_back(num);
		}
		sort(v.begin(), v.end(),greater<int>());
		if (v.size() > N) {
			v.erase(v.begin() + N, v.end());
		}
	}
	
	cout << v[N - 1];
	return 0;
}
