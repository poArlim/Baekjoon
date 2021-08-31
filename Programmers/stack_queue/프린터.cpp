#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> docList;
    priority_queue<int> priorityList;

    for(int i = 0; i < priorities.size(); i++){
        docList.push(make_pair(i, priorities[i]));
        priorityList.push(priorities[i]);
    }

    while(!docList.empty()){
        pair<int, int> curDoc = docList.front();
        int curPriority = priorityList.top();
        
        docList.pop();
        if(curDoc.second == curPriority) {
            priorityList.pop();
            answer++;
            if(curDoc.first == location) return answer;
        }
        else docList.push(curDoc);

    }
    
    return answer;
}