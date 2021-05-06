#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int,vector<int>,greater<int>> mixedScoville (scoville.begin(),scoville.end());
        
    while (mixedScoville.top() < K) {
        if (mixedScoville.size() < 2) {
            answer = -1;
            break;
        }
        answer++;
        int min = mixedScoville.top();
        mixedScoville.pop();
        int nextMin = mixedScoville.top();
        mixedScoville.pop();
        mixedScoville.push(min + (nextMin * 2));
    }
    
    return answer;
}