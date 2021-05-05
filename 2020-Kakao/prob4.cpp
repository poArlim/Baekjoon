#include <string>
#include <vector>
#include <queue>

using namespace std;
vector<vector<int>> g_board;
int N;
// direction
// left : 1, right : 2, up : 3, down : 4
void routeFind(int y, int x, int value, int dir) {
    g_board[y][x] = value;
    int newValue;
    
    if ((x - 1 >= 0) && (g_board[y][x-1] != -1)) {
        if (dir == 0 || dir == 1) newValue = value + 1;
        else newValue = value + 6;
        if (g_board[y][x-1] >= newValue) routeFind(y, x-1, newValue, 1);
    }
    if ((x + 1 < N) && (g_board[y][x+1] != -1)) {
        if (dir == 0 || dir == 2) newValue = value + 1;
        else newValue = value + 6;
        if (g_board[y][x+1] >= newValue) routeFind(y, x+1, newValue, 2);
    }
    if ((y - 1 >= 0) && (g_board[y-1][x] != -1)) {
        if (dir == 0 || dir == 3) newValue = value + 1;
        else newValue = value + 6;
        if (g_board[y-1][x] >= newValue) routeFind(y-1, x, newValue, 3);
    }
    if ((y + 1 < N) && (g_board[y+1][x] != -1)) {
        if (dir == 0 || dir == 4) newValue = value + 1;
        else newValue = value + 6;
        if (g_board[y+1][x] >= newValue) routeFind(y+1, x, newValue, 4);
    }
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    N = board.size();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++){
            if (board[i][j] == 1) board[i][j] = -1;
            if (board[i][j] == 0) board[i][j] = 100000;
        }
    }
    
    g_board.clear();
    g_board.assign(board.begin(),board.end() ); // 전체 복사
    
    routeFind(0, 0, 0, 0);
    answer = g_board[N-1][N-1] * 100;
    
    return answer;
}