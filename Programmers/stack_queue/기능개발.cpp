#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<pair<int, int>> workList;

    for(int i = 0; i < progresses.size(); i++){
        workList.push(make_pair(progresses[i], speeds[i]));
    }

    int day = 0;
    int releaseCount = -1;
    while(!workList.empty()){
        auto work = workList.front();
        workList.pop();
        int progress = work.first;
        int speed = work.second;
        if((progress + speed * day) < 100){
            if((100 - progress) % speed == 0) day = (100 - progress) / speed;
            else day = (100 - progress) / speed + 1;
            releaseCount++;
            answer.push_back(0);
        }
        answer[releaseCount]++;
    }

    return answer;
}