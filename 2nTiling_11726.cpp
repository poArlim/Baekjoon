#include <iostream>
using namespace std;

int dp[1001] = {0};
int Tiling (int n);

int main (){
	int n;
	cin>>n;
	Tiling(n);

	cout<<dp[n];

	return 0;
}

int Tiling (int n){
	if (dp[n] != 0) return dp[n];
	if (n == 1) dp[1] = 1;
	else if (n == 2) dp[2] = 2;
	else dp[n] = (Tiling (n - 1) + Tiling (n - 2)) % 10007;

	return dp[n];
}
