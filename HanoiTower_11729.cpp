#include <iostream>
using namespace std;

void HanoiTower(int n, int start, int dest){
	if(n <= 0) return ;
	HanoiTower(n-1, start, 6-start-dest);
	cout<<start<<" "<<dest<<"\n";
	HanoiTower(n-1, 6-start-dest, dest);
}

int main(){
    cin.tie(NULL);
	cout.tie(NULL);
    ios::sync_with_stdio(false);

	int N, result;
	cin>>N;

	result = 1;
	for(int i = 0; i < N; i++) result *= 2;
	cout<<result - 1<<"\n";
	HanoiTower(N, 1, 3);
	return 0;
}
