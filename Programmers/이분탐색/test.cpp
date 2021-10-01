#include <string>
#include <vector>
#include <queue>
using namespace std;

struct compare{
    bool operator()(pair<int, int> a, pair<int, int> b){
        if(a.first + a.second > b.first + b.second) return true;
        else return false;
    }
};

long long solution(int n, vector<int> times) {
    priority_queue<int, vector<int>, greater<int>> ready;
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> working;
    long long answer = 0;
    long long time = 0;
    long long waiting_number = 0;
    
    for(int t : times) ready.push(t);
    
    while(waiting_number < n){
        if(!ready.empty() && (working.empty() || time + ready.top() <= working.top().first + working.top().second)){
            working.push(make_pair(ready.top(), time + ready.top()));
            ready.pop();
        }
        else {
            time = working.top().second;
            working.push(make_pair(working.top().first, working.top().first + working.top().second));
            working.pop();
        }
        
        waiting_number += 1;
    }
    
    while(!working.empty()){
        if(time < working.top().second) time = working.top().second;
        working.pop();
    }
    
    answer = time;
    
    return answer;
}