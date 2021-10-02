#include <string>
#include <vector>

using namespace std;

int map[101][101];

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    for(int i = 1; i <= rows; i++){
        for(int j = 1; j <= columns; j++){
            map[i][j] = (i - 1) * columns + j;
        }
    }
    
    for(auto query : queries){
        int min = 9999;
        int x1 = query[0];
        int y1 = query[1];
        int x2 = query[2];
        int y2 = query[3];
        
        int lefttop = map[x1][y1];
        int righttop = map[x1][y2];
        int leftbottom = map[x2][y1];
        int rightbottom = map[x2][y2];
        for(int x = x1; x < x2; x++){
            if(map[x][y1] < min) min = map[x][y1];
            if(x == x2 - 1) map[x][y1] = leftbottom;
            else map[x][y1] = map[x+1][y1];
        }
        for(int y = y2; y > y1; y--){
            if(map[x1][y] < min) min = map[x1][y];
            if(y == y1 + 1) map[x1][y] = lefttop;
            else map[x1][y] = map[x1][y-1];
        }
        for(int x = x2; x > x1; x--){
            if(map[x][y2] < min) min = map[x][y2];
            if(x == x1 + 1) map[x][y2] = righttop;
            else map[x][y2] = map[x-1][y2];
        }
        for(int y = y1; y < y2; y++){
            if(map[x2][y] < min) min = map[x2][y];
            if(y == y2 - 1) map[x2][y] = rightbottom;
            else map[x2][y] = map[x2][y+1];
        }
        
        answer.push_back(min);
    }
    
    return answer;
}