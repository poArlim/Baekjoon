#include <stdio.h>

int
main()
{
    int i, j, k, gtindex, ltindex, max, min;  // k is number of inequality signs.
    char temp, flag;
    char signs[9];
    int gtarr[9] = {0};
    int ltarr[9] = {0};

    gtindex = 0;
    ltindex = 0;

    scanf("%d", &k);
    scanf("%c", &temp);

    scanf("%c", &signs[0]);
    scanf("%c", &temp);

    flag = signs[0];
    if(flag == '<') gtarr[gtindex] += 1;
    else ltarr[ltindex] += 1;

    for(i = 1; i < k; i++){
        scanf("%c", &signs[i]);
        if(flag == signs[i]){
            if(flag == '<') gtarr[gtindex] += 1;
            else ltarr[ltindex] += 1;
        }
        else{
            if(flag == '>'){
                gtarr[gtindex] += 1;
                ltindex += 1;
            }
            else{
                ltarr[ltindex] += 1;
                gtindex += 1;
            }
        }
        flag = signs[i];
        scanf("%c", &temp);
    }

    if(signs[0] == '<'){

    //maximum
    max = 9;
    i = 0;
        while(gtarr[i] != 0){
            for(j = max - gtarr[i]; j <= max; j++){
                printf("%d", j);
            }
            max = max - gtarr[i] - 1;
            if(ltarr[i] > 1){
                for(j = max; j >= max - ltarr[i] + 2; j--){
                    printf("%d", j);
                }
                max = max - ltarr[i] + 1;
            }
            i += 1;
        }
        if(ltarr[i - 1] != 0){
            printf("%d", max);
        }

        printf("\n");

    //minimun
    min = 0;
    i = 0;
        while(ltarr[i] != 0){
            for(j = min + ltarr[i]; j >= min; j--){
                printf("%d", j);
            }
            min = min + ltarr[i] + 1;
            if(gtarr[i] > 1){
                for(j = min; j <= min + gtarr[i] - 2; j++){
                    printf("%d", j);
                }
                min = min + gtarr[i] - 1;
            }
            i += 1;
        }
        if(gtarr[i - 1] != 0){
            printf("%d", min);
        }
    }




    if(signs[0] == '>'){

    //maximum
    max = 9;
    i = 0;
        for(j = max; j > max - ltarr[i]; j--){
            printf("%d", j);
        }
        max = max - ltarr[i];

        while(ltarr[i] != 0){
            for(j = max - gtarr[i]; j <= max; j++){
                printf("%d", j);
            }
            max = max - gtarr[i] - 1;
            if(ltarr[i + 1] == 0) break;
            i += 1;

            if(ltarr[i] > 1){
                for(j = max; j >= max - ltarr[i] + 2; j--){
                    printf("%d", j);
                }
                max = max - ltarr[i] + 1;
            }
        }

        if(ltarr[i - 1] != 0){
            printf("%d", max);
        }

        printf("\n");

    //minimun
    min = 0;
    i = 0;
        while(ltarr[i] != 0){
            for(j = min + ltarr[i]; j >= min; j--){
                printf("%d", j);
            }
            min = min + ltarr[i] + 1;
            if(gtarr[i] > 1){
                for(j = min; j <= min + gtarr[i] - 2; j++){
                    printf("%d", j);
                }
                min = min + gtarr[i] - 1;
            }
            i += 1;
        }
        if(gtarr[i - 1] != 0){
            printf("min %d", min);
        }
    }








    return 0;
}
