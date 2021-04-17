#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;
vector<string> ans[10];
set<string> check;

vector<int> solution(int n, vector<string> words) {
	vector<int> answer;
	bool flag = true;
	check.insert(words[0]);
	char next = words[0][words[0].length() - 1];
	for (int i = 1; i < words.size(); i++) {
		if (next == words[i][0]) {
			auto iter = check.find(words[i]);
			if (iter != check.end()) {
				answer.push_back((i%n) + 1);
				answer.push_back((i / n) + 1);
				flag = false;
				break;
			}
			else {
				next = words[i][words[i].length() - 1];
				check.insert(words[i]);
			}
		}
		else {
			answer.push_back((i%n) + 1);
			answer.push_back((i / n) + 1);
			flag = false;
			break;
		}
	}
	if (flag) {
		answer.push_back(0);
		answer.push_back(0);
	}

	return answer;
}