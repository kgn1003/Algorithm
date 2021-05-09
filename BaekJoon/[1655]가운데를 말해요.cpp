#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int N,num;
/*
	중간 값을 찾는 방법 : 최대힙과 최소힙을 만들어 매 순간의 최대힙의 top 값을 출력.
	1. 최대힙의 크기는 최소힙의 크기보다 같거나 "1" 커야함.
	2. 최대힙의 top은 최소힙의 top보다 작거나 같아야한다.
*/
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	priority_queue<int, vector<int>> max_pq, min_pq;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		if (max_pq.size() > min_pq.size()) // 최대힙이 크다면 최소힙에 삽입
			min_pq.push(-num);
		else
			max_pq.push(num);

		if (!max_pq.empty() && !min_pq.empty()) {
			if (max_pq.top() > -min_pq.top()) { // 만약 최소힙의 top이 최대힙의 top보다 작은 경우 두 값을 swap 해줌.
				int max_top = max_pq.top();
				int min_top = -min_pq.top();
				
				max_pq.pop(); min_pq.pop();
				
				max_pq.push(min_top);
				min_pq.push(-max_top);
			}
		}

		cout << max_pq.top() << "\n";
	}
	return 0;
}