#include <iostream>
#define MAX 1000000
#define MIN -1000000
using namespace std;

int main (){
    int N, num, max, min;
    cin>>N;
	min = MAX;
	max = MIN;
    for (int i = 0; i < N; i++){
        cin>>num;
        if (num <= min) min = num;
        if (num >= max) max = num;
    }
    cout<<min<<" "<<max;
    return 0;
}
