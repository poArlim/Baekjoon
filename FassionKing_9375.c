#include <stdio.h>
#include <string.h>

int
main()
{
    int T, n, n_kinds, result, i, j;
    char temp[21];
    char class[30][21];
    int n_clothes[30];

    scanf("%d", &T);
    for(int t = 0; t < T; t++){
        n_kinds = 0;
        result = 1;
        scanf("%d", &n);
        if(n == 0){
            printf("%d\n", 0);
            continue;
        }
        for(i = 0; i < 30; i++){
            class[i][0] = '\0';
            n_clothes[i] = 0;
        }
        for(i = 0; i < n; i++){
            scanf("%s %s", temp, class[i]);
        }

        for(i = 0; i < n; i++){
            if(class[i][0] != '\0'){
                n_clothes[i] += 1;
                for(j = i + 1; j < n; j++){
                    if(strcmp(class[i], class[j]) == 0){
                        class[j][0] = '\0';
                        n_clothes[i] += 1;
                    }
                }
                class[i][0] = '\0';
            }
        }

        for(i = 0; i < n; i++){
            if(n_clothes[i] > 0){
                result *= (n_clothes[i] + 1);
            }
        }
        printf("%d\n", result - 1);
    }
    return 0;
}
