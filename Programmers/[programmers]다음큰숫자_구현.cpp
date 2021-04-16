#include <string>
#include <vector>
using namespace std;

int convert_binary(int n) {
	string s = "";
	int cnt = 0;
	while (n != 0) {
		s = to_string(n % 2) + s;
		if (n % 2 == 1) cnt++;
		n /= 2;
	}
	return cnt;
}

int solution(int n) {
	int answer = 0;
	int start = convert_binary(n);
	for (int i = n + 1; ; i++) {
		int target = convert_binary(i);
		if (start == target) {
			answer = i;
			break;
		}
	}

	return answer;
}