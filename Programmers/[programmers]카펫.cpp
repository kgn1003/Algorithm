#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
	vector<int> answer;
	for (int i = yellow; i >= (yellow / i); i--) {
		if (yellow % i != 0) continue;
		if ((2 * i) + 2 * (yellow / i) + 4 == brown) {
			answer.push_back(i + 2);
			answer.push_back((yellow / i) + 2);
			break;
		}
	}

	return answer;
}