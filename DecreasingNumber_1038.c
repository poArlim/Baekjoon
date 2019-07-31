#include <stdio.h>
#include <string.h>
#include <math.h>


int arr[100];
int result[10];

int main()
{
    int N, i, j, index, sum;
    long res;
    index = 0;
    sum = 0;
    res = 0;
    scanf("%d", &N);

    if(N == 0){
        printf("%d", 0);
        return 0;
    }
    if(N >= 3318){
        printf("%d", -1);
        return 0;
    }
    N = N + 1;


    for(i = 0; i < 10; i++) arr[i] = 1;
    for(i = 10; i < 100; i++){
        if(i % 10 == 0) arr[i] = 1;
        else{
            for(j = ((i / 10) - 1) * 10; j < i - 10; j++) arr[i] += arr[j];
        }
    }

    j = 1;
    int flag = 1;
    while(j >= 0){
        sum = 0;
        for(i = (j / 10) * 10; sum < N; i++){
            if(flag == 1){
                if(i % 10 == 0 && i != 0) continue;
            }
            sum += arr[i];
        }
        flag = 0;
        i -= 1;
        result[index] = i % 10;
        index += 1;
        N = N - (sum - arr[i]);
        j = i - 10;
    }

    index -= 1;
    j = 0;
    for(i = index; i >= 0; i--){
        res += result[i] * pow(10,j);
        j += 1;
    }
    printf("%ld", res);

    return 0;
}
