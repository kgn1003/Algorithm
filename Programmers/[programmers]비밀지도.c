#include <string>
#include <vector>
#include <cmath>

using namespace std;
int map1[17][17], map2[17][17];

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for(int i = 0; i < n; i++){
        int num = arr1.at(i);
        for(int j = 0; j < n; j++){
            if((num / (int)pow(2,(n-1)-j)) > 0){
                map1[i][j] = 1;
                num -= (int)pow(2,(n-1)-j);
            }
            else
                map1[i][j] = 0;
        }
    }
    
    for(int i = 0; i < n; i++){
        int num = arr2.at(i);
        for(int j = 0; j < n; j++){
            if((num / (int)pow(2,(n-1)-j)) > 0){
                map2[i][j] = 1;
                num -= (int)pow(2,(n-1)-j);
            }
            else
                map2[i][j] = 0;
        }
    }

    for(int i = 0; i < n; i++){
        string s = "";
        for(int j = 0; j < n; j++){
            if(map1[i][j] + map2[i][j])
                s += "#";
            else
                s += " ";
        }
        answer.push_back(s);
    }
    return answer;
}
