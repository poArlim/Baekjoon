#include <stdio.h>
#include <string.h>

int
main()
{
    int N, i, j, depth;
    char ways[500][81];
    char tmp[81];
    char compare[500][81];

    scanf("%d", &N);
    for(i = 0; i < N; i++){
        scanf("%s", ways[i]);
        j = 0;
        while(ways[i][j] != '\0'){
            if(ways[i][j] == '\\') ways[i][j] = ' ';
            j++;
        }
        compare[i][0] = '\0';
    }

    for(i = 0; i < N-1; i++){
        for(j = 0; j < N-1-i; j++){
            if(strcmp(ways[j], ways[j+1]) > 0){
                strcpy(tmp, ways[j]);
                strcpy(ways[j], ways[j+1]);
                strcpy(ways[j+1], tmp);
            }
        }
    }

    for(i = 0; i < N; i++){
        depth = 0;
        char *t = strtok(ways[i], " ");
        if(strcmp(compare[depth], t) != 0){
            while(t != NULL){
                strcpy(compare[depth], t);
                for(j = 0; j < depth; j++) printf(" ");
                printf("%s\n", t);
                t = strtok(NULL, " ");
                depth += 1;
            }
            while(compare[depth][0] != '\0'){
                compare[depth][0] = '\0';
                depth += 1;
            }
        }
        else{
            while(strcmp(compare[depth], t) == 0){
                t = strtok(NULL, " ");
                depth += 1;
                if(t == NULL) break;
            }
            while(t != NULL){
                strcpy(compare[depth], t);
                for(j = 0; j < depth; j++) printf(" ");
                printf("%s\n", t);
                t = strtok(NULL, " ");
                depth += 1;
            }
            while(compare[depth][0] != '\0'){
                compare[depth][0] = '\0';
                depth += 1;
            }
        }
    }
    return 0;
}
