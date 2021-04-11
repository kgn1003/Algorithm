#include <iostream>
#include <queue>
#define MAX 100001
using namespace std;
int N, K, answer,cnt[MAX],flag;
bool visited[MAX];

void solution(int start, int dist[]) {
	queue<int> q;
	q.push(start);
	visited[start] = true;
	while (!q.empty()) {
		answer++;
		int q_size = q.size();
		for (int i = 0; i < q_size; i++) {
			int x = q.front();
			dist[2] = x;
			q.pop();
			visited[x] = true;
			for (int j = 0; j < 3; j++) {
				int nx = x + dist[j];

				if (nx == K) {
					cnt[nx]++;
					flag = true;
					continue;
				}
				if (nx >= 0 && nx < MAX && !visited[nx]) {
						q.push(nx);
				}
			}
		}
		if (flag)
			break;
	}
	cout << answer << '\n' << cnt[K];
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	int dist[] = { -1, 1 , N};
	if (N == K)
		cout << answer << '\n' <<1;
	else
		solution(N,dist);
	return 0;
}