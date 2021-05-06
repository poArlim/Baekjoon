#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct compare {
    bool operator() (vector<int> elem, vector<int> e) {
        return elem[1] > e[1];
    } 
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    sort(jobs.begin(), jobs.end());
    priority_queue<vector<int>, vector<vector<int>>, compare> scheduler;
    
    int curTime = 0;
    int totalTime = 0;
    int numJob = jobs.size();
    int i = 0;
    while (i < numJob || !scheduler.empty()) {
        if (i < numJob && jobs[i][0] <= curTime) {
            scheduler.push(jobs[i]);
            i++;
            continue;
        }
        if (!scheduler.empty()) {
            vector<int> curJob = scheduler.top();
            scheduler.pop();
            curTime += curJob[1];
            totalTime += curTime - curJob[0];
        }
        else curTime = jobs[i][0];
    }
    
    answer = totalTime / numJob;
    
    return answer;
}