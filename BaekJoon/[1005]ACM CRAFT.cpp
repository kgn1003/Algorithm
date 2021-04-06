#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int T, N, K, W,entry[1001],time[1001], answer[1001];
vector<long long> v[1001];

int solution() {
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (entry[i] == 0) {
			q.push(i);
			answer[i] = time[i];
		}
	}
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];
			answer[next] = answer[next] > answer[cur] + time[next] ? answer[next] : answer[cur] + time[next];
			entry[next]--;
			if (entry[next] == 0) q.push(next);
		}
	}
	return answer[W];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N >> K;
		for (int j = 0; j < 1001; j++)
			v[i].clear();
		memset(answer, 0, sizeof(answer));
		memset(time, 0, sizeof(time));
		memset(entry, 0, sizeof(entry));
		
		for (int j = 1; j <= N; j++)
			cin >> time[j];

		for (int j = 0; j < K; j++) {
			int x, y;
			cin >> y >> x;
			v[y].push_back(x);
			entry[x]++;
		}
		cin >> W;
		cout << solution() << '\n';
	}
	return 0;
}