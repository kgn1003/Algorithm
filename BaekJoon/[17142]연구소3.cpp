#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#define INF 10000000
using namespace std;
int N, M, init_cnt, answer = INF, map[51][51];
int dy[] = { 1,-1,0,0 }, dx[] = { 0,0,1,-1 };
bool visited[51][51];
vector <pair<int, int>> v;
vector <int> comb;

int BFS(vector<pair<int,int>> start) {
	queue<pair<int, int>> q;
	int virus_cnt = init_cnt;
	int time = 0;
	int v_size = start.size();
	for (int i = 0; i < v_size; i++) {
		q.push(start[i]);
	}
	while (!q.empty())
	{
		int q_size = q.size();
		time++;
		for (int i = 0; i < q_size; i++) {
			int y = q.front().first, x = q.front().second;
			visited[y][x] = true;
			q.pop();

			for (int j = 0; j < 4; j++) {
				int ny = y + dy[j], nx = x + dx[j];

				if (ny >= 1 && ny <= N && nx >= 1 && nx <= N 
					&& !visited[ny][nx] && map[ny][nx] != 1) {
					if (map[ny][nx] == 2) {
						visited[ny][nx] = true;
						q.push({ ny,nx });
					}
					else {
						visited[ny][nx] = true;
						virus_cnt--;
						if (virus_cnt == 0) {
							return time;
						}
						q.push({ ny,nx });
					}
				}
				
			}
		}
	}

		return INF;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				v.push_back({ i,j });
			}
			else if (map[i][j] == 0) {
				init_cnt++;
			}
		}
	}
	if (init_cnt == 0) {
		cout << 0;
	}
	else {
		int v_size = v.size();
		for (int i = 0; i < v_size - M; i++) {
			comb.push_back(0);
		}
		for (int i = 0; i < M; i++) {
			comb.push_back(1);
		}

		do {
			int cnt = 0;
			vector<pair<int, int>> start;
			for (int i = 0; i < v_size; i++) {
				if (comb[i]) {
					start.push_back(v[i]);
					cnt++;
					if (cnt == M)
						break;
				}
			}
			int tmp = BFS(start);
			memset(visited, false, sizeof(visited));
			answer = answer < tmp ? answer : tmp;
		} while (next_permutation(comb.begin(), comb.end()));

		if (answer == INF)
			cout << -1;
		else
			cout << answer;
	}
	
	return 0;
}