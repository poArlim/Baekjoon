#include <stdio.h>


void digitPlus(int current, int i_arr[][5], int rw, int cl, int count) ;
int numbers[1000000];
int result = 0;

int
main()
{
    int i_array[5][5];
    int i, j ;

    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            scanf("%d",&i_array[i][j]);
        }
    }

    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            digitPlus(0, i_array, i, j, 0) ;
        }
    }
    printf("%d\n", result);

    return 0 ;
}

void digitPlus(int current, int i_arr[][5], int rw, int cl, int count){
    int update = 10 * current + i_arr[rw][cl];
    if(count == 5){
        if(numbers[update] == 0){
            numbers[update] = 1 ;
            result += 1 ;
        }
    }
    else{
        if(rw - 1 >= 0) digitPlus(update, i_arr, rw - 1, cl, count + 1);
        if(rw + 1 <= 4) digitPlus(update, i_arr, rw + 1, cl, count + 1);
        if(cl - 1 >= 0) digitPlus(update, i_arr, rw, cl - 1, count + 1);
        if(cl + 1 <= 4) digitPlus(update, i_arr, rw, cl + 1, count + 1);
    }

    return ;
}
