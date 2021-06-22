#include <iostream>
using namespace std;

int main (){
    int N;
    cin>>N;
    
    for (int line = 1; line <= N; line++){
        int numStar, numSpace;
        if (line == 1) {
            for (int i = 0; i < N - line; i++) cout<<" ";
            cout<<"*";
        }
        else if (line == N){
            for (int i = 0; i < 2 * N - 1; i++) cout<<"*";
        }
        else {
            for (int i = 0; i < N - line; i++) cout<<" ";
            cout<<"*";
            for (int i = 0; i < (line - 1) * 2 - 1; i++) cout<<" ";
            cout<<"*";
        }
        cout<<endl;
    }
    
    return 0;
}
