#include <stdio.h>

int row, column;
int arr[1002][1002];

int min(int a, int b){
    if(a < b) return a;
    else return b;
}

int main(){
    char temp;
    int max = 0;

    scanf("%d %d", &row, &column);
    scanf("%c", &temp);

    for(int i = 1; i <= row; i++){
        for(int j = 1; j <= column; j++){
            scanf("%c", &temp);
            arr[i][j] = (int)temp - (int)'0';
            if(arr[i][j] == 1){
                arr[i][j] = min(arr[i - 1][j], min(arr[i - 1][j - 1], arr[i][j - 1])) + 1;
                if(max < arr[i][j]) max = arr[i][j];
            }
        }
        scanf("%c", &temp);
    }
    printf("%d", max * max);
    return 0;
}
