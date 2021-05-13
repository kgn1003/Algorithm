#include <iostream>
#include <stack>
#include <vector>

using namespace std;
int N, h;
vector<int> answer;
stack<pair<int, int>> s;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> h;
		if (i == 0) {
			answer.push_back(0);
			s.push({ h,i + 1 });
		}
		else {
			while (!s.empty() && s.top().first <= h) { // ���� ž�� �߿��� ������ ū ���� ���ö����� pop()
				s.pop();
			}
			if (s.empty()) { // ���� ������ �������, ���簡 ���� ���� ž
				answer.push_back(0);
				s.push({ h,i + 1 });
			}
			else { // ���� ž���� ���� ž�� ������ �־���.
				answer.push_back(s.top().second);
				s.push({ h,i + 1 });
			}
		}
	}

	for (int i = 0; i < N; i++) {
		cout << answer[i] << " ";
	}
	return 0;
}