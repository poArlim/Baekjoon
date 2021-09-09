#include <string>
#include <vector>
#include <queue>

using namespace std;

bool visited[200] = {0};

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    for(int i = 0; i < computers.size(); i++){
        if(visited[i] == false){
            visited[i] = true;
            queue<int> connected;
            connected.push(i);
            while(!connected.empty()){
                int cur = connected.front(); connected.pop();
                for(int j = 0; j < computers.size(); j++){
                    if(computers[cur][j] == 1 && visited[j] == false) {
                        connected.push(j);
                        visited[j] = true;
                    }
                }
            }
        answer++;
        }
    }

    return answer;
}