#include <string>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pair_t;      // pair<req_time, needed_time>

struct compare_req_time{
    bool operator() (pair_t a, pair_t b){
        return a.first > b.first;
        
    }
};

struct compare_needed_time{
    bool operator() (pair_t a, pair_t b){
        return a.second > b.second;
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue<pair_t, vector<pair_t>, compare_req_time> ordered_jobs;
    priority_queue<pair_t, vector<pair_t>, compare_needed_time> pos_jobs;
    
    for(auto job : jobs){
        ordered_jobs.push(make_pair(job[0], job[1]));
    }
    
    int time = 0;
    while(!ordered_jobs.empty() || !pos_jobs.empty()){
        if(!ordered_jobs.empty() && ordered_jobs.top().first <= time){
            pos_jobs.push(ordered_jobs.top());
            ordered_jobs.pop();
            continue;
        }
        
        if(!pos_jobs.empty()){
            pair_t cur = pos_jobs.top(); pos_jobs.pop();
            time += cur.second;
            answer += time - cur.first;
        }
        else time = ordered_jobs.top().first;
    }
    
    return answer / jobs.size();
}
