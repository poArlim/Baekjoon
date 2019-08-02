#include <stdio.h>
#include <math.h>

int main()
{
    int T, x1, y1, x2, y2, n, cx, cy, r;
    int i, j, flag1, flag2, count;
    double distance1, distance2;

    scanf("%d", &T);
    for(i = 0; i < T; i++){
        count = 0;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        scanf("%d", &n);
        for(j = 0; j < n; j++){
            flag1 = 0;
            flag2 = 0;
            scanf("%d %d %d", &cx, &cy, &r);
            distance1 = sqrt(pow((cx - x1), 2) + pow((cy - y1), 2));
            distance2 = sqrt(pow((cx - x2), 2) + pow((cy - y2), 2));
            if(distance1 < r) flag1 = 1;
            if(distance2 < r) flag2 = 1;
            if(flag1 != flag2) count += 1;
        }
        printf("%d\n", count);
    }
    return 0;
}
