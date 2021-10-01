#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    sort(times.begin(), times.end());
    long long minTime = 1;
    long long maxTime = (long long)times[times.size() - 1] * n;
    long long avgTime;
    long long answer = 0;
    
    while(minTime <= maxTime){
        avgTime = (minTime + maxTime) / 2;
        
        long long cnt = 0;
        for(int time : times){
            cnt += avgTime / time;
        }
        
        if(cnt < n) minTime = avgTime + 1;
        else maxTime = avgTime - 1;
    }
    
    return minTime;
}