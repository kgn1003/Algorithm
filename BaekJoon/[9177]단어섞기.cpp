#include <iostream>
#include <string>
#include <cstring>
#include <queue>
using namespace std;
int N;
bool visited[201][201];
bool solutionn(string str1, string str2, string target) {
	queue<pair<pair<int, int>, int>> q;
	visited[0][0] = true;
	q.push({ {0,0},0 });
	while (!q.empty()) {
		int s1 = q.front().first.first, s2 = q.front().first.second;
		int t = q.front().second;
		q.pop();
		if (t == target.size()) {
			return true;
		}
		if (!visited[s1 + 1][s2] && str1[s1] == target[t]) {
			visited[s1 + 1][s2] = true;
			q.push({ {s1 + 1,s2},t + 1 });
		}
		if (!visited[s1][s2 + 1] && str2[s2] == target[t]) {
			visited[s1][s2+1] = true;
			q.push({ {s1,s2+1},t + 1 });
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		memset(visited, false, sizeof(visited));
		string s1="", s2="", target="";
		cin >> s1 >> s2 >> target;
		if (solutionn(s1, s2, target)) {
			cout << "Data set " << i + 1 << ": " << "yes\n" ;
		}
		else {
			cout << "Data set " << i + 1 << ": " << "no\n";
		}
	}
	return 0;
}
