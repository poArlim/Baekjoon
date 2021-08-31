#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> needDays;

    for(int i = 0; i < progresses.size(); i++){
        needDays.push((99 - progresses[i]) / speeds[i]);
    }

    int day = 0;
    int releaseCount = -1;
    while(!needDays.empty()){
        int cur = needDays.front();
        needDays.pop();
        
        if(cur > day){
            day = cur;
            releaseCount++;
            answer.push_back(0);
        }
        
        answer[releaseCount]++;
    }

    return answer;
}