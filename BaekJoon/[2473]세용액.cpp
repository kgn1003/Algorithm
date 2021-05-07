#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define INF 100000000000

using namespace std;
long low_ans, mid_ans, high_ans;
int N;
vector <long> liquid;

void solution() {
	long ans = INF;
	for (int i = 0; i < N - 2; i++) {
		long low = liquid[i], mid = i+1, high = N - 1;
		while (mid < high)
		{
			long cmp = low + liquid[mid] + liquid[high];
			if (abs(cmp) < ans) { // ������ ������ ���� ���� ���� ������Ʈ
				ans = abs(cmp);
				low_ans = low;
				mid_ans = liquid[mid];
				high_ans = liquid[high];
			}
			if (cmp > 0) high--; // �� ����� ���� ����̸� �ִ밪�� ����
			else if( cmp < 0) mid++; // �� ����� ���� �����̸� �ּҰ��� ����
			else return; // 0�� ���°�� ���� ����
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long a;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a;
		liquid.push_back(a);
	}
	sort(liquid.begin(), liquid.end());
	solution();
	cout << low_ans << " " << mid_ans << " " << high_ans << endl;
	return 0;
}