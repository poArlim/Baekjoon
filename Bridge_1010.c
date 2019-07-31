#include <stdio.h>

int combination(int a, int b);

int main()
{
    int T, N, M;
    scanf("%d", &T);
    for(int i = 0; i < T; i++){
        scanf("%d %d", &N, &M);
        printf("%d\n", combination(N, M));
    }
    return 0;
}

int combination(int a, int b){
    double nominator = 1;
    double denominator = 1;
    double result = 1;
    int i;
    if(b - a <= a){
        for(i = 0; i < b - a; i++){
            nominator *= b - i;
            denominator *= b - a - i;
            // result *= (nominator / denominator);
        }
    }
    else{
        for(i = 0; i < a; i++){
            nominator *= b - i;
            denominator *= a - i;
            // result *= (nominator / denominator);
        }
    }
    result = nominator / denominator;
    return (int)result;
}
