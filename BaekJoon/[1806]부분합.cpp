//#include <iostream>
//#include <vector>
//#define MAX 100000
//using namespace std;
//int N, S, answer= MAX, Arr[100001];
//
//int solution() {
//	int start = 0, end = 0, sum = Arr[0];
//	while (true) {
//		if (sum >= S) {
//			answer = answer < end - start + 1 ? answer : end - start + 1;
//			sum -= Arr[start++];
//		}
//		else {
//			sum += Arr[++end];
//		}
//		if (end == N)
//			break;
//	}
//	return answer = answer == MAX ? 0 : answer;
//}
//
//int main() {
//	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	cin >> N >> S;
//	for (int i = 0; i < N; i++) {
//		cin >> Arr[i];
//	}
//	cout << solution();
//	return 0;
//}