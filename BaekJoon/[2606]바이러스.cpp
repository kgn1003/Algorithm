#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int N, com, answer, ans;
bool visited[101], check[101];
vector <int> v[101];

int DFS(int start) {
	check[start] = true;
	for (int i = 0; i < v[start].size(); i++) {
		int next = v[start][i];
		if (check[next] == false) {
			ans++;
			DFS(next);
		}
	}
	return ans;
}

int BFS(int virus) {
	queue <int> q;
	q.push(virus);
	while (!q.empty()) {
		int q_size = q.size();
		for (int i = 0; i < q_size; i++) {
			int start = q.front();
			q.pop();
			for (int j = 0; j < v[start].size(); j++) {
				int next = v[start][j];
				if (visited[next] == false) {
					visited[next] = true;
					q.push(next);
					answer++;
				}
			}
		}
	}
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> com;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	visited[1] = true;
	cout << BFS(1) << "\n";
	cout << DFS(1);
}