#include <stdio.h>

void Unplug(int sp);

int N, K;
int usedNum;
int inputK[100];
int hole[101];
int flag[101];

int main()
{
    int result = 0;
    int i;
    scanf("%d %d", &N, &K);
    for(i = 0; i < K; i++){
        scanf("%d", &inputK[i]);
    }

    usedNum = 0;
    for(i = 0; i < K; i++){
        if(hole[inputK[i]] == 0){
            if(usedNum >= N){
                Unplug(i);
                result += 1;
            }
            hole[inputK[i]] = 1;
            usedNum += 1;
        }
    }
    printf("%d\n", result);

    return 0;
}

void Unplug(int sp){
    int count = 0;
    int j;
    for(j = 0; j <= K; j++) flag[j] = 0;
    for(j = sp; j < K; j++){
        if(hole[inputK[j]] == 1 && flag[inputK[j]] == 0){
            count += 1;
            flag[inputK[j]] = 1;
            if(count >= N){
                hole[inputK[j]] = 0;
                usedNum -= 1;
                return ;
            }
        }
    }
    for(j = 0; j <= K; j++){
        if(hole[j] == 1 && flag[j] == 0){
            hole[j] = 0;
            usedNum -= 1;
            return ;
        }
    }
}
