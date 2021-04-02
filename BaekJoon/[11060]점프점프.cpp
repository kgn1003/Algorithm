#include <iostream>
#define MAX_LEN 10000
using namespace std;
int N, dist[1001], answer[1001];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> dist[i];
	}
	for (int i = 1; i <= N - 1; i++)
		answer[i] = MAX_LEN;

	int start = 0, max_range = start + dist[0];
	
	while (start <= max_range) {
		for (int i = 1; i <= dist[start]; i++) {
			if (start + i >= N) {
				answer[N - 1] = answer[N - 1] < answer[start] + 1 ? answer[N - 1] : answer[start] + 1;
			}
			else
				answer[start + i] = answer[start + i] < answer[start] + 1 ? answer[start + i] : answer[start] + 1;
			if (start + dist[start + i] > max_range && max_range != N-1) {
				max_range = start + dist[start + i] + 1;
				if (max_range >= N - 1)
					max_range = N - 1;
			}
		}
		start++;
	}


	if (answer[N - 1] == MAX_LEN)
		cout <<- 1;
	else
		cout << answer[N-1];
	return 0;
}