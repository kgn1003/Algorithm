#include <iostream>
#include <queue>
#include <vector>
#define INF 1000000000
using namespace std;
vector<pair<int, int>> v[51];
int dist[51];

int solution(int N, vector<vector<int> > road, int K) {
	int answer = 0;
	for (int i = 0; i < road.size(); i++) {
		int s = road[i][0], e = road[i][1], d = road[i][2];
		v[s].push_back({ e,d });
		v[e].push_back({ s,d });
	}
	for (int i = 1; i <= N; i++) {
		dist[i] = INF;
	}

	queue<int> q;
	for (int i = 0; i < v[1].size(); i++) {
		int next = v[1][i].first, d = v[1][i].second;
		if (d > K)
			continue;
		dist[next] = d;
		q.push(next);
	}
	dist[1] = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].first, d = v[cur][i].second;
			if (dist[next] > dist[cur] + d && dist[cur] + d <= K) {
				dist[next] = dist[cur] + d;
				q.push(next);
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		if (dist[i] <= K)
			answer++;
	}
	return answer;
}