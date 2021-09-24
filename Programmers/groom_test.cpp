#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int input[10][10];
int possible[10][10];

int v_idx = -1;

void search(int y, int x, int size, vector<int> &count){
    int dy[4] = {-1,1,0,0};
    int dx[4] = {0,0,-1,1};

    possible[y][x] = 0;
    count[v_idx]++;

    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < size && ny >= 0 && nx < size && nx >= 0 && input[ny][nx] == 1 && possible[ny][nx] == 1){
            search(ny, nx, size, count);
        }
    }
}

int main(){
    int size;
    vector<int> count;
    
    cin>> size;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            cin>>input[i][j];
            possible[i][j] = 1;
        }
    }

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(input[i][j] == 1 && possible[i][j] == 1){
                v_idx++;
                count.push_back(0);
                search(i, j, size, count);
            }
        }
    }

    sort(count.begin(), count.end());
    count<<count.size()<<endl;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            count<<count[i];
            if(i != count.size() - 1) count<<" ";
        }
    }

    return 0;
}