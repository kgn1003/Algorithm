#include<iostream>
#include<vector>
using namespace std;
int N, M, answer, arr[501][501];
vector<vector<pair<int, int>>> v[5] = 
{ 
{ { {0,1},{0,2},{0,3} },{ {1,0},{2,0},{3,0} } }, // 긴막대기
{{ {0,1},{1,0},{1,1} }}, //사각형
{{{1,0},{2,0},{2,1}}, {{0,1},{0,2},{-1,2}},{{-1,0},{-2,0},{-2,-1}},{{0,-1},{0,-2},{1,-2}},
{{1,0},{2,0},{2,-1}}, {{0,1},{0,2},{1,2}},{{-1,0},{-2,0},{-2,1}},{{0,-1},{0,-2},{-1,-2}}}, // 7 모양
{{ {0,1},{1,0},{0,-1} },{ {-1,0},{0,1},{1,0} },{ {0,-1},{-1,0},{0,1} },{ {-1,0},{0,-1},{1,0} }}, // 볼록모양
{{{1,0},{1,1},{2,1}},{{0,1},{-1,1},{-1,2}},{{-1,0},{-1,-1},{-2,-1}},{ {0,-1},{1,-1},{1,-2}},
{{1,0},{1,-1},{2,-1}},{{0,1},{1,1},{1,2}},{{-1,0},{-1,1},{-2,1}},{ {0,-1},{-1,-1},{-1,-2}}}
}; // 지그재그

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < v[i].size(); j++) {
					int sum = 0;
					bool flag = true;
					for (int k = 0; k < v[i][j].size(); k++) {
						int ny = y + v[i][j][k].first, nx = x + v[i][j][k].second;
						if (ny >= 1 && ny <= N && nx >= 1 && nx <= M) {
							sum += arr[ny][nx];
						}
						else {
							flag = false;
							break;
						}
					}
					if (flag) {
						sum += arr[y][x];
						if (answer < sum) {		
							answer = sum;
						}
					}
				}
			}
		}
	}
	cout << answer;
	return 0;
}