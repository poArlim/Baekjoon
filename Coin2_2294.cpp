#include <iostream>
#include <algorithm>
using namespace std;

int CalculateMinNum(int, int);

const int MAX_N = 101;
const int MAX_K = 10001;
const int IMPOSSIBLE = 1000000;
int n, k, cost[MAX_N], minNumCoin[MAX_N][MAX_K];

int main(){
	cin>>n>>k;
	for (int i = 0; i < n; i++){
		cin>>cost[i];
	}

	for (int i = 0; i < n; i++){
		for (int j = 0; j <= k; j++){
			minNumCoin[i][j] = -1;
		}
	}

	int result = CalculateMinNum(0, k);
	if (result == IMPOSSIBLE) cout<<-1<<endl;
    else cout<<result<<endl;

	return 0;
}

int CalculateMinNum(int th, int wishValue){
	int result;

	if (th == n) return (wishValue == 0 ? 0 : IMPOSSIBLE);
	if (minNumCoin[th][wishValue] != -1) return minNumCoin[th][wishValue];

	if (cost[th] > wishValue) result = CalculateMinNum(th + 1, wishValue);
	else result = min(CalculateMinNum(th + 1, wishValue), CalculateMinNum(th, wishValue - cost[th]) + 1);

	minNumCoin[th][wishValue] = result;

	return result;
}
