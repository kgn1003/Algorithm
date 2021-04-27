#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, double> &a, pair<int, double> &b) {
	if (a.second == b.second)
		return a.first < b.first;
	else
		return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	vector<pair<int, double>> v;
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		int cur_stage = 0;
		for (int j = 0; j < stages.size(); j++) {
			if (stages[j] == i) {
				cur_stage++;
			}
		}
		if (cur_stage == 0) {
			v.push_back({ i,0 });
		}
		else {
			v.push_back({ i,(double)cur_stage / (stages.size() - cnt) });
		}
		cnt += cur_stage;
	}
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++) {
		answer.push_back(v[i].first);
	}

	return answer;
}