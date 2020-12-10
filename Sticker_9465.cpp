#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 100000;

int max_3(int a, int b, int c) {return max(a, max(b, c));}
int CalculateScore(int , int);
int n, value[2][MAX], valueSum[3][MAX];

int main(){
	int T;
	cin>>T;

	for(int t = 0; t < T; t++){
		cin>>n;
		for(int i = 0; i < 2; i++){
			for(int j = 0; j < n; j++){
				cin>>value[i][j];
			}
		}
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < n; j++){
				valueSum[i][j] = -1;
			}
		}
		cout<<CalculateScore(0, 0)<<endl;
	}
	
	return 0;
}

int CalculateScore(int col, int status){
	int result;
	
	if (col == n) return 0;
	if (valueSum[status][col] != -1) return valueSum[status][col];

	result = CalculateScore(col + 1, 0);
	if (status == 0) result = max_3(result, value[0][col] + CalculateScore(col + 1, 1), value[1][col] + CalculateScore(col + 1, 2));
	else if (status == 1) result = max(result, value[1][col] + CalculateScore(col + 1, 2));
	else if (status == 2) result = max(result, value[0][col] + CalculateScore(col + 1, 1));
	else {
		cout<<"invalid status value..."<<endl;
		exit(1);
	}

	valueSum[status][col] = result;

	return result;
}
