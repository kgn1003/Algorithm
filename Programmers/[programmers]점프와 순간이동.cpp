#include <iostream>
using namespace std;

int solution(int n)
{
	int ans = 0;
	while (true) {
		if (n % 2) {
			ans++;
			if (n / 2) {
				n /= 2;
			}
			else {
				break;
			}
		}
		else {
			n /= 2;
		}
	}

	return ans;
}