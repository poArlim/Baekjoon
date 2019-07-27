#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int value;
    int * config;
} pieces ;

pieces partOfToy[101];
int n_piece;

void run(int index, int value);

int
main()
{
    int p, i;
    int relation;
    int x, y, k;
    int IsBasic[101];


    scanf("%d", &n_piece);
    scanf("%d", &relation);

    for(p = 0; p <= n_piece; p++){
        partOfToy[p].config = (int *)malloc(sizeof(int) * n_piece);

        for(i = 0; i < n_piece; i++){
            *(partOfToy[p].config + i) = 0;
        }
        partOfToy[p].value = 0;
        IsBasic[p] = 1;
    }

    partOfToy[n_piece].value = 1;

    for(p = 0; p < relation; p++){
        scanf("%d %d %d", &x, &y, &k);
        IsBasic[x] = 0;
        *(partOfToy[x].config + y) = k;
    }

    run(n_piece, 1);



    // for(p = n_piece; p > 0; p--){
    //     for(i = 1; i < n_piece; i++){
    //         partOfToy[i].value += partOfToy[p].value * (*(partOfToy[p].config + i));
    //     }
    // }
    for(p = 1; p <= n_piece; p++){
        if(IsBasic[p] == 1) printf("%d %d\n", p, partOfToy[p].value);
    }

    for(p = 0; p <= n_piece; p++){
        free(partOfToy[p].config);
    }

    return 0;
}


void run(int index, int value){
    int i ;

    for(i = 1; i < n_piece; i++){
        if(*(partOfToy[index].config + i) != 0){
            run(i, value * *(partOfToy[index].config + i));
        }
    }

    partOfToy[index].value += value;
}
