#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, map[17][17];
int dy[] = {0,1,0,1,1}, dx[] = {1,0,1,0,1}, answer;
int solution(pair<pair<int,int>,int> start) {
	queue <pair<pair<int, int>, int>> q;
	q.push(start);
	while (!q.empty()) {
		int q_size = q.size();
		for (int i = 0; i < q_size; i++) {
			int y = q.front().first.first, x = q.front().first.second, ny,nx;
			int state = q.front().second;
			q.pop();
			if (state == 0) {
					ny = y + dy[state]; nx = x + dx[state];
					if (ny >= 1 && ny <= N && nx >= 1 && nx <= N && !map[ny][nx]) {
						if (ny == N && nx == N) {
							answer++;
						}
						else {
							q.push({ {ny,nx},0 });
						}
					}
				
			}
			else if (state == 1) {
					ny = y + dy[state]; nx = x + dx[state];
					if (ny == N && nx == N && !map[ny][nx]) {
						answer++;
						break;
					}
					if (ny >= 1 && ny <= N && nx >= 1 && nx <= N && !map[ny][nx]) {
						if (ny == N && nx == N) {
							answer++;
						}
						else {
							q.push({ {ny,nx},1 });
						}
					}
				
			}
			else {
				for (int j = 0; j < 2; j++) {
					ny = y + dy[j]; nx = x + dx[j];
					if (ny >= 1 && ny <= N && nx >= 1 && nx <= N && !map[ny][nx]) {
						if (ny == N && nx == N) {
							answer++;
						}
						else {
							q.push({ {ny,nx},j });
						}
					}
				}
			}
			bool check = true;
			for (int j = 2; j < 5; j++) {
				ny = y + dy[j]; nx = x + dx[j];
				if (ny >= 1 && ny <= N && nx >= 1 && nx <= N && !map[ny][nx]);
				else {
					check = false;
					break;
				}
			}
			if (check) {
				if (ny == N && nx == N && !map[ny][nx]) {
					answer++;
				}
				else
					q.push({ {ny,nx},2 });
			}
		}
	}
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}
	cout << solution({ {1,2},0 });
}