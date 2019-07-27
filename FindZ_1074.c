#include <stdio.h>
#include <math.h>

int findZ(int r, int c, int N);

int
main()
{
    int N, r, c;
    scanf("%d %d %d", &N, &r, &c);
    printf("%d\n", findZ(r, c, N));

    return 0;
}

int findZ(int r, int c, int N)
{
    if(N == 0) return 0;
    else if((r < pow(2, N-1)) && (c < pow(2, N-1))) return ((0 * pow(4, N-1)) + findZ(r, c, N-1));
    else if((r < pow(2, N-1)) && (c >= pow(2, N-1))) return ((1 * pow(4, N-1)) + findZ(r, c - pow(2, N-1), N-1));
    else if((r >= pow(2, N-1)) && (c < pow(2, N-1))) return ((2 * pow(4, N-1)) + findZ(r - pow(2, N-1), c, N-1));
    else if((r >= pow(2, N-1)) && (c >= pow(2, N-1))) return ((3 * pow(4, N-1)) + findZ(r - pow(2, N-1), c - pow(2, N-1), N-1));
}
