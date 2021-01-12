#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 100001;

int main(){
	int N;
	cin>>N;

	int minNum[MAX];

	for(int i = 1; i <= N; i++){
		minNum[i] = i;
		for(int j = 1; j*j <= i; j++){
			minNum[i] = min(minNum[i], minNum[i-j*j] + 1);
		}
	}

	cout<<minNum[N]<<endl;

	return 0;
}
