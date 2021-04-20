#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;
int answer, ate, cur_state = 2, N, map[21][21],f_size[7];
int dy[] = { 1,-1,0,0 }, dx[] = { 0,0,1,-1 };
bool visited[21][21];
pair<int, int> start;

bool cmp(pair<int, int> &a, pair<int, int> &b) {
	if (a.first == b.first)
		return a.second < b.second;
	else
		return a.first < b.first;
}

bool move(pair<int,int> s) {
	int temp = answer;
	bool flag = false;
	queue <pair<int, int>> q;
	vector<pair<int, int>> ans;
	q.push(s);
	//cout << s.first << " " << s.second << endl;
	while (!q.empty())
	{
		int q_size = q.size();
		//sort(q.begin(), q.end(), cmp);
		answer++;
		for (int i = 0; i < q_size; i++) {
			int y = q.front().first, x = q.front().second;
			q.pop();
			for (int j = 0; j < 4; j++) {
				int ny = y + dy[j], nx = x + dx[j];
				if (ny >= 1 && ny <= N && nx >= 1 && nx <= N && cur_state >= map[ny][nx] && !visited[ny][nx]) {
					if (map[ny][nx] != 0 && cur_state > map[ny][nx]) {
						ans.push_back({ ny,nx });
						visited[ny][nx] = true;
						flag = true;
						/*start.first = ny; start.second = nx;
						ate++;
						map[ny][nx] = 0;
						if (ate == cur_state) {
							ate = 0;
							cur_state++;
						}
						return false;*/
					}
					else {
						visited[ny][nx] = true;
						q.push({ ny,nx });
					}
				}
			}
		}
		if (flag) {
			sort(ans.begin(), ans.end(), cmp);
			start.first = ans[0].first; start.second = ans[0].second;
			ate++;
			map[ans[0].first][ans[0].second] = 0;
			if (ate == cur_state) {
				ate = 0;
				cur_state++;
			}
			return false;
		}
	/*	cout << endl;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cout << map[i][j] << " ";
			}
			cout << endl;
		}*/
	}
	/*cout << endl;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << visited[i][j] << " ";
		}
		cout << endl;
	}*/
	
	answer = temp;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				start.first = i;
				start.second = j;
				map[i][j] = 0;
				continue;
			}
			f_size[map[i][j]]++;
		}
	}

	while (true) {
		memset(visited, false, sizeof(visited));
		bool check = true;
		for (int i = 1; i < cur_state; i++) {
			if (f_size[i]) {
				check = false;
				break;
			}
		}
		if (check)
			break;
		if (move(start))
			break;

	}
	cout << answer;
	return 0;
}