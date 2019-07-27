#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Directory{
    char name[9];
    int height;
    struct _Directory *next;
}Directory;

typedef Directory *head;
typedef Directory *Nptr;
typedef Directory *Temp;

head rootList[501];
Nptr nptr;
Temp tmp;

int
main()
{
    int N, i, j;
    char ways[81];
    scanf("%d", &N);

    for(i = 0; i < N; i++){
        scanf("%s", ways);
        char *ptr = strtok(ways, "\\");

        for(j = 0; j < 500; j++){
            if(rootList[j] == NULL){
                rootList[j] = (Directory *)malloc(sizeof(Directory));
                strcpy(rootList[j]->name, ptr);
                rootList[j]->height = 0;
                rootList[j]->next = NULL;
                nptr = rootList[j];
                break;
            }
            else if(strcmp(rootList[j]->name, ptr) == 0){
                nptr = rootList[j];
                break;
            }
        }
        while(ptr != NULL){
            ptr = strtok(NULL, "\\");
            if(nptr->next == NULL){
                nptr->next = (Directory *)malloc(sizeof(Directory));
                strcpy(nptr->next->name, ptr);
                nptr->next->height = nptr->height + 1;
                nptr->next->next = NULL;
                nptr = nptr->next;
            }
            else{
                if(strcmp(ptr, nptr->next->name) == -1){
                    tmp = nptr->next;
                    nptr->next = (Directory *)malloc(sizeof(Directory));
                    strcpy(nptr->next->name, ptr);
                    nptr->next->height = tmp->height;
                    nptr->next->next = tmp;
                    nptr = tmp;
                }
                else if(strcmp(ptr, nptr->next->name) == 0){
                    nptr = nptr->next;
                }
                else{
                    nptr->next->next = (Directory *)malloc(sizeof(Directory));
                    strcpy(nptr->next->next->name, ptr);
                    nptr->next->next->height = nptr->next->height;
                    nptr->next->next->next = NULL;
                    nptr = nptr->next->next;
                }
            }
        }
    }

    j = 0;
    while(rootList[j] != NULL){


        j += 1;
    }











    return 0;
}
