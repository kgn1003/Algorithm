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
			while (!s.empty() && s.top().first <= h) { // 이전 탑들 중에서 나보다 큰 값이 나올때까지 pop()
				s.pop();
			}
			if (s.empty()) { // 만약 스택이 비었으면, 현재가 제일 높은 탑
				answer.push_back(0);
				s.push({ h,i + 1 });
			}
			else { // 현재 탑보다 높은 탑의 정보를 넣어줌.
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