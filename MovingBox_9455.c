#include <stdio.h>

int main(){
  int test, m, n, count = 0;
  int arr[101][101] = { 0 }, columnSum[101], result[100];

  int i, j, k;

  scanf("%d", &test);

  for(i = 0; i < test; i++){
    scanf("%d %d", &m, &n);

    for(k = 0; k < n; k++){
      columnSum[k] = 0;
    }
    count = 0;

    for(j = 0; j < m; j++){
      for(k = 0; k < n; k++){
        scanf("%d", &arr[j][k]);

        if(arr[j][k] == 1){
          columnSum[k] += 1;
        }
      }
    }

    for(j = 0; j < m; j++){
      for(k = 0; k < n; k++){
        if(j == m - 1 && arr[j][k] == 1) continue;
        else if(arr[j][k] == 1){
          count += m - j - 1;
        }
      }
    }

    for(k = 0; k < n; k++){
      j = columnSum[k];
      while(j > 1){
        count -= --j;
      }
    }

    result[i] = count;
  }

  for (i = 0; i < test; i++) {
		printf("%d\n", result[i]);
	}


  return 0;
}
