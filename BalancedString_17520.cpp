#include <iostream>
using namespace std;

int main(){
	int n, indices, result;
	cin>>n;

	indices = (n + 1) / 2;
	result = 1;
	for(int i = 0; i < indices; i++){
		result *= 2;
		result %= 16769023;
	}

	cout<<result;

	return 0;
}
