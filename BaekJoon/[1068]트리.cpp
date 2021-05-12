#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int N, root, node, del, leaf;
vector<int> p[51];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	queue<int> q;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> node;
		if (node == -1) // root 인 경우
			root = i;
		else {
			p[node].push_back(i);
		}
	}
	cin >> del;
	if (del == root) // 만약 삭제하는 노드가 root인 경우 leaf는 0
		cout << 0;
	else {
		bool flag = true;
		for (int i = 0; i < p[root].size(); i++) { // root의 자식 수 만큼 반복문 수행
			int r = p[root][i];

			if (r == del) continue; //루트의 자식이 삭제된 경우

			if (p[r].size() == 0) { // 루트의 자식이 리프 노드인 경우
				flag = false;
				leaf++;
				continue;
			}
			q.push(r);
			while (!q.empty()) {
				flag = false;
				int q_size = q.size();
				for (int j = 0; j < q_size; j++) {
					int parent = q.front(), c_cnt = 0;
					q.pop();
					for (int k = 0; k < p[parent].size(); k++) {
						int child = p[parent][k];
						if (child == del) continue;
						q.push(child);
						c_cnt++; // 자식이 삭제되어 본인이 리프 노드가 될 수 있으므로 자식의 갯수 확인
					}
					if (c_cnt == 0) {
						leaf++;
					}
				}

			}
		}
		if (flag) // 만약 루트가 리프 노드가 될 경우
			leaf++;
		cout << leaf;
	}
	return 0;
}