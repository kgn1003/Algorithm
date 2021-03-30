#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
	return a.first < b.first;
}
int T, N;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--) {
		vector <pair<int, int>> v1;
		vector <pair<int, int>> v2;
		cin >> N;
		int answer = N;
		for (int i = 0; i < N; i++) {
			int a, b;
			cin >> a >> b;
			v1.push_back({ a,i });
			v2.push_back({ b,i });
		}
		sort(v1.begin(), v1.end(), cmp);
		int target = v2[v1[0].second].first;
		for (int i = 1; i < N; i++) {
			if (target > v2[v1[i].second].first) {
				target = v2[v1[i].second].first;
			}
			else {
				answer--;
			}
		}
		cout << answer << '\n';
	}
}