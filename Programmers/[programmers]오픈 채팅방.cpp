#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
	string state, id, name;
	map<string, string> info;
	vector<pair<string, string>> ans;
	vector<string> answer;
	for (int i = 0; i < record.size(); i++) {
		stringstream s(record[i]);
		s >> state;
		if (state == "Enter") {
			s >> id; s >> name;
			info[id] = name;
			ans.push_back({ state,id });
		}
		else if (state == "Change") {
			s >> id; s >> name;
			info[id] = name;
		}
		else {
			s >> id;
			ans.push_back({ state,id });
		}
	}

	for (int i = 0; i < ans.size(); i++) {
		if (ans[i].first == "Enter") {
			answer.push_back(info.find(ans[i].second)->second + "님이 들어왔습니다.");
		}
		else {
			answer.push_back(info.find(ans[i].second)->second + "님이 나갔습니다.");
		}
	}
	return answer;
}