#include <iostream>
using namespace std;

int factorial(int n);

int main(){
	int N;
	cin>>N;

	cout<<factorial(N);
	return 0;
}

int factorial(int n){
	if(n <= 1) return 1;
	return n * factorial(n - 1);
}
