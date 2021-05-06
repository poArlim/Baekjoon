#include <string>
#include <vector>
#include <queue>

using namespace std;

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    bool visited[201] = {false};
    queue<int> q;
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            answer++;
            q.push(i);
            while (!q.empty()) {
                int cur = q.front();
                q.pop();
                visited[cur] = true;
                for (int k = 0; k < n; k++) {
                    if (computers[cur][k] == 1 && visited[k] == false) {
                        q.push(k);
                    }
                }
            }
        }
    }
    
    return answer;
}