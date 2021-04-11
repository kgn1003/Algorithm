#include <iostream>
using namespace std;

int Arr[1001], Dp[1001],N, answer;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> Arr[i];
	}
	Dp[0] = Arr[0];
	for (int i = 1; i < N; i++) {
		int sum = 0;
		for (int j = 0; j < i; j++) {
			if (Arr[j] > Arr[i]) {
				if (sum < Dp[j])
					sum = Dp[j];
			}
		}
		Dp[i] = sum + Arr[i];
		answer = answer > Dp[i] ? answer : Dp[i];
	}
	cout << answer;
	//int a;

	//for (int i = 0; i < N; i++) {
	//	cin >> a;
	//	if (len == 0) {
	//		Arr[len] = a;
	//		Dp[len++] = a;
	//	}
	//	else {
	//		if (Arr[len-1] < a) {
	//			int idx = binary_search(0, len-1, a);
	//			//cout << "a : " << a << " idx :" << idx << endl;
	//			//cout << "Dp[len-1] : " << Dp[len - 1] << " Dp[temp] - Arr[idx] + a " << Dp[len-1] - Arr[idx] + a << endl;
	//			if (Dp[len-1] < Dp[len-1] - Arr[idx] + a) {
	//			//	cout << Dp[len - 1] << " " << Dp[len-1] - Arr[temp] + a << endl;
	//				//Arr[temp] = a;
	//				if (len == 1 || idx == 0) {
	//					//Arr[idx] = a;
	//					Dp[idx] = a;
	//					len = 1;
	//				}
	//				else {
	//					//Arr[idx] = a;
	//					Dp[idx] = Dp[idx - 1] + a;
	//					len = idx+1;
	//				}
	//				Arr[idx] = a;
	//				//cout <<  "idx :"<< idx << " " <<Dp[idx] << endl;
	//			}
	//		}
	//		else {
	//			Arr[len] = a;
	//			Dp[len++] = Arr[len] + Dp[len - 1];
	//		}
	//	}
	//}
	///*for (int i = 0; i < len; i++) {
	//	cout << Dp[i] << " ";
	//}*/
	//cout << Dp[len-1];
	return 0;
}