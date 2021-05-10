#include <iostream>
#include <queue>
#define INF 100001
using namespace std;
int N, K, answer;
bool visited[INF];

int solution(int start) {
	queue<pair<int,int>> q;
	if (start == K)
		return 0;
	q.push({ start,0 });
	visited[start] = true;
	while (!q.empty()) {
		int cur = q.front().first, time = q.front().second;
		q.pop();
		if ((cur * 2) < INF && !visited[cur * 2]) {
			if ((cur * 2) == K)
				return time;
			visited[cur * 2] = true;
			q.push({ cur * 2, time });
		}
		if (cur >= 1 && !visited[cur - 1]) {
			if ((cur - 1) == K)
				return time + 1;
			visited[cur - 1] = true;
			q.push({ cur - 1, time+1 });
		}
		if (cur < INF - 1 && !visited[cur + 1]) {
			if ((cur + 1) == K)
				return time + 1;
			visited[cur + 1] = true;
			q.push({ cur + 1, time+1 });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;

	cout << solution(N);

}