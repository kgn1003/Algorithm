#include <string>
#include <algorithm>
#include <vector>

using namespace std;
vector<vector<string>> answer_list; // 정답이 될 수 있는 것들 
void DFS(vector<vector<string>> tickets, vector<pair<int, int>> visited, string from, int order) {
	if (order == tickets.size()) { // 마지막 순서까지 다 돌았을 경우
		vector<string> answer;
		vector<pair<int, int>> tmp = visited;
		sort(tmp.begin(), tmp.end()); // 경로 순서대로 정렬
		for (int i = 0; i < tmp.size(); i++) {
			answer.push_back(tickets[tmp[i].second][0]); // 출발지의 위치 저장
		}
		answer.push_back(tickets[tmp[tmp.size() - 1].second][1]); // 맨마지막 도착지 위치
		answer_list.push_back(answer); // 정답 리스트에 삽입
		return;
	}

	for (int idx = 0; idx < tickets.size(); idx++) {
		if (visited[idx].second == -1 && from == tickets[idx][0]) { // 방문한 적이 없고, 출발지의 목적지인 경우
			visited[idx] = { order,idx }; // 방문 순서와 도착지의 티켓 인덱스를 저장.
			DFS(tickets, visited, tickets[idx][1], order + 1); // 그 다음 방문순서로 재귀
			visited[idx] = { 0,-1 }; // 방문하지 않은 걸로 초기화
		}
	}
}

vector<string> solution(vector<vector<string>> tickets) {
	vector<pair<int, int>> visited(tickets.size(), { 0,-1 });
	DFS(tickets, visited, "ICN", 0); // 처음 시작은 ICN 부터
	sort(answer_list.begin(), answer_list.end()); // 정답 리스트 중 알파벳 순서가 앞서는 경로로 정렬.
	return answer_list[0];
}