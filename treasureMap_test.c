#include <stdio.h>
#include <string.h>

void search(int y, int x, char map[][50], int score[][50], int count);
int findMax(int score[][50]);

int row, column ;

int
main()
{
    int i, j, p;
    char state, temp;
    char stateArray[50][50];
    int hourArray[50][50];
    int max = 0;

    scanf("%d %d", &row, &column);
    scanf("%c", &temp);

    for(i = 0; i < row; i++){
        for(j = 0; j < column ; j++){
            scanf("%c", &state);
            stateArray[i][j] = state;
        }
        scanf("%c", &temp);
    }

    for(i = 0; i < row; i++){
        for(j = 0; j < column; j++){
            memset(hourArray, -1, sizeof(hourArray));
            search(i, j, stateArray, hourArray, 0);
            p = findMax(hourArray);
            if(p > max) max = p;
        }
    }

    printf("%d", max);

    return 0 ;
}

void search(int y, int x, char map[][50], int score[][50], int count){
    if(map[y][x] != 'L') return;
    else if(score[y][x] == -1 || score[y][x] > count){
        score[y][x] = count;
    }
    else return;

    if(y - 1 >= 0) search(y - 1, x, map, score, count + 1);
    if(y + 1 < row) search(y + 1, x, map, score, count + 1);
    if(x - 1 >= 0) search(y, x - 1, map, score, count + 1);
    if(x + 1 < column) search(y, x + 1, map, score, count + 1);

}

int findMax(int score[][50]){
    int max = 0;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            if(score[i][j] > max) max = score[i][j];
        }
    }
    return max ;
}
