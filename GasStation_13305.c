#include <stdio.h>

long long cost[100000];
long long dist[100000];

int
main()
{
    int N, i, j;
    long long result, currentCost;
    scanf("%d", &N);

    for(i = 0; i < N - 1; i++){
        scanf("%lld", &dist[i]);
    }
    for(i = 0; i < N; i++){
        scanf("%lld", &cost[i]);
    }

    result = 0;
    currentCost = cost[0];
    i = 0;
    while(i != N - 1){
        result += currentCost * dist[i];
        if(currentCost > cost[i+1])
            currentCost = cost[i+1];
        i++;
    }

    printf("%lld", result);

    return 0;
}
