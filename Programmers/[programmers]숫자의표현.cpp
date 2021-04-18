#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	int answer = 0, start = 1;
	while (start <= n)
	{
		int sum = 0;
		for (int i = start; sum <= n; i++)
		{
			if (sum == n)
				answer++;
			sum += i;
		}
		start++;
	}
	return answer;
}