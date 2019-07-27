#include <stdio.h>

int search(int y, int x, int v);
int arr[1002][1002];

int
main()
{
    int row, column;
    int i, j, v;
    int max = 0;
    char temp;

    scanf("%d %d", &row, &column);
    scanf("%c", &temp);
    for(i = 0; i < row; i++){
        for(j = 0; j < column; j++){
            scanf("%c", &temp);
            arr[i][j] = (int)temp - (int)'0';
        }
        scanf("%c", &temp);
    }

    for(i = 0; i < row; i++){
        for(j = 0; j < column; j++){
            v = 1;
            if(arr[i][j] == 1){
                while(search(i, j, v) == 1)
                    v += 1;
                if(max < v) max = v;
            }
        }
        if(row - i - 1 < max) break;
    }
    printf("%d\n", max * max);

    return 0;
}

int search(int y, int x, int v){
    if(arr[y+v][x+v] == 0) return 0;
    else{
        for(int i = 0; i <= v; i++)
            if(arr[y+v][x+i] == 0 || arr[y+i][x+v] == 0) return 0;
        return 1;
    }
}
