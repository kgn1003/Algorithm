#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int V, E, v1, v2, w, answer;
vector <pair<int,int>> vec[10001];
bool visited[10001];

struct cmp {
	bool operator()(pair<int, int> &a, pair<int, int> &b) {
		if (a.second == b.second)
			return a.first > b.first;
		else
			return  a.second > b.second;
	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	priority_queue <pair<int, int>, vector<pair<int, int>>, cmp> pq;
	//int cur, next, weight = 1000001;
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		cin >> v1 >> v2 >> w;
		vec[v1].push_back({ v2,w });
		vec[v2].push_back({ v1,w });
	}
	visited[1] = true;
	for (int i = 0; i < vec[1].size(); i++) {
		int next = vec[1][i].first, next_w = vec[1][i].second;
		pq.push({ next,next_w });
	}
	V--;
	while(V){
		int cur = pq.top().first, weight = pq.top().second;
		pq.pop();
		if (!visited[cur]) {
			V--;
			answer += weight;
			visited[cur] = true;
			for (int i = 0; i < vec[cur].size(); i++) {
				int next = vec[cur][i].first, next_w = vec[cur][i].second;
				if (!visited[next]) {
					pq.push({ next,next_w });
				}
			}
		}
	}
	


	//pq.push({next,weight});
	////int cur = pq.top().first.first, next = pq.top().first.second, weight = pq.top().second;
	//visited[cur] = true;
	//answer += weight;
	////visited[1] = true;
/*
	while (!pq.empty())
	{
		int current = pq.top().first, c_weight = pq.top().second;
		pq.pop();
		for (int i = 0; i < vec[current].size(); i++) {
			int next = vec[current][i].first, n_weight = vec[current][i].second;
			if (visited[next])
				continue;
			answer += n_weight;
			pq.push({ next,n_weight });
			visited[next] = true;
		}
	}*/
	cout << answer;
	return 0;
}