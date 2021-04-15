#include <string>
#include <vector>

using namespace std;
int skill_order[27];
int solution(string skill, vector<string> skill_trees) {
	int answer = 0;
	for (int i = 0; i < skill.length(); i++) {
		skill_order[skill[i] - 'A'] = i + 1;
	}
	for (int idx = 0; idx < skill_trees.size(); idx++) {
		int pos = 1;
		bool flag = true;
		for (int i = 0; i < skill_trees[idx].length(); i++) {
			int cmp = skill_order[skill_trees[idx][i] - 'A'];
			if (cmp != 0) {
				if (cmp != pos) {
					flag = false;
					break;
				}
				else {
					pos++;
				}
			}
		}
		if (flag == true) {
			answer++;
		}
	}
	return answer;
}