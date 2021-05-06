#include <string>
#include <algorithm>
#include <vector>

using namespace std;
vector<vector<string>> answer_list; // ������ �� �� �ִ� �͵� 
void DFS(vector<vector<string>> tickets, vector<pair<int, int>> visited, string from, int order) {
	if (order == tickets.size()) { // ������ �������� �� ������ ���
		vector<string> answer;
		vector<pair<int, int>> tmp = visited;
		sort(tmp.begin(), tmp.end()); // ��� ������� ����
		for (int i = 0; i < tmp.size(); i++) {
			answer.push_back(tickets[tmp[i].second][0]); // ������� ��ġ ����
		}
		answer.push_back(tickets[tmp[tmp.size() - 1].second][1]); // �Ǹ����� ������ ��ġ
		answer_list.push_back(answer); // ���� ����Ʈ�� ����
		return;
	}

	for (int idx = 0; idx < tickets.size(); idx++) {
		if (visited[idx].second == -1 && from == tickets[idx][0]) { // �湮�� ���� ����, ������� �������� ���
			visited[idx] = { order,idx }; // �湮 ������ �������� Ƽ�� �ε����� ����.
			DFS(tickets, visited, tickets[idx][1], order + 1); // �� ���� �湮������ ���
			visited[idx] = { 0,-1 }; // �湮���� ���� �ɷ� �ʱ�ȭ
		}
	}
}

vector<string> solution(vector<vector<string>> tickets) {
	vector<pair<int, int>> visited(tickets.size(), { 0,-1 });
	DFS(tickets, visited, "ICN", 0); // ó�� ������ ICN ����
	sort(answer_list.begin(), answer_list.end()); // ���� ����Ʈ �� ���ĺ� ������ �ռ��� ��η� ����.
	return answer_list[0];
}