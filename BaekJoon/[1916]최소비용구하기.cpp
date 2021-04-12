#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 100001
using namespace std;
int N, M,s,e,d, answer[1001];
vector <pair<int, int>> v[1001];

struct cmp{
	bool operator()(pair<int, int> &a, pair<int, int> &b){
		if (a.first == b.first)
			return a.second < b.second;
		else
			return a.first < b.first;
	}
};

int solution(int start,int dest) {
	priority_queue <pair<int, int>, vector<pair<int, int>>> pq;
	answer[start] = 0;
	pq.push({ start,0 });
	while (!pq.empty()) {
		int cur = pq.top().first;
		int dist = -pq.top().second;
		pq.pop();
		if (answer[cur] < dist) continue;
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].first;
			int next_dist = dist + v[cur][i].second;
			if (answer[next] > next_dist) {
				//cout << "cur " << cur << " nxt " << next << " n_dist " << next_dist << endl;
				answer[next] = next_dist;
				pq.push({ next,-next_dist });
			}
		}
	}

	return answer[dest];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	fill(&answer[1], &answer[N+1], INF);
	int start, dest;
	for (int i = 0; i < M; i++) {
		cin >> s >> e >> d;
		v[s].push_back({ e,d });
	}
	cin >> start >> dest;
	cout << solution(start,dest);
	return 0;
}