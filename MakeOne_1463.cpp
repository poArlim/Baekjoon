#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> minCount;

int MakeOne(int n){
	if (n == 0) {
		cout<<"0 could not be calculated."<<endl;
		return 0;
	}

	if (minCount[n] != -1) return minCount[n];
	
	int result = 1000001;

	if (n % 3 == 0) result = min(result, MakeOne(n/3) + 1);
	if (n % 2 == 0) result = min(result, MakeOne(n/2) + 1);
	result = min(result, MakeOne(n-1) + 1);

	minCount[n] = result;
	return result;
}


int main(){
	int N;

	cin>>N;
	minCount.resize(N+2, -1);
	
	minCount[1] = 0;
	cout<<MakeOne(N)<<endl;
    
	return 0;
}
