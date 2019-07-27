#include <stdio.h>

#define MAX_SIZE 10000

typedef struct{
    char state;
    int count;
    int mark;
    int y;
    int x;   // 0: unmarked ,   1: marked
} element;

void addQ(element item);
element deleteQ();

element queue[MAX_SIZE];
int search(element map[][50], int y, int x);

int rear = -1;
int front = -1;
int row, column;
int max = 0;

int
main()
{
    int i, j, p;
    char state, temp;
    element stateArray[50][50];

    scanf("%d %d", &row, &column);
    scanf("%c", &temp);

    for(i = 0; i < row; i++){
        for(j = 0; j < column; j++){
            scanf("%c", &state);
            stateArray[i][j].state = state;
            stateArray[i][j].y = i;
            stateArray[i][j].x = j;
            stateArray[i][j].mark = 1;
        }
        scanf("%c", &temp);
    }

    for(i = 0; i < row; i++){
        for(j = 0; j < column; j++){
            if(stateArray[i][j].state == 'L'){
                p = search(stateArray, i, j);
                if(p > max) max = p;
            }
        }
    }

    printf("%d\n", max);

    return 0 ;
}


void addQ(element item){
    queue[++rear] = item;
}

element deleteQ(){
    return queue[++front];
}

int search(element map[][50], int y, int x){
    element u;
    for(int i = 0; i < row; i ++){
        for(int j = 0; j < column; j++){
            if(map[i][j].state == 'L') map[i][j].mark = 0;
            map[i][j].count = 1000;
        }
    }
    map[y][x].mark = 1;
    map[y][x].count = 0;
    rear = -1;
    front = -1;
    addQ(map[y][x]);
    while(front != rear){
        u = deleteQ();
        if(u.y - 1 >= 0 && map[u.y - 1][u.x].mark == 0){
            map[u.y - 1][u.x].mark = 1;
            map[u.y - 1][u.x].count = map[u.y][u.x].count + 1;
            addQ(map[u.y - 1][u.x]);
        }
        if(u.y + 1 < row && map[u.y + 1][u.x].mark == 0){
            map[u.y + 1][u.x].mark = 1;
            map[u.y + 1][u.x].count = map[u.y][u.x].count + 1;
            addQ(map[u.y + 1][u.x]);
        }
        if(u.x - 1 >= 0 && map[u.y][u.x - 1].mark == 0){
            map[u.y][u.x - 1].mark = 1;
            map[u.y][u.x - 1].count = map[u.y][u.x].count + 1;
            addQ(map[u.y][u.x - 1]);
        }
        if(u.x + 1 < column && map[u.y][u.x + 1].mark == 0){
            map[u.y][u.x + 1].mark = 1;
            map[u.y][u.x + 1].count = map[u.y][u.x].count + 1;
            addQ(map[u.y][u.x + 1]);
        }
    }
    return u.count;
}
