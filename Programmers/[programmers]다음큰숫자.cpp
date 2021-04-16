#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n) {
	int answer = 0;
	string binary_n = "", ans = "";
	int cnt = 0;
	while (n != 0) {
		binary_n = to_string(n % 2) + binary_n;
		if (n % 2 == 1) cnt++;
		n /= 2;
	}
	if (next_permutation(binary_n.begin(), binary_n.end())) {
		ans = binary_n;
	}
	else {
		string tmp = "";
		for (int i = 0; i < binary_n.length(); i++) {
			if (cnt > 1) {
				tmp = '1' + tmp;
				cnt--;
			}
			else {
				tmp = '0' + tmp;
			}
		}
		ans = '1' + tmp;
	}
	for (int i = ans.length() - 1; i >= 0; i--) {
		answer += (ans[i] - '0') * pow(2, (ans.length() - i) - 1);
	}
	return answer;
}