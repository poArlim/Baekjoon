#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> ordered_scoville(scoville.begin(), scoville.end());
    
    while(!ordered_scoville.empty() && ordered_scoville.top() < K){
        if(ordered_scoville.size() < 2) return -1;
        
        int first = ordered_scoville.top();
        ordered_scoville.pop();
        int second = ordered_scoville.top();
        ordered_scoville.pop();

        ordered_scoville.push(first + second * 2);
        answer++;
    }
    
    return answer;
}