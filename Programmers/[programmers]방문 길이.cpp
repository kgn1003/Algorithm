#include <string>
#include <set>

using namespace std;
int solution(string dirs) {
	set<pair<pair<int, int>, pair<int, int>>> move;
	int cy = 0, cx = 0, ny, nx;
	for (int i = 0; i < dirs.length(); i++) {
		char d = dirs[i];
		if (d == 'U') {
			ny = cy + 1; nx = cx;
			if (ny >= -5 && ny <= 5 && nx >= -5 && nx <= 5) { // 좌표 경계를 넘어 가지 않으면
				if (!move.count({ {cy,cx}, {ny,nx} }) && !move.count({ {ny,nx},{cy,cx} })) { // 선분이 겹치는게 존재 하는지 확인.
					move.insert({ {cy,cx}, {ny,nx} });
				}
				cy += 1;
			}
		}
		else if (d == 'D') {
			ny = cy - 1; nx = cx;
			if (ny >= -5 && ny <= 5 && nx >= -5 && nx <= 5) { // 좌표 경계를 넘어 가지 않으면
				if (!move.count({ {cy,cx}, {ny,nx} }) && !move.count({ {ny,nx},{cy,cx} })) { // 선분이 겹치는게 존재 하는지 확인.
					move.insert({ {cy,cx}, {ny,nx} });
				}
				cy -= 1;
			}
		}
		else if (d == 'R') {
			ny = cy; nx = cx + 1;

			if (ny >= -5 && ny <= 5 && nx >= -5 && nx <= 5) { // 좌표 경계를 넘어 가지 않으면
				if (!move.count({ {cy,cx}, {ny,nx} }) && !move.count({ {ny,nx},{cy,cx} })) { // 선분이 겹치는게 존재 하는지 확인.
					move.insert({ {cy,cx}, {ny,nx} });
				}
				cx += 1;
			}
		}
		else {
			ny = cy; nx = cx - 1;
			if (ny >= -5 && ny <= 5 && nx >= -5 && nx <= 5) { // 좌표 경계를 넘어 가지 않으면
				if (!move.count({ {cy,cx}, {ny,nx} }) && !move.count({ {ny,nx},{cy,cx} })) { // 선분이 겹치는게 존재 하는지 확인.
					move.insert({ {cy,cx}, {ny,nx} });
				}
				cx -= 1;
			}
		}
	}
	return move.size();
}