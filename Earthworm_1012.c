#include <stdio.h>

void search(int y, int x, int value);

int T, M, N, K;
int field[50][50];

int
main()
{
    int p, q, i, j;
    int x, y;
    int count;

    scanf("%d", &T);


    for(p = 0; p < T; p++){//test case
        count = 0;
        for(i = 0; i < 50; i++){
            for(j = 0; j < 50; j++){
                field[i][j] = 0;
            }
        }

        scanf("%d %d %d", &M, &N, &K);
        for(q = 0; q < K; q++){
            scanf("%d %d", &x, &y);
            field[y][x] = 1;
        }

        for(y = 0; y < N; y++){
            for(x = 0; x < M; x++){
                if(field[y][x] == 1) search(y, x, 1);
            }
        }

        for(y = 0; y < N; y++){
            for(x = 0; x < M; x++){
                if(field[y][x] == -1) count += 1;
            }
        }

        printf("%d\n", count);

    }

    return 0;
}

void search(int y, int x, int value){
    field[y][x] = value;
    if(value == 1) field[y][x] = -1;
    if(y - 1 >= 0 && field[y-1][x] == 1) search(y - 1, x, value + 1);
    if(y + 1 < 50 && field[y+1][x] == 1) search(y + 1, x, value + 1);
    if(x - 1 >= 0 && field[y][x-1] == 1) search(y, x - 1, value + 1);
    if(x + 1 < 50 && field[y][x+1] == 1) search(y, x + 1, value + 1);
}
