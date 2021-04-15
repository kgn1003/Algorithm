#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(int n) {
	string answer = "";
	string number[] = { "4","1","2" };
	while (n) {
		answer = number[n % 3] + answer;
		if (n % 3 == 0)
			n = (n / 3) - 1;
		else
			n = (n / 3);
	}
	return answer;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	cout << solution(n);
	return 0;
}