#include <iostream>
#include<vector>
using namespace std;
int solution(vector<vector<int>> board)
{
	int answer = board[0][0];
	int N = board.size(), M = board[0].size();
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < M; j++) {
			if (board[i][j] == 1) {
				int temp = board[i - 1][j - 1] < board[i][j - 1] ? board[i - 1][j - 1] : board[i][j - 1];
				board[i][j] = (temp < board[i - 1][j] ? temp : board[i - 1][j]) + 1;
				if (answer < board[i][j])
					answer = board[i][j];
			}
		}
	}
	return answer * answer;
}