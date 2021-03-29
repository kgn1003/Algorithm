#include <iostream>

using namespace std;
int N, step[310], point_1[310], point_2[310];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> step[i];
	}
	point_1[1] = step[1]; point_2[1] = step[1];
	for (int i = 2; i <= N; i++) {
		point_1[i] = (point_1[i - 2] > point_2[i - 2] ? point_1[i - 2] : point_2[i - 2]) + step[i];
		point_2[i] = point_1[i - 1] + step[i];
	}

	cout << (point_1[N] > point_2[N] ? point_1[N] : point_2[N]) << "\n";
	return 0;
}