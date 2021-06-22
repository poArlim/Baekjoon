#include <iostream>
using namespace std;

int main (){
    int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string day[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
	int x, y, days;
    cin>>x>>y;
    
    days = 0;
    for (int i = 0; i < x-1; i++){
        days += month[i];
    }
    days += y;
    
    cout<<day[days % 7]<<endl;
    
    return 0;
}
