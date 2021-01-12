#include <iostream>
using namespace std;

int main(){
	long  N;
	cin>>N;

	long priNum[91];

	priNum[1] = 1;
	priNum[2] = 1;
	for(int i = 3; i <= N; i++){
		priNum[i] = priNum[i-1] + priNum[i-2];
	}

	cout<<priNum[N]<<endl;

	return 0;
}

