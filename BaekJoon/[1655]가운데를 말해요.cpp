#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int N,num;
/*
	�߰� ���� ã�� ��� : �ִ����� �ּ����� ����� �� ������ �ִ����� top ���� ���.
	1. �ִ����� ũ��� �ּ����� ũ�⺸�� ���ų� "1" Ŀ����.
	2. �ִ����� top�� �ּ����� top���� �۰ų� ���ƾ��Ѵ�.
*/
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	priority_queue<int, vector<int>> max_pq, min_pq;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		if (max_pq.size() > min_pq.size()) // �ִ����� ũ�ٸ� �ּ����� ����
			min_pq.push(-num);
		else
			max_pq.push(num);

		if (!max_pq.empty() && !min_pq.empty()) {
			if (max_pq.top() > -min_pq.top()) { // ���� �ּ����� top�� �ִ����� top���� ���� ��� �� ���� swap ����.
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