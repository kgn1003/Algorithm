#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;
int N, H;
int top[MAX], bottom[MAX], init_cnt = MAX + MAX, answer;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> H;

	for (int i = 0; i < N / 2; i++)
		cin >> bottom[i] >> top[i];

	sort(bottom, bottom + N / 2);
	sort(top, top + N / 2);


	for (int i = 1; i <= H; i++) {
		int cnt = 0;
		cnt = (N / 2) - (lower_bound(bottom, bottom + (N / 2), i) - bottom);
		cnt += (N / 2) - (upper_bound(top, top + (N / 2), H - i) - top);
		if (init_cnt == cnt) {
			answer++;
		}
		else if (init_cnt > cnt) {
			init_cnt = cnt;
			answer = 1;
		}
	}
	cout << init_cnt << " " << answer;
	return 0;
}