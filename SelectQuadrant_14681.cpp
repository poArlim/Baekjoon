#include <iostream>
using namespace std;

int main(){
	int x, y;
	cin>>x>>y;

	if(x * y < 0){
		if(x < 0) cout<<2;
		else cout<<4;
	}
	else{
		if(x < 0) cout<<3;
		else cout<<1;
	}

	return 0;
}
