#include <stdio.h>

int compare(int y, int x);

char board[50][50];
char chess[8][8] = {{'W','B','W','B','W','B','W','B'},
                    {'B','W','B','W','B','W','B','W'},
                    {'W','B','W','B','W','B','W','B'},
                    {'B','W','B','W','B','W','B','W'},
                    {'W','B','W','B','W','B','W','B'},
                    {'B','W','B','W','B','W','B','W'},
                    {'W','B','W','B','W','B','W','B'},
                    {'B','W','B','W','B','W','B','W'}};
int max, new;

int
main()
{
    int N, M; // N : row , M : column
    int y, x;
    char temp;

    scanf("%d %d", &N, &M);
    scanf("%c", &temp);
    for(y = 0; y < N; y++){
        for(x = 0; x < M; x++){
            scanf("%c", &board[y][x]);
        }
        scanf("%c", &temp);
    }
    for(y = 0; y < N - 7; y++){
        for(x = 0; x < M - 7; x++){
            new = compare(y,x);
            if(max < new) max = new;
        }
    }
    printf("%d\n", 64 - max);

    return 0;
}

int compare(int yy, int xx){
    int rightNum = 0;
    int wrongNum = 0;

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(board[yy+i][xx+j] == chess[i][j]) rightNum += 1;
            else wrongNum += 1;
        }
    }
    if(rightNum > wrongNum) return rightNum;
    else return wrongNum;
}
