#include <string>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
int S[25][25][4] = {0};

int solution(vector<vector<int>> board) {
    int answer = INF;
    int n = board.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 4; k++) {
                S[i][j][k] = INF;
            }
        }
    }
    for (int k = 0; k < 4; k++) {
        S[0][0][k] = 0;
    }

    queue<pair<pair<int,int>,int>> pos_dir;
    pos_dir.push({{0,0},1});
    pos_dir.push({{0,0},3});
    
    while (!pos_dir.empty()) {
        int cury = pos_dir.front().first.first;
        int curx = pos_dir.front().first.second;
        int curd = pos_dir.front().second;
        pos_dir.pop();

        for (int i = 0; i < 4; i++){
            int ny = cury + dy[i];
            int nx = curx + dx[i];
            int ndir = i;
            int nextValue;
            if (ny < 0 || ny > n - 1 || nx < 0 || nx > n - 1) continue;
            if (board[ny][nx] == 1) continue;
            
            if (curd == ndir) nextValue = S[cury][curx][curd] + 100;
            else nextValue = S[cury][curx][curd] + 600;
            
            if (S[ny][nx][ndir] > nextValue) {
                S[ny][nx][ndir] = nextValue;
                pos_dir.push({{ny,nx},ndir});
            }
        }
    }
    for (int i = 0; i < 4; i++){
        answer = min(answer, S[n-1][n-1][i]);
    }
    
    return answer;
}