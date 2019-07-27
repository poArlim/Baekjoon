#include <stdio.h>


void digitPlus(int current, int i_arr[][5], int rw, int cl, int count) ;
int numbers[1000000];
int result = 0;
// int n = 0;
// int r = 0;

int
main()
{
    int i_array[5][5];
    int i, j ;
    // int flag = 0;

    //input values
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

    // numbers[n] = 0x0;
    // result[r] = 0x0;
    //
    // i = 0;
    // while(numbers[i] != 0x0){
    //
    //     for(j = 0; result[j] != 0x0; j++){
    //         if(numbers[i] == result[j]) flag = 1;
    //     }
        // do{
        //     if(numbers[i] == result[j]) flag = 1;
        // }while(result[j] != 0x0;)

    //     if(flag == 0){
    //         result[r++] = numbers[i];
    //         result[r] = 0x0;
    //     }
    //
    //     flag = 0;
    //
    //
    //     i += 1;
    // }


    printf("%d\n", result);

    // for(i = 0; i < r; i++){
    //     printf("result = %d\n", result[i]);
    // }


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
