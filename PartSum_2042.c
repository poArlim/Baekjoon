#include <stdio.h>

long long array[1000001];
long long sector[1001];

int
main()
{
    int N, M, K;
    int i, j, p, a, b;
    long long c, result;

    scanf("%d %d %d", &N, &M, &K);

    for(i = 1; i <= N; i++){
        scanf("%lld", &array[i]);
        sector[i/1000] += array[i];
    }


    for(i = 0; i < M + K; i++){
        result = 0;
        scanf("%d %d %lld", &a, &b, &c);
        if(a == 1){
            j = c - array[b];
            array[b] = c;
            sector[b/1000] += j;
        }
        else if(a == 2){
            for(p = b/1000; p < c/1000; p++) result += sector[p];
            for(p = ((c/1000) * 1000); p <= c; p++) result += array[p];
            for(p = ((b/1000) * 1000); p < b; p++) result -= array[p];
            printf("%lld\n", result);
        }
    }
    return 0;
}
