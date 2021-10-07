#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    int r_idx = 0;
    int l_idx = 0;
    while(r_idx < reserve.size() && l_idx < lost.size()){
        if(reserve[r_idx] == lost[l_idx]){
            reserve.erase(reserve.begin() + r_idx);
            lost.erase(lost.begin() + l_idx);
        }
        else if(reserve[r_idx] > lost[l_idx]) l_idx++;
        else r_idx++;
    }    
    
    r_idx = 0;
    l_idx = 0;
    while(r_idx < reserve.size() && l_idx < lost.size()){
        if(reserve[r_idx] - lost[l_idx] == 1 || reserve[r_idx] - lost[l_idx] == -1 ){
            reserve.erase(reserve.begin() + r_idx);
            lost.erase(lost.begin() + l_idx);
        }
        else{
            if(reserve[r_idx] > lost[l_idx]) l_idx++;
            else r_idx++;
        }
    }
    
    answer = n - lost.size();
    return answer;
}

