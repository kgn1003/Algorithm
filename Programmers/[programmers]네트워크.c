#include <string>
#include <vector>
#include <stack>
using namespace std;

bool visited[201];

void DFS(int com, int n,vector<vector<int>> computers){
    stack<int> s;
    s.push(com);
    while(!s.empty()){
        int s_size = s.size();
        for(int i = 0; i < s_size; i++){
            int cur = s.top();
            s.pop();
            for(int j = 0; j < n; j++){
                if(computers[cur][j] && !visited[j]){
                    visited[j] = true;
                    s.push(j);
                }
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(computers[i][j] == 1 && !visited[j]){
                visited[j] = true;
                DFS(j, n,computers);
                answer++;
            }
        }
    }
    return answer;
}
