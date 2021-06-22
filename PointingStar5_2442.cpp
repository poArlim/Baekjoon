#include <iostream>
using namespace std;

int main (){
    int N;
    cin>>N;
    for (int line = 1; line <= N; line++){
        int numStar = line * 2 - 1;
        int numSpace = (N * 2 - 1) - numStar;
        for (int i = 0; i < numSpace / 2; i++) cout<<" ";
        for (int i = 0; i < numStar; i++) cout<<"*";
        cout<<endl;
    }
    return 0;
}
